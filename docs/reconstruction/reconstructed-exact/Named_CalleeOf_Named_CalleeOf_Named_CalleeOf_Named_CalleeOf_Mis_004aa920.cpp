// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_004aa920
// -----------------------------------------------------------------------------
// Stable ID: aa_004aa920
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting
// Address:   0x004aa920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, while×1.
//  - Notable callees: FUN_005be7b0×2, FUN_0096f510×2, FUN_0048ea00, FUN_004aa920.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Attempting
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mis_004aa920(uint32_t /* width from decompiler */ *param_1)



{

  void *pvVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *local_4;

  

  local_4 = param_1;

  cVar2 = FUN_005be7b0(&local_4);

  while (cVar2 != '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1[0xe3] + (local_4[0x35] * param_1[0xe1] + local_4[0x34]) * 4) = 0;

    if (local_4 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*local_4)(1);

    }

    local_4 = (uint32_t /* width from decompiler */ *)0x0;

    cVar2 = FUN_005be7b0(&local_4);

  }

  if ((void *)param_1[0xe3] != (void *)0x0) {

    operator_delete__((void *)param_1[0xe3]);

  }

  pvVar1 = (void *)param_1[0xe5];

  param_1[0xe3] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0xe5] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0xe4] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xe4])(1);

  }

  pvVar1 = (void *)param_1[0xe5];

  param_1[0xe4] = 0;

  if (pvVar1 != (void *)0x0) {

    FUN_0096f510();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  param_1[0xe5] = 0;

  if ((uint32_t /* width from decompiler */ *)param_1[0xe4] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xe4])(1);

  }

  param_1[0xe4] = 0;

  FUN_0048ea00();

  return;

}
