#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/audio_stream.hpp>

namespace godot {
    class UclAudioPlayer : public Object {
        GDCLASS(UclAudioPlayer, Object)

        private:
            ma_decoder audio;
            ma_decoder_config audio_config;
        
        protected:
            static void _bind_methods();
        
        public:
            UclAudioPlayer();
            ~UclAudioPlayer();

            //void _process(double delta) override;

            void set_audio_from_path(std::string path);
            void set_audio_from_file(AudioStream file);
    };
}

#endif