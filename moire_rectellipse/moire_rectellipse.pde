int x, y, i;

void setup() {
  size(800,800);
  x = width;
  y = height;
  ellipseMode(CENTER);
  rectMode(CENTER);
  noCursor();
}

void draw() {
  background(255);
  for (float j = 0.0; j < 1600.0; j += 6.0) {
    stroke(0);
    noFill();
    rect(x/2,y/2,(mouseX-j-i),(mouseY-j+i));
    ellipse(x/2,y/2,mouseX-j-i,mouseY-j+i);
  }
  i += 1;
  if (i == width *1.5) {
    i = -1;
  }
}