// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0053b610
// -----------------------------------------------------------------------------
// Stable ID: aa_0053b610
// Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x0053b610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: while×2, do×1, return×1.
//  - Notable callees: FUN_0053b610.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0053b610(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  

  uVar4 = 0;

  do {

    puVar3 = *(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4);

    while (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar2 = (uint32_t /* width from decompiler */ *)puVar3[3];

      *puVar3 = &PTR_LAB_009cf024;

      *puVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

      *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar3;

      puVar3 = puVar2;

    }

    iVar1 = uVar4 * 4;

    uVar4 = uVar4 + 1;

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x10) + iVar1) + 4) = 0;

  } while (uVar4 <= *(uint *)(param_1 + 8));

  return;

}
