package Demo;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class Handle_user_events extends Application implements EventHandler<ActionEvent>
{
	Button b;
	@Override
	public void start(Stage primaryStage) throws Exception 
	{
		// TODO Auto-generated method stub
		primaryStage.setTitle("wnidow");
		 b=new Button("click me");
		 b.setOnAction(this);
		
		StackPane layout=new StackPane();
		layout.getChildren().add(b);
		
		Scene s=new Scene(layout,300,250);
		primaryStage.setScene(s);
		primaryStage.show();	
	}

	@Override
	public void handle(ActionEvent e)
	{
		// TODO Auto-generated method stub
		if(e.getSource()==b)
		{	
			System.out.println("hi there");
			
		}
	}
	
	public static void main(String args[])
	{
		launch(args);
	}


}
