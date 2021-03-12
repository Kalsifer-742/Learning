package com.company;

import java.io.IOException;
import java.net.*;
import java.nio.ByteBuffer;

public class Client {
    final int MTU = 14;
    String[] phrasesToSend = {
            "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the " +
                    "industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of " +
                    "type and scrambled it to make a type specimen book. It has survived not only five centuries, " +
                    "but also the leap into electronic typesetting, remaining essentially unchanged. It was " +
                    "popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, " +
                    "and more recently with desktop publishing software like Aldus PageMaker including versions " +
                    "of Lorem Ipsum.",
            "It is a long established fact that a reader will be distracted by the readable content of a page when " +
                    "looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal " +
                    "distribution of letters, as opposed to using 'Content here, content here', making it look like " +
                    "readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as " +
                    "their default model text, and a search for 'lorem ipsum' will uncover many web sites still in " +
                    "their infancy. Various versions have evolved over the years, sometimes by accident, sometimes " +
                    "on purpose (injected humour and the like).",
            "Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical " +
                    "Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin" +
                    " professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words," +
                    " consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical " +
                    "literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and " +
                    "1.10.33 of \"de Finibus Bonorum et Malorum\" (The Extremes of Good and Evil) by Cicero, written " +
                    "in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. " +
                    "The first line of Lorem Ipsum, \"Lorem ipsum dolor sit amet..\", comes from a line " +
                    "in section 1.10.32.",
    };

    private DatagramSocket socket;
    private DatagramPacket request, response;
    private InetAddress address;
    private int port;
    private ByteBuffer buffer;
    private byte[] successResponse;

    public Client(String host, int port) throws UnknownHostException, SocketException {
        socket = new DatagramSocket();
        socket.setSoTimeout(3000);
        buffer = ByteBuffer.allocate(MTU);
        address = InetAddress.getByName(host);
        this.port = port;
        successResponse = new byte[7];
    }

    public void send() throws IOException {
        response = new DatagramPacket(buffer.array(), buffer.array().length);
        for(String phrase: phrasesToSend) {
            for (int t = 0; t < 3; t++) { //3 maximum tries
                buffer.putInt(phrase.length() / 5);
                request = new DatagramPacket(buffer.array(), buffer.array().length, address, port);
                socket.send(request);
                buffer.clear();

                for (int i = 0; i < phrase.length() / 5; i++) {
                    buffer.putInt(i);
                    for (int j = i*5; j < i*5+5; j++) {
                        buffer.putChar(phrase.charAt(j));
                    }
                    request = new DatagramPacket(buffer.array(), buffer.array().length, address, port);
                    socket.send(request);
                    buffer.clear();
                }

                try {
                    socket.receive(response);
                } catch (java.io.InterruptedIOException e){
                    buffer.clear();
                    continue;
                }
                buffer = ByteBuffer.wrap(response.getData());
                buffer.get(successResponse);
                buffer.clear();
                System.out.println(new String(successResponse));
                break;
            }
        }
        System.out.println("Client finished to send...");
    }
}