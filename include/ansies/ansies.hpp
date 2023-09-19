/*****************************************************************************/
/*  Copyright (c) 2023 Caden Shmookler                                       */
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

#ifndef ANSIES_ESCAPE_CODE
#define ANSIES_ESCAPE_CODE "\e["
#endif

#ifndef ANSIES_INCLUDE_NONE
#include <string_view>
#endif

namespace ansies {

#ifndef ANSIES_INCLUDE_NONE
using string_type = std::string_view;
#else
using string_type = const char *;
#endif

auto enable() -> void;
auto disable() -> void;

constexpr ::ansies::string_type escape = ANSIES_ESCAPE_CODE;
constexpr ::ansies::string_type reset = ANSIES_ESCAPE_CODE "0m";
constexpr ::ansies::string_type bold = ANSIES_ESCAPE_CODE "1m";
constexpr ::ansies::string_type faint = ANSIES_ESCAPE_CODE "2m";
constexpr ::ansies::string_type italic = ANSIES_ESCAPE_CODE "3m";
constexpr ::ansies::string_type underline = ANSIES_ESCAPE_CODE "4m";
constexpr ::ansies::string_type slow_blink = ANSIES_ESCAPE_CODE "5m";
constexpr ::ansies::string_type rapid_blink = ANSIES_ESCAPE_CODE "6m";
constexpr ::ansies::string_type invert = ANSIES_ESCAPE_CODE "7m";
constexpr ::ansies::string_type hide = ANSIES_ESCAPE_CODE "8m";
constexpr ::ansies::string_type strike = ANSIES_ESCAPE_CODE "9m";
constexpr ::ansies::string_type reset_font = ANSIES_ESCAPE_CODE "10m";
constexpr ::ansies::string_type alt_font_1 = ANSIES_ESCAPE_CODE "11m";
constexpr ::ansies::string_type alt_font_2 = ANSIES_ESCAPE_CODE "12m";
constexpr ::ansies::string_type alt_font_3 = ANSIES_ESCAPE_CODE "13m";
constexpr ::ansies::string_type alt_font_4 = ANSIES_ESCAPE_CODE "14m";
constexpr ::ansies::string_type alt_font_5 = ANSIES_ESCAPE_CODE "15m";
constexpr ::ansies::string_type alt_font_6 = ANSIES_ESCAPE_CODE "16m";
constexpr ::ansies::string_type alt_font_7 = ANSIES_ESCAPE_CODE "17m";
constexpr ::ansies::string_type alt_font_8 = ANSIES_ESCAPE_CODE "18m";
constexpr ::ansies::string_type alt_font_9 = ANSIES_ESCAPE_CODE "19m";
constexpr ::ansies::string_type fraktur = ANSIES_ESCAPE_CODE "20m";
constexpr ::ansies::string_type double_underline = ANSIES_ESCAPE_CODE "21m";
constexpr ::ansies::string_type reset_intensity = ANSIES_ESCAPE_CODE "22m";
constexpr ::ansies::string_type no_italic = ANSIES_ESCAPE_CODE "23m";
constexpr ::ansies::string_type no_underline = ANSIES_ESCAPE_CODE "24m";
constexpr ::ansies::string_type no_blink = ANSIES_ESCAPE_CODE "25m";
constexpr ::ansies::string_type proportional_spacing = ANSIES_ESCAPE_CODE "26m";
constexpr ::ansies::string_type no_invert = ANSIES_ESCAPE_CODE "27m";
constexpr ::ansies::string_type show = ANSIES_ESCAPE_CODE "28m";
constexpr ::ansies::string_type no_strike = ANSIES_ESCAPE_CODE "29m";
constexpr ::ansies::string_type black_fg = ANSIES_ESCAPE_CODE "30m";
constexpr ::ansies::string_type red_fg = ANSIES_ESCAPE_CODE "31m";
constexpr ::ansies::string_type green_fg = ANSIES_ESCAPE_CODE "32m";
constexpr ::ansies::string_type yellow_fg = ANSIES_ESCAPE_CODE "33m";
constexpr ::ansies::string_type blue_fg = ANSIES_ESCAPE_CODE "34m";
constexpr ::ansies::string_type magenta_fg = ANSIES_ESCAPE_CODE "35m";
constexpr ::ansies::string_type cyan_fg = ANSIES_ESCAPE_CODE "36m";
constexpr ::ansies::string_type white_fg = ANSIES_ESCAPE_CODE "37m";
constexpr ::ansies::string_type reset_fg = ANSIES_ESCAPE_CODE "39m";
constexpr ::ansies::string_type black_bg = ANSIES_ESCAPE_CODE "40m";
constexpr ::ansies::string_type red_bg = ANSIES_ESCAPE_CODE "41m";
constexpr ::ansies::string_type green_bg = ANSIES_ESCAPE_CODE "42m";
constexpr ::ansies::string_type yellow_bg = ANSIES_ESCAPE_CODE "43m";
constexpr ::ansies::string_type blue_bg = ANSIES_ESCAPE_CODE "44m";
constexpr ::ansies::string_type magenta_bg = ANSIES_ESCAPE_CODE "45m";
constexpr ::ansies::string_type cyan_bg = ANSIES_ESCAPE_CODE "46m";
constexpr ::ansies::string_type white_bg = ANSIES_ESCAPE_CODE "47m";
constexpr ::ansies::string_type reset_bg = ANSIES_ESCAPE_CODE "49m";
constexpr ::ansies::string_type no_proportional_spacing =
    ANSIES_ESCAPE_CODE "50m";
constexpr ::ansies::string_type framed = ANSIES_ESCAPE_CODE "51m";
constexpr ::ansies::string_type encircled = ANSIES_ESCAPE_CODE "52m";
constexpr ::ansies::string_type overlined = ANSIES_ESCAPE_CODE "53m";
constexpr ::ansies::string_type no_encircled_no_overlined =
    ANSIES_ESCAPE_CODE "54m";
constexpr ::ansies::string_type black_bfg = ANSIES_ESCAPE_CODE "90m";
constexpr ::ansies::string_type red_bfg = ANSIES_ESCAPE_CODE "91m";
constexpr ::ansies::string_type green_bfg = ANSIES_ESCAPE_CODE "92m";
constexpr ::ansies::string_type yellow_bfg = ANSIES_ESCAPE_CODE "93m";
constexpr ::ansies::string_type blue_bfg = ANSIES_ESCAPE_CODE "94m";
constexpr ::ansies::string_type magenta_bfg = ANSIES_ESCAPE_CODE "95m";
constexpr ::ansies::string_type cyan_bfg = ANSIES_ESCAPE_CODE "96m";
constexpr ::ansies::string_type white_bfg = ANSIES_ESCAPE_CODE "97m";
constexpr ::ansies::string_type black_bbg = ANSIES_ESCAPE_CODE "100m";
constexpr ::ansies::string_type red_bbg = ANSIES_ESCAPE_CODE "101m";
constexpr ::ansies::string_type green_bbg = ANSIES_ESCAPE_CODE "102m";
constexpr ::ansies::string_type yellow_bbg = ANSIES_ESCAPE_CODE "103m";
constexpr ::ansies::string_type blue_bbg = ANSIES_ESCAPE_CODE "104m";
constexpr ::ansies::string_type magenta_bbg = ANSIES_ESCAPE_CODE "105m";
constexpr ::ansies::string_type cyan_bbg = ANSIES_ESCAPE_CODE "106m";
constexpr ::ansies::string_type white_bbg = ANSIES_ESCAPE_CODE "107m";

} // namespace ansies
