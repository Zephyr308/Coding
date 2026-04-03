from core.port_scanner import scan

def scan_internal(target, ports):
    results = scan(target, ports)
    return {p: s for p, s in results.items() if s == "OPEN"}
