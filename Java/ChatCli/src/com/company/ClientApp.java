package com.company;

import java.io.IOException;
import java.net.*;
import java.nio.charset.StandardCharsets;

public class ClientApp extends Thread {
    private DatagramSocket socket;
    private DatagramPacket request, response;
    private InetAddress address;
    private int port;
    private byte[] buffer;

    public ClientApp(String host, int port) throws SocketException, UnknownHostException {
        address = InetAddress.getByName(host);
        this.port = port;
        socket = new DatagramSocket();
        socket.setSoTimeout(1000);
        buffer = new byte[2048];
    }

    public void run(){
        response = new DatagramPacket(buffer, buffer.length);
        while(!Thread.interrupted()) {
            try {
                socket.receive(response);
                System.out.println(new String(response.getData(), response.getOffset(),response.getLength()));
            } catch (IOException e) {
            }
        }
    }

    public void Send(String message) throws IOException {
        buffer = message.getBytes();
        request = new DatagramPacket(buffer, buffer.length, address, port);
        socket.send(request);
    }
}
