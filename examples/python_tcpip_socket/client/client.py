import socket

# Define the server's IP and port
HOST = 'server'  # Use the service name from docker-compose
PORT = 65432     # Port to connect to the server

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    s.sendall(b'Hello from the client!')
    data = s.recv(1024)

print('Received from server:', data.decode())
