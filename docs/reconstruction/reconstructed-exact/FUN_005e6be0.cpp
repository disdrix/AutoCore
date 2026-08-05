// =============================================================================
// FUN_005e6be0
// -----------------------------------------------------------------------------
// Stable ID: aa_005e6be0
// Address:   0x005e6be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e6be0 @ 0x005e6be0
// Stable ID: aa_005e6be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_005e6be0.
//  - Return sites: 1.

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

void __fastcall FUN_005e6be0(int *param_1)



{

  char cVar1;

  void *pvVar2;

  

  if ((void *)param_1[0x5b] != (void *)0x0) {

    operator_delete__((void *)param_1[0x5b]);

  }

  param_1[0x5b] = 0;

  pvVar2 = operator_new__(0x20);

  param_1[0x5b] = (int)pvVar2;

  cVar1 = (**(code **)(*param_1 + 0xa0))(pvVar2);

  if (cVar1 == '\0') {

    if ((void *)param_1[0x5b] != (void *)0x0) {

      operator_delete__((void *)param_1[0x5b]);

    }

    param_1[0x5b] = 0;

  }

  return;

}
