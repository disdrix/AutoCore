// =============================================================================
// FUN_0052d0b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0052d0b0
// Address:   0x0052d0b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052d0b0 @ 0x0052d0b0
// Stable ID: aa_0052d0b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00418b80×2, FUN_0052d0b0, FUN_00538ab0.
//  - Return sites: 3.

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

int __fastcall FUN_0052d0b0(int param_1)



{

  int iVar1;

  int *piVar2;

  int iVar3;

  int local_10;

  int local_c;

  int local_8;

  int local_4;

  

  iVar3 = *(int *)(param_1 + 0x594);

  local_4 = 0x32;

  if (-1 < iVar3) {

    local_10 = iVar3;

    piVar2 = (int *)FUN_00538ab0(&local_8,&local_10);

    if (*piVar2 != DAT_00b045b4) {

      local_10 = iVar3;

      FUN_00418b80(&local_c,&local_10);

      iVar1 = *(int *)(param_1 + 0x588);

      if (local_c == iVar1) {

        local_10 = 0;

      }

      else {

        local_10 = *(int *)(local_c + 0x14);

      }

      local_c = iVar3;

      FUN_00418b80(&local_8,&local_c);

      if (local_8 == iVar1) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(local_8 + 0x14);

      }

      if (*(int *)(param_1 + 0x590) - iVar3 < 0x32) {

        return *(int *)(param_1 + 0x590) - local_10;

      }

      return local_4;

    }

  }

  return 0;

}
