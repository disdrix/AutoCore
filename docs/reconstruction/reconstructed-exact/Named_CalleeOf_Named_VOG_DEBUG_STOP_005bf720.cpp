// =============================================================================
// Named_CalleeOf_Named_VOG_DEBUG_STOP_005bf720
// -----------------------------------------------------------------------------
// Stable ID: aa_005bf720
// Callee of Named_VOG_DEBUG_STOP
// Address:   0x005bf720  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: if×7, return×4.
//  - Notable callees: FUN_0096f510×2, FUN_005bf720, FUN_0096efd0.
//  - Return sites: 4.

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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_VOG_DEBUG_STOP_005bf720(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x10);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    if (puVar1[-1] == 0) {

      operator_delete__(puVar1 + -1);

    }

    else {

      (**(code **)*puVar1)(3);

    }

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x30);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    if (puVar1[-1] == 0) {

      operator_delete__(puVar1 + -1);

    }

    else {

      (**(code **)*puVar1)(3);

    }

  }

  pvVar2 = *(void **)(param_1 + 0x48);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x30) = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_0096efd0();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  pvVar2 = *(void **)(param_1 + 0x4c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  pvVar2 = *(void **)(param_1 + 0x50);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = 0;

  if (pvVar2 != (void *)0x0) {

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar2);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

  return 1;

}
