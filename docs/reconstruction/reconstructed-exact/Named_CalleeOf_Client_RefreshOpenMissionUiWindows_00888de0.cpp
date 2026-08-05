// =============================================================================
// Named_CalleeOf_Client_RefreshOpenMissionUiWindows_00888de0
// -----------------------------------------------------------------------------
// Stable ID: aa_00888de0
// Callee of Client_RefreshOpenMissionUiWindows
// Address:   0x00888de0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_RefreshOpenMissionUiWindows: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00888de0, FUN_0089e710, FUN_008b2f00, FUN_008b3050, FUN_008b3670.
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

void Named_CalleeOf_Client_RefreshOpenMissionUiWindows_00888de0(void)



{

  char cVar1;

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x510) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x510) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_0089e710();

    }

  }

  if (*(int *)(in_EAX + 0x514) != 0) {

    cVar1 = (**(code **)(**(int **)(in_EAX + 0x514) + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_008b3670();

      FUN_008b3050();

      FUN_008b2f00();

    }

  }

  return;

}
