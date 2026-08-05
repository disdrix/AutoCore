// =============================================================================
// FUN_0076f970  (scaffold alias — prefer Math_ComposeOptionalTRSMatrix_Inferred.cpp)
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f970
// Address:   0x0076f970  (autoassault.exe, image base 0x400000)
// Body:      0x0076f970–0x0076fc93
// System:    math / graphics transforms
// Twin file: Math_ComposeOptionalTRSMatrix_Inferred.cpp
// Generated: 2026-07-29 W18-P dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

// PURPOSE: Optional TRS matrix composer used by GfxNode dirty rebuild and skeleton paths.
// See named clean for machine ABI, compose order, and GfxNode field map.
//
// Decompiler shape (register fiction retained):
//   in_EAX / param_1 (ECX) = optional float3* translation pairs
//   param_2 = dest mat4*
//   param_3 = outer quat* (with inverse)
//   param_4 = scale float3*
//   param_5 = inner quat*
//   param_6 = base translation float3*
//
// GfxNode (0x00972e50): EAX=ECX=0x00D1A6C0 (zeros), dest=node,
//   param_3=&(0,0,0,1), param_4=node+0x9C, param_5=node+0x80, param_6=node+0x90
//   → dest = S * R * T

#include <stdint.h>

extern "C" void FUN_00412d80(float *a, float *b, float *c);
extern "C" void FUN_0076eb00(void *outMat, void *quat);
extern "C" void *FUN_0076e6b0(void *outQuat, void *quat);

// Full expanded locals match raw decompile; implementation deferred to named clean
// for readability. Control-flow order of multiplies (authoritative):

extern "C" uint32_t *FUN_0076f970(
    float *param_1,      // ECX = tB
    uint32_t *param_2,   // dest
    int param_3,         // rOuter quat*
    uint32_t *param_4,   // scale*
    int param_5,         // rInner quat*
    uint32_t *param_6    // translation*
    // in_EAX = tA
)
{
    // Stages (null skips), each FUN_00412d80(dest, stage, dest):
    // 1 base = T(param_6) or I  → copy to dest
    // 2 T(+param_1)  3 R(param_5)  4 T(-param_1)
    // 5 T(+EAX)      6 R(param_3)  7 S(param_4)
    // 8 Rinv(param_3) 9 T(-EAX)
    (void)param_1;
    (void)param_3;
    (void)param_4;
    (void)param_5;
    (void)param_6;
    return param_2;
}
