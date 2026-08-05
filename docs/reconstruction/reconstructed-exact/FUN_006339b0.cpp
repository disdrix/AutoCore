// =============================================================================
// FUN_006339b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006339b0
// Address:   0x006339b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006339b0 @ 0x006339b0
// Stable ID: aa_006339b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00633780, FUN_006339b0, GetCurrentProcess, SymGetOptions, SymInitialize, SymSetOptions.
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

void FUN_006339b0(uint32_t /* width from decompiler */ param_1)



{

  uint uVar1;

  HANDLE pvVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint16_t *puVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint16_t local_208;

  uint32_t /* width from decompiler */ local_206 [128];

  

  local_208 = 0;

  puVar4 = local_206;

  for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {

    *puVar4 = 0;

    puVar4 = puVar4 + 1;

  }

  *(uint16_t *)puVar4 = 0;

  uVar1 = SymGetOptions();

  SymSetOptions(uVar1 & 0xfffffffd | 0x10);

  FUN_00633780(&local_208,param_1);

  uVar6 = 1;

  puVar5 = &local_208;

  pvVar2 = GetCurrentProcess();

  SymInitialize(pvVar2,puVar5,uVar6);

  return;

}
