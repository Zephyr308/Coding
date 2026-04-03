from core import encryption, password_checker, port_scanner, intrusion_detection

def main():
    print("CyberSec Toolkit")

    while True:
        print("\n1. Encrypt File\n2. Check Password\n3. Scan Ports\n4. Detect Intrusion\n5. Exit")
        choice = input("Choose: ")

        if choice == "1":
            path = input("File path: ")
            print(encryption.encrypt_file(path))

        elif choice == "2":
            pwd = input("Password: ")
            print(password_checker.check_strength(pwd))

        elif choice == "3":
            target = input("Target IP: ")
            print(port_scanner.scan(target))

        elif choice == "4":
            log = input("Log file: ")
            print(intrusion_detection.detect(log))

        elif choice == "5":
            break

if __name__ == "__main__":
    main()
