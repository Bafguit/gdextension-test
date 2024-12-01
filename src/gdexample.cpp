#define MINIAUDIO_IMPLEMENTATION

#include <godot_cpp/core/class_db.hpp>

#include "gdexample.h"
#include "miniaudio.h"

using namespace godot;

void UclAudioPlayer::_bind_methods() {

}

UclAudioPlayer::UclAudioPlayer() {
    audio_config = ma_decoder_config_init(ma_format_f32, 2, 48000);
}

UclAudioPlayer::~UclAudioPlayer() {
    
}

void UclAudioPlayer::set_audio_from_path(std::string path) {
    ma_decoder_init_file(path.c_str(), &audio_config, &audio);
}