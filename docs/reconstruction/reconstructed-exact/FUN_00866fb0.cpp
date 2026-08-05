// =============================================================================
// FUN_00866fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00866fb0
// Address:   0x00866fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00866fb0 @ 0x00866fb0
// Stable ID: aa_00866fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00866fb0.
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

void __fastcall FUN_00866fb0(int *param_1)



{

  int *piVar1;

  int iVar2;

  int aiStack_18 [6];

  

  if (param_1[0x14c] != 0) {

    (**(code **)(*(int *)param_1[0x14c] + 0x13c))();

    iVar2 = 0;

    piVar1 = aiStack_18;

    (**(code **)(*(int *)param_1[0x14c] + 0x120))(piVar1,1,0);

    (**(code **)(*(int *)param_1[0x14c] + 0x140))(&stack0xffffffe4,1);

    aiStack_18[0] = iVar2 + (int)piVar1;

    (**(code **)(*param_1 + 300))(&stack0xffffffe4);

  }

  return;

}
