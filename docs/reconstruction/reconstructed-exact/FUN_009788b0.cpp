// =============================================================================
// FUN_009788b0
// -----------------------------------------------------------------------------
// Stable ID: aa_009788b0
// Address:   0x009788b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009788b0 @ 0x009788b0
// Stable ID: aa_009788b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0090dd50, FUN_00944d50, FUN_009788b0.
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

void __fastcall FUN_009788b0(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009bb9e4;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a76860;

  local_4 = 0;

  iVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1[9] + 4) + 4) + 4 + param_1[9]) + 0x210))

                    (0);

  if (iVar1 == DAT_00d1b6d8) {

    param_1[3] = *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c);

    *(uint32_t /* width from decompiler */ *)(DAT_00d1b778 + 0x60c) = 4;

    FUN_0090dd50();

  }

  iVar1 = param_1[4];

  if (iVar1 != 0) {

    FUN_00944d50(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1);

    (**(code **)(*(int *)(*(int *)(*(int *)(param_1[4] + 4) + 4) + 4 + param_1[4]) + 0x2a8))

              (*(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe4e8));

    iVar1 = param_1[4];

    if (iVar1 != 0) {

      (*(code *)**(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1))(1);

    }

  }

  *param_1 = &PTR_LAB_00a766f8;

  ExceptionList = param_1;

  return;

}
