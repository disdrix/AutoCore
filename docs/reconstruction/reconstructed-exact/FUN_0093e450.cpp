// =============================================================================
// FUN_0093e450
// -----------------------------------------------------------------------------
// Stable ID: aa_0093e450
// Address:   0x0093e450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0093e450 @ 0x0093e450
// Stable ID: aa_0093e450
// Embedded strings (evidence for future rename):
//   - "Dialog has no choices from %I64d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~120 non-empty decompiler lines.
//  - Control keywords: if×17, return×10, goto×4, switch×1, do×1, while×1.
//  - Notable callees: FUN_005795b0×4, FUN_0092f090×3, TFID_NotEquals×3, FUN_008aa510×2, CVOGReaction_ResolveObjectTarget, FUN_0057a200, FUN_0057a250, FUN_0057a8e0.
//  - Strings: "Dialog has no choices from %I64d".
//  - Return sites: 10.

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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __thiscall FUN_0093e450(TFID_16 *param_1,int param_2)



{

  uint8_t *puVar1;

  int *piVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  uint64_t uVar7;

  void *pB;

  int local_1008;

  uint8_t local_1000 [4092];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x93e45a;

  iVar4 = CVOGReaction_ResolveObjectTarget(0,param_1[1].dwCoidLo,param_1[1].dwCoidHi);

  if (iVar4 == 0) {

    return;

  }

  local_1008 = 0;

  if (*(int *)(*(int *)(iVar4 + 0xa8) + 0x38) == 0x3a) {

    local_1008 = iVar4;

  }

  piVar5 = Object_ResolveFromTFID(param_1);

  if (local_1008 == 0) {

    return;

  }

  puVar1 = *(uint8_t **)(local_1008 + 600);

  if (puVar1 == (uint8_t *)0x0) {

    return;

  }

  if (piVar5 == (int *)0x0) goto LAB_0093e5ac;

  if (puVar1[1] == '\0') {

    iVar4 = TFID_NotEquals(piVar5 + 0x58,

                           (void *)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) + 0x164 +

                                   *(int *)(param_2 + 0xe98)));

    if ((char)iVar4 == '\0') goto LAB_0093e5ac;

    iVar4 = *(int *)(*(int *)(param_2 + 0xe98) + 0x250);

    pB = (void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x164 + iVar4);

  }

  else {

    if (puVar1[1] != '\x01') goto LAB_0093e5ac;

    iVar4 = (**(code **)(*piVar5 + 0x210))(0);

    if (iVar4 == 0) {

      return;

    }

    if (((*(int *)(iVar4 + 0xcb0) != 0) &&

        (*(int *)(iVar4 + 0xcb0) == *(int *)(*(int *)(param_2 + 0xe98) + 0xcb0))) ||

       (iVar4 = TFID_NotEquals(piVar5 + 0x58,

                               (void *)(*(int *)(*(int *)(*(int *)(param_2 + 0xe98) + 4) + 4) +

                                        0x164 + *(int *)(param_2 + 0xe98))), (char)iVar4 == '\0'))

    goto LAB_0093e5ac;

    iVar4 = *(int *)(*(int *)(param_2 + 0xe98) + 0x250);

    pB = (void *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 0x164 + iVar4);

  }

  iVar4 = TFID_NotEquals(piVar5 + 0x58,pB);

  if ((char)iVar4 != '\0') {

    return;

  }

LAB_0093e5ac:

  FUN_0057a8e0(local_1000,*(uint32_t /* width from decompiler */ *)(param_2 + 0xe98),piVar5);

  switch(*puVar1) {

  case 0:

    if ((*(int **)(param_2 + 0xf40) != (int *)0x0) &&

       (**(int **)(param_2 + 0xf40) == *(int *)(param_2 + 0xf38))) {

      piVar2 = *(int **)(param_2 + 0x1058);

      cVar3 = (**(code **)(*piVar2 + 0x3d8))();

      if (cVar3 == '\0') {

        FUN_007fef20(10,1,0);

        FUN_008ab550();

        piVar2[0x191] = 0;

        if ((int *)piVar2[0x1b6] != (int *)0x0) {

          (**(code **)(*(int *)piVar2[0x1b6] + 0x1d8))(&DAT_00a1419b,1,1);

          (**(code **)(*(int *)piVar2[0x1b6] + 0x34c))();

        }

        FUN_008aaf60();

        piVar2[0x19e] = *(int *)(local_1008 + 0x160);

        piVar2[0x19f] = *(int *)(local_1008 + 0x164);

        iVar4 = FUN_005795b0();

        if (iVar4 < 1) {

          FUN_007a4480(1,"Dialog has no choices from %I64d",*(uint32_t /* width from decompiler */ *)(local_1008 + 0x160),

                       *(uint32_t /* width from decompiler */ *)(local_1008 + 0x164));

          piVar2[0x144] = 1;

          FUN_008ac110();

          FUN_008aa510(0xffffffff,0xffffffff);

          FUN_0092f090();

          return;

        }

        FUN_005795b0();

        FUN_008ac890();

        iVar6 = 0;

        iVar4 = FUN_005795b0();

        if (0 < iVar4) {

          do {

            FUN_0057a200(iVar6,local_1000,*(uint32_t /* width from decompiler */ *)(param_2 + 0xe98),piVar5);

            uVar7 = FUN_0057a250(iVar6);

            FUN_008aa510(uVar7);

            iVar6 = iVar6 + 1;

            iVar4 = FUN_005795b0();

          } while (iVar6 < iVar4);

        }

        FUN_0092f090();

        return;

      }

    }

    break;

  case 1:

    FUN_007fdfb0(param_2,local_1000,0xffffffff,1,0);

    FUN_0092f090();

    return;

  case 2:

    FUN_007fde80(local_1000,0,0x3f800000,0x40000000,0);

    return;

  case 3:

    if (*(int *)(param_2 + 0x109c) != 0) {

      FUN_008f8200(*(int *)(param_2 + 0x109c),6,&DAT_00a1419b,local_1000,0);

    }

  }

  return;

}
