
//g++ -o dsl1.out dsl1.cpp -lSDL2 -lSDL2_mixer
//g++ dsl1.cpp -o dsl1 -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 -I/Library/Frameworks/SDL2_mixer.framework/Headers -F/Library/Frameworks -framework SDL2_mixer

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    //SDL_mixerの初期化
    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,1024)<0) {
        // 初期化に失敗した時の処理
        fprintf(stderr,"failed to initialize SDL_mixer.\n");
        SDL_Quit();
        exit(-1);
    }

   Mix_Music *music;    // BGM格納用のポインタ
   Mix_Chunk *se1, *se2, *se3;  // SE格納用のポインタ
   int channel1, channel2, channel3;    // SEを再生するための変数

 /* ファイルから読み込む */
    music = Mix_LoadMUS("pi2_001.wav");
    if(!music) {
        cout << "failed to load music: " << Mix_GetError() << endl;
    }

    se1 = Mix_LoadWAV("se_sac01.wav");
    if(!se1) {
       cout << "failed to load music: " << Mix_GetError() << endl;
    }

    se2 = Mix_LoadWAV("se_sab04.wav");
    if(!se1) {
       cout << "failed to load music: " << Mix_GetError() << endl;
    }

    se3 = Mix_LoadWAV("se_sab05.wav");
    if(!se1) {
       cout << "failed to load music: " << Mix_GetError() << endl;
    }

    Mix_PlayMusic(music, -1);

    // SE再生
    channel1 = Mix_PlayChannel(-1, se1, 0);
    channel2 = Mix_PlayChannel(-1, se2, 0);
    channel3 = Mix_PlayChannel(-1, se3, 0);

    // BGM再生
    Mix_PlayMusic(music, -1);

    //ちゃんと終了させるなら…
    SDL_Delay(4000); // 引数のミリ秒処理を遅らせる
    Mix_HaltMusic(); // BGMの停止
    //曲の解放
    Mix_FreeMusic(music);

    //SDL_mixerの終了
    Mix_CloseAudio();

    return 0;
}