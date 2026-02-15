#!/usr/bin/env python3

def solve():
    # 题目给出的已知序列
    targets = [71, 6, 79, 39, 94, 28, 98, 72, 1, 76]
    
    # LCG 参数
    M = 2147483647
    A = 48271
    C = 12345

    print(f"[*] 正在爆破初始状态，正在验证完整序列: {targets}")
    found_state = None
    for k in range(M // 100 + 2):
        candidate = k * 100 + targets[0]
        if candidate >= M:
            break
        temp_state = candidate
        is_valid = True
        for i in range(1, len(targets)):
            temp_state = (A * temp_state + C) % M
            if temp_state % 100 != targets[i]:
                is_valid = False
                break
    
        if is_valid:
            found_state = candidate
            print(f"[+] 找到完美匹配的状态: {found_state}")
            break
    
    if found_state is not None:
        current_state = found_state

        for i in range(len(targets) - 1):
             current_state = (A * current_state + C) % M
        
        print("[+] 预测接下来的 5 个数字：")
        predictions = []
        for _ in range(5):
            current_state = (A * current_state + C) % M
            output = current_state % 100
            predictions.append(str(output))
            
        print(" ".join(predictions))
    else:
        print("[-] 未找到解，可能是输入序列有误。")

if __name__ == "__main__":
    solve()