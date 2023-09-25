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

#include "../include/ansies/ansies.hpp"
#include "../include/ansies/version.hpp"

#ifdef _WIN32
    #include <windows.h>
#endif

#define ANSIES_ESC "\033"
#define ANSIES_CSI ANSIES_ESC "["
#define ANSIES_DCS ANSIES_ESC "P"
#define ANSIES_OSC ANSIES_ESC "]"

#define ANSIES_CURSOR_UP "A"
#define ANSIES_CURSOR_DOWN "B"
#define ANSIES_CURSOR_FORWARD "C"
#define ANSIES_CURSOR_BACK "D"
#define ANSIES_CURSOR_NEXT_LINE "E"
#define ANSIES_CURSOR_PREVIOUS_LINE "F"
#define ANSIES_CURSOR_COLUMN "G"

#define ANSIES_GRAPHICS "m"

namespace ansies {

constexpr ::ansies::string_type escape = ANSIES_ESC;
constexpr ::ansies::string_type reset = ANSIES_CSI "0" ANSIES_GRAPHICS;
constexpr ::ansies::string_type bold = ANSIES_CSI "1" ANSIES_GRAPHICS;
constexpr ::ansies::string_type faint = ANSIES_CSI "2" ANSIES_GRAPHICS;
constexpr ::ansies::string_type italic = ANSIES_CSI "3" ANSIES_GRAPHICS;
constexpr ::ansies::string_type underline = ANSIES_CSI "4" ANSIES_GRAPHICS;
constexpr ::ansies::string_type slow_blink = ANSIES_CSI "5" ANSIES_GRAPHICS;
constexpr ::ansies::string_type rapid_blink = ANSIES_CSI "6" ANSIES_GRAPHICS;
constexpr ::ansies::string_type invert = ANSIES_CSI "7" ANSIES_GRAPHICS;
constexpr ::ansies::string_type hide = ANSIES_CSI "8" ANSIES_GRAPHICS;
constexpr ::ansies::string_type strike = ANSIES_CSI "9" ANSIES_GRAPHICS;
constexpr ::ansies::string_type reset_font = ANSIES_CSI "10" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_1 = ANSIES_CSI "11" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_2 = ANSIES_CSI "12" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_3 = ANSIES_CSI "13" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_4 = ANSIES_CSI "14" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_5 = ANSIES_CSI "15" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_6 = ANSIES_CSI "16" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_7 = ANSIES_CSI "17" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_8 = ANSIES_CSI "18" ANSIES_GRAPHICS;
constexpr ::ansies::string_type alt_font_9 = ANSIES_CSI "19" ANSIES_GRAPHICS;
constexpr ::ansies::string_type fraktur = ANSIES_CSI "20" ANSIES_GRAPHICS;
constexpr ::ansies::string_type double_underline =
    ANSIES_CSI "21" ANSIES_GRAPHICS;
constexpr ::ansies::string_type reset_intensity =
    ANSIES_CSI "22" ANSIES_GRAPHICS;
constexpr ::ansies::string_type no_italic = ANSIES_CSI "23" ANSIES_GRAPHICS;
constexpr ::ansies::string_type no_underline = ANSIES_CSI "24" ANSIES_GRAPHICS;
constexpr ::ansies::string_type no_blink = ANSIES_CSI "25" ANSIES_GRAPHICS;
constexpr ::ansies::string_type proportional_spacing =
    ANSIES_CSI "26" ANSIES_GRAPHICS;
constexpr ::ansies::string_type no_invert = ANSIES_CSI "27" ANSIES_GRAPHICS;
constexpr ::ansies::string_type show = ANSIES_CSI "28" ANSIES_GRAPHICS;
constexpr ::ansies::string_type no_strike = ANSIES_CSI "29" ANSIES_GRAPHICS;
constexpr ::ansies::string_type black_fg = ANSIES_CSI "30" ANSIES_GRAPHICS;
constexpr ::ansies::string_type red_fg = ANSIES_CSI "31" ANSIES_GRAPHICS;
constexpr ::ansies::string_type green_fg = ANSIES_CSI "32" ANSIES_GRAPHICS;
constexpr ::ansies::string_type yellow_fg = ANSIES_CSI "33" ANSIES_GRAPHICS;
constexpr ::ansies::string_type blue_fg = ANSIES_CSI "34" ANSIES_GRAPHICS;
constexpr ::ansies::string_type magenta_fg = ANSIES_CSI "35" ANSIES_GRAPHICS;
constexpr ::ansies::string_type cyan_fg = ANSIES_CSI "36" ANSIES_GRAPHICS;
constexpr ::ansies::string_type white_fg = ANSIES_CSI "37" ANSIES_GRAPHICS;
constexpr ::ansies::string_type reset_fg = ANSIES_CSI "39" ANSIES_GRAPHICS;
constexpr ::ansies::string_type black_bg = ANSIES_CSI "40" ANSIES_GRAPHICS;
constexpr ::ansies::string_type red_bg = ANSIES_CSI "41" ANSIES_GRAPHICS;
constexpr ::ansies::string_type green_bg = ANSIES_CSI "42" ANSIES_GRAPHICS;
constexpr ::ansies::string_type yellow_bg = ANSIES_CSI "43" ANSIES_GRAPHICS;
constexpr ::ansies::string_type blue_bg = ANSIES_CSI "44" ANSIES_GRAPHICS;
constexpr ::ansies::string_type magenta_bg = ANSIES_CSI "45" ANSIES_GRAPHICS;
constexpr ::ansies::string_type cyan_bg = ANSIES_CSI "46" ANSIES_GRAPHICS;
constexpr ::ansies::string_type white_bg = ANSIES_CSI "47" ANSIES_GRAPHICS;
constexpr ::ansies::string_type reset_bg = ANSIES_CSI "49" ANSIES_GRAPHICS;
constexpr ::ansies::string_type no_proportional_spacing =
    ANSIES_CSI "50" ANSIES_GRAPHICS;
constexpr ::ansies::string_type framed = ANSIES_CSI "51" ANSIES_GRAPHICS;
constexpr ::ansies::string_type encircled = ANSIES_CSI "52" ANSIES_GRAPHICS;
constexpr ::ansies::string_type overlined = ANSIES_CSI "53" ANSIES_GRAPHICS;
constexpr ::ansies::string_type no_encircled_no_overlined =
    ANSIES_CSI "54" ANSIES_GRAPHICS;
constexpr ::ansies::string_type black_lfg = ANSIES_CSI "90" ANSIES_GRAPHICS;
constexpr ::ansies::string_type red_lfg = ANSIES_CSI "91" ANSIES_GRAPHICS;
constexpr ::ansies::string_type green_lfg = ANSIES_CSI "92" ANSIES_GRAPHICS;
constexpr ::ansies::string_type yellow_lfg = ANSIES_CSI "93" ANSIES_GRAPHICS;
constexpr ::ansies::string_type blue_lfg = ANSIES_CSI "94" ANSIES_GRAPHICS;
constexpr ::ansies::string_type magenta_lfg = ANSIES_CSI "95" ANSIES_GRAPHICS;
constexpr ::ansies::string_type cyan_lfg = ANSIES_CSI "96" ANSIES_GRAPHICS;
constexpr ::ansies::string_type white_lfg = ANSIES_CSI "97" ANSIES_GRAPHICS;
constexpr ::ansies::string_type black_lbg = ANSIES_CSI "100" ANSIES_GRAPHICS;
constexpr ::ansies::string_type red_lbg = ANSIES_CSI "101" ANSIES_GRAPHICS;
constexpr ::ansies::string_type green_lbg = ANSIES_CSI "102" ANSIES_GRAPHICS;
constexpr ::ansies::string_type yellow_lbg = ANSIES_CSI "103" ANSIES_GRAPHICS;
constexpr ::ansies::string_type blue_lbg = ANSIES_CSI "104" ANSIES_GRAPHICS;
constexpr ::ansies::string_type magenta_lbg = ANSIES_CSI "105" ANSIES_GRAPHICS;
constexpr ::ansies::string_type cyan_lbg = ANSIES_CSI "106" ANSIES_GRAPHICS;
constexpr ::ansies::string_type white_lbg = ANSIES_CSI "107" ANSIES_GRAPHICS;

class Sequencer::Impl {
    bool escape_sequences_enabled_ = false;

#ifdef _WIN32
    HANDLE std_output_handle_ = INVALID_HANDLE_VALUE;
    DWORD initial_output_mode_ = ENABLE_PROCESSED_OUTPUT;
#endif

