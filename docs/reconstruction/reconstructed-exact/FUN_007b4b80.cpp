// =============================================================================
// FUN_007b4b80
// -----------------------------------------------------------------------------
// Stable ID: aa_007b4b80
// Address:   0x007b4b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007b4b80 @ 0x007b4b80
// Stable ID: aa_007b4b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~208 non-empty decompiler lines.
//  - Control keywords: if×19, return×9, while×9, do×7, goto×1.
//  - Notable callees: CONCAT11×2, CONCAT13×2, FUN_0040aeb0×2, FUN_00759730×2, CONCAT12, CONCAT21, FUN_00423f40, FUN_004294f0.
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

void __fastcall FUN_007b4b80(int *param_1)



{

  char cVar1;

  byte *pbVar2;

  uint uVar3;

  int *piVar4;

  char *pcVar5;

  char *pcVar6;

  int iVar7;

  uint uVar8;

  char *pcVar9;

  int iVar10;

  bool bVar11;

  int iStack_48;

  char *pcStack_44;

  int iStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  int iStack_34;

  int iStack_30;

  uint32_t /* width from decompiler */ local_18;

  int *local_14;

  uint local_10;

  uint8_t *local_c;

  int local_8;

  int local_4;

  

  if (param_1[0x83] == 0) {

    if (param_1[0xa4] == 0) {

      return;

    }

    pcVar6 = (char *)param_1[0x9d];

    if (pcVar6 == (char *)0x0) {

      return;

    }

    pcVar5 = pcVar6 + 1;

    do {

      cVar1 = *pcVar6;

      pcVar6 = pcVar6 + 1;

    } while (cVar1 != '\0');

    local_c = (uint8_t *)((int)pcVar6 - (int)pcVar5);

    if (local_c == (uint8_t *)0x0) {

      return;

    }

    local_4 = param_1[0x5d] / 2;

    iVar10 = param_1[0x5c] / 2;

    local_8 = iVar10;

    if (*(char *)((int)param_1 + 0xb9) != '\0') {

      if (param_1[0xa3] == 0) {

        iVar7 = (**(code **)(*param_1 + 0x210))();

        param_1[0xa3] = iVar7;

      }

      iStack_34 = param_1[0xa3];

      uStack_38 = 0x7b4e70;

      iStack_30 = iVar10;

      (**(code **)(*param_1 + 0x194))();

      return;

    }

    pbVar2 = (byte *)param_1[0x89];

    local_18 = param_1[0x8b];

    if (pbVar2 != (byte *)0x0) {

      local_c = (uint8_t *)(((uint)pbVar2[1] * (local_18 >> 8 & 0xff)) / 0xff);

      local_18 = CONCAT13((char)(((uint)pbVar2[3] * (local_18 >> 0x18)) / 0xff),

                          CONCAT21(CONCAT11((char)(((uint)pbVar2[2] * (local_18 >> 0x10 & 0xff)) /

                                                  0xff),local_c._0_1_),

                                   (char)(((uint)*pbVar2 * (local_18 & 0xff)) / 0xff)));

    }

    pcVar5 = (char *)param_1[0x9d];

    pcVar6 = pcVar5 + 1;

    do {

      cVar1 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar1 != '\0');

    if ((uint)((int)pcVar5 - (int)pcVar6) <= (uint)param_1[0x46]) {

      return;

    }

    pcVar6 = (char *)param_1[0x9d];

    if (*(char *)((int)param_1 + 0xcb) != '\0') {

      pcVar5 = pcVar6 + 1;

      do {

        cVar1 = *pcVar6;

        pcVar6 = pcVar6 + 1;

      } while (cVar1 != '\0');

      iStack_30 = 0x7b4f74;

      pcVar6 = operator_new__((uint)(pcVar6 + (1 - (int)pcVar5)));

      pcVar5 = (char *)param_1[0x9d];

      pcVar9 = pcVar6;

      do {

        cVar1 = *pcVar5;

        *pcVar9 = cVar1;

        pcVar5 = pcVar5 + 1;

        pcVar9 = pcVar9 + 1;

      } while (cVar1 != '\0');

      cVar1 = *pcVar6;

      pcVar5 = pcVar6;

      while (cVar1 != '\0') {

        *pcVar5 = '*';

        pcVar5 = pcVar5 + 1;

        cVar1 = *pcVar5;

      }

    }

    iStack_30 = param_1[0x4c];

    iStack_48 = param_1[0x47];

    iStack_34 = 1;

    uStack_38 = 0;

    uStack_3c = 0;

    pcStack_44 = pcVar6 + param_1[0x46];

    local_c = (uint8_t *)&iStack_48;

    iStack_40 = iStack_48;

    FUN_0040aeb0(&iStack_48);

    FUN_00759730(param_1,&local_8,&local_18);

    if (pcVar6 == (char *)0x0) {

      return;

    }

    bVar11 = pcVar6 == (char *)param_1[0x9d];

LAB_007b4ff0:

    if (!bVar11) {

      iStack_30 = 0x7b4ff8;

      operator_delete__(pcVar6);

    }

    return;

  }

  local_4 = param_1[0x5d] / 2;

  iVar10 = param_1[0x5c] / 2;

  local_8 = iVar10;

  if ((param_1[0x83] == 1) && (*(char *)((int)param_1 + 0xb9) == '\0')) {

    local_18 = param_1[0x8b];

    local_14 = (int *)0x0;

    local_c = (uint8_t *)0x0;

    pbVar2 = (byte *)param_1[0x89];

    if (pbVar2 != (byte *)0x0) {

      uVar8 = local_18 >> 0x18;

      uVar3 = local_18 >> 0x10;

      local_10 = ((uint)pbVar2[1] * (local_18 >> 8 & 0xff)) / 0xff;

      local_18._0_2_ =

           CONCAT11((uint8_t)local_10,(char)(((uint)*pbVar2 * (local_18 & 0xff)) / 0xff));

      local_18 = CONCAT13((char)((pbVar2[3] * uVar8) / 0xff),

                          CONCAT12((char)(((uint)pbVar2[2] * (uVar3 & 0xff)) / 0xff),

                                   (uint16_t)local_18));

    }

    FUN_004294f0();

    iStack_30 = 0x7b4ca8;

    FUN_00423f40();

    if ((char)param_1[0x84] != '\0') {

      *(uint8_t *)(param_1 + 0x84) = 0;

      iStack_30 = 0x7b4cbc;

      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x7b));

    }

    piVar4 = local_14;

    if (((param_1[0xa4] != 0) && (local_14 != (int *)0x0)) && (*local_14 == 1)) {

      pcVar6 = (char *)local_14[1];

      pcVar5 = pcVar6;

      do {

        cVar1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

      } while (cVar1 != '\0');

      if ((uint)param_1[0x46] < (uint)((int)pcVar5 - (int)(pcVar6 + 1))) {

        if (*(char *)((int)param_1 + 0xcb) != '\0') {

          pcVar5 = pcVar6 + 1;

          do {

            cVar1 = *pcVar6;

            pcVar6 = pcVar6 + 1;

          } while (cVar1 != '\0');

          iStack_30 = 0x7b4d24;

          pcVar6 = operator_new__((uint)(pcVar6 + (1 - (int)pcVar5)));

          pcVar5 = (char *)piVar4[1];

          pcVar9 = pcVar6;

          do {

            cVar1 = *pcVar5;

            *pcVar9 = cVar1;

            pcVar5 = pcVar5 + 1;

            pcVar9 = pcVar9 + 1;

          } while (cVar1 != '\0');

          cVar1 = *pcVar6;

          pcVar5 = pcVar6;

          while (cVar1 != '\0') {

            *pcVar5 = '*';

            pcVar5 = pcVar5 + 1;

            cVar1 = *pcVar5;

          }

        }

        iStack_48 = param_1[0x4c];

        iStack_40 = param_1[0x47];

        iStack_34 = 1;

        uStack_38 = 0;

        uStack_3c = 0;

        pcStack_44 = pcVar6 + param_1[0x46];

        local_c = (uint8_t *)&iStack_48;

        iStack_30 = iStack_48;

        FUN_0040aeb0(&iStack_48);

        FUN_00759730(param_1,&local_8,&local_18);

        if (pcVar6 == (char *)0x0) {

          return;

        }

        bVar11 = pcVar6 == (char *)local_14[1];

        goto LAB_007b4ff0;

      }

    }

  }

  if (param_1[0xa3] == 0) {

    iVar7 = (**(code **)(*param_1 + 0x210))();

    param_1[0xa3] = iVar7;

  }

  iStack_34 = param_1[0xa3];

  uStack_38 = 0x7b4ddb;

  iStack_30 = iVar10;

  (**(code **)(*param_1 + 0x194))();

  return;

}
