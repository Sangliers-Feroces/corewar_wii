#version 430 core

layout (location = 0) in vec2 uv;
layout (binding = 0) uniform sampler2D tex;

out vec4 color;

uniform vec2 tex_pos;
uniform vec2 tex_size;

void main()
{
    color = texture(tex, tex_pos + vec2(uv.x, -uv.y) * tex_size);
}