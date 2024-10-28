import javax.swing.*; 
import java.awt.*; 
public class ShapeCanvas extends JPanel { 
@Override 
public void paintComponent(Graphics g) { 
super.paintComponent(g);  // Call the superclass's paintComponent method 
// Drawing a rectangle 
g.drawRect(50, 50, 200, 100);   // Draw rectangle at (50, 50) with width 200 
and height 100 
g.drawString("Rectangle", 100, 160);  // Label the rectangle 
// Drawing a circle 
g.drawOval(300, 50, 100, 100);  // Draw circle at (300, 50) with width and 
height of 100 
g.drawString("Circle", 340, 160);  // Label the circle 
// Drawing a line 
g.drawLine(50, 200, 250, 200);  // Draw a line from (50, 200) to (250, 200) 
g.drawString("Line", 120, 220);  // Label the line 
} 
public static void main(String[] args) { 
JFrame frame = new JFrame("Shape Canvas"); 
ShapeCanvas canvas = new ShapeCanvas(); 
frame.setSize(500, 400);  // Set the size of the window 
frame.add(canvas);        // Add the canvas to the window 
frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
frame.setVisible(true); 
} 
} 
