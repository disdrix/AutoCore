// =============================================================================
// FUN_00998910
// -----------------------------------------------------------------------------
// Stable ID: aa_00998910
// Address:   0x00998910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00998910 @ 0x00998910
// Stable ID: aa_00998910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_00414b60, FUN_00414c20, FUN_004451c0, FUN_00447ea0, FUN_0044cc30, FUN_00746910, FUN_00746b90, FUN_00747220.
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

void FUN_00998910(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_EDI;

  uint local_28;

  uint8_t local_24 [16];

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009b205f;

  local_c = ExceptionList;

  iVar2 = *(int *)(*(int *)(unaff_EDI + 0x20) + 0x14);

  uVar3 = 3;

  if ((iVar2 != 0) && (*(char *)(iVar2 + 0x10) != '\0')) {

    uVar3 = 0x13;

  }

  ExceptionList = &local_c;

  FUN_004451c0(local_24,*(int *)(unaff_EDI + 0x14) + 0x24);

  local_4 = 0;

  FUN_00746b90();

  if (*(int *)(unaff_EDI + 0x14) == 0) {

    uVar1 = 0;

  }

  else {

    uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x14) + 0x18);

  }

  FUN_00414c20(uVar1,local_24,uVar3,0);

  if (*(int *)(unaff_EDI + 0x1c) != 0) {

    FUN_00447ea0();

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd4) = local_14;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd8) = local_10;

    FUN_00747220(1,0xffffffff);

    local_28 = local_28 & 0xffffff00;

    iVar2 = *(int *)(unaff_EDI + 0xcc) + -8;

    FUN_0044cc30(*(int *)(unaff_EDI + 200),iVar2,iVar2 - *(int *)(unaff_EDI + 200) >> 3,local_28);

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd4) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0xd8) = 0;

    FUN_00746910();

  }

  *(uint *)(unaff_EDI + 0xbc) = *(uint *)(unaff_EDI + 0xbc) | 8;

  FUN_00414b60();

  ExceptionList = local_c;

  return;

}
