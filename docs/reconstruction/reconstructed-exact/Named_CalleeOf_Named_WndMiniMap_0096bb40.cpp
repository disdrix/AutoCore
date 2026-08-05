// =============================================================================
// Named_CalleeOf_Named_WndMiniMap_0096bb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0096bb40
// Callee of Named_WndMiniMap (+1 other named callers)
// Address:   0x0096bb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_WndMiniMap: UI/dialog helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_WndMiniMap (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×5, goto×2, return×1.
//  - Notable callees: FUN_0096bb40.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_WndMiniMap (+1 other named callers)
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

void __thiscall Named_CalleeOf_Named_WndMiniMap_0096bb40(int param_1,int param_2)



{

  uint uVar1;

  

  uVar1 = *(uint *)(param_1 + 0x2c) & 0xf;

  if (uVar1 != 1) {

    if (uVar1 == 2) {

      if (param_2 < 0) {

        param_2 = *(int *)(param_1 + 0x38);

      }

      (**(code **)(**(int **)(param_1 + 0x10) + 0x50))

                (*(int **)(param_1 + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x3c),param_2);

      goto LAB_0096bb6d;

    }

    if (uVar1 != 4) goto LAB_0096bb6d;

  }

  if (param_2 < 0) {

    param_2 = *(int *)(param_1 + 0x38);

  }

  (**(code **)(**(int **)(param_1 + 0x10) + 0x50))(*(int **)(param_1 + 0x10),param_2);

LAB_0096bb6d:

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x38) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x40) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x44) = 0;

  return;

}
