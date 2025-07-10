//     FILE: atomic_weight_minerals_3.ino
//   AUTHOR: Rob Tillaart
//  PURPOSE: demo
//      URL: https://github.com/RobTillaart/AtomicWeight
//
//  Note this sketch uses a lot of RAM for the char arrays used.
//  Arduino UNO warns
//  Could be solved by implementing "PROGMEM" formulas

#include "Arduino.h"
#include "AtomicWeight.h"
#include "minerals.h"


PTOE ptoe;


void setup()
{
  while (!Serial);
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print("ATOMIC_WEIGHT_LIB_VERSION: ");
  Serial.println(ATOMIC_WEIGHT_LIB_VERSION);
  Serial.println();


  Serial.println("METAMORPHISM (15)");
  Serial.println("NAME\tWEIGHT\tFORMULA\n");

  printMineral("PERICLASE", PERICLASE);
  printMineral("MONTICELLITE", MONTICELLITE);
  printMineral("MERWINITE", MERWINITE);
  printMineral("LARNITE", LARNITE);
  printMineral("SPURRITE", SPURRITE);
  printMineral("TILLEYITE", TILLEYITE);
  printMineral("RANKINITE", RANKINITE);
  printMineral("PHLOGOPITE", PHLOGOPITE);
  printMineral("ANNIITE", ANNIITE);
  Serial.println();

  Serial.println("ECONOMIC MINERALS (16)");
  Serial.println("NAME\tWEIGHT\tFORMULA\n");
  printMineral("GALENA", GALENA);
  printMineral("SPHALERITE", SPHALERITE);
  printMineral("BORNITE", BORNITE);
  printMineral("CHALCOCITE", CHALCOCITE);
  printMineral("MARCASITE", MARCASITE);
  printMineral("MOLYBDENITE", MOLYBDENITE);
  printMineral("ARSENOPYRITE", ARSENOPYRITE);
  printMineral("FLUORITE", FLUORITE);
  printMineral("BARITE", BARITE);
  printMineral("SPODUMENE", SPODUMENE);
  Serial.println();
  Serial.println("NAME\tWEIGHT\tFORMULA\n");
  printMineral("RUBY", RUBY);
  printMineral("SAPPHIRE", SAPPHIRE);
  printMineral("EMERALD", EMERALD);
  printMineral("HELIODOR", HELIODOR);
  printMineral("AQUAMARINE", AQUAMARINE);
  printMineral("JADE", JADE);
  printMineral("TURQOISE", TURQOISE);
  Serial.println();

  Serial.println("RARE EARTH MINERALS (16)");
  Serial.println("NAME\tWEIGHT\tFORMULA\n");
  printMineral("XENOTIME", XENOTIME);
  printMineral("NATROLITE", NATROLITE);
  printMineral("STIBILITE", STIBILITE);


  Serial.println();
  Serial.println("\ndone...");
}


void loop()
{
}


void printMineral(const char * name, const char * formula)
{
  Serial.print(name);
  Serial.print("\t");
  Serial.print(ptoe.weight(formula));
  Serial.print("\t");
  Serial.println(formula);
}

//  -- END OF FILE --
