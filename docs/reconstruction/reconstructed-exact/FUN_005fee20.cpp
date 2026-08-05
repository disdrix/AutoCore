// =============================================================================
// FUN_005fee20
// -----------------------------------------------------------------------------
// Stable ID: aa_005fee20
// Address:   0x005fee20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005fee20 @ 0x005fee20
// Stable ID: aa_005fee20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, goto×1, return×1.
//  - Notable callees: FUN_005fee20, FUN_006a3db0, ceil.
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



void __thiscall FUN_005fee20(int param_1,float param_2)



{

  short sVar1;

  short sVar2;

  short sVar3;

  

  sVar1 = *(short *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                    + 0x4c4);

  ceil((double)((float)(int)sVar1 * param_2));

  sVar2 = FUN_006a3db0();

  sVar3 = *(short *)(param_1 + 0xb4);

  sVar2 = sVar2 - sVar1;

  if (sVar2 == sVar3) {

    if (param_2 <= _DAT_00aaac14) {

      if (_DAT_009dd778 <= param_2) goto LAB_005fee9c;

      sVar3 = sVar3 + -1;

    }

    else {

      sVar3 = sVar3 + 1;

    }

  }

  else {

    sVar3 = sVar3 + sVar2;

  }

  *(short *)(param_1 + 0xb4) = sVar3;

LAB_005fee9c:

  if (*(short *)(param_1 + 0xb4) < 10) {

    *(uint16_t *)(param_1 + 0xb4) = 10;

  }

  return;

}
