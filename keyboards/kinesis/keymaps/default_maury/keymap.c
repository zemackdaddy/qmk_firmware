#include QMK_KEYBOARD_H

enum combo_events {
  RCTLPRGRM_RESET
};

// Tap Dance declarations
enum tap_dance_codes {
    TD_ESC_CAPS,
    DANCE_0,
    DANCE_1,
    DANCE_R,
    DANCE_LEFT_ARROW
};

#define QWERTY 0 // Base qwerty
#define MOUSE 1
#define NAV 2

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
[QWERTY] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           HYPR_T(KC_EQL), KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           MEH_T(KC_TAB), TD(DANCE_0)   ,TD(DANCE_1)   ,LT(1,KC_E)   ,TD(DANCE_R)   ,KC_T   ,
           KC_CAPS,MT(MOD_LALT,KC_A)   ,MT(MOD_LCTL,KC_S)   ,MT(MOD_LGUI,KC_D)   ,MT(MOD_LSFT,KC_F)   ,LT(1,KC_G)   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT, KC_RGHT,
			                            KC_LGUI,  KC_LALT,
                                                        KC_HOME,
                                  KC_BSPC ,KC_DEL , KC_END ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, KC_FN0,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,HYPR_T(KC_MINS),
	KC_Y   ,KC_U   ,LT(1,KC_I)   ,KC_O   ,KC_P   ,MEH_T(KC_BSLS),
	LT(1,KC_H)   ,MT(MOD_RSFT,KC_J)   ,MT(MOD_RGUI,KC_K)   ,MT(MOD_RCTL,KC_L)   ,MT(MOD_RALT,KC_SCLN),  KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                  KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RCTL, KC_RGUI,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),

[MOUSE] = LAYOUT(
           KC_ESC, KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           KC_EQL, KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, KC_Q   ,KC_W   ,LT(1,KC_E)   ,KC_BTN1   ,KC_BTN2  ,
           KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,LGUI(LALT(KC_I)),LGUI(LALT(KC_K)),
			   KC_LCTL,KC_LALT,
                                    KC_HOME,
                           KC_BSPC,KC_DEL ,KC_END ,
    KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, RESET,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_MINS,
	KC_Y   ,KC_BTN1   ,KC_MS_U   ,KC_BTN2   ,KC_P   ,KC_BSLS,
	KC_H   ,KC_MS_L   ,KC_MS_D   ,KC_MS_R   ,KC_SCLN, KC_QUOT,
	KC_N   ,KC_WH_L   ,KC_WH_D   ,KC_WH_U   ,KC_WH_R, KC_RSFT,
		KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RGUI,KC_RCTL,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),

[NAV] = LAYOUT(
           TD(TD_ESC_CAPS), KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,KC_F7  ,KC_F8,
           HYPR_T(KC_EQL), KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,
           KC_TAB, TD(DANCE_0)   ,TD(DANCE_1)   ,LT(1,KC_E)   ,KC_R   ,KC_T   ,
           KC_CAPS,MT(MOD_LALT,KC_A)   ,MT(MOD_LCTL,KC_S)   ,MT(MOD_LGUI,KC_D)   ,MT(MOD_LSFT,KC_F)   ,LT(1,KC_G)   ,
           KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,
                   KC_GRV ,KC_INS ,KC_LEFT, KC_RGHT,
			                            KC_LGUI,  KC_LALT,
                                                        KC_HOME,
                                  KC_BSPC ,KC_DEL , KC_END ,

  KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,KC_PSCR ,KC_SLCK  ,KC_PAUS, KC_FN0, KC_FN0,
	KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,HYPR_T(KC_MINS),
	G(A(KC_SLSH))   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
	G(A(KC_BSLS)),  TD(DANCE_LEFT_ARROW)   ,KC_DOWN   ,KC_UP   ,KC_RIGHT,  KC_QUOT,
	KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                  KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,
           KC_RCTL, KC_RGUI,
           KC_PGUP,
           KC_PGDN,KC_ENTER ,KC_SPC
    ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
   case RCTLPRGRM_RESET:
      if (pressed) {
       reset_keyboard();
      }
      break;
  }
}

void led_set_user(uint8_t usb_led) {

}

//const uint16_t PROGMEM ctrlprgrm_combo[] = {MOD_RCTL, KC__MUTE, COMBO_END};

//combo_t key_combos[COMBO_COUNT] = {
//  [RCTLPRGRM_RESET] = COMBO_ACTION(ctrlprgrm_combo)
//};

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

void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_0_dance_step(qk_tap_dance_state_t *state);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if(state->count > 3) {
        tap_code16(KC_Q);
    }
}

uint8_t dance_0_dance_step(qk_tap_dance_state_t *state) {
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
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_0_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_Q)); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_Q)); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state.step = 0;
}

void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_1_dance_step(qk_tap_dance_state_t *state);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_W);
        tap_code16(KC_W);
        tap_code16(KC_W);
    }
    if(state->count > 3) {
        tap_code16(KC_W);
    }
}

uint8_t dance_1_dance_step(qk_tap_dance_state_t *state) {
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
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_1_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_W); break;
        case SINGLE_HOLD: register_code16(LGUI(KC_W)); break;
        case DOUBLE_TAP: register_code16(KC_W); register_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_W); register_code16(KC_W);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_W); break;
        case SINGLE_HOLD: unregister_code16(LGUI(KC_W)); break;
        case DOUBLE_TAP: unregister_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_W); break;
    }
    dance_state.step = 0;
}

void on_dance_R(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_R_dance_step(qk_tap_dance_state_t *state);
void dance_R_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_R_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_R(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_R);
        tap_code16(KC_R);
        tap_code16(KC_R);
    }
    if(state->count > 3) {
        tap_code16(KC_R);
    }
}

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


void on_dance_leftarrow(qk_tap_dance_state_t *state, void *user_data);
uint8_t dance_leftarrow_dance_step(qk_tap_dance_state_t *state);
void dance_leftarrow_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_leftarrow_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_leftarrow(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT);
    }
}

uint8_t dance_leftarrow_dance_step(qk_tap_dance_state_t *state) {
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
void dance_leftarrow_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state.step = dance_leftarrow_dance_step(state);
    switch (dance_state.step) {
        case SINGLE_TAP: register_code16(KC_LEFT); break;
        case SINGLE_HOLD: register_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: register_code16(LALT(LSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: register_code16(LSFT(KC_LEFT)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT); register_code16(KC_LEFT);
    }
}

void dance_leftarrow_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state.step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT); break;
        case SINGLE_HOLD: unregister_code16(LALT(KC_LEFT)); break;
        case DOUBLE_TAP: unregister_code16(LALT(LSFT(KC_LEFT))); break;
        case DOUBLE_HOLD: unregister_code16(LSFT(KC_LEFT)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT); break;
    }
    dance_state.step = 0;
}

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_R] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_R, dance_R_finished, dance_R_reset),
    [DANCE_LEFT_ARROW] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_leftarrow, dance_leftarrow_finished, dance_leftarrow_reset)
};
