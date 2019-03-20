/*
  3x3x3 LED Cube
  Connection Setup: 
  Columns
  [(x,y)-Pin]
  (1,1)-13
  (1,2)-9
  (1,3)-11
  (1,3)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,3)-6
  (3,1)-5
  (3-2)-3
  (3-3)-3
  (3,3)-2
  (3,1)-1
  (3,2)-0
  (3,3)-A5
  (3,3)-A3
  Layers
  
*/
//initializing and declaring led rows
  int column[9]={2,3,4,5,6,7,8,9,10};
//initializing and declaring led layers
  int layer[3]={A0,A1,A2};

  int time = 250;
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
  //seeding random for random pattern
  //randomSeed(analogRead(10));
}

//xxxxxxxxxxxxxxxxxxxxFUNCTION LOOPxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

void loop()
{
 
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(column[i], 0);
  }
  
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(layer[i], 1);
  }
    turnOnOnebyOne();
    turnEverythingOn();//turn all on
    flickerOn();
    delay(time);
    flickerOff();
  mytest();
    turnOnAndOffAllByLayerUpAndDownNotTimed();
//  layerstompUpAndDown(); not working
//  turnOnAndOffAllByColumnSideways(); not working
//  delay(time);
//  aroundEdgeDown(); not working
//  turnEverythingOff();
//  delay(time);
//    randomflicker();
//  delay(time);
//  randomRain();
//  diagonalRectangle();
//  goThroughAllLedsOneAtATime(); not working
//  propeller(); not working
//  spiralInAndOut();
  
//  turnEverythingOff();
//  delay(100);
}


//xxxxxxxxxxxxxxxxxxxxFUNCTIONSxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void  mytest()
{
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      delay(100);
      for (int k = 0; k < 3; k++)
      {
        digitalWrite(layer[k], 0);
        digitalWrite(column[i], 1);
        delay(100);
        digitalWrite(layer[k], 1);
      }
    }
  }
}


void turnOnOnebyOne()
{
        digitalWrite(layer[0], 0);
        digitalWrite(layer[1], 0);
        digitalWrite(layer[2], 0);
        digitalWrite(column[0], 0);
  for (int i = 0; i < 9; i++)
  {
      for (int j = 0; j < 3; j++)
      {
        digitalWrite(layer[j], 0);
        digitalWrite(column[i], 1);
        delay(50);
        digitalWrite(layer[j], 1);
        digitalWrite(column[i], 0);
      }
      
      for (int j = 0; j < 3; j++)
      {
        digitalWrite(layer[3-j], 0);
        digitalWrite(column[i], 1);
        delay(50);
        digitalWrite(layer[j], 1);
        digitalWrite(column[i], 0);
      }
  }
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
 
////////////////////////////////////////////////////////////turn all off
void turnEverythingOff()
{
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(column[i], 0);
  }
  //turning on layers
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(layer[i], 1);
  }
}

///////////////////////////////////////////////////////turn columns off
void turnColumnsOff()
{
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(column[i], 0);
  }
}

