#include <Wire.h>
/*define delay uri mari
functie cu for pt delay
*/

// definire întărzieri

#define DELAY1 1000
#define DELAY2 2000
#define DELAY3 5000
#define DELAY4 15000
#define DELAY5 20000
//**
const int B1_P = 13;

// definire variabile globale
const int B23_r_P = 12; // tipul numele = pinul
const int B23_g_P = 11;
const int B45_r_P = 10;
//....
const int B45_g_P = 9;
const int B67_r_P = 8;
const int B67_g_P = 7;
const int B89_r_P = 6;
const int B89_g_P = 14;
const int B1_r_M = 5;
const int B1_g_M = 4;
const int B2_r_M = 3;
const int B2_g_M = 2;
const int B34_r_M = 15;
const int B34_g_M = 16;

char input, input1;

void setup()
{ // setează pinii, inițializează variabile, începe să utilizeze biblioteci

    pinMode(B23_r_P, OUTPUT);
    pinMode(B23_g_P, OUTPUT);
    pinMode(B45_r_P, OUTPUT);
    pinMode(B45_g_P, OUTPUT);
    pinMode(B67_g_P, OUTPUT);
    pinMode(B67_r_P, OUTPUT);
    pinMode(B89_g_P, OUTPUT);
    pinMode(B89_r_P, OUTPUT);
    pinMode(B1_r_M, OUTPUT);
    pinMode(B1_g_M, OUTPUT);
    pinMode(B2_r_M, OUTPUT);
    pinMode(B2_g_M, OUTPUT);
    pinMode(B34_r_M, OUTPUT);
    pinMode(B34_g_M, OUTPUT);
    //...
    Wire.begin();       // începe o legătură
    Serial.begin(9600); // începe transmiterea serială
}

int ok;
char anterior = 'S';

// seteaza culoarea becului RGB primit ca referinta
void setColor(const int P1, const int P2, int R, int G)
{
    analogWrite(P1, R);
    analogWrite(P2, G);
}

// functie pentru setarea semafoarelor
void culori(char c, char s)
{
    int r = 0, g = 0;
    int b_g = 0;
    switch (c)
    { // switch case pentru cele 3 culori de semafor si cand e stins
    case 'V':
        r = 0;
        g = 255;
        b_g = 0;
        break;
    case 'R':
        r = 255;
        g = 0;
        b_g = 0;
        break;
    case 'G':
        r = 255;
        g = 255;
        b_g = 255;
        break;
    case 'S':
        r = 0;
        g = 0;
        b_g = 0;
        break;
    }

    if (s == 'T')
    { // seteaza toate semafoarele
        // analogWrite(B1_P,b_g);
        setColor(B23_r_P, B23_g_P, r, g);
        setColor(B45_r_P, B45_g_P, r, g);
        setColor(B67_r_P, B67_g_P, r, g);
        setColor(B89_r_P, B89_g_P, r, g);
        setColor(B1_r_M, B1_g_M, r, g);
        setColor(B2_r_M, B2_g_M, r, g);
        setColor(B34_r_M, B34_g_M, r, g);
    }
    if (s == 'M')
    { // seteaza semafoarele pentru masini
        setColor(B1_r_M, B1_g_M, r, g);
        setColor(B2_r_M, B2_g_M, r, g);
        setColor(B34_r_M, B34_g_M, r, g);
    }
    if (s == 'P')
    { // seteaza semafoarele pentru pietoni
        setColor(B23_r_P, B23_g_P, r, g);
        setColor(B45_r_P, B45_g_P, r, g);
        setColor(B67_r_P, B67_g_P, r, g);
        setColor(B89_r_P, B89_g_P, r, g);
    }
}

bool delay_n(int d)
{
    // funcție care primește ca parametru un delay și daca se citește
    // alt caracter de la monitorul serial returnează true
    for (int i = 0; i < d; i = i + 100)
    {
        delay(100);
        if (Serial.available())
        {
            input = Serial.read();
            return true;
        }
    }
    return false;
}

