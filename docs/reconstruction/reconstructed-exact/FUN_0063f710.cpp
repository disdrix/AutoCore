// =============================================================================
// FUN_0063f710
// -----------------------------------------------------------------------------
// Stable ID: aa_0063f710
// Address:   0x0063f710  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0063f710 @ 0x0063f710
// Stable ID: aa_0063f710
// Embedded strings (evidence for future rename):
//   - "VisualDebugger: ["
//   - "Registering viewer \""
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~175 non-empty decompiler lines.
//  - Control keywords: if×22, do×6, while×6, return×2.
//  - Notable callees: FUN_00631dc0×4, FUN_00638180×4, FUN_005b3300, FUN_00631da0, FUN_00631f80, FUN_00637f70, FUN_00638060, FUN_006380a0.
//  - Strings: "VisualDebugger: ["; "Registering viewer \"".
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

int __thiscall FUN_0063f710(int param_1,char *param_2,int param_3)



{

  uint uVar1;

  int *piVar2;

  int *piVar3;

  uint uVar4;

  bool bVar5;

  int iVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int *piVar9;

  int *piVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  char *pcVar14;

  uint16_t *puVar15;

  char *pcVar16;

  uint32_t /* width from decompiler */ uVar17;

  int local_18;

  

  if (0 < DAT_00d030ec) {

    pcVar16 = "VisualDebugger: [";

    (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

    FUN_00631dc0(pcVar16);

    uVar17 = 0x5d;

    puVar15 = &DAT_00a2faa8;

    pcVar14 = "Registering viewer \"";

    pcVar16 = param_2;

    (**(code **)(*DAT_00d030e0 + 4))("Registering viewer \"",param_2,&DAT_00a2faa8,0x5d);

    FUN_00631dc0(pcVar14);

    FUN_00631dc0(pcVar16);

    FUN_00631dc0(puVar15);

    uVar17 = FUN_00631da0(uVar17);

    FUN_00631f80(uVar17);

  }

  iVar11 = 0;

  bVar5 = false;

  if (0 < *(int *)(param_1 + 0x10)) {

    iVar12 = 0;

    iVar13 = 0;

    do {

      iVar6 = FUN_00637f70(*(uint32_t /* width from decompiler */ *)(iVar12 + *(int *)(param_1 + 0xc)),param_2);

      if (iVar6 == 0) {

        iVar13 = *(int *)(param_1 + 0xc) + iVar12;

        bVar5 = true;

      }

      iVar11 = iVar11 + 1;

      iVar12 = iVar12 + 0xc;

    } while (iVar11 < *(int *)(param_1 + 0x10));

    if (bVar5) {

      return *(int *)(iVar13 + 8);

    }

  }

  iVar11 = *(int *)(param_1 + 0x10);

  piVar10 = (int *)(param_1 + 0xc);

  uVar1 = iVar11 + 1;

  if ((int)uVar1 < iVar11) {

    iVar12 = uVar1 * 0xc;

    iVar13 = iVar11 - uVar1;

    do {

      piVar2 = (int *)(*(int *)(iVar12 + *piVar10) + -4);

      *piVar2 = *piVar2 + -1;

      if (*piVar2 < 0) {

        FUN_00638180();

      }

      iVar12 = iVar12 + 0xc;

      iVar13 = iVar13 + -1;

    } while (iVar13 != 0);

  }

  else {

    uVar4 = *(uint *)(param_1 + 0x14);

    if ((int)(uVar4 & 0x7fffffff) < (int)uVar1) {

      uVar7 = (uVar4 & 0x7fffffff) * 2;

      if ((int)uVar7 <= (int)uVar1) {

        uVar7 = uVar1;

      }

      piVar2 = (int *)*piVar10;

      *piVar10 = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0x80000000;

      if (0 < (int)uVar7) {

        FUN_005b3300(piVar10,uVar7 & ((int)uVar7 < 0) - 1,0xc);

      }

      iVar12 = *piVar10;

      if (0 < iVar11) {

        puVar8 = (uint32_t /* width from decompiler */ *)(iVar12 + 4);

        piVar9 = piVar2;

        iVar13 = iVar11;

        do {

          if (puVar8 != (uint32_t /* width from decompiler */ *)0x4) {

            iVar6 = *piVar9;

            piVar3 = (int *)(iVar6 + -4);

            *piVar3 = *piVar3 + 1;

            puVar8[-1] = iVar6;

            *puVar8 = *(uint32_t /* width from decompiler */ *)(((int)piVar2 - iVar12) + (int)puVar8);

            puVar8[1] = piVar9[2];

          }

          puVar8 = puVar8 + 3;

          piVar9 = piVar9 + 3;

          iVar13 = iVar13 + -1;

        } while (iVar13 != 0);

        piVar9 = piVar2;

        local_18 = iVar11;

        if (0 < iVar11) {

          do {

            piVar3 = (int *)(*piVar9 + -4);

            *piVar3 = *piVar3 + -1;

            if (*piVar3 < 0) {

              FUN_00638180();

            }

            local_18 = local_18 + -1;

            piVar9 = piVar9 + 3;

          } while (local_18 != 0);

        }

      }

      if (-1 < (int)uVar4) {

        (**(code **)(*DAT_00b05060 + 0x14))(piVar2,(uVar4 & 0x7fffffff) * 0xc,0x12);

      }

    }

    else if (iVar11 < (int)uVar1) {

      puVar8 = (uint32_t /* width from decompiler */ *)(*piVar10 + iVar11 * 0xc);

      iVar12 = uVar1 - iVar11;

      do {

        if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

          DAT_00d02c6c = DAT_00d02c6c + 1;

          *puVar8 = &DAT_00d02c70;

        }

        puVar8 = puVar8 + 3;

        iVar12 = iVar12 + -1;

      } while (iVar12 != 0);

    }

    if (iVar11 < iVar11 + 1) {

      puVar8 = (uint32_t /* width from decompiler */ *)(*piVar10 + iVar11 * 0xc);

      iVar12 = (iVar11 + 1) - iVar11;

      do {

        if (puVar8 != (uint32_t /* width from decompiler */ *)0x0) {

          DAT_00d02c6c = DAT_00d02c6c + 1;

          *puVar8 = &DAT_00d02c70;

        }

        puVar8 = puVar8 + 3;

        iVar12 = iVar12 + -1;

      } while (iVar12 != 0);

    }

  }

  *(int *)(param_1 + 0x10) = iVar11 + 1;

  piVar10 = (int *)(*piVar10 + iVar11 * 0xc);

  if ((param_2 == (char *)0x0) || (*param_2 == '\0')) {

    piVar2 = (int *)(*piVar10 + -4);

    *piVar2 = *piVar2 + -1;

    if (*piVar2 < 0) {

      FUN_00638180();

    }

    DAT_00d02c6c = DAT_00d02c6c + 1;

    *piVar10 = (int)&DAT_00d02c70;

  }

  else {

    iVar12 = FUN_00638060(param_2);

    iVar11 = *piVar10;

    if ((*(int *)(iVar11 + -8) < iVar12) || (0 < *(int *)(iVar11 + -4))) {

      piVar2 = (int *)(iVar11 + -4);

      *piVar2 = *piVar2 + -1;

      if (*piVar2 < 0) {

        FUN_00638180();

      }

      iVar11 = FUN_006381a0(iVar12);

      *piVar10 = iVar11 + 0xc;

    }

    FUN_006380a0(*piVar10,param_2,iVar12 + 1);

    *(int *)(*piVar10 + -0xc) = iVar12;

  }

  piVar10[1] = param_3;

  piVar10[2] = *(int *)(param_1 + 8);

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;

  return piVar10[2];

}
