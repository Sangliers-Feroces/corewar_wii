#version 430 core

layout(location = 0) in vec2 pos;

layout(location = 0) out vec2 uv_out;

uniform vec2 p;
uniform vec2 s;

void main()
{
    gl_Position = vec4(p + pos * s, 0.0, 1.0);
    uv_out = pos;
}