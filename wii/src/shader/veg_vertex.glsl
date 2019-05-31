#version 430 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv_albedo;

layout(location = 0) out vec3 pos_out;
layout(location = 1) out vec3 normal_out;
layout(location = 2) out vec2 uv_albedo_out;

uniform mat4 mvp;
uniform mat4 world;
uniform mat4 rot;

uniform vec3 off;

void main(void)
{
    vec3 p_a = pos + off * normalize(pos.y);
    vec4 p = vec4(p_a, 1.0);
    vec4 n = vec4(normal, 1.0);
    gl_Position = mvp * p;

    pos_out = (world * p).xyz;
    normal_out = (rot * n).xyz;
    uv_albedo_out = uv_albedo;
}
