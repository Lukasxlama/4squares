/*
 * Team name: 4squares
 * Team members: Sanz Lukas, Stolz Nico, Lampl Sebastian, Wiedemann Raphael, Kosche Johannes, Bleier Stefan
 * Version: 1.0
 * Description: Version 1 of the mainbot program (.h)
 */

// --- include guard --- //
#pragma once

// --- includes --- //
#include <riplib/riplib.h>

// --- namespaces & function prototypes --- //
namespace BotballGame
{
    void collectRocksReverse(rip::Create& create, std::vector<rip::Servo> servoVec);
    void driveToMoonbase(rip::Create& create, std::vector<rip::Servo>& servoVec);
    void grabCube(rip::Create& create, std::vector<rip::Servo>& servoVec);

    void driveToNoodle(rip::Create& create);
    void grabNoodle(rip::Create& create);

    void driveToLavaTube(rip::Create& create);
    void placeNoodle(rip::Create& create);

    void driveToAstronaut(rip::Create& create);
    void grabAstronaut(rip::Create& create);

    void driveToFlagStation(rip::Create& create);
    void placeAstronaut(rip::Create& create);

    void driveToFuel(rip::Create& create);
    void driveToStart(rip::Create& create);
}