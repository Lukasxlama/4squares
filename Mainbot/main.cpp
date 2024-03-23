/*
 * Team name: 4squares
 * Team members: Sanz Lukas, Stolz Nico, Lampl Sebastian, Wiedemann Raphael, Kosche Johannes, Bleier Stefan
 * Version: 1.0
 * Description: Version 1 of the mainbot program (.cpp)
 */

// --- includes --- //
#include "main.h"
#include <vector>
// <riplib/riplib.h> from "main.h"

// --- function definitions --- //
int main()
{
    rip::RIP::initialize("/home/pi/programs/examples/mainbot/config.json");

    // --- objects --- //
    rip::Create& create = rip::Create::get();
    rip::Servo absima = rip::Servo("absima");
    rip::Servo botbig = rip::Servo("botbig");
    rip::Servo botsmall = rip::Servo("botsmall");

    std::vector<rip::Servo> servoVec = {absima, botbig, botsmall};

    // --- robot setup --- //
    // rip::RIP::await_game_start(true);

    // --- Botball strategy --- //
    if (rip::RIP::is_running())
    {
        BotballGame::driveToMoonbase(create, servoVec);
        /*
        BotballGame::grabCube(create);

        BotballGame::driveToRockheap(create);
        BotballGame::placeCube(create);

        BotballGame::driveToNoodle(create);
        BotballGame::graboNoodle(create);

        BotballGame::driveToLavaTube(create);
        BotballGame::placeNoodle(create);

        BotballGame::driveToAstronaut(create);
        BotballGame::grabAstronaut(create);

        BotballGame::driveToFlagStation(create);
        BotballGame::placeAstronaut(create);

        BotballGame::driveToFuel(create);
        BotballGame::driveToStart(create);
         */
    }

    // --- end --- //
    rip::RIP::shutdown();
    return EXIT_SUCCESS;
}

void BotballGame::driveToMoonbase(rip::Create& create, std::vector<rip::Servo> servoVec)
{
    create.turn(40, 1, true, true);
    create.drive(100, 0, 0, 1, true, true);
    create.turn(-90, 1, true, true);

    new rip::Task([&]
    {
        // Values noch nicht konfiguriert!!
        servoVec[0].move_to(0); // TODO: Value konfigurieren
        servoVec[1].move_to(0); // TODO: Value konfigurieren
        servoVec[2].move_to(0); // TODO: Value konfigurieren
    });

    create.drive(20, 1, true, true);
    // TODO: Weitere Logik einbauen; Funktion fertigschreiben
}

void BotballGame::grabCube(rip::Create& create);

void BotballGame::driveToRockheap(rip::Create& create);
void BotballGame::placeCube(rip::Create& create);

void BotballGame::driveToNoodle(rip::Create& create);
void BotballGame::graboNoodle(rip::Create& create);

void BotballGame::driveToLavaTube(rip::Create& create);
void BotballGame::placeNoodle(rip::Create& create);

void BotballGame::driveToAstronaut(rip::Create& create);
void BotballGame::grabAstronaut(rip::Create& create);

void BotballGame::driveToFlagStation(rip::Create& create);
void BotballGame::placeAstronaut(rip::Create& create);

void BotballGame::driveToFuel(rip::Create& create);
void BotballGame::driveToStart(rip::Create& create);