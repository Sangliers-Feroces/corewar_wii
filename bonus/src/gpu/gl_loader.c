/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** vulkan ftw
*/

#include "gl_loader_implementation.h"

#include "headers.h"

#include "global_shenanigans.h"

const glenum (*p_glgeterror)(void);
const void (*p_glgenvertexarrays)(glsizei n, gluint *arrays);
const void (*p_gldeletevertexarrays)(glsizei n, const gluint *arrays);
const void (*p_glbindvertexarray)(gluint array);
const void (*p_glgenbuffers)(glsizei n, gluint *buffers);
const void (*p_gldeletebuffers)(glsizei n, const gluint *buffers);
const void (*p_glbindbuffer)(glenum target, gluint buffer);
const void (*p_glbufferdata)(glenum target, glsizeiptr size,
const glvoid *data, glenum usage);
const void (*p_glclearcolor)(glfloat red, glfloat green,
glfloat blue, glfloat alpha);
const void (*p_glenable)(glenum cap);
const void (*p_gldepthfunc)(glenum cap);
const void (*p_glclear)(glbitfield mask);
const void (*p_gluseprogram)(gluint program);
const glint (*p_glgetuniformlocation)(gluint program, const glchar *name);
const void (*p_gluniformmatrix4fv)(glint location, glsizei count,
glboolean transform, const glfloat *value);
const void (*p_glcullface)(glenum mode);
const void (*p_glfrontface)(glenum mode);
const void (*p_glpolygonmode)(glenum face, glenum mode);
const void (*p_glblendequationseparate)(glenum mode_rgb, glenum mode_alpha);
const void (*p_glblendfuncseparate)(glenum src_rgb, glenum dst_rgb,
glenum src_alpha, glenum dst_alpha);

const void (*p_glenablevertexattribarray)(gluint index);
const void (*p_gldisablevertexattribarray)(gluint index);
const void (*p_glvertexattribpointer)(gluint index, glint size, glenum type,
glboolean normalized, glsizei stride, const glvoid *pointer);
const void (*p_gldrawarrays)(glenum mode, glint first, glsizei count);
const void (*p_gluniform1f)(glint location, float value);
const void (*p_gluniform2fv)(glint location, glsizei count,
const glfloat *value);
const void (*p_gluniform3fv)(glint location, glsizei count,
const glfloat *value);
const void (*p_glactivetexture)(glenum texture);
const void (*p_glgeneratemipmap)(glenum target);
const void (*p_gldisable)(glenum cap);
const void (*p_gltexstorage2d)(glenum target, glsizei levels,
glenum internal_format, glsizei w, glsizei h);
const void (*p_gltexsubimage2d)(glenum target, glint level,
glint offx, glint offy, glsizei w, glsizei h, glenum format,
glenum type, const glvoid *pixels);

const gluint (*p_glcreateshader)(glenum shader_type);
const void (*p_glshadersource)(gluint shader, glsizei count,
const glchar **string, const glint *length);
const void (*p_glcompileshader)(gluint shader);
const void (*p_glgetshaderiv)(gluint shader, glenum pname, glint *params);
const void (*p_glgetshaderinfolog)(gluint shader, glsizei max_length,
glsizei *length, glchar *info_log);
const void (*p_glgetprograminfolog)(gluint shader, glsizei max_length,
glsizei *length, glchar *info_log);
const gluint (*p_glcreateprogram)(void);
const void (*p_glattachshader)(gluint program, gluint shader);
const void (*p_gllinkprogram)(gluint program);
const void (*p_glgetprogramiv)(gluint program, glenum pname, glint *params);
const void (*p_gldetachshader)(gluint program, gluint shader);
const void (*p_gldeleteshader)(gluint shader);
const void (*p_gldeleteprogram)(gluint program);
const void (*p_glfinish)(void);

const void (*p_glgentextures)(glsizei n, gluint *textures);
const void (*p_gldeletetextures)(glsizei n, const gluint *textures);
const void (*p_glbindtexture)(glenum target, gluint texture);
const void (*p_gltexparameteri)(glenum target, glenum pname, glint param);
const void (*p_glteximage2d)(glenum target, glint level, glint internalformat,
glsizei width, glsizei height, glint border, glenum format, glenum type,
const glvoid *data);
const void (*p_glbindimagetexture)(gluint unit, gluint texture, glint level,
glboolean layered, glint layer, glenum access, glenum format);
const void (*p_gldispatchcompute)(gluint num_groups_x, gluint num_groups_y,
gluint num_groups_z);
const void (*p_glmemorybarrier)(glbitfield barriers);
const void (*p_glgetteximage)(glenum target, glint level, glenum format,
glenum type, glvoid *pixels);
const void (*p_glenablevertexarrayattrib)(gluint vaobj, gluint index);

const void (*p_glgetintegerv)(glenum pname, glint *params);
const void (*p_glgetintegeri_v)(glenum pname, gluint index, glint *params);

const void (*p_glgenframebuffers)(glsizei n, gluint *ids);
const void (*p_glbindframebuffer)(glenum target, gluint framebuffer);
const void (*p_glgenrenderbuffers)(glsizei n, gluint *renderbuffers);
const void (*p_glbindrenderbuffer)(glenum target, gluint renderbuffer);
const void (*p_glrenderbufferstorage)(glenum target, glenum internalformat,
glsizei width, glsizei height);
const void (*p_glframebufferrenderbuffer)(glenum target, glenum attachment,
glenum renderbuffertarget, gluint renderbuffer);
const void (*p_glframebuffertexture)(glenum target, glenum attachment,
gluint texture, glint level);
const void (*p_gldrawbuffers)(glsizei n, const glenum *bufs);
const void (*p_glviewport)(glint x, glint y, glsizei width, glsizei height);

void load_gl_fun(void)
{
}
