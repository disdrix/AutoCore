// =============================================================================
// FUN_009791c0
// -----------------------------------------------------------------------------
// Stable ID: aa_009791c0
// Address:   0x009791c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009791c0 @ 0x009791c0
// Stable ID: aa_009791c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0090dd50, FUN_00944d50, FUN_00978aa0, FUN_009791c0.
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

void __fastcall FUN_009791c0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bb9f6;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = &PTR_FUN_00a76800;

  local_4 = 0;

  if (param_1[0xe] == DAT_00d1b6d8) {

    *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c) = param_1[8];

    FUN_0090dd50();

  }

  FUN_00978aa0();

  iVar1 = param_1[9];

  if (iVar1 != 0) {

    FUN_00944d50(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1[9] + 4) + 4) + 4 + param_1[9]) + 0x2a8))

              (*(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe4e8));

    iVar1 = param_1[9];

    if (iVar1 != 0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

    }

  }

  *param_1 = &PTR_LAB_00a766f8;

  ExceptionList = local_c;

  return;

}
