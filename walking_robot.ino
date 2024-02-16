//servo control test
#include <Servo.h>

//making the servo variables
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;
Servo servo7;
Servo servo8;

int servo1center = 88;
int servo2center = 94;
int servo3center = 95;
int servo4center = 90;
int servo5center = 100;
int servo6center = 89;
int servo7center = 85;
int servo8center = 97;

int d = 500;
int ds = 15;

void setup() 
{
  //ataching the servos to the correct pins
  servo1.attach(3);
  servo2.attach(4);
  servo3.attach(5);
  servo4.attach(6);
  servo5.attach(7);
  servo6.attach(8);
  servo7.attach(9);
  servo8.attach(10);

  Stand();
  delay(1000);
  LeanLeft();
  delay(1000);
  RightKneeUp();
  delay(1000);
  RightKneeOut();
  delay(1000);
  LeanRightBack();
  delay(1000);
  LeanRightLeftUp();
}
void loop ()
{
}

void Stand()
{
  servo1.write(88);
  servo2.write(94);
  servo3.write(95);
  servo4.write(90);
  servo5.write(100);
  servo6.write(89);
  servo7.write(85);
  servo8.write(97);
  delay(d);
}

//-------------------LEANING--------------------//

void LeanLeft()
{
  int pos1 = servo1.read();
  int target = pos1-19;
  int pos2 = servo2.read();
  int pos7 = servo7.read();
  int pos8 = servo8.read();

  for (int i = pos1; i>=target; i--)
  {
    servo1.write(i);
    servo2.write(pos2);
    servo7.write(pos7);
    servo8.write(pos8);
    pos2--;
    pos7--;
    pos8--;
    delay(30);
  }
}

void LeanRight()
{
  int pos1 = servo1.read();
  int target = pos1+19;
  int pos2 = servo2.read();
  int pos7 = servo7.read();
  int pos8 = servo8.read();
  
  for (int i = pos1; i<=target; i++)
  {
    servo1.write(i);
    servo2.write(pos2);
    servo7.write(pos7);
    servo8.write(pos8);
    pos2++;
    pos7++;
    pos8++;
    delay(30);
  }
}

void LeanRightBack()
{
  int pos1 = servo1.read();
  int target = pos1+19;
  int pos2 = servo2.read();
  int pos7 = servo7.read();
  int pos8 = servo8.read();
  int pos3 = servo3.read();
  int target3 = pos3+13;
  int pos5 = servo5.read();
  int pos6 = servo6.read();

  for (int i = pos1; i<=target; i++)
  {
    servo1.write(i);
    servo2.write(pos2);
    servo7.write(pos7);
    servo8.write(pos8);
    //servo5.write(pos5);
    //servo6.write(pos6);
    pos5++;
    pos6--;
    pos2++;
    pos7++;
    pos8++;
    if (pos3<=target3) {
      servo3.write(pos3);
      pos3++;
    }
    delay(30);
  }
}

void LeanRightLeftUp()
{
  int pos1 = servo1.read();
  int target = pos1+19;
  int pos2 = servo2.read();
  int pos7 = servo7.read();
  int pos8 = servo8.read();

  int pos4 = servo4.read();
  int pos6 = servo6.read();

  int pos3 = servo3.read();
  int target3 = pos3-70;
  int pos5 = servo5.read();
  
  for (int i = pos1; i<=target; i++)
  {
    servo1.write(i);
    servo2.write(pos2);
    servo7.write(pos7);
    servo8.write(pos8);
    servo3.write(pos3);
    servo5.write(pos5);
    pos3--;
    pos5--;
    servo4.write(pos4);
    servo6.write(pos6);
    pos4--;
    pos6--;
    pos2++;
    pos7++;
    pos8++;
    delay(30);
  }
}

void LeanBackAndForth()
{
  Stand();
  delay(d);
  LeanLeft();
  delay(d);
  Stand();
  delay(d);
  LeanRight();
  delay(d);
  Stand();
  delay(d);
}

//-----------------KNEE MOVEMENT------------------//

void RightKneeUp()
{
  int pos4 = servo4.read();
  int target4 = pos4+70;
  int pos6 = servo6.read();

  for (int i = pos4; i<=target4; i++)
  {
    servo4.write(i);
    servo6.write(pos6);
    pos6++;
    delay(ds);
  }
}

void LeftKneeUp()
{
  int pos3 = servo3.read();
  int target3 = pos3-70;
  int pos5 = servo5.read();

  for (int i = pos3; i>=target3; i--)
  {
    servo3.write(i);
    servo5.write(pos5);
    pos5--;
    delay(ds);
  }
}

void RightKneeExtend()
{
  int pos3 = servo3.read();
  int target3 = pos3+10;
  int pos5 = servo5.read();

  int pos4 = servo4.read();
  int target4 = pos4-40;
  int pos6 = servo6.read();
  int target6 = pos6-40;

  int pos1 = servo1.read();
  int target1 = pos1+20;
  int pos2 = servo2.read();
  int pos7 = servo7.read();
  int pos8 = servo8.read();

  for (pos4; pos4>=target4; pos4--)
  {
    servo4.write(pos4);
    if (pos6>=target6)
    {
      servo6.write(pos6);
      pos6--;
    }
    
    if (pos3<=target3)
    {
      servo5.write(pos5);
      servo3.write(pos3);
      pos5++;
      pos3++;
    }

    if (pos1<=target1)
    {
      servo1.write(pos1);
      servo2.write(pos2);
      servo7.write(pos7);
      servo8.write(pos8);
      pos1++;
      pos2++;
      pos7++;
      pos8++;
    }
    delay(30);
  }
}

void RightKneeOut () {
  int pos4 = servo4.read();
  int target4 = pos4-40;
  int pos6 = servo6.read();
  int target6 = pos6-20;
  int pos3 = servo3.read();
  int target3 = pos3+5;

  for (pos4; pos4>=target4; pos4--)
  {
    servo4.write(pos4);
    if (pos6>=target6)
    {
      servo6.write(pos6);
      pos6--;
    }
    delay(15);
  }
  
}
