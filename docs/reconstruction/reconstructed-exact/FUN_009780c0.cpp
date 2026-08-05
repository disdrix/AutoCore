// =============================================================================
// FUN_009780c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009780c0
// Address:   0x009780c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009780c0 @ 0x009780c0
// Stable ID: aa_009780c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0053d970, FUN_00560e90, FUN_009780c0.
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

void FUN_009780c0(void)



{

  int iVar1;

  int *piVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x24) + 4) + 4) + 4 +

                               *(int *)(unaff_ESI + 0x24)) + 0x19c))();

  if (*(int *)(iVar1 + 8) == 0) {

    *(uint8_t *)(unaff_ESI + 8) = 1;

    return;

  }

  *(uint8_t *)(unaff_ESI + 8) = 0;

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x24) + 4) + 4) + 4 +

                               *(int *)(unaff_ESI + 0x24)) + 0x19c))();

  *(uint32_t /* width from decompiler */ *)(*(int *)(iVar1 + 8) + 0x28) = 0x10;

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x24) + 4) + 4) + 4 +

                               *(int *)(unaff_ESI + 0x24)) + 0x19c))();

  if (*(int *)(iVar1 + 8) != 0) {

    uVar3 = 1;

    iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x24) + 4) + 4) + 4 +

                                 *(int *)(unaff_ESI + 0x24)) + 0x19c))(1);

    FUN_00560e90(*(uint32_t /* width from decompiler */ *)(iVar1 + 8),uVar3);

    uVar3 = 1;

    (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 0x24) + 4) + 4) + 4 +

                         *(int *)(unaff_ESI + 0x24)) + 0x19c))(1);

    FUN_0053d970(uVar3);

    iVar1 = *(int *)(unaff_ESI + 0x24);

    if (((*(char *)(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0xa8 + iVar1) + 0xf5) != '\0') &&

        (piVar2 = *(int **)(iVar1 + 0x48), piVar2 != (int *)0x0)) ||

       ((*(int *)(iVar1 + 0x250) != 0 &&

        (piVar2 = *(int **)(*(int *)(iVar1 + 0x250) + 0x48), piVar2 != (int *)0x0)))) {

      iVar1 = (**(code **)(*piVar2 + 0x48))();

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = *(uint32_t /* width from decompiler */ *)(iVar1 + 4);

    }

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = 0;

  }

  return;

}
