package Demo;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;


public class Anonymous_inner_class extends Application 
{
	Button b;
	@Override
	public void start(Stage primaryStage) throws Exception 
	{
		// TODO Auto-generated method stub
		primaryStage.setTitle("wnidow");
		 b=new Button("click me");
		 b.setOnAction(new EventHandler<ActionEvent>()
		 {
			 @Override 
			 public void handle(ActionEvent e)
			 {
				 System.out.println("hi there");
			 }
		 });
		
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
