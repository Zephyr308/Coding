import tkinter as tk
from tkinter import filedialog, messagebox
import re
import socket
from cryptography.fernet import Fernet

key = Fernet.generate_key()
cipher = Fernet(key)

# ===== FUNCTIONS =====
def encrypt_file():
    file = filedialog.askopenfilename()
    if file:
        with open(file, "rb") as f:
            data = f.read()
        encrypted = cipher.encrypt(data)
        with open(file + ".enc", "wb") as f:
            f.write(encrypted)
        messagebox.showinfo("Success", "File Encrypted")

def check_password():
    pwd = entry.get()

    checks = [
        len(pwd) >= 8,
        re.search(r"[A-Z]", pwd),
        re.search(r"[a-z]", pwd),
        re.search(r"\d", pwd),
        re.search(r"[@#$%^&*!]", pwd)
    ]

    score = sum(bool(c) for c in checks)

    if score == 5:
        result.set("Strong 💪")
    elif score >= 3:
        result.set("Medium ⚠️")
    else:
        result.set("Weak ❌")

def scan_ports():
    target = entry.get()
    open_ports = []

    for port in [21, 22, 80, 443]:
        sock = socket.socket()
        sock.settimeout(1)
        if sock.connect_ex((target, port)) == 0:
            open_ports.append(port)
        sock.close()

    result.set(f"Open Ports: {open_ports}")

# ===== GUI SETUP =====
app = tk.Tk()
app.title("Cybersecurity Toolkit")

entry = tk.Entry(app, width=30)
entry.pack(pady=10)

result = tk.StringVar()
tk.Label(app, textvariable=result).pack(pady=10)

tk.Button(app, text="Encrypt File", command=encrypt_file).pack(pady=5)
tk.Button(app, text="Check Password", command=check_password).pack(pady=5)
tk.Button(app, text="Scan Ports", command=scan_ports).pack(pady=5)

app.mainloop()
