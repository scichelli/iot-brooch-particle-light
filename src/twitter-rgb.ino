void setup() {
    RGB.control(true);
    RGB.brightness(0);
    
    Particle.function("setLed", setLed);
}

void loop() {

}

int setLed(String colors) {
    Particle.publish("received-request", colors, PRIVATE);
    RGB.brightness(255);
    RGB.color(255, 0, 0);
    delay(1000);

    RGB.brightness(0);
    return 0;
}
