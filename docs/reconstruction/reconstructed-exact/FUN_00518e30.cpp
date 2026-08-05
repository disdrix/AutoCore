// =============================================================================
// FUN_00518e30
// -----------------------------------------------------------------------------
// Stable ID: aa_00518e30
// Address:   0x00518e30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00518e30 @ 0x00518e30
// Stable ID: aa_00518e30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: FUN_004cbdc0, FUN_00518e30, FUN_0051dd60.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_00518e30(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a3627;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x70) != 0) {

    ExceptionList = &local_c;

    FUN_004cbdc0(param_2);

    ExceptionList = local_c;

    return;

  }

  ExceptionList = &local_c;

  pvVar1 = operator_new(0x34);

  local_4 = 0;

  if (pvVar1 != (void *)0x0) {

    uVar2 = FUN_0051dd60(param_2);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = uVar2;

    ExceptionList = local_c;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x70) = 0;

  ExceptionList = local_c;

  return;

}
