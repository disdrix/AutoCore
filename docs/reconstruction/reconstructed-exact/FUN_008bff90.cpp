// =============================================================================
// FUN_008bff90
// -----------------------------------------------------------------------------
// Stable ID: aa_008bff90
// Address:   0x008bff90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bff90 @ 0x008bff90
// Stable ID: aa_008bff90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_008bff90.
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

void __thiscall FUN_008bff90(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  iVar1 = *(int *)(param_1 + 0x560);

  while( true ) {

    if (*(int *)(param_1 + 0x568) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 0x56c) - *(int *)(param_1 + 0x568) >> 2;

    }

    if ((iVar2 <= iVar1) || (*(int *)(param_1 + 0x530) + *(int *)(param_1 + 0x560) <= iVar1)) break;

    if ((*(int *)(*(int *)(param_1 + 0x568) + iVar1 * 4) == param_2) &&

       (*(int *)(iVar3 + *(int *)(param_1 + 0x598)) != 0)) {

                    /* WARNING: Could not recover jumptable at 0x008c0014. Too many branches */

                    /* WARNING: Treating indirect jump as call */

      (**(code **)(**(int **)(*(int *)(param_1 + 0x598) + (iVar1 - *(int *)(param_1 + 0x560)) * 4) +

                  0xd4))();

      return;

    }

    iVar1 = iVar1 + 1;

    iVar3 = iVar3 + 4;

  }

  return;

}
