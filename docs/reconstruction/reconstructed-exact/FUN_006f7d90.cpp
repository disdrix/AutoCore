// =============================================================================
// FUN_006f7d90
// -----------------------------------------------------------------------------
// Stable ID: aa_006f7d90
// Address:   0x006f7d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f7d90 @ 0x006f7d90
// Stable ID: aa_006f7d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×1, while×1.
//  - Notable callees: FUN_006f7ca0×2, FUN_006f7d30×2, FUN_006f7d90, block.
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

/* WARNING: Removing unreachable block (ram,0x006f7e97) */



void FUN_006f7d90(int param_1,int param_2,int param_3)



{

  int iVar1;

  ushort *puVar2;

  int local_8;

  int local_4;

  

  if (*(int *)(param_1 + 0x54) < 3) {

    return;

  }

  if (3 < *(int *)(param_1 + 0x50)) {

    *(uint8_t *)(param_1 + 0x58) = 1;

    return;

  }

  if ((param_2 >> 4 & 8U) == 0) {

    local_4 = 2 - (uint)((param_2 >> 4 & 4U) != 0);

  }

  else {

    local_4 = 0;

  }

  if ((param_3 >> 4 & 8U) == 0) {

    local_8 = 2 - (uint)((param_3 >> 4 & 4U) != 0);

  }

  else {

    local_8 = 0;

  }

  if (0 < *(int *)(param_1 + 0x54)) {

    iVar1 = *(int *)(param_1 + 0x54);

    puVar2 = (ushort *)(param_1 + 0x20);

    do {

      if (*puVar2 < 3) {

        FUN_006f7ca0(local_8);

      }

      else if (*puVar2 < 6) {

        FUN_006f7ca0(local_4);

      }

      else {

        FUN_006f7d30();

        FUN_006f7d30();

      }

      puVar2 = puVar2 + 3;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  *(uint8_t *)(param_1 + 0x58) = 1;

  return;

}
