#ifndef CONFIG_H
#define CONFIG_H

#define MOD Mod4Mask

const char* menu[] = { "drun-hist",    0};
const char* term[] = {"st",    0};
const char* clipbrd[] = {"dclipmenu",    0};

const char* voldown[] = {"amixer",    "sset",    "Master",    "5%-",   0};
const char* volup[] = {"amixer",    "sset",    "Master",    "5%+",    0};
const char* volmute[] = {"amixer",    "sset",    "Master",    "toggle",    0};

#define CMD(cmd){ .com = (const char* []){ "/bin/sh", "-c", cmd, 0}}

static struct key keys[] = {
    {MOD,     XK_space,    run,    {.com = menu}},
    {MOD,     XK_Return,    run,    {.com = term}},

    {MOD,    XK_Tab,    win_next,   {0}},
    {MOD|ShiftMask,    XK_Tab, win_prev,   {0}},

    {0,    XF86XK_AudioLowerVolume,    run,    {.com = voldown}},
    {0,    XF86XK_AudioRaiseVolume,    run,    {.com = volup}},
    {0,    XF86XK_AudioMute,    run,    {.com = volmute}},

    {MOD,    XK_1,    ws_go,     {.i = 1}},
    {MOD,    XK_1,    run,     CMD("dunstify -r 4253 'Desktop        1' -u low -t 1000")},
    {MOD|Mod1Mask,    XK_1, win_to_ws,    {.i = 1}},
    {MOD,    XK_2,    ws_go,    {.i = 2}},
    {MOD,    XK_2,    run,     CMD("dunstify -r 4253 'Desktop        2' -u low -t 1000")},
    {MOD|Mod1Mask,    XK_2,    win_to_ws,    {.i = 2}},

    {0,    XK_F1,    run,     CMD("/usr/local/bin/nclock")},

    {MOD,    XK_a,    run,     {.com = clipbrd}},
    {MOD,    XK_c,    win_center,    {0}},
    {MOD,    XK_f,    win_fs,    {0}},
    {MOD,    XK_q,    win_kill,    {0}},
};

static struct button buttons[] = {
    {MOD,    Button1,    win_raise,    {0}},
    {MOD,    Button1,    win_move,    {0}},
    {MOD,    Button2,    win_raise,    {0}},
    {MOD,    Button2,    win_center,    {0}},
    {MOD,    Button3,    win_raise,    {0}},
    {MOD,    Button3,    win_resize,    {0}},
    {MOD,    Button4,    win_raise,    {0}},
	{MOD,    Button5,    win_lower,    {0}},
};

#endif
