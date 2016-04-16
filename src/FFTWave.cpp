//
//  FFTWave.cpp
//  vjTest_OSC01
//
//  Created by 松岡正 on 2015/12/05.
//
//

#include "FFTWave.hpp"
void FFTWave::setup(){
    pre_val=1;
    ave_range=0.5;
    ofLoadImage(texture,"pTexture.jpg");
    pos1.set(ofGetWidth()/2-200,ofGetHeight()/2-200);
    pos2.set(pos1.x+400, pos1.y);
    pos3.set(pos2.x, pos2.y+400);
    pos4.set(pos1.x, pos3.y);
 
/*    if(ofRandom(-1,1)>0)triPosLeft_Right=1;
    else triPosLeft_Right=0;
    if(triPosLeft_Right==0)triPos.set(ofRandom(-200,0), ofRandom(ofGetHeight()),0);
    else triPos.set(ofRandom(ofGetWidth(),ofGetWidth()+200),ofRandom(ofGetHeight()),0);
    speed=ofRandom(1,4);
    triPos2=ofRandom(500);*/
    
    triPos.set(ofGetWidth()/2, ofGetHeight()/2,0);
    targetPos.set(ofRandom(ofGetWidth()),ofRandom(ofGetHeight()),2000);
    
}

void FFTWave::update(float * buf,int i){
    buffer[i]=buf[i];
}

void FFTWave::draw(int i){

    if(i==0){
        ofBackgroundGradient(ofColor(0,0,0), ofColor(60,60,100));
       // texture.draw(pos1[0],pos2[0],pos3[0],pos4[0]);
    }
    val=ave_range*buffer[i]+(1-ave_range)*pre_val;
    new_val=ofMap(val,-0.05,0.1,0,300);
//    new_val=ofMap(new_val,95,120,0,200);
    if(new_val<0)new_val=0;
//    cout<<"new_val:"<<new_val<<endl;
    ofSetColor(0, 200, 200);
    if(i<120)ofRect(i*5+50, ofGetHeight()/2, 2, new_val);
    else if(i>=120&&i<240)ofRect(i*5+50, ofGetHeight()/2, 2, new_val*-1);
    pre_val=val;
}

void FFTWave::light(int i,bool b){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    if(b)bLight=true;
    if(scene==0){
        MAXLightSize=(int)ofRandom(50,200);
        pos1.set(ofRandom(ofGetWidth()-200)-lightSize/2,ofRandom(ofGetWidth()-200)-lightSize/2);
        pos2.set(pos1.x+lightSize, pos1.y);
        pos3.set(pos2.x, pos2.y+lightSize);
        pos4.set(pos1.x, pos3.y);
        scene=1;
        alpha=255;
    }else if(scene==1){
        if(lightSize<MAXLightSize)lightSize+=2;
        else scene=2;
    }else if(scene==2){
        if(alpha>0)alpha-=5;
        else {
            scene=0;
            bLight=false;
        }
    }
    ofSetColor(255, 255, 255,alpha);

}

void FFTWave::triRotation(){
    ofSetCircleResolution(3);
    ofSetColor(255,255,255);
    ofPushMatrix();
    ofRotateZ(tri_angle);
    ofTranslate(triPos);
    ofCircle(0,0, 20);
    ofPopMatrix();
    tri_angle+=speed;
    triPos.z+=10;
}
