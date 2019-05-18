/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** nvidia fanboyisme
*/

#include "headers.h"

void texture2f_refresh_gpu(texture2f *texture)
{
    (void)texture;
    /*glBindTexture(GL_TEXTURE_2D, texture->id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, texture->w, texture->h,
    0, GL_RGBA, GL_FLOAT, texture->pixel);*/
}

void texture2f_refresh_cpu(texture2f *texture)
{
    (void)texture;
    /*glBindTexture(GL_TEXTURE_2D, texture->id);
    glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_FLOAT, texture->pixel);*/
}
