// =============================================================================
// FUN_005dbdc0
// -----------------------------------------------------------------------------
// Stable ID: aa_005dbdc0
// Address:   0x005dbdc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dbdc0 @ 0x005dbdc0
// Stable ID: aa_005dbdc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget×2, FUN_00404840, FUN_00418700, FUN_005dbdc0.
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

void __thiscall

FUN_005dbdc0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,uint32_t /* width from decompiler */ param_5,

            int param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  int iVar4;

  int *piVar5;

  char cVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  uVar2 = param_6;

  if ((*(char *)(param_1 + -0x36) == '\0') &&

     (((cVar6 = (char)param_6, cVar6 != '\0' || ((char)param_3 == '\0')) ||

      (cVar3 = (**(code **)(*(int *)(param_1 + -0x1c0) + 100))(param_2), cVar3 != '\0')))) {

    *(uint8_t *)(param_1 + -0x36) = 1;

    if (param_1 == 0x1c0) {

      param_6 = 0;

    }

    else {

      param_6 = *(int *)(*(int *)(param_1 + -0x1bc) + 4) + -0x1bc + param_1;

    }

    iVar1 = *(int *)(param_4 + 4);

    iVar4 = FUN_00418700(iVar1,*(uint32_t /* width from decompiler */ *)(iVar1 + 4),&param_6);

    FUN_00404840(1);

    *(int *)(iVar1 + 4) = iVar4;

    **(int **)(iVar4 + 4) = iVar4;

    puVar7 = *(uint32_t /* width from decompiler */ **)(param_1 + -0x78);

    if (puVar7 != *(uint32_t /* width from decompiler */ **)(param_1 + -0x74)) {

      do {

        piVar5 = (int *)CVOGReaction_ResolveObjectTarget(uVar2,*puVar7,puVar7[1]);

        if (piVar5 != (int *)0x0) {

          (**(code **)(*piVar5 + 0x130))(param_2,param_3,param_4,param_5,uVar2);

        }

        puVar7 = puVar7 + 2;

      } while (puVar7 != *(uint32_t /* width from decompiler */ **)(param_1 + -0x74));

    }

    if ((cVar6 != '\0') &&

       (puVar7 = *(uint32_t /* width from decompiler */ **)(param_1 + -0x98), puVar7 != *(uint32_t /* width from decompiler */ **)(param_1 + -0x94))) {

      do {

        piVar5 = (int *)CVOGReaction_ResolveObjectTarget(uVar2,*puVar7,puVar7[1]);

        if (piVar5 != (int *)0x0) {

          (**(code **)(*piVar5 + 0x130))(param_2,param_3,param_4,param_5,uVar2);

        }

        puVar7 = puVar7 + 4;

      } while (puVar7 != *(uint32_t /* width from decompiler */ **)(param_1 + -0x94));

    }

    *(uint8_t *)(param_1 + -0x36) = 0;

  }

  return;

}
