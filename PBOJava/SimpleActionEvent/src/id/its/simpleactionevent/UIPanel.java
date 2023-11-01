package id.its.simpleactionevent;

import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class UIPanel extends JPanel implements ActionListener {
	
	private static final long serialVersionUID = 4434284526519342444L;

	public UIPanel(int width, int height) {
	
		this.setPreferredSize(new Dimension(width, height));
		
		//buat button dan tambahkan ke panel
		JButton button = new JButton("Click This Button!");
		
		Font font = new Font("FreeSans", Font.BOLD , 12);
		button.setFont(font);
		
		this.add(button);
		//button.setBounds(200, 100, 100, 20);
	    
		//bind event action
		button.addActionListener(this);	
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		JOptionPane.showMessageDialog(this, "Anda telah mengaktifkan action event");
	}
}