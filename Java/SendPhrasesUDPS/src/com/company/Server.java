package com.company;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class Server extends Thread {
    private DatagramSocket socket;
    private DatagramPacket answer, request;
    private ByteBuffer buffer;
    final int bufferSize = 14;
    private int phraselegth;
    private byte[] phraseChunk;
    private String phraseComplete;
    private final String success = "SUCCESS";

    public Server(int port) throws SocketException {
        socket = new DatagramSocket(port);
        buffer = ByteBuffer.allocate(bufferSize);
        phraseChunk = new byte[10];
        phraseComplete = "";
    }

    public void run() {
        request = new DatagramPacket(buffer.array(), buffer.array().length);
        while(!Thread.interrupted()) {
            try {
                socket.receive(request);
                buffer = ByteBuffer.wrap(request.getData());
                phraselegth = buffer.getInt();
                buffer.clear();
                for (int i = 0; i < phraselegth; i++) {
                    socket.receive(request);
                    buffer = ByteBuffer.wrap(request.getData());
                    buffer.position(4);
                    buffer.get(phraseChunk);
                    buffer.clear();
                    phraseComplete += new String(phraseChunk);
                }
                answer = new DatagramPacket(success.getBytes(StandardCharsets.UTF_8), success.getBytes(StandardCharsets.UTF_8).length, request.getAddress(), request.getPort());
                socket.send(answer);
                System.out.println(phraseComplete.toUpperCase());
            } catch (IOException e) { }
        }
    }

    public void Stop(){
        this.interrupt();
    }
}
