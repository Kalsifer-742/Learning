package unitn.minecraft.Main;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.stage.Stage;
import unitn.minecraft.data.Block;
import unitn.minecraft.data.Map;

import java.io.IOException;
import java.util.Scanner;

public class main extends Application {
    static void create_default_map() {
        Map map = new Map();
        map.display_on_out();

        map.change_cell(1, 1);
        map.display_on_out();

        map.insert_at_coords_rec(0, 7, new Block('A'));
        map.display_on_out();

        map.insert_at_coords_iter(0, 7, new Block('B'));
        map.display_on_out();

        for (int i = 0; i < 3; i++) {
            System.out.print("Enter row: ");
            Scanner myObj = new Scanner(System.in);
            int row = myObj.nextInt();

            System.out.print("Enter column: ");
            int col = myObj.nextInt();

            System.out.println("Changing: "+row+" - "+col);
            map.change_cell(row,col);

            map.display_on_out();
        }
    }

    @Override
    public void start(Stage stage) throws IOException {
        Group root = new Group();
        Scene scene = new Scene(root, 320, 240);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        create_default_map();

        //launch();
    }
}