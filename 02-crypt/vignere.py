def vignere(text, key, mod):
    """
    Encrypt the text with the Vignere cipher.
    """
    encrypted_text = ""
    if mod == 27: # spanish
        alphabet = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"
        tild = {'á': 'a', 'é': 'e', 'í': 'i', 'ó': 'o', 'ú': 'u', 'Á': 'A', 'É': 'E', 'Í': 'I', 'Ó': 'O', 'Ú': 'U'}
        key = "".join([c if c.isalpha() else "" for c in key])
        key.upper()
        text = "".join([c if c.isalpha() else "" for c in text])
        text = text.upper()

        # replace tildes
        for k, v in tild.items():
            text = text.replace(k, v)
            key = key.replace(k, v)
        
        for i in range(len(text)):
            char = text[i]
            key_char = key[i % len(key)]
            if char in alphabet:
                encrypted_text += alphabet[(alphabet.index(char) + alphabet.index(key_char)) % mod]
            else:
                encrypted_text += char
                i -= 1
    elif mod == 191: # ascii
        alphabet = [chr(i) for i in range(33, 256)]
        key = key.upper().replace("\n", "").replace(" ", "")
        text = text.upper().replace("\n", "").replace(" ", "")
        
        for i in range(len(text)):
            char = text[i]
            key_char = key[i % len(key)]
            index = alphabet.index(char) + alphabet.index(key_char) % 191

            # avoid espetial characters
            if index < 94:
                encrypted_text += alphabet[index]
            elif index >= 94:
                index += 32
                if index >= len (alphabet):
                    index = index % mod
                    encrypted_text += alphabet[index]
                else:
                    if index in [126, 127, 140]:
                        index %= 32
                        encrypted_text += alphabet[index]
                    else:
                        encrypted_text += alphabet[index]
    return encrypted_text

def decrypt_vignere(text, key, mod):
    alphabet = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"
    encrypted_text = ""
    
    for i in range(len(text)):
        char = text[i]
        key_char = key[i % len(key)]
        if char in alphabet:
            encrypted_text += alphabet[(alphabet.index(char) - alphabet.index(key_char)) % mod]
        else:
            encrypted_text += char
            i -= 1
    return encrypted_text
    

if __name__ == "__main__":
    """ text = input("Enter the text to encrypt: ")
    key = input("Enter the key: ")
    mod = int(input("Enter the mod: "))
    print("\nEntrada:\n", text)
    print("Salida:\n", vignere(text, key, mod)) """

    text = input("Enter the text to decrypt: ") #GYLKWQRVEBTPXDJRQDDVQNPHHGQGUWRNPPWHRGCONLJOHMÑCOXEEAVASIÑDOEQPETAPVHEOPEKRXYAEVRUHAÑVNRSIVPZBSXINLEWSMGBSHEEITVDEENSVR
    key = input("Enter the key: ")

    print("\nEntrada:\n", text)
    print("Salida:\n", decrypt_vignere(text, key, 27))