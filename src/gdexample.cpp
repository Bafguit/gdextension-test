#define MINIAUDIO_IMPLEMENTATION

#include <godot_cpp/core/class_db.hpp>

#include "gdexample.h"
#include "miniaudio.h"

using namespace godot;

void UclAudioPlayer::_bind_methods() {

}

UclAudioPlayer::UclAudioPlayer() {
    audio_config = ma_decoder_config_init(ma_format_f32, 2, 48000);
    device_config = ma_device_config_init(ma_device_type_playback);
    device_config.playback.format = audio_config.format;
    device_config.playback.channels = audio_config.channels;
    device_config.sampleRate = audio_config.sampleRate;
    device_config.dataCallback = data_callback;

    ma_device_init(NULL, &device_config, &device);
}

UclAudioPlayer::~UclAudioPlayer() {
    ma_decoder_uninit(&audio);
    ma_device_uninit(&device);
}

void UclAudioPlayer::data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount) {
    ma_decoder_read_pcm_frames(&audio, pOutput, frameCount, NULL);
}

void UclAudioPlayer::set_audio_from_path(std::string path) {
    ma_decoder_init_file(path.c_str(), &audio_config, &audio);
}

int UclAudioPlayer::get_audio_playback_time() {
    ma_uint64 check = 0;
    ma_decoder_get_cursor_in_pcm_frames(&audio, &check);

    return check;
}

bool UclAudioPlayer::play() {
    return ma_device_start(&device) == MA_SUCCESS;
}

bool UclAudioPlayer::pause() {
    return ma_device_stop(&device) == MA_SUCCESS;
}

bool UclAudioPlayer::stop() {
    bool check = ma_device_stop(&device) == MA_SUCCESS;
    ma_decoder_seek_to_pcm_frame(&audio, 0);
    return check;
}
