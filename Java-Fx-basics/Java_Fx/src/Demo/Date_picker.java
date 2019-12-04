package Demo;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.DatePicker;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Date_picker extends Application 
{
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		primaryStage.setTitle("wnidow");
		Button b=new Button("click me");
		DatePicker d=new DatePicker();
	     d.setPromptText("Enter Today's Date");
	      
		
		StackPane layout=new StackPane();
		layout.getChildren().add(d);
		
		Scene s=new Scene(layout,300,250);
		primaryStage.setScene(s);
		primaryStage.show();
		
	}
	public static void main(String args[])
	{
		launch(args);
	}
}
