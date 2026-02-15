from z3 import *
import struct

# 用z3我好像没有跑通，可以自己试一试（）

def solve():
    # 题目给出的输出
    real_outputs = [
        11329270341625800450, 14683377949987450496, 11656037499566818711, 14613944493490807838, 
        370532313626579329, 5006729399082841610, 8072429272270319226, 3035866339305997883, 
        8753420467487863273, 15606411394407853524, 5092825474622599933, 6483262783952989294, 
        15380511644426948242, 13769333495965053018, 5620127072433438895, 6809804883045878003, 
        1965081297255415258, 2519823891124920624, 8990634037671460127, 3616252826436676639, 
        1455424466699459058, 2836976688807481485, 11291016575083277338, 1603466311071935653, 
        14629944881049387748, 3844587940332157570, 584252637567556589, 10739738025866331065, 
        11650614949586184265, 1828791347803497022, 9101164617572571488, 16034652114565169975, 
        13629596693592688618, 17837636002790364294, 10619900844581377650, 15079130325914713229, 
        5515526762186744782, 1211604266555550739, 11543408140362566331, 18425294270126030355, 
        2629175584127737886, 6074824578506719227, 6900475985494339491, 3263181255912585281, 
        12421969688110544830, 10785482337735433711, 10286647144557317983, 15284226677373655118, 
        9365502412429803694, 4248763523766770934, 13642948918986007294, 3512868807899248227, 
        14810275182048896102, 1674341743043240380, 28462467602860499, 1060872896572731679, 
        13208674648176077254, 14702937631401007104, 5386638277617718038, 8935128661284199759
    ]

    solver = Solver()
    
    # 1. 定义未知数：Flag 对应的整数 (256字节 = 2048位)
    seed_bv = BitVec('seed', 2048)
    
    # 2. 模拟 __init__ 过程，初始化状态列表
    # 原始代码：state.append((seed_int >> shift) & 0xFFFFFFFFFFFFFFFF)
    # Z3 中我们使用 Extract 提取对应位段
    state = []
    state_size = 32
    for i in range(state_size):
        shift = 64 * (state_size - 1 - i)
        # Z3 Extract(high, low) 是包含边界的
        # 第一个块 (i=0): shift=1984. Extract(2047, 1984)
        high = shift + 63
        low = shift
        # 提取出 64 位的 BitVec
        state.append(Extract(high, low, seed_bv))

    print("正在构建约束...")
    
    # 3. 模拟 RNG 生成过程并添加约束
    # 我们只需要前 40 个输出就足够约束所有变量了 (40 * 64 > 2048)
    for step, real_out_val in enumerate(real_outputs[:40]):
        
        # --- GiantLinearRNG.next() 的 Z3 实现 ---
        s = state
        taps = [0, 1, 3, 7, 13, 22, 28, 31]
        
        new_val = BitVecVal(0, 64) # 0
        
        for i in taps:
            val = s[i]
            # Python: mixed = val ^ ((val << 11) & mask) ^ (val >> 7)
            # Z3: LShR 是逻辑右移 (无符号)，Python >> 对正数也是逻辑右移
            mixed = val ^ (val << 11) ^ LShR(val, 7)
            
            rot = (i * 3) % 64
            # Python: mixed = ((mixed << rot) | (mixed >> (64 - rot))) & mask
            # Z3 原生支持 RotateLeft，或者我们可以手动实现以确保一致性
            # 手动实现:
            mixed = (mixed << rot) | LShR(mixed, 64 - rot)
            
            new_val = new_val ^ mixed
        
        # Python: new_val ^= (s[-1] >> 13) ^ ((s[-1] << 5) & mask)
        new_val = new_val ^ LShR(s[-1], 13) ^ (s[-1] << 5)
        
        # 更新状态
        state = s[1:] + [new_val]
        
        # 计算输出
        out_expr = BitVecVal(0, 64)
        for i in range(state_size):
            if i % 2 == 0:
                out_expr = out_expr ^ state[i]
            else:
                val = state[i]
                # Python: out ^= ((val >> 2) | (val << 62))
                # 相当于循环右移 2 或循环左移 62
                rotated_val = LShR(val, 2) | (val << 62)
                out_expr = out_expr ^ rotated_val
        
        # --- 添加约束 ---
        # 告诉 Solver：计算出的符号结果必须等于真实给出的数字
        solver.add(out_expr == real_out_val)

    print("约束构建完成，正在求解 (这可能需要几秒钟)...")
    
    # 4. 求解
    if solver.check() == sat:
        print("找到解了！")
        model = solver.model()
        
        # 获取 seed 的具体数值
        seed_int = model[seed_bv].as_long()
        
        # 转换为字符串 Flag
        try:
            # 256 字节
            flag_bytes = seed_int.to_bytes(256, 'big')
            # 去除 padding
            flag = flag_bytes.replace(b'\x00', b'')
            print("\n" + "="*50)
            print("FLAG:", flag.decode(errors='ignore'))
            print("="*50 + "\n")
        except Exception as e:
            print("解码出错:", e)
            print("Hex:", hex(seed_int))
    else:
        print("无解 (unsat)。请检查约束逻辑或输入数据。")

if __name__ == '__main__':
    solve()