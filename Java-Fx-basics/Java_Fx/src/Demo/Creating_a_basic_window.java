package Demo;
import javafx.application.Application;
//import javafx.event.ActionEvent;
//import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Creating_a_basic_window extends Application
{

	@Override
	public void start(Stage primaryStage) throws Exception
	{
		primaryStage.setTitle("wnidow");
		Button b=new Button("click me");
		
		StackPane layout=new StackPane();
		layout.getChildren().add(b);
		
		Scene s=new Scene(layout,300,250);
		primaryStage.setScene(s);
		primaryStage.show();
		
	}
	public static void main(String args[])
	{
		launch(args);
	}

}
