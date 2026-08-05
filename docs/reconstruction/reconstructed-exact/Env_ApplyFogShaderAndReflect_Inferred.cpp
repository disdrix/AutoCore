// =============================================================================
// Env_ApplyFogShaderAndReflect_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Virtual method (vtbl[1] of PTR_FUN_009d95a0): if context is ready
//           and work flag set, push fog shader constants (gFogEnable/Start/End/
//           Color) from this+0x164, pack fog color, then refresh environment
//           reflection / light vectors on *(this+0x158)+8.
//
// Address:  0x005b36f0  (autoassault.exe, image base 0x400000)
// Body:     0x005b36f0–0x005b3992 (674 B / 0x2A2)
// Stable:   aa_005b36f0
// System:   client environment / fog shader
// Ghidra:   FUN_005b36f0
//
// ABI:      thiscall ECX=this; stack: uint32_t arg0; ret 4
//           returns 0 on gate pass, -1 if this+0x15c / nested e4f8 missing
//
// Vtbl:     PTR_FUN_009d95a0 + 4  ==  this function
// Ctor:     FUN_005b35a0 installs vtbl; stores parent at +0x15c
//
// Exactness: CF + strings + vtbl slot + ret4 sealed via decompile + read_memory
//            + byte search. Nested helper product English open.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W29-I seal).
// =============================================================================

#include <stdint.h>

extern uint32_t FUN_0074f1b0(const char *name);
extern void FUN_00442d50(const char *name, void *float4_src);
extern void Color_PackFloat4_Scale255_Inferred(uint8_t *dest /*ecx*/, const float *src);
extern void FUN_0075bf40(void *a0);
extern void FUN_0040d340(void);
extern void FUN_00442b90(uint32_t a0);
extern void FUN_0074dfa0(void);
extern void FUN_00416160(uint32_t a0);
extern long double FUN_004cd220(uint32_t a, uint32_t b);
extern void FUN_005b39d0(void *vec4);
extern void FUN_0099b8a0(void *p);

/* Image globals (names structural) */
extern uint8_t *DAT_00d1f048;
extern int DAT_00d1f05c;
extern uint8_t g_flag_af3ed5; /* image 0x00af3ed5 */
extern uint8_t g_flag_af3ed6; /* image 0x00af3ed6 */

/*
 * Port surface — control flow mirrors raw. Nested shader-bind vcalls and
 * material layouts are represented as opaque calls matching the image.
 */
uint32_t __thiscall Env_ApplyFogShaderAndReflect_Inferred(void *self, uint32_t arg0)
{
  uint8_t *base = (uint8_t *)self;
  int ctx = *(int *)(base + 0x15c);

  if (ctx == 0 || *(int *)(ctx + 0xe4f8) == 0)
    return 0xFFFFFFFFu;

  if (*(char *)(base + 0x80) != 0) {
    uint8_t flag78 = *(uint8_t *)(base + 0x78);
    DAT_00d1f048[0x0f] = flag78;
    DAT_00d1f048[0x2d] = flag78;

    int shader = *(int *)(base + 0x164);
    int gfx = DAT_00d1f05c;

    /* gFogEnable / gFogStart / gFogEnd via name lookup + vfunc(+0x50) binds */
    (void)FUN_0074f1b0("gFogEnable");
    (void)gfx;
    (void)(shader + 0x70);
    (void)FUN_0074f1b0("gFogStart");
    (void)(shader + 0x10c);
    (void)FUN_0074f1b0("gFogEnd");
    (void)(shader + 0x110);

    FUN_00442d50("gFogColor", (void *)(shader + 0x60));
    /* image: ECX = dest for pack; surface of FUN_00973820 drops ECX */
    Color_PackFloat4_Scale255_Inferred((uint8_t *)(shader + 0x60),
                                       (const float *)(shader + 0x60));

    FUN_0075bf40(0);
    FUN_0040d340();
    FUN_00442b90(*(uint32_t *)(base + 4));
    if (*(int *)(base + 4) != 0)
      FUN_0074dfa0();

    FUN_00416160(*(uint32_t *)(*(int *)(*(int *)(ctx + 0xe894) + 0xc0) + 8));

    int reflect = *(int *)(*(int *)(base + 0x158) + 8);
    *(uint32_t *)(reflect + 0xbc) = 0xFFFFFFFFu;
    *(int *)(reflect + 0xb4) = *(int *)(reflect + 0xb4) + 1;

    uint32_t v90 = *(uint32_t *)(reflect + 0x90);
    float v94 = *(float *)(reflect + 0x94);
    uint32_t v98 = *(uint32_t *)(reflect + 0x98);
    long double adj = FUN_004cd220(v90, v98);
    if (g_flag_af3ed6 != 0)
      v94 = (float)adj - (v94 - (float)adj);

    /* snapshot vec at +0x80..+0x8c; optional transform when flag af3ed5 */
    uint32_t snap[4];
    snap[0] = *(uint32_t *)(reflect + 0x80);
    snap[1] = *(uint32_t *)(reflect + 0x84);
    snap[2] = *(uint32_t *)(reflect + 0x88);
    snap[3] = *(uint32_t *)(reflect + 0x8c);
    if (g_flag_af3ed5 != 0) {
      FUN_005b39d0(snap);
      FUN_0099b8a0(0);
    }

    reflect = *(int *)(*(int *)(base + 0x158) + 8);
    *(uint32_t *)(reflect + 0xbc) = 0xFFFFFFFFu;
    *(int *)(reflect + 0xb4) = *(int *)(reflect + 0xb4) + 1;
    *(uint32_t *)(reflect + 0x90) = v90;
    *(float *)(reflect + 0x94) = v94;
    *(uint32_t *)(reflect + 0x98) = v98;

    reflect = *(int *)(*(int *)(base + 0x158) + 8);
    *(uint32_t *)(reflect + 0xbc) = 0xFFFFFFFFu;
    *(int *)(reflect + 0xb4) = *(int *)(reflect + 0xb4) + 1;
    *(uint32_t *)(reflect + 0x80) = snap[0];
    *(uint32_t *)(reflect + 0x84) = snap[1];
    *(uint32_t *)(reflect + 0x88) = snap[2];
    *(uint32_t *)(reflect + 0x8c) = snap[3];

    int node = *(int *)(ctx + 0xe894);
    int *vobj = *(int **)(node + 0x94);
    if (vobj != 0 && *(char *)(node + 0x87) != 0)
      ((void (*)(int *, uint32_t))(*(void **)(*vobj + 0x3c)))(vobj, arg0);

    (void)arg0;
  }

  return 0;
}
