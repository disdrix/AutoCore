// =============================================================================
// FUN_00853020
// -----------------------------------------------------------------------------
// Stable ID: aa_00853020
// Address:   0x00853020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00853020 @ 0x00853020
// Stable ID: aa_00853020
// Embedded strings (evidence for future rename):
//   - ".dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×11, do×2, while×2, return×1.
//  - Notable callees: FUN_00853020, strncat, strncpy.
//  - Strings: ".dds".
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

void FUN_00853020(int param_1,int param_2,int param_3)



{

  int iVar1;

  int *piVar2;

  char *_Source;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int *piVar5;

  size_t _Count;

  uint32_t /* width from decompiler */ *local_88;

  char acStack_80 [128];

  

  *(int *)(param_1 + 0x55c) = param_2;

  if (((param_2 != 0) && (param_3 != 0)) && (iVar4 = 0, 0 < param_2)) {

    local_88 = (uint32_t /* width from decompiler */ *)(param_1 + 0x570);

    piVar5 = (int *)(param_1 + 0x53c);

    do {

      *local_88 = *(uint32_t /* width from decompiler */ *)(param_3 + iVar4 * 8);

      local_88[1] = *(uint32_t /* width from decompiler */ *)(param_3 + 4 + iVar4 * 8);

      piVar2 = (int *)CVOGReaction_ResolveObjectTarget

                                (1,*(uint32_t /* width from decompiler */ *)(param_3 + iVar4 * 8),

                                 *(uint32_t /* width from decompiler */ *)(param_3 + 4 + iVar4 * 8));

      if (piVar2 == (int *)0x0) {

        *(int *)(param_1 + 0x55c) = *(int *)(param_1 + 0x55c) + -1;

      }

      else {

        if (*piVar5 != 0) {

          _Count = 0x80;

          _Source = (char *)(**(code **)(*piVar2 + 0x1c4))();

          strncpy(acStack_80,_Source,_Count);

          strncat(acStack_80,".dds",0x80);

          (**(code **)(*(int *)*piVar5 + 0x50))(acStack_80,1,0);

          (**(code **)(*(int *)*piVar5 + 0xcc))(1);

          (**(code **)(*(int *)*piVar5 + 0x34c))();

        }

        if (piVar5[-8] != 0) {

          (**(code **)(*(int *)piVar5[-8] + 4))(1);

        }

        if (piVar5[-4] != 0) {

          (**(code **)(*(int *)piVar5[-4] + 4))(1);

        }

        if (piVar5[4] != 0) {

          iVar1 = *(int *)piVar5[4];

          uVar3 = (**(code **)(*piVar2 + 0x15c))(1,1);

          (**(code **)(iVar1 + 0x1d8))(uVar3);

          (**(code **)(*(int *)piVar5[4] + 0xcc))(1);

          (**(code **)(*(int *)piVar5[4] + 0x34c))();

        }

        local_88 = local_88 + 2;

      }

      iVar4 = iVar4 + 1;

      piVar5 = piVar5 + 1;

    } while (iVar4 < param_2);

  }

  iVar4 = *(int *)(param_1 + 0x55c);

  if (iVar4 < 4) {

    piVar5 = (int *)(param_1 + 0x52c + iVar4 * 4);

    iVar4 = 4 - iVar4;

    do {

      if (piVar5[-4] != 0) {

        (**(code **)(*(int *)piVar5[-4] + 4))(0);

      }

      if (*piVar5 != 0) {

        (**(code **)(*(int *)*piVar5 + 4))(0);

      }

      if (piVar5[4] != 0) {

        (**(code **)(*(int *)piVar5[4] + 4))(0);

      }

      if (piVar5[8] != 0) {

        (**(code **)(*(int *)piVar5[8] + 4))(0);

      }

      piVar5 = piVar5 + 1;

      iVar4 = iVar4 + -1;

    } while (iVar4 != 0);

  }

  return;

}
