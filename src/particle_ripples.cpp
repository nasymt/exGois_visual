//
//  particle_ripples.cpp
//  Gois_ParticleTest2
//
//  Created by 松岡正 on 2015/11/28.
//
//

#include "particle_ripples.hpp"

ParticleRipples::ParticleRipples(){
    ofLoadImage(texture,"pTexture.jpg");
}

void ParticleRipples::set(int _index){
    pos.x=100;
    pos.y=0;
    
    for(int i=0;i<8;i++){
        if(_index==i){
            pos.z=i*70;
        }
    }
    speed=1;
    if(_index==1)rColor.set(200,0,150);
    else if(_index==2)rColor.set(220, 220,0);
    else if(_index==3)rColor.set(0,152, 152);
    else if(_index==4)rColor.set(54,16, 175);
    else if(_index==5)rColor.set(71, 219,0);
    else if(_index==6)rColor.set(226,0, 68);
    else if(_index==7)rColor.set(253, 121,0);
    else if(_index==8)rColor.set(122,6,168);
    rColor.set(0,200,200);
    
    noise.set(ofRandom(20),ofRandom(20),ofRandom(20));
    size=ofRandom(2,10);
    alpha=255;
}

void ParticleRipples::reset(int _index){
    pos.z=0;
    noise.set(ofRandom(20),ofRandom(20),ofRandom(20));
    size=ofRandom(2,10);
    alpha=0;
}

void ParticleRipples::update(int _ripple_index,int _index){
    angle=_index;
    while(angle>RIP_PERIOD)angle-=RIP_PERIOD;
    angle=angle*360/RIP_PERIOD;
    pos.z+=speed;
    count+=0.2;
    alpha++;
    pos1.set(pos.x, pos.y,pos.z);
    pos2.set(pos1.x+size, pos1.y,pos.z);
    pos3.set(pos2.x, pos2.y+size,pos.z);
    pos4.set(pos1.x, pos3.y,pos.z);
}

void ParticleRipples::draw(){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
//    ofSetColor(0, 200, 200,alpha);
    ofSetColor(rColor.x,rColor.y,rColor.z,alpha);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateZ(angle+count);
    ofPushMatrix();
    ofTranslate(noise);
    texture.draw(pos1, pos2, pos3, pos4);
    ofPopMatrix();
    ofPopMatrix();
}