/*
 * Team name: 4squares & Blank Faced
 * Team members: Sanz Lukas, Stolz Nico, Lampl Sebastian, Wiedemann Raphael, Kosche Johannes, Bleier Stefan
 * Version: 1.0
 * Description: Version 1 of the mainbot program (cpp)
 */

// --- includes --- //
#include "main.h" // <riplib/riplib.h> from "main.hpp"
#include <chrono>

// --- function definitions --- //
int main()
{
    rip::RIP::initialize("/home/pi/programs/examples/mainbot/config.json");

    // --- objects --- //
    rip::LOG->info("getting create");
    rip::Create& create = rip::Create::get();
    rip::LOG->info("got create");
    // rip::Servo absima = rip::Servo("absima");
    // rip::Servo botbig = rip::Servo("botbig");
    // rip::Servo botsmall = rip::Servo("botsmall");

    // --- robot setup --- //
    // rip::LOG->info("\n1\n");
    // BotballSetup::setupPosition(create);
    //rip::LOG->info("\n2\n");
    // BotballSetup::setupServo(botsmall);
    // rip::LOG->info("\n3\n");
    // BotballSetup::setupServo(botbig);
    // rip::LOG->info("\n4\n");
    // BotballSetup::setupServo(absima);

    /*
    rip::LOG->info("\n5\n");
    rip::RIP::await_game_start(true);

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
    auto start = std::chrono::high_resolution_clock::now();

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

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    rip::LOG->info("Servo setup completed in {} milliseconds\n\n", duration.count());
}

void BotballSetup::setupPosition(rip::Create& create)
{
    rip::LOG->info("\n\nStarting position setup");
    auto start = std::chrono::high_resolution_clock::now();

    constexpr int THRESHOLD = 2600;
    constexpr int DRIVE_CM = 4;
    constexpr double TARGET_SPEED = 0.6;

    while (create.get_cliff_sensors().front_left > THRESHOLD && create.get_cliff_sensors().front_right > THRESHOLD)
    {
        create.drive(1, 0, 0, TARGET_SPEED, true, false);
    }

    create.turn(85, TARGET_SPEED, true, false);

    while (!(create.get_bumpers().left || create.get_bumpers().right))
    {
        create.drive(10, 0, 0, TARGET_SPEED, true, false);
    }

    create.drive(-5, 0, 0, TARGET_SPEED, true, false);
    create.turn(-90, TARGET_SPEED, true, false);
    create.drive(-DRIVE_CM, 0, 0, TARGET_SPEED, true, false);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    rip::LOG->info("Position setup completed in {} milliseconds\n\n", duration.count());
}