// =============================================================================
// FUN_0064a880
// -----------------------------------------------------------------------------
// Stable ID: aa_0064a880
// Address:   0x0064a880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064a880 @ 0x0064a880
// Stable ID: aa_0064a880
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~146 non-empty decompiler lines.
//  - Control keywords: if×12, do×6, while×6, return×3.
//  - Notable callees: FUN_005b3300, FUN_0064a880.
//  - Return sites: 3.

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

int __thiscall FUN_0064a880(int param_1,int param_2)



{

  int *piVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  *(uint16_t *)(param_1 + 4) = *(uint16_t *)(param_2 + 4);

  *(uint16_t *)(param_1 + 6) = *(uint16_t *)(param_2 + 6);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  iVar8 = *(int *)(param_2 + 0x14);

  piVar1 = (int *)(param_1 + 0x10);

  if ((int)(*(uint *)(param_1 + 0x18) & 0x7fffffff) < iVar8) {

    iVar8 = *(int *)(param_1 + 0x14);

    puVar4 = (uint32_t /* width from decompiler */ *)*piVar1;

    if (0 < iVar8) {

      do {

        (**(code **)*puVar4)(0);

        puVar4 = puVar4 + 0xc;

        iVar8 = iVar8 + -1;

      } while (iVar8 != 0);

    }

    iVar8 = *(int *)(param_2 + 0x14);

    uVar2 = *(uint *)(param_1 + 0x18) & 0x7fffffff;

    if ((int)uVar2 < iVar8) {

      iVar7 = uVar2 * 2;

      if (iVar7 <= iVar8) {

        iVar7 = iVar8;

      }

      FUN_005b3300(piVar1,iVar7,0x30);

    }

    *(int *)(param_1 + 0x14) = iVar8;

    iVar8 = *piVar1;

    iVar7 = 0;

    if (0 < *(int *)(param_2 + 0x14)) {

      puVar4 = (uint32_t /* width from decompiler */ *)(iVar8 + 0x18);

      do {

        if (puVar4 != (uint32_t /* width from decompiler */ *)0x18) {

          iVar6 = *(int *)(param_2 + 0x10) + (-0x18 - iVar8);

          puVar4[-6] = &PTR_LAB_009cc290;

          *(uint16_t *)(puVar4 + -5) = *(uint16_t *)((int)puVar4 + iVar6 + 4);

          *(uint16_t *)((int)puVar4 + -0x12) = *(uint16_t *)((int)puVar4 + iVar6 + 6);

          puVar4[-6] = &PTR_LAB_009e4950;

          puVar4[-2] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x10);

          puVar4[-1] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x14);

          *puVar4 = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x18);

          puVar4[1] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x1c);

          puVar4[2] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x20);

          puVar4[3] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x24);

          puVar4[4] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x28);

          puVar4[5] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x2c);

        }

        iVar7 = iVar7 + 1;

        puVar4 = puVar4 + 0xc;

      } while (iVar7 < *(int *)(param_2 + 0x14));

    }

  }

  else if (*(int *)(param_1 + 0x14) < iVar8) {

    iVar8 = 0;

    if (0 < *(int *)(param_1 + 0x14)) {

      iVar7 = 0;

      do {

        iVar6 = *(int *)(param_2 + 0x10);

        iVar5 = *piVar1;

        *(uint16_t *)(iVar5 + 4 + iVar7) = *(uint16_t *)(iVar6 + 4 + iVar7);

        iVar3 = iVar6 + iVar7;

        iVar5 = iVar5 + iVar7;

        *(uint16_t *)(iVar5 + 6) = *(uint16_t *)(iVar6 + 6 + iVar7);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

        iVar8 = iVar8 + 1;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c);

        iVar7 = iVar7 + 0x30;

      } while (iVar8 < *(int *)(param_1 + 0x14));

    }

    iVar7 = *piVar1;

    if (iVar8 < *(int *)(param_2 + 0x14)) {

      puVar4 = (uint32_t /* width from decompiler */ *)(iVar8 * 0x30 + 0x18 + iVar7);

      do {

        if (puVar4 != (uint32_t /* width from decompiler */ *)0x18) {

          iVar6 = *(int *)(param_2 + 0x10);

          puVar4[-6] = &PTR_LAB_009cc290;

          iVar6 = iVar6 + (-0x18 - iVar7);

          *(uint16_t *)(puVar4 + -5) = *(uint16_t *)(iVar6 + 4 + (int)puVar4);

          *(uint16_t *)((int)puVar4 + -0x12) = *(uint16_t *)(iVar6 + 6 + (int)puVar4);

          puVar4[-6] = &PTR_LAB_009e4950;

          puVar4[-2] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x10);

          puVar4[-1] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x14);

          *puVar4 = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x18);

          puVar4[1] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x1c);

          puVar4[2] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x20);

          puVar4[3] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x24);

          puVar4[4] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x28);

          puVar4[5] = *(uint32_t /* width from decompiler */ *)((int)puVar4 + iVar6 + 0x2c);

        }

        iVar8 = iVar8 + 1;

        puVar4 = puVar4 + 0xc;

      } while (iVar8 < *(int *)(param_2 + 0x14));

      return param_1;

    }

  }

  else {

    iVar7 = 0;

    if (0 < iVar8) {

      iVar8 = 0;

      iVar7 = 0;

      do {

        iVar6 = *(int *)(param_2 + 0x10);

        iVar5 = *piVar1;

        *(uint16_t *)(iVar5 + 4 + iVar8) = *(uint16_t *)(iVar6 + 4 + iVar8);

        iVar3 = iVar6 + iVar8;

        iVar5 = iVar5 + iVar8;

        *(uint16_t *)(iVar5 + 6) = *(uint16_t *)(iVar6 + 6 + iVar8);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x10) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x14) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x18) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x18);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x1c);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x20) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x20);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x24);

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x28) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x28);

        iVar7 = iVar7 + 1;

        *(uint32_t /* width from decompiler */ *)(iVar5 + 0x2c) = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x2c);

        iVar8 = iVar8 + 0x30;

      } while (iVar7 < *(int *)(param_2 + 0x14));

    }

    if (iVar7 < *(int *)(param_1 + 0x14)) {

      iVar8 = iVar7 * 0x30;

      do {

        (*(code *)**(uint32_t /* width from decompiler */ **)(*piVar1 + iVar8))(0);

        iVar7 = iVar7 + 1;

        iVar8 = iVar8 + 0x30;

      } while (iVar7 < *(int *)(param_1 + 0x14));

      return param_1;

    }

  }

  return param_1;

}
