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

#ifndef ANSIES_NAMESPACE
    #define ANSIES_NAMESPACE esc
#endif

namespace ANSIES_NAMESPACE {

using string_t = const char*;

constexpr string_t escape = "\x1B";
constexpr string_t reset = "\x1B[0m";
constexpr string_t bold = "\x1B[1m";
constexpr string_t faint = "\x1B[2m";
constexpr string_t italic = "\x1B[3m";
constexpr string_t underline = "\x1B[4m";
constexpr string_t slow_blink = "\x1B[5m";
constexpr string_t rapid_blink = "\x1B[6m";
constexpr string_t invert = "\x1B[7m";
constexpr string_t hide = "\x1B[8m";
constexpr string_t strike = "\x1B[9m";
constexpr string_t reset_font = "\x1B[10m";
constexpr string_t alt_font_1 = "\x1B[11m";
constexpr string_t alt_font_2 = "\x1B[12m";
constexpr string_t alt_font_3 = "\x1B[13m";
constexpr string_t alt_font_4 = "\x1B[14m";
constexpr string_t alt_font_5 = "\x1B[15m";
constexpr string_t alt_font_6 = "\x1B[16m";
constexpr string_t alt_font_7 = "\x1B[17m";
constexpr string_t alt_font_8 = "\x1B[18m";
constexpr string_t alt_font_9 = "\x1B[19m";
constexpr string_t fraktur = "\x1B[20m";
constexpr string_t double_underline = "\x1B[21m";
constexpr string_t reset_intensity = "\x1B[22m";
constexpr string_t no_italic = "\x1B[23m";
constexpr string_t no_underline = "\x1B[24m";
constexpr string_t no_blink = "\x1B[25m";
constexpr string_t proportional_spacing = "\x1B[26m";
constexpr string_t no_invert = "\x1B[27m";
constexpr string_t show = "\x1B[28m";
constexpr string_t no_strike = "\x1B[29m";
constexpr string_t black_fg = "\x1B[30m";
constexpr string_t red_fg = "\x1B[31m";
constexpr string_t green_fg = "\x1B[32m";
constexpr string_t yellow_fg = "\x1B[33m";
constexpr string_t blue_fg = "\x1B[34m";
constexpr string_t magenta_fg = "\x1B[35m";
constexpr string_t cyan_fg = "\x1B[36m";
constexpr string_t white_fg = "\x1B[37m";
constexpr string_t reset_fg = "\x1B[39m";
constexpr string_t black_bg = "\x1B[40m";
constexpr string_t red_bg = "\x1B[41m";
constexpr string_t green_bg = "\x1B[42m";
constexpr string_t yellow_bg = "\x1B[43m";
constexpr string_t blue_bg = "\x1B[44m";
constexpr string_t magenta_bg = "\x1B[45m";
constexpr string_t cyan_bg = "\x1B[46m";
constexpr string_t white_bg = "\x1B[47m";
constexpr string_t reset_bg = "\x1B[49m";
constexpr string_t no_proportional_spacing = "\x1B[50m";
constexpr string_t framed = "\x1B[51m";
constexpr string_t encircled = "\x1B[52m";
constexpr string_t overlined = "\x1B[53m";
constexpr string_t no_encircled_no_overlined = "\x1B[54m";
constexpr string_t black_lfg = "\x1B[90m";
constexpr string_t red_lfg = "\x1B[91m";
constexpr string_t green_lfg = "\x1B[92m";
constexpr string_t yellow_lfg = "\x1B[93m";
constexpr string_t blue_lfg = "\x1B[94m";
constexpr string_t magenta_lfg = "\x1B[95m";
constexpr string_t cyan_lfg = "\x1B[96m";
constexpr string_t white_lfg = "\x1B[97m";
constexpr string_t black_lbg = "\x1B[100m";
constexpr string_t red_lbg = "\x1B[101m";
constexpr string_t green_lbg = "\x1B[102m";
constexpr string_t yellow_lbg = "\x1B[103m";
constexpr string_t blue_lbg = "\x1B[104m";
constexpr string_t magenta_lbg = "\x1B[105m";
constexpr string_t cyan_lbg = "\x1B[106m";
constexpr string_t white_lbg = "\x1B[107m";

} // namespace ANSIES_NAMESPACE
