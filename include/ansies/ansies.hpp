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

#include <memory>
#include <string_view>

namespace ansies {

constexpr char alert = '\a';
constexpr char backspace = '\b';
constexpr char tab = '\t';
constexpr char newline = '\n';
constexpr char vertical_tab = '\v';
constexpr char new_page = '\f';
constexpr char return_line = '\r';
constexpr char del = '\177';

using string_type = std::string_view;

constexpr string_type nothing;

class Sequencer {
    class Impl;
    std::shared_ptr<Impl> impl_;

    string_type escape_ = nothing;
    string_type reset_ = nothing;
    string_type bold_ = nothing;
    string_type faint_ = nothing;
    string_type italic_ = nothing;
    string_type underline_ = nothing;
    string_type slow_blink_ = nothing;
    string_type rapid_blink_ = nothing;
    string_type invert_ = nothing;
    string_type hide_ = nothing;
    string_type strike_ = nothing;
    string_type reset_font_ = nothing;
    string_type alt_font_1_ = nothing;
    string_type alt_font_2_ = nothing;
    string_type alt_font_3_ = nothing;
    string_type alt_font_4_ = nothing;
    string_type alt_font_5_ = nothing;
    string_type alt_font_6_ = nothing;
    string_type alt_font_7_ = nothing;
    string_type alt_font_8_ = nothing;
    string_type alt_font_9_ = nothing;
    string_type fraktur_ = nothing;
    string_type double_underline_ = nothing;
    string_type reset_intensity_ = nothing;
    string_type no_italic_ = nothing;
    string_type no_underline_ = nothing;
    string_type no_blink_ = nothing;
    string_type proportional_spacing_ = nothing;
    string_type no_invert_ = nothing;
    string_type show_ = nothing;
    string_type no_strike_ = nothing;
    string_type black_fg_ = nothing;
    string_type red_fg_ = nothing;
    string_type green_fg_ = nothing;
    string_type yellow_fg_ = nothing;
    string_type blue_fg_ = nothing;
    string_type magenta_fg_ = nothing;
    string_type cyan_fg_ = nothing;
    string_type white_fg_ = nothing;
    string_type reset_fg_ = nothing;
    string_type black_bg_ = nothing;
    string_type red_bg_ = nothing;
    string_type green_bg_ = nothing;
    string_type yellow_bg_ = nothing;
    string_type blue_bg_ = nothing;
    string_type magenta_bg_ = nothing;
    string_type cyan_bg_ = nothing;
    string_type white_bg_ = nothing;
    string_type reset_bg_ = nothing;
    string_type no_proportional_spacing_ = nothing;
    string_type framed_ = nothing;
    string_type encircled_ = nothing;
    string_type overlined_ = nothing;
    string_type no_encircled_no_overlined_ = nothing;
    string_type black_lfg_ = nothing;
    string_type red_lfg_ = nothing;
    string_type green_lfg_ = nothing;
    string_type yellow_lfg_ = nothing;
    string_type blue_lfg_ = nothing;
    string_type magenta_lfg_ = nothing;
    string_type cyan_lfg_ = nothing;
    string_type white_lfg_ = nothing;
    string_type black_lbg_ = nothing;
    string_type red_lbg_ = nothing;
    string_type green_lbg_ = nothing;
    string_type yellow_lbg_ = nothing;
    string_type blue_lbg_ = nothing;
    string_type magenta_lbg_ = nothing;
    string_type cyan_lbg_ = nothing;
    string_type white_lbg_ = nothing;

