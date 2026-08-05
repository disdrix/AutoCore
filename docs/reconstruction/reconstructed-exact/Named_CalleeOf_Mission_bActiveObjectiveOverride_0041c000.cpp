// =============================================================================
// Named_CalleeOf_Mission_bActiveObjectiveOverride_0041c000
// -----------------------------------------------------------------------------
// Stable ID: aa_0041c000
// Callee of Mission_bActiveObjectiveOverride (+8 other named callers)
// Address:   0x0041c000  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_bActiveObjectiveOverride: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Mission_bActiveObjectiveOverride (+8 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0041c000, FUN_004205e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_bActiveObjectiveOverride (+8 other named callers)
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

int Named_CalleeOf_Mission_bActiveObjectiveOverride_0041c000(uint32_t /* width from decompiler */ param_1,char param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar2;

  int *local_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar1 = in_EAX + 3;

  local_4 = 0;

  if (in_EAX[3] != 0) {

    (**(code **)(*(int *)*in_EAX + 0x18))((int *)*in_EAX,1,piVar1,0,0,0);

    *piVar1 = 0;

  }

  local_8 = piVar1;

  iVar2 = (**(code **)(*(int *)*in_EAX + 0x14))

                    ((int *)*in_EAX,0,param_1,(uint)(param_2 != '\0') * 2 + -1,&local_4,&local_8);

  if (((iVar2 == 0) && (iVar2 = FUN_004205e0(), iVar2 < 0)) && (*piVar1 != 0)) {

    (**(code **)(*(int *)*in_EAX + 0x18))((int *)*in_EAX,1,piVar1,0,0,0);

    *piVar1 = 0;

  }

  return iVar2;

}
