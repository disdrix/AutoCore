// =============================================================================
// Named_CalleeOf_Named_assManager_0044e8c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044e8c0
// Callee of Named_assManager (+1 other named callers)
// Address:   0x0044e8c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_assManager: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_assManager (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_0043b870, FUN_0044e8c0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_assManager (+1 other named callers)
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_assManager_0044e8c0(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  uint uVar2;

  uint uVar3;

  int *piVar4;

  uint *unaff_EBX;

  int unaff_EDI;

  

  uVar2 = *(uint *)(unaff_EDI + 0x20);

  uVar3 = FUN_0043b870();

  uVar3 = uVar3 & uVar2;

  if (*(uint *)(unaff_EDI + 0x24) <= uVar3) {

    uVar3 = uVar3 + (-1 - (uVar2 >> 1));

  }

  piVar1 = (int *)(*(int *)(unaff_EDI + 0x14) + uVar3 * 4);

  piVar4 = (int *)*piVar1;

  if (piVar4 != (int *)piVar1[1]) {

    do {

      if (*unaff_EBX <= (uint)piVar4[2]) {

        if ((uint)piVar4[2] <= *unaff_EBX) {

          *param_1 = piVar4;

          return param_1;

        }

        *param_1 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

        return param_1;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)piVar1[1]);

  }

  *param_1 = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 8);

  return param_1;

}
