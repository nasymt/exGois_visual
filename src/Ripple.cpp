//
//  Ripple.cpp
//  vjTest_OSC01
//
//  Created by 松岡正 on 2015/12/03.
//
//

#include "Ripple.hpp"
void Ripple::setup(){
    ofLoadImage(texture,"ringTexture.jpg");
    size=100;
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
}

void Ripple::update(float * _fft){
    fft=_fft;
    /*
     pos1.set(ofGetWidth()/2-size/2,ofGetHeight()/2-size/2);
     pos2.set(pos1.x+size,pos1.y);
     pos3.set(pos2.x,pos2.y+size);
     pos4.set(pos1.x,pos3.y);
     if(size<500)size+=10;
     else size=100;*/
    for(int i=0;i<AUDIO_INDEX;i++){
        vol[i]=0;
    }
    
    for(int i=0;i<BUFFER_SIZE;i++){
        for(int j=0;j<AUDIO_INDEX;j++)if(i>=(BUFFER_SIZE/AUDIO_INDEX*j)&&i<(BUFFER_SIZE/AUDIO_INDEX*(j+1)))vol[j]+=fft[i];
    }
}



void Ripple::draw(){
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofBackgroundGradient(ofColor(0, 0,0), ofColor(0,0,10));
    ofSetColor(255, 0, 0,200);
    ofNoFill();
    for(int i=0;i<10;i++){
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, vol[i]*200+50);
    }
    ofFill();
    ofSetRectMode(OF_RECTMODE_CORNER);
}