#version 430 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv_albedo;

layout (binding = 0) uniform sampler2D tex_albedo;

layout (location = 0) out vec4 color;
layout (location = 1) out vec4 dist;

uniform float aperture;
uniform vec3 l_dir;
uniform vec3 p_cam;

float shlick(float cosnv)
{
    float n1 = 1.333;
    float n2 = 1.0;
    float r0 = ((n1 - n2) / (n1 + n2));
    float r0_sq = r0 * r0;

    return r0 + (1.0 - r0_sq) * pow(1 - cosnv, 5.0);
}

void main(void)
{
    vec3 n = normalize(normal);
    vec3 v = normalize(p_cam - pos);
    vec3 r = 2 * dot(n, l_dir) * n - l_dir;
	vec3 blue = vec3(94.0, 155.0, 255.0) / 255.0;
	vec3 light = blue;

    float fresnel = shlick(dot(n, v));
	color = vec4(vec3(light * texture(tex_albedo, uv_albedo).xyz), 0.05) + vec4(vec3(fresnel), fresnel / 2.0) + max(0, pow(dot(r, v), 128.0)) * 2.0;
    dist = vec4(vec3(p_cam - pos), 1.0);
}
