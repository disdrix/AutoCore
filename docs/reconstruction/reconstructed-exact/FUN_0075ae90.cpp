// =============================================================================
// FUN_0075ae90
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ae90
// Address:   0x0075ae90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075ae90 @ 0x0075ae90
// Stable ID: aa_0075ae90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~91 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, for×1, return×1.
//  - Notable callees: FUN_0043ffb0×2, FUN_0075ae90.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0075ae90(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ uVar8;

  int *piVar9;

  uint32_t /* width from decompiler */ *local_24;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b2538;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  local_24 = operator_new(0x28);

  if (local_24 == (uint32_t /* width from decompiler */ *)0x0) {

    local_24 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    local_24[1] = param_2;

    *local_24 = &PTR_FUN_00a9f174;

    local_24[3] = 0;

    local_24[4] = 0;

    local_24[5] = 0;

    local_24[7] = 0;

    local_24[8] = 0;

    local_24[9] = 0;

  }

  local_4 = 0xffffffff;

  piVar3 = *(int **)(param_1 + 0x10);

  for (piVar9 = *(int **)(param_1 + 0xc); piVar9 != piVar3; piVar9 = piVar9 + 4) {

    uVar8 = 0;

    piVar6 = *(int **)(*(int *)(param_1 + 4) + 0xc0);

    puVar7 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xc0);

    piVar4 = *(int **)(*(int *)(param_1 + 4) + 0xc4);

    if (piVar6 != piVar4) {

      do {

        if (*piVar6 == *piVar9) {

          uVar8 = *puVar7;

          break;

        }

        piVar6 = piVar6 + 1;

        puVar7 = puVar7 + 1;

      } while (piVar6 != piVar4);

    }

    iVar1 = piVar9[3];

    iVar2 = piVar9[2];

    FUN_0043ffb0(0,0,0,0);

    iVar5 = local_24[4];

    *(uint32_t /* width from decompiler */ *)(iVar5 + -0x10) = uVar8;

    *(int *)(iVar5 + -8) = iVar2;

    *(uint8_t *)(iVar5 + -0xc) = 0;

    *(int *)(iVar5 + -4) = iVar1;

  }

  piVar3 = *(int **)(param_1 + 0x20);

  piVar9 = *(int **)(param_1 + 0x1c);

  do {

    if (piVar9 == piVar3) {

      ExceptionList = local_c;

      return local_24;

    }

    uVar8 = 0;

    piVar6 = *(int **)(*(int *)(param_1 + 4) + 0xd0);

    puVar7 = *(uint32_t /* width from decompiler */ **)(param_2 + 0xd0);

    piVar4 = *(int **)(*(int *)(param_1 + 4) + 0xd4);

    if (piVar6 != piVar4) {

      do {

        if (*piVar6 == *piVar9) {

          uVar8 = *puVar7;

          break;

        }

        piVar6 = piVar6 + 1;

        puVar7 = puVar7 + 1;

      } while (piVar6 != piVar4);

    }

    iVar1 = piVar9[3];

    iVar2 = piVar9[2];

    FUN_0043ffb0(0,0,0,0);

    iVar5 = local_24[8];

    piVar9 = piVar9 + 4;

    *(int *)(iVar5 + -8) = iVar2;

    *(uint32_t /* width from decompiler */ *)(iVar5 + -0x10) = uVar8;

    *(uint8_t *)(iVar5 + -0xc) = 0;

    *(int *)(iVar5 + -4) = iVar1;

  } while( true );

}
