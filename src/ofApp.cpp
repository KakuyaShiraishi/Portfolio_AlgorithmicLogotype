#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofBackground(255);
    
    
    ofxTrueTypeFontUC::setGlobalDpi(400);
    
    
    font1.loadFont("SourceHanCodeJP-Light.otf", 100,true,true, true);
    font1.setLetterSpacing(1.0);
    
    

    Eshow.append("SoundsofFacial");
    Jshow.append("聴覚障害者のための音楽情報呈示");
    
    font1.getStringAsPoints(Eshow);
    

    
    
    //日本語文字列を分割するアルゴリズム
    
    for( int i = 0; i < Jshow.size(); ++i ){
        string bin_str = ofToBinary( Jshow.at( i ) );
        
        if( bin_str.find( "0" ) == 0 ){
            letters.push_back( ofToString( Jshow.at( i ) ) );
        }
        else if( bin_str.find( "110" ) == 0 ){
            letters.push_back( ofToString( Jshow.at( i ) ) + ofToString( Jshow.at( i + 1 ) ) );
        }
        else if( bin_str.find( "1110" ) == 0 ){
            letters.push_back( ofToString( Jshow.at( i ) ) + ofToString( Jshow.at( i + 1 ) ) + ofToString( Jshow.at( i + 2 ) ) );
        }
        else if( bin_str.find( "10" ) == 0  ){
        }
    }
    
    
    
    

    //英語の文字列 vol1
    
    /*
    for(int l = 0; l < Eshow.length(); l++){
        //font1.drawStringAsShapes(ofToString(Eshow.at(i)), 100, 500);
        
        vector < ofTTFCharacter > paths = font1.getStringAsPoints(ofToString(Eshow.at(l)));

        for(int k = 0; k < paths.size(); k++){
            for(int j = 0; j < paths[k].getOutline().size(); j++){
                if( j != 0)ofNextContour(true);
                for(int h = 0; h < paths[k].getOutline()[j].size(); h+=30){
                   // ofDrawEllipse(paths[k].getOutline()[j].getVertices()[h].x, paths[k].getOutline()[j].getVertices()[h].y, 1, 1);
                    //ofVertex(paths[k].getOutline()[j].getVertices()[i].x, paths[k].getOutline()[j].getVertices()[i].y);
                    
                    
                    x = paths[k].getOutline()[j].getVertices()[h].x;
                    y = paths[k].getOutline()[j].getVertices()[h].y;
                    
                    
                    delaunay.addPoint(ofPoint(x,y));

                }
            }
        }

    }
    
    */

    
    
    
    
    
    
    
    //英語の文字列 vol2
    /*
    for(int l = 0; l < Eshow.length(); l++){
        //font1.drawStringAsShapes(ofToString(Eshow.at(i)), 100, 500);
        vector < ofTTFCharacter > paths = font1.getStringAsPoints(ofToString(Eshow.at(l)));
        
        
        for (int i = 0; i < paths.size(); i++){
            for (int j = 0; j < paths[i].getOutline().size(); j++){
                for (int k = 0; k < paths[i].getOutline()[j].size(); k+=30){
                    
                    x = paths[i].getOutline()[j][k].x;
                    y = paths[i].getOutline()[j][k].y;
                    
                    delaunay.addPoint(ofPoint(x,y));
                    
                    //ofDrawEllipse(paths[i].getOutline()[j][k], 1, 1);
                }
            }
        }
    }
*/



    
    
    //日本語の文字列
    
    /*
    for(int i = 0; i < (Jshow.length()/3); i++){
        //font1.drawStringAsShapes(ofToString(letters.at(i)), 100, 500);
        vector < ofTTFCharacter > paths = font1.getStringAsPoints(ofToString(letters.at(i)));
        font1.getStringAsPoints(ofToString(letters.at(0)));
        
        
        ofPushMatrix();
        ofBeginShape();

        for (int i = 0; i < paths.size(); i++){
            for (int j = 0; j < paths[i].getOutline().size(); j++){
                for (int k = 0; k < paths[i].getOutline()[j].size(); k+=1){
                    delaunay.addPoint(ofPoint(paths[i].getOutline()[j][k].x, paths[i].getOutline()[j][k].y));

                    
                    
                    //ofDrawEllipse(paths[i].getOutline()[j][k], 1, 1);
                }
            }
        }
 
        ofPopMatrix();
        
    }
    */
    
 
    
    
    delaunay.triangulate();

}


//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (save) ofBeginSaveScreenAsPDF("exportedData/exported-"+ ofToString(ofGetDay()) + ofToString(ofGetHours()) + ofToString(ofGetMinutes()) + ofToString(ofGetSeconds()) +".pdf", false);
    
    
    ofSetColor(0, 0, 0);
    ofFill();
    
 
    ofTranslate(ofGetWidth()/2-200, ofGetHeight()/2+200);
    
    
    font1.drawStringAsShapes(Jshow, 0, 0);
    
    /*
    
    vector < ofTTFCharacter > paths = font1.getStringAsPoints(ofToString(Jshow));
    
    
    for(int l = 0; l < paths.size(); l++){
        
        for(int k = 0; k < paths[l].getOutline().size(); k++){
            
            ofPoint first;
            
            ofBeginShape();
            
            for(int j = 0; j < paths[l].getOutline()[k].size(); j++){
                ofVec2f pos;
                
                if(j < paths[l].getOutline()[k].size()){
                    // ofDrawEllipse(paths[k].getOutline()[j].getVertices()[h].x, paths[k].getOutline()[j].getVertices()[h].y, 1, 1);
                    ofVertex(paths[l].getOutline()[k].getVertices()[j].x, paths[l].getOutline()[k].getVertices()[j].y);
                }else{
                    pos = first;
                }
            }
            
            ofEndShape();
        }
        
        
    }
    
    */
    
    
    
    
    
    
    //delaunay.draw();
    
    if( save ){
        ofEndSaveScreenAsPDF();
        save = false;
    }
    
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", 10, 15);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's') save = true;
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
