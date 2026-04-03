def load_blacklist(path):
    with open(path) as f:
        return set(line.strip() for line in f)

def match_blacklist(threats, blacklist):
    return {ip: "BLACKLISTED" for ip in threats if ip in blacklist}
