import json
from engine.log_monitor import detect_bruteforce
from engine.alert_engine import create_alerts
from engine.threat_intel import load_blacklist, match_blacklist
from engine.scanner import scan_internal

def run():
    with open("scenario/config.json") as f:
        config = json.load(f)

    # Step 1: Detect attacks
    threats = detect_bruteforce(config["log_file"], config["threshold"])
    print("\n[+] Threats Detected:", threats)

    # Step 2: Generate alerts
    alerts = create_alerts(threats, config["report_file"])
    print("[+] Alerts generated")

    # Step 3: Threat intelligence check
    blacklist = load_blacklist(config["blacklist_file"])
    flagged = match_blacklist(threats, blacklist)
    print("[+] Blacklisted IPs:", flagged)

    # Step 4: Scan system
    open_ports = scan_internal(config["scan_target"], config["ports"])
    print("[+] Open Ports:", open_ports)

if __name__ == "__main__":
    run()
