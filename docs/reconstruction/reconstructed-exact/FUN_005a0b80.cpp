// =============================================================================
// FUN_005a0b80
// -----------------------------------------------------------------------------
// Stable ID: aa_005a0b80
// Address:   0x005a0b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a0b80 @ 0x005a0b80
// Stable ID: aa_005a0b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0042c890, FUN_005a0b80, FUN_005a3be0.
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

void __thiscall FUN_005a0b80(int param_1,int param_2)



{

  uint *puVar1;

  uint uVar2;

  uint8_t local_18 [8];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  int local_8;

  

  puVar1 = (uint *)(param_1 + 0xb0);

  uVar2 = *puVar1;

  *puVar1 = *puVar1 + 1;

  *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + (uint)(0xfffffffe < uVar2);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x238) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(param_2 + 0x23c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4);

  local_10 = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb0);

  local_c = *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4);

  local_8 = param_2;

  FUN_005a3be0(local_18,&local_10);

  if (*(char *)(param_1 + 0xae) != '\0') {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xb0) = 10;

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xac) = 3000;

  }

  FUN_0042c890(param_2);

  return;

}
