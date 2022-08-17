/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bekk <ael-bekk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:40:53 by ael-bekk          #+#    #+#             */
/*   Updated: 2022/08/14 20:32:48 by ael-bekk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void    mouse_press_intro(int key)
{
    if (key == LEFT_CLICK)
        data.mouse.on_click = 1;
}

void    mouse_press_setting(int key, int x, int y)
{
    if (key == LEFT_CLICK)
    {
        if (data.mode == SETTING)
        {
            if (x >= (RES_X - data.intro.start.x) / 2 && y >= (RES_Y - data.intro.start.y) / 2 - RES_Y / 6 && x < (RES_X + data.intro.start.x) / 2 && y < (RES_Y + data.intro.start.y) / 2 - RES_Y / 6)
                data.mouse.on_clk[0] = 1;
            if (x >= (RES_X - data.intro.sett.x) / 2 && y >= (RES_Y - data.intro.sett.y) / 2 - RES_Y / 12 && x < (RES_X + data.intro.sett.x) / 2 && y < (RES_Y + data.intro.sett.y) / 2 - RES_Y / 12)
                data.mouse.on_clk[1] = 1;
            if (x >= (RES_X - data.intro.exit.x) / 2 && y >= (RES_Y - data.intro.exit.y) / 2 && x < (RES_X + data.intro.exit.x) / 2 && y < (RES_Y + data.intro.exit.y) / 2)
                data.mouse.on_clk[2] = 1;
        }
        if (data.mode == S_CONTROL)
        {
            if (x >= RES_X / 2 - 225 && y >= RES_Y - 100 && x < RES_X / 2 - 75 && y < RES_Y - 40)
                data.mouse.on_clk[5] = 1;
            if (x >= RES_X / 2 + 75 && y >= RES_Y - 100 && x < RES_X / 2 + 225 && y < RES_Y - 40)
                data.mouse.on_clk[6] = 1;
        }
    }
}


void    mouse_press_control(int key, int x, int y)
{
    int i;
    int inc_y;
    int pos;

    pos = -1;
    i = -1;
        while (++i < 12)
            if (data.intro.on_clk[i + 4])
                pos = i;
    if (key == LEFT_CLICK && pos == -1)
    {
        i = 5;
        inc_y = 280;
        pos = 3 * (x > 390 && x < 436 && y > 120 && y < 160)
            + 4 * (x > 564 && x < 610 && y > 120 && y < 160);
        while (i < 16)
        {
            pos += i++ * (x - 100 > 0 && x - 100 < 500 && y - inc_y > -25 && y - inc_y < 65);
            if (i < 16)
                pos += i++ * (x - 800 > 0 && x - 800 < 500 && y - inc_y > -25 && y - inc_y < 65);
            inc_y += 120;
        }
        if (pos && !data.intro.on_clk[pos])
        {
            if (pos == 3 || pos == 4)
                data.intro.g_k[0] = !data.intro.g_k[0];
            else    
                data.intro.on_clk[pos] = 3;
            data.sound.click = 1;
        }
        i = 0;
        while (++i < 15)
            data.intro.on_clk[(pos + i) % 16] = 0;
    }
    else if (key == LEFT_CLICK && key_not_in_use(M_LEFT_CLICK))
        data.intro.on_clk[pos + 4] = 0,
        data.intro.g_k[pos] = M_LEFT_CLICK;
    else if (key == RIGHT_CLICK && key_not_in_use(M_RIGHT_CLICK))
        data.intro.on_clk[pos + 4] = 0,
        data.intro.g_k[pos] = M_RIGHT_CLICK;
    else
        data.intro.on_clk[pos + 4] = 0;
    if (key == LEFT_CLICK && x >= 1100 - 25 && y >= 75 && x <= 1300 && y <= 115)
    {
        data.intro.volume = x - 1100 + 12;
        if (data.intro.volume > 200)
            data.intro.volume = 200;
        if (data.intro.volume < 0)
            data.intro.volume = 0;
        paint_color(&data.intro.vol[1], 0xff3333, 25, 40);
        paint_color(&data.intro.vol[0], 0xB2BEB5, 200, 10);
        paint_color(&data.intro.vol[0], 0xff0000, data.intro.volume, 10);
        data.intro.vol_click = 1;
    }
    if (key == LEFT_CLICK && x >= 1025 && y >= 70 && x <= 1075 && y <= 120)
    {
        data.sound.click = 1;
        data.intro.vol_click = 1;
        data.intro.volume = !data.intro.volume * 100;
        paint_color(&data.intro.vol[0], 0xB2BEB5, 200, 10);
        paint_color(&data.intro.vol[0], 0xff0000, data.intro.volume, 10);
    }
    
    if (key == LEFT_CLICK && x >= 1100 - 25 && y >= 170 && x <= 1300 && y <= 210)
    {
        data.intro.light = x - 1100 + 12;
        if (data.intro.light > 200)
            data.intro.light = 200;
        if (data.intro.light < 0)
            data.intro.light = 0;
        paint_color(&data.intro.lgt[1], 0xff3333, 25, 40);
        paint_color(&data.intro.lgt[0], 0xB2BEB5, 200, 10);
        paint_color(&data.intro.lgt[0], 0xff0000, data.intro.light, 10);
        data.intro.lgt_click = 1;
    }
    if (key == LEFT_CLICK && x >= 1025 && y >= 165 && x <= 1075 && y <= 215)
    {
        data.sound.click = 1;
        data.intro.lgt_click = 1;
        data.intro.light = !data.intro.light * 200;
        paint_color(&data.intro.lgt[0], 0xB2BEB5, 200, 10);
        paint_color(&data.intro.lgt[0], 0xff0000, data.intro.light, 10);
    }
    mouse_press_setting(key, x, y);
}


void    mouse_press_game(int key)
{
    if (key == SCROLL_UP)
        data.objects.w++;    
    if (key == SCROLL_DOWN)
        data.objects.w--;
    if (data.objects.w < 0)
        data.objects.w = 6;
    if (data.objects.w > 6)
        data.objects.w = 0;
    if (key == SCROLL_UP)
        data.keys[1000 - SCROLL_UP - 1] = 1;
    if (key == SCROLL_DOWN)
        data.keys[1000 - SCROLL_DOWN - 1] = 1;
}

int mouse_press(int key, int x, int y, void *w)
{
    w = NULL;
    if (data.mode == INTRO)
        mouse_press_intro(key);
    if (data.mode == SETTING)
        mouse_press_setting(key, x, y);
    if (data.mode == S_CONTROL)
        mouse_press_control(key, x, y);
    if (data.mode == GAME)
        mouse_press_game(key);
    return (0);
}