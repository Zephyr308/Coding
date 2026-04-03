import socket

def scan(target, ports=[21,22,80,443]):
    results = {}

    for port in ports:
        sock = socket.socket()
        sock.settimeout(1)

        result = sock.connect_ex((target, port))
        results[port] = "OPEN" if result == 0 else "CLOSED"

        sock.close()

    return results
