#version 430 core

layout (location = 0) in vec2 uv;

layout (binding = 0) uniform sampler2D tex;
layout (binding = 1) uniform sampler2D dist;

out vec4 color;

uniform vec3 p_cam;
uniform float t;

vec2 off = vec2(0.0);
vec2 size = vec2(1.0);

float fog_ratio(vec3 d)
{
    return 1.0 - 1.0 / exp(length(d) * 0.0002);
}

float get_im(float h)
{
    return clamp(-(h + 42.01) / 100.0, 0.0, 1.0);
}

vec3 get_hdr_color(vec3 d)
{
    vec3 f = vec3(1.0);
    float im_v = get_im((p_cam - d).y);

    if ((im_v > 0.0) || (p_cam.y < -42.0)) {
        float im = get_im(p_cam.y);
        off = vec2(sin(gl_FragCoord.y / 10.0 + t * 10.0 * (0.15 + 0.85 * im_v)) / 300.0, 0.0);
        size = vec2(0.8);
        off -= (size - 1.0) / 2.0;
        f = vec3(0.2, 0.5, 0.8) * (1.0 - im);
    }
    return texture(tex, (uv * size) + off).xyz * f;
}

void main(void)
{
    vec3 d = texture(dist, uv).xyz;
    float gamma = 1.0;
    float exposure = 1.0;
    vec3 hdr = get_hdr_color(d);
    vec3 blue = vec3(40, 90, 256) / 255;
    d =texture(dist, (uv * size) + off).xyz;
    float fog = fog_ratio(d);

    hdr = hdr * (1.0 - fog) + blue * fog;
    vec3 mapped = vec3(1.0) - exp(-hdr * exposure);
    color = vec4(pow(mapped, vec3(1.0 / gamma)), 1.0);
}
