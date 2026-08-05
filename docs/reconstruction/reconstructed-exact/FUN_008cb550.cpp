// =============================================================================
// FUN_008cb550
// -----------------------------------------------------------------------------
// Stable ID: aa_008cb550
// Address:   0x008cb550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008cb550 @ 0x008cb550
// Stable ID: aa_008cb550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~110 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×2.
//  - Notable callees: FUN_008ca6c0×2, FUN_00728840, FUN_008cb550.
//  - Return sites: 2.

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

void FUN_008cb550(void)



{

  int *piVar1;

  int *piVar2;

  int iVar3;

  int *unaff_ESI;

  uint64_t uVar4;

  

  piVar1 = unaff_ESI + 0x15d;

  unaff_ESI[0x156] = 0;

  iVar3 = 0x10;

  piVar2 = piVar1;

  do {

    piVar2[-4] = -1;

    *(uint8_t *)piVar2 = 0;

    *(uint16_t *)(piVar2 + -2) = 0;

    piVar2 = piVar2 + 0xf;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  FUN_008ca6c0();

  if (DAT_00d1a8e6 == '\0') {

    if (DAT_00d1a90c != 0) {

      FUN_00728840(DAT_00d1a90c,DAT_00d1a958,DAT_00d1a95c);

    }

    return;

  }

  unaff_ESI[0x156] = 1;

  iVar3 = 0x10;

  piVar2 = piVar1;

  do {

    piVar2[-4] = -1;

    *(uint8_t *)piVar2 = 0;

    *(uint16_t *)(piVar2 + -2) = 0;

    piVar2[-1] = 0x9c4;

    piVar2[-3] = 999;

    *(uint8_t *)((int)piVar2 + -0x12) = 0;

    *(uint8_t *)((int)piVar2 + -0x11) = 0;

    *(uint8_t *)((int)piVar2 + -0x13) = 0;

    *(uint8_t *)(piVar2 + -5) = 0;

    piVar2 = piVar2 + 0xf;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  unaff_ESI[0x159] = 0x7b;

  *(uint16_t *)(unaff_ESI + 0x15b) = 0x45;

  *piVar1 = s_Pumpkin_00a41ef4._0_4_;

  unaff_ESI[0x15e] = s_Pumpkin_00a41ef4._4_4_;

  unaff_ESI[0x15a] = 0x87;

  *(uint8_t *)((int)unaff_ESI + 0x562) = 1;

  unaff_ESI[0x168] = 0x1c8;

  *(uint16_t *)(unaff_ESI + 0x16a) = 0x985;

  unaff_ESI[0x16c] = DAT_00a41eec;

  *(uint8_t *)(unaff_ESI + 0x16d) = DAT_00a41ef0;

  unaff_ESI[0x169] = 0x17a;

  unaff_ESI[0x177] = 0x315;

  *(uint16_t *)(unaff_ESI + 0x179) = 3999;

  unaff_ESI[0x17b] = s_LittleLamb_00a41ee0._0_4_;

  unaff_ESI[0x17c] = s_LittleLamb_00a41ee0._4_4_;

  *(uint16_t *)(unaff_ESI + 0x17d) = s_LittleLamb_00a41ee0._8_2_;

  *(char *)((int)unaff_ESI + 0x5f6) = s_LittleLamb_00a41ee0[10];

  *(uint8_t *)((int)unaff_ESI + 0x5d9) = 1;

  *(uint8_t *)((int)unaff_ESI + 0x5db) = 1;

  *(uint8_t *)(unaff_ESI + 0x176) = 1;

  unaff_ESI[0x178] = 0x2ea;

  *(uint16_t *)(unaff_ESI + 0x188) = 3999;

  unaff_ESI[0x186] = 0x316;

  unaff_ESI[0x18a] = DAT_00a41ed0;

  unaff_ESI[0x18b] = DAT_00a41ed4;

  unaff_ESI[0x18c] = DAT_00a41ed8;

  unaff_ESI[0x18d] = DAT_00a41edc;

  unaff_ESI[0x187] = 0x2ea;

  *(uint8_t *)((int)unaff_ESI + 0x615) = 1;

  *(uint8_t *)((int)unaff_ESI + 0x617) = 1;

  *(uint8_t *)(unaff_ESI + 0x185) = 1;

  *(uint16_t *)(unaff_ESI + 0x197) = 3999;

  unaff_ESI[0x195] = 0x317;

  unaff_ESI[0x199] = DAT_00a41ebc;

  unaff_ESI[0x19a] = DAT_00a41ec0;

  unaff_ESI[0x19b] = DAT_00a41ec4;

  unaff_ESI[0x19c] = DAT_00a41ec8;

  *(uint8_t *)(unaff_ESI + 0x19d) = DAT_00a41ecc;

  unaff_ESI[0x196] = 0x2ea;

  *(uint8_t *)((int)unaff_ESI + 0x651) = 1;

  *(uint8_t *)((int)unaff_ESI + 0x653) = 1;

  *(uint8_t *)(unaff_ESI + 0x194) = 1;

  unaff_ESI[0x1a4] = 0x2c7;

  *(uint16_t *)(unaff_ESI + 0x1a6) = 399;

  unaff_ESI[0x1a8] = s_Wastelands___RP_West__00a41ea4._0_4_;

  unaff_ESI[0x1a9] = s_Wastelands___RP_West__00a41ea4._4_4_;

  unaff_ESI[0x1aa] = s_Wastelands___RP_West__00a41ea4._8_4_;

  unaff_ESI[0x1ab] = s_Wastelands___RP_West__00a41ea4._12_4_;

  unaff_ESI[0x1ac] = s_Wastelands___RP_West__00a41ea4._16_4_;

  *(uint16_t *)(unaff_ESI + 0x1ad) = s_Wastelands___RP_West__00a41ea4._20_2_;

  unaff_ESI[0x1a5] = 0x2ea;

  *(uint8_t *)((int)unaff_ESI + 0x68d) = 1;

  *(uint8_t *)((int)unaff_ESI + 0x68f) = 1;

  *(uint8_t *)(unaff_ESI + 0x1a3) = 1;

  if ((int *)unaff_ESI[0x252] != (int *)0x0) {

    uVar4 = (**(code **)(*(int *)unaff_ESI[0x252] + 0x44c))();

    *(uint64_t *)(unaff_ESI + 0x154) = uVar4;

  }

  FUN_008ca6c0();

  if ((int *)unaff_ESI[0x252] != (int *)0x0) {

    (**(code **)(*(int *)unaff_ESI[0x252] + 0x448))(unaff_ESI[0x154],unaff_ESI[0x155]);

    uVar4 = (**(code **)(*(int *)unaff_ESI[0x252] + 0x44c))();

    *(uint64_t *)(unaff_ESI + 0x154) = uVar4;

  }

                    /* WARNING: Could not recover jumptable at 0x008cb83a. Too many branches */

                    /* WARNING: Treating indirect jump as call */

  (**(code **)(*unaff_ESI + 0x34c))();

  return;

}
