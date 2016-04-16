//
//  FFTWave.hpp
//  vjTest_OSC01
//
//  Created by 松岡正 on 2015/12/05.
//
//

#ifndef FFTWave_hpp
#define FFTWave_hpp

#include "ofMain.h"
#define WAVE_NUM 1000
#define LIGHT_NUM 20

#endif /* FFTWave_hpp */
class FFTWave{
public:
    void setup();
    void update(float * buf,int i);
    void draw(int i);
    void light(int i,bool b);
    void triRotation();

    
    float buffer[WAVE_NUM];
    float pre_buffer,val,pre_val;
    float ave_range;
    float new_val;
    
    ofTexture texture;
    ofPoint pos1;
    ofPoint pos2;
    ofPoint pos3;
    ofPoint pos4;
    ofVec3f lightColor;
    int MAXLightSize;
    int lightSize;
    bool bLight;
    int alpha;
    int scene;
    
    //--------triangle
    int tri_angle;
    ofVec3f triPos;
    int triPosLeft_Right;
    int triPos2;
    float speed;
    ofVec3f targetPos;
};