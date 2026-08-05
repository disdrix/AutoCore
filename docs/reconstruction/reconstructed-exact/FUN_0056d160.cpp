// =============================================================================
// FUN_0056d160
// -----------------------------------------------------------------------------
// Stable ID: aa_0056d160
// Address:   0x0056d160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0056d160 @ 0x0056d160
// Stable ID: aa_0056d160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~165 non-empty decompiler lines.
//  - Control keywords: if×25, return×11, goto×3, do×1, while×1.
//  - Notable callees: FUN_004b8dc0×6, FUN_004b7550×4, FUN_004ec010×3, FUN_004b7e50×2, CONCAT11, CONCAT12, CONCAT13, FUN_004b68c0.
//  - Return sites: 11.

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

uint __thiscall FUN_0056d160(void *param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  short sVar2;

  ushort uVar3;

  uint16_t uVar4;

  bool bVar5;

  int iVar6;

  uint uVar7;

  char cVar8;

  int *piVar9;

  float fVar10;

  uint8_t local_c;

  char cStack_b;

  byte bStack_a;

  uint8_t uStack_9;

  uint8_t uStack_8;

  

  if ((*(char *)((int)param_1 + 0xb2) == '\0') &&

     (*(uint8_t *)((int)param_1 + 0xb2) = 1, *(int *)((int)param_1 + 0xbc) == 0)) {

    iVar6 = FUN_004ec010(8);

    *(int *)((int)param_1 + 0xbc) = iVar6;

    if (iVar6 != 0) {

      FUN_004b73c0(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1);

      *(uint32_t /* width from decompiler */ *)(*(int *)((int)param_1 + 0xbc) + 0x2c) =

           *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 0xa8 + (int)param_1);

      FUN_004b8dc0(0,0);

    }

  }

  if ((*(byte *)((int)param_1 + 0xc4) & 0x80) == 0) {

    if ((*(char *)((int)param_1 + 199) == '\0') || (*(char *)((int)param_1 + 0xcb) != '\0')) {

      uVar7 = 0;

    }

    else {

      uVar7 = 1;

    }

    if ((*(int *)((int)param_1 + 0xbc) == 0) || (*(char *)((int)param_1 + 0xb1) == '\0')) {

      if ((char)uVar7 == '\0') {

        return uVar7;

      }

    }

    else if ((char)uVar7 == '\0') {

      uVar3 = *(ushort *)((int)param_1 + 0xb4);

      *(ushort *)((int)param_1 + 0xb4) = uVar3 + 1;

      if (uVar3 != 5) {

        return (uint)uVar3;

      }

      *(uint8_t *)((int)param_1 + 0xb1) = 0;

      uVar7 = FUN_004b8dc0(0,0);

      *(uint16_t *)((int)param_1 + 0xb4) = 0;

      return uVar7;

    }

    if (param_3 != '\0') {

      return uVar7;

    }

    if (*(int *)((int)param_1 + 0xbc) != 0) {

      *(uint8_t *)((int)param_1 + 0xb1) = 1;

      FUN_004b8dc0(1,0);

    }

    iVar6 = FUN_004ec010(4);

    if (iVar6 == 0) {

      return 0;

    }

    local_c = 0;

    cStack_b = 0;

    bStack_a = 0;

    uStack_9 = 0;

    FUN_004b7550(&local_c,1);

    uVar1 = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0xe8);

    local_c = (uint8_t)uVar1;

    cStack_b = (char)((uint)uVar1 >> 8);

    bStack_a = (byte)((uint)uVar1 >> 0x10);

    uStack_9 = (uint8_t)((uint)uVar1 >> 0x18);

    FUN_004b7550(&local_c,2);

    fVar10 = (g_flOne - *(float *)((int)param_1 + 0xdc)) * DAT_00a0f298;

    local_c = SUB41(fVar10,0);

    cStack_b = (char)((uint)fVar10 >> 8);

    bStack_a = (byte)((uint)fVar10 >> 0x10);

    uStack_9 = (uint8_t)((uint)fVar10 >> 0x18);

    FUN_004b7550(&local_c,3);

    uVar1 = *(uint32_t /* width from decompiler */ *)((int)param_1 + 0xe0);

    local_c = (uint8_t)uVar1;

    cStack_b = (char)((uint)uVar1 >> 8);

    bStack_a = (byte)((uint)uVar1 >> 0x10);

    uStack_9 = (uint8_t)((uint)uVar1 >> 0x18);

    FUN_004b7550(&local_c,4);

    (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 0xf8))

              (iVar6,1,0);

    FUN_004b7e50(0,0,0,0,0,0);

    iVar6 = (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) +

                        0x210))(0);

    if (iVar6 == 0) {

      return 0;

    }

    iVar6 = *(int *)(*(int *)(*(int *)(iVar6 + 4) + 4) + 0xa4 + iVar6);

    if (iVar6 == 0) {

      return 0;

    }

    FUN_004b68c0(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x164),

                 *(uint32_t /* width from decompiler */ *)(iVar6 + 0x168),*(uint32_t /* width from decompiler */ *)(iVar6 + 0x16c),&DAT_00b047c0);

    uVar7 = FUN_004b75d0();

    return uVar7;

  }

  bVar5 = Weapon_CanFireHeatCheck(param_1);

  if (*(int *)((int)param_1 + 0xbc) == 0) {

LAB_0056d24f:

    if ((*(char *)((int)param_1 + 199) != '\0') && (bVar5)) {

      cVar8 = '\x01';

      goto LAB_0056d262;

    }

  }

  else {

    if (*(char *)((int)param_1 + 0xb1) != '\0') {

      sVar2 = *(short *)((int)param_1 + 0xb4);

      *(short *)((int)param_1 + 0xb4) = sVar2 + 1;

      if (sVar2 == 2) {

        *(uint8_t *)((int)param_1 + 0xb1) = 0;

        FUN_004b8dc0(0,0);

        *(uint16_t *)((int)param_1 + 0xb4) = 0;

      }

      goto LAB_0056d24f;

    }

    if (*(char *)((int)param_1 + 199) != '\0') {

      if (bVar5) {

        *(uint8_t *)((int)param_1 + 0xb1) = 1;

        FUN_004b8dc0(1,0);

      }

      goto LAB_0056d24f;

    }

  }

  cVar8 = '\0';

