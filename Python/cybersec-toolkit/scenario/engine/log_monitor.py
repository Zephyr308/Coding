def detect_bruteforce(logfile, threshold):
    attempts = {}

    with open(logfile) as f:
        for line in f:
            if "FAILED" in line:
                ip = line.split()[0]
                attempts[ip] = attempts.get(ip, 0) + 1

    return {ip: c for ip, c in attempts.items() if c >= threshold}
