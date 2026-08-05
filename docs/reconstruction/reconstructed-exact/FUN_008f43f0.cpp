// =============================================================================
// FUN_008f43f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008f43f0
// Address:   0x008f43f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f43f0 @ 0x008f43f0
// Stable ID: aa_008f43f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_008f43f0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __thiscall FUN_008f43f0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  piVar1 = (int *)param_1[0x14f];

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0xd8))();

    if (cVar2 != '\0') {

      if (0 < (short)((uint)param_2 >> 0x10)) {

        (**(code **)(*piVar1 + 0x45c))(0xbf800000);

        return 1;

      }

      (**(code **)(*piVar1 + 0x45c))(0x3f800000);

      return 1;

    }

  }

  cVar2 = (**(code **)(*param_1 + 0x3d8))();

  if ((cVar2 != '\0') && (param_1[0x12e] != 0)) {

                    /* WARNING: Could not recover jumptable at 0x008f4463. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    uVar3 = (**(code **)(*(int *)param_1[0x12e] + 0x39c))();

    return uVar3;

  }

  return 0;

}
