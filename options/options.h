#ifndef MPLAYER_OPTIONS_H
#define MPLAYER_OPTIONS_H

#include <stdbool.h>
#include <stdint.h>
#include "m_option.h"

typedef struct mp_vo_opts {
    struct m_obj_settings *video_driver_list, *vo_defs;

    int ontop;
    int fullscreen;
    int screen_id;
    int fsscreen_id;
    char *winname;
    int x11_netwm;
    int native_keyrepeat;

    float panscan;
    float zoom;
    float pan_x, pan_y;
    float align_x, align_y;
    int unscaled;

    struct m_geometry geometry;
    struct m_geometry autofit;
    struct m_geometry autofit_larger;

    int keepaspect;
    int border;

    int enable_mouse_movements;

    int64_t WinID;

    float force_monitor_aspect;
    float monitor_pixel_aspect;
    int force_window_position;

    int fs_missioncontrol;
} mp_vo_opts;

struct mp_cache_opts {
    int size;
    int def_size;
    int initial;
    int seek_min;
};

typedef struct MPOpts {
    int use_terminal;
    char *msglevels;
    char *dump_stats;
    int verbose;
    int msg_color;
    int msg_module;
    int msg_time;

    char **reset_options;
    char **lua_files;
    char **lua_opts;
    int lua_load_osc;
    int auto_load_scripts;

    struct m_obj_settings *audio_driver_list, *ao_defs;
    int fixed_vo;
    int force_vo;
    int softvol;
    float mixer_init_volume;
    int mixer_init_mute;
    char *mixer_restore_volume_data;
    int volstep;
    float softvol_max;
    int gapless_audio;

    mp_vo_opts vo;
    int allow_win_drag;

    char *wintitle;
    int force_rgba_osd;

    // ranges -100 - 100, 1000 if the vo default should be used
    int gamma_gamma;
    int gamma_brightness;
    int gamma_contrast;
    int gamma_saturation;
    int gamma_hue;

    int stop_screensaver;
    int cursor_autohide_delay;
    int cursor_autohide_fs;

    int requested_colorspace;
    int requested_input_range;
    int requested_output_range;

    int video_rotate;

    char *audio_decoders;
    char *video_decoders;

    int osd_level;
    int osd_duration;
    int osd_fractions;
    int untimed;
    char *stream_capture;
    char *stream_dump;
    int loop_times;
    int loop_file;
    int shuffle;
    int ordered_chapters;
    char *ordered_chapters_files;
    int chapter_merge_threshold;
    double chapter_seek_threshold;
    int load_unsafe_playlists;
    int merge_files;
    int quiet;
    int load_config;
    char *force_configdir;
    int use_filedir_conf;
    int network_rtsp_transport;
    struct mp_cache_opts stream_cache;
    int stream_cache_pause;
    int stream_cache_unpause;
    int chapterrange[2];
    int edition_id;
    int correct_pts;
    int user_pts_assoc_mode;
    int initial_audio_sync;
    int hr_seek;
    float hr_seek_demuxer_offset;
    int hr_seek_framedrop;
    float audio_delay;
    float default_max_pts_correction;
    int autosync;
    int softsleep;
    int frame_dropping;
    int term_osd;
    int term_osd_bar;
    char *term_osd_bar_chars;
    char *playing_msg;
    char *status_msg;
    char *osd_status_msg;
    char *heartbeat_cmd;
    float heartbeat_interval;
    int player_idle_mode;
    int slave_mode;
    int consolecontrols;
    struct m_rel_time play_start;
    struct m_rel_time play_end;
    struct m_rel_time play_length;
    int play_frames;
    double step_sec;
    int position_resume;
    int position_save_on_quit;
    int pause;
    int keep_open;
    int audio_id;
    int video_id;
    int sub_id;
    int sub2_id;
    char **audio_lang;
    char **sub_lang;
    int audio_display;
    int sub_visibility;
    int sub_pos;
    float sub_delay;
    float sub_fps;
    float sub_speed;
    int forced_subs_only;
    int stretch_dvd_subs;
    char *quvi_format;
    int quvi_fetch_subtitles;

    // subreader.c
    int suboverlap_enabled;
    char *sub_cp;

    char *audio_stream;
    char *demuxer_name;
    char *audio_demuxer_name;
    char *sub_demuxer_name;
    int mkv_subtitle_preroll;

    struct image_writer_opts *screenshot_image_opts;
    char *screenshot_template;

    double force_fps;
    int index_mode; // -1=untouched  0=don't use index  1=use (generate) index

    struct mp_chmap audio_output_channels;
    int audio_output_format;
    int force_srate;
    int dtshd;
    double playback_speed;
    struct m_obj_settings *vf_settings, *vf_defs;
    struct m_obj_settings *af_settings, *af_defs;
    int deinterlace;
    float movie_aspect;
    int field_dominance;
    char **sub_name;
    char **sub_paths;
    int sub_auto;
    int osd_bar_visible;
    float osd_bar_align_x;
    float osd_bar_align_y;
    float osd_bar_w;
    float osd_bar_h;
    float osd_scale;
    int osd_scale_by_window;
    struct osd_style_opts *osd_style;
    struct osd_style_opts *sub_text_style;
    float sub_scale;
    float sub_gauss;
    int sub_gray;
    int ass_enabled;
    float ass_line_spacing;
    int ass_use_margins;
    int ass_vsfilter_aspect_compat;
    int ass_vsfilter_color_compat;
    int ass_vsfilter_blur_compat;
    int use_embedded_fonts;
    char **ass_force_style_list;
    char *ass_styles_file;
    int ass_style_override;
    int ass_hinting;
    int ass_shaper;

    int hwdec_api;
    char *hwdec_codecs;

    int network_cookies_enabled;
    char *network_cookies_file;
    char *network_useragent;
    char *network_referrer;
    char **network_http_header_fields;
    int network_tls_verify;
    char *network_tls_ca_file;

    struct lavc_param {
        int fast;
        int show_all;
        char *skip_loop_filter_str;
        char *skip_idct_str;
        char *skip_frame_str;
        int threads;
        int bitexact;
        int check_hw_profile;
        char *avopt;
    } lavc_param;

    struct ad_lavc_param {
        float ac3drc;
        int downmix;
        int threads;
        char *avopt;
    } ad_lavc_param;

    struct lavfdopts {
        int probesize;
        int probescore;
        float analyzeduration;
        int buffersize;
        int allow_mimetype;
        char *format;
        char *cryptokey;
        char *avopt;
        int genptsmode;
    } lavfdopts;

    struct input_conf {
        char *config_file;
        int doubleclick_time;
        int key_fifo_size;
        int ar_delay;
        int ar_rate;
        char *js_dev;
        char *in_file;
        int use_joystick;
        int use_lirc;
        char *lirc_configfile;
        int use_lircc;
        int use_alt_gr;
        int use_appleremote;
        int use_media_keys;
        int default_bindings;
        int test;
    } input;

    struct encode_output_conf {
        char *file;
        char *format;
        char **fopts;
        float fps;
        float maxfps;
        char *vcodec;
        char **vopts;
        char *acodec;
        char **aopts;
        int harddup;
        float voffset;
        float aoffset;
        int copyts;
        int rawts;
        int autofps;
        int neverdrop;
        int video_first;
        int audio_first;
        int metadata;
    } encode_output;
} MPOpts;

extern const m_option_t mp_opts[];
extern const struct MPOpts mp_default_opts;

#endif
