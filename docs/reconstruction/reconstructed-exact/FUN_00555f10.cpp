// =============================================================================
// FUN_00555f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00555f10
// Address:   0x00555f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00555f10 @ 0x00555f10
// Stable ID: aa_00555f10
// Embedded strings (evidence for future rename):
//   - "Failed to load weather FX: %s"
//   - "env_time_midday"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~177 non-empty decompiler lines.
//  - Control keywords: if×31, return×4, goto×2, do×1, while×1.
//  - Notable callees: FUN_00553d20×7, FUN_004b8dc0×6, FUN_004b73c0×4, NDSpecialFX_LoadFromScriptName×4, CONCAT31×2, FUN_004b6fc0×2, FUN_004b9270×2, FUN_00553f50×2.
//  - Strings: "Failed to load weather FX: %s"; "env_time_midday".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_00555f10(int param_1,float param_2)



{

  char *pcVar1;

  int iVar2;

  DWORD DVar3;

  int iVar4;

  void *pvVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint3 uVar8;

  float fVar9;

  int local_10;

  

  *(float *)(param_1 + 0x188) = param_2;

  if (*(int *)(param_1 + 0x18c) == 0) {

LAB_00555f84:

    param_2 = g_flOne;

  }

  else {

    DVar3 = GetTickCount();

    iVar4 = DVar3 - *(int *)(param_1 + 0x18c);

    fVar9 = (float)iVar4;

    if (iVar4 < 0) {

      fVar9 = fVar9 + _DAT_00aaa5dc;

    }

    if (g_flOne <= fVar9 / _DAT_00af2ce8) goto LAB_00555f84;

    DVar3 = GetTickCount();

    iVar4 = DVar3 - *(int *)(param_1 + 0x18c);

    param_2 = (float)iVar4;

    if (iVar4 < 0) {

      param_2 = param_2 + _DAT_00aaa5dc;

    }

    param_2 = param_2 / _DAT_00af2ce8;

  }

  if (*(int *)(param_1 + 0x180) == 0) {

    param_2 = g_flOne;

  }

  local_10 = 0;

  do {

    if (local_10 < 1) {

      iVar4 = *(int *)(param_1 + 0x17c);

    }

    else {

      param_2 = g_flOne - param_2;

      iVar4 = *(int *)(param_1 + 0x180);

    }

    if (iVar4 != 0) {

      pcVar1 = (char *)(iVar4 + 0x440);

      if ((*(int *)(iVar4 + 0x544) == 0) && (*pcVar1 != '\0')) {

        pvVar5 = NDSpecialFX_LoadFromScriptName(pcVar1,0,0);

        *(void **)(iVar4 + 0x544) = pvVar5;

        if (pvVar5 == (void *)0x0) {

          FUN_007a4480(1,"Failed to load weather FX: %s",pcVar1);

          pvVar5 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

          *(void **)(iVar4 + 0x544) = pvVar5;

        }

        if (*(int *)(iVar4 + 0x544) != 0) {

          *(uint8_t *)(*(int *)(iVar4 + 0x544) + 9) = 1;

          FUN_004b8dc0(0,0);

          FUN_004b9270(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x544));

        }

      }

      iVar6 = *(int *)(iVar4 + 0x544);

      if ((iVar6 != 0) && (iVar2 = *(int *)(param_1 + 0x188), iVar2 != 0)) {

        FUN_004b73c0(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2);

        FUN_004b8dc0(1,0);

        *(float *)(iVar6 + 0x38) = g_flOne;

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

      }

      fVar9 = g_flOne;

      if (*(float *)(iVar4 + 0x554) <= g_flOne && g_flOne != *(float *)(iVar4 + 0x554)) {

        fVar9 = g_flOne - *(float *)(iVar4 + 0x554);

      }

      iVar6 = 0;

      if (*(int *)(iVar4 + 0x434) != 0) {

        iVar6 = (*(int *)(iVar4 + 0x438) - *(int *)(iVar4 + 0x434)) / 0x134;

      }

      if (((*(int *)(iVar4 + 0x558) < iVar6) && (iVar6 = FUN_00553d20(0), iVar6 != 0)) &&

         (iVar2 = *(int *)(param_1 + 0x188), iVar2 != 0)) {

        FUN_004b73c0(*(int *)(*(int *)(iVar2 + 4) + 4) + 4 + iVar2);

        FUN_004b8dc0(1,0);

        *(float *)(iVar6 + 0x38) = fVar9 * param_2;

        *(uint32_t /* width from decompiler */ *)(iVar6 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

      }

      uVar8 = (uint3)((uint)local_10 >> 8);

      if (*(int *)(iVar4 + 0x558) != *(int *)(iVar4 + 0x55c)) {

        fVar9 = *(float *)(iVar4 + 0x554) * param_2;

        if (g_flOne <= fVar9) {

          iVar6 = (uint)uVar8 << 8;

        }

        else {

          iVar6 = CONCAT31(uVar8,1);

        }

        uVar7 = FUN_00555600(*(int *)(iVar4 + 0x55c));

        FUN_00553f50(iVar6,uVar7,fVar9);

      }

      fVar9 = g_flOne;

      if (*(float *)(param_1 + 0x15c) <= g_flOne && g_flOne != *(float *)(param_1 + 0x15c)) {

        fVar9 = g_flOne - *(float *)(param_1 + 0x15c);

      }

      if (((-1 < *(int *)(param_1 + 0x150)) && (*(int *)(param_1 + 0x150) < 4)) &&

         ((iVar4 = FUN_00553d20(0), iVar4 != 0 && (iVar6 = *(int *)(param_1 + 0x188), iVar6 != 0))))

      {

        FUN_004b73c0(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6);

        FUN_004b8dc0(1,0);

        *(float *)(iVar4 + 0x38) = fVar9 * param_2;

        *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

      }

      iVar4 = *(int *)(param_1 + 0x154);

      if (*(int *)(param_1 + 0x150) != iVar4) {

        if (g_flOne <= *(float *)(param_1 + 0x15c) * param_2) {

          iVar6 = (uint)uVar8 << 8;

        }

        else {

          iVar6 = CONCAT31(uVar8,1);

        }

        if ((iVar4 < 0) || (3 < iVar4)) {

          uVar7 = 0;

        }

        else {

          uVar7 = FUN_00553d20(0);

        }

        FUN_00553f50(iVar6,uVar7,*(float *)(param_1 + 0x15c) * param_2);

      }

    }

    local_10 = local_10 + 1;

  } while (local_10 < 2);

  pcVar1 = (char *)(param_1 + 0x44);

  if ((*(int *)(param_1 + 0x148) == 0) && (*pcVar1 != '\0')) {

    pvVar5 = NDSpecialFX_LoadFromScriptName(pcVar1,0,0);

    *(void **)(param_1 + 0x148) = pvVar5;

    if (pvVar5 == (void *)0x0) {

      FUN_007a4480(1,"Failed to load weather FX: %s",pcVar1);

      pvVar5 = NDSpecialFX_LoadFromScriptName("env_time_midday",0,0);

      *(void **)(param_1 + 0x148) = pvVar5;

    }

    if (*(int *)(param_1 + 0x148) != 0) {

      *(uint8_t *)(*(int *)(param_1 + 0x148) + 9) = 1;

      FUN_004b8dc0(0,0);

      FUN_004b9270(*(uint32_t /* width from decompiler */ *)(param_1 + 0x148));

    }

  }

  iVar4 = *(int *)(param_1 + 0x148);

  if ((iVar4 != 0) && (iVar6 = *(int *)(param_1 + 0x188), iVar6 != 0)) {

    FUN_004b73c0(*(int *)(*(int *)(iVar6 + 4) + 4) + 4 + iVar6);

    FUN_004b8dc0(1,0);

    *(float *)(iVar4 + 0x38) = g_flOne;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x40);

  }

  if (*(int *)(param_1 + 0x17c) == 0) {

    return;

  }

  if (((-1 < *(int *)(param_1 + 0x150)) && (*(int *)(param_1 + 0x150) < 4)) &&

     (iVar4 = FUN_00553d20(0), iVar4 != 0)) {

    if ((*(int *)(param_1 + 0x150) < 0) || (3 < *(int *)(param_1 + 0x150))) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_00553d20(0);

    }

    if (*(int *)(iVar4 + 0x1fc) != 0) {

      if ((*(int *)(param_1 + 0x150) < 0) || (3 < *(int *)(param_1 + 0x150))) {

        FUN_004b6fc0();

        return;

      }

      goto LAB_00556433;

    }

  }

  iVar4 = FUN_00553d20(0);

  if (iVar4 == 0) {

    return;

  }

LAB_00556433:

  FUN_00553d20(0);

  FUN_004b6fc0();

  return;

}
