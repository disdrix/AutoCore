// =============================================================================
// FUN_008d8a10
// -----------------------------------------------------------------------------
// Stable ID: aa_008d8a10
// Address:   0x008d8a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d8a10 @ 0x008d8a10
// Stable ID: aa_008d8a10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, goto×2, while×1, for×1, return×1.
//  - Notable callees: FUN_008d8a10, FUN_00913030.
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

void FUN_008d8a10(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  

  FUN_00913030();

  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b77c + 0xaf0) + 4) + 4) + 4 +

                               *(int *)(DAT_00d1b77c + 0xaf0)) + 0x1cc))();

  iVar2 = *(int *)(iVar2 + 8);

  if (iVar2 != 0) {

    iVar6 = 0;

    while( true ) {

      if (*(int *)(iVar2 + 100) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(*(int *)(iVar2 + 100) + 0x10);

      }

      if (iVar4 <= iVar6) break;

      if (*(int *)(iVar2 + 100) != 0) {

        puVar5 = *(uint32_t /* width from decompiler */ **)(*(int *)(iVar2 + 100) + 0xc);

        iVar4 = iVar6;

        for (puVar1 = (uint32_t /* width from decompiler */ *)*puVar5; puVar1 != puVar5; puVar1 = (uint32_t /* width from decompiler */ *)*puVar1) {

          if (iVar4 == 0) {

            piVar3 = puVar1 + 2;

            goto LAB_008d8ab7;

          }

          iVar4 = iVar4 + -1;

        }

      }

      piVar3 = (int *)0x0;

LAB_008d8ab7:

      iVar4 = *piVar3;

      if (*(int *)(iVar4 + 8) == 6) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x50c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x20);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x510) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x24);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x514) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x28);

        puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x518);

LAB_008d8b0b:

        *puVar5 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10);

        puVar5[1] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x14);

        puVar5[2] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x18);

        puVar5[3] = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x1c);

      }

      else if (*(int *)(iVar4 + 8) == 7) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x528) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x20);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x52c) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x24);

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x530) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x28);

        puVar5 = (uint32_t /* width from decompiler */ *)(param_1 + 0x534);

        goto LAB_008d8b0b;

      }

      iVar6 = iVar6 + 1;

    }

  }

  return;

}
