// =============================================================================
// MeshHost0xC4_BaseCtor_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Placement-construct a 0xC4 multi-vtbl mesh/host shell: three vtbl
//           slots, two small subobjects, FLT_MAX/−FLT_MAX float triples, a
//           nested subobject at +0x78, and flag bits 0x81 at +0xBC.
//
// Address:  0x00748960  (autoassault.exe, image base 0x400000)
// Body:     0x00748960–0x00748aaf (336 B / 0x150)
// Stable:   aa_00748960
// System:   mesh / host graphics
// Ghidra:   FUN_00748960
//
// ABI:      ECX = self (preallocated 0xC4); return self in EAX; plain RET.
// Callers:  many (HostPtrTable12, TacArc mesh init, particle fluid, …).
//
// Exactness: CF mirrors raw + read_memory; names structural _Inferred.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W36-H seal).
// =============================================================================

#include <stdint.h>

extern void *ExceptionList;
extern void *LAB_009ad90d;
extern void *PTR_FUN_00a9db64;
extern void *PTR_LAB_00a9db0c;
extern void *PTR_LAB_00a9db58;
extern void *PTR_FUN_00a9da80;
extern uint32_t DAT_00aaa630; /* +FLT_MAX 0x7f7fffff */
extern uint32_t DAT_00aaa63c; /* -FLT_MAX 0xff7fffff */

extern void __stdcall eh_vector_constructor_iterator_(
    void *array, uint32_t size, uint32_t count,
    void (__fastcall *ctor)(void *), void (__fastcall *dtor)(void *));
extern void __fastcall FUN_00437440(void *elem);
extern void __fastcall FUN_00437450(void *elem);
extern int FUN_00437680(void *sub /* this+0x78 */);

uint32_t *__fastcall MeshHost0xC4_BaseCtor_Inferred(uint32_t *self /* ECX */)
{
  void *frame[3];
  /* SEH: frame[0]=prev ExceptionList; frame[1]=handler; frame[2]=state */
  frame[1] = &LAB_009ad90d;
  frame[0] = ExceptionList;
  ExceptionList = &frame[0];

  /* multi-vtbl install (interim secondary then final) */
  self[1] = (uint32_t)&PTR_LAB_00a9db0c;
  self[0] = (uint32_t)&PTR_FUN_00a9db64;
  self[1] = (uint32_t)&PTR_LAB_00a9db58;
  self[3] = 0;
  self[2] = (uint32_t)&PTR_FUN_00a9da80;

  /* EH state ~2: vector-construct 2 elements of size 8 at +0x10 */
  eh_vector_constructor_iterator_(self + 4, 8, 2, FUN_00437440, FUN_00437450);

  self[8] = 0;                         /* +0x20 */
  *(uint8_t *)(self + 9) = 0;          /* +0x24 */
  *((uint8_t *)self + 0x25) = 0;
  *((uint8_t *)self + 0x26) = 0;

  /* EH state ~4; zero mid floats then seed AABB-style extremes */
  self[10] = 0;  /* +0x28 */
  self[11] = 0;
  self[12] = 0;
  self[13] = 0;
  self[14] = 0;
  {
    uint32_t hi = DAT_00aaa630; /* +FLT_MAX */
    self[15] = hi; self[16] = hi; self[17] = hi; /* +0x3C..+0x44 */
  }
  {
    uint32_t lo = DAT_00aaa63c; /* -FLT_MAX */
    self[18] = lo; self[19] = lo; self[20] = lo; /* +0x48..+0x50 */
  }

  *(uint8_t *)(self + 0x15) = 1;       /* +0x54 */
  self[0x16] = 0;                      /* +0x58 */
  self[0x17] = 0;                      /* +0x5C */
  self[0x18] = 0xFFFFFFFFu;            /* +0x60 */
  self[0x19] = 0;
  self[0x1a] = 0;
  self[0x1b] = 0;                      /* +0x6C zero float */
  self[0x1c] = 0;
  self[0x1d] = 0;

  FUN_00437680(self + 0x1e);           /* +0x78 subobject */

  self[0x23] = 0;                      /* +0x8C */
  self[0x24] = 0;
  self[0x25] = 0;
  self[0x27] = 0;                      /* +0x9C */
  self[0x28] = 0;
  self[0x29] = 0;
  self[0x2a] = 0;
  self[0x2c] = 0;                      /* +0xB0 */
  self[0x2d] = 0;
  self[0x2b] = 0xFFFFFFFFu;            /* +0xAC */
  self[0x2e] = 0;
  self[0x2f] = 0;
  self[0x30] = 0;                      /* +0xC0 */
  *(uint8_t *)(self + 0x2f) =
      (uint8_t)(*(uint8_t *)(self + 0x2f) | 0x81); /* +0xBC |= 0x81 */

  ExceptionList = frame[0];
  return self;
}
