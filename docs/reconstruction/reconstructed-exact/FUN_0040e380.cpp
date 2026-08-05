// =============================================================================
// FUN_0040e380
// -----------------------------------------------------------------------------
// Stable ID: aa_0040e380
// Address:   0x0040e380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040e380 @ 0x0040e380
// Stable ID: aa_0040e380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×3.
//  - Notable callees: EnterCriticalSection×2, FUN_0040e446×2, FUN_0040e380.
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

uint FUN_0040e380(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint uVar2;

  void *local_10;

  uint8_t *puStack_c;

  uint local_8;

  

  puStack_c = &LAB_009bc0db;

  local_10 = ExceptionList;

  if (param_2 == 0) {

    return (uint)ExceptionList & 0xffffff00;

  }

  local_8 = 0;

  ExceptionList = &local_10;

  puVar1 = operator_new(0xc);

  if (puVar1 == (uint32_t /* width from decompiler */ *)0x0) {

    puVar1 = (uint32_t /* width from decompiler */ *)0x0;

  }

  else {

    *puVar1 = &PTR_FUN_00a38aa4;

    puVar1[2] = 0;

    puVar1[1] = 0;

  }

  local_8 = local_8 & 0xffffff00;

  puVar1[1] = param_2;

  if (*(int *)(param_1 + 0xc) < 4) {

    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x28));

  }

  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x10));

  if (*(int *)(param_1 + 8) == 0) {

    *(uint32_t /* width from decompiler */ **)(param_1 + 4) = puVar1;

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar1;

    uVar2 = FUN_0040e446();

    return uVar2;

  }

  *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 8) + 8) = puVar1;

  *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar1;

  uVar2 = FUN_0040e446();

  return uVar2;

}
