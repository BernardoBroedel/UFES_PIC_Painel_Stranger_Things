int pinData = 13;
int pinLatch = 12;
int pinClock = 11;
int y = 2;
int z = 3;

#define TEMPO 1000

String text; //string para receber o texto

//Funções
void recebeTexto();
void piscaLED(String text);
void moduloLED(int RLed, int GLed, int BLed);

void setup(){
    Serial.begin(9600);

    pinMode(pinData, OUTPUT);
    pinMode(pinLatch, OUTPUT);
    pinMode(pinClock, OUTPUT);
    pinMode(y, OUTPUT);
    pinMode(z, OUTPUT);
}

void loop(){
    recebeTexto();
}

//Função que recebe o texto digitado
void recebeTexto(){
    while (Serial.available() > 0){
        char c = Serial.read();
        if (c != '\n'){
            //concat na string
            text.concat(c);
        }
        delay(10);
    }

    //verifica tamanho da string
    if (text.length() > 0){
        //passa string pra maiusculo
        text.toUpperCase();
        piscaLED(text);
    }
    //limpa a string text
    text = "";
}

void piscaLED(String text){
    for(int i = 0; i < text.length(); i++){
        if(text[i] == 'A'){
            moduloLED(128,0,0);
            delay(TEMPO);
        }else if(text[i] == 'B'){
            moduloLED(64,0,0);
            delay(TEMPO);
        }else if(text[i] == 'C'){
            moduloLED(32,0,0);
            delay(TEMPO);
        }else if(text[i] == 'D'){
            moduloLED(16,0,0);
            delay(TEMPO);
        }else if(text[i] == 'E'){
            moduloLED(8,0,0);
            delay(TEMPO);
        }else if(text[i] == 'F'){
            moduloLED(4,0,0);
            delay(TEMPO);
        }else if(text[i] == 'G'){
            moduloLED(2,0,0);
            delay(TEMPO);
        }else if(text[i] == 'H'){
            moduloLED(1,0,0);
            delay(TEMPO);
        }else if(text[i] == 'I'){
            moduloLED(0,128,0);
            delay(TEMPO);
        }else if(text[i] == 'J'){
            moduloLED(0,64,0);
            delay(TEMPO);
        }else if(text[i] == 'K'){
            moduloLED(0,32,0);
            delay(TEMPO);
        }else if(text[i] == 'L'){
            moduloLED(0,16,0);
            delay(TEMPO);
        }else if(text[i] == 'M'){
            moduloLED(0,8,0);
            delay(TEMPO);
        }else if(text[i] == 'N'){
            moduloLED(0,4,0);
            delay(TEMPO);
        }else if(text[i] == 'O'){
            moduloLED(0,2,0);
            delay(TEMPO);
        }else if(text[i] == 'P'){
            moduloLED(0,1,0);
            delay(TEMPO);
        }else if(text[i] == 'Q'){
            moduloLED(0,0,128);
            delay(TEMPO);
        }else if(text[i] == 'R'){
            moduloLED(0,0,64);
            delay(TEMPO);
        }else if(text[i] == 'S'){
            moduloLED(0,0,32);
            delay(TEMPO);
        }else if(text[i] == 'T'){
            moduloLED(0,0,16);
            delay(TEMPO);
        }else if(text[i] == 'U'){
            moduloLED(0,0,8);
            delay(TEMPO);
        }else if(text[i] == 'V'){
            moduloLED(0,0,4);
            delay(TEMPO);
        }else if(text[i] == 'W'){
            moduloLED(0,0,2);
            delay(TEMPO);
        }else if(text[i] == 'X'){
            moduloLED(0,0,1);
            delay(TEMPO);
        }else if(text[i] == 'Y'){
            digitalWrite(y, HIGH);
            delay(TEMPO);
            digitalWrite(y, LOW);
            delay(TEMPO);
        }else if(text[i] == 'Z'){
            digitalWrite(z, HIGH);
            delay(TEMPO);
            digitalWrite(z, LOW);
            delay(TEMPO);
        }
    }
}


void moduloLED(int RLed, int GLed, int BLed){
   shiftOut(pinData, pinClock, LSBFIRST, BLed);
   shiftOut(pinData, pinClock, LSBFIRST, GLed);
   shiftOut(pinData, pinClock, LSBFIRST, RLed);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);
}