package Demo;
import javafx.application.Application;

import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;

public class Switching_scenes extends Application
{
	Stage window;
	Scene s1,s2;
	@Override
	public void start(Stage primaryStage) throws Exception 
	{
		window=primaryStage;
		Label l1=new Label("welcome to first scene");
		Button b1=new Button("got to scene 2");
		b1.setOnAction(e -> window.setScene(s2));
		
		VBox layout=new VBox(20);
		layout.getChildren().addAll(l1,b1);
		s1=new Scene(layout,200,200);
		
		Button b2=new Button("got to scene 1");
		b2.setOnAction(e -> window.setScene(s1));
		
		StackPane layout1=new StackPane();
		layout1.getChildren().addAll(b2);
		s2=new Scene(layout1,200,200);
		
		window.setScene(s1);
		window.show();
		
	}
	public static void main(String args[])
	{
		launch(args);
	}
	

}
