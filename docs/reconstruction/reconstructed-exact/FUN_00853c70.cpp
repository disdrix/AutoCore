// =============================================================================
// FUN_00853c70
// -----------------------------------------------------------------------------
// Stable ID: aa_00853c70
// Address:   0x00853c70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00853c70 @ 0x00853c70
// Stable ID: aa_00853c70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00792490, FUN_00853c70.
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

void __fastcall FUN_00853c70(int *param_1)



{

  char cVar1;

  uint *puVar2;

  int iVar3;

  

  if ((((DAT_00d1d8dc != (int *)0x0) &&

       (cVar1 = (**(code **)(*DAT_00d1d8dc + 0x3d8))(), cVar1 != '\0')) &&

      (cVar1 = (**(code **)(*DAT_00d1d8dc + 0xd0))(), cVar1 != '\0')) && (DAT_00d1d8dc[0x146] != 0))

  {

    iVar3 = 0;

    puVar2 = (uint *)(param_1 + 0x15c);

    do {

      if ((((*puVar2 & puVar2[1]) != 0xffffffff) && (*puVar2 == DAT_00d1d8dc[0x148])) &&

         (puVar2[1] == DAT_00d1d8dc[0x149])) {

        DAT_00d1d8f4 = 1;

        DAT_00d1d8f5 = 0;

        (**(code **)(*DAT_00d1d8dc + 4))(0);

        break;

      }

      iVar3 = iVar3 + 1;

      puVar2 = puVar2 + 2;

    } while (iVar3 < 4);

  }

  (**(code **)(*param_1 + 0x3ac))();

  FUN_00792490();

  return;

}
