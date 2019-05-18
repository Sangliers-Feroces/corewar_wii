/*
** EPITECH PROJECT, 2018
** __xd__world
** File description:
** serialization for the GPU
*/

#pragma once

void gpu_serial_write(gpu_serial_t *serial, int32_t data);
void gpu_serial_write_float(gpu_serial_t *serial, double data);
void gpu_serial_write_vec2(gpu_serial_t *serial, vec2 data);
void gpu_serial_write_dvec3(gpu_serial_t *serial, dvec3 data);
