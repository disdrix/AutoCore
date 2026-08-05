// =============================================================================
// Named_CalleeOf_Named_effDeviceEffect_00751a10
// -----------------------------------------------------------------------------
// Stable ID: aa_00751a10
// Callee of Named_effDeviceEffect
// Address:   0x00751a10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_effDeviceEffect: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_00445470×2, FUN_00445230, FUN_0073dff0, FUN_00751a10.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_effDeviceEffect
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_effDeviceEffect_00751a10(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  int iVar1;

  uint8_t local_24 [4];

  int local_20;

  uint8_t local_1c [4];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b2460;

  local_c = ExceptionList;

  if ((*(int *)(param_1 + 0x10) == 1) && (*(int *)(param_1 + 0xc) == 0x43504658)) {

    local_24[0] = 0;

    local_18 = 0;

    local_14 = 0;

    local_10 = 0;

    local_4 = 0;

    ExceptionList = &local_c;

    FUN_00445230(local_24);

    iVar1 = FUN_0073dff0(param_3,local_1c);

    if (local_20 != iVar1) {

      FUN_00445470();

      ExceptionList = local_c;

      return 0;

    }

    FUN_00445470();

    ExceptionList = local_c;

    return 1;

  }

  return 0;

}
