// =============================================================================
// FUN_006f4170
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4170
// Address:   0x006f4170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4170 @ 0x006f4170
// Stable ID: aa_006f4170
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_006f4170.
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

void __thiscall FUN_006f4170(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  uint *puVar5;

  uint *puVar6;

  uint uVar7;

  int iVar8;

  uint local_c;

  uint local_4;

  

  iVar3 = param_3;

  puVar6 = (uint *)*param_2;

  uVar7 = *puVar6;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x34) = 0;

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x30) = 0xffffffff;

  param_3 = param_2[1];

  local_c = uVar7;

  if (-1 < param_3 + -1) {

    do {

      uVar1 = *puVar6;

      if (local_c < uVar1) {

        local_c = uVar1;

      }

      if (uVar1 < uVar7) {

        uVar7 = uVar1;

      }

      iVar4 = (**(code **)(**(int **)(param_1 + 0x28) + 0x18))(puVar6,&local_4);

      if (*(int *)(iVar3 + 0x2c) < iVar4) {

        *(int *)(iVar3 + 0x2c) = iVar4;

      }

      iVar8 = 0;

      if (0 < iVar4) {

        puVar5 = (uint *)(iVar3 + 0x34);

        do {

          uVar1 = (&local_4)[iVar8];

          if (uVar1 < puVar5[-1]) {

            puVar5[-1] = uVar1;

          }

          if (*puVar5 < uVar1) {

            *puVar5 = uVar1;

          }

          iVar8 = iVar8 + 1;

          puVar5 = puVar5 + 1;

        } while (iVar8 < iVar4);

      }

      puVar6 = puVar6 + 4;

      param_3 = param_3 + -1;

    } while (param_3 != 0);

  }

  uVar2 = param_2[1];

  *(uint *)(iVar3 + 0x24) = uVar7;

  *(uint32_t /* width from decompiler */ *)(iVar3 + 8) = uVar2;

  *(uint *)(iVar3 + 0x28) = local_c;

  return;

}
