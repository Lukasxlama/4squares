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
        BotballGame::collectRocks(create, servoVec);

        // BotballGame::driveToMoonbase(create, servoVec);
        // BotballGame::grabCube(create, servoVec);

        /*

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

void BotballGame::collectRocks(rip::Create& create, std::vector<rip::Servo> servoVec)
{
    create.turn(50, 1, true, true);
    create.drive(25, 0, 0, 1, true, true);

    new rip::Task([&]
    {
        servoVec[0].move_to(82.5, 1000);
        servoVec[1].move_to(-60.0, 1000);
        servoVec[2].move_to(0.0, 1000);
    });

    create.drive_until(true, [&] {
        return create.get_cliff_sensors().front_left < 2600 ||
               create.get_cliff_sensors().front_right < 2600;
    }, 1, true);

    create.drive(13, 0, 0, 1, true, true);
    create.turn(-90, 1, true, true);
    create.drive(-30, 0.3, true, true);
    create.drive(45, 0, 0, 1, true, true);
    create.turn(90, 1, true, true);
    create.drive(60, 0, 0, 1, true, true);

    create.turn(-60, 1, true, true);
    create.drive(20, 0, 0, 1, true, true);

    create.drive(-35, 0, 0, 1, true, true);
    create.turn(-40, 1, true, true);

    rip::Task::join_all();
}

void BotballGame::driveToMoonbase(rip::Create& create, std::vector<rip::Servo>& servoVec)
{
    // Wird am 26.03.2024 implementiert !!
}

void BotballGame::grabCube(rip::Create& create, std::vector<rip::Servo>& servoVec)
{
    // Funktion unvollständig, wird am 26.03.2024 implementiert!!

    servoVec[1].move_to(-56, 1000);
    servoVec[2].move_to(60, 1000);
    servoVec[1].move_to(-80, 1000);

    create.turn(90, 0.5, true, true);

    servoVec[0].move_to(0, 1000);
    servoVec[1].move_to(-60, 1000);
}

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