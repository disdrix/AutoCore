// =============================================================================
// FUN_006f3390
// -----------------------------------------------------------------------------
// Stable ID: aa_006f3390
// Address:   0x006f3390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f3390 @ 0x006f3390
// Stable ID: aa_006f3390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×15, return×5, while×1, for×1.
//  - Notable callees: FUN_006f3390×4, FUN_006f1d20×2, FUN_006f1d70×2, FUN_006f1f30×2, FUN_006f2290×2, FUN_006f1da0, FUN_006f1dd0, FUN_006f1eb0.
//  - Return sites: 5.

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

int __thiscall FUN_006f3390(int param_1,int param_2,int param_3,int *param_4)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  int *piVar4;

  int *piVar5;

  uint8_t local_85;

  int local_84;

  int local_80;

  int local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  int local_6c;

  int local_68;

  char local_64 [20];

  int local_50 [19];

  

  if (*(char *)(param_2 + 0x38) != '\0') {

    return 3;

  }

  if (((*(int *)(param_1 + 0x14) < *param_4) || ((char)param_4[1] != '\0')) ||

     (*param_4 % *(int *)(param_1 + 0x70) != 0)) {

    if (*(char *)(param_2 + 4) == '\0') {

      local_64[0] = '\0';

      if (*(char *)(param_2 + 0x3c) == '\x01') {

        FUN_006f22e0(param_3,param_4,local_64);

      }

      FUN_006f1dd0(param_2,param_3,param_4);

      local_78 = FUN_006f28c0(*(uint32_t /* width from decompiler */ *)(param_2 + 0xb8));

      FUN_006f29f0(param_2,param_4,&local_74,&local_70);

      local_7c = 0xffffffff;

      local_84 = -1;

      local_80 = *(int *)(param_2 + 0xf0);

      if (local_80 != 0) {

        FUN_006f2290(param_4,local_80,param_1 + 0x30);

        local_84 = FUN_006f3390(local_80,param_4,local_50);

        if (-1 < local_84) {

          local_7c = *(uint32_t /* width from decompiler */ *)(local_80 + 0x5c);

          FUN_006f1d20(local_80);

        }

      }

      local_80 = *(int *)(param_2 + 0xec);

      if (local_80 != 0) {

        FUN_006f2290(param_4,local_80,param_1 + 0x30);

        local_68 = FUN_006f3390(local_80,param_4,local_50);

        iVar2 = local_80;

        if (-1 < local_68) {

          local_80 = *(uint32_t /* width from decompiler */ *)(local_80 + 0x5c);

          FUN_006f1d20(iVar2);

          if ((-1 < local_84) &&

             (pcVar3 = (char *)FUN_006f1da0(&local_85,param_2,param_4), *pcVar3 != '\0')) {

            FUN_006f1d70(param_2);

            *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;

            local_6c = *(int *)(*(int *)(param_1 + 0x10) + 0xc);

            FUN_006f2750(local_70,local_74,local_78,local_80,local_7c);

            iVar2 = param_4[0xd] - *(int *)(param_3 + 0x34);

            if (iVar2 != 0) {

              FUN_006f1ef0(iVar2);

            }

            FUN_006f2010(param_2,param_3,param_4);

            FUN_006f1f30(param_2,param_4);

            if (local_64[0] != '\0') {

              FUN_006f1eb0(local_64);

            }

            *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0xc);

            *(uint8_t *)(param_2 + 0x38) = 1;

            return (*(int *)(*(int *)(param_1 + 0x10) + 0xc) - local_6c) + local_68 + local_84;

          }

        }

      }

    }

    else {

      FUN_006f1d70(param_2);

      if ((*(int *)(param_2 + 8) < 0x16) || (*(int *)(param_1 + 0x14) < *param_4)) {

        *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;

        local_7c = *(int *)(*(int *)(param_1 + 0x10) + 0xc);

        FUN_006f2060(param_2,param_3,param_4);

        FUN_006f1f30(param_2,param_4);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x5c) = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + 0xc);

        iVar2 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);

        *(uint8_t *)(param_2 + 0x38) = 1;

        return iVar2 - local_7c;

      }

    }

    return -1;

  }

  *(uint8_t *)(param_4 + 1) = 1;

  local_80 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  iVar2 = -1;

  cVar1 = *(char *)(param_2 + 0x38);

  while (cVar1 == '\0') {

    local_7c = *(int *)(*(int *)(param_1 + 0x10) + 0xc);

    piVar4 = param_4;

    piVar5 = local_50;

    for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {

      *piVar5 = *piVar4;

      piVar4 = piVar4 + 1;

      piVar5 = piVar5 + 1;

    }

    iVar2 = FUN_006f3390(param_2,param_3,local_50);

    if (*(int *)(param_1 + 0x20) < *(int *)(param_1 + 0x24)) break;

    if (local_7c == *(int *)(*(int *)(param_1 + 0x10) + 0xc)) {

      if (*(int *)(param_1 + 0x14) < 0) break;

      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x70);

    }

    cVar1 = *(char *)(param_2 + 0x38);

  }

  *(int *)(param_1 + 0x14) = local_80;

  *(uint8_t *)(param_4 + 1) = 0;

  return iVar2;

}
