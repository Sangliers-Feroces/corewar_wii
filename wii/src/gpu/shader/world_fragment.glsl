#version 430 core

layout (location = 0) in vec3 normal;
layout (location = 1) in vec2 uv_albedo;
layout (location = 2) in vec2 uv_lightmap;

layout (binding = 0) uniform sampler2D tex_lightmap;
layout (binding = 1) uniform sampler2D tex_albedo;

out vec4 color;

uniform float aperture;

void main(void)
{
	vec3 blue = (vec3(94.0, 155.0, 255.0) / 255.0) * 0.001 * aperture;
	vec3 light = texture(tex_lightmap, uv_lightmap).xyz / aperture + blue;

    light = vec3(max(0.0, dot(normal, normalize(vec3(1.0) - vec3(0.0, 0.0, -0.5)))));
	color = vec4(light * texture(tex_albedo, uv_albedo).xyz, 1.0);
}
