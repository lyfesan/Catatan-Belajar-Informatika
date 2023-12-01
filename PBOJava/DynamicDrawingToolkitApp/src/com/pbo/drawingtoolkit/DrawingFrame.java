package com.pbo.drawingtoolkit;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.plaf.IconUIResource;

public class DrawingFrame extends JFrame {
	
	private static final long serialVersionUID = 3398165690356407806L;
	private JButton jbLine, jbCircle, jbRectangle, clear;
	private JPanel toolboxPanel, toolboxPadding;
	private static int frameWidth = 500, frameHeight = 500;
	public static DrawingCanvas canvas;
	
	public DrawingFrame() {
		
		super("Drawing Toolkit");
		JLabel statusLabel = new JLabel("");
		
		canvas = new DrawingCanvas(statusLabel);
		canvas.setBorder(BorderFactory.createLineBorder(Color.GRAY, 15));
		
		clear = new JButton("Clear");
		jbCircle = new JButton("Circle");
		jbLine = new JButton("Line");
		jbRectangle = new JButton("Rectangle");
		
		toolboxPanel = new JPanel();
		toolboxPanel.setLayout(new GridLayout(1,1,1,1));
		toolboxPadding = new JPanel();
		toolboxPadding.setLayout(new FlowLayout(FlowLayout.LEADING, 1, 1));
		
		toolboxPanel.add(clear);
		toolboxPanel.add(jbCircle);
		toolboxPanel.add(jbLine);
		toolboxPanel.add(jbRectangle);
		toolboxPadding.add(toolboxPanel);
		//ImageIcon icon = new ImageIcon();
		
		add(toolboxPadding, BorderLayout.SOUTH);
		add(canvas, BorderLayout.CENTER);
		
		ButtonHandler buttonHandler = new ButtonHandler();
		clear.addActionListener(buttonHandler);
		jbLine.addActionListener(buttonHandler);
		jbCircle.addActionListener(buttonHandler);
		jbRectangle.addActionListener(buttonHandler);
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		addWindowListener(new WindowAdapter(){
			@Override
			public void windowClosing(WindowEvent e) {
				int choose = JOptionPane.showConfirmDialog(null, 
						"Do you really want to exit the application?",
						"Confirm Close", JOptionPane.YES_NO_OPTION,
						JOptionPane.INFORMATION_MESSAGE);
				if(choose == JOptionPane.YES_OPTION) {
					e.getWindow().dispose();
					System.out.println("close");
				} else {
					setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
		
				}
			}
		});
		
		setSize(frameWidth,frameHeight);
		setVisible(true);
	}
	
	public int getFrameWidth() {
		return frameWidth;
	}
	
	public int getFrameHeight() {
		return frameHeight;
	}
	
	private class ButtonHandler implements ActionListener {
		
		public void actionPerformed(ActionEvent event) {
			if(event.getActionCommand().equals("Clear")) {
				canvas.clearDrawing();
			}
			else if(event.getActionCommand().equals("Line")) {
				canvas.setCurrentShapeType("line");
			}
			else if(event.getActionCommand().equals("Circle")) {
				canvas.setCurrentShapeType("circle");
			}
			else if(event.getActionCommand().equals("Rectangle")) {
				canvas.setCurrentShapeType("rectangle");
			}
		}
	}
}
