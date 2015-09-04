//Declaração da porta analógica A0 para receber a voltagem da bateria e a partir daí verificar o seu nível
const int Medidor_Bateria = A0;

//Variável que irá receber o valor analógico lido na porta A0 para verificar o nível da bateria
int Nivel_Bateria = 0;
float Nivel_Bateria_Voltagem = 0;

void setup()
{	
	// Inicialização da comunicação serial
	Serial.begin(9600);

}

void loop()
{
	// Leitura do valor que está sendo enviado da bateria para a porta A0
	Nivel_Bateria = analogRead(A0);
	Serial.print("Valor analógico da bateria = ");
	// imprimindo o valor analógico da carga da baterial na serial
	Serial.println(Nivel_Bateria);
	//Transformando o valor analógico para tensão
	Nivel_Bateria_Voltagem = 5 * Nivel_Bateria / 1023;
	//Imprimindo o valor da tensão
	Serial.print("Valor voltagem da bateria = ");
	Serial.println(Nivel_Bateria_Voltagem);
	delay(500);

}
