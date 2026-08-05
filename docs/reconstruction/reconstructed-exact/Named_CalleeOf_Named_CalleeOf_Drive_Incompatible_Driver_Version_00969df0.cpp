// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_00969df0
// -----------------------------------------------------------------------------
// Stable ID: aa_00969df0
// Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
// Address:   0x00969df0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: for×3, return×1.
//  - Notable callees: FUN_00969df0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_Incompatible_Driver_Version_Detected_Drive
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

void Named_CalleeOf_Named_CalleeOf_Drive_Incompatible_Driver_Version_00969df0(void)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  DAT_00d1f05c = in_EAX;

  *in_EAX = 0;

  in_EAX[1] = 0;

  puVar2 = &DAT_00afdf70;

  puVar3 = in_EAX + 0xc;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = &DAT_00afdf70;

  puVar3 = in_EAX + 0x1c;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  puVar2 = &DAT_00afdf70;

  puVar3 = in_EAX + 0x2c;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *puVar3 = *puVar2;

    puVar2 = puVar2 + 1;

    puVar3 = puVar3 + 1;

  }

  *(uint8_t *)(in_EAX + 0x3c) = 1;

  *(uint8_t *)(in_EAX + 0x46) = 1;

  in_EAX[0x50] = 0;

  in_EAX[0x51] = 0;

  return;

}
