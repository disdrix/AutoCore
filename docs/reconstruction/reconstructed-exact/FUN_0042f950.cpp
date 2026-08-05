// =============================================================================
// FUN_0042f950
// -----------------------------------------------------------------------------
// Stable ID: aa_0042f950
// Address:   0x0042f950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042f950 @ 0x0042f950
// Stable ID: aa_0042f950
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Received Arranged Connect Request"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~251 non-empty decompiler lines.
//  - Control keywords: if×35, do×7, while×7, return×7, goto×2.
//  - Notable callees: BitStream_readBits×4, FUN_0042bdf0×3, FUN_0042bd10×2, FUN_0042c540×2, FUN_0042e5b0×2, FUN_007838a0×2, FUN_0040b290, FUN_00426b40.
//  - Strings: "LogNetInterface"; "Received Arranged Connect Request".
//  - Return sites: 7.

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



void FUN_0042f950(int *param_1,int *param_2,int *param_3)



{

  int *piVar1;

  byte bVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  char cVar5;

  short *psVar6;

  uint32_t /* width from decompiler */ uVar7;

  void *pvVar8;

  int iVar9;

  int iVar10;

  int *piVar11;

  int *piVar12;

  int *piVar13;

  bool bVar14;

  int *local_510;

  int *local_50c;

  int *local_508;

  uint32_t /* width from decompiler */ uStack_504;

  int *local_500;

  int local_4fc [3];

  uint8_t local_4f0 [4];

  uint32_t /* width from decompiler */ *local_4ec;

  uint8_t auStack_278 [632];

  

  local_50c = (int *)0x0;

  BitStream_readBits(0x40,local_4fc);

  local_4fc[2] = FUN_0042c6c0();

  if (local_4fc[2] != 0) {

    iVar9 = 2;

    bVar14 = true;

    piVar11 = (int *)(local_4fc[2] + 0x138);

    piVar12 = local_4fc;

    do {

      if (iVar9 == 0) break;

      iVar9 = iVar9 + -1;

      bVar14 = *piVar11 == *piVar12;

      piVar11 = piVar11 + 1;

      piVar12 = piVar12 + 1;

    } while (bVar14);

    if (bVar14) {

      FUN_0042e5b0(param_1,*(uint32_t /* width from decompiler */ *)(local_4fc[2] + 0x10c));

      return;

    }

  }

  local_510 = (int *)param_1[9];

  local_508 = (int *)0x0;

  if (0 < (int)local_510) {

    local_500 = (int *)param_1[0xb];

    do {

      local_50c = (int *)*local_500;

      iVar9 = 2;

      if ((local_50c[0x6e] == 2) && ((char)local_50c[0x65] == '\0')) {

        bVar14 = true;

        piVar11 = local_4fc;

        piVar12 = local_50c + 0x4e;

        do {

          if (iVar9 == 0) break;

          iVar9 = iVar9 + -1;

          bVar14 = *piVar11 == *piVar12;

          piVar11 = piVar11 + 1;

          piVar12 = piVar12 + 1;

        } while (bVar14);

        if (bVar14) {

          iVar9 = local_50c[0x62];

          iVar10 = 0;

          if (0 < iVar9) {

            psVar6 = (short *)local_50c[100];

            do {

              if (((((short)*param_2 == *psVar6) && (param_2[1] == *(int *)(psVar6 + 2))) &&

                  (param_2[2] == *(int *)(psVar6 + 4))) &&

                 ((param_2[3] == *(int *)(psVar6 + 6) && (param_2[4] == *(int *)(psVar6 + 8)))))

              break;

              iVar10 = iVar10 + 1;

              psVar6 = psVar6 + 10;

            } while (iVar10 < iVar9);

          }

          if (iVar10 != iVar9) break;

        }

      }

      local_508 = (int *)((int)local_508 + 1);

      local_500 = local_500 + 1;

    } while ((int)local_508 < (int)local_510);

  }

  piVar11 = local_50c;

  if (local_508 == local_510) {

    return;

  }

  FUN_007838a0();

  cVar5 = FUN_0042bd10(param_3,5,local_4f0);

  if (cVar5 == '\0') {

    if (local_4ec == (uint32_t /* width from decompiler */ *)0x0) {

      return;

    }

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)local_4ec[2];

      *local_4ec = 0;

      local_4ec[1] = 0;

      local_4ec[2] = 0;

      local_4ec = puVar3;

    } while (puVar3 != (uint32_t /* width from decompiler */ *)0x0);

    return;

  }

  param_3[6] = param_3[6] + 7U & 0xfffffff8;

  BitStream_readBits(0x40,local_4fc);

  iVar9 = 2;

  bVar14 = true;

  piVar12 = local_4fc;

  piVar13 = piVar11 + 0x50;

  do {

    if (iVar9 == 0) break;

    iVar9 = iVar9 + -1;

    bVar14 = *piVar12 == *piVar13;

    piVar12 = piVar12 + 1;

    piVar13 = piVar13 + 1;

  } while (bVar14);

  if (!bVar14) {

    if (local_4ec == (uint32_t /* width from decompiler */ *)0x0) {

      return;

    }

    do {

      puVar3 = (uint32_t /* width from decompiler */ *)local_4ec[2];

      *local_4ec = 0;

      local_4ec[1] = 0;

      local_4ec[2] = 0;

      local_4ec = puVar3;

    } while (puVar3 != (uint32_t /* width from decompiler */ *)0x0);

    return;

  }

  uVar4 = param_3[6];

  if ((uint)param_3[0xb] < uVar4) {

    *(uint8_t *)(param_3 + 7) = 1;

  }

  else {

    local_510 = param_3;

    bVar2 = *(byte *)((uVar4 >> 3) + param_3[3]);

    param_3[6] = uVar4 + 1;

    if ((bVar2 & (byte)(1 << ((byte)uVar4 & 7))) != 0) {

      *(uint8_t *)((int)piVar11 + 0x135) = 1;

      if (*(char *)((int)piVar11 + 0x136) == '\0') {

        if (param_1[0xf] == 0) goto LAB_0042fe47;

        pvVar8 = operator_new(0x24);

        if (pvVar8 == (void *)0x0) {

          iVar9 = 0;

        }

        else {

          iVar9 = FUN_0042be80(param_3);

        }

        piVar12 = (int *)piVar11[0x55];

        if (piVar12 != (int *)0x0) {

          piVar13 = piVar12 + 2;

          *piVar13 = *piVar13 + -1;

          if (*piVar13 == 0) {

            (**(code **)(*piVar12 + 8))();

          }

        }

        piVar11[0x55] = iVar9;

        if (iVar9 != 0) {

          *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + 1;

        }

        FUN_004300e0();

        param_3[6] = param_3[6] + 7U & 0xfffffff8;

        uVar7 = FUN_0098b790(piVar11[0x56],&local_510);

        FUN_00426b40(uVar7);

        FUN_0040b290();

        FUN_007838a0();

        cVar5 = FUN_0042bd10(param_3,5,auStack_278);

        if (cVar5 == '\0') {

          FUN_0042bdf0();

          goto LAB_0042fe47;

        }

        FUN_0042bdf0();

      }

      BitStream_readBits(0x80,(int)piVar11 + 0x166);

    }

  }

  piVar12 = local_50c;

  if (*(char *)((int)piVar11 + 0x135) != '\0') {

    FUN_00975f50((int)piVar11 + 0x176,0x10);

    pvVar8 = operator_new(0x274);

    if (pvVar8 == (void *)0x0) {

      iVar9 = 0;

    }

    else {

      iVar9 = FUN_007839b0();

    }

    piVar12 = local_50c;

    piVar13 = (int *)local_50c[0x6d];

    if (piVar13 != (int *)0x0) {

      piVar1 = piVar13 + 2;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar13 + 8))();

      }

    }

    piVar12[0x6d] = iVar9;

    if (iVar9 != 0) {

      *(int *)(iVar9 + 8) = *(int *)(iVar9 + 8) + 1;

    }

  }

  uVar4 = param_3[6];

  if ((uint)param_3[0xb] < uVar4) {

    *(uint8_t *)(param_3 + 7) = 1;

    bVar14 = false;

  }

  else {

    local_510 = param_3;

    bVar14 = (*(byte *)((uVar4 >> 3) + param_3[3]) & (byte)(1 << ((byte)uVar4 & 7))) != 0;

    param_3[6] = param_3[6] + 1;

  }

  *(bool *)(piVar11 + 0x67) = bVar14;

  BitStream_readBits(0x20,&local_510);

  if ((_DAT_00d217f4 & 1) == 0) {

    _DAT_00d217f4 = _DAT_00d217f4 | 1;

    DAT_00d217f0 = FUN_00783b60("LogNetInterface");

  }

  if (*(char *)(DAT_00d217f0 + 4) != '\0') {

    DAT_00d179a0 = DAT_00d217f0;

    FUN_00783aa0("Received Arranged Connect Request");

    DAT_00d179a0 = 0;

  }

  if (local_4fc[2] != 0) {

    FUN_0042fe60();

  }

  piVar12[0x3e] = *param_2;

  piVar12[0x3f] = param_2[1];

  piVar12[0x40] = param_2[2];

  piVar12[0x41] = param_2[3];

  piVar12[0x42] = param_2[4];

  piVar12[0x27] = (int)local_510;

  piVar12[0x23] = (int)local_510;

  piVar12[0x29] = (int)local_510;

  uStack_504 = 0;

  cVar5 = (**(code **)(*piVar12 + 0x24))(param_3,&uStack_504);

  if (cVar5 == '\0') {

    FUN_0042e9a0(param_1,piVar12[0x43],param_2);

    FUN_0042c540();

  }

  else {

    (**(code **)(*param_1 + 0xc))(piVar12);

    FUN_0042c540();

    piVar11 = local_510;

    local_510[0x6e] = 7;

    (**(code **)(*local_510 + 0x14))();

    FUN_0042e5b0(param_1,piVar11[0x43]);

  }

LAB_0042fe47:

  FUN_0042bdf0();

  return;

}
