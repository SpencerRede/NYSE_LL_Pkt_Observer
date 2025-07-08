# Simple python script to listen to a socket and print out the cooresponding packets
# Used to verify that the PCAP Reader + Server is properly reading a pcap file and serving them to 127.0.0.1:5000

import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("127.0.0.1", 5000))
print("Listening to 127.0.0.1:5000")

while True:
    data, addr = sock.recvfrom(4096)
    print(f"Received {len(data)} bytes: {data.hex()}")
