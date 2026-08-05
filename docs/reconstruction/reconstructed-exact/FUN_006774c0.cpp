// =============================================================================
// FUN_006774c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006774c0
// Address:   0x006774c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006774c0 @ 0x006774c0
// Stable ID: aa_006774c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: EnterCriticalSection, FUN_006772f0, FUN_006774c0, FUN_00680c30, LeaveCriticalSection.
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

void __thiscall FUN_006774c0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a9508;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if (*(char *)(param_1 + 0x2c) != '\0') {

    ExceptionList = &local_c;

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));

  }

  local_4 = 0;

  FUN_00680c30();

  FUN_006772f0(0);

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 4);

  *(uint32_t /* width from decompiler */ *)(param_2 + 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = uVar1;

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 8);

  *(uint32_t /* width from decompiler */ *)(param_2 + 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = uVar1;

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0xc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xc);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar1;

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x10) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = uVar1;

  if (*(char *)(param_1 + 0x2c) != '\0') {

    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x14));

  }

  ExceptionList = local_c;

  return;

}
