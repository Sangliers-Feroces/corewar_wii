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

vec3 get_sky_color(vec3 v)
{
    vec3 hor = vec3(80, 120, 180) / 255;
    vec3 up = vec3(0, 60, 256) / 255;
    float up_ratio = dot(v, vec3(0.0, -1.0, 0.0));

    up_ratio = 1.0 - up_ratio;
    up_ratio *= up_ratio;
    up_ratio *= up_ratio;
    up_ratio = 1.0 - up_ratio;
    return hor * (1.0 - up_ratio) + vec3(1.0) * up;
}

void main(void)
{
	vec3 blue = vec3(94.0, 155.0, 255.0) / 255.0;
    vec3 v = normalize(p_cam - pos);

	color = vec4(get_sky_color(v) + max(0, pow(dot(-l_dir, v), 128.0)) * 2.0, 1.0);
    dist = vec4(0.0);
}
