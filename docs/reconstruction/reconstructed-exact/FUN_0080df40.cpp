// =============================================================================
// FUN_0080df40
// -----------------------------------------------------------------------------
// Stable ID: aa_0080df40
// Address:   0x0080df40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080df40 @ 0x0080df40
// Stable ID: aa_0080df40
// Embedded strings (evidence for future rename):
//   - "You are not skilled enough to Reverse Engineer that."
//   - "You do not have enough room in your inventory."
//   - "Reverse Engineer failed."
//   - "You cannot Reverse Engineer crafting materials."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, return×2, switch×1, while×1.
//  - Notable callees: Client_RefreshOpenMissionUiWindows, FUN_00512290, FUN_00513de0, FUN_007a69d0, FUN_007a6de0, FUN_007fdfb0, FUN_0080df40.
//  - Strings: "You are not skilled enough to Reverse Engineer that."; "You do not have enough room in your inventory."; "Reverse Engineer failed."; "You cannot Reverse Engineer crafting materials.".
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

void FUN_0080df40(int param_1,int param_2)



{

  int iVar1;

  uint16_t uVar2;

  int *piVar3;

  int iVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint uVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ uVar11;

  

  FUN_007a69d0();

  switch(*(uint32_t /* width from decompiler */ *)(param_2 + 0x14)) {

  case 1:

    pcVar8 = "You are not skilled enough to Reverse Engineer that.";

    break;

  case 2:

    pcVar8 = "You do not have enough room in your inventory.";

    break;

  case 3:

    pcVar8 = "Reverse Engineer failed.";

    break;

  case 4:

    pcVar8 = "You cannot Reverse Engineer crafting materials.";

    break;

  default:

    piVar3 = (int *)CVOGReaction_ResolveObjectTarget

                              (1,*(uint32_t /* width from decompiler */ *)(param_2 + 8),*(uint32_t /* width from decompiler */ *)(param_2 + 0xc));

    if (piVar3 != (int *)0x0) {

      uVar7 = 0;

      iVar4 = (**(code **)(*piVar3 + 0x80))();

      if (iVar4 != 0) {

        do {

          uVar5 = (**(code **)(*piVar3 + 0x7c))(uVar7);

          if ((uVar5 & 0xffff) != 0xffffffff) {

            iVar4 = *piVar3;

            uVar2 = (**(code **)(iVar4 + 0x7c))(uVar7,1);

            (**(code **)(iVar4 + 0x68))(uVar2);

            param_2 = param_1;

          }

          uVar7 = uVar7 + 1;

          uVar5 = (**(code **)(*piVar3 + 0x80))();

        } while (uVar7 < uVar5);

      }

      (**(code **)(*piVar3 + 0x84))();

      (**(code **)(*piVar3 + 0x74))();

      FUN_00513de0(*(uint8_t *)(param_2 + 0x10));

      if ((*(char *)(param_2 + 0x10) == '\0') && (*(int *)(param_1 + 0xe98) != 0)) {

        iVar4 = *(int *)(param_1 + 0xe98);

        iVar1 = *(int *)(*(int *)(iVar4 + 4) + 4);

        piVar3[0x3e] = *(int *)(iVar1 + 0x164 + iVar4);

        piVar3[0x3f] = *(int *)(iVar1 + 0x168 + iVar4);

        uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                     *(int *)(param_1 + 0xe98)) + 0x160))();

        FUN_00512290(uVar6);

      }

    }

    Client_RefreshOpenMissionUiWindows(param_1);

    return;

  }

  uVar11 = 0;

  uVar10 = 1;

  uVar9 = 0xffffffff;

  uVar6 = FUN_007a6de0(pcVar8,0xffffffff);

  FUN_007fdfb0(param_1,uVar6,uVar9,uVar10,uVar11);

  return;

}