  public:
    Impl() noexcept {
#ifdef _WIN32
        /// @todo Make thread safe.
        // Get the standard output handle.
        this->std_output_handle_ = GetStdHandle(STD_OUTPUT_HANDLE);
        if (this->std_output_handle_ == INVALID_HANDLE_VALUE) {
            return;
        }

        // Get the current console output mode.
        if (! GetConsoleMode(
                this->std_output_handle_, &this->initial_output_mode_)) {
            return;
        }
        if (! this->initial_output_mode_) {
            return;
        }

        // Enable virtual terminal processing.
        DWORD new_console_mode =
            this->initial_output_mode_ | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        if (! SetConsoleMode(this->std_output_handle_, new_console_mode)) {
            return;
        }
#endif
        // NOLINTNEXTLINE(cppcoreguidelines-prefer-member-initializer)
        this->escape_sequences_enabled_ = true;
    }

    Impl(const Impl&) = delete;
    Impl(Impl&&) noexcept = delete;
    Impl& operator=(const Impl&) = delete;
    Impl& operator=(Impl&&) noexcept = delete;

    // NOLINTNEXTLINE(hicpp-use-equals-default, modernize-use-equals-default)
    ~Impl() {
#ifdef _WIN32
        /// @todo Make thread safe.
        // Attempt to reset the console output mode. Do nothing if it fails.
        SetConsoleMode(this->std_output_handle_, this->initial_output_mode_);
#endif
    }

