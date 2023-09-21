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

#define ANSIES_ESCAPE_CODE "\033"

namespace ansies {

constexpr ::ansies::string_type escape = ANSIES_ESCAPE_CODE;
constexpr ::ansies::string_type reset = ANSIES_ESCAPE_CODE "[0m";
constexpr ::ansies::string_type bold = ANSIES_ESCAPE_CODE "[1m";
constexpr ::ansies::string_type faint = ANSIES_ESCAPE_CODE "[2m";
constexpr ::ansies::string_type italic = ANSIES_ESCAPE_CODE "[3m";
constexpr ::ansies::string_type underline = ANSIES_ESCAPE_CODE "[4m";
constexpr ::ansies::string_type slow_blink = ANSIES_ESCAPE_CODE "[5m";
constexpr ::ansies::string_type rapid_blink = ANSIES_ESCAPE_CODE "[6m";
constexpr ::ansies::string_type invert = ANSIES_ESCAPE_CODE "[7m";
constexpr ::ansies::string_type hide = ANSIES_ESCAPE_CODE "[8m";
constexpr ::ansies::string_type strike = ANSIES_ESCAPE_CODE "[9m";
constexpr ::ansies::string_type reset_font = ANSIES_ESCAPE_CODE "[10m";
constexpr ::ansies::string_type alt_font_1 = ANSIES_ESCAPE_CODE "[11m";
constexpr ::ansies::string_type alt_font_2 = ANSIES_ESCAPE_CODE "[12m";
constexpr ::ansies::string_type alt_font_3 = ANSIES_ESCAPE_CODE "[13m";
constexpr ::ansies::string_type alt_font_4 = ANSIES_ESCAPE_CODE "[14m";
constexpr ::ansies::string_type alt_font_5 = ANSIES_ESCAPE_CODE "[15m";
constexpr ::ansies::string_type alt_font_6 = ANSIES_ESCAPE_CODE "[16m";
constexpr ::ansies::string_type alt_font_7 = ANSIES_ESCAPE_CODE "[17m";
constexpr ::ansies::string_type alt_font_8 = ANSIES_ESCAPE_CODE "[18m";
constexpr ::ansies::string_type alt_font_9 = ANSIES_ESCAPE_CODE "[19m";
constexpr ::ansies::string_type fraktur = ANSIES_ESCAPE_CODE "[20m";
constexpr ::ansies::string_type double_underline = ANSIES_ESCAPE_CODE "[21m";
constexpr ::ansies::string_type reset_intensity = ANSIES_ESCAPE_CODE "[22m";
constexpr ::ansies::string_type no_italic = ANSIES_ESCAPE_CODE "[23m";
constexpr ::ansies::string_type no_underline = ANSIES_ESCAPE_CODE "[24m";
constexpr ::ansies::string_type no_blink = ANSIES_ESCAPE_CODE "[25m";
constexpr ::ansies::string_type proportional_spacing =
    ANSIES_ESCAPE_CODE "[26m";
constexpr ::ansies::string_type no_invert = ANSIES_ESCAPE_CODE "[27m";
constexpr ::ansies::string_type show = ANSIES_ESCAPE_CODE "[28m";
constexpr ::ansies::string_type no_strike = ANSIES_ESCAPE_CODE "[29m";
constexpr ::ansies::string_type black_fg = ANSIES_ESCAPE_CODE "[30m";
constexpr ::ansies::string_type red_fg = ANSIES_ESCAPE_CODE "[31m";
constexpr ::ansies::string_type green_fg = ANSIES_ESCAPE_CODE "[32m";
constexpr ::ansies::string_type yellow_fg = ANSIES_ESCAPE_CODE "[33m";
constexpr ::ansies::string_type blue_fg = ANSIES_ESCAPE_CODE "[34m";
constexpr ::ansies::string_type magenta_fg = ANSIES_ESCAPE_CODE "[35m";
constexpr ::ansies::string_type cyan_fg = ANSIES_ESCAPE_CODE "[36m";
constexpr ::ansies::string_type white_fg = ANSIES_ESCAPE_CODE "[37m";
constexpr ::ansies::string_type reset_fg = ANSIES_ESCAPE_CODE "[39m";
constexpr ::ansies::string_type black_bg = ANSIES_ESCAPE_CODE "[40m";
constexpr ::ansies::string_type red_bg = ANSIES_ESCAPE_CODE "[41m";
constexpr ::ansies::string_type green_bg = ANSIES_ESCAPE_CODE "[42m";
constexpr ::ansies::string_type yellow_bg = ANSIES_ESCAPE_CODE "[43m";
constexpr ::ansies::string_type blue_bg = ANSIES_ESCAPE_CODE "[44m";
constexpr ::ansies::string_type magenta_bg = ANSIES_ESCAPE_CODE "[45m";
constexpr ::ansies::string_type cyan_bg = ANSIES_ESCAPE_CODE "[46m";
constexpr ::ansies::string_type white_bg = ANSIES_ESCAPE_CODE "[47m";
constexpr ::ansies::string_type reset_bg = ANSIES_ESCAPE_CODE "[49m";
constexpr ::ansies::string_type no_proportional_spacing =
    ANSIES_ESCAPE_CODE "[50m";
constexpr ::ansies::string_type framed = ANSIES_ESCAPE_CODE "[51m";
constexpr ::ansies::string_type encircled = ANSIES_ESCAPE_CODE "[52m";
constexpr ::ansies::string_type overlined = ANSIES_ESCAPE_CODE "[53m";
constexpr ::ansies::string_type no_encircled_no_overlined =
    ANSIES_ESCAPE_CODE "[54m";
constexpr ::ansies::string_type black_bfg = ANSIES_ESCAPE_CODE "[90m";
constexpr ::ansies::string_type red_bfg = ANSIES_ESCAPE_CODE "[91m";
constexpr ::ansies::string_type green_bfg = ANSIES_ESCAPE_CODE "[92m";
constexpr ::ansies::string_type yellow_bfg = ANSIES_ESCAPE_CODE "[93m";
constexpr ::ansies::string_type blue_bfg = ANSIES_ESCAPE_CODE "[94m";
constexpr ::ansies::string_type magenta_bfg = ANSIES_ESCAPE_CODE "[95m";
constexpr ::ansies::string_type cyan_bfg = ANSIES_ESCAPE_CODE "[96m";
constexpr ::ansies::string_type white_bfg = ANSIES_ESCAPE_CODE "[97m";
constexpr ::ansies::string_type black_bbg = ANSIES_ESCAPE_CODE "[100m";
constexpr ::ansies::string_type red_bbg = ANSIES_ESCAPE_CODE "[101m";
constexpr ::ansies::string_type green_bbg = ANSIES_ESCAPE_CODE "[102m";
constexpr ::ansies::string_type yellow_bbg = ANSIES_ESCAPE_CODE "[103m";
constexpr ::ansies::string_type blue_bbg = ANSIES_ESCAPE_CODE "[104m";
constexpr ::ansies::string_type magenta_bbg = ANSIES_ESCAPE_CODE "[105m";
constexpr ::ansies::string_type cyan_bbg = ANSIES_ESCAPE_CODE "[106m";
constexpr ::ansies::string_type white_bbg = ANSIES_ESCAPE_CODE "[107m";

class Sequencer::Impl {

