//飞鸟说
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <al.h>
#include <alc.h>
#include <unistd.h>
// C大调基础音阶频率 (C Major Scale Frequencies)
// 第3八度 (低八度)
#define C3 130.81
#define D3 146.83
#define E3 164.81
#define F3 174.61
#define G3 196.00
#define A3 220.00
#define B3 246.94
// 第4八度 (中央C所在八度)
#define C4 261.63
#define D4 293.66
#define E4 329.63
#define F4 349.23
#define G4 392.00
#define A4 440.00
#define B4 493.88
// 第5八度 (高八度)
#define C5 523.25
#define D5 587.33
#define E5 659.25
#define F5 698.46
#define G5 783.99
#define A5 880.00
#define B5 987.77
typedef struct 
{
    int note;
    int octave;
    float duration;
    float volume;
} MusicNote;
float note_to_frequency(int note, int octave) 
{
    if (note == 0) 
    {
        return 0.0f;  // 频率0表示休止符
    }
    // 核心逻辑：将数字音符映射到C大调的自然音级
    switch(note) 
    {
        // 音符 1 对应 Do (C)
        case 1: 
            if(octave == 3) return C3;
            else if(octave == 4) return C4;
            else if(octave == 5) return C5;
            else return 0; // 可扩展更高或更低八度
        // 音符 2 对应 Re (D)
        case 2: 
            if(octave == 3) return D3;
            else if(octave == 4) return D4;
            else if(octave == 5) return D5;
            else return 0;
        // 音符 3 对应 Mi (E)
        case 3: 
            if(octave == 3) return E3;
            else if(octave == 4) return E4;
            else if(octave == 5) return E5;
            else return 0;
        // 音符 4 对应 Fa (F)
        case 4: 
            if(octave == 3) return F3;
            else if(octave == 4) return F4;
            else if(octave == 5) return F5;
            else return 0;
        // 音符 5 对应 Sol (G)
        case 5: 
            if(octave == 3) return G3;
            else if(octave == 4) return G4;
            else if(octave == 5) return G5;
            else return 0;
        // 音符 6 对应 La (A)
        case 6: 
            if(octave == 3) return A3;
            else if(octave == 4) return A4;
            else if(octave == 5) return A5;
            else return 0;
        // 音符 7 对应 Si (B)
        case 7: 
            if(octave == 3) return B3;
            else if(octave == 4) return B4;
            else if(octave == 5) return B5;
            else return 0;
        default: 
            return 0; // 无效音符
    }
}
short* generate_sine_wave(float frequency, float duration, float volume, int* sample_count) 
{
    int sample_rate = 44100;
    int total_samples = (int)(sample_rate * duration);
    *sample_count = total_samples;
    short* buffer = (short*)malloc(total_samples * sizeof(short));
    for(int i = 0; i < total_samples; i++) 
    {
        float time = (float)i / sample_rate;
        float envelope = 1.0;
        if(i < sample_rate * 0.01) 
        {
            envelope = (float)i / (sample_rate * 0.01);
        }
        if(i > total_samples - sample_rate * 0.02) 
        {
            envelope = (float)(total_samples - i) / (sample_rate * 0.02);
        }
        float value = sin(2.0 * M_PI * frequency * time) * volume * envelope;
        buffer[i] = (short)(value * 32767);
    }
    
    return buffer;
}
float get_duration_44(int note_type, int is_dotted) 
{
    float beat_duration = 60.0f / 74.0f;
    float duration;
    
    switch(note_type) 
    {
        case 1:  // 全音符，4拍
            duration = beat_duration * 4.0f;
            break;
        case 2:  // 二分音符，2拍
            duration = beat_duration * 2.0f;
            break;
        case 4:  // 四分音符，1拍
            duration = beat_duration;
            break;
        case 8:  // 八分音符，0.5拍
            duration = beat_duration * 0.5f;
            break;
        case 16: // 十六分音符，0.25拍
            duration = beat_duration * 0.25f;
            break;
        default: // 默认值设为四分音符
            duration = beat_duration;
    }
    
    // 处理附点音符：时值增加原时值的一半
    if(is_dotted) 
    {
        duration *= 1.5f;
    }
    
    return duration;
}
void play_music_score(MusicNote* score, int note_count) 
{
    ALCdevice* device = alcOpenDevice(NULL);
    if(!device) 
    {
        printf("无法打开音频设备\n");
        return;
    }
    
    ALCcontext* context = alcCreateContext(device, NULL);
    alcMakeContextCurrent(context);
    
    ALuint source;
    alGenSources(1, &source);
    for(int i = 0; i < note_count; i++) 
    {
        MusicNote current_note = score[i];
        float frequency = note_to_frequency(current_note.note, current_note.octave);
        
        if(frequency > 0) 
        {
            int sample_count;
            short* audio_data = generate_sine_wave(frequency, current_note.duration, 
                                                  current_note.volume, &sample_count);
            
            ALuint buffer;
            alGenBuffers(1, &buffer);
            alBufferData(buffer, AL_FORMAT_MONO16, audio_data, 
                         sample_count * sizeof(short), 44100);
            
            alSourcei(source, AL_BUFFER, buffer);
            alSourcePlay(source);
            
            // 等待播放完成
            ALint state;
            do 
            {
                alGetSourcei(source, AL_SOURCE_STATE, &state);
                usleep(10000);
            } while(state == AL_PLAYING);
            alDeleteBuffers(1, &buffer);
            free(audio_data);
        } 
        else 
        {
            usleep((int)(current_note.duration * 1000000));
        }
    }
    alDeleteSources(1, &source);
    alcMakeContextCurrent(NULL);
    alcDestroyContext(context);
    alcCloseDevice(device);    
    printf("播放完成！\n");
}
int main() 
{ 
    MusicNote spring_shadow[] = 
{
    {3,4,get_duration_44(8,0),0.7},{5,4,get_duration_44(8,0),0.7},{1,5,get_duration_44(16,0),0.7},{7,4,get_duration_44(8,0),0.7},
    {6,4,get_duration_44(16,0),0.7},{7,4,get_duration_44(8,0),0.7},{6,4,get_duration_44(16,0),0.7},{7,4,get_duration_44(8,0),0.7},
    {1,5,get_duration_44(4,0),0.7}
};   
    int note_count = sizeof(spring_shadow) / sizeof(spring_shadow[0]);
    if(note_count > 0) 
    {
        play_music_score(spring_shadow, note_count);
    } 
    else 
    {
        printf("请先添加音符序列到spring_shadow数组\n");
    }
    return 0;
}