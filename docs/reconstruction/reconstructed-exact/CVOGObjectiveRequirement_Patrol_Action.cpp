// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: CVOGObjectiveRequirement_Patrol_Action.
//  - Return sites: 2.

// =============================================================================
// CVOGObjectiveRequirement_Patrol_Action
// -----------------------------------------------------------------------------
// Stable ID: aa_0060e120
// Address:   0x0060e120  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

float10 __thiscall

CVOGObjectiveRequirement_Patrol_Action(int param_1,uint32_t /* width from decompiler */ param_2,float param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0xd0) * *(int *)(param_1 + 0x24);

  if (iVar1 == 0) {

    return (float10)g_flOne;

  }

  param_3 = *(float *)((int)param_3 + 4 + (uint)*(byte *)(param_1 + 8) * 4) / (float)iVar1;

  if (g_flOne <= param_3) {

    param_3 = g_flOne;

  }

  return (float10)param_3;

}
