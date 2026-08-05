// =============================================================================
// FUN_00755db0
// -----------------------------------------------------------------------------
// Stable ID: aa_00755db0
// Address:   0x00755db0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00755db0 @ 0x00755db0
// Stable ID: aa_00755db0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×8, do×2, while×2, return×1.
//  - Notable callees: FUN_00755db0×2, FUN_004432e0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00755db0(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  

  iVar2 = (**(code **)(*param_2 + 4))();

  if (iVar2 == 0x47424459) {

    uVar3 = 0;

    if (*(int *)(param_1 + 0x50) != 0) {

      uVar3 = (*(int *)(param_1 + 0x54) - *(int *)(param_1 + 0x50)) / 0x14;

    }

    uVar4 = 0;

    if (uVar3 != 0) {

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x50);

      puVar5 = puVar1;

      do {

        if ((int *)*puVar5 == param_2) {

          if ((uint32_t /* width from decompiler */ *)puVar1[uVar4 * 5 + 1] != (uint32_t /* width from decompiler */ *)0x0) {

            (*(code *)**(uint32_t /* width from decompiler */ **)puVar1[uVar4 * 5 + 1])(1);

          }

          if ((uint32_t /* width from decompiler */ *)puVar1[uVar4 * 5 + 2] != (uint32_t /* width from decompiler */ *)0x0) {

            (*(code *)**(uint32_t /* width from decompiler */ **)puVar1[uVar4 * 5 + 2])(1);

          }

          FUN_004432e0();

          break;

        }

        uVar4 = uVar4 + 1;

        puVar5 = puVar5 + 5;

      } while (uVar4 < uVar3);

    }

  }

  if (param_2[0x1b] == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = param_2[0x1c] - param_2[0x1b] >> 2;

  }

  iVar6 = 0;

  if (0 < iVar2) {

    do {

      FUN_00755db0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_2[0x1b] + iVar6 * 4) + 8));

      iVar6 = iVar6 + 1;

    } while (iVar6 < iVar2);

  }

  return 0;

}
