#ifndef RCN_POST_PROC_H
#define RCN_POST_PROC_H

#include <stdint.h>

struct OVSEIFGrain;
struct OVVCDec;

typedef void (*FGFunc)(int16_t** dstComp, int16_t** srcComp, struct OVSEIFGrain* fgrain, 
                          int pic_w, int pic_h, int poc, uint8_t isIdrPic, uint8_t enableDeblocking);

struct PostProcFunctions
{
    uint8_t pp_apply_flag;
    FGFunc pp_film_grain;
};

int pp_process_frame(const OVSEI* sei, OVDPB *dpb, OVFrame **frame_p);


//TODO: change function names.
// void fg_data_base_generation(int8_t****  dataBase, uint8_t enableDeblocking)
void fg_data_base_generation(uint8_t enableDeblocking);

void fg_grain_apply_pic(int16_t** dstComp, int16_t** srcComp, struct OVSEIFGrain* fgrain, 
                          int pic_w, int pic_h, int poc, uint8_t isIdrPic, uint8_t enableDeblocking);


#endif