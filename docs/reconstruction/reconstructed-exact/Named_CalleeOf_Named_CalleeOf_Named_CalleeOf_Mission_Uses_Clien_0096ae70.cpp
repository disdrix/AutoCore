// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Uses_Clien_0096ae70
// -----------------------------------------------------------------------------
// Stable ID: aa_0096ae70
// Callee of Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom
// Address:   0x0096ae70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_00456780, FUN_0096ae70, _aligned_free.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Mission_Uses_Client_GetMissionCom
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_Uses_Clien_0096ae70(void)



{

  int *_Memory;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar1;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0xc);

  if (puVar1 != *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x10)) {

    do {

      _Memory = (int *)*puVar1;

      (**(code **)(*_Memory + 0x10))(0);

      _aligned_free(_Memory);

      puVar1 = puVar1 + 1;

    } while (puVar1 != *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x10));

  }

  FUN_00456780(0);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x1c) = 0xffffffff;

  return;

}
