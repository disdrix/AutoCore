// =============================================================================
// Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_004c4b20
// -----------------------------------------------------------------------------
// Stable ID: aa_004c4b20
// Callee of CVOGCombat_OnDeathAwardKillXp
// Address:   0x004c4b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGCombat_OnDeathAwardKillXp: combat/reward helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004c4b20.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGCombat_OnDeathAwardKillXp
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

float10 __fastcall Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_004c4b20(int param_1)



{

  int iVar1;

  float fVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

  fVar2 = *(float *)(iVar1 + 100 + param_1);

  iVar1 = (**(code **)(*(int *)(iVar1 + param_1 + 4) + 0x244))();

  fVar2 = fVar2 / (float)iVar1;

  if (DAT_009cb8b8 <= fVar2) {

    return (float10)g_flOne;

  }

  if (fVar2 < g_flMultiKillCountBlend) {

    return (float10)g_flZero;

  }

  return (float10)fVar2;

}
