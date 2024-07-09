#include "kernel.h"

int main() {
  char buf[128];
  clearScreen();
  printString("Welcome to MengOS\n");

  while (1) {
    printString("$ ");
    readString(buf);
    printString(buf);
    printString("\n");
  }
}

void printString(char* str) {
  while (*str != 0) {
    //interrupt buat nampilin karakter
    interrupt(0x10, 0x0E * 256 + *str, 0, 0, 0);
    //nyimpen sring
    str++;
  }
}

void readString(char* buf) {
  int i = 0;
  char ch;
  while (1) {
    ch = interrupt(0x16, 0, 0, 0, 0);
    if (ch == '\r') {  
      buf[i] = 0;
      break;
    } else if (ch == '\b' && i > 0) {  
      i--;
      interrupt(0x10, 0x0E * 256 + '\b', 0, 0, 0);  // Move cursor back
      interrupt(0x10, 0x0E * 256 + ' ', 0, 0, 0);   // Erase character
      interrupt(0x10, 0x0E * 256 + '\b', 0, 0, 0);  // Move cursor back again
    } else if (ch != '\b') {
      buf[i] = ch;
      interrupt(0x10, 0x0E * 256 + ch, 0, 0, 0);
      i++;
    }
  }
}

void clearScreen() {
  int i;
  for (i = 0; i < 80 * 25; i++) {
    putInMemory(0xB800, 2 * i, ' ');
    putInMemory(0xB800, 2 * i + 1, 0x07);
  }
  interrupt(0x10, 0x02 * 256, 0, 0, 0);  // Move cursor to (0,0)
}
