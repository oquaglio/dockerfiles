import socket

# Define the IP and port for the server
HOST = '0.0.0.0'  # Listen on all available interfaces
PORT = 65432      # Port to listen on

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen()
    print("Server listening on port", PORT)

    # Accept the connection
    conn, addr = s.accept()

    # Get the client IP and port
    client_ip, client_port = addr

    try:
        # Attempt to resolve the hostname from the client IP
        hostname, aliases, ip_addresses = socket.gethostbyaddr(client_ip)
        print(f"Connected by {hostname} ({client_ip}) on port {client_port}")
    except socket.herror:
        # If hostname cannot be resolved, just show the IP
        print(f"Connected by {client_ip} on port {client_port} (hostname could not be resolved)")

    with conn:
        while True:
            data = conn.recv(1024)
            if not data:
                break
            print(f"Received from client: {data.decode()}")
            conn.sendall(b'Hello from the server!')
