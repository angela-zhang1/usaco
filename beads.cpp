/*
ID: angela.11
TASK: beads
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main() {
 int beadNumber;
 string necklace;
 
 int maxBeads = 0;
 int x=0;
 int y=0;
 char backwardsBead;
 char forwardsBead;
 
 ifstream beadsIn("beads.in");
 beadsIn >> beadNumber >> necklace;
 beadsIn.close();
 beadNumber *= 2;
 necklace += necklace;
 for (int i = 0; i < beadNumber; i ++) {
  x = 0;
  y = 0;
  if (i == 0)
   backwardsBead = necklace[beadNumber - 1];
  else
   backwardsBead = necklace[i - 1];
  forwardsBead = necklace[i];
  
  for (int j = i; j < beadNumber; j++) {
   if (forwardsBead == 'w')
    forwardsBead = necklace[j];
   if (necklace[j] == forwardsBead || necklace[j] == 'w')
    x++;
   else
    break;
  }
  for (int j = i - 1; j >= 0; j--) {
   if (backwardsBead == 'w')
    backwardsBead = necklace[j];
   if (necklace[j] == backwardsBead || necklace[j] == 'w')
    y++;
   else
    break;
  }
  if ((x + y) > maxBeads)
   maxBeads = x + y;
 }
 if (maxBeads > beadNumber / 2)
  maxBeads = beadNumber/2;
 
 ofstream beadsOut("beads.out");
 
 beadsOut << maxBeads << "\n";
 
 beadsOut.close();
}
