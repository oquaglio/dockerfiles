import socket
import os

# Define the path for the Unix Domain Socket file
SOCKET_PATH = "/tmp/uds_socket"

# Make sure the socket file doesn't already exist
if os.path.exists(SOCKET_PATH):
    os.remove(SOCKET_PATH)

# Create a Unix domain socket
with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as s:
    s.bind(SOCKET_PATH)
    s.listen()
    print(f"Server listening on {SOCKET_PATH}")

    # Accept a connection
    conn, _ = s.accept()
    with conn:
        print('Connected to client')
        while True:
            data = conn.recv(1024)
            if not data:
                break
            print(f"Received from client: {data.decode()}")
            conn.sendall(b'Hello from the server!')

# Clean up the socket file after the server is done
os.remove(SOCKET_PATH)
