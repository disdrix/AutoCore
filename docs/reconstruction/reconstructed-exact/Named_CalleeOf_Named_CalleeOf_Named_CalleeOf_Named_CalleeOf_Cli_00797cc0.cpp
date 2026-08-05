// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00797cc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00797cc0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
// Address:   0x00797cc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00797a60, FUN_00797cc0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_RefreshOpen
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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_00797cc0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int *param_3)



{

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  int *local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_28 = *param_1;

  local_24 = param_1[1];

  local_2c = param_3;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_c = 0;

  local_20 = 0;

  local_1c = 0;

  local_8 = 0;

  local_4 = 0;

  if (unaff_ESI == (uint32_t /* width from decompiler */ *)0x0) {

    if (param_3 != (int *)0x0) {

      local_10 = *(uint32_t /* width from decompiler */ *)(*param_3 + 0x1c);

      local_c = *(uint32_t /* width from decompiler */ *)(*param_3 + 0x20);

      local_18 = 0;

      local_14 = 0;

    }

  }

  else {

    local_18 = *unaff_ESI;

    local_14 = unaff_ESI[1];

    local_10 = unaff_ESI[2];

    local_c = unaff_ESI[3];

  }

  if (unaff_EDI != (uint32_t /* width from decompiler */ *)0x0) {

    local_20 = *unaff_EDI;

    local_1c = unaff_EDI[1];

  }

  if (unaff_EBX != (uint32_t /* width from decompiler */ *)0x0) {

    local_8 = *unaff_EBX;

    local_4 = unaff_EBX[1];

  }

  FUN_00797a60(&local_2c);

  return;

}
