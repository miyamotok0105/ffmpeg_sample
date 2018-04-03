#https://www.tensorflow.org/api_guides/python/contrib.ffmpeg
import tensorflow as tf
from tensorflow.contrib import ffmpeg

audio_binary = tf.read_file('shibuya.mp3')
waveform = ffmpeg.decode_audio(
    audio_binary, file_format='mp3', samples_per_second=44100, channel_count=2)
uncompressed_binary = ffmpeg.encode_audio(
    waveform, file_format='wav', samples_per_second=44100)

print(waveform)
print(uncompressed_binary)
