// =============================================================================
// FUN_005a0930
// -----------------------------------------------------------------------------
// Stable ID: aa_005a0930
// Address:   0x005a0930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a0930 @ 0x005a0930
// Stable ID: aa_005a0930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, while×3, do×2.
//  - Notable callees: FUN_00780c30×2, FUN_005a0930.
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

void __thiscall FUN_005a0930(int param_1,int param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ **ppuVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint *puVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *local_8;

  uint32_t /* width from decompiler */ *local_4;

  

  puVar5 = *(uint **)(param_2 + 4);

  if (puVar5 != (uint *)0x0) {

    local_4 = (uint32_t /* width from decompiler */ *)((int)*(uint **)(param_2 + 8) - (int)puVar5 >> 2);

    if (local_4 != (uint32_t /* width from decompiler */ *)0x0) {

      if (puVar5 == *(uint **)(param_2 + 8)) {

        return;

      }

      do {

        iVar6 = *(int *)(param_1 + 0xb0);

        puVar4 = (uint32_t /* width from decompiler */ *)(*(uint32_t /* width from decompiler */ **)(iVar6 + 0xbc))[1];

        cVar1 = *(char *)((int)puVar4 + 0x21);

        local_8 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0xbc);

        while (cVar1 == '\0') {

          if (((int)puVar4[5] < 1) && (((int)puVar4[5] < 0 || ((uint)puVar4[4] < *puVar5)))) {

            puVar2 = (uint32_t /* width from decompiler */ *)puVar4[2];

            puVar4 = local_8;

          }

          else {

            puVar2 = (uint32_t /* width from decompiler */ *)*puVar4;

          }

          local_8 = puVar4;

          puVar4 = puVar2;

          cVar1 = *(char *)((int)puVar2 + 0x21);

        }

        if (((local_8 == *(uint32_t /* width from decompiler */ **)(iVar6 + 0xbc)) || (0 < (int)local_8[5])) ||

           (((uint)local_8[5] < 0x80000000 && (*puVar5 < (uint)local_8[4])))) {

          local_4 = *(uint32_t /* width from decompiler */ **)(iVar6 + 0xbc);

          ppuVar3 = &local_4;

        }

        else {

          ppuVar3 = &local_8;

        }

        if ((*ppuVar3 != *(uint32_t /* width from decompiler */ **)(iVar6 + 0xbc)) && ((*ppuVar3)[6] != 0)) {

          FUN_00780c30();

        }

        puVar5 = puVar5 + 1;

      } while (puVar5 != *(uint **)(param_2 + 8));

      return;

    }

  }

  iVar6 = 0;

  if (0 < *(int *)(*(int *)(param_1 + 0xb0) + 0xc)) {

    do {

      FUN_00780c30();

      iVar6 = iVar6 + 1;

    } while (iVar6 < *(int *)(*(int *)(param_1 + 0xb0) + 0xc));

  }

  return;

}
