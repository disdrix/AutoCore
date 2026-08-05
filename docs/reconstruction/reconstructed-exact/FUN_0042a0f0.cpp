// =============================================================================
// FUN_0042a0f0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a0f0
// Address:   0x0042a0f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042a0f0 @ 0x0042a0f0
// Stable ID: aa_0042a0f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00429fc0×2, FUN_00429f60, FUN_0042a0f0.
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

void __thiscall FUN_0042a0f0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int *piVar3;

  

  (**(code **)(*param_1 + 0x38))(param_2);

  iVar1 = FUN_00429f60(&stack0xfffffff4);

  if (iVar1 == 0) {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00429fc0(&stack0xfffffff4);

    *puVar2 = 1;

    return;

  }

  piVar3 = (int *)FUN_00429fc0(&stack0xfffffff4);

  *piVar3 = *piVar3 + 1;

  return;

}
