// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00439f10
// -----------------------------------------------------------------------------
// Stable ID: aa_00439f10
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody
// Address:   0x00439f10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×10, return×7.
//  - Notable callees: FUN_004384f0×2, FUN_0043a6e0×2, FUN_0043aac0×2, FUN_00690210×2, FUN_00437f20, FUN_00438490, FUN_00439f10.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxBody
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00439f10(int param_1)



{

  char cVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  uint uVar6;

  int unaff_ESI;

  

  if (unaff_ESI == param_1) {

    return;

  }

  if (*(int *)(param_1 + 4) != 0) {

    iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4);

    iVar4 = iVar5 >> 0x1f;

    iVar5 = iVar5 / 0x38 + iVar4;

    uVar6 = iVar5 - iVar4;

    if (iVar5 != iVar4) {

      iVar4 = *(int *)(unaff_ESI + 4);

      if (iVar4 == 0) {

        uVar2 = 0;

      }

      else {

        uVar2 = (*(int *)(unaff_ESI + 8) - iVar4) / 0x38;

      }

      if (uVar6 <= uVar2) {

        uVar3 = FUN_0043a6e0(param_1);

        FUN_004384f0(uVar3,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

        iVar4 = 0;

        if (*(int *)(param_1 + 4) != 0) {

          iVar4 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x38;

        }

        *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 4) + iVar4 * 0x38;

        return;

      }

      if (iVar4 == 0) {

        uVar2 = 0;

      }

      else {

        uVar2 = (*(int *)(unaff_ESI + 0xc) - iVar4) / 0x38;

      }

      if (uVar2 < uVar6) {

        if (iVar4 != 0) {

          FUN_004384f0(iVar4,*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8));

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(unaff_ESI + 4));

        }

        uVar3 = FUN_00690210();

        cVar1 = FUN_00438490(uVar3);

        if (cVar1 == '\0') {

          return;

        }

        uVar3 = FUN_0043aac0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 4),param_1);

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar3;

        return;

      }

      FUN_00690210();

      FUN_0043a6e0(param_1);

      uVar3 = FUN_0043aac0(*(uint32_t /* width from decompiler */ *)(param_1 + 8),*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),param_1);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8) = uVar3;

      return;

    }

  }

  FUN_00437f20();

  return;

}
