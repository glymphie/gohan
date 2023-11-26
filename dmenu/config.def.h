/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 1;                      /* -b  option; if 0, dmenu appears at bottom     */
static int centered = 0;                    /* -c option; centers dmenu on screen */
static int min_width = 500;                    /* minimum width when centered */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const int user_bh = 5;               /* add an defined amount of pixels to the bar height */

static const char *fonts[] = { "Comic Code Ligatures,Comic Code Ligatures Medium:style=Medium,Regular:pixelsize=15:antialias=true:autohint=true", "Noto Color Emoji:style=Regular:pixelsize=14:antialias=true:autohint=true" };
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */
static const char *colors[SchemeLast][2] = {
	/*     fg         bg       */
	[SchemeNorm] = { "#d8dee9", "#4c566a" },
	[SchemeSel] = { "#4c566a", "#d8dee9" },
	[SchemeSelHighlight] = { "#4c566a", "#a3be8c" },
	[SchemeNormHighlight] = { "#4c566a", "#a3be8c" },
	[SchemeOut] = { "#4c566a", "#88c0d0" }
};
/* -l and -g options; controls number of lines and columns in grid if > 0 */
static unsigned int lines      = 0;
static unsigned int columns    = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";

/* Size of the window border */
static unsigned int border_width = 0;