LAB_0056d262:

  cStack_b = cVar8;

  (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 0x198))();

  bStack_a = *(byte *)((int)param_1 + 0xcb);

  if (cVar8 == *(char *)((int)param_1 + 0xca)) {

    return (uint)bStack_a;

  }

  if (cVar8 == '\0') {

    if (bStack_a != 0) {

      return (uint)bStack_a;

    }

    iVar6 = FUN_004ec010(7);

    if (iVar6 != 0) {

      (**(code **)(*(int *)(*(int *)(*(int *)((int)param_1 + 4) + 4) + 4 + (int)param_1) + 0xf8))

                (iVar6,1,0);

      FUN_004b7e50(0,0,0,0,0,0);

    }

    FUN_00569cb0();

  }

  iVar6 = *(int *)(*(int *)((int)param_1 + 4) + 4);

  piVar9 = *(int **)(iVar6 + 0x128 + (int)param_1);

  uVar7 = iVar6 + (int)param_1;

  if (piVar9 != *(int **)(iVar6 + 300 + (int)param_1)) {

    uVar4 = CONCAT11(bStack_a,cStack_b);

    do {

      if (*(int *)(*piVar9 + 0x28) == 4) {

        FUN_004b8dc0(CONCAT13(uStack_8,CONCAT12(uStack_9,uVar4)),0);

      }

      uVar7 = *(uint *)(*(int *)((int)param_1 + 4) + 4);

      piVar9 = piVar9 + 1;

    } while (piVar9 != *(int **)(uVar7 + 300 + (int)param_1));

  }

  *(char *)((int)param_1 + 0xca) = cVar8;

  return uVar7;

}
