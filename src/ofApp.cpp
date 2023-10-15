#include "ofApp.h"
using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	ofSetVerticalSync(true);
	ofSetFrameRate(120);

	objectFinder.setup("haarcascade_frontalface_default.xml");
	objectFinder.setPreset(ObjectFinder::Fast);

	camera.initGrabber(ofGetWidth(), ofGetHeight());
	colorType = DEFAULT;
}

//--------------------------------------------------------------
void ofApp::update(){
	camera.update();
	if (camera.isFrameNew()) {
		objectFinder.update(camera);

		switch (colorType) {
			case DEFAULT: break;
			case GRAY:
				ofxCv::convertColor(camera, gray, CV_RGB2GRAY);
				gray.update();
				break;
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	switch (colorType) {
		case DEFAULT: camera.draw(0, 0); break;
		case GRAY:    gray.draw(0, 0); break;
	}
	objectFinder.draw();
	ofDrawBitmapStringHighlight(ofToString(objectFinder.size()), 10, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case 'a': colorType = DEFAULT; break;
		case 'b': colorType = GRAY; break;
		default: break;
	}
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
