// =============================================================================
// FUN_00653840
// -----------------------------------------------------------------------------
// Stable ID: aa_00653840
// Address:   0x00653840  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00653840 @ 0x00653840
// Stable ID: aa_00653840
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: return×9, switch×1.
//  - Notable callees: FUN_006621d0×8, FUN_00656af0×2, FUN_00653710, FUN_00653750, FUN_00653790, FUN_00653840, FUN_00662640, FUN_00662c50.
//  - Return sites: 9.

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

void FUN_00653840(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  

  uVar1 = (**(code **)(*param_1 + 0x20))();

  switch(uVar1) {

  case 0:

    FUN_006621d0();

    FUN_00664180(param_1,param_2,DAT_00d03500);

    return;

  case 1:

    FUN_006621d0();

    FUN_00663fc0(param_1,param_2,DAT_00d03500);

    return;

  case 2:

    FUN_006621d0();

    FUN_00656af0();

    break;

  case 3:

    FUN_006621d0();

    FUN_00662c50(param_1,param_2,DAT_00d03500);

    return;

  case 4:

    FUN_006621d0();

    FUN_00656af0();

    break;

  case 5:

  case 7:

    FUN_00653750();

    FUN_00662640(param_1,param_2,DAT_00d03500);

    FUN_00653790();

    return;

  case 6:

    FUN_006621d0();

    FUN_00663a70(param_1,param_2,DAT_00d03500);

    return;

  case 8:

    FUN_006621d0();

    FUN_006638d0(param_1,param_2,DAT_00d03500);

    return;

  case 9:

    FUN_006621d0();

    FUN_006632a0(param_1,param_2,DAT_00d03500);

    return;

  default:

    return;

  }

  FUN_00662e60(param_1,param_2,DAT_00d03500);

  FUN_00653710();

  return;

}
