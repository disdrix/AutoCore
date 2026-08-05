// =============================================================================
// HostPtrTable12_Bootstrap_EDI_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Bootstrap twelve subsystem host objects into a caller-supplied
//           pointer table (EDI register formal). Each slot: operator_new +
//           construct/vtbl + post-init. Returns 0.
//
// Address:  0x0073c810  (autoassault.exe, image base 0x400000)
// Body:     0x0073c810–0x0073cb6d (862 B / 0x35E)
// Stable:   aa_0073c810
// System:   host pointer-table bootstrap
// Ghidra:   FUN_0073c810
//
// ABI:      EDI = void** host_table (12 slots @ +0x00..+0x2C); no stack args;
//           return 0; plain RET.
// Callers:  none recovered in Ghidra (gap).
//
// Exactness: CF mirrors raw + read_memory; names structural _Inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W35-E seal).
// =============================================================================

/* HostPtrTable12_Bootstrap_EDI_Inferred

   Register formal:
     EDI — pointer to array of 12 void* host slots (span >= 0x30).

   Side effects:
     - allocates and constructs 12 subsystem hosts
     - stores pointers into table[0..11]
     - runs per-slot init callees (unowned product bodies)

   Returns: 0
*/

#include <stdint.h>

extern void *operator_new(unsigned size);
extern uint32_t *FUN_00748960(uint32_t *self /* ECX */);
extern uint32_t *FUN_00457720(uint32_t *self /* stack */);
extern uint32_t FUN_00457ac0(void *self /* stack */); /* NestedHash0x10 */
extern uint32_t FUN_00457b30(void *self /* stack */); /* NestedHashBag0x18 */
extern uint32_t FUN_00764030(void); /* large host ctor; ECX=mem */
extern void FUN_0099e6c0(void);
extern void FUN_0099e4a0(void);
extern void FUN_0099e2c0(void);
extern void FUN_0099e0a0(void);
extern void FUN_0099d060(void *obj);
extern void FUN_00731130(void *obj);
extern void FUN_007300c0(void *obj);
extern void FUN_0099eb60(void *obj);
extern void FUN_0099f450(void *obj, uint32_t f32_bits);
extern void FUN_0098fd80(void *obj);
extern void FUN_0098df00(void);
extern void FUN_007647c0(void *slot8);

/* dual-vtbl pair labels from image (product demangle open) */
extern void *PTR_FUN_00aa37b4, *PTR_LAB_00aa37a8;
extern void *PTR_FUN_00aa3714, *PTR_LAB_00aa3708;
extern void *PTR_FUN_00aa3674, *PTR_LAB_00aa3668;
extern void *PTR_FUN_00aa35d4, *PTR_LAB_00aa35c8;
extern void *PTR_FUN_00aa3534, *PTR_LAB_00aa3528;
extern void *PTR_FUN_00aa3494, *PTR_LAB_00aa3484;
extern void *PTR_FUN_00aa33fc, *PTR_LAB_00aa33ec;
extern void *PTR_FUN_00aa33c8, *PTR_FUN_00a9db18, *PTR_FUN_00a9da80;

static void *new_c4_dual_vtbl(void *vt0, void *vt1)
{
  uint32_t *p = (uint32_t *)operator_new(0xC4);
  if (p == 0) return 0;
  FUN_00748960(p);
  p[0] = (uint32_t)vt0;
  p[1] = (uint32_t)vt1;
  return p;
}

