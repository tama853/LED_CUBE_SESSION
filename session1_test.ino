
//initializing and declaring led rows
  int column[9]={2,3,4,5,6,7,8,9,10};
//initializing and declaring led layers
  int layer[3]={A0,A1,A2};

  int time = 100;
  int testPin = A0;
 
void setup()
{
  //setting rows to ouput
  for (int i = 0; i < 9; i++)
  {
    pinMode(column[i], OUTPUT);
  }
  
  //setting layers to output
  for (int i = 0; i < 3; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
}


void loop()
{  
    turnEverythingOn();
}


///////////////////////////////////////////////////////////turn all on
void turnEverythingOn()
 {
   for (int i = 0; i < 9; i++)
   {
     digitalWrite(column[i], 1);
   }
   for (int i = 0; i < 3; i++)
   {
     digitalWrite(layer[i], 0);
   }
 }
