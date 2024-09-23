import socket

# Define the path for the Unix Domain Socket file
SOCKET_PATH = "/tmp/uds_socket"

# Create a Unix domain socket
with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as s:
    s.connect(SOCKET_PATH)
    s.sendall(b'Hello from the client!')
    data = s.recv(1024)

print('Received from server:', data.decode())
