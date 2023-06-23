import socket

# IP and port for sending and receiving UDP packets
ip = '192.168.0.69'   #Miniserver IP
port = 55000            #Port

def send_udp(message):
    """
    Sends a UDP packet to the specified IP and port.
    """
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.sendto(message.encode('utf-8'), (ip, port))
    sock.close()

def receive_udp():
    """
    Listens for incoming UDP packets on the specified IP and port.
    """
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.bind((ip, port))
    
    while True:
        data, address = sock.recvfrom(1024)
        print('Received packet from {}: {}'.format(address[0], data.decode('utf-8')))

# Usage exampleV
send_udp('Some Value Here: 1505')
send_udp('Some Value Here: 10')



receive_udp()
