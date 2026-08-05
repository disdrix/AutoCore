// =============================================================================
// FUN_00829970
// -----------------------------------------------------------------------------
// Stable ID: aa_00829970
// Address:   0x00829970  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00829970 @ 0x00829970
// Stable ID: aa_00829970
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: return×6, if×2, switch×1.
//  - Notable callees: FUN_00827920×2, Client_QuickBar_ActivateSlot, FUN_00826270, FUN_00829970.
//  - Return sites: 6.

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

uint32_t /* width from decompiler */ __thiscall FUN_00829970(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if (param_3 == 60000) {

    switch(param_2) {

    case 6:

      FUN_00827920();

      return 1;

    case 7:

      FUN_00826270();

      return 1;

    case 8:

      FUN_00827920();

      Client_QuickBar_ActivateSlot((char)param_1[0x140],0,0xffffffff);

      return 1;

    case 0xd:

    case 0x15:

      return 1;

    }

  }

  cVar1 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar1 != '\0') && (param_1[0xac] != 0)) {

    uVar2 = (**(code **)(*(int *)param_1[0xac] + 0x338))(param_2,param_3);

    return uVar2;

  }

  return 0;

}
