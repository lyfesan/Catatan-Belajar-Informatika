package id.its.pbo.multiplebouncingball;

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
	
	public void collide(Ball ball2) {
		
		/*
		double ballMinX = ball2.x + ball2.radius + this.radius;
		double ballMinY = ball2.y + ball2.radius + this.radius;
		double ballMaxX = ball2.x - ball2.radius - this.radius;
		double ballMaxY = ball2.y - ball2.radius - this.radius;
		
		this.x += this.speedX;
		this.y += this.speedY;
		
		if (this.x < ballMinX) {
			this.speedX *= -1;
			ball2.speedX *= -1;
			//this.x = ballMinX + this.radius + ball2.radius;
			//ball2.x = ballMinX - this.radius - ball2.radius;
		} else if (this.x > ballMaxX) {
			this.speedX *= -1;
			ball2.speedX *= -1;
			//this.x = ballMaxX - this.radius - ball2.radius;
			//ball2.x = ballMaxX + this.radius + ball2.radius; 
		}
		if (this.y < ballMinY) {
			this.speedY *= -1;
			ball2.speedY *= -1;
			//this.y = ballMinY + this.radius + ball2.radius;
			//ball2.y = ballMinY - this.radius - ball2.radius;
		} else if (this.y > ballMaxY) {
			this.speedY *= -1;
			ball2.speedY *= -1;
			//this.y = ballMaxY - this.radius - ball2.radius;
			//ball2.y = ballMaxY + this.radius + ball2.radius;
		}
		*/

		this.x += this.speedX;
		this.y += this.speedY;
		
		double deltaX = Math.abs(this.x - ball2.x);
        double deltaY = Math.abs(this.y - ball2.y);
        double distance = deltaX * deltaX + deltaY * deltaY;
        
        /*
        if(deltaX < this.radius) {
        	this.speedX *= -1;
        	ball2.speedX *= -1;
        }
        if(deltaY < this.radius) {
        	this.speedY *= -1;
        	ball2.speedY *= -1;
        }
        */
        
        if(distance < (this.radius + ball2.radius) * (this.radius + ball2.radius)){
        	this.speedX *= -1;
        	//ball2.speedX *= -1;
        	this.speedY *= -1;
        	//ball2.speedY *= -1;
        }
     	
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
