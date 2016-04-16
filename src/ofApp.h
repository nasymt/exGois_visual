#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"
//#include "ofxOsc.h"
#include "FFTGrid.hpp"
#include "FFTWave.hpp"
#include "particle_bg.hpp"
#include "particle_ripples.hpp"
#include "SimpleLineEffects.hpp"
#include "Ripple.hpp"

#define RIP_NUM 2000
#define BG_NUM 300
#define RIPPLE_NUM 5
#define RIP_PERIOD 250
#define FFT_WAVE_NUM 256
#define FFT_GRID_NUM 100
#define WIDTH 1280
#define HEIGHT 720

#define HOST "localhost"
#define S_PORT 9001
#define R_PORT 9000
#define NUM_MSG_STRINGS 20

#define BUFFER_SIZE 1024
#define AUDIO_INDEX 10




class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void audioReceived(float *buf,int bufSize,int nChan);
    void sceneChange();
    
    
    ofFbo myFbo;
    ofTrueTypeFont font;
    ofxPostGlitch myGlitch;
    ParticleRipples myRipples[RIP_NUM];
    particle_bg myBgParticle[BG_NUM];
    Ripple fftRipple[RIPPLE_NUM];
    FFTGrid fftGrid[FFT_GRID_NUM];
    FFTWave fftWave[FFT_WAVE_NUM];
    SimpleLineEffects simpleLineEffects[FFT_WAVE_NUM];
    int ripple_index;
    int nowTime,targetTime;
    int mode;
    bool bAutoChange;
    
    /*--------OSC---------*/
    /*ofxOscSender sender;
     ofxOscReceiver receiver;
     int current_mgs_string;
     string msg_strings[NUM_MSG_STRINGS];
     float timers[NUM_MSG_STRINGS];
     float beat,temp_beat;
     int low,mid1,mid2,high;*/
    
    /*--------AUDIOGET----------*/
    float * fft;
    int nBandsToGet;
    ofSoundStream soundStream;
    float pre_buf,pre_val;
    float buffer[BUFFER_SIZE];
    
    
};
