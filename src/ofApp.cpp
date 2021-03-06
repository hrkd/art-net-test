#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    string targetIP = "127.0.0.1";
    int width = 170*2;
    int height = 1;
    int internalformat = GL_RGB;
    sendData.allocate(width, height, internalformat);
    artnet.setup(targetIP);
}

//--------------------------------------------------------------
void ofApp::update(){
    sendData.begin();
        ofClear(0);
        ofColor color;
        color.r = (ofNoise(ofGetElapsedTimef() + 0)*0.5+0.5) * 255;
        color.g = (ofNoise(ofGetElapsedTimef() + 3000)) * 255;
        color.b = (ofNoise(ofGetElapsedTimef() + 1000)) * 255;
        ofSetColor(color);
        ofDrawRectangle(0, 0, sendData.getWidth(), sendData.getHeight());
    sendData.end();
    ofPixels data;
    sendData.readToPixels(data);
    ofxArtnetMessage msg(data);
    msg.setUniverse(0,0,0); //Net:SubNet:Universe
    artnet.sendArtnet(msg);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    sendData.draw(0, 1);
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
