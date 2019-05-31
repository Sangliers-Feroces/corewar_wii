#version 430 core

layout (location = 0) in vec2 pos;

layout (location = 0) out vec2 uv_out;

void main()
{
    vec2 pos2 = pos;

    gl_Position = vec4(vec2(-1.0) + (pos * 2.0), 0.0, 1.0);
    uv_out = pos;
}
