// =============================================================================
// Named_CalleeOf_Named_effTextureImpl_0096c810
// -----------------------------------------------------------------------------
// Stable ID: aa_0096c810
// Callee of Named_effTextureImpl (+1 other named callers)
// Address:   0x0096c810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effTextureImpl: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_effTextureImpl (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0044b1f0, FUN_0096c810.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_effTextureImpl (+1 other named callers)
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

int Named_CalleeOf_Named_effTextureImpl_0096c810(int param_1)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int local_14;

  int local_10;

  int local_c;

  int local_8 [2];

  

  iVar1 = param_1;

  if ((*(int *)(param_1 + 0x10) != 0) &&

     ((*(int *)(param_1 + 0x30) == 1 || (*(int *)(param_1 + 0x30) == 2)))) {

    local_14 = *(int *)(param_1 + 0x34);

    piVar3 = (int *)(param_1 + 0x1c);

    local_10 = *(int *)(param_1 + 0x48);

    param_1 = 0;

    if (0 < local_10) {

      iVar4 = *piVar3 / 2;

      local_c = 1;

      local_8[1] = 1;

      do {

        iVar2 = FUN_0044b1f0();

        param_1 = param_1 + iVar2 * local_14;

        local_8[0] = iVar4;

        piVar3 = &local_c;

        if (0 < iVar4) {

          piVar3 = local_8;

        }

        iVar4 = *piVar3 / 2;

        if ((*(byte *)(iVar1 + 0x2c) & 4) != 0) {

          local_14 = local_14 / 2;

        }

        local_10 = local_10 + -1;

        local_8[0] = iVar4;

      } while (local_10 != 0);

    }

    return param_1;

  }

  return 0;

}
