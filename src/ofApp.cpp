#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    bAutoChange=true;
    /*---------FBO/PostGlitch------------*/
    myFbo.allocate(WIDTH,HEIGHT);
    myGlitch.setup(&myFbo);
    ofSetFrameRate(30);
    /*-------------OSC--------------*/
    /*    sender.setup(HOST,S_PORT);
     receiver.setup(R_PORT);*/
    /*---------FFT-----------------------*/
    nBandsToGet=1024;
    ofSoundStreamSetup(0, 2, 44100, BUFFER_SIZE, 4);
}

//--------------------------------------------------------------
void ofApp::update(){
    nowTime=ofGetElapsedTimeMillis();
    if(bAutoChange)sceneChange();
    /*-----------OSC-------------*/
    /* while(receiver.hasWaitingMessages()){
     ofxOscMessage m;
     receiver.getNextMessage(m);
     
     if(m.getAddress() == "/vol"){
     low=m.getArgAsInt32(0);
     mid1 = m.getArgAsInt32(1);
     mid2 = m.getArgAsInt32(2);
     high = m.getArgAsInt32(3);
     }
     else{
     string msg_string;
     msg_string = m.getAddress();
     msg_string += ": ";
     for(int i = 0; i < m.getNumArgs(); i++){
     msg_string += m.getArgTypeName(i);
     msg_string += ":";
     
     if(m.getArgType(i) == OFXOSC_TYPE_INT32){
     msg_string += ofToString(m.getArgAsInt32(i));
     }
     else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT){
     msg_string += ofToString(m.getArgAsFloat(i));
     }
     else if(m.getArgType(i) == OFXOSC_TYPE_STRING){
     msg_string += m.getArgAsString(i);
     }
     else{
     msg_string += "unknown";
     }
     }
     }
     }*/
    /*-----------------FBO-------------------*/
    myFbo.begin();
    ofClear(0, 0, 0,255);
    if(mode==1){
        ofSetCircleResolution(3);//ÂÆáÂÆôËÉåÊôØ
        for(int i=0;i<BG_NUM;i++){
            myBgParticle[i].update(i,buffer);
            myBgParticle[i].draw();
            if(myBgParticle[i].pos.z>700)myBgParticle[i].reset();
        }
        ofSetCircleResolution(20);
        for(int i=0;i<RIP_NUM;i++){
            for(int j=0;j<8;j++){
                if(i>=j*RIP_PERIOD&&i<j*RIP_PERIOD+RIP_PERIOD)ripple_index=j+1;
                if(myRipples[i].pos.z>600)myRipples[i].reset(i);
            }
            myRipples[i].update(ripple_index,i);
            myRipples[i].draw();
        }
    }
    else if(mode==2){
        for(int i=0;i<RIPPLE_NUM;i++){
            fftRipple[i].update(buffer);
            fftRipple[i].draw();
        }
        for(int i=0;i<FFT_WAVE_NUM;i++){
            fftWave[i].update(buffer,i);
            fftWave[i].draw(i);
        }
    }
    else if(mode==3){
        for(int i=0;i<FFT_GRID_NUM/10;i++){
            for(int j=0;j<FFT_GRID_NUM/10;j++){
                fftGrid[i*10+j].update(buffer,i,j);
                fftGrid[i*10+j].draw();
            }
        }
    }
    
    myFbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
    myGlitch.generateFx();
    ofSetColor(255);
    myFbo.draw(0,0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key=='1'){
        mode=1;
        ofSetFrameRate(30);
        for(int i=0;i<BG_NUM;i++){
            myBgParticle[i].set();
        }
        for(int i=0;i<RIP_NUM;i++){
            for(int j=0;j<8;j++){
                if(i>=j*RIP_PERIOD&&i<j*RIP_PERIOD+RIP_PERIOD)ripple_index=j+1;
            }
            myRipples[i].set(ripple_index);
        }
    }else if(key=='2'){
        mode=2;
        for(int i=0;i<RIPPLE_NUM;i++){
            fftRipple[i].setup();
        }
        
        for(int i=0;i<FFT_WAVE_NUM;i++){
            fftWave[i].setup();
            simpleLineEffects[i].setup();
        }

        
    }else if(key=='3'){
        mode=3;
        ofSetFrameRate(60);
        for(int i=0;i<FFT_GRID_NUM;i++)fftGrid[i].setup();
    }else if(key==OF_KEY_RETURN)ofToggleFullscreen();
    else if(key==OF_KEY_SHIFT){
        
    }
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}
//--------------------------------------------------------------

void ofApp::audioReceived(float *buf,int bufSize,int nChan){
    for(int i=0;i<BUFFER_SIZE;i++){
        buffer[i]=buf[i];
    }
}



/*-----------シーン変更用メソッド-----------*/
void ofApp::sceneChange(){
    nowTime=ofGetElapsedTimeMillis();
    //    cout<<"target:"<<targetTime<<":"<<nowTime<<endl;
    if(mode==1&&nowTime>targetTime){
        mode=2;
        ofSetFrameRate(30);
        targetTime=nowTime+25000;
        for(int i=0;i<RIPPLE_NUM;i++){
            fftRipple[i].setup();
        }
        for(int i=0;i<FFT_WAVE_NUM;i++){
            fftWave[i].setup();
        }
    }else if(mode==2&&nowTime>targetTime){
        mode=3;
        targetTime=nowTime+30000;
        ofSetFrameRate(60);
        /*        for(int i=0;i<FFT_GRID_NUM;i++){
         fftGrid[i].setup();
         }*/
    }else if(mode==3&&nowTime>targetTime){
        mode=1;
        ofSetFrameRate(30);
        targetTime=nowTime+20000;
        for(int i=0;i<BG_NUM;i++){
            myBgParticle[i].set();
        }
        for(int i=0;i<RIP_NUM;i++){
            for(int j=0;j<8;j++){
                if(i>=j*RIP_PERIOD&&i<j*RIP_PERIOD+RIP_PERIOD)ripple_index=j+1;
            }
            myRipples[i].set(ripple_index);
        }
    }
}
