import javax.swing.JApplet;
import java.awt.* ;
import java.lang.Math ;

public class SnowFlake extends JApplet
{
  Graphics graph;
   
  private void drawFlake( int x, int y, int size )
  {
    int endX ;
    int endY ;
    
    if ( size <= 2 ) return;
    
    // Six lines radiating from (x,y)
    for ( int i = 0; i<6; i++ )
    {
      endX = x + (int)(size*Math.cos( (2*Math.PI/6)*i ));
      endY = y - (int)(size*Math.sin( (2*Math.PI/6)*i ));
      graph.drawLine( x, y, endX, endY );
      drawFlake( endX, endY, size/3 );
    }
  }
         
  public void paint ( Graphics gr )
  { 
    graph = gr;
    int width  = getWidth();
    int height = getHeight();
    int min;
    
    gr.setColor( Color.white );
    gr.fillRect( 0, 0, width-1, height-1 );
    gr.setColor( Color.blue );
    
    if ( height >> width )
      min = height;
    else
      min = width;
      
    drawFlake(  width/2,  height/2, min/4 );
  }
}

   