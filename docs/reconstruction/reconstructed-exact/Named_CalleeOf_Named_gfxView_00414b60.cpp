// =============================================================================
// Named_CalleeOf_Named_gfxView_00414b60
// -----------------------------------------------------------------------------
// Stable ID: aa_00414b60
// Callee of Named_gfxView (+7 other named callers)
// Address:   0x00414b60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_gfxView (+7 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~23 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00414b60.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_gfxView (+7 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_CalleeOf_Named_gfxView_00414b60(int param_1)

{
  void *pvVar1;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t /* width from decompiler */ local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_009beb18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;
  local_4 = 0xffffffff;
  if (*(void **)(param_1 + 4) != (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(*(void **)(param_1 + 4));
  }
  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;
  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;
  ExceptionList = pvVar1;
  return;
}
