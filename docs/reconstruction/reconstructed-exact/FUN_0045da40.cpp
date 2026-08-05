// =============================================================================
// FUN_0045da40
// -----------------------------------------------------------------------------
// Stable ID: aa_0045da40
// Address:   0x0045da40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0045da40 @ 0x0045da40
// Stable ID: aa_0045da40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0045da40, FUN_0073f7b0.
//  - Return sites: 2.

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

void __thiscall FUN_0045da40(int *param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  

  uVar1 = (**(code **)(*param_1 + 0x38))();

  uVar2 = (**(code **)(*param_1 + 0x34))();

  if (*param_2 != 0) {

    iVar3 = FUN_0073f7b0(uVar2,uVar1);

    param_1[7] = iVar3;

    return;

  }

  param_1[7] = -1;

  return;

}
