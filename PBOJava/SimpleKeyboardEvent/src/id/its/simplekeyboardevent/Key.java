package id.its.simplekeyboardevent;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;

public class Key {
	
	private static final int WIDTH = 40;
	private static final int HEIGHT = 40;
	private static final int RELEASED = 1;
	private static final int PRESSED = 2;
	
	private int x;
	private int y;
	private char symbol;
	private int state;
	
	public Key(int x, int y, char symbol) {
		this.x = x;
		this.y = y;
		this.state = RELEASED;
		this.symbol = symbol;
	}
	
	public void render(Graphics g) {
	
		//render tuts sesuai dengan state
		if (this.state == RELEASED) {
			g.setColor(Color.GRAY);
		} 
		else if (this.state == PRESSED) {
			g.setColor(Color.GRAY);
		} 
		else {
			g.setColor(Color.WHITE);
		}
		
		//g.fillRect(this.x, this.y, WIDTH, HEIGHT);
		g.fill3DRect(this.x, this.y, WIDTH, HEIGHT, this.state==RELEASED ? true : false);
		//g.fillRoundRect(this.x, this.y, WIDTH, HEIGHT, 25, 25);
		
		//render text
		int stringPosX = (int)this.x + (WIDTH / 3) + 3;
		int stringPosY = this.y + (HEIGHT / 2) + 3;
		
		Font font1 =  new Font("Arial", Font.TRUETYPE_FONT, 12);
		
		g.setFont(font1);
		g.setColor(Color.WHITE);
		g.drawString(String.valueOf(this.symbol), stringPosX, stringPosY);
	}
	
	public boolean isSymbolMatch(char symbol) {
		if (this.symbol == symbol) return true;
		return false;
	}
	
	public void setPressed() {
		this.state = PRESSED;
	}
	
	public void setReleased() {
		this.state = RELEASED;
	}
}
