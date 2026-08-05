// =============================================================================
// CNDHashNode_ValueOwning_scalar_dtor_Inferred (FUN_00537550)
// -----------------------------------------------------------------------------
// Stable ID: aa_00537550
// Address:   0x00537550  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-07-29 dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual: reviews/A_aa_00537550_* + B_aa_00537550_*
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting dtor — vtbl[0] of PTR_FUN_009cefec.
//   Frees owned value at node+0x08; if flags&1, operator_delete(this).
// =============================================================================

extern "C" void operator_delete(void *);
extern void *PTR_FUN_009cefec;

void *__thiscall FUN_00537550(void **node, unsigned char flags)
{
  *node = &PTR_FUN_009cefec;
  if (node[2] != 0) {
    operator_delete(node[2]); // value at +0x08
  }
  node[2] = 0;
  if ((flags & 1) != 0) {
    operator_delete(node);
  }
  return node;
}
