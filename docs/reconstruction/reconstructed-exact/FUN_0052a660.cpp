// =============================================================================
// FUN_0052a660
// -----------------------------------------------------------------------------
// Stable ID: aa_0052a660
// Address:   0x0052a660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052a660 @ 0x0052a660
// Stable ID: aa_0052a660
// Embedded strings (evidence for future rename):
//   - "MatGlow"
//   - "PulseTime"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~123 non-empty decompiler lines.
//  - Control keywords: if×14, return×2, while×2.
//  - Notable callees: FUN_0079a110×2, _CIfmod×2, __allrem×2, ABS, FUN_00442640, FUN_004c7490, FUN_004e87d0, FUN_004e8a40.
//  - Strings: "MatGlow"; "PulseTime".
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

void __fastcall FUN_0052a660(int param_1)



{

  float fVar1;

  bool bVar2;

  char cVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int iVar6;

  float *pfVar7;

  float10 fVar8;

  float local_48;

  float local_44;

  longlong local_40 [2];

  float local_30;

  float local_2c;

  float local_28;

  float local_24;

  uint8_t local_20 [28];

  

  FUN_004c7490();

  if (*(int *)(param_1 + 8) != 0) {

    if (*(int *)(param_1 + 0x48) == 0) {

      return;

    }

    FUN_004e8a40(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30,&local_30);

    local_44 = local_2c * 0.0;

    local_48 = local_30 * 0.0 + local_44 + local_28;

    if (ABS(local_48) < g_flOne) {

      fVar8 = (float10)_CIacos();

      local_48 = (float)fVar8;

    }

    else {

      bVar2 = local_48 <= 0.0;

      local_48 = 0.0;

      if (bVar2) {

        local_48 = DAT_009ceecc;

      }

    }

    if (local_28 * 0.0 + local_44 + local_30 < 0.0) {

      local_48 = DAT_009cb158 - local_48;

    }

    FUN_00567ce0(&DAT_00af2430,local_48);

    iVar5 = **(int **)(param_1 + 0x48);

    uVar4 = FUN_004e87d0(local_20,local_40);

    (**(code **)(iVar5 + 0x14))(uVar4);

    iVar5 = (**(code **)(**(int **)(param_1 + 0x48) + 0x10))(3);

    *(uint32_t /* width from decompiler */ *)(iVar5 + 0xbc) = 0xffffffff;

    *(int *)(iVar5 + 0xb4) = *(int *)(iVar5 + 0xb4) + 1;

    *(float *)(iVar5 + 0x94) = *(float *)(iVar5 + 0x94) - g_flOne;

  }

  if (*(int *)(param_1 + 0x48) != 0) {

    cVar3 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c

                              ) + 0x532);

    if (cVar3 == '\0') {

      local_30 = 0.0;

      local_2c = 0.0;

      local_28 = 0.0;

      local_24 = g_flOne;

      fVar8 = (float10)FUN_0079a110();

      local_44 = (float)fVar8;

      fVar8 = (float10)_CIfmod();

      iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);

      local_44 = (float)fVar8;

      local_40[0] = __allrem(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x164 + param_1),

                             *(uint32_t /* width from decompiler */ *)(iVar5 + 0x168 + param_1),10,0);

      local_24 = g_flOne;

      local_48 = 0.0;

      fVar8 = (float10)fsin(((float10)local_40[0] + (float10)local_44) *

                            (float10)g_flVehicleHpTechCoeff);

      fVar8 = fVar8 * (float10)DAT_00a0f720 + (float10)DAT_00a0f734;

      local_30 = (float)fVar8;

      local_2c = (float)fVar8;

      local_28 = (float)fVar8;

      while( true ) {

        iVar5 = *(int *)(param_1 + 0x48);

        if (*(int *)(iVar5 + 0xc0) == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = *(int *)(iVar5 + 0xc4) - *(int *)(iVar5 + 0xc0) >> 2;

        }

        if (iVar6 <= (int)local_48) break;

        if (*(int *)(*(int *)(*(int *)(iVar5 + 0xc0) + (int)local_48 * 4) + 0x20) == 0) {

          local_44 = -NAN;

          pfVar7 = &local_44;

        }

        else {

          pfVar7 = (float *)FUN_00752370(local_40,"MatGlow");

        }

        fVar1 = *pfVar7;

        cVar3 = FUN_0096fdf0();

        iVar5 = FUN_00752a00(fVar1,&local_30);

        if ((iVar5 == -1) && (cVar3 != '\0')) {

          FUN_0096f5d0();

        }

        local_48 = (float)((int)local_48 + 1);

      }

    }

    else if (cVar3 == '\x01') {

      fVar8 = (float10)FUN_0079a110();

      local_44 = (float)fVar8;

      fVar8 = (float10)_CIfmod();

      iVar5 = *(int *)(*(int *)(param_1 + 4) + 4);

      local_44 = (float)fVar8;

      local_40[0] = __allrem(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x164 + param_1),

                             *(uint32_t /* width from decompiler */ *)(iVar5 + 0x168 + param_1),10,0);

      iVar5 = 0;

      local_48 = (float)local_40[0] + local_44;

      while( true ) {

        iVar6 = *(int *)(*(int *)(param_1 + 0x48) + 0xc0);

        if (iVar6 == 0) {

          iVar6 = 0;

        }

        else {

          iVar6 = *(int *)(*(int *)(param_1 + 0x48) + 0xc4) - iVar6 >> 2;

        }

        if (iVar6 <= iVar5) break;

        FUN_00442640("PulseTime",&local_48);

        iVar5 = iVar5 + 1;

      }

    }

  }

  return;

}
