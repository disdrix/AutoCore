// =============================================================================
// FUN_005a9400
// -----------------------------------------------------------------------------
// Stable ID: aa_005a9400
// Address:   0x005a9400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a9400 @ 0x005a9400
// Stable ID: aa_005a9400
// Embedded strings (evidence for future rename):
//   - "ehwfGrass"
//   - "ehwfSnow"
//   - "ehwfDirt"
//   - "ehwfSand"
//   - "ehwfMud2"
//   - "ehwfWaterSpray"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~101 non-empty decompiler lines.
//  - Control keywords: if×6, do×4, while×4, return×1.
//  - Notable callees: NDSpecialFX_LoadFromScriptName×7, FUN_0067fdd0×3, FUN_004b73c0×2, FUN_004b7550×2, FUN_004b8dc0×2, FUN_005a9400.
//  - Strings: "ehwfGrass"; "ehwfSnow"; "ehwfDirt"; "ehwfSand".
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

void __thiscall FUN_005a9400(int param_1,int param_2)



{

  void *pvVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  char cVar6;

  int iVar7;

  int local_10;

  uint32_t /* width from decompiler */ local_c;

  float local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (((*(int *)(param_1 + 0x124) == 0) ||

      (*(int *)(param_1 + 0x128) - *(int *)(param_1 + 0x124) >> 2 == 0)) && (param_2 != 0)) {

    FUN_0067fdd0(*(char *)(param_1 + 0xb0) * 5,0);

    FUN_0067fdd0((int)*(char *)(param_1 + 0xb0),0);

    FUN_0067fdd0((int)*(char *)(param_1 + 0xb0),0);

    iVar7 = 0;

    if ('\0' < *(char *)(param_1 + 0xb0)) {

      do {

        iVar4 = *(int *)(param_1 + 0x124);

        iVar3 = iVar7 * 4;

        pvVar1 = NDSpecialFX_LoadFromScriptName("ehwfGrass",-1,iVar7);

        *(void **)(iVar4 + iVar3) = pvVar1;

        cVar6 = *(char *)(param_1 + 0xb0);

        iVar4 = *(int *)(param_1 + 0x124);

        pvVar1 = NDSpecialFX_LoadFromScriptName("ehwfSnow",-1,iVar7);

        *(void **)(iVar4 + (cVar6 + iVar7) * 4) = pvVar1;

        cVar6 = *(char *)(param_1 + 0xb0);

        iVar4 = *(int *)(param_1 + 0x124);

        pvVar1 = NDSpecialFX_LoadFromScriptName("ehwfDirt",-1,iVar7);

        *(void **)(iVar4 + (iVar7 + cVar6 * 2) * 4) = pvVar1;

        cVar6 = *(char *)(param_1 + 0xb0);

        iVar4 = *(int *)(param_1 + 0x124);

        pvVar1 = NDSpecialFX_LoadFromScriptName("ehwfSand",-1,iVar7);

        *(void **)(iVar4 + (iVar7 + cVar6 * 3) * 4) = pvVar1;

        cVar6 = *(char *)(param_1 + 0xb0);

        iVar4 = *(int *)(param_1 + 0x124);

        pvVar1 = NDSpecialFX_LoadFromScriptName("ehwfMud2",-1,iVar7);

        *(void **)(iVar4 + (iVar7 + cVar6 * 4) * 4) = pvVar1;

        iVar4 = *(int *)(param_1 + 0x134);

        pvVar1 = NDSpecialFX_LoadFromScriptName("ehwfWaterSpray",-1,iVar7);

        *(void **)(iVar4 + iVar3) = pvVar1;

        iVar4 = *(int *)(param_1 + 0x144);

        pvVar1 = NDSpecialFX_LoadFromScriptName("ehwfWaterWake",-1,iVar7);

        *(void **)(iVar4 + iVar3) = pvVar1;

        iVar7 = iVar7 + 1;

      } while (iVar7 < *(char *)(param_1 + 0xb0));

    }

    iVar7 = 0;

    if (0 < *(char *)(param_1 + 0xb0) * 5) {

      do {

        iVar3 = iVar7 * 4;

        if (*(int *)(iVar3 + *(int *)(param_1 + 0x124)) != 0) {

          FUN_004b73c0(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

          *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x124) + iVar3) + 0x2c) =

               *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

          *(uint8_t *)(*(int *)(*(int *)(param_1 + 0x124) + iVar3) + 9) = 1;

          FUN_004b8dc0(0,0);

          iVar4 = (int)(char)(iVar7 % (int)*(char *)(param_1 + 0xb0));

          local_c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x514 + iVar4 * 0xc);

          iVar3 = param_2 + 0x514 + iVar4 * 0xc;

          local_8 = *(float *)(iVar3 + 4) - *(float *)(param_2 + 0x600 + iVar4 * 4);

          local_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

          FUN_004b7550(&local_c,1);

        }

        iVar7 = iVar7 + 1;

      } while (iVar7 < *(char *)(param_1 + 0xb0) * 5);

    }

    piVar5 = (int *)(param_1 + 0x138);

    local_10 = 2;

    do {

      piVar2 = (int *)piVar5[-1];

      cVar6 = '\0';

      if (piVar2 != (int *)*piVar5) {

        do {

          iVar7 = *piVar2;

          if (iVar7 != 0) {

            FUN_004b73c0(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1);

            *(uint32_t /* width from decompiler */ *)(iVar7 + 0x2c) =

                 *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

            *(uint8_t *)(iVar7 + 9) = 1;

            FUN_004b8dc0(0,0);

            iVar3 = (int)cVar6;

            local_c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x514 + iVar3 * 0xc);

            iVar7 = param_2 + 0x514 + iVar3 * 0xc;

            local_8 = *(float *)(iVar7 + 4) - *(float *)(param_2 + 0x600 + iVar3 * 4);

            local_4 = *(uint32_t /* width from decompiler */ *)(iVar7 + 8);

            FUN_004b7550(&local_c,1);

          }

          piVar2 = piVar2 + 1;

          cVar6 = cVar6 + '\x01';

        } while (piVar2 != (int *)*piVar5);

      }

      piVar5 = piVar5 + 4;

      local_10 = local_10 + -1;

    } while (local_10 != 0);

  }

  return;

}
