#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    ofImage img;
    ofVboMesh mesh;
    ofShader shader;
    ofFbo fbo;
    int w,h;
    bool hideGui=true;
    
    ofxPanel gui;
    ofxIntSlider iterat;
    ofxFloatSlider scale;
    ofxVec2Slider fold;
    ofxVec2Slider translate;
    
    ofxFloatSlider zoom;
    ofxFloatSlider brightness;
    ofxFloatSlider saturation;
    ofxFloatSlider texturescale;
    ofxFloatSlider rotspeed;
    ofxFloatSlider colspeed;
    ofxFloatSlider antialias;
    ofxToggle      aniTime;
    ofxFloatSlider anime,incanime;

		
};
