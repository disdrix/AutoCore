// =============================================================================
// FUN_004d1680
// -----------------------------------------------------------------------------
// Stable ID: aa_004d1680
// Address:   0x004d1680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d1680 @ 0x004d1680
// Stable ID: aa_004d1680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: do×4, while×4, if×2, return×1.
//  - Notable callees: FUN_006c6280×2, FUN_004d1680, FUN_005a58c0, FUN_006c5c90, FUN_006c5f00, FUN_006c5f80, FUN_006c6110, FUN_006c6150.
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

uint32_t /* width from decompiler */ FUN_004d1680(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  float10 fVar5;

  float fVar6;

  int iStack_84;

  int iStack_80;

  float local_78;

  float fStack_74;

  float fStack_70;

  uint32_t /* width from decompiler */ uStack_6c;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  uint8_t auStack_58 [44];

  void *pvStack_2c;

  uint8_t uStack_24;

  void *pvStack_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  uStack_14 = 0xffffffff;

  puStack_18 = &LAB_009a1ffe;

  pvStack_1c = ExceptionList;

  ExceptionList = &pvStack_1c;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x34,0x22);

  *(uint16_t *)(iVar1 + 4) = 0x34;

  iVar1 = 0;

  pvStack_1c = (void *)0x0;

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_006c6af0();

  pvStack_1c = (void *)0xffffffff;

  FUN_006c6200(0x44800000);

  FUN_006c6210(9,8);

  do {

    fVar6 = (float)iVar1 * DAT_009cc4dc;

    iVar4 = 0;

    do {

      fStack_68 = fVar6;

      if (*(int *)(iStack_80 + 0xe4e0) == 0) {

        fStack_64 = 0.0;

      }

      else {

        fVar5 = (float10)FUN_005a58c0(fVar6,(float)iVar4 * DAT_009cc4dc);

        fStack_64 = (float)fVar5;

      }

      fStack_60 = (float)iVar4 * DAT_009cc4dc;

      FUN_006c64c0(&fStack_68);

      iVar4 = iVar4 + 1;

    } while (iVar4 < 3);

    iVar1 = iVar1 + 1;

  } while (iVar1 < 3);

  iStack_84 = 3;

  do {

    iStack_80 = 2;

    iVar1 = iStack_84;

    do {

      FUN_006c6280(iVar1 + -3,iVar1 + -2,iVar1);

      FUN_006c6280(iVar1 + -2,iVar1 + 1,iVar1);

      iStack_80 = iStack_80 + -1;

      iVar1 = iVar1 + 1;

    } while (iStack_80 != 0);

    iStack_84 = iStack_84 + 3;

  } while (iStack_84 < 9);

  FUN_006c6150();

  pvStack_1c = (void *)0x1;

  FUN_006c6110(0x3f000000);

  local_78 = g_flMultiKillCountBlend;

  fStack_74 = g_flMultiKillCountBlend;

  fStack_70 = g_flMultiKillCountBlend;

  uStack_6c = 0;

  FUN_006c6190(&local_78);

  uVar3 = FUN_006c5f80(puVar2,auStack_58);

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x14,0x22);

  *(uint16_t *)(iVar1 + 4) = 0x14;

  uStack_24 = 2;

  uVar3 = FUN_006c5f00(puVar2,uVar3);

  uStack_24 = 1;

  FUN_006c5c90();

  *(short *)((int)puVar2 + 6) = *(short *)((int)puVar2 + 6) + -1;

  if (*(short *)((int)puVar2 + 6) == 0) {

    (**(code **)*puVar2)(1);

  }

  ExceptionList = pvStack_2c;

  return uVar3;

}
