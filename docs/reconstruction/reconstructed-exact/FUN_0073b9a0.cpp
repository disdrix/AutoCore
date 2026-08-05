// =============================================================================
// FUN_0073b9a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073b9a0
// Address:   0x0073b9a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073b9a0 @ 0x0073b9a0
// Stable ID: aa_0073b9a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0073b9a0, FUN_00745d70.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ * __fastcall FUN_0073b9a0(int param_1)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac9fe;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  puVar2 = operator_new(0x40);

  local_4 = 0;

  puVar3 = (uint32_t /* width from decompiler */ *)0x0;

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x3c);

    FUN_00745d70(puVar2,param_1 + 4,*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

    puVar2[0xf] = uVar1;

    *puVar2 = &PTR_FUN_00a9e99c;

    puVar3 = puVar2;

  }

  ExceptionList = local_c;

  return puVar3;

}
