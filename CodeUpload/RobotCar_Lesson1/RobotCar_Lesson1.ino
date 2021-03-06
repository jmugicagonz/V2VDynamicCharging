/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)
Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/

#include "src/Motors/RobotCarLib.h"

RobotCarLib robot;

const int waitTime = 2000;

void setup()
{
	//robot.Init();
  pinMode(D2, OUTPUT);
}

void loop()
{
	/*robot.MoveForward();
	delay(waitTime);

	robot.MoveBackward();
	delay(waitTime);

	robot.TurnLeft();
	delay(waitTime);

	robot.TurnRight();
	delay(waitTime);

	robot.Stop();
	delay(waitTime);*/


  digitalWrite(D2, HIGH);
  delay(4000);
  digitalWrite(D2, LOW);
  delay(4000);
}
