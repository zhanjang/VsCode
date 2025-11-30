//春日影
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <al.h>
#include <alc.h>
#include <unistd.h>
#define B3 493.88
#define C4 554.37
#define D4 622.25
#define E4 659.26
#define F4 739.99
#define G4 830.61
#define A4 932.33
#define B4 987.77
#define C5 1108.73
#define D5 1244.51
#define E5 1318.51
#define F5 1479.98
#define G5 1661.22
#define A5 1864.66
#define B5 1975.53
float note_to_frequency(int note, int octave) 
{
    switch(note) 
    {
        case 1: return (octave == 4) ? B3 : B4;
        case 2: return (octave == 4) ? C4 : C5;
        case 3: return (octave == 4) ? D4 : D5;
        case 4: return (octave == 4) ? E4 : E5;
        case 5: return (octave == 4) ? F4 : F5;
        case 6: return (octave == 4) ? G4 : G5;
        case 7: return (octave == 4) ? A4 : A5;
        default: return 0;
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

typedef struct 
{
    int note;
    int octave;
    float duration;
    float volume;
} MusicNote;

float get_duration(int note_type, int is_dotted) 
{
    float beat_duration = 60.0 / 97;
    float duration;
    switch(note_type) 
    {
        case 8: duration = beat_duration * 1.5; break;
        case 4: duration = beat_duration; break;
        case 2: duration = beat_duration * 0.5; break;
        case 1: duration = beat_duration * 0.25; break;
        default: duration = beat_duration;
    }
    if(is_dotted) 
    {
        duration *= 1.5;
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
        
        printf("播放进度: %d/%d\n", i+1, note_count);
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
    {3,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},{1,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},
    {3,5,get_duration(2,1),0.7},{4,5,get_duration(1,0),0.7},{3,5,get_duration(2,0),0.7},{2,5,get_duration(8,0),0.7},
    {3,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},{1,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},
    {3,5,get_duration(2,1),0.7},{4,5,get_duration(1,0),0.7},{3,5,get_duration(2,0),0.7},{2,5,get_duration(8,0),0.7},
    {3,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},{1,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},
    {3,5,get_duration(2,1),0.7},{4,5,get_duration(1,0),0.7},{3,5,get_duration(2,0),0.7},{2,5,get_duration(8,0),0.7},
    {3,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},{1,5,get_duration(4,0),0.7},{2,5,get_duration(2,0),0.7},
    {3,5,get_duration(2,1),0.7},{4,5,get_duration(1,0),0.7},{3,5,get_duration(2,0),0.7},{2,5,get_duration(8,0),0.7},
    {1,4,get_duration(1,0),0.7},{2,4,get_duration(1,0),0.7},{3,4,get_duration(2,0),0.7},{3,4,get_duration(2,0),0.7},
    {2,4,get_duration(2,0),0.7},{4,4,get_duration(2,0),0.7},{3,4,get_duration(2,0),0.7},{2,4,get_duration(2,0),0.7},
    {2,4,get_duration(2,0),0.7},{2,4,get_duration(2,0),0.7},{1,4,get_duration(1,0),0.7},{1,4,get_duration(1,0),0.7},{4,4,get_duration(2,0),0.7},{3,4,get_duration(2,0),0.7},{2,4,get_duration(2,0),0.7},
    {2,4,get_duration(4,0),0.7},{1,4,get_duration(1,0),0.7},{2,4,get_duration(1,0),0.7},{3,4,get_duration(8,0),0.7}
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