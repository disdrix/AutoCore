// =============================================================================
// FUN_00638be0
// -----------------------------------------------------------------------------
// Stable ID: aa_00638be0
// Address:   0x00638be0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00638be0 @ 0x00638be0
// Stable ID: aa_00638be0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_004bb0d0, FUN_00638be0.
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

void __fastcall FUN_00638be0(int param_1)



{

  bool bVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  if (*(char *)((*(int **)(param_1 + 0x18))[0x29] + 0x7e) != '\0') {

    iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

    uStack_10 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x228);

    uStack_c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x22c);

    uStack_8 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x230);

    uStack_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x234);

    iVar2 = FUN_004bb0d0(&uStack_10);

    if (iVar2 == 0) {

      iVar2 = (**(code **)(**(int **)(param_1 + 0x18) + 0x214))();

      if ((*(char *)(*(int *)(iVar2 + 0xf8) + 0x50) == '\0') ||

         ((*(int *)(iVar2 + 0x250) != 0 &&

          (*(char *)(*(int *)(*(int *)(iVar2 + 0x250) + 0xf8) + 0x50) == '\0')))) {

        bVar1 = true;

      }

      else {

        bVar1 = false;

      }

      if (*(int *)(iVar2 + 0x208) == 0) {

        *(uint *)(iVar2 + 0x208) = g_dwClientTickMs;

        return;

      }

      if (((*(char *)(iVar2 + 0x204) == '\0') || (!bVar1)) &&

         (0x9c4 < g_dwClientTickMs - *(int *)(iVar2 + 0x208))) {

        (**(code **)(**(int **)(param_1 + 0x18) + 0x118))();

        *(uint32_t /* width from decompiler */ *)(iVar2 + 0x208) = 0;

      }

    }

  }

  return;

}
