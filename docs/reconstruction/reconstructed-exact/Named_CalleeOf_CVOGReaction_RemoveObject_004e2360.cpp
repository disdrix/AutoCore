// =============================================================================
// Named_CalleeOf_CVOGReaction_RemoveObject_004e2360
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2360
// Callee of CVOGReaction_RemoveObject
// Address:   0x004e2360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from CVOGReaction_RemoveObject: event/reaction helper. Evidence string: "HashListError: Went to node we already touched! Attempting repair!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "HashListError: Went to node we already touched! Attempting repair!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×2, while×2, for×1.
//  - Notable callees: FUN_004e2360, FUN_007a4480.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of CVOGReaction_RemoveObject
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

void __fastcall Named_CalleeOf_CVOGReaction_RemoveObject_004e2360(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 4);

  if (*(int *)(param_1 + 4) != 0) {

    do {

      iVar1 = iVar2;

      *(uint8_t *)(iVar1 + 8) = 1;

      iVar2 = *(int *)(iVar1 + 0x10);

      if (iVar2 == 0) {

        for (iVar2 = *(int *)(param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

          *(uint8_t *)(iVar2 + 8) = 0;

        }

        return;

      }

    } while (*(char *)(iVar2 + 8) == '\0');

    FUN_007a4480(1,"HashListError: Went to node we already touched! Attempting repair!");

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10) = 0;

    iVar2 = *(int *)(param_1 + 4);

    if (iVar2 != 0) {

      do {

        *(uint8_t *)(iVar2 + 8) = 0;

        iVar2 = *(int *)(iVar2 + 0x10);

      } while (iVar2 != 0);

      return;

    }

  }

  return;

}
