// =============================================================================
// Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_00516930
// -----------------------------------------------------------------------------
// Stable ID: aa_00516930
// Callee of Named_CalleeOf_CVOGReaction_SpawnObject
// Address:   0x00516930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_CVOGReaction_SpawnObject: spawn/transfer helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: FUN_004b7150, FUN_004b99c0, FUN_00516930.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_CVOGReaction_SpawnObject
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

void __fastcall Named_CalleeOf_Named_CalleeOf_CVOGReaction_SpawnObject_00516930(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x138);

  if (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x13c)) {

    do {

      pvVar1 = (void *)*puVar2;

      FUN_004b7150();

      if (pvVar1 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      puVar2 = puVar2 + 1;

    } while (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x13c));

  }

  *(uint *)(param_1 + 0x184) = *(uint *)(param_1 + 0x184) & 0xfffffffb;

  if (*(void **)(param_1 + 0x138) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x138) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x13c) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x140) = 0;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x138));

}
