/*
 * Team name: 4squares & Blank Faced
 * Team members: Sanz Lukas, Stolz Nico, Lampl Sebastian, Wiedemann Raphael, Kosche Johannes, Bleier Stefan
 * Version: 1.0
 * Description: Version 1 of the mainbot program (cpp)
 */

// --- includes --- //
// <riplib/riplib.h> from "main.h"
#include "main.h"
#include <chrono>

// --- function definitions --- //
int main()
{
    rip::RIP::initialize("/home/pi/programs/examples/mainbot/config.json");

    // --- objects --- //
    rip::Create& create = rip::Create::get();
    rip::Servo absima = rip::Servo("absima");
    rip::Servo botbig = rip::Servo("botbig");
    rip::Servo botsmall = rip::Servo("botsmall");

    // --- robot setup --- //
    rip::LOG->info("\n1\n");
    BotballSetup::setupPosition(create);
    // rip::LOG->info("\n2\n");
    // BotballSetup::setupServo(botsmall);
    // rip::LOG->info("\n3\n");
    // BotballSetup::setupServo(botbig);
    // rip::LOG->info("\n4\n");
    // BotballSetup::setupServo(absima);

    rip::LOG->info("\n5\n");
    rip::RIP::await_game_start(true);

    /*
    // --- Botball strategy --- //
    if (rip::RIP::is_running())
    {
        rip::LOG->info("\n6\n");
        create.drive(100, 0, 0, 0.5, true, false);
    }
    */

    // --- end --- //
    rip::RIP::shutdown();
    return EXIT_SUCCESS;
}

void BotballSetup::setupServo(rip::Servo& servo)
{
    rip::LOG->info("\n\nStarting servo setup");
    auto start = rip::util::now();

    constexpr double MIN_ANGLE = -82.5;
    constexpr double MAX_ANGLE = 82.5;
    constexpr int DURATION_MS = 1000;
    constexpr int SLEEP_MS = 3000;

    rip::LOG->info("Move servo to minimum angle: {}°", MIN_ANGLE);
    servo.move_to(MIN_ANGLE, DURATION_MS);
    rip::util::sleep(SLEEP_MS);

    rip::LOG->info("Move servo to maximum angle: {}°", MAX_ANGLE);
    servo.move_to(MAX_ANGLE, DURATION_MS);
    rip::util::sleep(SLEEP_MS);

    rip::LOG->info("Move servo to centre angle: {}°", MAX_ANGLE + (MIN_ANGLE - MAX_ANGLE) / 2);
    servo.move_to( MAX_ANGLE + (MIN_ANGLE - MAX_ANGLE) / 2, DURATION_MS);
    rip::util::sleep(SLEEP_MS);

    rip::LOG->info("Move servo to starting position: {}°\n\n", MIN_ANGLE);
    servo.move_to(MIN_ANGLE, DURATION_MS);
    rip::util::sleep(SLEEP_MS);

    auto end = rip::util::now();
    int duration = rip::util::time_diff(start, end);
    rip::LOG->info("Servo setup completed in {} milliseconds\n\n", duration);
}

void BotballSetup::setupPosition(rip::Create& create)
{
    rip::LOG->info("\n\nStarting position setup");
    auto start = rip::util::now();

    constexpr int THRESHOLD = 2600;
    constexpr int DRIVE_CM = 12;
    constexpr double TARGET_SPEED = 0.7;
    constexpr bool ACCELERATE = false;
    constexpr bool DECELERATE = true;

    while (create.get_cliff_sensors().front_left > THRESHOLD && create.get_cliff_sensors().front_right > THRESHOLD)
    {
        create.drive(3, 0, 0, TARGET_SPEED, ACCELERATE, DECELERATE);
    }

    create.turn(90, TARGET_SPEED, ACCELERATE, DECELERATE);

    while (!(create.get_bumpers().left || create.get_bumpers().right))
    {
        create.drive(5, 0, 0, TARGET_SPEED, ACCELERATE, DECELERATE);
    }

    create.drive(-8, 0, 0, TARGET_SPEED, ACCELERATE, DECELERATE);
    create.turn(-90, TARGET_SPEED, ACCELERATE, DECELERATE);
    create.drive(-DRIVE_CM, 0, 0, TARGET_SPEED, ACCELERATE, DECELERATE);

    auto end = rip::util::now();
    rip::LOG->info("Position setup completed in {} milliseconds\n\n", rip::util::time_diff(start, end));
}