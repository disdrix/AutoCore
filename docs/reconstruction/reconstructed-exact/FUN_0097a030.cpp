// =============================================================================
// FUN_0097a030
// -----------------------------------------------------------------------------
// Stable ID: aa_0097a030
// Address:   0x0097a030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0097a030 @ 0x0097a030
// Stable ID: aa_0097a030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00979d80, FUN_0097a030.
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

void __thiscall FUN_0097a030(int *param_1,int *param_2,char param_3)



{

  char cVar1;

  int local_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  if (param_2 != (int *)0x0) {

    (**(code **)(*param_2 + 0x120))(&local_18,1,1);

    (**(code **)(*param_1 + 0x120))(&stack0xffffffe4,1,1);

    local_18 = local_18 - iStack_10;

    iStack_14 = iStack_14 - iStack_c;

    if (param_3 == '\0') {

      param_1[0x147] = local_18;

      param_1[0x148] = iStack_14;

    }

    else {

      (**(code **)(*param_2 + 0x140))(&iStack_8,1);

      param_1[0x147] = iStack_8 / 2 + local_18;

      param_1[0x148] = iStack_4 / 2 + iStack_14;

    }

  }

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    FUN_00979d80();

  }

  return;

}
