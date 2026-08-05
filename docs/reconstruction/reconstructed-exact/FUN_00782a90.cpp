// =============================================================================
// FUN_00782a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00782a90
// Address:   0x00782a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00782a90 @ 0x00782a90
// Stable ID: aa_00782a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, while×3, do×1, for×1.
//  - Notable callees: FUN_00782a90.
//  - Return sites: 5.

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

int __fastcall FUN_00782a90(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  if (param_2 == 0) {

    return 0;

  }

  iVar2 = *(int *)(param_2 + 0xc);

  iVar4 = param_2;

  while (iVar1 = iVar2, iVar1 != 0) {

    iVar4 = iVar1;

    iVar2 = *(int *)(iVar1 + 0xc);

  }

  iVar2 = 0;

  do {

    iVar1 = *(int *)(iVar4 + 8);

    iVar2 = iVar2 + 1;

    if (iVar1 == 0) {

      iVar1 = *(int *)(iVar4 + 0x10);

      if (*(int *)(iVar4 + 0x10) == 0) {

        return iVar2;

      }

      while( true ) {

        iVar3 = iVar1;

        if (iVar3 == *(int *)(param_2 + 0x10)) {

          return iVar2;

        }

        if (iVar4 == *(int *)(iVar3 + 0xc)) break;

        iVar1 = *(int *)(iVar3 + 0x10);

        iVar4 = iVar3;

        if (*(int *)(iVar3 + 0x10) == 0) {

          return iVar2;

        }

      }

      iVar4 = *(int *)(iVar4 + 0x10);

    }

    else {

      iVar4 = iVar1;

      for (iVar1 = *(int *)(iVar1 + 0xc); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {

        iVar4 = iVar1;

      }

    }

  } while (iVar4 != 0);

  return iVar2;

}
