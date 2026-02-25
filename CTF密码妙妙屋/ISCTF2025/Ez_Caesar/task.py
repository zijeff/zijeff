def variant_caesar_encrypt(text):
    encrypted = ""
    shift = 2
    for char in text:
        if char.isalpha():
            if char.isupper():
                base = ord('A')
                new_char = chr((ord(char) - base + shift) % 26 + base)
            else:
                base = ord('a')
                new_char = chr((ord(char) - base + shift) % 26 + base)
            encrypted += new_char
            shift += 3
        else:
            encrypted += char
    return encrypted

# KXKET{Tubsdx_re_hg_zytc_hxq_vnjma}