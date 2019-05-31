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

void main(void)
{
    vec3 blue = vec3(40, 90, 256) / 255;
	vec3 light;
    vec3 v = normalize(p_cam - pos);
    vec3 yellow = vec3(1.0, 1.0, 0.15);
    vec4 tex = texture(tex_albedo, uv_albedo);

    light = vec3(max(0.0, dot(normal, l_dir))) * yellow + blue * 0.2;
    float ff = pos.y < -42.0 ? (1.0 - min(1.0, (-pos.y - 42.0) / 40.0)) * 0.6 + 0.1 : 1.0;
    if (tex.w < 0.05)
        discard;
	color = vec4(light * tex.xyz * vec3(ff, ff, 1.0), tex.w);
    dist = vec4(vec3(p_cam - pos), 1.0);
}
