RGB_MATRIX_EFFECT(TUCO_SOLID)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define TUCO_DIR_HSV   {0, 0, 255}
#define TUCO_L_HSV     {190, 230, 255}
#define TUCO_M_HSV     {185, 242, 255}
#define TUCO_H_HSV     {180, 255, 255}
#define TUCO_PARRY_HSV {156, 255, 255}
#define TUCO_DASH_HSV  {8, 255, 255}
#define TUCO_S1_HSV    {137, 255, 255}
#define TUCO_S2_HSV    {0, 255, 255}
#define TUCO_TEAM_HSV  {52, 255, 255}
#define TUCO_BREAK_HSV {0, 0, 0}
// #define TUCO_ULT_HSV   TUCO_H_HSV
#define TUCO_ULT_HSV   {0, 0, 0}
#define TUCO_THROW_HSV {28, 255, 255}
#define TUCO_TAUNT_HSV {233, 255, 255}


static bool TUCO_SOLID(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    // Array of color codes based on pin order
    hsv_t colors[] = {
         [0] = TUCO_DIR_HSV,   [1] = TUCO_DIR_HSV,    [2] = TUCO_DIR_HSV,    [3] = TUCO_DIR_HSV,
         [4] = TUCO_L_HSV,     [5] = TUCO_M_HSV,      [6] = TUCO_H_HSV,      [7] = TUCO_BREAK_HSV,
         [8] = TUCO_S1_HSV,    [9] = TUCO_S2_HSV,    [10] = TUCO_TEAM_HSV,  [11] = TUCO_ULT_HSV,
        [12] = TUCO_DASH_HSV, [13] = TUCO_THROW_HSV, [14] = TUCO_PARRY_HSV, [15] = TUCO_TAUNT_HSV,
    };

    // Set main button colors
    uint8_t i = 0;
    for (; i < ARRAY_SIZE(colors); i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_t rgb = hsv_to_rgb(colors[i]);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }

    // Set underglow color, uniformily
    rgb_t team_rgb = hsv_to_rgb((hsv_t)TUCO_TEAM_HSV);
    for (; i < 46; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        rgb_matrix_set_color(i, team_rgb.r, team_rgb.g, team_rgb.b);
    }

    return rgb_matrix_check_finished_leds(i);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
