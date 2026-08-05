// =============================================================================
// FUN_004f46c0
// -----------------------------------------------------------------------------
// Stable ID: aa_004f46c0
// Address:   0x004f46c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004f46c0 @ 0x004f46c0
// Stable ID: aa_004f46c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×8, do×1, while×1, return×1.
//  - Notable callees: FUN_004f46c0, FUN_00517db0.
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

void __thiscall FUN_004f46c0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  FUN_00517db0(param_2);

  iVar2 = *(int *)(param_1 + -0x418);

  if (iVar2 != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x2b0))(param_2);

  }

  if (*(int *)(param_1 + -0x41c) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x41c) + 4) + 4) + 4 +

                         *(int *)(param_1 + -0x41c)) + 0x2b0))(param_2);

  }

  iVar2 = 0;

  iVar3 = 3;

  do {

    iVar1 = *(int *)(iVar2 + *(int *)(param_1 + -0x410));

    if (iVar1 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1) + 0x2b0))(param_2);

    }

    iVar2 = iVar2 + 4;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  iVar2 = *(int *)(param_1 + -0x40c);

  if (iVar2 != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2) + 0x2b0))(param_2);

  }

  if (*(int *)(param_1 + -0x408) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x408) + 4) + 4) + 4 +

                         *(int *)(param_1 + -0x408)) + 0x2b0))(param_2);

  }

  if (*(int *)(param_1 + -0x404) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x404) + 4) + 4) + 4 +

                         *(int *)(param_1 + -0x404)) + 0x2b0))(param_2);

  }

  if (*(int *)(param_1 + -0x400) != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + -0x400) + 4) + 4) + 4 +

                         *(int *)(param_1 + -0x400)) + 0x2b0))(param_2);

  }

  if (*(int *)(param_1 + -0x3c0) != 0) {

    (**(code **)(**(int **)(param_1 + -0x3c0) + 0xc))(param_2);

  }

  return;

}
