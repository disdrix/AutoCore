// =============================================================================
// FUN_00968310
// -----------------------------------------------------------------------------
// Stable ID: aa_00968310
// Address:   0x00968310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00968310 @ 0x00968310
// Stable ID: aa_00968310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_0076c3c0×3, FUN_0043f1d0×2, FUN_0040d340, FUN_0075ece0, FUN_0075fb90, FUN_00968310.
//  - Return sites: 4.

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

int __fastcall FUN_00968310(int *param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = DAT_00d1f614;

  iVar5 = DAT_00d1f044;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3f4e;

  local_c = ExceptionList;

  uVar2 = *(uint32_t /* width from decompiler */ *)(DAT_00d1f614 + 0xc4);

  local_14 = DAT_00d1f614;

  ExceptionList = &local_c;

  local_10 = uVar2;

  if (*(char *)(DAT_00d1f614 + 200) == '\0') {

    ExceptionList = &local_c;

    iVar4 = FUN_0076c3c0();

    piVar1 = (int *)(iVar3 + 0x34 + *(int *)(iVar3 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar4 - *(int *)(iVar3 + 0x30));

    *(int *)(iVar3 + 0x30) = iVar4;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc4) = 1;

  }

  local_4 = 0;

  if (param_1[0x34] == *(int *)(iVar5 + 0x7ac)) {

    if (*(char *)(iVar3 + 200) == '\0') {

      iVar5 = FUN_0076c3c0();

      piVar1 = (int *)(iVar3 + 0x34 + *(int *)(iVar3 + 0xc4) * 4);

      *piVar1 = *piVar1 + (iVar5 - *(int *)(iVar3 + 0x30));

      *(int *)(iVar3 + 0x30) = iVar5;

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc4) = uVar2;

    }

    ExceptionList = local_c;

    return 0;

  }

  iVar5 = FUN_0075fb90();

  if (iVar5 < 0) {

    if (*(char *)(iVar3 + 200) == '\0') {

      iVar4 = FUN_0076c3c0();

      piVar1 = (int *)(iVar3 + 0x34 + *(int *)(iVar3 + 0xc4) * 4);

      *piVar1 = *piVar1 + (iVar4 - *(int *)(iVar3 + 0x30));

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc4) = uVar2;

      *(int *)(iVar3 + 0x30) = iVar4;

      ExceptionList = local_c;

      return iVar5;

    }

  }

  else {

    local_18 = 0;

    (**(code **)(*param_1 + 0x20))(&local_18);

    iVar5 = (**(code **)(*param_1 + 0x14))(&DAT_00d1f024);

    if (iVar5 < 0) {

      FUN_0043f1d0();

      ExceptionList = local_c;

      return iVar5;

    }

    local_4 = 0xffffffff;

    FUN_0043f1d0();

    FUN_0040d340();

    iVar5 = FUN_0075ece0();

  }

  ExceptionList = local_c;

  return iVar5;

}
