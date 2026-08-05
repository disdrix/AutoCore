// =============================================================================
// FUN_005a61d0
// -----------------------------------------------------------------------------
// Stable ID: aa_005a61d0
// Address:   0x005a61d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a61d0 @ 0x005a61d0
// Stable ID: aa_005a61d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: fwrite×5, FUN_005a61d0.
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

void __thiscall FUN_005a61d0(int param_1,FILE *param_2)



{

  FILE *_File;

  int iVar1;

  int local_4;

  

  _File = param_2;

  local_4 = param_1;

  fwrite((void *)(param_1 + 0x134),4,1,param_2);

  fwrite((void *)(param_1 + 0x140),0xc,1,_File);

  fwrite((void *)(param_1 + 0x30),1,0x104,_File);

  iVar1 = 0;

  if (*(int *)(param_1 + 0x14) == 0) {

    param_2 = (FILE *)0x0;

  }

  else {

    param_2 = (FILE *)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14) >> 2);

  }

  fwrite(&param_2,4,1,_File);

  if (0 < (int)param_2) {

    do {

      if (*(int *)(*(int *)(param_1 + 0x14) + iVar1 * 4) == 0) {

        local_4 = -1;

      }

      else {

        local_4 = *(int *)(*(int *)(*(int *)(param_1 + 0x14) + iVar1 * 4) + 0x134);

      }

      fwrite(&local_4,4,1,_File);

      iVar1 = iVar1 + 1;

    } while (iVar1 < (int)param_2);

  }

  return;

}
