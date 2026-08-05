// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_005202d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005202d0
// Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows (+1 other named callers)
// Address:   0x005202d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Client_RefreshOpenMissionUiWindows (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, while×1, if×1.
//  - Notable callees: CONCAT31, FUN_005202d0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_RefreshOpenMissionUiWindows (+1 other named callers)
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

uint __thiscall Named_CalleeOf_Named_CalleeOf_Client_RefreshOpenMissionUiWindow_005202d0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  

  piVar1 = (int *)(param_1 + 0x5a0);

  iVar2 = 0;

  while ((*piVar1 != param_2 || (piVar1[1] != param_3))) {

    iVar2 = iVar2 + 1;

    piVar1 = piVar1 + 2;

    if (7 < iVar2) {

      return (uint)piVar1 & 0xffffff00;

    }

  }

  return CONCAT31((int3)((uint)piVar1 >> 8),1);

}
