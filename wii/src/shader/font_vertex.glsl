#version 430 core

layout (location = 0) in vec2 vertex_array;

layout (location = 0) out vec2 uv_out;

uniform vec2 pos;
uniform vec2 size;
uniform float depth;

void main()
{
    vec2 pos2 = pos;

    gl_Position = vec4(pos2 + (vertex_array * size), depth, 1);
    uv_out = vertex_array * 0.99 + vec2(-0.005, 0.005);
}
