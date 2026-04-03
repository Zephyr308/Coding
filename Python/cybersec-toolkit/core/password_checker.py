import re

def check_strength(password):
    checks = [
        len(password) >= 8,
        re.search(r"[A-Z]", password),
        re.search(r"[a-z]", password),
        re.search(r"\d", password),
        re.search(r"[@#$%^&*!]", password)
    ]

    score = sum(bool(c) for c in checks)

    if score == 5:
        return "Strong"
    elif score >= 3:
        return "Medium"
    return "Weak"
