import argparse, socket

MAX_SIZE_BYTES = 65535

def server(port):
    # write server code
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    hostname = '127.0.0.1'
    s.bind((hostname, port))
    print('Listening at {}'.format(s.getsockname()))
    while True:
        data, clientAddress = s.recvfrom(MAX_SIZE_BYTES)
        message = data.decode('ascii')
        upperCaseMessage = message.upper()
        print('The client at {} says {!r}'.format(clientAddress, message))
        data = upperCaseMessage.encode('ascii')
        s.sendto(data, clientAddress)


def client(port):
    # wirte client code
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    host = '127.0.0.1'
    s.connect((host, port))
    while True:
        message = input('Input message to send to server:' )
        data = message.encode('ascii')
        s.send(data)
        print('The OS assigned the address {} to me'.format(s.getsockname()))
        data, address = s.recv(MAX_SIZE_BYTES)
        text = data.decode('ascii')
        print('The server {} replied with {!r}'.format(address, text))
        



if __name__ == '__main__':
    funcs = {'client': client, 'server': server}
    parser = argparse.ArgumentParser(description='UDP client and server')
    parser.add_argument('functions', choices=funcs, help='client or server')
    parser.add_argument('-p', metavar='PORT', type=int, default=3000,
                        help='UDP port (default 3000)')
    args = parser.parse_args()
    print("args =========== ", args)
    function = funcs[args.functions]
    function(args.p)

    
