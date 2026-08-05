// =============================================================================
// FUN_008f6450
// -----------------------------------------------------------------------------
// Stable ID: aa_008f6450
// Address:   0x008f6450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008f6450 @ 0x008f6450
// Stable ID: aa_008f6450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: return×5, if×3, switch×1.
//  - Notable callees: FUN_0078e670, FUN_008f5e20, FUN_008f5e70, FUN_008f6100, FUN_008f62a0, FUN_008f6450, ROUND.
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

uint32_t /* width from decompiler */ __thiscall FUN_008f6450(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  float10 fVar3;

  

  if (param_3 == 0x9c41) {

    switch(param_2) {

    case 5:

    case 0x65:

    case 0x66:

      FUN_008f5e70();

      return 1;

    case 6:

    case 100:

    case 0x67:

      if ((param_1[0x3a0] != 0) && (cVar1 = FUN_0078e670(), cVar1 == '\0')) {

        FUN_008f5e20();

      }

      return 1;

    case 0x1a:

      fVar3 = (float10)(**(code **)(*(int *)param_1[0x3a0] + 0x458))();

      param_1[0x43d] =

           (int)ROUND(((float10)g_flOne - fVar3) *

                      (float10)((param_1[0x43c] - param_1[0x43b]) + param_1[0x439]));

      FUN_008f62a0(param_1);

      FUN_008f6100(0);

      return 1;

    }

  }

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && ((int *)param_1[0xac] != (int *)0x0)) {

    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar2;

  }

  return 0;

}
