def detect(logfile):
    suspicious = {}
    
    with open(logfile, "r") as f:
        for line in f:
            if "FAILED" in line:
                ip = line.split()[0]
                suspicious[ip] = suspicious.get(ip, 0) + 1

    return {ip:count for ip,count in suspicious.items() if count >= 3}
