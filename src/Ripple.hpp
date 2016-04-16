//
//  Ripple.hpp
//  vjTest_OSC01
//
//  Created by 松岡正 on 2015/12/03.
//
//

#ifndef Ripple_hpp
#define Ripple_hpp

#include "ofMain.h"
#define BUFFER_SIZE 1024
#define AUDIO_INDEX 10

#endif /* Ripple_hpp */

class Ripple{
public:
    void setup();
    void update(float * _fft);
    void draw();
    
    ofTexture texture;
    ofPoint pos1;
    ofPoint pos2;
    ofPoint pos3;
    ofPoint pos4;
    float size;
    ofSoundStream soundStream;
    float * fft;
    int nBandsToGet;
    float buffer[BUFFER_SIZE];
    float pre_buf,pre_val;
    float vol[AUDIO_INDEX];
};