/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 8;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 8;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static int floatposgrid_x           = 5;        /* float grid columns */
static int floatposgrid_y           = 5;        /* float grid rows */
static const char *fonts[]          = { "Hack Nerd Font Mono:pixelsize=15:antialias=true:autohint=true", "emoji:pixelsize=15:antialias=true:autohint=true" };
static const char dmenufont[]       = "Hack Nerd Font Mono:pixelsize=15:antialias=true:autohint=true";
static const char col_normfg[]      = "#ffffff";
static const char col_normbg[]      = "#111111";
static const char col_selfg[]       = "#111111";
static const char col_selbg[]       = "#ffffff";
static const char col_normborder[]  = "#111111";
static const char col_selborder[]   = "#ffffff";

enum { SchemeNorm, SchemeCol1, SchemeCol2, SchemeCol3, SchemeCol4,
       SchemeCol5, SchemeCol6, SchemeSel }; /* color schemes */

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_normfg, col_normbg, col_normborder },
	[SchemeCol1]  = { col_normfg, col_normbg, col_normborder },
	[SchemeCol2]  = { col_normfg, col_normbg, col_normborder },
	[SchemeCol3]  = { col_normfg, col_normbg, col_normborder },
	[SchemeCol4]  = { col_normfg, col_normbg, col_normborder },
	[SchemeCol5]  = { col_normfg, col_normbg, col_normborder },
	[SchemeCol6]  = { col_normfg, col_normbg, col_normborder },
	[SchemeSel]  = { col_selfg, col_selbg,  col_selborder  },
};

static const XPoint stickyicon[]    = { {0,0}, {4,0}, {4,8}, {2,6}, {0,8}, {0,0} }; /* represents the icon as an array of vertices */
static const XPoint stickyiconbb    = {4,8};	/* defines the bottom right corner of the polygon's bounding box (speeds up scaling) */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class     		instance  title           	tags mask	isfloating	isterminal	noswallow	floatpos		  			monitor */
	{ "st",      		NULL,     NULL,           	0,         	0,          1,          0,       	NULL,			  			-1 },
	{ NULL,		        NULL,     "Event Tester", 	0,         	1,          0,          1,       	NULL,			  			-1 }, /* xev */
	{ NULL,		 		NULL,     "pulsemixer",   	0,    	   	1,          0,          -1,       	"50% 50%",			  		-1 },
	{ "b_mouse",		NULL,     NULL,   	 	  	0,    	   	1,          0,          -1,       	"0m 0m 400W 200H", 			-1 },
	{ "b_float_wttr",	NULL,     NULL,   	 	  	0,    	   	1,          0,          -1,       	"50% 50% 780W 900H", 	 	-1 } 
};

/* layout(s) */
static const float mfact     = 0.60; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-i", "-c", "-l", "20","-bw","3", NULL };
/* static const char *termcmd[]  = { "st", NULL }; */

#include "movestack.c"
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_s,      spawn,          {.v = dmenucmd } },
/*	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } }, */
	{ MODKEY|ShiftMask,				XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.01} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.01} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,  			            XK_x,      incrgaps,       {.i = +1 } },
	{ MODKEY,					    XK_z,      incrgaps,       {.i = -1 } },
/*	{ MODKEY|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } }, */
/*	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } }, */
/*	{ MODKEY|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } }, */
/*	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } }, */
/*	{ MODKEY|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } }, */
/*	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } }, */
/*	{ MODKEY|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } }, */
/*	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } }, */
/*	{ MODKEY|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } }, */
/*	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } }, */
/*	{ MODKEY|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } }, */
/*	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } }, */
	{ MODKEY|ShiftMask,             XK_x,      togglegaps,     {0} },
	{ MODKEY|ShiftMask,             XK_g,      defaultgaps,    {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|Mod1Mask, 				XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|Mod1Mask,				XK_m,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|Mod1Mask,				XK_slash,  setlayout,      {.v = &layouts[3]} },
	{ MODKEY|Mod1Mask,				XK_d,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY|Mod1Mask,				XK_n,      setlayout,      {.v = &layouts[8]} },
	{ MODKEY|Mod1Mask,				XK_c,      setlayout,      {.v = &layouts[11]} },
	{ MODKEY|Mod1Mask,				XK_f,      setlayout,      {.v = &layouts[13]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = -1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Escape, quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

