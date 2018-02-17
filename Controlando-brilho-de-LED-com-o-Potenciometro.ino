//Controle do brilho de um LED usando PWM
//Babuino.tec
//vagnerromario@hotmail.com

int pinoled = 10;  //Pino ligado ao anodo do led
int pinopot = A0;   //Pino ligado ao pino central do potenciometro
int valorpot = 0;  //Armazena valor lido do potenciometro, entre 0 e 1023

float luminosidade = 0; //Valor de luminosidade do led

void setup()
{
   Serial.begin(9600);        //Inicializa a serial
   pinMode(pinoled, OUTPUT);  //Define o pino do led como saída
   pinMode(pinopot, INPUT);   //Define o pino do potenciometro como entrada
}

void loop()
{
  // Le o valor - analogico - do pino do potenciometro
  valorpot = analogRead(pinopot);

  //Converte e atribui para a variavel "luminosidade" o
  // valor lido do potenciometro
  luminosidade = map(valorpot, 1, 1020, 0, 255);  

  Serial.print("Valor lido do potenciometro : "); 

  //Mostra o valor lido do potenciometro no monitor serial
  Serial.print(valorpot);   
  Serial.print(" = Luminosidade : ");

  //Mostra o valor da luminosidade no monitor serial
 Serial.println(luminosidade);  
 
  //Envia sinal analogico para a saída do led, com luminosidade variavel
  analogWrite(pinoled, luminosidade);  
  delay(10);
}
