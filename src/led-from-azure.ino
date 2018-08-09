void setup() {
    RGB.control(true);
    RGB.brightness(0);
    
    Particle.function("setLed", setLed);
}

void loop() {

}

int setLed(String colors) {
    Particle.publish("received-request", colors, 60, PRIVATE);
    
    RGB.brightness(255);
    
    String red = colors.substring(0, 3);
    String green = colors.substring(4, 7);
    String blue = colors.substring(8, 11);
    RGB.color(red.toInt(), green.toInt(), blue.toInt());
    delay(1000);

    RGB.brightness(0);
    return 0;
}
