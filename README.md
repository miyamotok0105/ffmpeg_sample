# ffmpeg_sample

1.ffmpegコマンドを動かす    
2.ffmpeg-playerをビルド    



# 1.ffmpegコマンドを動かす

なるべく理解したいffmpeg    
http://d.hatena.ne.jp/zariganitosh/20150619/understand_ffmpeg    
こちらを元に勉強致しました。

## ファイル情報を見る


```
ffmpeg -i shibuya.mp4
```


```
ffmpeg version 3.4.2 Copyright (c) 2000-2018 the FFmpeg developers
  built with Apple LLVM version 9.0.0 (clang-900.0.39.2)
  configuration: --prefix=/usr/local/Cellar/ffmpeg/3.4.2 --enable-shared --enable-pthreads --enable-version3 --enable-hardcoded-tables --enable-avresample --cc=clang --host-cflags= --host-ldflags= --disable-jack --enable-gpl --enable-libmp3lame --enable-libx264 --enable-libxvid --enable-opencl --enable-videotoolbox --disable-lzma
  libavutil      55. 78.100 / 55. 78.100
  libavcodec     57.107.100 / 57.107.100
  libavformat    57. 83.100 / 57. 83.100
  libavdevice    57. 10.100 / 57. 10.100
  libavfilter     6.107.100 /  6.107.100
  libavresample   3.  7.  0 /  3.  7.  0
  libswscale      4.  8.100 /  4.  8.100
  libswresample   2.  9.100 /  2.  9.100
  libpostproc    54.  7.100 / 54.  7.100
Input #0, mov,mp4,m4a,3gp,3g2,mj2, from 'shibuya.mp4':
  Metadata:
    major_brand     : mp42
    minor_version   : 0
    compatible_brands: isommp42
    creation_time   : 2016-08-18T06:41:19.000000Z
  Duration: 00:05:51.78, start: 0.000000, bitrate: 1825 kb/s
    Stream #0:0(und): Video: h264 (Main) (avc1 / 0x31637661), yuv420p, 1280x720 [SAR 1:1 DAR 16:9], 2161 kb/s, 25 fps, 25 tbr, 90k tbn, 50 tbc (default)
    Metadata:
      creation_time   : 2016-08-18T06:41:19.000000Z
      handler_name    : ISO Media file produced by Google Inc.
    Stream #0:1(und): Audio: aac (LC) (mp4a / 0x6134706D), 44100 Hz, stereo, fltp, 125 kb/s (default)
    Metadata:
      creation_time   : 2016-08-18T06:41:19.000000Z
      handler_name    : ISO Media file produced by Google Inc.
At least one output file must be specified

```

Stream #0:0がh264形式のビデオ。    
Stream #0:1がaac音声ファイル。    

Stream #0:0はファイル0番のストリーム0番。    


## 音声を取り出す


```
ffmpeg -i shibuya.mp4 shibuya.mp3
```


```
#copyはそのまま取り出す。mp4内にmp3がないので通らない。
ffmpeg -i shibuya.mp4 -acodec copy shibuya.mp3
#aacがあるので通る
ffmpeg -i shibuya.mp4 -acodec copy shibuya.aac
```

コーデックとは動画をエンコード、符号化、圧縮化する方法のこと。    


## 範囲指定で切り出す


```
#再生時刻1分10秒から2分30秒まで（スタート時刻とエンド時刻を指定）
ffmpeg -i shibuya.mp4 -ss 1:10 -to 2:30 shibuya_110_to_230.mp4
```

## フェードインフィルター


```
#ビデオの先頭から、30フレーム使ってフェードインさせる。
ffmpeg -i shibuya.mp4 -vf "fade=in:0:30" shibuya_fade-in.mp4
```


# 2.ffmpeg-playerをビルド

MacでのSDLの導入    
https://qiita.com/inomasa/items/d5a9c6ebfb2ff2e40003    

SDL version 2.0.8 (stable)のruntimeとsourceをダウンロード。    
https://www.libsdl.org/download-2.0.php    


```
unzip SDL2-2.0.8.zip
cd SDL2-2.0.8
./configure
make
sudo make install

unzip SDL2_mixer-2.0.2
cd SDL2_mixer-2.0.2
./configure
make
sudo make install
```

下記に入ったことを確認。

```
ls /usr/local/include/SDL/
ls /usr/local/include/SDL2/
ls /usr/local/lib/ | grep SDL
```


```
#バイナリを移動
sudo cp -R SDL2.framework/ /Library/Frameworks/SDL2.framework
sudo cp -R SDL2_mixer.framework/ /Library/Frameworks/SDL2_mixer.framework
```



```
#ちなみにbrewでも入るけど、入る場所がlocal以下のフォルダに入る。
brew install sdl sdl_image sdl_mixer sdl_ttf portmidi
```






