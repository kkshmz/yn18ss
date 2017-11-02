float theta = 0.0;
int eWM = 10;
int eHM = 10;
float rotSpeed = 0.01;

void setup() {
  size(800,800);
  rectMode(CENTER);
}

void draw() {
  background(240,240,220);
  noFill();
  stroke(190,190,240);
  
  for (int i=0; i< 200; i++) {
    ellipse(mouseX, mouseY, i*eWM, i*eHM);
  }
  translate(width/2, height/2);
  for (int i=0; i< 200; i++) {
    ellipse(0,0,i*eWM,i*eHM);
  }
}