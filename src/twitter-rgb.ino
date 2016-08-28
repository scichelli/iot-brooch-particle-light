void setup() {
    RGB.control(true);
    RGB.brightness(0);
    
    Particle.function("tweet", tweetToLight);
    Particle.subscribe("hook-response/tweet-parse", respondToTweet, MY_DEVICES);
}

void loop() {

}

int tweetToLight(String tweet) {
    Particle.publish("tweet-parse", tweet, PRIVATE);
    return 0;
}

void respondToTweet(const char *event, const char *data) {
    RGB.brightness(255);
    RGB.color(255, 0, 0);
    delay(1000);

    RGB.brightness(0);
}
