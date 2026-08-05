// =============================================================================
// HostBase_DefaultCtor_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Shared first-stage default constructor for a client host / view base
//           (≥0x79 written; peers allocate 0x80). Installs vtbl PTR_FUN_00a9f534,
//           zeros early fields, inits subobject at +0x10 via FUN_0076c500(1000)
//           + FUN_0076c4d0, writes dual 1000 defaults, copies float4 ones from
//           DAT_00afdf40, stores g_flHardKillInterpolate (0.005f), sets flag+0x78=1.
//           Most-derived ctors typically overwrite vtbl after return.
//
// Address:  0x007560d0  (autoassault.exe, image base 0x400000)
// Body:     0x007560d0–0x0075617f exclusive (175 B / 0xAF)
// Stable:   aa_007560d0
// System:   client / shared host base
// Ghidra:   FUN_007560d0
//
// ABI:      __thiscall; ECX=self*; returns self; plain RET (after ADD ESP,0x10 SEH)
//
// Exactness: Field order mirrors full body hex (raw W32-O append).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W32-O seal).
// Reject: Named_CalleeOf_Named_VOG_DEBUG_STOP_007560d0 scaffold alias.
// =============================================================================

#include <stdint.h>

extern void *PTR_FUN_00a9f534;           /* vtbl @ 0x00a9f534 */
extern float DAT_00afdf40;              /* 1.0f */
extern float DAT_00afdf44;
extern float DAT_00afdf48;
extern float DAT_00afdf4c;
extern float g_flHardKillInterpolate;   /* 0x00AAA6A4 = 0.005f */

/* ECX = subobject at host+0x10 */
extern void FUN_0076c500(int arg /* stack; retail 1000 */);
extern void FUN_0076c4d0(void);

void *HostBase_DefaultCtor_Inferred(void *self /*ECX*/)
{
  uint8_t *p = (uint8_t *)self;

  *(void **)(p + 0x00) = &PTR_FUN_00a9f534;
  *(uint32_t *)(p + 0x04) = 0;
  *(uint32_t *)(p + 0x08) = 0;

  /* LEA EDI,[ESI+0x10]; PUSH 1000; MOV ECX,EDI; CALL FUN_0076c500 */
  FUN_0076c500(1000);

  *(uint32_t *)(p + 0x40) = 1000;
  *(uint32_t *)(p + 0x44) = 1000;

  /* MOV ECX,EDI; CALL FUN_0076c4d0 */
  FUN_0076c4d0();

  *(uint8_t *)(p + 0x48) = 0;
  *(uint32_t *)(p + 0x50) = 0;
  *(uint32_t *)(p + 0x54) = 0;
  *(uint32_t *)(p + 0x58) = 0;
  *(uint32_t *)(p + 0x5C) = 0; /* xorps zero slot; part of 16B clear */

  *(float *)(p + 0x60) = DAT_00afdf40;
  *(float *)(p + 0x64) = DAT_00afdf44;
  *(float *)(p + 0x68) = DAT_00afdf48;
  *(float *)(p + 0x6C) = DAT_00afdf4c;

  *(uint32_t *)(p + 0x70) = 0;
  *(float *)(p + 0x74) = g_flHardKillInterpolate;
  *(uint8_t *)(p + 0x78) = 1;

  return self;
}
