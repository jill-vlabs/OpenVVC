#ifndef OPENVVC_H
#define OPENVVC_H

#include <stdint.h>
#include <stddef.h>

typedef struct OVVCDec OVVCDec;

typedef struct SubDec OVSubDec;

/**
 * Submit raw Annex B data corresponding to a Picture Unit
 * the decoder will then extract RBSP data of each NAL Unit
 * contained in the PU, sequentially read Non VCL data and
 * update the decoder status and attach the VCL data to a decoding
 * thread before returning
 * returns a negative number of failure, 0 otherwise
 */
int ovdec_submit_picture_unit(OVVCDec *vvcdec, uint8_t *buff, size_t buff_size);

int ovdec_init(OVVCDec **ovvcdec);

int ovdec_close(OVVCDec *ovvcdec);

#endif
