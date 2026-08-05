// =============================================================================
// FUN_004c0db0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c0db0
// Address:   0x004c0db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c0db0 @ 0x004c0db0
// Stable ID: aa_004c0db0
// Embedded strings (evidence for future rename):
//   - "v3Right"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00493550×4, FUN_00972e50×2, FUN_004148e0, FUN_004c0db0.
//  - Strings: "v3Right".
//  - Return sites: 2.

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

uint32_t /* width from decompiler */ __thiscall FUN_004c0db0(int param_1,int param_2)



{

  int iVar1;

  

  if (*(int *)(param_1 + 0xc0) == 0) {

    return 0;

  }

  FUN_004148e0(param_1 + 0x8c);

  if (*(int *)(*(int *)(param_1 + 0xb0) + 0x20) != 0) {

    iVar1 = *(int *)(*(int *)(param_2 + 0x30) + 8);

    if ((*(byte *)(iVar1 + 0xbc) & 1) != 0) {

      iVar1 = FUN_00972e50();

    }

    FUN_00493550("v3Right",iVar1);

    FUN_00493550(&DAT_009cb684,iVar1 + 0x10);

  }

  if (*(int *)(param_1 + 0x84) != 0) {

    iVar1 = *(int *)(*(int *)(param_2 + 0x30) + 8);

    if ((*(byte *)(iVar1 + 0xbc) & 1) != 0) {

      iVar1 = FUN_00972e50();

    }

    FUN_00493550("v3Right",iVar1);

    FUN_00493550(&DAT_009cb684,iVar1 + 0x10);

  }

  (**(code **)(**(int **)(param_1 + 0xac) + 0x3c))(param_2);

  return 1;

}
