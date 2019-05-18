#version 430 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv_albedo;
layout(location = 3) in vec2 uv_lightmap;

layout(location = 0) out vec3 normal_out;
layout(location = 1) out vec2 uv_albedo_out;
layout(location = 2) out vec2 uv_lightmap_out;

uniform mat4 vp;

void main(void)
{
    gl_Position = vp * vec4(pos, 1.0);

    normal_out = normal;
    uv_albedo_out = uv_albedo;
    uv_lightmap_out = uv_lightmap;
}
