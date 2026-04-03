from cryptography.fernet import Fernet

key = Fernet.generate_key()
cipher = Fernet(key)

def encrypt_file(filepath):
    with open(filepath, "rb") as f:
        data = f.read()
    encrypted = cipher.encrypt(data)

    with open(filepath + ".enc", "wb") as f:
        f.write(encrypted)

    return "File encrypted successfully"

def decrypt_file(filepath):
    with open(filepath, "rb") as f:
        data = f.read()
    decrypted = cipher.decrypt(data)

    output = "decrypted_" + filepath.replace(".enc", "")
    with open(output, "wb") as f:
        f.write(decrypted)

    return "File decrypted successfully"
