package Demo;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

//in this we will close the window using cross mark
public class Closing_the_prog_2 extends Application
{
	Stage window;
	Button b;
	@Override
	public void start(Stage primaryStage) throws Exception 
	{
		// TODO Auto-generated method stub
		window=primaryStage;
		window.setTitle("closing the program");
		
		
		b=new Button("close");
		b.setOnAction(e ->closeprogram());
		
		window.setOnCloseRequest(e->
		{
			e.consume();
			closeprogram();
		});
		
		
		 StackPane layout = new StackPane();
	     layout.getChildren().add(b);
	     Scene scene = new Scene(layout, 300, 250);
	     window.setScene(scene);
	     window.show();
	    
	}
	public static void main(String args[])
	{
		launch(args);
	}
	private void closeprogram()
	{
		boolean answer=Closing_the_prog_1.display("close?","are you sure?");
		if(answer==true)
			window.close();
	}

}
