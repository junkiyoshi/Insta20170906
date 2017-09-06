#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	this->noise_source = ofRandom(10);
	this->noise_step = 0.05236 / 3;
}

//--------------------------------------------------------------
void ofApp::update(){
	this->noise_source += this->noise_step;
}

//--------------------------------------------------------------
void ofApp::draw(){

	this->cam.begin();

	float radius = 300;
	int deg_span = 15;
	float x, y;
	float tmp_noise_source = this->noise_source;
	ofColor body_color;

	int deg = 0;
	for (int z = -300; z < 300; z += 4) {

		deg += deg_span;

		body_color.setHsb(ofMap(sin(tmp_noise_source), -1, 1, 0, 1) * 255, 255, 255);
		ofSetColor(body_color);

		ofBeginShape();

		float tmp_deg_span = deg_span - 2;

		for (int tmp_deg = deg - tmp_deg_span / 2; tmp_deg <= deg + tmp_deg_span / 2; tmp_deg += 1) {
			x = radius * cos(tmp_deg * DEG_TO_RAD);
			y = radius * sin(tmp_deg * DEG_TO_RAD);

			ofVertex(ofVec3f(x, y, z));
		}

		for (int tmp_deg = deg + tmp_deg_span / 2; tmp_deg >= deg - tmp_deg_span / 2; tmp_deg -= 1) {
			x = (radius * 0.8) * cos(tmp_deg * DEG_TO_RAD);
			y = (radius * 0.8) * sin(tmp_deg * DEG_TO_RAD);

			ofVertex(ofVec3f(x, y, z));
		}

		ofEndShape(true);

		tmp_noise_source += this->noise_step;
	}


	this->cam.end();
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
