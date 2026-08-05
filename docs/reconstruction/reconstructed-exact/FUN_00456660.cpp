// =============================================================================
// FUN_00456660
// -----------------------------------------------------------------------------
// Stable ID: aa_00456660
// Address:   0x00456660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00456660 @ 0x00456660
// Stable ID: aa_00456660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00456660, memmove.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_00456660(int param_1,void *param_2,void *param_3)



{

  size_t _Size;

  void *pvVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  

  if (param_2 != param_3) {

    _Size = (*(int *)(param_1 + 8) - (int)param_3 >> 2) * 4;

    pvVar1 = memmove(param_2,param_3,_Size);

    *(void **)(param_1 + 8) = (void *)((int)pvVar1 + _Size);

  }

  *unaff_EBX = param_2;

  return;

}
