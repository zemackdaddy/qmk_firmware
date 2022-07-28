#include QMK_KEYBOARD_H

bool is_alt_tab_active = false; // ADD this near the begining of keymap
uint16_t alt_tab_timer = 0;     // we will be using them soon

enum custom_keycodes {          // Make sure have the awesome keycode ready
  ALT_TAB = SAFE_RANGE,
};

// Tap Dance declarations
enum tap_dance_codes {
    TD_ESC_CAPS,
    TD_GUI_END,
    TD_GUI_PGDN,
    TD_CAPS_MOUSE,
    DANCE_Q,
    DANCE_W,
    DANCE_R,
    DANCE_C,
    DANCE_T,
    DANCE_V,
    //need cut and undo and save
    //left hand mouse buttons and speed
    //mouse layer needs cut/copy/paste/undo or maybe make the f1-f4 do these in every layer
    //mouse layer could exit with F1 instead of end
};

#define DVORAK 0 // Base
#define QWERTY 1
#define MOUSE 2
#define MOD 3
#define CLEAN 4

/****************************************************************************************************
*
* Keymap: Default Layer in Qwerty
*
* ,-------------------------------------------------------------------------------------------------------------------.
* | Esc    |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F8  |  F9  |  F10 |  F12 | PSCR | SLCK | PAUS |  FN0 | KC_MUTE |
* |--------+------+------+------+------+------+---------------------------+------+------+------+------+------+---------|
* | =+     |  1!  |  2@  |  3#  |  4$  |  5%  |                           |  6^  |  7&  |  8*  |  9(  |  0)  | -_      |
* |--------+------+------+------+------+------|                           +------+------+------+------+------+---------|
* | Tab    |   Q  |   W  |   E  |   R  |   T  |                           |   Y  |   U  |   I  |   O  |   P  | \|      |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+---------|
* | Caps   |   A  |   S  |   D  |   F  |   G  |                           |   H  |   J  |   K  |   L  |  ;:  | '"      |
* |--------+------+------+------+------+------|                           |------+------+------+------+------+---------|
* | Shift  |   Z  |   X  |   C  |   V  |   B  |                           |   N  |   M  |  ,.  |  .>  |  /?  | Shift   |
* `--------+------+------+------+------+-------                           `------+------+------+------+------+---------'
*          | `~   | INS  | Left | Right|                                         | Up   | Down |  [{  |  ]}  |
*          `---------------------------'                                         `---------------------------'
*                                        ,-------------.         ,-------------.
*                                        | Ctrl | Alt  |         | Gui  | Ctrl |
*                                 ,------|------|------|         |------+------+------.
*                                 |      |      | Home |         | PgUp |      |      |
*                                 | BkSp | Del  |------|         |------|Return| Space|
*                                 |      |      | End  |         | PgDn |      |      |
*                                 `--------------------'         `--------------------'
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DVORAK] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           HYPR_T(KC_EQL), KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           MEH_T(KC_TAB), KC_QUOT   ,KC_COMM   ,LT(2, KC_DOT)   ,KC_P   ,KC_Y   ,
           TD(TD_CAPS_MOUSE), KC_A   ,KC_O   ,KC_E   ,KC_U   ,KC_I   ,
           KC_LSFT,KC_SCLN   ,KC_Q   , KC_J  , KC_K   ,KC_X   ,
                   KC_GRV ,KC_INS ,KC_LEFT, KC_RGHT,
			                            KC_LCTL,  KC_LALT,
                                                        KC_HOME,
                                  LT(MOD, KC_BSPC), KC_DEL , TD(TD_GUI_END) ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  , KC_PAUS, KC_FN0, TO(QWERTY),
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,HYPR_T(KC_MINS),
	KC_F   ,KC_G  ,KC_C   ,KC_R   ,KC_L   ,MEH_T(KC_SLSH),
	KC_D   ,KC_H   ,KC_T   ,KC_N   ,KC_S,  KC_BSLS,
	KC_B   ,KC_M   ,KC_W, KC_V ,KC_Z, KC_RSFT,
                  KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RALT,  KC_RCTL, 
           LALT_T(KC_PGUP),
           TD(TD_GUI_PGDN),  KC_ENTER ,  LT(MOD, KC_SPC)
    ),

[QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           HYPR_T(KC_EQL), KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           MEH_T(KC_TAB), KC_Q   ,KC_W   ,LT(2, KC_E)   ,KC_R   ,KC_T   ,
           TD(TD_CAPS_MOUSE), KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   , KC_C  , KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT, KC_RGHT,
			                            KC_LCTL,  KC_LALT,
                                                        KC_HOME,
                                  LT(MOD, KC_BSPC), KC_DEL , TD(TD_GUI_END) ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  , KC_PAUS, KC_FN0, TO(DVORAK),
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,HYPR_T(KC_MINS),
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,MEH_T(KC_BSLS),
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,  KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                  KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RALT,  KC_RCTL, 
           LALT_T(KC_PGUP),
           TD(TD_GUI_PGDN),  KC_ENTER ,  LT(MOD, KC_SPC)
    ),

[MOUSE] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  , KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_BTN1   ,LT(1,KC_E)   ,KC_BTN2   ,KC_T  ,
           TO(0), KC_A   ,KC_BTN3   ,KC_BTN2   ,KC_BTN1   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,TD(DANCE_C)  , TD(DANCE_V)   ,KC_ACL0   ,
                   KC_GRV ,KC_INS ,LGUI(LALT(KC_I)),LGUI(LALT(KC_K)),
			   KC_LCTL,KC_LALT,
                                    KC_HOME,
                           KC_ACL1,KC_ACL2 ,TO(DVORAK) ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, TO(DVORAK),
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_WH_U   ,KC_WH_L   ,KC_MS_U   ,KC_WH_R   ,KC_P   ,KC_BSLS,
	KC_WH_D   ,KC_MS_L   ,KC_MS_D   ,KC_MS_R   ,KC_SCLN, KC_QUOT,
	KC_N   ,KC_WH_L   ,KC_WH_D   ,KC_WH_U   ,KC_WH_R, KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,RESET,
           KC_BTN2,KC_BTN1,
           KC_PGUP,
           KC_PGDN,KC_BTN2 ,KC_BTN1
    ),

[MOD] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,
           KC_TAB, KC_ESC   ,RCS(KC_TAB)   ,RCTL(KC_T)   ,RCTL(KC_TAB)   ,LSFT(KC_5)   ,
           KC_CAPS, KC_A   ,RGUI(LSFT(KC_S))   ,ALT_TAB   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   , RCTL(KC_W)  , KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT, KC_RGHT,
			                            KC_LCTL,  KC_LALT,
                                                        KC_HOME,
                                  KC_BSPC ,KC_DEL , KC_END ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  , KC_PAUS, KC_FN0, KC_FN0,
	KC_F9   ,KC_F10   ,KC_F11   ,KC_F12   ,KC_0   ,KC_MINS,
	KC_PGUP   ,KC_HOME   ,KC_UP   ,KC_END   ,KC_P   ,KC_BSLS,
	KC_PGDN   ,KC_LEFT   ,KC_DOWN   ,KC_RGHT   ,KC_SCLN,  KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                  KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,  KC_RCTL, 
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
      	   ),

[CLEAN] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,
           KC_CAPS, KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   , KC_C  , KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT, KC_RGHT,
			                            KC_LCTL,  KC_LALT,
                                                        KC_HOME,
                                  KC_BSPC ,KC_DEL , KC_END ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  , KC_PAUS, KC_FN0, KC_FN0,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,  KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                  KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,  KC_RCTL, 
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) { // This will do most of the grunt work with the keycodes.
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_RGUI);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) { // The very important timer.
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1000) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}




void matrix_init_user(void) {

}

void led_set_user(uint8_t usb_led) {

}

typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state = {
    .is_press_action = true,
    .step = 0
};

uint8_t dance_Q_dance_step(qk_tap_dance_state_t *state);
void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_Q_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_Q_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_Q_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_Q)); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_Q_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state.step = 0;
}

uint8_t dance_W_dance_step(qk_tap_dance_state_t *state);
void dance_W_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_W_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_W_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_W_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_W_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_W); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_W)); break;
        case DOUBLE_TAP: register_code16(KC_W); register_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_W); register_code16(KC_W);
    }
}

void dance_W_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_W); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_W); break;
    }
    dance_state.step = 0;
}

uint8_t dance_R_dance_step(qk_tap_dance_state_t *state);
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_R_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_R_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_R_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_R); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_R)); break;
        case DOUBLE_TAP: register_code16(KC_R); register_code16(KC_R); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_R); register_code16(KC_R);
    }
}

void dance_R_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_R); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_R)); break;
        case DOUBLE_TAP: unregister_code16(KC_R); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_R); break;
    }
    dance_state.step = 0;
}

uint8_t dance_C_dance_step(qk_tap_dance_state_t *state);
void dance_C_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_C_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_C_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_C_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_C_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_C)); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_C_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state.step = 0;
}

uint8_t dance_V_dance_step(qk_tap_dance_state_t *state);
void dance_V_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_V_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_V_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_V_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_V_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_V_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_V)); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state.step = 0;
}

uint8_t dance_TD_CAPS_MOUSE_dance_step(qk_tap_dance_state_t *state);
void dance_TD_CAPS_MOUSE_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_T_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_TD_CAPS_MOUSE_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_TD_CAPS_MOUSE_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_TD_CAPS_MOUSE_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_CAPS); break;
        case SINGLE_HOLD: layer_move(2); break;
        case DOUBLE_TAP: register_code16(KC_CAPS); register_code16(KC_CAPS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_CAPS); register_code16(KC_CAPS);
    }
}

void dance_TD_CAPS_MOUSE_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_CAPS); break;
        case SINGLE_HOLD: unregister_code16(TO(2)); break;
        case DOUBLE_TAP: unregister_code16(KC_CAPS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_CAPS); break;
    }
    dance_state.step = 0;
}

uint8_t dance_TD_GUI_END_dance_step(qk_tap_dance_state_t *state);
void dance_TD_GUI_END_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_TD_GUI_END_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_TD_GUI_END_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_TD_GUI_END_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_TD_GUI_END_dance_step(state);
    switch (dance_state.step)  {
        case SINGLE_TAP: register_code16(KC_END); break;
        case SINGLE_HOLD: register_code16(KC_LGUI); break;
        case DOUBLE_TAP: register_code16(KC_END); register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_END); register_code16(KC_END);
    }
}

void dance_TD_GUI_END_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_END); break;
        case SINGLE_HOLD: unregister_code16(KC_LGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_END); break;
    }
    dance_state.step = 0;
}

uint8_t dance_TD_GUI_PGDN_dance_step(qk_tap_dance_state_t *state);
void dance_TD_GUI_PGDN_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_TD_GUI_PGDN_reset(qk_tap_dance_state_t *state, void *user_data);

uint8_t dance_TD_GUI_PGDN_dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}
void dance_TD_GUI_PGDN_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_TD_GUI_PGDN_dance_step(state);
    switch (dance_state.step)  {
        case SINGLE_TAP: register_code16(KC_PGDN); break;
        case SINGLE_HOLD: register_code16(KC_RGUI); break;
        case DOUBLE_TAP: register_code16(KC_PGDN); register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PGDN); register_code16(KC_END);
    }
}

void dance_TD_GUI_PGDN_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_PGDN); break;
        case SINGLE_HOLD: unregister_code16(KC_RGUI); break;
        case DOUBLE_TAP: unregister_code16(KC_PGDN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PGDN); break;
    }
    dance_state.step = 0;
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_GUI_END] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_TD_GUI_END_finished, dance_TD_GUI_END_reset),
    [TD_GUI_PGDN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_TD_GUI_PGDN_finished, dance_TD_GUI_PGDN_reset),
    [TD_CAPS_MOUSE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_TD_CAPS_MOUSE_finished, dance_TD_CAPS_MOUSE_reset),
    [DANCE_Q] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_Q_finished, dance_Q_reset),
    [DANCE_W] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_W_finished, dance_W_reset),
    [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_R_finished, dance_R_reset),
    [DANCE_C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_C_finished, dance_C_reset),
    [DANCE_V] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_V_finished, dance_V_reset),
};
