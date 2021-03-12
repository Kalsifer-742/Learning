package com.company;

import java.io.IOException;

public class Main {

    public static void main(String[] args) throws IOException {

        // start del server
        Server server = new Server(7070);
        server.start();
        System.out.println("Server started...");

        // start del client
        Client client = new Client("localhost", 7070);
        client.send();

        server.Stop();
    }
}
