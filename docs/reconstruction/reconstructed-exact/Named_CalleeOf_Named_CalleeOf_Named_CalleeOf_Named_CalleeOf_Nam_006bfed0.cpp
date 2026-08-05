// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bfed0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bfed0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
// Address:   0x006bfed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006bfd90×4, FUN_006c0b20×4, FUN_006bfed0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_006bfed0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  char *pcVar1;

  uint8_t local_39;

  char local_38 [4];

  uint8_t local_34 [4];

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

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

  

  local_30 = 0x37a7c5ac;

  local_28 = 0x358637bd;

  local_24 = 0x3727c5ac;

  local_20 = 0x3d4ccccd;

  local_1c = 0x358637bd;

  local_18 = 0x358637bd;

  local_14 = 0x322bcc77;

  local_10 = 0x358637bd;

  local_c = 0x38d1b717;

  local_8 = 0x3727c5ac;

  local_4 = 0x37a7c5ac;

  local_34[0] = 0;

  local_2c = 0x368637bd;

  FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);

  FUN_006c0b20(local_38,local_34,param_1,param_2,param_3,param_4);

  if (local_38[0] == '\0') {

    local_34[0] = 1;

    FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);

    pcVar1 = (char *)FUN_006c0b20(&local_39,local_34,param_1,param_2,param_3,param_4);

    local_38[0] = *pcVar1;

    if (local_38[0] == '\0') {

      local_2c = 0x3456bf95;

      FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);

      pcVar1 = (char *)FUN_006c0b20(&local_39,local_34,param_1,param_2,param_3,param_4);

      local_38[0] = *pcVar1;

      if (local_38[0] == '\0') {

        local_4 = 0x358637bd;

        FUN_006bfd90(local_34,param_1,param_2,param_3,param_4);

        FUN_006c0b20(&local_39,local_34,param_1,param_2,param_3,param_4);

      }

    }

  }

  return;

}
