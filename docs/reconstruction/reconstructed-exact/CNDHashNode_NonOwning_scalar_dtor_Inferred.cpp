// =============================================================================
// CNDHashNode_NonOwning_scalar_dtor_Inferred (FUN_00537d10)
// -----------------------------------------------------------------------------
// Stable ID: aa_00537d10
// Address:   0x00537d10  (autoassault.exe, image base 0x400000)
// System:    container / CNDHash
// Generated: 2026-07-29 dual A/B seal (function created in Ghidra this dual)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Dual: reviews/A_aa_00537d10_* + B_aa_00537d10_*
// =============================================================================
//
// PURPOSE:
//   MSVC scalar-deleting dtor — vtbl[0] of PTR_FUN_009cf02c.
//   Does NOT free value at +0x08 (non-owning). If flags&1, operator_delete(this).
//   Twin of value-owning FUN_00537550 (009cefec).
// =============================================================================

extern "C" void operator_delete(void *);
extern void *PTR_FUN_009cf02c;

void *__thiscall FUN_00537d10(void **node, unsigned char flags)
{
  *node = &PTR_FUN_009cf02c;
  if ((flags & 1) != 0) {
    operator_delete(node);
  }
  return node;
}
