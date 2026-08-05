// =============================================================================
// FUN_00564200
// -----------------------------------------------------------------------------
// Stable ID: aa_00564200
// Address:   0x00564200  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00564200 @ 0x00564200
// Stable ID: aa_00564200
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_005085b0, FUN_005635e0, FUN_00564200.
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

void __thiscall FUN_00564200(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  

  if (*(char *)(param_2 + 0x204) != '\0') {

    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

    if ((*(uint *)(param_2 + 0x210) & *(uint *)(param_2 + 0x214)) == 0xffffffff) {

      piVar1 = (int *)(iVar2 + 0x28);

      *piVar1 = *piVar1 + -1;

    }

    else {

      piVar1 = (int *)(iVar2 + 0x2c);

      *piVar1 = *piVar1 + -1;

    }

  }

  FUN_005085b0(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2);

  FUN_005635e0(0xffffffff,0);

  return;

}
