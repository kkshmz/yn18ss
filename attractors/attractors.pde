

import toxi.geom.*;
import toxi.processing.*;


int n_attractors=20;
int cell = 2; // cell size

Vec2D[] gravityPCollection= new Vec2D[n_attractors];
Vec2D[] orientorCollection;
Vec2D[] orientorSortedCollection;

float[] gravity= new float[n_attractors];
float[] distCollection;

ArrayList particuleCollection;



boolean lancer =true;

void setup() {
  size( 1800, 1800 );
  background(250, 250, 250);
  smooth();


  particuleCollection= new ArrayList();



  // POINT ATTRACTEUR
  for (int i = 0; i < n_attractors; i = i+1) {

    gravityPCollection[i]= new Vec2D(random(width), random(height));
    gravity[i]=random(1, 100);
  }
  
    // POINTS  
  for (int i=0; i<=width; i=i+cell) {
    for (int j=0; j<=height; j=j+cell) {

      Vec2D p = new Vec2D(i, j);
      particuleCollection.add(p);
    }
  }
  
}


void draw() {




  orientorCollection= new Vec2D[particuleCollection.size()];
  distCollection= new float[particuleCollection.size()];

  for (int j=0; j< particuleCollection.size (); j++) {
    
    
    Vec2D p = (Vec2D)particuleCollection.get(j);
    Vec2D target = new Vec2D();
   
   
    float distTot= 0;
    float minDist=-100;
    int minIdx=0;

    for (int i=0; i<n_attractors; i++) {



      float disti = p.distanceTo(gravityPCollection[i]);

//      if (disti<minDist) {
//        minDist=disti;
//      }
      Vec2D  vi = gravityPCollection[i].sub(p);
      vi.normalize();
      vi.scaleSelf(gravity[i]/disti);

      target.addSelf(vi);
    }  


    target.normalizeTo(5);

    // STOCKAGE DES ORIENTEURS et DISTANCES 
    orientorCollection[j]=target;
    //distCollection[j]= minDist;
  }


  float distmax=max(distCollection);
  float distmin=min(distCollection);

  orientorSortedCollection= new Vec2D[particuleCollection.size()];

  for (int j=0; j< particuleCollection.size (); j++) {


    Vec2D temp=orientorCollection[j];//.getRotated(PI/2);
    orientorSortedCollection[j] =  temp.normalizeTo(3);
  }

  for (int j=0; j< particuleCollection.size (); j++) {
    Vec2D p =  (Vec2D)particuleCollection.get(j);  
    p.addSelf(orientorSortedCollection[j]);
    noStroke();
    fill(250, 128, 114, 255);
    ellipse(p.x, p.y, 0.6, 0.6);
  }
}

void initialize() {
}