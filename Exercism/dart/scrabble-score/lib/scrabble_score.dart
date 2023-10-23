int scoring (String c){
  if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='L' || c=='N' || c=='R' || c=='S' || c=='T') return 1;
  if(c=='D' || c=='G') return 2;
  if(c=='B' || c=='C' || c=='M' || c=='P') return 3;
  if(c=='F' || c=='H' || c=='V' || c=='W' || c=='Y') return 4;
  if(c=='K') return 5;
  if(c=='J' || c=='X') return 8;
  if(c=='Q' || c=='Z') return 10;
  return 0;
}

int score (String s) {
  int total=0;
  for(int i=0; i<s.length; i++){
    total+=scoring(s[i].toUpperCase());
  }
  return total;
}
