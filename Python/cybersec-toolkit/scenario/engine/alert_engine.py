import json
from datetime import datetime

def create_alerts(threats, output_file):
    alerts = []

    for ip, count in threats.items():
        alerts.append({
            "ip": ip,
            "attempts": count,
            "severity": "HIGH",
            "timestamp": str(datetime.now())
        })

    with open(output_file, "w") as f:
        json.dump(alerts, f, indent=4)

    return alerts
