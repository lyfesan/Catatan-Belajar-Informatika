package com.pbo.drawingtoolkit;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.ArrayList;

import javax.swing.JLabel;
import javax.swing.JPanel;

public class DrawingCanvas extends JPanel {
	
	private static final long serialVersionUID = -5305035303464928738L;
	private ArrayList<DrawingObject> myShapes;
	private String currentShapeType;
	private DrawingObject currentShapeObject;
	private Color currentShapeColor;
	
	JLabel statusLabel;
	
	public DrawingCanvas(JLabel statusLabel) {
		myShapes = new ArrayList<DrawingObject>();
		currentShapeType = "";
		currentShapeObject = null;
		currentShapeColor = Color.BLACK;
		
		this.statusLabel = statusLabel;
		setLayout(null);
		setBackground(Color.WHITE);
		add(statusLabel, BorderLayout.SOUTH);
		
		MouseHandler handler = new MouseHandler();
		addMouseListener(handler);
		addMouseMotionListener(handler);
	}
	
	public void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		for(int counter = myShapes.size()-1; counter >= 0; counter--) {
			myShapes.get(counter).draw(g);
		}
		
		if(currentShapeObject!=null) {
			currentShapeObject.draw(g);
		}
		
	}
	
	public void setCurrentShapeType(String type) {
		currentShapeType=type;
	}
	
	public void clearDrawing() {
		myShapes.clear();
		currentShapeType = null;
		repaint();
	}
	
	private class MouseHandler extends MouseAdapter{
		
		public void mousePressed(MouseEvent event) {
			if(currentShapeType == "line") {
				currentShapeObject = new Line(event.getX(), event.getY(),
						event.getX(), event.getY(), currentShapeColor);
			}
			else if(currentShapeType == "circle") {
				currentShapeObject = new Circle(event.getX(), event.getY(),
						event.getX(), event.getY(), currentShapeColor, false);
			}
			else if(currentShapeType == "rectangle") {
				currentShapeObject = new Rectangle(event.getX(), event.getY(),
						event.getX(), event.getY(), currentShapeColor, false);
			}
			//repaint();
		}
		
		public void mouseReleased(MouseEvent event) {
			currentShapeObject.setX2(event.getX());
			currentShapeObject.setY2(event.getY());
			
			myShapes.add(currentShapeObject);
			System.out.println(myShapes.toArray());
			
			currentShapeObject = null;
			repaint();
		}
		
		public void mouseMoved(MouseEvent event) {
			statusLabel.setText(String.format("Mouse coordinates X: %d Y: %d", event.getX(), event.getY()));
		}
		
		public void mouseDragged(MouseEvent event) {
			currentShapeObject.setX2(event.getX());
			currentShapeObject.setY2(event.getY());
			statusLabel.setText(String.format("Mouse coordinates X: %d Y: %d", event.getX(), event.getY()));
			repaint();
		}
		
	}
		
}
