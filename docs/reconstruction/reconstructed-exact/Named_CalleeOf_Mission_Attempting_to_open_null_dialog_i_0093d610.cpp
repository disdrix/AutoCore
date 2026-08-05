// =============================================================================
// Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0093d610
// -----------------------------------------------------------------------------
// Stable ID: aa_0093d610
// Callee of Mission_Attempting_to_open_null_dialog_i
// Address:   0x0093d610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Attempting_to_open_null_dialog_i: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_008b30c0, FUN_0093d610.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Mission_Attempting_to_open_null_dialog_i
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

void Named_CalleeOf_Mission_Attempting_to_open_null_dialog_i_0093d610(void)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8;

  uint8_t local_7;

  

  iVar3 = CVOGReaction_ResolveObjectTarget

                    (1,*(uint32_t /* width from decompiler */ *)(in_EAX + 0x30c8),*(uint32_t /* width from decompiler */ *)(in_EAX + 0x30cc));

  if (iVar3 != 0) {

    *(uint8_t *)(iVar3 + 0x100) = 1;

  }

  local_10 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30c8);

  local_c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30cc);

  local_7 = *(uint8_t *)(in_EAX + 0x30d4);

  local_18[0] = 0x20a2;

  local_8 = 1;

  if (*(int **)(in_EAX + 0xc78) != (int *)0x0) {

    (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,local_18,0x18,0);

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30c8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30cc) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x30d4) = 0xffffffff;

  piVar1 = *(int **)(in_EAX + 0x1030);

  if (piVar1 != (int *)0x0) {

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if ((cVar2 != '\0') && (piVar1[0x145] != 0)) {

      FUN_008b30c0(0);

    }

  }

  return;

}
