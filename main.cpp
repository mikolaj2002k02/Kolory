#include <iostream>
#include <bitset>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;
int main(int argc, char** argv) {
int kolor = 0x00aa5500;
int kolor2 = 0x00ffffff;
int red = 0x00ff0000;//kolor red
int green = 0x0000ff00;// kolor green
int blue = 0x000000ff;// kolor blue


int partBlue = (kolor & blue);
int partRed = (kolor & red);
int partGreen = (kolor & green);
int partBlue2 = (kolor2 & blue);
int partRed2 =  (kolor2 & red);
int partGreen2 = (kolor2 & green);

partRed >>=16; //przesuniecie o 2 kolory 4 zera w cyfrze (ka¿da para cyfr to 8 bitów)
partGreen >>=8;
partGreen2 >>=8;
partRed2 >>=16;


cout << "czerwony: "  << hex << partRed <<endl
<< "zielony: " << hex << partGreen <<endl
<< "niebieski: "  << hex << partBlue <<endl ;
cout << "czerwony drugi: "  << hex << partRed2 <<endl
<< "zielony drugi: " << hex << partGreen2 <<endl
<< "niebieski drugi: "  << hex << partBlue2 <<endl ;

//nowy kolor jest jak stary tylko ma na pocz¹tku f 34->f4

int newRed =(partRed | 0xf0); // tego 16 w lewo 
int newGreen =(partGreen | 0xf0); //trzeba w lewo 0 8 cyfr
int newBlue = (partBlue | 0xf0); //zostaje ostatnie 2 cyfry
newRed <<= 16;
newGreen <<= 8;
int newColor = (newRed | newGreen | newBlue);

cout << newColor << endl;

int newRed2 =(partRed2 | 0xf0); // tego 16 w lewo 
int newGreen2 =(partGreen2 | 0xf0); //trzeba w lewo 0 8 cyfr
int newBlue2 = (partBlue2 | 0xf0); //zostaje ostatnie 2 cyfry
newRed2 <<= 16;
newGreen2 <<= 8;
int newColor2 = (newRed2 | newGreen2 | newBlue2);
cout << newColor2 << endl;



int stepR = (newRed2-newRed)/20;
int stepG = (newGreen2-newGreen)/20;
int stepB = (newBlue2-newBlue)/20;
int stepColor = (stepR | stepG | stepB);

cout << "Step Kolor: " << stepColor << endl;
	return 0;
}
