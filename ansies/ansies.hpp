/*****************************************************************************/
/*  Copyright (c) 2024 Caden Shmookler                                       */
/*                                                                           */
/*  This software is provided 'as-is', without any express or implied        */
/*  warranty. In no event will the authors be held liable for any damages    */
/*  arising from the use of this software.                                   */
/*                                                                           */
/*  Permission is granted to anyone to use this software for any purpose,    */
/*  including commercial applications, and to alter it and redistribute it   */
/*  freely, subject to the following restrictions:                           */
/*                                                                           */
/*  1. The origin of this software must not be misrepresented; you must not  */
/*     claim that you wrote the original software. If you use this software  */
/*     in a product, an acknowledgment in the product documentation would    */
/*     be appreciated but is not required.                                   */
/*  2. Altered source versions must be plainly marked as such, and must not  */
/*     be misrepresented as being the original software.                     */
/*  3. This notice may not be removed or altered from any source             */
/*     distribution.                                                         */
/*****************************************************************************/

#pragma once

// Standard includes
#include <cstdint>
#include <string>

// Preprocessor directives
#ifndef ANSIES_NAMESPACE
    #define ANSIES_NAMESPACE esc
#endif

namespace ANSIES_NAMESPACE {

using string_t = std::string;

const string_t escape = "\x1B";

// Colors, Fonts, and Styles
const string_t reset = escape + "[0m";
const string_t bold = escape + "[1m";
const string_t faint = escape + "[2m";
const string_t italic = escape + "[3m";
const string_t underline = escape + "[4m";
const string_t slow_blink = escape + "[5m";
const string_t rapid_blink = escape + "[6m";
const string_t invert = escape + "[7m";
const string_t hide = escape + "[8m";
const string_t strike = escape + "[9m";
const string_t reset_font = escape + "[10m";
const string_t alt_font_1 = escape + "[11m";
const string_t alt_font_2 = escape + "[12m";
const string_t alt_font_3 = escape + "[13m";
const string_t alt_font_4 = escape + "[14m";
const string_t alt_font_5 = escape + "[15m";
const string_t alt_font_6 = escape + "[16m";
const string_t alt_font_7 = escape + "[17m";
const string_t alt_font_8 = escape + "[18m";
const string_t alt_font_9 = escape + "[19m";
const string_t fraktur = escape + "[20m";
const string_t double_underline = escape + "[21m";
const string_t no_bold = escape + "[22m";
const string_t no_italic = escape + "[23m";
const string_t no_underline = escape + "[24m";
const string_t no_blink = escape + "[25m";
const string_t proportional_spacing = escape + "[26m";
const string_t no_invert = escape + "[27m";
const string_t show = escape + "[28m";
const string_t no_strike = escape + "[29m";
const string_t black_fg = escape + "[30m";
const string_t red_fg = escape + "[31m";
const string_t green_fg = escape + "[32m";
const string_t yellow_fg = escape + "[33m";
const string_t blue_fg = escape + "[34m";
const string_t magenta_fg = escape + "[35m";
const string_t cyan_fg = escape + "[36m";
const string_t white_fg = escape + "[37m";
const string_t reset_fg = escape + "[39m";
const string_t black_bg = escape + "[40m";
const string_t red_bg = escape + "[41m";
const string_t green_bg = escape + "[42m";
const string_t yellow_bg = escape + "[43m";
const string_t blue_bg = escape + "[44m";
const string_t magenta_bg = escape + "[45m";
const string_t cyan_bg = escape + "[46m";
const string_t white_bg = escape + "[47m";
const string_t reset_bg = escape + "[49m";
const string_t no_proportional_spacing = escape + "[50m";
const string_t framed = escape + "[51m";
const string_t encircled = escape + "[52m";
const string_t overlined = escape + "[53m";
const string_t no_encircled_no_overlined = escape + "[54m";
const string_t black_lfg = escape + "[90m";
const string_t red_lfg = escape + "[91m";
const string_t green_lfg = escape + "[92m";
const string_t yellow_lfg = escape + "[93m";
const string_t blue_lfg = escape + "[94m";
const string_t magenta_lfg = escape + "[95m";
const string_t cyan_lfg = escape + "[96m";
const string_t white_lfg = escape + "[97m";
const string_t black_lbg = escape + "[100m";
const string_t red_lbg = escape + "[101m";
const string_t green_lbg = escape + "[102m";
const string_t yellow_lbg = escape + "[103m";
const string_t blue_lbg = escape + "[104m";
const string_t magenta_lbg = escape + "[105m";
const string_t cyan_lbg = escape + "[106m";
const string_t white_lbg = escape + "[107m";

// 256 colors
[[nodiscard]] string_t fg(uint8_t index) {
    std::string index_str = std::to_string(index);
    return escape + "[38;5;" + index_str + "m";
}
[[nodiscard]] string_t bg(uint8_t index) {
    std::string index_str = std::to_string(index);
    return escape + "[48;5;" + index_str + "m";
}

// RGB colors
[[nodiscard]] string_t fg(uint8_t red, uint8_t green, uint8_t blue) {
    std::string red_str = std::to_string(red);
    std::string green_str = std::to_string(green);
    std::string blue_str = std::to_string(blue);
    return escape + "[38;2;" + red_str + ";" + green_str + ";" + blue_str + "m";
}
[[nodiscard]] string_t bg(uint8_t red, uint8_t green, uint8_t blue) {
    std::string red_str = std::to_string(red);
    std::string green_str = std::to_string(green);
    std::string blue_str = std::to_string(blue);
    return escape + "[48;2;" + red_str + ";" + green_str + ";" + blue_str + "m";
}

} // namespace ANSIES_NAMESPACE
