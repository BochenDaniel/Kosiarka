#ifndef DM
#define DM

#include "Arduino.h"
/*  wykrywa wersje arduino i wczytuje biblioteki wymagane do dzialania kodu. 
 *   Ja mam tylko Uno wiec wersja jest wyzsza niz 1.00

#if (ADUINO >= 100)
  #include "Ardiuno.h"
#else 
  #include "WProgram.h"
#endif
*/
//String DM_Msg;
  
class DriveM {
  public:
    // Construktor
    DriveM(bool displayMsg=false);


    //Metods
    long GetRandomNumber();
    int DriveStop();
    int DriveRun();
    int DriveReverseLeft();
    int DriveReverseRight();
    int DriveBack();
    String DM_Msg(); 
     

  private:
    bool _msg;
    String _DM_Msg; 
  
};
#endif
