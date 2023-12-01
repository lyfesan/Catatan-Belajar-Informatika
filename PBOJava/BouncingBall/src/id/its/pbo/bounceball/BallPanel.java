package id.its.pbo.bounceball;

import java.awt.*;
import java.awt.event.*;
import java.util.Random;
import javax.swing.*;
import java.lang.Math;

public class BallPanel extends JPanel implements KeyListener {
	
	private static final long serialVersionUID = -521365982629519820L;
	
	private static final int REFRESH_RATE = 30;
	private Ball ball;
	private BallArea box;
	private int areaWidth;
	private int areaHeight;
	private Color color[]= {Color.cyan, Color.orange, Color.white, Color.red, Color.yellow, Color.magenta, Color.pink};
	
	public BallPanel(int width, int height) {
		
		this.areaWidth = width; 
		this.areaHeight = height;
		this.setPreferredSize(new Dimension(areaWidth, areaHeight));
		
		Random rand = new Random();
		
		int radius = rand.nextInt(1, 20);
		int x = rand.nextInt(width - radius * 2 - 20) + radius + 10;
		int y = rand.nextInt(height - radius * 2 - 20) + radius + 10;
		int speed = rand.nextInt(1, 40);
		int angleInDegree = rand.nextInt(360);
		
		ball = new Ball(x, y, radius, speed, angleInDegree, color[Math.abs(rand.nextInt()%color.length)]);
		box = new BallArea(0, 0, width, height, Color.BLACK, Color.WHITE);
		
		this.addKeyListener(this);
		this.setFocusable(true);
		
		//untuk mendapatkan ukuran area latar belakang jika frame diresize
		this.addComponentListener(new ComponentAdapter() {
			@Override
			public void componentResized(ComponentEvent e) {
				Component c = (Component)e.getSource();
				Dimension dim = c.getSize();
				areaWidth = dim.width;
				areaHeight = dim.height;
				box.set(0, 0, areaWidth, areaHeight);
			}
		});
		
		startThread();
	}
	
	public void startThread() {
		
		Thread gameThread = new Thread() {
			public void run() {
				while (true) {
					ball.collide(box);
					repaint();
					try {
					Thread.sleep(1000 / REFRESH_RATE);
					} catch (InterruptedException ex) {}
				}
			}
		};
		
		gameThread.start();
	}
	
	@Override
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		box.draw(g);
		ball.draw(g);
	}

	@Override
	public void keyTyped(KeyEvent e) {
		
	}

	@Override
	public void keyPressed(KeyEvent e) {
		int key = e.getKeyCode();
		System.out.println(key);
		if(key == KeyEvent.VK_UP) {
			ball.radius+=1.0;
			repaint();
		} else if (key == KeyEvent.VK_DOWN) {
			ball.radius = ball.radius > 1.0 ? ball.radius-=1.0 : 1.0;
			repaint();
		}
	}

	@Override
	public void keyReleased(KeyEvent e) {
		
		
	}
}	