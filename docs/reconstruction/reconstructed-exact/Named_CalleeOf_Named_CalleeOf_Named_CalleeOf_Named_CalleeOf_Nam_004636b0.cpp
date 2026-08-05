// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004636b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004636b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBuff
// Address:   0x004636b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBuff: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0044c010, FUN_00462820, FUN_004633e0, FUN_004636b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_gfxIndexBuff
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

uint32_t /* width from decompiler */ * Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004636b0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  int in_EAX;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar3 = param_2;

  if (param_1 != in_EAX) {

    puVar2 = (uint32_t /* width from decompiler */ *)(in_EAX + 4);

    puVar4 = param_2 + 1;

    do {

      puVar1 = (uint32_t /* width from decompiler */ *)(in_EAX + -0x20);

      in_EAX = in_EAX + -0x20;

      puVar2 = puVar2 + -8;

      puVar3 = puVar3 + -8;

      *puVar3 = *puVar1;

      if (puVar4 + -8 != puVar2) {

        FUN_00462820(&param_2,*(uint32_t /* width from decompiler */ *)puVar4[-7],(uint32_t /* width from decompiler */ *)puVar4[-7]);

        FUN_004633e0();

      }

      FUN_0044c010();

      puVar4 = puVar4 + -8;

    } while (in_EAX != param_1);

  }

  return puVar3;

}
