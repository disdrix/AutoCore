// =============================================================================
// FUN_00780e50
// -----------------------------------------------------------------------------
// Stable ID: aa_00780e50
// Address:   0x00780e50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00780e50 @ 0x00780e50
// Stable ID: aa_00780e50
// Embedded strings (evidence for future rename):
//   - "LogGhostConnection"
//   - "Max Ghost count reached"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, for×1.
//  - Notable callees: FUN_00429bd0, FUN_00431c60, FUN_00780e50, FUN_00783aa0, FUN_00783b60.
//  - Strings: "LogGhostConnection"; "Max Ghost count reached".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_00780e50(uint param_1)



{

  uint *puVar1;

  uint uVar2;

  uint unaff_EDI;

  

  if ((((*(char *)(unaff_EDI + 0x215) != '\0') && (*(int *)(unaff_EDI + 0x208) != 0)) &&

      ((*(uint *)(param_1 + 0x38) >> 3 & 1) != 0)) &&

     (((*(uint *)(param_1 + 0x38) >> 2 & 1) == 0 || (*(int *)(unaff_EDI + 0x128) != 0)))) {

    uVar2 = param_1 & 0x3ff;

    for (puVar1 = *(uint **)(*(int *)(unaff_EDI + 0x224) + uVar2 * 4); puVar1 != (uint *)0x0;

        puVar1 = (uint *)puVar1[8]) {

      if (*puVar1 == param_1) {

        puVar1[10] = puVar1[10] | 1;

        return;

      }

    }

    if (*(int *)(unaff_EDI + 0x210) == 0x400) {

      if ((_DAT_00d1fd50 & 1) == 0) {

        _DAT_00d1fd50 = _DAT_00d1fd50 | 1;

        DAT_00d1fd4c = FUN_00783b60("LogGhostConnection");

      }

      if (*(char *)(DAT_00d1fd4c + 4) != '\0') {

        DAT_00d179a0 = DAT_00d1fd4c;

        FUN_00783aa0(&DAT_00a2c2a4,"Max Ghost count reached");

        DAT_00d179a0 = 0;

        return;

      }

    }

    else {

      puVar1 = *(uint **)(*(int *)(unaff_EDI + 0x208) + *(int *)(unaff_EDI + 0x210) * 4);

      FUN_00431c60();

      puVar1[2] = 0xffffffff;

      puVar1[3] = 0xffffffff;

      FUN_00429bd0();

      puVar1[10] = 5;

      *puVar1 = param_1;

      puVar1[4] = 0;

      puVar1[9] = 0;

      puVar1[7] = unaff_EDI;

      puVar1[5] = *(uint *)(param_1 + 0x24);

      if (*(int *)(param_1 + 0x24) != 0) {

        *(uint **)(*(int *)(param_1 + 0x24) + 0x18) = puVar1;

      }

      puVar1[6] = 0;

      *(uint **)(param_1 + 0x24) = puVar1;

      puVar1[8] = *(uint *)(*(int *)(unaff_EDI + 0x224) + uVar2 * 4);

      *(uint **)(*(int *)(unaff_EDI + 0x224) + uVar2 * 4) = puVar1;

    }

  }

  return;

}
