package id.its.pbo.bounceball;

import java.awt.*;

public class Ball {
	
	double x, y;
	double speedX, speedY;
	double radius;
	private Color color;
	
	public Ball(double x, double y, double radius, double speed, double angleInDegree, Color color) {
		this.x = x;
		this.y = y;
		this.speedX = (double)(speed * Math.cos(Math.toRadians(angleInDegree)));
		this.speedY = (double)(-speed * (double)Math.sin(Math.toRadians(angleInDegree)));
		this.radius = radius;
		this.color = color;
	}
	
	public void draw(Graphics g) {
		g.setColor(color);
		g.fillOval((int)(x - radius), (int)(y - radius), (int)(2 * radius), (int)(2 * radius));
	}
	
	public void collide(BallArea box) {
		
		double ballMinX = box.minX + radius;
		double ballMinY = box.minY + radius;
		double ballMaxX = box.maxX - radius;
		double ballMaxY = box.maxY - radius;
		
		x += speedX;
		y += speedY;
		
		if (x < ballMinX) {
			speedX = -speedX;
			x = ballMinX;
		} else if (x > ballMaxX) {
			speedX = -speedX;
			x = ballMaxX;
		}
		if (y < ballMinY) {
			speedY = -speedY;
			y = ballMinY;
		} else if (y > ballMaxY) {
			speedY = -speedY;
			y = ballMaxY;
		}
	}
}
