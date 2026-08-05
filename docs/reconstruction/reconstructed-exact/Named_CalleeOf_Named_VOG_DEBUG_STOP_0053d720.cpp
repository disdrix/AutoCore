// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_0053d720
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d720
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x0053d720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0053d720, FUN_00561450.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_VOG_DEBUG_STOP
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

void __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_0053d720(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ uStack_4;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xa8 + param_1);

  if ((iVar1 != 0) && (iVar2 = *(int *)(param_1 + 8), iVar2 != 0)) {

    uStack_4 = param_1;

    if ((*(int *)(iVar1 + 0xe4a4) != 0) && (*(int *)(iVar2 + 8) != 0)) {

      FUN_00561450((int)&uStack_4 + 3,iVar2);

    }

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

    *(short *)((int)puVar3 + 6) = *(short *)((int)puVar3 + 6) + -1;

    if (*(short *)((int)puVar3 + 6) == 0) {

      (**(code **)*puVar3)(1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

  }

  return;

}
