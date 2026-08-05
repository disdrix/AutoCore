// =============================================================================
// FUN_0064a840
// -----------------------------------------------------------------------------
// Stable ID: aa_0064a840
// Address:   0x0064a840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064a840 @ 0x0064a840
// Stable ID: aa_0064a840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0064a840.
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

void __thiscall FUN_0064a840(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int iVar1;

  

  param_2[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x44);

  param_2[3] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x48);

  param_2[1] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x38) + 0xc);

  *param_2 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  iVar1 = 0;

  do {

    *(uint8_t *)((int)param_2 + iVar1 + 0x10) = *(uint8_t *)(param_1 + 0xc + iVar1);

    iVar1 = iVar1 + 1;

  } while (iVar1 < 0x20);

  return;

}
