///                MentOS, The Mentoring Operating system project
/// @file termios-struct.h
/// @brief Definition of the `termios` structure.
/// @copyright (c) 2014-2021 This file is distributed under the MIT License.
/// See LICENSE.md for details.

#pragma once

/// Type for control characters.
typedef unsigned char cc_t;
/// Type for speed.
typedef unsigned int speed_t;
/// Type for flags.
typedef unsigned int tcflag_t;
/// The number of control characters.
#define NCCS 32

/// @brief Stores information about a terminal IOs.
typedef struct termios {
    tcflag_t c_iflag; ///< input mode flags
    tcflag_t c_oflag; ///< output mode flags
    tcflag_t c_cflag; ///< control mode flags
    tcflag_t c_lflag; ///< local mode flags
    cc_t c_line;      ///< line discipline
    cc_t c_cc[NCCS];  ///< control characters
    speed_t c_ispeed; ///< input speed
    speed_t c_ospeed; ///< output speed
} termios;

/// @brief These flags generally control higher-level aspects of input processing than the input
/// modes flags described in Input Modes, such as echoing, signals, and the choice of canonical
/// or noncanonical input.
enum {
    ISIG    = 000001U, ///< Controls whether the INTR, QUIT, and SUSP characters are recognized.
    ICANON  = 000002U, ///< Enables canonical input processing mode.
    ECHO    = 000010U, ///< Echo input characters.
    ECHOE   = 000020U, ///< If ICANON is set, the ERASE character erases the preceding character.
    ECHOK   = 000040U, ///< If ICANON is set, the KILL character erases the current line.
    ECHONL  = 000100U, ///< If ICANON is set, echo the NL character even if ECHO is not set.
    NOFLSH  = 000200U, ///< Do not clear in/out queues when receiving INTR, QUIT, and SUSP.
    TOSTOP  = 000400U, ///< Allows SIGTTOU signals generated by background processes.
    ECHOCTL = 001000U, ///< If this and ECHO are set, control characters with ‘^’ are echoed.
    ECHOKE  = 004000U, ///< If ICANON is set, KILL is echoed by erasing each character on the line.
    IEXTEN  = 100000U, ///< Enables implementation-defined input processing.
};