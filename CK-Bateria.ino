//Declaração da porta analógica A0 para receber a voltagem da bateria e a partir daí verificar o seu nível
const int Medidor_Bateria = A0;

//Variável que irá receber o valor analógico lido na porta A0 para verificar o nível da bateria
int Nivel_Bateria = 0;
float Nivel_Bateria_Voltagem = 0;
float Carga_Bateria_porcentagem = 0;

void setup()
{	
	// Inicialização da comunicação serial
	Serial.begin(9600);

}

float carga_bateria(){
	// imprimindo o valor analógico da carga da baterial na serial
	//Transformando o valor analógico para tensão
	Nivel_Bateria = analogRead(A0);
	Nivel_Bateria_Voltagem = 12 * Nivel_Bateria / 1023;
	// porcentagem da bateria
	Carga_Bateria_porcentagem = 100 * Nivel_Bateria_Voltagem / 12;
	return Carga_Bateria_porcentagem;

}

bool bateria_baixa(){
	int x = 0;
	int cont = 0;
	if (carga_bateria() >= 40 ){
		// verificar 5 vezes se esse nivel continua abaixo, ou se foi apenas interferencia
		while(x < 5){
			// se a carga continuar com menos de 40% na segunda leitura, o soma-se 1 ao contador
			if(carga_bateria() <= 40){
				cont++;	
			}
			x++;
			// cada leitura e feita apos 200 ms
			delay(200);
		}
	}
	
	// se o contador for >= a 4, quer dizer que realmente a bateria esta ruim, entao acender led de aviso
	if(cont >= 4){
		return true;
	}else
		return false;
	    
}


void loop()
{
	Nivel_Bateria = analogRead(A0);
	if( bateria_baixa() ){
		Serial.println("Acenda led");
	    
	}

	
	


}


