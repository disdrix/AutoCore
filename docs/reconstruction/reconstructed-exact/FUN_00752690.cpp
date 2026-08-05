// =============================================================================
// FUN_00752690
// -----------------------------------------------------------------------------
// Stable ID: aa_00752690
// Address:   0x00752690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752690 @ 0x00752690
// Stable ID: aa_00752690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×1.
//  - Notable callees: FUN_00752690, _aligned_free.
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

void FUN_00752690(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int unaff_EDI;

  

  iVar4 = *(int *)(unaff_EDI + 8);

  if (iVar4 != 0) {

    iVar2 = *(int *)(iVar4 + 0x18);

    for (iVar4 = *(int *)(iVar4 + 0x14); iVar4 < iVar2; iVar4 = iVar4 + 1) {

      piVar5 = (int *)((uint)*(ushort *)(*(int *)(*(int *)(unaff_EDI + 8) + 0x10) + 4 + iVar4 * 8) +

                      *(int *)(unaff_EDI + 0xc));

      iVar3 = piVar5[1];

      if (iVar3 != 0) {

        piVar1 = (int *)(iVar3 + 8);

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*(int *)(iVar3 + 4) + 8))();

        }

      }

      piVar5 = (int *)*piVar5;

      if (piVar5 != (int *)0x0) {

        (**(code **)(*piVar5 + 8))(piVar5);

      }

    }

    _aligned_free(*(void **)(unaff_EDI + 0xc));

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xc) = 0;

    iVar4 = *(int *)(unaff_EDI + 8);

    if (iVar4 != 0) {

      piVar5 = (int *)(iVar4 + 8);

      *piVar5 = *piVar5 + -1;

      if (*piVar5 == 0) {

        (**(code **)(*(int *)(iVar4 + 4) + 8))();

      }

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8) = 0;

      *(uint16_t *)(unaff_EDI + 0x1c) = 0xffff;

      *(uint16_t *)(unaff_EDI + 0x1e) = 0xffff;

      *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14) = 0;

      return;

    }

  }

  *(uint16_t *)(unaff_EDI + 0x1c) = 0xffff;

  *(uint16_t *)(unaff_EDI + 0x1e) = 0xffff;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x14) = 0;

  return;

}