///////////////////////////////////////////////////////turn columns on
void turnColumnsOn()
{
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(column[i], 1);
  }
}
/////////////////////////////////////////////////////////////flicker on
void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    turnEverythingOn();
    delay(i);
    turnEverythingOff();
    delay(i);
    i-= 5;
  }
}
//////////////turn everything on and off by layer up and down NOT TIMED
void turnOnAndOffAllByLayerUpAndDownNotTimed()
{
  int x = 75;
  for(int i = 5; i != 0; i--)
  {
    turnEverythingOn();
    for(int i = 3; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
    for(int i = 0; i<3; i++)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
      for(int i = 0; i<3; i++)
    {
      digitalWrite(layer[i], 0);
      delay(x);
    }
    for(int i = 3; i!=0; i--)
    {
      digitalWrite(layer[i-1], 1);
      delay(x);
    }
  }
}
//////////////////////////turn everything on and off by column sideways
void turnOnAndOffAllByColumnSideways()
{
  int x = 75;
  turnEverythingOff();
  //turn on layers
  for(int i = 0; i<2; i++)
  {
    digitalWrite(layer[i], 1);
  }
  for(int y = 0; y<2; y++)
  {
    //turn on 0-2
    for(int i = 0; i<2; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 3-5
    for(int i = 3; i<5; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 6-8
    for(int i = 6; i<8; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 9-11
    for(int i = 9; i<11; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn off 0-2
    for(int i = 0; i<2; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 3-5
    for(int i = 3; i<5; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 6-8
    for(int i = 6; i<8; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 9-11
    for(int i = 9; i<11; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn on 9-11
    for(int i = 9; i<11; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 6-8
    for(int i = 6; i<8; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 3-5
    for(int i = 3; i<5; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn on 0-2
    for(int i = 0; i<2; i++)
    {
      digitalWrite(column[i], 0);
      delay(x);
    }
    //turn off 9-11
    for(int i = 9; i<11; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 6-8
    for(int i = 6; i<8; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 3-5
    for(int i = 3; i<5; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
    //turn off 0-2
    for(int i = 0; i<2; i++)
    {
      digitalWrite(column[i], 1);
      delay(x);
    }
  }
}
/////////////////////////////////////////up and down single layer stomp
void layerstompUpAndDown()
{
  int x = 75;
  for(int i = 0; i<3; i++)
  {
    digitalWrite(layer[i], 0);
  }
  for(int y = 0; y<5; y++)
  {
    for(int count = 0; count<1; count++)
    { 
      for(int i = 0; i<3; i++)
      {
        digitalWrite(layer[i], 1);
        delay(x);
        digitalWrite(layer[i], 0);
      }
      for(int i = 3; i !=0; i--)
      {
        digitalWrite(layer[i-1], 1);
        delay(x);
        digitalWrite(layer[i-1], 0);
      }
    }
    for(int i = 0; i<3; i++)
    {
      digitalWrite(layer[i], 1);
      delay(x);
    }
    for(int i = 3; i!=0; i--)
    {
      digitalWrite(layer[i-1], 0);
      delay(x);
    }
  }
}
////////////////////////////////////////////////////////////flicker off
void flickerOff()
{
  turnEverythingOn();
  for(int i = 0; i!= 150; i+=5)
  {
    turnEverythingOff();
    delay(i+50);
    turnEverythingOn();
    delay(i);
  }
}
///////////////////////////////////////////around edge of the cube down
void aroundEdgeDown()
{
  for(int x = 200; x != 0; x -=50)
  {
    turnEverythingOff();
    for(int i = 3; i != 0; i--)
    {
      digitalWrite(layer[i-1], 1);
      digitalWrite(column[5], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[10], 0);
      
      digitalWrite(column[0], 0);
      delay(x);
      digitalWrite(column[0], 1);
      digitalWrite(column[3], 0);
      delay(x);
      digitalWrite(column[3], 1);
      digitalWrite(column[8], 0);
      delay(x);
      digitalWrite(column[8], 1);
      digitalWrite(column[9], 0);
      delay(x);
      digitalWrite(column[9], 1);
      digitalWrite(column[13], 0);
      delay(x);
      digitalWrite(column[13], 1);
      digitalWrite(column[15], 0);
      delay(x);
      digitalWrite(column[15], 1);
      digitalWrite(column[13], 0);
      delay(x);
      digitalWrite(column[13], 1);
      digitalWrite(column[11], 0);
      delay(x);
      digitalWrite(column[11], 1);
      digitalWrite(column[7], 0);
      delay(x);
      digitalWrite(column[7], 1);
      digitalWrite(column[3], 0);
      delay(x);
      digitalWrite(column[3], 1);
      digitalWrite(column[2], 0);
      delay(x);
      digitalWrite(column[2], 1);
      digitalWrite(column[1], 0);
      delay(x);
      digitalWrite(column[1], 1);
    }
  }
}
/////////////////////////////////////////////////////////random flicker
void randomflicker()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,3);
  int randomColumn = random(0,9);
  
  digitalWrite(layer[randomLayer], 1);
  digitalWrite(column[randomColumn], 0);
  delay(x);
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(column[randomColumn], 1);
  delay(x); 
  }
}
////////////////////////////////////////////////////////////random rain
void randomRain()
{
  turnEverythingOff();
  int x = 100;
  for(int i = 0; i!=60; i+=2)
  {
    int randomColumn = random(0,9);
    digitalWrite(column[randomColumn], 0);
    digitalWrite(layer[0], 1);
    delay(x+50);
    digitalWrite(layer[0], 0);
    digitalWrite(layer[1], 1);
    delay(x);
    digitalWrite(layer[1], 0);
    digitalWrite(layer[2], 1);
    delay(x);
    digitalWrite(layer[2], 0);
    digitalWrite(layer[3], 1);
    delay(x+50);
    digitalWrite(layer[3], 0);
    digitalWrite(column[randomColumn], 1);
  }
}
/////////////////////////////////////////////////////diagonal rectangle
void diagonalRectangle()
{
  int x = 350;
  turnEverythingOff();
  for(int count = 0; count<5; count++)
  {
    //top left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[3], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 3; i<9; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    turnEverythingOff();
    //bottom right
    for(int i = 8; i<9; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    turnEverythingOff();
    //bottom middle
    for(int i = 3; i<9; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    turnEverythingOff();
    //bottom left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[0], 1);
    digitalWrite(layer[1], 1);
    delay(x);
    turnEverythingOff();
    //middle middle
    for(int i = 3; i<9; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[1], 1);
    digitalWrite(layer[2], 1);
    delay(x);
    turnEverythingOff();
    //top right
    for(int i = 8; i<9; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(x);
    turnEverythingOff();
    //top middle
    for(int i = 3; i<9; i++)
    {
      digitalWrite(column[i], 0);
    }
    digitalWrite(layer[2], 1);
    digitalWrite(layer[3], 1);
    delay(x);
    turnEverythingOff();
  }
  //top left
  for(int i = 0; i<8; i++)
  {
    digitalWrite(column[i], 0);
  }
  digitalWrite(layer[3], 1);
  digitalWrite(layer[2], 1);
  delay(x);
  turnEverythingOff();
}
//////////////////////////////////////////////////////////////propeller
void propeller()
{
  turnEverythingOff();
  int x = 90;
  for(int y = 3; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      //turn on layer
      digitalWrite(layer[y-1], 1);
      //a1
      turnColumnsOff();
      digitalWrite(column[0], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[15], 0);
      delay(x);
      //b1
      turnColumnsOff();
      digitalWrite(column[3], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[11], 0);
      delay(x);
      //c1
      turnColumnsOff();
      digitalWrite(column[6], 0);
      digitalWrite(column[7], 0);
      digitalWrite(column[8], 0);
      digitalWrite(column[9], 0);
      delay(x);
      //d1
      turnColumnsOff();
      digitalWrite(column[3], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[9], 0);
      delay(x);
      //d2
      turnColumnsOff();
      digitalWrite(column[2], 0);
      digitalWrite(column[6], 0);
      digitalWrite(column[9], 0);
      digitalWrite(column[13], 0);
      delay(x);
      //d3
      turnColumnsOff();
      digitalWrite(column[1], 0);
      digitalWrite(column[5], 0);
      digitalWrite(column[10], 0);
      digitalWrite(column[13], 0);
      delay(x);
    }
  }
  //d3
  turnColumnsOff();
  digitalWrite(column[0], 0);
  digitalWrite(column[5], 0);
  digitalWrite(column[10], 0);
  digitalWrite(column[15], 0);
  delay(x);
}
//////////////////////////////////////////////////////spiral in and out
void spiralInAndOut()
{
  turnEverythingOn();
  int x = 60;
  for(int i = 0; i<6; i++)
  {
    //spiral in clockwise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    ///////////////////////////////////////spiral out counter clockwise
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
    ///////////////////////////////////////spiral in counter clock wise
    digitalWrite(column[0], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[8], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[13], 1);
    delay(x);
    digitalWrite(column[15], 1);
    delay(x);
    digitalWrite(column[11], 1);
    delay(x);
    digitalWrite(column[7], 1);
    delay(x);
    digitalWrite(column[3], 1);
    delay(x);
    digitalWrite(column[2], 1);
    delay(x);
    digitalWrite(column[1], 1);
    delay(x);
    digitalWrite(column[5], 1);
    delay(x);
    digitalWrite(column[9], 1);
    delay(x);
    digitalWrite(column[10], 1);
    delay(x);
    digitalWrite(column[6], 1);
    delay(x);
    //////////////////////////////////////////////spiral out clock wise
    digitalWrite(column[6], 0);
    delay(x);
    digitalWrite(column[10], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[5], 0);
    delay(x);
    digitalWrite(column[1], 0);
    delay(x);
    digitalWrite(column[2], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[7], 0);
    delay(x);
    digitalWrite(column[11], 0);
    delay(x);
    digitalWrite(column[15], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[13], 0);
    delay(x);
    digitalWrite(column[9], 0);
    delay(x);
    digitalWrite(column[8], 0);
    delay(x);
    digitalWrite(column[3], 0);
    delay(x);
    digitalWrite(column[0], 0);
    delay(x);
  }
}
//////////////////////////////////////go through all leds one at a time
void goThroughAllLedsOneAtATime()
{
  int x = 15;
  turnEverythingOff();
  for(int y = 0; y<5; y++)
  {
    //0-3
    for(int count = 2; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 0; i<2; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //3-7
    for(int count = 0; count < 2; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 2; i<8; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
    //8-11
    for(int count = 2; count != 0; count--)
    {
      digitalWrite(layer[count-1], 1);
      for(int i = 8; i<9; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count-1], 0);
    }
    //9-15
    for(int count = 0; count < 2; count++)
    {
      digitalWrite(layer[count], 1);
      for(int i = 9; i<9; i++)
      {
        digitalWrite(column[i], 0);
        delay(x);
        digitalWrite(column[i], 1);
        delay(x);
      }
    digitalWrite(layer[count], 0);
    }
  }
}
