module unitn.minecraft {
    requires javafx.controls;
    requires javafx.fxml;


    opens unitn.minecraft.Main to javafx.fxml;
    exports unitn.minecraft.Main;
}