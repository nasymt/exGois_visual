//
//  FFTGrid.hpp
//  vjTest_OSC01
//
//  Created by 松岡正 on 2015/12/06.
//
//

#ifndef FFTGrid_hpp
#define FFTGrid_hpp

#include "ofMain.h"

#endif /* FFTGrid_hpp */

class FFTGrid{
public:
    void setup();
    void update(float * buf,int i,int j);
    void draw();
    ofVec3f pos;
    ofBoxPrimitive box;
    ofCamera cam;
    ofVec3f camPos;
    
    float averageVal(float num);
    float pre_val,val,ave_range;
    int size;
    ofVec3f rot;
};