    [[nodiscard]] bool enabled() const noexcept {
        return this->escape_sequences_enabled_;
    }
};

void Sequencer::construct_(bool enabled) {
    if (! enabled) {
        return;
    }

    this->impl_ = std::make_shared<::ansies::Sequencer::Impl>();
    if (! this->impl_->enabled()) {
        return;
    }

    this->escape_ = ::ansies::escape;
    this->reset_ = ::ansies::reset;
    this->bold_ = ::ansies::bold;
    this->faint_ = ::ansies::faint;
    this->italic_ = ::ansies::italic;
    this->underline_ = ::ansies::underline;
    this->slow_blink_ = ::ansies::slow_blink;
    this->rapid_blink_ = ::ansies::rapid_blink;
    this->invert_ = ::ansies::invert;
    this->hide_ = ::ansies::hide;
    this->strike_ = ::ansies::strike;
    this->reset_font_ = ::ansies::reset_font;
    this->alt_font_1_ = ::ansies::alt_font_1;
    this->alt_font_2_ = ::ansies::alt_font_2;
    this->alt_font_3_ = ::ansies::alt_font_3;
    this->alt_font_4_ = ::ansies::alt_font_4;
    this->alt_font_5_ = ::ansies::alt_font_5;
    this->alt_font_6_ = ::ansies::alt_font_6;
    this->alt_font_7_ = ::ansies::alt_font_7;
    this->alt_font_8_ = ::ansies::alt_font_8;
    this->alt_font_9_ = ::ansies::alt_font_9;
    this->fraktur_ = ::ansies::fraktur;
    this->double_underline_ = ::ansies::double_underline;
    this->reset_intensity_ = ::ansies::reset_intensity;
    this->no_italic_ = ::ansies::no_italic;
    this->no_underline_ = ::ansies::no_underline;
    this->no_blink_ = ::ansies::no_blink;
    this->proportional_spacing_ = ::ansies::proportional_spacing;
    this->no_invert_ = ::ansies::no_invert;
    this->show_ = ::ansies::show;
    this->no_strike_ = ::ansies::no_strike;
    this->black_fg_ = ::ansies::black_fg;
    this->red_fg_ = ::ansies::red_fg;
    this->green_fg_ = ::ansies::green_fg;
    this->yellow_fg_ = ::ansies::yellow_fg;
    this->blue_fg_ = ::ansies::blue_fg;
    this->magenta_fg_ = ::ansies::magenta_fg;
    this->cyan_fg_ = ::ansies::cyan_fg;
    this->white_fg_ = ::ansies::white_fg;
    this->reset_fg_ = ::ansies::reset_fg;
    this->black_bg_ = ::ansies::black_bg;
    this->red_bg_ = ::ansies::red_bg;
    this->green_bg_ = ::ansies::green_bg;
    this->yellow_bg_ = ::ansies::yellow_bg;
    this->blue_bg_ = ::ansies::blue_bg;
    this->magenta_bg_ = ::ansies::magenta_bg;
    this->cyan_bg_ = ::ansies::cyan_bg;
    this->white_bg_ = ::ansies::white_bg;
    this->reset_bg_ = ::ansies::reset_bg;
    this->no_proportional_spacing_ = ::ansies::no_proportional_spacing;
    this->framed_ = ::ansies::framed;
    this->encircled_ = ::ansies::encircled;
    this->overlined_ = ::ansies::overlined;
    this->no_encircled_no_overlined_ = ::ansies::no_encircled_no_overlined;
    this->black_lfg_ = ::ansies::black_lfg;
    this->red_lfg_ = ::ansies::red_lfg;
    this->green_lfg_ = ::ansies::green_lfg;
    this->yellow_lfg_ = ::ansies::yellow_lfg;
    this->blue_lfg_ = ::ansies::blue_lfg;
    this->magenta_lfg_ = ::ansies::magenta_lfg;
    this->cyan_lfg_ = ::ansies::cyan_lfg;
    this->white_lfg_ = ::ansies::white_lfg;
    this->black_lbg_ = ::ansies::black_lbg;
    this->red_lbg_ = ::ansies::red_lbg;
    this->green_lbg_ = ::ansies::green_lbg;
    this->yellow_lbg_ = ::ansies::yellow_lbg;
    this->blue_lbg_ = ::ansies::blue_lbg;
    this->magenta_lbg_ = ::ansies::magenta_lbg;
    this->cyan_lbg_ = ::ansies::cyan_lbg;
    this->white_lbg_ = ::ansies::white_lbg;
}

} // namespace ansies
