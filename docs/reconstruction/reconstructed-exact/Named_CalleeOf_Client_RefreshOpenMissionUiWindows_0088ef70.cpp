// =============================================================================
// Named_CalleeOf_Client_RefreshOpenMissionUiWindows_0088ef70
// -----------------------------------------------------------------------------
// Stable ID: aa_0088ef70
// Callee of Client_RefreshOpenMissionUiWindows
// Address:   0x0088ef70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0088ef70.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Client_RefreshOpenMissionUiWindows
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

void Named_CalleeOf_Client_RefreshOpenMissionUiWindows_0088ef70(void)



{

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = DAT_00afdf0c;

  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xcd0) == 0)) {

    local_4 = 0xff414141;

  }

  if (*(int *)(unaff_ESI + 0x5b4) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5b4) + 0x15c))(0,&local_4);

    (**(code **)(**(int **)(unaff_ESI + 0x5b4) + 0x34c))();

  }

  if (*(int *)(unaff_ESI + 0x5b8) != 0) {

    (**(code **)(**(int **)(unaff_ESI + 0x5b8) + 0x15c))(0,&local_4);

    (**(code **)(**(int **)(unaff_ESI + 0x5b8) + 0x34c))();

  }

  return;

}
