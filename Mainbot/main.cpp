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
    rip::Servo botsmall = rip::Servo("botclaw");

    std::vector<rip::Servo> servoVec = {absima, botbig, botsmall};

    // --- robot setup --- //
    // rip::RIP::await_game_start(true);

    // --- Botball strategy --- //
    if (rip::RIP::is_running())
    {
        BotballGame::collectRocksReverse(create, servoVec);

        // BotballGame::driveToMoonbase(create, servoVec);
        // BotballGame::grabCube(create, servoVec);

        /*

        BotballGame::driveToNoodle(create);
        BotballGame::grabNoodle(create);

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

void BotballGame::collectRocksReverse(rip::Create& create, std::vector<rip::Servo> servoVec)
{
    constexpr double SPEED = 0.5;

    create.turn(45, 1, true, true);

    while (!(create.get_bumpers().right || create.get_bumpers().left))
    {
        create.drive(1, 0, 0, 1, true, true);
    }

    create.drive(-90, 0, 0, 1, true, true);
    create.turn(-80, 1, true, true);
    create.drive(-65, 0, 0, SPEED, true, true);
    create.turn(90, SPEED, true, true);
    create.drive(-55, 0, 0, SPEED, true, true);
    create.turn(-45, SPEED, true, true);
    create.drive(-55, 0, 0, SPEED, true, true);
    create.drive(80, 0, 0, SPEED, true, false);
}

void BotballGame::driveToMoonbase(rip::Create& create, std::vector<rip::Servo>& servoVec)
{
    // Wird noch implementiert !!
}

void BotballGame::grabCube(rip::Create& create, std::vector<rip::Servo>& servoVec)
{
    // Funktion unvollständig, wird noch implementiert!!

    servoVec[1].move_to(-56, 1000);
    servoVec[2].move_to(60, 1000);
    servoVec[1].move_to(-80, 1000);

    create.turn(90, 0.5, true, true);
    servoVec[0].move_to(0, 1000);
    servoVec[1].move_to(-60, 1000);
}

void BotballGame::driveToNoodle(rip::Create& create);
void BotballGame::grabNoodle(rip::Create& create);

void BotballGame::driveToLavaTube(rip::Create& create);
void BotballGame::placeNoodle(rip::Create& create);

void BotballGame::driveToAstronaut(rip::Create& create);
void BotballGame::grabAstronaut(rip::Create& create);

void BotballGame::driveToFlagStation(rip::Create& create);
void BotballGame::placeAstronaut(rip::Create& create);

void BotballGame::driveToFuel(rip::Create& create);
void BotballGame::driveToStart(rip::Create& create);