#ifndef RCN_STRUCTURES_H
#define RCN_STRUCTURES_H

#include <stdint.h>
#include <stddef.h>


enum DCTType
{
    DST_VII = 0,
    DCT_VIII = 1,
    DCT_II = 2,
    NB_TR_TYPES = 3
};

#define NB_TR_SIZES 7

typedef void (*MCUniDirFunc)(uint16_t *_dst, ptrdiff_t _dststride,
                             const uint16_t *_src, ptrdiff_t _srcstride,
                             int height, intptr_t mx, intptr_t my, int width);

typedef void (*MCBiDir0Func)(int16_t *_dst,
                             const uint16_t *_src, ptrdiff_t _srcstride,
                             int height, intptr_t mx, intptr_t my, int width);

typedef void (*MCBiDir1Func)(uint16_t *_dst, ptrdiff_t _dststride,
                             const uint16_t *_src0, ptrdiff_t _srcstride,
                             const int16_t *_src1,
                             int height, intptr_t mx, intptr_t my, int width);

typedef void (*TrFunc)(const int16_t *src, int16_t *dst,
                 ptrdiff_t src_stride,
                 int num_lines, int num_columns, int shift);

typedef void (*DCFunc)(const uint16_t* const src_above,
                 const uint16_t* const src_left, uint16_t* const dst,
                 ptrdiff_t dst_stride, int log2_pb_w, int log2_pb_h);

typedef void (*PlanarFunc)(const uint16_t* const src_above,
                     const uint16_t* const src_left, uint16_t* const dst,
                     ptrdiff_t dst_stride, int log2_pb_w, int log2_pb_h);

/**
 * The Context put together all functions used by strategies.
 */

struct MCFunctions{

    MCUniDirFunc unidir[4][8];

    MCBiDir0Func bidir0[4][8];
    MCBiDir1Func bidir1[4][8];
};

struct TRFunctions
{
   TrFunc func[NB_TR_TYPES][NB_TR_SIZES];
};

struct DCFunctions
{
  DCFunc func;
  DCFunc pdpc;
};

struct PlanarFunctions
{
  PlanarFunc func;
  PlanarFunc pdpc[2];
};


struct RCNFunctions
{
    /* Motion Compensation Luma */
    struct MCFunctions mc_l;

    /* Motion Compensation Chroma */
    struct MCFunctions mc_c;

    /* Transform Functions */
    struct TRFunctions tr;

    /* DC Functions */
    struct DCFunctions dc;

    /* DC Functions */
    struct PlanarFunctions planar;
};

#endif
