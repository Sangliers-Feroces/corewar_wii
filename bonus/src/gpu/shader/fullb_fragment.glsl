#version 430 core

layout (location = 0) in vec2 uv;

layout (binding = 0) uniform sampler2D tex;

out vec4 color;

void main()
{
	color = texture(tex, uv);
	if (color.w == 0.0)
		discard;
}
