#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    w=ofGetScreenWidth();
    h=ofGetScreenHeight();
    gui.setup();
    gui.add(iterat.setup("iterations",            20, 0,80));
    gui.add(scale.setup("scale",                  1.3,0.0,10.0));
    gui.add(fold.setup("fold",                    ofVec2f(.5),  ofVec2f(.5),  ofVec2f(.1000)));
    gui.add(translate.setup("translate",          ofVec2f(1.5), ofVec2f(1.5), ofVec2f(25.5)));
    gui.add(zoom.setup("zoom",                    .25,.25,.100));
    gui.add(brightness.setup("brightness",        7.,7.,255.));
    gui.add(saturation.setup("saturation",        .65,.65,.100));
    gui.add(texturescale.setup("texturescale",    .15,.15,.100));
    gui.add(rotspeed.setup("rotspeed",            0.1, 0.0,10.100));
    gui.add(colspeed.setup("colspeed",            .05,.05,.100));
    gui.add(antialias.setup("antialias",          2.,2.,10.));
    gui.add(aniTime.setup("anime-time",           false));
    gui.add(incanime.setup("inc-time-anime",      2.,2.,10.));
    gui.add(anime.setup("anime",                  2.,2.,100.));
    gui.saveToFile("settings.xml");
    
    ofEnableDepthTest();
    ofDisableArbTex();
    img.loadImage("model.jpg");
    shader.load("madel2d.vertex","madel2d.fragment");
    fbo.allocate(w,h);
    fbo.begin();
    ofClear(0,0,0,0);
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(64, 0);
    
    shader.begin();
    shader.setUniformTexture("texture",    img, 1);
    shader.setUniform3f("resolution", w,h,0);
    if(aniTime)
        shader.setUniform1f("time", ofGetElapsedTimef()*incanime);
    else
        shader.setUniform1f("time", anime);
    
    shader.setUniform1i("iterations", iterat);
    shader.setUniform1f("scale", scale);
    shader.setUniform2f("fold",      fold->x,fold->y);
    shader.setUniform2f("translate", translate->x, translate->y);
    shader.setUniform1f("zoom", zoom);
    shader.setUniform1f("brightness", brightness);
    shader.setUniform1f("saturation", saturation);
    shader.setUniform1f("texturescale", texturescale);
    shader.setUniform1f("rotspeed", rotspeed);
    shader.setUniform1f("colspeed", colspeed);
    shader.setUniform1f("antialias", antialias);
    
    fbo.draw(0,0);
    shader.end();
    
    ofDisableDepthTest();
    if(hideGui)
        gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'h')
        hideGui=!hideGui;
    if(key == 's')
        ofSaveFrame();
    if(key == 'f')
        ofToggleFullscreen();
    if(key == 'l')
        gui.loadFromFile("settings.xml");
    if(key == 'x')
        gui.saveToFile("settings.xml");
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
