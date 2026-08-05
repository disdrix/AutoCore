// =============================================================================
// FUN_008d0b70
// -----------------------------------------------------------------------------
// Stable ID: aa_008d0b70
// Address:   0x008d0b70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d0b70 @ 0x008d0b70
// Stable ID: aa_008d0b70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: Character_GetTechForPoolCalcs, FUN_004c4070, FUN_004c4140, FUN_004c41c0, FUN_008d0b70.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_008d0b70(void)



{

  int iVar1;

  short sVar2;

  int iVar3;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x544) != 0) {

    if (*(int *)(unaff_ESI + 2000) != 0) {

      iVar1 = **(int **)(unaff_ESI + 2000);

      sVar2 = FUN_004c4070();

      (**(code **)(iVar1 + 0x3ac))(((float)(int)sVar2 - DAT_00a111b0) * _DAT_00a110e8);

    }

    if (*(int *)(unaff_ESI + 0x7d4) != 0) {

      iVar1 = **(int **)(unaff_ESI + 0x7d4);

      iVar3 = Character_GetTechForPoolCalcs(*(void **)(unaff_ESI + 0x544));

      (**(code **)(iVar1 + 0x3ac))(((float)(int)(short)iVar3 - DAT_00a111b0) * _DAT_00a110e8);

    }

    if (*(int *)(unaff_ESI + 0x7d8) != 0) {

      iVar1 = **(int **)(unaff_ESI + 0x7d8);

      sVar2 = FUN_004c4140();

      (**(code **)(iVar1 + 0x3ac))(((float)(int)sVar2 - DAT_00a111b0) * _DAT_00a110e8);

    }

    if (*(int *)(unaff_ESI + 0x7dc) != 0) {

      iVar1 = **(int **)(unaff_ESI + 0x7dc);

      sVar2 = FUN_004c41c0();

      (**(code **)(iVar1 + 0x3ac))(((float)(int)sVar2 - DAT_00a111b0) * _DAT_00a110e8);

    }

  }

  return;

}
