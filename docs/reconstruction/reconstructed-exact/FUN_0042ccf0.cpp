// =============================================================================
// FUN_0042ccf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0042ccf0
// Address:   0x0042ccf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042ccf0 @ 0x0042ccf0
// Stable ID: aa_0042ccf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~294 non-empty decompiler lines.
//  - Control keywords: if×26, while×10, do×4, for×3, return×2, goto×1.
//  - Notable callees: free×6, FUN_00785070×4, htonl×2, FUN_0042ccf0, FUN_007833a0, FUN_00783f40, FUN_007843e0, FUN_00784f20.
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

void __fastcall FUN_0042ccf0(int *param_1)



{

  int iVar1;

  int iVar2;

  void *pvVar3;

  void *pvVar4;

  uint uVar5;

  SOCKET SVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  void *local_75c;

  char local_755;

  SOCKET local_754;

  void *local_750;

  uint16_t local_74c;

  uint16_t local_74a;

  u_long local_748;

  uint32_t /* width from decompiler */ local_744;

  uint32_t /* width from decompiler */ local_740;

  uint32_t /* width from decompiler */ local_73c;

  uint32_t /* width from decompiler */ local_738;

  short local_734;

  uint16_t local_732;

  u_long local_730;

  uint32_t /* width from decompiler */ local_72c;

  uint32_t /* width from decompiler */ local_728;

  uint32_t /* width from decompiler */ local_724;

  int local_720;

  sockaddr local_71c;

  undefined **local_70c;

  uint32_t /* width from decompiler */ *local_708;

  uint32_t /* width from decompiler */ local_704;

  uint8_t *local_700;

  void *local_6fc;

  char local_6f8;

  uint32_t /* width from decompiler */ local_6f4;

  uint8_t local_6f0;

  uint8_t local_6ef;

  int local_6e0;

  uint32_t /* width from decompiler */ local_6dc;

  uint32_t /* width from decompiler */ local_6d8;

  uint8_t local_6d4;

  uint8_t local_5d4 [1492];

  

  local_700 = local_5d4;

  local_708 = (uint32_t /* width from decompiler */ *)0x0;

  local_704 = 0;

  local_6fc = (void *)0x5d2;

  local_6f8 = '\0';

  local_6e0 = 0x2e90;

  local_6dc = 0x2e90;

  local_6f4 = 0;

  local_6f0 = 0;

  local_6ef = 0;

  local_6d4 = 0;

  local_6d8 = 0;

  local_70c = &PTR_LAB_009d7ba4;

  local_74c = 0;

  local_74a = 0;

  local_73c = 0;

  local_740 = 0;

  local_744 = 0;

  local_748 = htonl(0);

  iVar1 = FUN_007833a0();

  param_1[0x1e] = iVar1;

  while( true ) {

    iVar1 = FUN_00785070(param_1 + 0x1a,&local_74c,local_5d4,0x5d2,&local_75c);

    if (local_6f8 != '\0') {

      local_6f8 = '\0';

      free(local_700);

    }

    local_6fc = local_75c;

    local_6e0 = (int)local_75c * 8;

    local_700 = local_5d4;

    local_6dc = 0;

    local_6f4 = 0;

    local_6f0 = 0;

    local_6ef = 0;

    local_6d4 = 0;

    local_6d8 = 0;

    if (iVar1 != 0) break;

    (**(code **)(*param_1 + 0x14))(&local_74c,&local_70c,0);

  }

  iVar1 = 0;

  if (0 < param_1[9]) {

    do {

      local_700 = local_5d4;

      local_6d4 = 0;

      local_6d8 = 0;

      local_6dc = 0;

      local_6ef = 0;

      local_6f0 = 0;

      local_6f4 = 0;

      if (*(int *)(*(int *)(param_1[0xb] + iVar1 * 4) + 0x10c) != 0) {

        while( true ) {

          iVar2 = FUN_00785070(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[0xb] + iVar1 * 4) + 0x10c),

                               &local_74c,local_5d4,0x5d2,&local_75c);

          if (local_6f8 != '\0') {

            local_6f8 = '\0';

            free(local_700);

          }

          local_700 = local_5d4;

          local_6e0 = (int)local_75c * 8;

          local_6fc = local_75c;

          local_6dc = 0;

          local_6f4 = 0;

          local_6f0 = 0;

          local_6ef = 0;

          local_6d4 = 0;

          local_6d8 = 0;

          if (iVar2 != 0) break;

          (**(code **)(*param_1 + 0x14))(*(int *)(param_1[0xb] + iVar1 * 4) + 0xf8,&local_70c,0);

        }

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < param_1[9]);

  }

  iVar1 = 0;

  if (0 < param_1[3]) {

    do {

      local_700 = local_5d4;

      local_6d4 = 0;

      local_6d8 = 0;

      local_6dc = 0;

      local_6ef = 0;

      local_6f0 = 0;

      local_6f4 = 0;

      if (*(int *)(*(int *)(param_1[5] + iVar1 * 4) + 0x10c) != 0) {

        while( true ) {

          iVar2 = FUN_00785070(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1[5] + iVar1 * 4) + 0x10c),&local_74c,

                               local_5d4,0x5d2,&local_75c);

          if (local_6f8 != '\0') {

            local_6f8 = '\0';

            free(local_700);

          }

          local_700 = local_5d4;

          local_6e0 = (int)local_75c * 8;

          local_6fc = local_75c;

          local_6dc = 0;

          local_6f4 = 0;

          local_6f0 = 0;

          local_6ef = 0;

          local_6d4 = 0;

          local_6d8 = 0;

          if (iVar2 != 0) break;

          (**(code **)(*param_1 + 0x14))(*(int *)(param_1[5] + iVar1 * 4) + 0xf8,&local_70c,0);

        }

      }

      iVar1 = iVar1 + 1;

    } while (iVar1 < param_1[3]);

  }

  local_700 = local_5d4;

  local_6d4 = 0;

  local_6d8 = 0;

  local_6dc = 0;

  local_6ef = 0;

  local_6f0 = 0;

  local_6f4 = 0;

  local_734 = 0;

  local_732 = 0;

  local_724 = 0;

  local_728 = 0;

  local_72c = 0;

  local_730 = htonl(0);

  while (param_1[0x1b] != 0) {

    local_75c = (void *)0x10;

    local_754 = accept(param_1[0x1a],&local_71c,(int *)&local_75c);

    if (local_754 == 0xffffffff) {

      WSAGetLastError();

      break;

    }

    FUN_007843e0();

    if (local_734 == 0) {

      local_734 = 1;

    }

    local_720 = param_1[0x1e];

    pvVar3 = operator_new(0x10);

    if (pvVar3 == (void *)0x0) {

      local_738 = 0;

    }

    else {

      local_738 = FUN_00783f40(1000000,1000000);

    }

    uVar5 = param_1[0xc] + 1;

    if ((uint)param_1[0xd] < uVar5) {

      SVar6 = uVar5 + (0x10 - (uVar5 & 0xf));

      local_754 = SVar6;

      pvVar4 = malloc(SVar6 * 0x1c);

      pvVar3 = (void *)param_1[0xe];

      param_1[0xe] = (int)pvVar4;

      if ((void *)param_1[0xc] != (void *)0x0) {

        iVar1 = 0;

        local_75c = (void *)param_1[0xc];

        do {

          if ((uint32_t /* width from decompiler */ *)(param_1[0xe] + iVar1) != (uint32_t /* width from decompiler */ *)0x0) {

            puVar7 = (uint32_t /* width from decompiler */ *)((int)pvVar3 + iVar1);

            puVar8 = (uint32_t /* width from decompiler */ *)(param_1[0xe] + iVar1);

            for (iVar2 = 7; SVar6 = local_754, iVar2 != 0; iVar2 = iVar2 + -1) {

              *puVar8 = *puVar7;

              puVar7 = puVar7 + 1;

              puVar8 = puVar8 + 1;

            }

          }

          iVar1 = iVar1 + 0x1c;

          local_75c = (void *)((int)local_75c + -1);

        } while (local_75c != (void *)0x0);

        local_75c = (void *)0x0;

      }

      param_1[0xe] = (int)pvVar3;

      local_750 = pvVar4;

      free(pvVar3);

      param_1[0xe] = (int)pvVar4;

      param_1[0xd] = SVar6;

    }

    param_1[0xc] = param_1[0xc] + 1;

    puVar7 = (uint32_t /* width from decompiler */ *)(param_1[0xe] + -0x1c + param_1[0xc] * 0x1c);

    if (puVar7 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar8 = &local_738;

      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {

        *puVar7 = *puVar8;

        puVar8 = puVar8 + 1;

        puVar7 = puVar7 + 1;

      }

    }

  }

  local_75c = (void *)0x0;

  if (0 < param_1[0xc]) {

    local_754 = 0;

    do {

      SVar6 = local_754;

      if ((uint)(param_1[0x1e] - *(int *)(param_1[0xe] + 0x18 + local_754)) < 0x7531) {

        local_755 = '\0';

        while( true ) {

          iVar1 = FUN_00785070(*(uint32_t /* width from decompiler */ *)(SVar6 + param_1[0xe]),&local_74c,local_5d4,0x5d2,

                               &local_750);

          if (local_6f8 != '\0') {

            local_6f8 = '\0';

            free(local_700);

          }

          local_700 = local_5d4;

          local_6e0 = (int)local_750 * 8;

          local_6fc = local_750;

          local_6dc = 0;

          local_6f4 = 0;

          local_6f0 = 0;

          local_6ef = 0;

          local_6d4 = 0;

          local_6d8 = 0;

          if (iVar1 != 0) break;

          iVar1 = (**(code **)(*param_1 + 0x14))

                            (param_1[0xe] + SVar6 + 4,&local_70c,

                             *(uint32_t /* width from decompiler */ *)(param_1[0xe] + SVar6));

          if (iVar1 != 0) {

            *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(SVar6 + param_1[0xe]);

            local_755 = '\x01';

          }

        }

        if (local_755 != '\0') goto LAB_0042d227;

      }

      else {

        pvVar3 = *(void **)(param_1[0xe] + local_754);

        if (pvVar3 != (void *)0x0) {

          FUN_00784f20();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar3);

        }

LAB_0042d227:

        if (local_75c != (void *)(param_1[0xc] + -1)) {

          puVar7 = (uint32_t /* width from decompiler */ *)(param_1[0xe] + -0x1c + param_1[0xc] * 0x1c);

          puVar8 = (uint32_t /* width from decompiler */ *)(param_1[0xe] + local_754);

          for (iVar1 = 7; SVar6 = local_754, iVar1 != 0; iVar1 = iVar1 + -1) {

            *puVar8 = *puVar7;

            puVar7 = puVar7 + 1;

            puVar8 = puVar8 + 1;

          }

        }

        param_1[0xc] = param_1[0xc] + -1;

      }

      local_75c = (void *)((int)local_75c + 1);

      local_754 = SVar6 + 0x1c;

    } while ((int)local_75c < param_1[0xc]);

  }

  local_70c = &PTR_LAB_009d7b00;

  if (local_6f8 != '\0') {

    free(local_700);

  }

  while (local_708 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar7 = (uint32_t /* width from decompiler */ *)local_708[2];

    *local_708 = 0;

    local_708[1] = 0;

    local_708[2] = 0;

    local_708 = puVar7;

  }

  return;

}