bool delay_n1(int d)
{
    // funcție care primește ca parametru un delay și daca se citește
    // alt caracter de la monitorul serial returnează true
    for (int i = 0; i < d; i = i + 100)
    {
        delay(100);
        if (Serial.available())
        {
            Wire.beginTransmission(1);
            if (input1 != 'T' && input1 != 'X')
                anterior = input1;
            input1 = Serial.read();
            Wire.write(input1);
            Wire.endTransmission();
            return true;
        }
    }
    return false;
}
void normal() // starea 1/functionarea normala
{
    setColor(B23_r_P, B23_g_P, 0, 255);
    setColor(B45_r_P, B45_g_P, 255, 0);
    setColor(B67_r_P, B67_g_P, 0, 255);
    setColor(B89_r_P, B89_g_P, 255, 0);
    setColor(B1_r_M, B1_g_M, 0, 255);
    setColor(B2_r_M, B2_g_M, 255, 0);
    setColor(B34_r_M, B34_g_M, 0, 255);
    // dacă este true se iese din funcție
    if (delay_n(DELAY4) == true)
        return;
    //...
    setColor(B23_r_P, B23_g_P, 0, 0);
    setColor(B67_r_P, B67_g_P, 0, 0);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B23_r_P, B23_g_P, 0, 255);
    setColor(B67_r_P, B67_g_P, 0, 255);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B23_r_P, B23_g_P, 0, 0);
    setColor(B67_r_P, B67_g_P, 0, 0);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B23_r_P, B23_g_P, 0, 255);
    setColor(B67_r_P, B67_g_P, 0, 255);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B23_r_P, B23_g_P, 0, 0);
    setColor(B67_r_P, B67_g_P, 0, 0);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B23_r_P, B23_g_P, 255, 0);
    setColor(B67_r_P, B67_g_P, 255, 0);
    if (delay_n(DELAY5) == true)
        return;
    setColor(B1_r_M, B1_g_M, 255, 255);
    setColor(B34_r_M, B34_g_M, 255, 255);
    if (delay_n(DELAY3) == true)
        return;
    setColor(B1_r_M, B1_g_M, 255, 0);
    setColor(B34_r_M, B34_g_M, 255, 0);
    if (delay_n(DELAY3) == true)
        return;
    setColor(B45_r_P, B45_g_P, 0, 255);
    setColor(B89_r_P, B89_g_P, 0, 255);
    setColor(B2_r_M, B2_g_M, 0, 255);
    if (delay_n(DELAY4) == true)
        return;
    setColor(B45_r_P, B45_g_P, 0, 0);
    setColor(B89_r_P, B89_g_P, 0, 0);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B45_r_P, B45_g_P, 0, 255);
    setColor(B89_r_P, B89_g_P, 0, 255);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B45_r_P, B45_g_P, 0, 0);
    setColor(B89_r_P, B89_g_P, 0, 0);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B45_r_P, B45_g_P, 0, 255);
    setColor(B89_r_P, B89_g_P, 0, 255);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B45_r_P, B45_g_P, 0, 0);
    setColor(B89_r_P, B89_g_P, 0, 0);
    if (delay_n(DELAY1) == true)
        return;
    setColor(B45_r_P, B45_g_P, 255, 0);
    setColor(B89_r_P, B89_g_P, 255, 0);
    if (delay_n(DELAY5) == true)
        return;
    setColor(B2_r_M, B2_g_M, 255, 255);
    if (delay_n(DELAY3) == true)
        return;
    setColor(B2_r_M, B2_g_M, 255, 0);
    if (delay_n(DELAY3) == true)
        return;
}

void funct_x() // starea 3, la primirea caracterului 'X'
{
    culori('S', 'T');
    if (delay_n1(DELAY2) == true)
        return;
    culori('R', 'T');
    if (delay_n1(DELAY2) == true)
        return;
    culori('S', 'P');
    culori('G', 'M');
    if (delay_n1(DELAY2) == true)
        return;
    culori('V', 'T');
    if (delay_n1(DELAY2) == true)
        return;
}

void funct_t(char anterior) // starea 3, la primirea caracterului 'T'
{

    if (anterior == 'S')
    {
        culori('G', 'T');
        // analogWrite(B1_P,255);
    }
    else
    {
        culori(anterior, 'T');
        // analogWrite(B1_P,255);
    }
    delay(DELAY1);
    culori('S', 'T');
    // analogWrite(B1_P,0);
    delay(DELAY1);
}

void funct_b() // starea 2 /modul intermitent
{
    culori('G', 'T');
    delay(DELAY1);
    culori('S', 'T');
    delay(DELAY1);
}

void loop()
{
    Wire.beginTransmission(1);
    if (Serial.available())
    {
        Wire.beginTransmission(1); // se incepe comunicarea intre cele 2 placute
        input = Serial.read();     // se citeste un caracter de la monitorul serial
        Serial.print("You typed:");
        Serial.println(input);
        Wire.write(input);      // se scriu date de la un dispozitiv periferic în răspuns la o cerere din partea unui dispozitiv de control
        Wire.endTransmission(); // se incheie transmisia
    }
    if (input == 'N')
    { // starea 1
        normal();
    }
    if (input == 'B')
    { // starea 2
        funct_b();
    }
    if (input == 'D')
    { // starea 3
        ok = 1;
        culori('S', 'T'); // se sting toate semafoarele
        do
        {
            if (Serial.available())
            {
                //...
                Wire.beginTransmission(1);
                input1 = Serial.read();
                Serial.print("You typed 1:");
                Serial.println(input1);
                Wire.write(input1);
                Wire.endTransmission();
                if (input1 != 'T' && input1 != 'X')
                { // se retine inputul anterior
                    anterior = input1;
                }
            }
            if (input1 == 'T')
            { // se executa funct_t avand ca parametru inputul anterior
                funct_t(anterior);
            }
            culori(input1, 'T');
            if (input1 == 'X')
            {
                funct_x();
                break;
            }
            // if(input1=='G')
            // analogWrite(B1_P,255);
            if (input1 == 'B')
            { // ok se pune pe 0 si se iese din do while
                ok = 0;
                input = 'B';
                input1 = 'S';
            }
            if (input1 == 'N')
            { // ok se pune pe 0 si se iese din do while
                ok = 0;
                input = 'N';
                input1 = 'S';
            }
        } while (ok != 0);
    }
}