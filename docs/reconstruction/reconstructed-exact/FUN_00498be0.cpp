// =============================================================================
// FUN_00498be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00498be0
// Address:   0x00498be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00498be0 @ 0x00498be0
// Stable ID: aa_00498be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×10, return×4, for×2, do×1, while×1.
//  - Notable callees: FUN_00414ae0, FUN_0043f660, FUN_0044ba40, FUN_00498be0, FUN_00743ba0, FUN_007464e0.
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

void __fastcall FUN_00498be0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint *puVar5;

  int iVar6;

  uint uVar7;

  uint32_t /* width from decompiler */ *puVar8;

  

  if (*(char *)(param_1 + 0x178) != '\0') {

    if ((*(int *)(param_1 + 400) != 0) && (*(int *)(param_1 + 0x1c8) != 0)) {

      uVar2 = FUN_0043f660();

      (**(code **)(**(int **)(param_1 + 400) + 0x4c))(uVar2);

      (**(code **)(**(int **)(param_1 + 400) + 0x10))();

      (**(code **)(**(int **)(param_1 + 400) + 0x14))();

    }

    if (DAT_00aefae8 != '\0') {

      iVar1 = *(int *)(param_1 + 0x188);

      if (iVar1 == 0) {

        return;

      }

      if (*(int *)(param_1 + 0x184) == 0) {

        return;

      }

      if (*(int *)(param_1 + 0x1b0) == 0) {

        return;

      }

      *(uint *)(iVar1 + 0xbc) = *(uint *)(iVar1 + 0xbc) | 1;

      iVar3 = FUN_00414ae0(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1b0),1);

      if ((iVar3 != 0) && (uVar7 = 0, *(int *)(param_1 + 0x1b0) != 0)) {

        iVar6 = 0;

        puVar4 = (uint32_t /* width from decompiler */ *)(iVar3 + 0x14);

        do {

          iVar3 = *(int *)(param_1 + 0x1ac) + iVar6;

          puVar4[-5] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1ac) + iVar6);

          puVar4[-4] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

          puVar4[-3] = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

          iVar3 = *(int *)(param_1 + 0x1a8) + iVar6;

          puVar4[-2] = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1a8) + iVar6);

          puVar4[-1] = *(uint32_t /* width from decompiler */ *)(iVar3 + 4);

          *puVar4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 8);

          uVar7 = uVar7 + 1;

          iVar6 = iVar6 + 0xc;

          puVar4 = puVar4 + 6;

        } while (uVar7 < *(uint *)(param_1 + 0x1b0));

      }

      if (*(int *)(*(int *)(iVar1 + 0x14) + 0x10) != 0) {

        FUN_007464e0();

      }

      iVar1 = *(int *)(param_1 + 0x188);

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_0044ba40(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1bc),0x2000);

      if (puVar4 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar8 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1b8);

        for (uVar7 = *(uint *)(param_1 + 0x1bc) & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {

          *puVar4 = *puVar8;

          puVar8 = puVar8 + 1;

          puVar4 = puVar4 + 1;

        }

        for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

          *(uint8_t *)puVar4 = *(uint8_t *)puVar8;

          puVar8 = (uint32_t /* width from decompiler */ *)((int)puVar8 + 1);

          puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

        }

      }

      if (*(int *)(*(int *)(iVar1 + 0xc) + 0x10) != 0) {

        FUN_00743ba0();

      }

      *(uint *)(*(int *)(param_1 + 0x188) + 0xa8) = *(uint *)(param_1 + 0x1bc) / 3;

      puVar5 = (uint *)(*(int *)(param_1 + 0x188) + 0xbc);

      *puVar5 = *puVar5 & 0xfffffffe;

    }

    *(uint8_t *)(param_1 + 0x1dd) = 1;

  }

  return;

}
