// =============================================================================
// FUN_00530610
// -----------------------------------------------------------------------------
// Stable ID: aa_00530610
// Address:   0x00530610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00530610 @ 0x00530610
// Stable ID: aa_00530610
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00418b80, FUN_00530610, FUN_0053af20.
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

void __thiscall FUN_00530610(int param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int local_4;

  

  local_4 = param_1;

  FUN_00418b80(&local_4,&param_2);

  iVar1 = param_3;

  if (local_4 == *(int *)(param_1 + 0x588)) {

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_0053af20(&param_2);

    *puVar2 = 0;

    puVar2[1] = iVar1;

    return;

  }

  *(int *)(local_4 + 0x14) = *(int *)(local_4 + 0x14) + param_3;

  return;

}
