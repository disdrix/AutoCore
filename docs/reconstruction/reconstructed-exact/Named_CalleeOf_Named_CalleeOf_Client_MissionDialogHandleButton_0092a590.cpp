// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton_0092a590
// -----------------------------------------------------------------------------
// Stable ID: aa_0092a590
// Callee of Named_CalleeOf_Client_MissionDialogHandleButton
// Address:   0x0092a590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_MissionDialogHandleButton: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_00929c00×2, FUN_0092a3d0×2, CNDHash_LookupByKey, FUN_0092a590.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_MissionDialogHandleButton
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

uint32_t /* width from decompiler */ __fastcall Named_CalleeOf_Named_CalleeOf_Client_MissionDialogHandleButton_0092a590(int *param_1)



{

  uint in_EAX;

  void *pvVar1;

  

  param_1[4] = in_EAX;

  *(uint8_t *)((int)param_1 + 6) = 1;

  if (in_EAX == 0) {

    FUN_0092a3d0();

    FUN_00929c00();

    param_1[4] = 0;

    param_1[3] = 0;

    return 1;

  }

  if (*(int *)(*param_1 + 0xe98) != 0) {

    pvVar1 = CNDHash_LookupByKey(*(void **)(*(int *)(*param_1 + 0xe98) + 0x548),in_EAX);

    if (pvVar1 != (void *)0x0) {

      param_1[3] = **(int **)((int)pvVar1 + 0x14c);

      *(uint8_t *)(param_1 + 1) = 1;

      return 1;

    }

  }

  FUN_0092a3d0();

  FUN_00929c00();

  param_1[4] = 0;

  param_1[3] = 0;

  return 0;

}
