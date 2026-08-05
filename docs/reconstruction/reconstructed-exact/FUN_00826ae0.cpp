// =============================================================================
// FUN_00826ae0
// -----------------------------------------------------------------------------
// Stable ID: aa_00826ae0
// Address:   0x00826ae0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00826ae0 @ 0x00826ae0
// Stable ID: aa_00826ae0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~236 non-empty decompiler lines.
//  - Control keywords: if×20, return×14, do×10, while×10, for×5.
//  - Notable callees: FUN_007fb960×3, FUN_007fc970×3, FUN_007fb9e0×2, FUN_007fbaf0×2, FUN_007fc6c0×2, CVOGReaction_GiveItemByCbid, FUN_007a69d0, FUN_007a6de0.
//  - Return sites: 14.

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



void __fastcall FUN_00826ae0(char param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  char *pcVar5;

  uint uVar6;

  int iVar7;

  uint uVar8;

  int *unaff_EBX;

  char *pcVar9;

  char *pcVar10;

  char *pcVar11;

  int iStack_102c;

  int local_1018 [3];

  char cStack_1009;

  char local_1008 [2];

  uint32_t /* width from decompiler */ local_1006 [1022];

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x826af0;

  iVar7 = unaff_EBX[0x152];

  if (iVar7 != 1) {

    if (iVar7 == 2) {

      if ((param_1 != '\0') && (unaff_EBX[0x154] != -1)) {

        cVar1 = FUN_007fbab0();

        if (cVar1 != '\0') {

          return;

        }

        iStack_102c = 0x826c60;

        piVar4 = (int *)CVOGReaction_GiveItemByCbid(unaff_EBX[0x154]);

        if (piVar4 == (int *)0x0) {

          return;

        }

        iStack_102c = unaff_EBX[0x154];

        (**(code **)(*piVar4 + 8))();

        puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x140))(&stack0xffffefe4,1);

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x120))(&iStack_102c,1,1);

        FUN_007fd420(*puVar3,puVar3[1],*puVar2,puVar2[1]);

        if (DAT_00d1d8dc != (int *)0x0) {

          DAT_00d1d8dc[0x146] = 0;

        }

        (**(code **)*piVar4)(1);

        FUN_007fb960();

        FUN_007fc970();

        FUN_007fbaf0();

        return;

      }

      DAT_00d1d8f4 = 1;

      DAT_00d1d8f5 = 0;

      piVar4 = DAT_00d1d8dc;

    }

    else {

      if (iVar7 != 5) {

        return;

      }

      local_1018[0] = unaff_EBX[0x154] + 3000;

      if (((param_1 != '\0') && (-1 < local_1018[0])) && (local_1018[0] < 0xf)) {

        cVar1 = FUN_007fba30();

        if (cVar1 != '\0') {

          return;

        }

        local_1008[0] = '\0';

        local_1008[1] = '\0';

        puVar2 = local_1006;

        for (iVar7 = 0x3ff; iVar7 != 0; iVar7 = iVar7 + -1) {

          *puVar2 = 0;

          puVar2 = puVar2 + 1;

        }

        *(uint16_t *)puVar2 = 0;

        pcVar10 = &cStack_1009;

        do {

          pcVar5 = pcVar10 + 1;

          pcVar10 = pcVar10 + 1;

        } while (*pcVar5 != '\0');

        *(uint16_t *)pcVar10 = DAT_00a2faa8;

        pcVar10 = (char *)(&DAT_00d17788)[local_1018[0]];

        if ((pcVar10 == (char *)0x0) || (pcVar5 = pcVar10, *pcVar10 == '\0')) {

          iStack_102c = 0x826dca;

          FUN_007a69d0();

          iStack_102c = 0x826dd1;

          pcVar10 = (char *)FUN_007a6de0();

          pcVar5 = pcVar10;

          do {

            cVar1 = *pcVar5;

            pcVar5 = pcVar5 + 1;

          } while (cVar1 != '\0');

          uVar6 = (int)pcVar5 - (int)pcVar10;

          pcVar5 = &cStack_1009;

          do {

            pcVar11 = pcVar5 + 1;

            pcVar5 = pcVar5 + 1;

          } while (*pcVar11 != '\0');

        }

        else {

          do {

            cVar1 = *pcVar5;

            pcVar5 = pcVar5 + 1;

          } while (cVar1 != '\0');

          uVar6 = (int)pcVar5 - (int)pcVar10;

          pcVar5 = &cStack_1009;

          do {

            pcVar11 = pcVar5 + 1;

            pcVar5 = pcVar5 + 1;

          } while (*pcVar11 != '\0');

        }

        for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {

          *(uint32_t /* width from decompiler */ *)pcVar5 = *(uint32_t /* width from decompiler */ *)pcVar10;

          pcVar10 = pcVar10 + 4;

          pcVar5 = pcVar5 + 4;

        }

        for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

          *pcVar5 = *pcVar10;

          pcVar10 = pcVar10 + 1;

          pcVar5 = pcVar5 + 1;

        }

        pcVar10 = &cStack_1009;

        do {

          pcVar5 = pcVar10 + 1;

          pcVar10 = pcVar10 + 1;

        } while (*pcVar5 != '\0');

        *(uint16_t *)pcVar10 = DAT_00a2faa8;

        puVar2 = &DAT_00d177c8 + local_1018[0] * 5;

        local_1018[0] = 5;

        do {

          pcVar10 = (char *)*puVar2;

          if ((pcVar10 != (char *)0x0) && (*pcVar10 != '\0')) {

            pcVar5 = &cStack_1009;

            do {

              pcVar11 = pcVar5 + 1;

              pcVar5 = pcVar5 + 1;

            } while (*pcVar11 != '\0');

            *(uint16_t *)pcVar5 = DAT_00a15104;

            pcVar5 = pcVar10;

            do {

              cVar1 = *pcVar5;

              pcVar5 = pcVar5 + 1;

            } while (cVar1 != '\0');

            pcVar11 = &cStack_1009;

            do {

              pcVar9 = pcVar11 + 1;

              pcVar11 = pcVar11 + 1;

            } while (*pcVar9 != '\0');

            pcVar9 = pcVar10;

            for (uVar6 = (uint)((int)pcVar5 - (int)pcVar10) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

              *(uint32_t /* width from decompiler */ *)pcVar11 = *(uint32_t /* width from decompiler */ *)pcVar9;

              pcVar9 = pcVar9 + 4;

              pcVar11 = pcVar11 + 4;

            }

            for (uVar6 = (int)pcVar5 - (int)pcVar10 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {

              *pcVar11 = *pcVar9;

              pcVar9 = pcVar9 + 1;

              pcVar11 = pcVar11 + 1;

            }

          }

          puVar2 = puVar2 + 1;

          local_1018[0] = local_1018[0] + -1;

        } while (local_1018[0] != 0);

        iStack_102c = 0x826ea3;

        puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x140))();

        iStack_102c = 1;

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x120))(&stack0xffffefe0,1);

        FUN_007fd1c0(*puVar3,puVar3[1],*puVar2,puVar2[1]);

        FUN_007fb960();

        DAT_00d1d8f4 = 1;

        DAT_00d1d8f5 = 0;

        if (DAT_00d1d8dc != (int *)0x0) {

          (**(code **)(*DAT_00d1d8dc + 4))(0);

        }

        FUN_007fc970();

        return;

      }

      DAT_00d1d8fe = 1;

      DAT_00d1d8ff = 0;

      piVar4 = DAT_00d1d8f0;

    }

    if (piVar4 != (int *)0x0) {

      (**(code **)(*piVar4 + 4))();

    }

    if ((DAT_00d1b984 != (int *)0x0) &&

       (cVar1 = (**(code **)(*DAT_00d1b984 + 0xd0))(), cVar1 == '\0')) {

      iStack_102c = 0x826f54;

      (**(code **)(*DAT_00d1b984 + 0xfc))();

      iStack_102c = 0x826f5e;

      (**(code **)(*unaff_EBX + 0x30c))();

      iStack_102c = 0x826f6a;

      FUN_007fb9e0();

      iStack_102c = DAT_00d1d870;

      FUN_007fc6c0(DAT_00d1d86c);

    }

    return;

  }

  if ((param_1 == '\0') || (unaff_EBX[0x156] == 0)) {

    FUN_007fc970();

    if (DAT_00d1b984 == (int *)0x0) {

      return;

    }

    cVar1 = (**(code **)(*DAT_00d1b984 + 0xd0))();

    if (cVar1 != '\0') {

      return;

    }

    iStack_102c = 0x826bf4;

    (**(code **)(*DAT_00d1b984 + 0xfc))();

    iStack_102c = 0x826bfe;

    (**(code **)(*unaff_EBX + 0x30c))();

    iStack_102c = 0x826c05;

    FUN_007fb9e0();

    iStack_102c = DAT_00d1d870;

    FUN_007fc6c0(DAT_00d1d86c);

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  cVar1 = FUN_007fba70();

  if (cVar1 != '\0') {

    return;

  }

  iStack_102c = 0x826b46;

  puVar2 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x140))();

  iStack_102c = 1;

  puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_EBX + 0x120))(local_1018,1);

  FUN_007fd350(&DAT_00d1a840,*puVar3,puVar3[1],*puVar2,puVar2[1],1);

  FUN_007fb960();

  FUN_007fbaf0();

  DAT_00d1d8f4 = 1;

  DAT_00d1d8f5 = 0;

  if (DAT_00d1d8dc == (int *)0x0) {

    DAT_00d1d8f4 = 1;

    DAT_00d1d8f5 = 0;

    return;

  }

  (**(code **)(*DAT_00d1d8dc + 4))(0);

  return;

}
