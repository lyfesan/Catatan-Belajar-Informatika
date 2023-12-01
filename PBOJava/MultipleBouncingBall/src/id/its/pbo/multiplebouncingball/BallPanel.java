package id.its.pbo.multiplebouncingball;

import java.awt.*;
import java.awt.event.*;
import java.util.List;
import java.util.ArrayList;
import java.util.Random;
import javax.swing.*;
import java.lang.Math;

public class BallPanel extends JPanel {
	
	private static final long serialVersionUID = -521365982629519820L;
	
	private static final int REFRESH_RATE = 30;
	private List<Ball> ballList;
	private BallArea box;
	private int areaWidth;
	private int areaHeight;
	private Color color[]= {Color.cyan, Color.orange, Color.white, Color.red, Color.yellow, Color.magenta, Color.pink};
	
	public BallPanel(int width, int height) {
		
		this.ballList = new ArrayList<Ball>();
		this.areaWidth = width; 
		this.areaHeight = height;
		this.setPreferredSize(new Dimension(areaWidth, areaHeight));
		
		//Random rand = new Random();
		/*
		for(int i=0;i<4;i++) {
			ballList.add(addBall(rand,rand.nextInt(1, 50), rand.nextInt(1,5)));
		}
		*/
		box = new BallArea(0, 0, width, height, Color.BLACK, Color.WHITE);
		
		
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
	
	public Ball addBall(char key) {
		
		Random rand = new Random();
		
		int radius = rand.nextInt(1,50);
		int speed = rand.nextInt(1,6);
		int x = rand.nextInt(areaWidth - radius * 2 - 20) + radius + 10;
		int y = rand.nextInt(areaHeight - radius * 2 - 20) + radius + 10;
		int angleInDegree = rand.nextInt(360);
		
		return new Ball(x, y, radius, speed, angleInDegree, color[Math.abs(rand.nextInt()%color.length)]);
	}
	
	public void startThread() {
		
		Thread gameThread = new Thread() {
			public void run() {
				while (true) {
					for(Ball b : ballList) {
						for(Ball c : ballList) {
							if(b!=c) {
								b.collide(c);
								repaint();
							}
						}	
						b.collide(box);
					}
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
		for (Ball b :ballList) {
			b.draw(g);
		}
	}
}	