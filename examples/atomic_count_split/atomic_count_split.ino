//    FILE: atomic_weight_split.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo
//     URL: https://github.com/RobTillaart/AtomicWeight


#include "Arduino.h"
#include "AtomicWeight.h"


PTOE ptoe;

//  https://en.wikipedia.org/wiki/Glossary_of_chemical_formulae

char formula0[24] = "C6H6O6";
char formula1[24] = "Al2Si2O5(OH)4";    //  kaolin
char formula2[24] = "H2SO4";
char formula3[24] = "CuO2";
char formula4[24] = "(COH)3(COH)2COH";
// char formula4[24] = "(CH)6O6";
// char formula4[24] = "xH2";           // fails => 0;
char formula5[24] = "YBa2Cu3O7";
char formula6[24] = "Al(NO2)3";         //  aluminium nitrite
char formula7[24] = "Ba(C2H3O2)2";      //  barium acetate

uint8_t cnt;


void setup()
{
  Serial.begin(115200);
  while (!Serial);
  Serial.println(__FILE__);
  Serial.print("ATOMIC_WEIGHT_LIB_VERSION: ");
  Serial.println(ATOMIC_WEIGHT_LIB_VERSION);

  test("C");
  test("C6");
  test("CCCCCCC");
  test("He6");
  test("NaCl");

  test(formula0);
  test(formula1);
  test(formula2);
  test(formula3);
  test(formula4);
  test(formula5);
  test(formula6);
  test(formula7);

  Serial.println("done");
}


void loop()
{
}


void test(char * formula)
{
  Serial.println();
  Serial.print(formula);
  Serial.print("\t");
  Serial.print(ptoe.count(formula));
  Serial.println(" atoms.");

  uint8_t cnt = ptoe.splitElements(formula);
  for (int i = 0; i < cnt; i++)
  {
    Serial.print(ptoe.name(ptoe.element(i)));
    Serial.print("\t");
    Serial.println(ptoe.atomPercentage(formula, ptoe.name(ptoe.element(i))), 3);
  }

  Serial.println();
}


//  -- END OF FILE --
