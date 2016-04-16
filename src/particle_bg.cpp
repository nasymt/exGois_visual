//
//  particle_bg.cpp
//  particle_test
//
//  Created by 松岡正 on 2015/11/28.
//
//

#include "particle_bg.hpp"

void particle_bg::set(){
    pos.x=ofRandom(ofGetWidth());
    pos.y=ofRandom(ofGetHeight());
    pos.z=ofRandom(0,500);
    p_size = ofRandom(2);
}

void particle_bg::reset(){
    pos.x=ofRandom(ofGetWidth());
    pos.y=ofRandom(ofGetHeight());
    pos.z=0;
    p_size = ofRandom(1,4);
}

void particle_bg::update(int _index,float *buffer){
//    float tmp=0;
//    for(int i=0;i<50;i++){
//        tmp+=buffer[i];
//    }
//    tmp/=50;
    float map_tmp=ofMap(buffer[_index], -0.05,0.05, 0,5);
    pos.z++;
    p_size=map_tmp;
    if(_index==0)cout<<map_tmp<<":"<<buffer[0]<<":"<<buffer[1]<<endl;
}

void particle_bg::draw(){
    ofSetColor(255, 255, 255);
    ofCircle(pos ,p_size);
}
