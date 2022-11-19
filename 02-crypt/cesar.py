# La perfección se logra no cuando no hay nada más que añadir, sino cuando no hay nada más que  quitar

# ÑDSHUIHFFLRPVHÑRJUDPRFXDPGRPRKDBPDGDODVTXHDQDGLUVLPRFXDPGRPRKDBPDGDODVTXHTXLWDU
# ÑDSHUIHFFLRPVHÑRJUDPRFXDPGRPRKDBPDGDODVTXHDQDGLUVLPRFXDPGRPRKDBPDGDODVTXHTXLWDU

def encrypt_cesar(text, shift):
    """
    Encrypt the text with the Caesar cipher.
    """
    alphabet = "ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"
    encrypted_text = ""

    for punct in ".,;:¿?¡!":
        text = text.replace(punct, "")
    text = text.upper()

    for letter in text:
        index = alphabet.find(letter)
        encrypted_text += alphabet[(index + shift) % len(alphabet)]
    
    return encrypted_text

def desencrypt_cesar(text, shift):
    return encrypt_cesar(text, 27-shift)

if __name__ == "__main__":
    """ text = input("Enter the text to encrypt: ")
    shift = int(input("Enter the shift: "))
    print("Entrada:\n", text)
    print("Salida:\n", encrypt_cesar(text, shift)) """

    text = input("Enter the text to decrypt: ")
    shift = int(input("Enter the shift: "))
    print("Entrada:\n", text)
    print("Salida:\n", desencrypt_cesar(text, shift))