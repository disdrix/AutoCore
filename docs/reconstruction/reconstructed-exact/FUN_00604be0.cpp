// =============================================================================
// FUN_00604be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00604be0
// Address:   0x00604be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00604be0 @ 0x00604be0
// Stable ID: aa_00604be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: return×4, if×3, for×1.
//  - Notable callees: FUN_00604be0.
//  - Return sites: 4.

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

void __fastcall FUN_00604be0(int param_1)



{

  int iVar1;

  void *pvVar2;

  uint uVar3;

  

  for (uVar3 = 0;

      (iVar1 = *(int *)(param_1 + 8), iVar1 != 0 &&

      (uVar3 < (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 2))); uVar3 = uVar3 + 1) {

    pvVar2 = *(void **)(iVar1 + uVar3 * 4);

    if (pvVar2 != (void *)0x0) {

      if (*(void **)((int)pvVar2 + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)((int)pvVar2 + 8));

      }

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0xc) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar2 + 0x10) = 0;

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar2);

    }

  }

  if (*(void **)(param_1 + 8) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(*(void **)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  return;

}
