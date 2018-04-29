

//**********************************************
// Global Variables
//**********************************************

enum states {
  
  INITIALIZE,
  READ_SENSORS,
  TOGGLE_PUMP,
  READ_HB,
  SAFE_STATE,
  HANDLE_ERROR,
  LOG_ERROR,
  IDLE_STATE,
  RECONNECT_WIFI
  
 };

states nextState = INITIALIZE;

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
		case READ_SENSORS:      readSensors();      	    break;
		case TOGGLE_PUMP:       togglePump(false);        break;
    case READ_HB:           heartBeat();              break;
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
      nextState = READ_SENSORS;
    }

//*********************************************
//READ SENSORS - GET THEIR STATES
//*********************************************

void readSensors(){

      //State function code
      Serial.println("Lendo Sensores...");
      //Transition Code
      nextState = TOGGLE_PUMP;
}

//*********************************************
//TOGGLE PUMP STATE
//*********************************************

void togglePump(boolean pumpState){

   if(pumpState){ 
      //State function code
      Serial.println("aciona bomba!");
      //Transition Code
      nextState = READ_HB;

}else{

      //State function code
      Serial.println("desliga bomba!");
      //Transition Code
      nextState = SAFE_STATE;
}
}

//*********************************************
//READ HEARTBEAT
//*********************************************

void heartBeat(){
      //State function code
      Serial.println("HB ACK");
      //Transition Code
      nextState = READ_SENSORS;
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
