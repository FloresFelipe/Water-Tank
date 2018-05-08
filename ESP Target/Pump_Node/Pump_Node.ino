//This is the code for the Pump Node. This one will be
//Responsible for receiving the command from the Sensors Node
//and toggle the pump state


//**********************************************
// Global Variables
//**********************************************

enum states {
  
  INITIALIZE,
  READ_PUMP_STATE,
  TOGGLE_PUMP,
  SEND_HB,
  SAFE_STATE,
  HANDLE_ERROR,
  LOG_ERROR,
  IDLE_STATE,
  RECONNECT_WIFI
  
 };

states nextState = INITIALIZE;

char packetBuffer[255];
boolean pumpState;


//**********************************************
// Setup Routine
//**********************************************

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(03, OUTPUT);
}

//**********************************************
// Main Loop
//**********************************************

void loop() {
	//State Machine
	  
	switch (nextState){

    //Current State     |   Core State funtion  |  end of the state
		case INITIALIZE:        initialize();             break;
		case READ_PUMP_STATES:  readPumpStates();      	  break;
		case TOGGLE_PUMP:       togglePump(pumpState);    break;
    case SEND_HB:           heartBeat();              break;
    case SAFE_STATE:        safeState();              break;
    case HANDLE_ERROR:      handleError();            break;
    case LOG_ERROR:         logError();               break;
    case IDLE_STATE:        idleState();              break;
    case RECONNECT_WIFI:    reconnectWifi();          break;
     
 }
 
	delay(500);
}

//*********************************************
//Core State Functions
//*********************************************


//*********************************************
//INITIALIZE
//*********************************************

void initialize() {

      //State function code
      Serial.println("Inicializando Dispositivo...");
      //Transition Code
      nextState = READ_PUMP_STATES;
    }

//*********************************************
//READ PUMP STATE MESSAGE
//*********************************************

void readPumpStates(){

      //State function code
       Serial.println("Lendo estado da bomba...");
      //make a UDP Read function to get what is being send to me and put it to the packetBuffer[]
      
      //Transition Code
      //Check the Packet Buffer. If it is "CHANGE" so transition to TOGGLE_PUMP
      //boolean pumpState = true tirar o comentário mais para frente
      nextState = TOGGLE_PUMP;
      //Else, transition to SEND_HB
      nextState = SEND_HB;
}

//*********************************************
//TOGGLE PUMP STATE
//*********************************************

void togglePump(pumpState){

   if(pumpState){ 
      //State function code
      Serial.println("aciona bomba!");
      //Transition Code
      nextState = SEND_HB;

}else{

      //State function code
      Serial.println("desliga bomba!");
      //Transition Code
      nextState = SAFE_STATE;
}
}

//*********************************************
//SEND HEARTBEAT
//*********************************************

void heartBeat(){
      //State function code
      Serial.println("HB ACK");
      //Transition Code
      //SE EU LER O SINAL, VOLTAR E LER O ESTADO DA BOMBA
      nextState = READ_PUMP_STATES;      
      //SE EU NÃO LER O SINAL, DESVIAR PARA O SAFE STATE
      nextState = SAFE_STATE;
      }

//*********************************************
//SAFE STATE
//*********************************************

void safeState(){
  Serial.println("ih, deu ruim");
  nextState = HANDLE_ERROR;
}


//*********************************************
//HANDLE ERROR
//*********************************************

void handleError(){
  Serial.println("Pera, deixa eu ver...");
  nextState = LOG_ERROR;
}

//*********************************************
//LOG ERROR
//*********************************************

void logError(){
  Serial.println("Registrando Erros...");
  nextState = IDLE_STATE;
}

//*********************************************
//IDLE STATE
//*********************************************

void idleState(){
  Serial.println("aguardando...");
  nextState = RECONNECT_WIFI;
}

//*********************************************
//RECONNECT WIFI
//*********************************************

void reconnectWifi(){
  Serial.println("reconectando a rede WiFi...");
  nextState = INITIALIZE;
}
//*********************************************
//Transition Functions
//*********************************************

//Is there a way to create separate functions to determine the state transitions
