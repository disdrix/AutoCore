// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_0052b080
// -----------------------------------------------------------------------------
// Stable ID: aa_0052b080
// Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
// Address:   0x0052b080  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, goto×1.
//  - Notable callees: FUN_00418b80, FUN_0052b080.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow
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

float10 __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen_0052b080(int param_1,float param_2)



{

  int iVar1;

  int iVar2;

  int local_4;

  

  if ((param_2 == 0.0) || (*(int *)((int)param_2 + 0xa8) == 0)) {

    return (float10)g_flZero;

  }

  iVar2 = *(int *)(*(int *)((int)param_2 + 0xa8) + 0x3c);

  iVar1 = *(int *)(iVar2 + 0x4b0);

  param_2 = *(float *)(iVar2 + 0x4ac);

  local_4 = param_1;

  FUN_00418b80(&local_4,&param_2);

  if (local_4 == *(int *)(param_1 + 0x588)) {

    iVar2 = -1;

  }

  else {

    iVar2 = *(int *)(local_4 + 0x10);

  }

  param_2 = DAT_00aaa7ac;

  if (iVar1 <= iVar2) {

    if ((iVar2 != iVar1) && (iVar1 < iVar2)) {

      if (DAT_00aaa7a4 < (float)(iVar2 - iVar1)) goto LAB_0052b0ed;

      param_2 = DAT_00aaa7ac - (float)(iVar2 - iVar1) * DAT_00aaa8dc;

    }

    return (float10)param_2;

  }

LAB_0052b0ed:

  return (float10)0.0;

}
