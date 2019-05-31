#version 430 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec2 uv_albedo;

layout (binding = 0) uniform sampler2D tex;
layout (binding = 1) uniform sampler2D text_albedo;

out vec4 color;

uniform float aperture;

void main()
{
	vec3 blue = (vec3(94.0, 155.0, 255.0) / 255.0) * 0.001 * aperture;
	vec3 light = texture(tex, uv).xyz / aperture + blue;

	color = vec4(light * texture(text_albedo, uv_albedo).xyz, 1.0);
}
