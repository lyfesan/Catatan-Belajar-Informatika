package id.its.simplemouseevent;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JPanel;

public class MousePanel extends JPanel implements MouseListener, MouseMotionListener {
	
	private static final long serialVersionUID = 8171036699248929650L;
	
	private int areaWidth;
	private int areaHeight;
	private String text, info;
	
	public MousePanel(int width, int height) {
		this.areaWidth = width;
		this.areaHeight = height;
		
		this.setPreferredSize(new Dimension(areaWidth, areaHeight));
		
		this.text = "Lakukan sesuatu menggunakan mouse...";
		this.info = "Info Mouse...";
		
		this.addMouseMotionListener(this);
		this.addMouseListener(this);
		this.setFocusable(true);
	}
	
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);
		
		g.drawString(this.info, 0, 15);
		g.drawString(this.text, 0, this.areaHeight / 2);
	}
	
	public void mouseClicked(MouseEvent e) {
		this.text = "Tombol mouse diklik pada posisi X: " + e.getX() +
		" Y: " + e.getY();
		repaint();
	}
	
	public void mousePressed(MouseEvent e) {
		this.text = "Tombol mouse ditekan pada posisi X: " + e.getX() + " Y: " + e.getY();
		repaint();
	}
	
	public void mouseReleased(MouseEvent e) {
		this.text = "Tombol mouse dilepas pada posisi X: " + e.getX() + " Y: " + e.getY();
		repaint();
	}
	
	public void mouseEntered(MouseEvent e) {
		this.text = "Mouse memasuki area MousePanel";
		repaint();
	}
	
	public void mouseExited(MouseEvent e) {
		this.text = "Mouse meninggalkan area MousePanel";
		repaint();
	}

	public void mouseDragged(MouseEvent e) {
		this.info = "Position X = " + e.getX() + " Y = " + e.getY() + " Dragged";
		repaint();
	}

	public void mouseMoved(MouseEvent e) {
		this.info = "Position X = " + e.getX() + " Y = " + e.getY();
		repaint();
	}
}
