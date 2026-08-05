// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_0094dab0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094dab0
// Callee of Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
// Address:   0x0094dab0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_Server_needs_an_update: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~21 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_004bb970, FUN_00520330, FUN_00575200, FUN_008e8b50, FUN_008ea880, FUN_0094dab0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_Server_needs_an_update (+1 other named callers)
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

void Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_0094dab0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int in_EAX;

  

  if ((*(int *)(in_EAX + 0xe98) != 0) &&

     (iVar1 = *(int *)(*(int *)(in_EAX + 0xe98) + 0xcb0), iVar1 != 0)) {

    FUN_004bb970(1,*(uint32_t /* width from decompiler */ *)(iVar1 + 0x160),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x164));

    FUN_00575200();

    puVar2 = *(uint32_t /* width from decompiler */ **)(*(int *)(in_EAX + 0xe98) + 0xcb0);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar2)(1);

    }

    FUN_00520330(0);

    if (*(int *)(in_EAX + 0x10a0) != 0) {

      FUN_008ea880();

      FUN_008e8b50(0xffffffff,0xffffffff,1);

    }

  }

  return;

}
