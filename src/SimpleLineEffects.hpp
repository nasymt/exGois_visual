//
//  SimpleLineEffects.hpp
//  vjTest02
//
//  Created by 松岡正 on 2015/12/02.
//
//

#ifndef SimpleLineEffects_hpp
#define SimpleLineEffects_hpp

#include <stdio.h>
#include "ofMain.h"


#endif /* SimpleLineEffects_hpp */
class SimpleLineEffects{
public:
    void setup();
    void update();
    void draw();
    
    int time,nowTime;
    bool change;
    ofVec2f pos0;
    ofVec2f pos1;
    float distance;
    
    ofTexture texture;
    ofPoint tPos1;
    ofPoint tPos2;
    ofPoint tPos3;
    ofPoint tPos4;
};