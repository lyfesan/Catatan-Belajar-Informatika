package id.its.pbo.test;

import static org.junit.jupiter.api.Assertions.assertEquals;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import id.its.pbo.test.Calculator;

public class CalculatorTest {

	Calculator calculator;
	
	@BeforeEach
	void setUp() {
		calculator = new Calculator();
	}
	
	@Test
	@DisplayName("Dapat melakukan penambahan sederhana")
	void testAdd() {
		assertEquals(5, this.calculator.add(3, 2));
		assertEquals(5, this.calculator.add(2, 3));
	}
	
	@Test
	@DisplayName("Dapat melakukan pengurangan sederhana")
	void testSubtract() {
		assertEquals(2, this.calculator.subtract(4, 2));
		assertEquals(-2, this.calculator.subtract(2, 4));
	}
	
	@Test
	@DisplayName("Dapat melakukan perkalian sederhana")
	void testMultiply() {
		assertEquals(20, this.calculator.multiply(4, 5));
		assertEquals(20, this.calculator.multiply(5, 4));
	}
	
	@Test
	@DisplayName("Dapat melakukan pembagian sederhana")
	void testDivide() {
		assertEquals(2, this.calculator.divide(4, 2));
		assertEquals(0.5, this.calculator.divide(2, 4));
	}
	
	@Test
	@DisplayName("Dapat menangani perkalian dengan 0")
	void testMultiplyWithZero() {
		assertEquals(0, this.calculator.multiply(4, 0));
		assertEquals(0, this.calculator.multiply(0, 4));
	}

}