  bool escape_sequences_enabled = false;

#ifdef _WIN32
  HANDLE std_output_handle = INVALID_HANDLE_VALUE;
  DWORD initial_output_mode = ENABLE_PROCESSED_OUTPUT;
#endif

public:
  Impl() noexcept {
#ifdef _WIN32
    /// @todo Make thread safe.
    // Get the standard output handle.
    this->std_output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (this->std_output_handle == INVALID_HANDLE_VALUE)
      return;

    // Get the current console output mode.
    if (!GetConsoleMode(this->std_output_handle, &this->initial_output_mode))
      return;
    if (!this->initial_output_mode)
      return;

    // Enable virtual terminal processing.
    DWORD new_console_mode =
        this->initial_output_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(this->std_output_handle, new_console_mode))
      return;
#endif
    this->escape_sequences_enabled = true;
  }

  Impl(const Impl &) = delete;
  Impl(Impl &&) noexcept = delete;
  auto operator=(const Impl &) -> Impl & = delete;
  auto operator=(Impl &&) noexcept -> Impl & = delete;

  ~Impl() {
#ifdef _WIN32
    /// @todo Make thread safe.
    // Attempt to reset the console output mode. Do nothing if it fails.
    SetConsoleMode(this->std_output_handle, this->initial_output_mode);
#endif
  }

  bool enabled() const noexcept { return this->escape_sequences_enabled; }
};

Sequencer::Sequencer() : impl_(std::make_shared<::ansies::Sequencer::Impl>()) {
  if (!this->impl_->enabled())
    return;

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
  this->black_bfg_ = ::ansies::black_bfg;
  this->red_bfg_ = ::ansies::red_bfg;
  this->green_bfg_ = ::ansies::green_bfg;
  this->yellow_bfg_ = ::ansies::yellow_bfg;
  this->blue_bfg_ = ::ansies::blue_bfg;
  this->magenta_bfg_ = ::ansies::magenta_bfg;
  this->cyan_bfg_ = ::ansies::cyan_bfg;
  this->white_bfg_ = ::ansies::white_bfg;
  this->black_bbg_ = ::ansies::black_bbg;
  this->red_bbg_ = ::ansies::red_bbg;
  this->green_bbg_ = ::ansies::green_bbg;
  this->yellow_bbg_ = ::ansies::yellow_bbg;
  this->blue_bbg_ = ::ansies::blue_bbg;
  this->magenta_bbg_ = ::ansies::magenta_bbg;
  this->cyan_bbg_ = ::ansies::cyan_bbg;
  this->white_bbg_ = ::ansies::white_bbg;
}

} // namespace ansies
