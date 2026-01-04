RGB_MATRIX_EFFECT(TXKO_SOLID)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool TXKO_SOLID(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    hsv_t team_color = {52, 255, 255};
    hsv_t colors[] = {
        [0]  = {  0,   0, 255}, [1]  = {  0,   0, 255}, [2]  = {  0,    0, 255}, [3]  = {  0,   0, 255},
        // [4]  = {190, 230, 255}, [5]  = {185, 242, 255}, [6]  = {180,  255, 255}, [7]  = {  8, 255, 255},
        [4]  = {190, 230, 255}, [5]  = {185, 242, 255}, [6]  = {180,  255, 255}, [7]  = {156, 255, 255},
        [8]  = {137, 255, 255}, [9]  = {  0, 255, 255}, [10] = team_color,       [11] = {156, 255, 255},
        // [12] = {  0,   0,   0}, [13] = {233, 255, 255}, [14] = { 32,  255, 255}, [15] = {  0,   0,   0},
        [12] = {  8, 255, 255}, [13] = {233, 255, 255}, [14] = { 28,  255, 255}, [15] = {156, 255, 255},
    };

    uint8_t i = 0;
    for (; i < ARRAY_SIZE(colors); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_t rgb = hsv_to_rgb(colors[i]);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    rgb_t team_rgb = hsv_to_rgb(team_color);
    for (; i < 46; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, team_rgb.r, team_rgb.g, team_rgb.b);
    }

    return rgb_matrix_check_finished_leds(i);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
