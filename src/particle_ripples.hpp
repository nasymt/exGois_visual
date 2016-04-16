//
//  particle_ripples.hpp
//  Gois_ParticleTest2
//
//  Created by 松岡正 on 2015/11/28.
//
//

#ifndef particle_ripples_hpp
#define particle_ripples_hpp

#include "ofMain.h"
#include <stdio.h>
#define RIP_NUM 2000
#define RIP_PERIOD 250

#endif /* particle_ripples_hpp */

class ParticleRipples{
public:
    ParticleRipples();
    void set(int _index);
    void reset(int _index);
    void update(int _ripple_index,int _index);
    void draw();
    
    float angle;
    int speed,alpha;
    
    ofVec3f pos;
    ofVec3f rColor;
    ofVec3f noise;
    float size;
    float count;
    ofPoint pos1;
    ofPoint pos2;
    ofPoint pos3;
    ofPoint pos4;
    ofTexture texture;
};