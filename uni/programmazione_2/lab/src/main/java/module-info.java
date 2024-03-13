module unitn.prog2.template {
    requires javafx.controls;
    requires javafx.fxml;


    opens unitn.prog2.template to javafx.fxml;
    exports unitn.prog2.template;
}