// =============================================================================
// FUN_00496210
// -----------------------------------------------------------------------------
// Stable ID: aa_00496210
// Address:   0x00496210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00496210 @ 0x00496210
// Stable ID: aa_00496210
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00496210, FUN_004973b0, FUN_004973f0.
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

void __thiscall FUN_00496210(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x10);

  iVar2 = FUN_004973b0(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),

                       *(int *)(*(int *)(param_2 + 4) + 4) + 0x164 + param_2);

  FUN_004973f0(1);

  *(int *)(iVar1 + 4) = iVar2;

  **(int **)(iVar2 + 4) = iVar2;

  return;

}
