//This is the code for thePump Node. This one will be
//Responsible for receiving the command from the Sensors Node
//and toggle the pump state

#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

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

WiFiUDP Udp;
unsigned int localUdpPort = 61555;
char incomingPacket[255];
char replyPacket[255]="ACK";
boolean pumpState;

const char *ssid =  "GomesFlores";     // replace with your wifi ssid and wpa2 key
const char *pass =  "PassWord007";

WiFiClient client;


//**********************************************
// Setup Routine
//**********************************************

void setup() {
	// put your setup code here, to run once:
	Serial.begin(9600);
	pinMode(03, OUTPUT);

   Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println(WiFi.localIP()); 
      Udp.begin(localUdpPort);
}

//**********************************************
// Main Loop
//**********************************************

void loop() {
	//State Machine
	  
	switch (nextState){

    //Current State     |   Core State funtion  |  end of the state
		case INITIALIZE:        initialize();             break;
		case READ_PUMP_STATE:   readPumpStates();      	  break;
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
      nextState = SEND_HB;
    }

//*********************************************
//READ PUMP STATE MESSAGE
//*********************************************

void readPumpStates(){

      //State function code
       Serial.println("Lendo estado da bomba...");
      //make a UDP Read function to get what is being send to me and put it to the packetBuffer[]
      
      //Transition Code

//      int packetSize = Udp.parsePacket();
//if (packetSize)
//{
//  int len = Udp.read(incomingPacket, 255);
//  if (len > 0)
//  {
//   if (incomingPacket == "ToPu")
//   {
//    nextState = TOGGLE_PUMP;
//     pumpState = true;
//    Serial.println("mudando estado!");
//   }else{
//    nextState = SEND_HB;
//    Serial.println("Na mesma");
//   }
//  }else{
 nextState = SEND_HB;
    Serial.println("voltando..."); 
//}

  //    }
      
//      //Check the Packet Buffer. If it is "CHANGE" so transition to TOGGLE_PUMP
//      pumpState = true; //tirar o comentário mais para frente
//      nextState = TOGGLE_PUMP;
//      //Else, transition to SEND_HB
//      nextState = SEND_HB;
}

//*********************************************
//TOGGLE PUMP STATE
//*********************************************

void togglePump(boolean pumpState){

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
      Udp.beginPacket("192.168.0.128", 61500);
      Udp.write("HB");
      Udp.endPacket();
      Serial.println("HB");
      //Transition Code
//int packetSize = Udp.parsePacket();
//if (packetSize)
//{
  int len = Udp.read(incomingPacket, 255);
  Serial.println(incomingPacket);
  Serial.println(String(len));
  if (len > 0)
  {
//   if (incomingPacket == replyPacket)
  // {
    nextState = READ_PUMP_STATE;
    Serial.println("Lendo estado da Bomba!");
   }else{
    nextState = SEND_HB;
    Serial.println("NACK");
   }
//  }else{
//  nextState = SEND_HB;
//    Serial.println("nao veio");
//}

     // }
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
