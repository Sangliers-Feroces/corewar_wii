/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** vulkan ftw
*/

#pragma once

#include "gl_enums.h"

void load_gl_fun(void);

#ifndef GL_LOADER_IMPLEMENTATION

/*extern glenum (*p_glgeterror)(void);
extern void (*p_glgenvertexarrays)(glsizei n, gluint *arrays);
extern void (*p_gldeletevertexarrays)(glsizei n, const gluint *arrays);
extern void (*p_glbindvertexarray)(gluint array);
extern void (*p_glgenbuffers)(glsizei n, gluint *buffers);
extern void (*p_gldeletebuffers)(glsizei n, const gluint *buffers);
extern void (*p_glbindbuffer)(glenum target, gluint buffer);
extern void (*p_glbufferdata)(glenum target, glsizeiptr size,
glvoid *data, glenum usage);
extern void (*p_glclearcolor)(glfloat red, glfloat green,
glfloat blue, glfloat alpha);
extern void (*p_glenable)(glenum cap);
extern void (*p_gldepthfunc)(glenum cap);
extern void (*p_glclear)(glbitfield mask);
extern void (*p_gluseprogram)(gluint program);
extern glint (*p_glgetuniformlocation)(gluint program, const glchar *name);
extern void (*p_gluniformmatrix4fv)(glint location, glsizei count,
glboolean transform, const glfloat *value);
extern void (*p_glcullface)(glenum mode);
extern void (*p_glfrontface)(glenum mode);
extern void (*p_glpolygonmode)(glenum face, glenum mode);
extern void (*p_glblendequationseparate)(glenum mode_rgb, glenum mode_alpha);
extern void (*p_glblendfuncseparate)(glenum src_rgb, glenum dst_rgb,
glenum src_alpha, glenum dst_alpha);

extern void (*p_glenablevertexattribarray)(gluint index);
extern void (*p_gldisablevertexattribarray)(gluint index);
extern void (*p_glvertexattribpointer)(gluint index, glint size, glenum type,
glboolean normalized, glsizei stride, const glvoid *pointer);
extern void (*p_gldrawarrays)(glenum mode, glint first, glsizei count);
extern void (*p_gluniform1f)(glint location, float value);
extern void (*p_gluniform2fv)(glint location, glsizei count,
const glfloat *value);
extern void (*p_gluniform3fv)(glint location, glsizei count,
const glfloat *value);
extern void (*p_glactivetexture)(glenum texture);
extern void (*p_glgeneratemipmap)(glenum target);
extern void (*p_gldisable)(glenum cap);
extern void (*p_gltexstorage2d)(glenum target, glsizei levels,
glenum internal_format, glsizei w, glsizei h);
extern void (*p_gltexsubimage2d)(glenum target, glint level,
glint offx, glint offy, glsizei w, glsizei h, glenum format,
glenum type, const glvoid *pixels);

extern gluint (*p_glcreateshader)(glenum shader_type);
extern void (*p_glshadersource)(gluint shader, glsizei count,
const glchar **string, const glint *length);
extern void (*p_glcompileshader)(gluint shader);
extern void (*p_glgetshaderiv)(gluint shader, glenum pname, glint *params);
extern void (*p_glgetshaderinfolog)(gluint shader, glsizei max_length,
glsizei *length, glchar *info_log);
extern void (*p_glgetprograminfolog)(gluint shader, glsizei max_length,
glsizei *length, glchar *info_log);
extern gluint (*p_glcreateprogram)(void);
extern void (*p_glattachshader)(gluint program, gluint shader);
extern void (*p_gllinkprogram)(gluint program);
extern void (*p_glgetprogramiv)(gluint program, glenum pname, glint *params);
extern void (*p_gldetachshader)(gluint program, gluint shader);
extern void (*p_gldeleteshader)(gluint shader);
extern void (*p_gldeleteprogram)(gluint program);
extern void (*p_glfinish)(void);

extern void (*p_glgentextures)(glsizei n, gluint *textures);
extern void (*p_gldeletetextures)(glsizei n, const gluint *textures);
extern void (*p_glbindtexture)(glenum target, gluint texture);
extern void (*p_gltexparameteri)(glenum target, glenum pname, glint param);
extern void (*p_glteximage2d)(glenum target, glint level, glint internalformat,
glsizei width, glsizei height, glint border, glenum format, glenum type,
glvoid *data);
extern void (*p_glbindimagetexture)(gluint unit, gluint texture, glint level,
glboolean layered, glint layer, glenum access, glenum format);
extern void (*p_gldispatchcompute)(gluint num_groups_x, gluint num_groups_y,
gluint num_groups_z);
extern void (*p_glmemorybarrier)(glbitfield barriers);
extern void (*p_glgetteximage)(glenum target, glint level, glenum format,
glenum type, glvoid *pixels);
extern void (*p_glenablevertexarrayattrib)(gluint vaobj, gluint index);

extern void (*p_glgetintegerv)(glenum pname, glint *params);
extern void (*p_glgetintegeri_v)(glenum pname, gluint index, glint *params);

extern void (*p_glgenframebuffers)(glsizei n, gluint *ids);
extern void (*p_glbindframebuffer)(glenum target, gluint framebuffer);
extern void (*p_glgenrenderbuffers)(glsizei n, gluint *renderbuffers);
extern void (*p_glbindrenderbuffer)(glenum target, gluint renderbuffer);
extern void (*p_glrenderbufferstorage)(glenum target, glenum internalformat,
glsizei width, glsizei height);
extern void (*p_glframebufferrenderbuffer)(glenum target, glenum attachment,
glenum renderbuffertarget, gluint renderbuffer);
extern void (*p_glframebuffertexture)(glenum target, glenum attachment,
gluint texture, glint level);
extern void (*p_gldrawbuffers)(glsizei n, const glenum *bufs);
extern void (*p_glviewport)(glint x, glint y, glsizei width, glsizei height);

#define glGetError p_glgeterror
#define glGenVertexArrays p_glgenvertexarrays
#define glDeleteVertexArrays p_gldeletevertexarrays
#define glBindVertexArray p_glbindvertexarray
#define glGenBuffers p_glgenbuffers
#define glDeleteBuffers p_gldeletebuffers
#define glBindBuffer p_glbindbuffer
#define glBufferData p_glbufferdata
#define glClearColor p_glclearcolor
#define glEnable p_glenable
#define glDepthFunc p_gldepthfunc
#define glClear p_glclear
#define glUseProgram p_gluseprogram
#define glGetUniformLocation p_glgetuniformlocation
#define glUniformMatrix4fv p_gluniformmatrix4fv
#define glActiveTexture p_glactivetexture
#define glCullFace p_glcullface
#define glFrontFace p_glfrontface
#define glPolygonMode p_glpolygonmode
#define glBlendEquationSeparate p_glblendequationseparate
#define glBlendFuncSeparate p_glblendfuncseparate

#define glEnableVertexAttribArray p_glenablevertexattribarray
#define glDisableVertexAttribArray p_gldisablevertexattribarray
#define glVertexAttribPointer p_glvertexattribpointer
#define glDrawArrays p_gldrawarrays
#define glUniform2fv p_gluniform2fv
#define glUniform1f p_gluniform1f
#define glUniform3fv p_gluniform3fv
#define glGenerateMipmap p_glgeneratemipmap
#define glDisable p_gldisable
#define glCreateShader p_glcreateshader
#define glShaderSource p_glshadersource
#define glCompileShader p_glcompileshader
#define glGetShaderiv p_glgetshaderiv
#define glGetShaderInfoLog p_glgetshaderinfolog
#define glGetProgramInfoLog p_glgetprograminfolog
#define glCreateProgram p_glcreateprogram
#define glAttachShader p_glattachshader
#define glLinkProgram p_gllinkprogram
#define glGetProgramiv p_glgetprogramiv
#define glDetachShader p_gldetachshader
#define glDeleteShader p_gldeleteshader
#define glDeleteProgram p_gldeleteprogram
#define glFinish p_glfinish

#define glGenTextures p_glgentextures
#define glDeleteTextures p_gldeletetextures
#define glBindTexture p_glbindtexture
#define glTexParameteri p_gltexparameteri
#define glTexImage2D p_glteximage2d
#define glBindImageTexture p_glbindimagetexture
#define glDispatchCompute p_gldispatchcompute
#define glMemoryBarrier p_glmemorybarrier
#define glGetTexImage p_glgetteximage
#define glTexStorage2D p_gltexstorage2d
#define glTexSubImage2D p_gltexsubimage2d
#define glEnableVertexArrayAttrib p_glenablevertexarrayattrib

#define glGetIntegerv p_glgetintegerv
#define glGetIntegeri_v p_glgetintegeri_v

#define glGenFramebuffers p_glgenframebuffers
#define glBindFramebuffer p_glbindframebuffer
#define glGenRenderbuffers p_glgenrenderbuffers
#define glBindRenderbuffer p_glbindrenderbuffer
#define glRenderbufferStorage p_glrenderbufferstorage
#define glFramebufferRenderbuffer p_glframebufferrenderbuffer
#define glFramebufferTexture p_glframebuffertexture
#define glDrawBuffers p_gldrawbuffers
#define glViewport p_glviewport*/

#endif
