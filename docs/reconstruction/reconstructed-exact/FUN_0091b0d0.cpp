// =============================================================================
// FUN_0091b0d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091b0d0
// Address:   0x0091b0d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0091b0d0 @ 0x0091b0d0
// Stable ID: aa_0091b0d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_0040cf90, FUN_0091b0d0, FUN_0099b8b0.
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

void FUN_0091b0d0(void)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = DAT_00d17944;

  local_18 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x228);

  local_14 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x22c);

  local_10 = *(uint32_t /* width from decompiler */ *)(DAT_00d17944 + 0x230);

  FUN_0040cf90(&local_18);

  local_18 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x210);

  iVar2 = *(int *)(*(int *)(*(int *)(DAT_00d1b644 + 0xe894) + 0xc0) + 8);

  local_14 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x214);

  local_10 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x218);

  local_c = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x21c);

  local_8 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x220);

  local_4 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x224);

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0xbc) = 0xffffffff;

  piVar1 = (int *)(iVar2 + 0xb4);

  *piVar1 = *piVar1 + 1;

  FUN_0099b8b0(&local_c,&local_18);

  return;

}
