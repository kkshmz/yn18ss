#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(255);
    
    //settings for the models
    // for the textures to work on the models
//    ofDisableArbTex();
    nCircle = 200;
    ofSetColor(20, 50, 70);
    ofFill();
    xc = ofGetWidth()/2;
    yc = ofGetHeight()/2;
//    mesh.setMode(OF_PRIMITIVE_POINTS);
//    mesh.setMode(OF_PRIMITIVE_LINES);
//   vbo.setMode(OF_PRIMITIVE_POINTS);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
//mesh.addVertex(ofVec2f(x,y));
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<nCircle;i++) {
        radius = (i+1)*4;
        // radius starts on 20 and gets bigger for  each loop
        for (float ang=0; ang<=360; ang+=0.2) {
            float rad=ang*PI/180; //transorm ang in radians rather than degrees
            float radiusTransformX = 3*radius/2+radius*(radius/(ofGetMouseY()*1000.0/ofGetHeight())*cos(2*rad-5.0*ofGetMouseX()/ofGetWidth())); //change the radius depending on the angle and the size of the circle
            float radiusTransformY = radius+(radius/2)*(1-radius/200);
            x = xc + (radiusTransformX * cos(rad));
            y = yc + (radiusTransformY * sin(rad));
            
            
//            ofDrawCircle(x, y, 1);

            mesh.clear();
            mesh.setMode(OF_PRIMITIVE_POINTS);
            mesh.addVertex(ofVec2f(x,y));
//            mesh.setMode(OF_PRIMITIVE_LINES);
//            mesh.addIndex(i);
//            vbo.clear();
//            vbo.a
//            vboMesh.addVertex(ofVec2f(particles[i].position.x,particles[i].position.y));
//            for (int j=0; j<particles.size(); j++){
//            mesh.addVertex(ofVec2f(particles[i].position.x,particles[i].position.y));
//////                        vboMesh.draw();
//            }
            mesh.drawVertices();
            mesh.draw();
        }
//        vboMesh.drawVertices();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
