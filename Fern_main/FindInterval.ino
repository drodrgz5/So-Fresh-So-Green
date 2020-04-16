/*
 * Notes:
 * Added "Time" library
 * Added "TimeAlarms" Library
 * Link to use TimeAlarm library: https://www.pjrc.com/teensy/td_libs_TimeAlarms.html
 * To figure out how functions work, use:
 * File - > example -> TimeAlarms
 */
/*
#include <TimeLib.h>
#include <TimeAlarms.h>

AlarmId id;

void setup() {
  Serial.begin(9600);
  while (!Serial) ; // wait for Arduino Serial Monitor
  setTime(0,0,0,4,1,20); // set time to Wednesday 0:00:00am (12 am) April 1 2020
  Alarm.alarmRepeat(0,0,3, FindIntervals); // should call FindIntervals function to run once a day at 12:00:03 am
}
*/

//Function creates array that designates the interval.
int FindIntervals(int perDayRate, int offset, int whatHrs[])
{                                                            //assumed offset = 0; changed whatHrs[] from bool to int because it wasn't giving correct output
  //perDayRate = 2;                                                          
  int num_interval = 24/perDayRate; //must limit user to intervals of 24: 1,2,3,4,6,8,12,24
  int i;
  for(i = 0; i < perDayRate; i++){
    if(i == 0){
      whatHrs[i] = 0;
    }
    else{
      whatHrs[i] = whatHrs[i-1] + num_interval;
    }
  }
  /*
  for(i = 0; i < perDayRate; i++){
      Serial.println(whatHrs[i]);
   }
   */
   return whatHrs[i];
}

  /*
  for(i = 0; i < 24; i++){
    if(i == 0){
      //Alarm.alarmRepeat(whatHrs[i],10,0, Light);  // Light represents the light collection function
      Alarm.alarmRepeat(whatHrs[i],15,0, WriteData);  //
      }
    else if(24%whatHrs[i] == 0){
      //Alarm.alarmRepeat(whatHrs[i],10,0, Light);  // Light represents the light collection function
      Alarm.alarmRepeat(whatHrs[i],15,0, WriteData);  // 
      }
  }
 */
