// =============================================================================
// FUN_00892740
// -----------------------------------------------------------------------------
// Stable ID: aa_00892740
// Address:   0x00892740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00892740 @ 0x00892740
// Stable ID: aa_00892740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×4.
//  - Notable callees: FUN_007fef20, FUN_00802e70, FUN_0087b500, FUN_00892740.
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

uint32_t /* width from decompiler */ __thiscall FUN_00892740(int *param_1,int param_2,int param_3)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  

  if (param_3 == 0x9c41) {

    if ((param_2 == 8) && (*(char *)(DAT_00d1b644 + 0xf6) != '\0')) {

      FUN_007fef20(0x27,0,0);

      return 1;

    }

  }

  else if ((param_3 == 40000) && (param_2 == 8)) {

    FUN_00802e70(param_1[0x16c],param_1[0x16d]);

    return 1;

  }

  cVar2 = (**(code **)(*param_1 + 0xd8))();

  if ((cVar2 != '\0') && ((param_1[0xac] != 0 && (param_3 == 0x9c42)))) {

    iVar1 = *(int *)param_1[0xac];

    uVar3 = (**(code **)(*param_1 + 0x78))();

    uVar3 = (**(code **)(iVar1 + 0x338))(param_2,uVar3);

    return uVar3;

  }

  uVar3 = FUN_0087b500(param_2,param_3);

  return uVar3;

}
