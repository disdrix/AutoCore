// =============================================================================
// FUN_00407b70
// -----------------------------------------------------------------------------
// Stable ID: aa_00407b70
// Address:   0x00407b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00407b70 @ 0x00407b70
// Stable ID: aa_00407b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: return×2, if×1, while×1.
//  - Notable callees: FUN_00404000, FUN_00407b70, FUN_00408ad0, FUN_00409920.
//  - Return sites: 2.

// READABILITY:
// Control-flow (from raw @ 0x00407b70; evidence only — no invented semantics):
//  - Entry: `undefined4 * FUN_00407b70(undefined4 *param_1,int *param_2,int *param_3)`.
//  - Loops: while (param_2 != param_3).
//  - Branches: if ((param_2 == *piVar1) && (param_3 == piVar1)).
//  - Calls: FUN_00409920(piVar1[1]); FUN_00404000(); FUN_00408ad0().
//  - Writes: *param_1 = **(unaff_ESI + 4); *param_1 = param_2.
//  - Returns (2 site(s)): `param_1`.




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

uint32_t /* width from decompiler */ * FUN_00407b70(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3)



{

  int *piVar1;

  int unaff_ESI;

  

  piVar1 = *(int **)(unaff_ESI + 4);

  if ((param_2 == (int *)*piVar1) && (param_3 == piVar1)) {

    FUN_00409920(piVar1[1]);

    *(int *)(*(int *)(unaff_ESI + 4) + 4) = *(int *)(unaff_ESI + 4);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4) = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 4);

    *(int *)(*(int *)(unaff_ESI + 4) + 8) = *(int *)(unaff_ESI + 4);

    *param_1 = **(uint32_t /* width from decompiler */ **)(unaff_ESI + 4);

    return param_1;

  }

  while (param_2 != param_3) {

    FUN_00404000();

    FUN_00408ad0();

  }

  *param_1 = param_2;

  return param_1;

}
