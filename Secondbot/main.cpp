#include <riplib/riplib.h>

using namespace rip;

void straight(double time) {
    auto &movement = Movement::get();
    movement.set_speed(-10, -10);
    int zeit = (time * 1000);
    util::sleep(zeit * 1000);
    movement.set_speed(0, 0);
}
void back(int time) {
    auto &movement = Movement::get();
    movement.set_speed(10, 10);
    util::sleep(time * 1000);
    movement.set_speed(0, 0);
}

void right() {
    auto &movement = Movement::get();
    movement.set_speed(10, -10);
    util::sleep(650);
    movement.set_speed(0,0);
}
void left() {
    auto &movement = Movement::get();
    movement.set_speed(-10, 10);
    util::sleep(650);
    movement.set_speed(0,0);
}
void turn_around() {
    auto &movement = Movement::get();
    movement.set_speed(10, -10);
    util::sleep(650 * 2);
    movement.set_speed(0,0);
}
void drive_airlock() {

}


void grab_astronauts(Servo(arm), Servo(klaue), Servo(arm2), Servo(finger)) {
    arm.move_to(45, 1000);
    klaue.move_to(75, 1000);
    arm.move_to(10, 1000);
}

int main() {
    RIP::initialize("/home/pi/programs/examples/Secondbot/config.json");
    Servo klaue("servo0");
    Servo arm("servo1");
    Servo arm2("servo2");
    Servo finger("servo3");
    auto sensor0 = Sensor("sensor0");
    auto &movement = Movement::get();
    movement.drive(45);
    movement.set_speed(-1, 1);
    util::sleep(650);
    movement.drive(-14);
    movement.set_speed(0, 0);
    grab_astronauts(arm, klaue, arm2, finger);
    finger.move_to(-22, 500);
    movement.drive(-20);
    movement.set_speed(1, -1);
    util::sleep(550);
    movement.drive(22);



    RIP::shutdown(); // forgetting this line will result in runtime errors!
}
/*
    auto sensor0 = Sensor("sensor0");
    auto &movement = Movement::get();
    movement.drive(50);
    movement.set_speed(-1, 1);
    util::sleep(650);
    movement.drive(-13);
    movement.set_speed(0,0);
    grab_astronauts();
 */

