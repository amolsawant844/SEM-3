package Demo;

import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.layout.*;
import javafx.scene.control.*;
public class Embedding_layouts extends Application
{
	Stage window;
	@Override
	public void start(Stage primaryStage) throws Exception
	{
		// TODO Auto-generated method stub
		window=primaryStage;
		window.setTitle("embedding_layouts");
		
		HBox topmenu=new HBox();
		Button a1=new Button("file");
		Button b1=new Button("Edit");
		Button c1=new Button("view");
		topmenu.getChildren().addAll(a1,b1,c1);

		VBox leftmenu=new VBox();
		Button d=new Button("f");
		Button e=new Button("E");
		Button f=new Button("v");
		leftmenu.getChildren().addAll(d,e,f);
		
		BorderPane b2=new BorderPane();
		b2.setTop(topmenu);
		b2.setLeft(leftmenu);
		
		Scene s=new Scene(b2,300,250);
		window.setScene(s);
		window.show();
	}
	public static void main(String args[])
	{
		launch(args);
	}
	

}
