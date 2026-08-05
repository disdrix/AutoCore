// =============================================================================
// FUN_005d2600
// -----------------------------------------------------------------------------
// Stable ID: aa_005d2600
// Address:   0x005d2600  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d2600 @ 0x005d2600
// Stable ID: aa_005d2600
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00512460, FUN_005d2600.
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

void __fastcall FUN_005d2600(int param_1)



{

  uint *puVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  

  iVar2 = *(int *)(param_1 + 0x5c);

  if ((iVar2 != 0) && (*(int *)(param_1 + 0x50) != 0)) {

    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x50) + 0x1d8))();

    piVar3 = *(int **)(*(int *)(*(int *)(piVar4[1] + 4) + 0xa8 + (int)piVar4) + 0xe8a0);

    if ((piVar3 == (int *)0x0) ||

       ((iVar5 = (**(code **)(*piVar3 + 0x1dc))(), *(char *)(iVar5 + 0x6b9) == '\0' ||

        (*(int *)(param_1 + 0x50) !=

         *(int *)(*(int *)(*(int *)(*(int *)(piVar4[1] + 4) + 0xa8 + (int)piVar4) + 0xe8a0) + 0xa0))

        ))) {

      *(uint8_t *)(piVar4 + 0x9b) = *(uint8_t *)(iVar2 + 0x127);

      (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x240))

                (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x10));

      (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x248))

                (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x14));

      puVar1 = (uint *)((int)piVar4 + *(int *)(piVar4[1] + 4) + 0x180);

      *puVar1 = *puVar1 ^ ((uint)*(byte *)(iVar2 + 0x8a) << 8 ^

                          *(uint *)((int)piVar4 + *(int *)(piVar4[1] + 4) + 0x180)) & 0x100;

      (**(code **)(*piVar4 + 0x78))(&stack0xffffff88,0);

      (**(code **)(*(int *)(*(int *)(piVar4[1] + 4) + 4 + (int)piVar4) + 0x294))

                (*(uint32_t /* width from decompiler */ *)(iVar2 + 0x20));

      FUN_00512460(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c));

    }

  }

  return;

}
