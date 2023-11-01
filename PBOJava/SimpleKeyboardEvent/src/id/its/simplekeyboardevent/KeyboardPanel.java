package id.its.simplekeyboardevent;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JPanel;

public class KeyboardPanel extends JPanel implements KeyListener {
	
	private static final long serialVersionUID = -5138936583346756828L;
	private List<Key> keys;
	
	public KeyboardPanel(int width, int height) {
		this.setPreferredSize(new Dimension(width, height));
		this.keys = new ArrayList<Key>();
		//row 1
		this.keys.add(new Key(10, 10, 'q'));
		this.keys.add(new Key(55, 10, 'w'));
		this.keys.add(new Key(100, 10, 'e'));
		this.keys.add(new Key(145, 10, 'r'));
		this.keys.add(new Key(190, 10, 't'));
		this.keys.add(new Key(235, 10, 'y'));
		this.keys.add(new Key(280, 10, 'u'));
		this.keys.add(new Key(325, 10, 'i'));
		this.keys.add(new Key(370, 10, 'o'));
		this.keys.add(new Key(415, 10, 'p'));
		
		//row 2
		this.keys.add(new Key(25, 55, 'a'));
		this.keys.add(new Key(70, 55, 's'));
		this.keys.add(new Key(115, 55, 'd'));
		this.keys.add(new Key(160, 55, 'f'));
		this.keys.add(new Key(205, 55, 'g'));
		this.keys.add(new Key(250, 55, 'h'));
		this.keys.add(new Key(295, 55, 'j'));
		this.keys.add(new Key(340, 55, 'k'));
		this.keys.add(new Key(385, 55, 'l'));
		
		//row 3
		this.keys.add(new Key(40, 100, 'z'));
		this.keys.add(new Key(85, 100, 'x'));
		this.keys.add(new Key(130, 100, 'c'));
		this.keys.add(new Key(175, 100, 'v'));
		this.keys.add(new Key(220, 100, 'b'));
		this.keys.add(new Key(265, 100, 'n'));
		this.keys.add(new Key(310, 100, 'm'));
		
		this.addKeyListener(this);
		this.setFocusable(true);
	}
	
	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		//render seluruh keys
		for (Key key : this.keys) {
			key.render(g);
		}
	}
	
	@Override
	public void keyTyped(KeyEvent e) {
	//do nothing
	}
	
	@Override
	public void keyPressed(KeyEvent e) {
		char key = e.getKeyChar();
		for (Key k : this.keys) {
			if (k.isSymbolMatch(key)) {
				k.setPressed();
				repaint();
			}
		}
	}
	
	@Override
	public void keyReleased(KeyEvent e) {
		
		char key = e.getKeyChar();
		
		for (Key k : this.keys) {
			if (k.isSymbolMatch(key)) {
				k.setReleased();
				repaint();
			}
		}
	}
}
