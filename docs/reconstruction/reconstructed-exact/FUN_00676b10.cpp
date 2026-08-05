// =============================================================================
// FUN_00676b10
// -----------------------------------------------------------------------------
// Stable ID: aa_00676b10
// Address:   0x00676b10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00676b10 @ 0x00676b10
// Stable ID: aa_00676b10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, while×2.
//  - Notable callees: FUN_00676b10.
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

void __fastcall FUN_00676b10(int param_1)



{

  int *piVar1;

  void *pvVar2;

  uint uVar3;

  int iVar4;

  

  iVar4 = *(int *)(param_1 + 0x10);

  while (iVar4 != 0) {

    if (*(int *)(param_1 + 0x10) != 0) {

      uVar3 = *(int *)(param_1 + 0x10) + -1 + *(int *)(param_1 + 0xc);

      if (*(uint *)(param_1 + 8) <= uVar3) {

        uVar3 = uVar3 - *(uint *)(param_1 + 8);

      }

      (**(code **)**(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 4) + uVar3 * 4))(0);

      piVar1 = (int *)(param_1 + 0x10);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

      }

    }

    iVar4 = *(int *)(param_1 + 0x10);

  }

  iVar4 = *(int *)(param_1 + 8);

  while (iVar4 != 0) {

    pvVar2 = *(void **)(*(int *)(param_1 + 4) + -4 + iVar4 * 4);

    iVar4 = iVar4 + -1;

    if (pvVar2 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

  }

  if (*(void **)(param_1 + 4) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 4) = 0;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 4));

}
