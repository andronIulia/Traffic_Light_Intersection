#include <Wire.h>
// inițializare variabilă globală
const int B1_P = 13;

void setup() // setează pinii, inițializează variabile, începe să utilizeze biblioteci
{
    pinMode(B1_P, OUTPUT);
    Wire.begin(1);                // începe comunicarea
    Wire.onReceive(receiveEvent); // înregistrează o funcție care este apelată când se primește o informație
}

char input, input1;

char c;
char ant;

void receiveEvent(int howMany)
{                         // primește informații în format de biți de la plăcuța U1
    if (Wire.available()) // verifică dacă există informație transmisă de la U1
        c = Wire.read();  // primește bitul ca și caracter
    if (c != 'T' && c != 'X')
        ant = c;
}
void loop()
{
    // ant=c;
    if (c == 'B' || c == 'N')
    { // stăriile N și B(Starea 1 și Starea 2)
        analogWrite(B1_P, 255);
        delay(1000);
        analogWrite(B1_P, 0);
        delay(1000);
    }
    // Starea 3
    if (c == 'T' && ant != 'R' && ant != 'V')
    { // Starea "T"
        analogWrite(B1_P, 255);
        delay(1000);
        analogWrite(B1_P, 0);
        delay(1000);
    }
    if (c == 'G')
    { // Starea "G"
        analogWrite(B1_P, 255);
        // ant='G';
    }
    if (c == 'V' || c == 'R' || c == 'X')
        analogWrite(B1_P, 0);
    // if(ant=='X' && c=='G')
    // analogWrite(B1_P,255);
}
