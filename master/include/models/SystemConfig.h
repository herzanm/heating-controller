#pragma once

#include <Arduino.h>

struct SystemConfig
{
    // Heating

    uint32_t boilerMinRunTimeSec = 300;     // 5 min
    uint32_t boilerMinOffTimeSec = 180;     // 3 min

    // uint32_t pumpPostRunTimeSec = 60;       // doběh čerpadla - není potřeba

    // Manual mode
    bool manualModeEnabled = true;
    uint32_t manualModeTimeoutSec = 14400;   // 4 hours

    // Network
    char wifiSSID[32] = "Kysel32";
    char wifiPassword[64] = "";

    // Display
    uint8_t displayBrightness = 255;

    // Circuit names
    char circuit1Name[32] = "Loznice";
    char circuit2Name[32] = "Detsky pokoj";
    char circuit3Name[32] = "Pracovna";
    char circuit4Name[32] = "Koupelna";
};