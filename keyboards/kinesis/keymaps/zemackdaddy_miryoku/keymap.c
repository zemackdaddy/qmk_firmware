#include QMK_KEYBOARD_H

#define BASE 0
#define BUTTON 1
#define MEDIA 2
#define NAV 3
#define MOUSE 4
#define SYM 5
#define NUM 6
#define FUN 7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
	),
  [BUTTON] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
),
[FUN] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
),
[NUM] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
),
[SYM] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
),
[MOUSE] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
), 
[NAV] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
),
[MEDIA] = LAYOUT(
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		U_NU,								KC_Q,							KC_W,								KC_E,							KC_R,									KC_T,
		U_NU,								LGUI_T(KC_A),			LALT_T(KC_S),				LCTL_T(KC_D),			LSFT_T(KC_F),					KC_G,
		U_NU,								LT(BUTTON, KC_Z),	ALGR_T(KC_X),				KC_C,							KC_V,									KC_B,
		U_NU,								LT(MEDIA, KC_ESC),LT(NAV, KC_SPC),		LT(MOUSE, KC_TAB), 
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU,
    
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,							U_NU,							U_NU,							RESET,
		U_NU,								U_NU,							U_NU,								U_NU,							U_NU,									U_NU,
		KC_Y,								KC_U,							KC_I,								KC_O,							KC_P,									U_NU,
		KC_H,								SFT_T(KC_J),			LCTL_T(KC_K),				LALT_T(KC_L),			LGUI_T(KC_QUOT),			U_NU,
		KC_N,               KC_M,							KC_COMM,						KC_DOT,						KC_SLSH,							U_NU,
		LT(SYM, KC_ENT),		LT(NUM, KC_BSPC),	LT(FUN, KC_DEL),		U_NU,
		U_NU,								U_NU,
		U_NU,
		U_NU,								U_NU,							U_NU
  )
};