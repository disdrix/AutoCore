// =============================================================================
// Named_CalleeOf_Named_gfxView_0043f210
// -----------------------------------------------------------------------------
// Stable ID: aa_0043f210
// Callee of Named_gfxView
// Address:   0x0043f210  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_gfxView: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_0043f210.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_gfxView
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

void __thiscall

Named_CalleeOf_Named_gfxView_0043f210(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,

            uint32_t /* width from decompiler */ param_9,uint32_t /* width from decompiler */ param_10,uint32_t /* width from decompiler */ param_11,uint32_t /* width from decompiler */ param_12,

            uint32_t /* width from decompiler */ param_13,uint32_t /* width from decompiler */ param_14,uint32_t /* width from decompiler */ param_15,uint32_t /* width from decompiler */ param_16,

            uint32_t /* width from decompiler */ param_17)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ local_50 [4];

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_50[0] = param_2;

  local_50[1] = param_3;

  local_50[2] = param_4;

  local_50[3] = param_5;

  local_40 = param_6;

  local_3c = param_7;

  local_38 = param_8;

  local_34 = param_9;

  local_30 = param_10;

  local_2c = param_11;

  local_28 = param_12;

  local_24 = param_13;

  local_20 = param_14;

  local_1c = param_15;

  local_18 = param_16;

  local_14 = param_17;

  puVar2 = local_50;

  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {

    *param_1 = *puVar2;

    puVar2 = puVar2 + 1;

    param_1 = param_1 + 1;

  }

  return;

}
