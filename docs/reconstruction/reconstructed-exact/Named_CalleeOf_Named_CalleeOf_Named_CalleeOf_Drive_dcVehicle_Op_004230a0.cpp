// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Op_004230a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004230a0
// Callee of Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Open
// Address:   0x004230a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Open: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, for×1, return×1.
//  - Notable callees: FUN_004230a0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Open
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

void __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Op_004230a0(uint32_t /* width from decompiler */ param_1,int *param_2,uint32_t /* width from decompiler */ *param_3)



{

  int in_EAX;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = (uint32_t /* width from decompiler */ *)(*param_2 + in_EAX * 0x34);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {

      *puVar2 = *param_3;

      param_3 = param_3 + 1;

      puVar2 = puVar2 + 1;

    }

  }

  return;

}
