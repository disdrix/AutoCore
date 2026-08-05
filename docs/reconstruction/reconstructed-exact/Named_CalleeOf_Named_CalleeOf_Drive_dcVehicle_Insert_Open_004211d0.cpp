// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_004211d0
// -----------------------------------------------------------------------------
// Stable ID: aa_004211d0
// Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
// Address:   0x004211d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Drive_dcVehicle_Insert_Open: drive/input helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_004211d0, FUN_00421c30, FUN_004229e0.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Drive_dcVehicle_Insert_Open
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

int Named_CalleeOf_Named_CalleeOf_Drive_dcVehicle_Insert_Open_004211d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,char param_3)



{

  int iVar1;

  uint8_t *puVar2;

  int unaff_ESI;

  uint8_t local_c [4];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (*(int *)(unaff_ESI + 0xc) == 0) {

    puVar2 = (uint8_t *)0x0;

  }

  else {

    iVar1 = FUN_004229e0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10),local_c);

    if (iVar1 < 0) {

      return iVar1;

    }

    local_4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14);

    local_8 = 1;

    puVar2 = local_c;

  }

  iVar1 = FUN_00421c30(unaff_ESI,0,puVar2,param_2);

  if (((-1 < iVar1) && (param_3 != '\0')) && (*(int *)(unaff_ESI + 4) != 0)) {

    iVar1 = -0x7fffbffb;

  }

  return iVar1;

}
