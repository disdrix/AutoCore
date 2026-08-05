// =============================================================================
// FUN_0098d870
// -----------------------------------------------------------------------------
// Stable ID: aa_0098d870
// Address:   0x0098d870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098d870 @ 0x0098d870
// Stable ID: aa_0098d870
// Embedded strings (evidence for future rename):
//   - "ZFill"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxSubPhaseZFill.cpp"
//   - "Z-Fill Phase Effect not present, Z-Fill disabled."
//   - "PalZFill.fx"
//   - "Z-Fill Techniques Effect not present, Z-Fill disabled."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~56 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, do×1, goto×1, while×1.
//  - Notable callees: FUN_004450d0×2, vog_LogMessage×2, FUN_0043bd40, FUN_00746270, FUN_0075d330, FUN_009701d0, FUN_00989e00, FUN_0098d870.
//  - Strings: "ZFill"; ",0x4d,1,

                   "; "PalZFill.fx"; ",0x62,1,

                 ".
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

uint32_t /* width from decompiler */ __fastcall FUN_0098d870(int param_1)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = param_1;

  FUN_00746270(&local_4,"ZFill");

  if ((short)local_4 < 0) {

    *(uint8_t *)(DAT_00d1f044 + 0x780) = 0;

    return 0xffffffff;

  }

  piVar4 = *(int **)(in_EAX + 0x10);

  if (piVar4 != *(int **)(in_EAX + 0x14)) {

    do {

      iVar1 = *piVar4;

      if (*(int *)(iVar1 + 0x1c) == (int)local_4._2_2_) goto LAB_0098d8d0;

      piVar4 = piVar4 + 1;

    } while (piVar4 != *(int **)(in_EAX + 0x14));

  }

  iVar1 = 0;

LAB_0098d8d0:

  iVar3 = *(int *)(iVar1 + 0x2c);

  if (((iVar3 != 0) && (local_4 = *(int *)(iVar1 + 0x30) - iVar3 >> 4, local_4 != 0)) &&

     (*(int *)(iVar3 + 4) != 2)) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxSubPhaseZFill.cpp",0x4d,1,

                   "Z-Fill Phase Effect not present, Z-Fill disabled.");

    *(uint8_t *)(DAT_00d1f044 + 0x780) = 0;

    return 0xffffffff;

  }

  piVar4 = *(int **)(iVar1 + 0x20);

  *(int **)(param_1 + 0x20) = piVar4;

  piVar4[1] = piVar4[1] + 1;

  if (piVar4[1] == 1) {

    (**(code **)(*piVar4 + 4))();

  }

  uVar2 = FUN_004450d0();

  iVar1 = FUN_0075d330(uVar2);

  FUN_00989e00(&local_4,"PalZFill.fx");

  iVar3 = FUN_009701d0(&local_4);

  local_4 = FUN_004450d0();

  if (iVar1 != 0) {

    piVar4 = (int *)FUN_0043bd40();

    *piVar4 = iVar1;

    piVar4[1] = 0;

  }

  if (-1 < iVar3) {

    return 0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxSubPhaseZFill.cpp",0x62,1,

                 "Z-Fill Techniques Effect not present, Z-Fill disabled.");

  *(uint8_t *)(DAT_00d1f044 + 0x780) = 0;

  return 0xffffffff;

}
