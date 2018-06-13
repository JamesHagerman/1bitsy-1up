#include <stdio.h>

#include "tracker_app.h"

#include "audio.h"
#include "button_boot.h"
#include "gamepad.h"
#include "lcd.h"
#include "led.h"
#include "math-util.h"
#include "pam8019.h"
#include "systick.h"
#include "text.h"
#include "volume.h"

// Define these to test other audio paths.
//#define MONO
//#define BIT8

#define Fs (44100.0)
#define FREQ0 (440.0 / 8) // A1, 55Hz
#define FREQ1 (523.3 / 8) // C2, 64 Hz

#ifdef MONO
    #define ACC  ACC_MONO
#else
    #define ACC  ACC_STEREO
#endif

#ifdef BIT8
    typedef uint8_t sample;
    #define SAMP_MAX 255
    #define ASD  ASD_8BIT
#else
    typedef uint16_t sample;
    #define SAMP_MAX 4095
    #define ASD  ASD_12BIT
#endif

//static const gfx_rgb565 bg_color  = 0xF81F;
//static const gfx_rgb565 vol_color = 0x07E0;

//static uint8_t prev_vol;

#define FRAMES ((int)Fs / 250)
//DEFINE_AUDIO_BUFFER(abuf, FRAMES, ACC, ASD);

//static void audio_callback(void *buf, size_t frame_count) {
//  // TODO: This is where my NCO phase should be advancing...
//  sample (*frames)[2] = buf;
//  static float phase[2];
//
//  for (size_t i = 0; i < frame_count; i++ ) {
//    frames[i][0] = phase[0] * SAMP_MAX;
//    frames[i][1] = SAMP_MAX - phase[1] * SAMP_MAX;
//    phase[0] += FREQ0 / Fs;
//    phase[1] += FREQ1 / Fs;
//    if (phase[0] >= 1.0)
//      phase[0] -= 1.0;
//    if (phase[1] >= 1.0)
//      phase[1] -= 1.0;
//  }
//}

void tracker_init(void) {
  // audio_init(44100, ACC_STEREO, ASD, abuf, sizeof abuf);
  // audio_register_callback(audio_callback);
  // pam8019_set_mode(PM_NORMAL);
  // audio_start();
  // prev_vol = volume_get();
}

void tracker_animate(void) { 
}

void tracker_render(void) {
  // For now, just render somthing simple...
  //if (lcd_bg_color() != bg_color) {
  //  lcd_set_bg_color(bg_color, true);
  //}

  for (size_t y = 0, h; y < LCD_HEIGHT; y += h) {
    h = MIN(LCD_MAX_SLICE_ROWS, LCD_HEIGHT - y);
    gfx_pixslice *slice = lcd_alloc_pixslice(0, y, LCD_WIDTH, h);
    
    //text_draw_str16(slice, "Volume: ", 4, 10, vol_color); 

    //audio_render_slice(slice);
    lcd_send_pixslice(slice);
  }

}

void tracker_end(void) {
  // audio_stop();
  // pam8019_set_mode(PM_SHUTDOWN);
}
