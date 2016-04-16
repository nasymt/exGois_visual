//
//  SimpleLineEffects.cpp
//  vjTest02
//
//  Created by 松岡正 on 2015/12/02.
//
//

#include "SimpleLineEffects.hpp"

void SimpleLineEffects::setup(){
    time=ofGetElapsedTimeMillis();
    distance=0;
    ofLoadImage(texture, "pTexture.jpg");
/*    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);*/
}
　
void SimpleLineEffects::update(){
    nowTime=ofGetElapsedTimeMillis();
    if(nowTime>time+500)change=true;
    if(change){
        while(distance<200){
            pos0.set(ofRandom(-200,ofGetWidth()+200),ofRandom(-200,ofGetHeight()+200));
            pos1.set(ofRandom(-200,ofGetWidth()+200),ofRandom(-200,ofGetHeight()+200));
            distance=sqrt((pos1.x-pos0.x)*(pos1.x-pos0.x)+(pos1.y-pos0.y)*(pos1.y-pos0.y));
        }
        tPos1.set(pos0.x, pos0.y);
        tPos2.set(pos0.x+10, pos0.y);
        tPos3.set(pos1.x, pos1.y);
        tPos4.set(tPos3.x+10, tPos3.y);
        time=ofGetElapsedTimeMillis();
        change=false;
        distance=0;
        ofSetLineWidth(ofRandom(20,100));
    }
}

void SimpleLineEffects::draw(){
    ofSetColor(0, 200, 200);
    texture.draw(tPos1,tPos2,tPos3,tPos4);

}

