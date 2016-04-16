//
//  FFTGrid.cpp
//  vjTest_OSC01
//
//  Created by 松岡正 on 2015/12/06.
//
//

#include "FFTGrid.hpp"

void FFTGrid::setup(){
    cam.setFov(60);
    camPos.set(40,40, 190);
    cam.setPosition(camPos);
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    ave_range=0.5;
    pre_val=1;
    size=0;
    rot.set(-30, -30,0);
}

void FFTGrid::update(float * buf,int i,int j){
   // cam.begin();
    box.set(10);
    ofSetColor(255, 255, 255);
    float new_val=averageVal(buf[i]);
    box.setResolution(1);
    box.setHeight(new_val);

    ofRotateX(rot.x);
    ofRotateY(rot.y);
    ofRotateZ(rot.z);
    
    ofPushMatrix();
    box.setPosition(i*50, 200, j*50-300);
    ofTranslate(ofGetWidth()/2 , ofGetHeight()/2);
    box.drawWireframe();
    ofPopMatrix();
    camPos.z+=5;
    cam.setPosition(camPos);
    
    
    if(size>-2300)size-=2;
    else size=0;
    
    if(rot.z<360)rot.z++;
    else rot.z=0;
    if(rot.y<360)rot.y++;
    else rot.y=0;
    if(rot.x<360)rot.x+=0.1;
    else rot.x=0;
}
void FFTGrid::draw(){
    ofRectMode(OF_RECTMODE_CORNER);
    ofSetColor(0, 200,200);
    box.setResolution(1);
    box.set(500);
    box.setPosition(ofGetWidth()/2, ofGetHeight()/2, size);
    box.drawWireframe();
    ofRectMode(OF_RECTMODE_CENTER);
}

float FFTGrid::averageVal(float num){
/*    if(num<0)num=0;
    val=ave_range*num+(1-ave_range)*pre_val;
    pre_val=val;*/
    val=ave_range*num+(1-ave_range)*pre_val;
    float val2=ofMap(val,-0.005,0.1,0,120);
    float new_val=ofMap(val2,200,800,0,50);
    if(new_val<0)new_val=0;
    else if(new_val>100)new_val=100;
//    cout<<new_val<<":"<<num<<":"<<val2<<endl;

    return new_val;
}