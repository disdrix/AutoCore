// =============================================================================
// FUN_00877c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00877c50
// Address:   0x00877c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00877c50 @ 0x00877c50
// Stable ID: aa_00877c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00877690×2, FUN_00877bf0×2, FUN_008778e0, FUN_00877c50.
//  - Return sites: 2.

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

void __fastcall FUN_00877c50(int *param_1)



{

  int iVar1;

  char in_AL;

  uint32_t /* width from decompiler */ uVar2;

  int local_8;

  int local_4;

  

  if (in_AL != (char)param_1[0x149]) {

    *(char *)(param_1 + 0x149) = in_AL;

    if (in_AL != '\0') {

      param_1[0x151] = 0;

      param_1[0x152] = 0;

      FUN_00877690(0);

      FUN_00877bf0(1);

      param_1[0x13f] = 0;

      param_1[0x140] = 2;

      *(uint8_t *)((int)param_1 + 0xc5) = 1;

      if ((int *)param_1[0x163] != (int *)0x0) {

        iVar1 = *param_1;

        uVar2 = (**(code **)(*(int *)param_1[0x163] + 0x140))(&local_8,1);

        (**(code **)(iVar1 + 0x130))(uVar2);

      }

      local_8 = (int)((float)DAT_00d1e818 * (float)param_1[0x14c] * DAT_00aaa67c);

      local_4 = (int)((float)DAT_00d1e81c * (float)param_1[0x14d] * DAT_00aaa678);

      (**(code **)(*param_1 + 0x110))(&local_8);

      return;

    }

    FUN_00877690(1);

    FUN_00877bf0(0);

    local_8 = param_1[0x14a];

    local_4 = param_1[0x14b];

    param_1[0x13f] = 0xf;

    param_1[0x140] = 1;

    (**(code **)(*param_1 + 0x110))(&local_8);

    (**(code **)(*param_1 + 0x130))(param_1 + 0x14e);

    *(uint8_t *)((int)param_1 + 0xc5) = 0;

    FUN_008778e0(param_1);

  }

  return;

}
