// =============================================================================
// FUN_008f7c40
// -----------------------------------------------------------------------------
// Stable ID: aa_008f7c40
// Address:   0x008f7c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f7c40 @ 0x008f7c40
// Stable ID: aa_008f7c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00792490, FUN_008f7c40.
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

void __fastcall FUN_008f7c40(int *param_1)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  

  piVar3 = param_1 + 0x150;

  iVar2 = 2;

  do {

    if (*piVar3 != 0) {

      cVar1 = (**(code **)(*(int *)*piVar3 + 0x3d8))();

      if (cVar1 != '\0') {

        (**(code **)(*(int *)*piVar3 + 0x440))();

      }

      (**(code **)(*param_1 + 0xb0))(*piVar3);

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  FUN_00792490();

                    /* WARNING: Could not recover jumptable at 0x008f7c90. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*param_1 + 0x3ac))();

  return;

}