/* Note: MSVC thiscall uses ECX; EDI is the table formal (custom / regcall-ish). */
uint32_t HostPtrTable12_Bootstrap_EDI_Inferred(void **table /* EDI */)
{
  void *p;

  /* slot 0 */
  p = new_c4_dual_vtbl(&PTR_FUN_00aa37b4, &PTR_LAB_00aa37a8);
  table[0] = p;
  FUN_0099e6c0();

  /* slot 1 */
  p = new_c4_dual_vtbl(&PTR_FUN_00aa3714, &PTR_LAB_00aa3708);
  table[1] = p;
  FUN_0099e4a0();

  /* slot 2 */
  p = new_c4_dual_vtbl(&PTR_FUN_00aa3674, &PTR_LAB_00aa3668);
  table[2] = p;
  FUN_0099e2c0();

  /* slot 3 */
  p = new_c4_dual_vtbl(&PTR_FUN_00aa35d4, &PTR_LAB_00aa35c8);
  table[3] = p;
  FUN_0099e0a0();

  /* slot 4 */
  p = new_c4_dual_vtbl(&PTR_FUN_00aa3534, &PTR_LAB_00aa3528);
  table[4] = p;
  FUN_0099d060(p);

  /* slot 5 — 0x44 host */
  p = operator_new(0x44);
  p = (p == 0) ? 0 : (void *)FUN_00457720((uint32_t *)p);
  table[5] = p;
  FUN_00731130(p);

  /* slot 6 — 0x34 multi-vtbl inline */
  {
    uint32_t *q = (uint32_t *)operator_new(0x34);
    if (q == 0) {
      p = 0;
    } else {
      q[0] = (uint32_t)&PTR_FUN_00aa33c8;
      q[2] = 0;
      q[1] = (uint32_t)&PTR_FUN_00a9db18;
      q[4] = 0;
      q[3] = (uint32_t)&PTR_FUN_00a9db18;
      q[6] = 0;
      q[5] = (uint32_t)&PTR_FUN_00a9da80;
      q[9] = 0;
      *((uint8_t *)(q + 10)) = 0;
      *((uint8_t *)q + 0x29) = 0;
      *((uint8_t *)q + 0x2a) = 0;
      p = q;
    }
  }
  table[6] = p;
  FUN_007300c0(p);

  /* slot 7 */
  p = new_c4_dual_vtbl(&PTR_FUN_00aa3494, &PTR_LAB_00aa3484);
  table[7] = p;
  FUN_0099eb60(p);

  /* slot 8 — float 10.0f post-init */
  p = new_c4_dual_vtbl(&PTR_FUN_00aa33fc, &PTR_LAB_00aa33ec);
  table[8] = p;
  FUN_0099f450(p, 0x41200000u);

  /* slot 9 — NestedHash0x10 + host tail */
  p = operator_new(0x30);
  if (p != 0) {
    FUN_00457ac0(p);
    *(uint32_t *)((uint8_t *)p + 0x28) = 0;
    *((uint8_t *)p + 0x2c) = 0;
    *((uint8_t *)p + 0x2d) = 0;
    *((uint8_t *)p + 0x2e) = 0;
  }
  table[9] = p;
  FUN_0098fd80(p);

  /* slot 10 — NestedHashBag0x18 + extended tail */
  p = operator_new(0x40);
  if (p != 0) {
    FUN_00457b30(p);
    *(uint32_t *)((uint8_t *)p + 0x28) = 0;
    *((uint8_t *)p + 0x2c) = 0;
    *((uint8_t *)p + 0x2d) = 0;
    *((uint8_t *)p + 0x2e) = 0;
    *(uint32_t *)((uint8_t *)p + 0x30) = 0;
    *((uint8_t *)p + 0x34) = 0;
    *((uint8_t *)p + 0x35) = 0;
    *((uint8_t *)p + 0x36) = 0;
    *(uint32_t *)((uint8_t *)p + 0x38) = 0;
    *((uint8_t *)p + 0x3c) = 0;
    *((uint8_t *)p + 0x3d) = 0;
    *((uint8_t *)p + 0x3e) = 0;
  }
  table[10] = p;
  FUN_0098df00();

  /* slot 11 — 0x14C host; wire slot8 */
  p = operator_new(0x14C);
  p = (p == 0) ? 0 : (void *)FUN_00764030();
  table[11] = p;
  FUN_007647c0(table[8]);

  return 0;
}
