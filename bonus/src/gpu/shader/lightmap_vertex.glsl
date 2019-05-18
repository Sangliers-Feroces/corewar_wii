#version 430 core

layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 uv;
layout(location = 2) in vec2 uv_albedo;

layout(location = 0) out vec3 pos_out;
layout(location = 1) out vec2 uv_out;
layout(location = 2) out vec2 uv_albedo_out;

uniform mat4 vp;

void main() {
    vec3 pos = vertexPosition_modelspace;

    //gl_Position =
    //vec4(pos.xy / pos.z, pos.z / 100, 1.0);
    gl_Position = vp * vec4(pos, 1.0);
    pos_out = pos.xyz;
    uv_out = uv;
    uv_albedo_out = uv_albedo;
    /*gl_Position.xyz = vertexPosition_modelspace;
    gl_Position.w = 1.0;*/
}
