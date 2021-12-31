#include "zemackdaddy_miryoku.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_miryoku(
    U_NP,              U_NP,              U_NP,              U_NP,              U_NP,                 U_NP,            U_NP,             U_NP,             U_NP,
    U_NP,              U_NP,              U_NP,              U_NP,              U_NP,                 U_NP,
    U_NP,              KC_Q,              KC_W,              KC_E,              KC_R,                 KC_T,
    U_NP,              LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),         KC_G,
    U_NP,              LT(BUTTON, KC_Z),  ALGR_T(KC_X),      KC_C,              KC_V,                 KC_B,
    U_NP,              LT(FUN, KC_DEL),   LT(NUM, KC_BSPC),  LT(SYM, KC_ENT),
    U_NP,              U_NP,
    U_NP,              U_NP,              U_NP,              U_NP,
    
    U_NP,              U_NP,              U_NP,              U_NP,              U_NP,                 U_NP,            U_NP,             U_NP,             RESET,
	  U_NP,              U_NP,              U_NP,              U_NP,              U_NP,                 U_NP,
	  KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,                 U_NP,
	  KC_H,              SFT_T(KC_J),       LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),      U_NP,
	  KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT),    LT(BUTTON, KC_SLSH),  U_NP,
		LT(MOUSE, KC_TAB), LT(NAV, KC_SPC),   LT(MEDIA, KC_ESC), U_NP,
    U_NP,              U_NP,
    U_NP,              U_NP,              U_NP,              U_NP,
    )    
};