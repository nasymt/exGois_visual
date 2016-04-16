//
//  particle_bg.hpp
//  particle_test
//
//  Created by 松岡正 on 2015/11/28.
//
//

#ifndef particle_bg_hpp
#define particle_bg_hpp

#include <ofMain.h>
#include <stdio.h>

#endif /* particle_bg_hpp */

class particle_bg{
public:
    void set();
    void reset();
    void update(int _index,float *buffer);
    void draw();
    
//private:
    ofVec3f pos;
    float p_size;
    int count;
};