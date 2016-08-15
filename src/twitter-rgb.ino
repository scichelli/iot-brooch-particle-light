void setup() {
    RGB.control(true);
    RGB.brightness(0);
    
    Particle.function("tweet", tweetToLight);
}

void loop() {

}

int tweetToLight(String tweet) {
    Particle.publish("liskov-tweet", tweet);
    
    tweet.toLowerCase();
    if (tweet.indexOf("#lightup") > -1) {
        RGB.brightness(255);
        RGB.color(255, 0, 0);
        delay(1000);
    }
    
    RGB.brightness(0);
    return 0;
}