  public:
    // NOLINTBEGIN(misc-non-private-member-variables-in-classes,
    // cppcoreguidelines-avoid-const-or-ref-data-members,
    // cppcoreguidelines-non-private-member-variables-in-classes)
    const string_type& escape = this->escape_;
    const string_type& reset = this->reset_;
    const string_type& bold = this->bold_;
    const string_type& faint = this->faint_;
    const string_type& italic = this->italic_;
    const string_type& underline = this->underline_;
    const string_type& slow_blink = this->slow_blink_;
    const string_type& rapid_blink = this->rapid_blink_;
    const string_type& invert = this->invert_;
    const string_type& hide = this->hide_;
    const string_type& strike = this->strike_;
    const string_type& reset_font = this->reset_font_;
    const string_type& alt_font_1 = this->alt_font_1_;
    const string_type& alt_font_2 = this->alt_font_2_;
    const string_type& alt_font_3 = this->alt_font_3_;
    const string_type& alt_font_4 = this->alt_font_4_;
    const string_type& alt_font_5 = this->alt_font_5_;
    const string_type& alt_font_6 = this->alt_font_6_;
    const string_type& alt_font_7 = this->alt_font_7_;
    const string_type& alt_font_8 = this->alt_font_8_;
    const string_type& alt_font_9 = this->alt_font_9_;
    const string_type& fraktur = this->fraktur_;
    const string_type& double_underline = this->double_underline_;
    const string_type& reset_intensity = this->reset_intensity_;
    const string_type& no_italic = this->no_italic_;
    const string_type& no_underline = this->no_underline_;
    const string_type& no_blink = this->no_blink_;
    const string_type& proportional_spacing = this->proportional_spacing_;
    const string_type& no_invert = this->no_invert_;
    const string_type& show = this->show_;
    const string_type& no_strike = this->no_strike_;
    const string_type& black_fg = this->black_fg_;
    const string_type& red_fg = this->red_fg_;
    const string_type& green_fg = this->green_fg_;
    const string_type& yellow_fg = this->yellow_fg_;
    const string_type& blue_fg = this->blue_fg_;
    const string_type& magenta_fg = this->magenta_fg_;
    const string_type& cyan_fg = this->cyan_fg_;
    const string_type& white_fg = this->white_fg_;
    const string_type& reset_fg = this->reset_fg_;
    const string_type& black_bg = this->black_bg_;
    const string_type& red_bg = this->red_bg_;
    const string_type& green_bg = this->green_bg_;
    const string_type& yellow_bg = this->yellow_bg_;
    const string_type& blue_bg = this->blue_bg_;
    const string_type& magenta_bg = this->magenta_bg_;
    const string_type& cyan_bg = this->cyan_bg_;
    const string_type& white_bg = this->white_bg_;
    const string_type& reset_bg = this->reset_bg_;
    const string_type& no_proportional_spacing = this->no_proportional_spacing_;
    const string_type& framed = this->framed_;
    const string_type& encircled = this->encircled_;
    const string_type& overlined = this->overlined_;
    const string_type& no_encircled_no_overlined =
        this->no_encircled_no_overlined_;
    const string_type& black_lfg = this->black_lfg_;
    const string_type& red_lfg = this->red_lfg_;
    const string_type& green_lfg = this->green_lfg_;
    const string_type& yellow_lfg = this->yellow_lfg_;
    const string_type& blue_lfg = this->blue_lfg_;
    const string_type& magenta_lfg = this->magenta_lfg_;
    const string_type& cyan_lfg = this->cyan_lfg_;
    const string_type& white_lfg = this->white_lfg_;
    const string_type& black_lbg = this->black_lbg_;
    const string_type& red_lbg = this->red_lbg_;
    const string_type& green_lbg = this->green_lbg_;
    const string_type& yellow_lbg = this->yellow_lbg_;
    const string_type& blue_lbg = this->blue_lbg_;
    const string_type& magenta_lbg = this->magenta_lbg_;
    const string_type& cyan_lbg = this->cyan_lbg_;
    const string_type& white_lbg = this->white_lbg_;
    // NOLINTEND(misc-non-private-member-variables-in-classes,
    // cppcoreguidelines-avoid-const-or-ref-data-members,
    // cppcoreguidelines-non-private-member-variables-in-classes)

  private:
    void construct_(bool enabled);

  public:
    inline Sequencer() { this->construct_(true); }
    inline explicit Sequencer(bool enabled) { this->construct_(enabled); }
};

} // namespace ansies
