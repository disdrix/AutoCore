// =============================================================================
// FUN_0065aa60
// -----------------------------------------------------------------------------
// Stable ID: aa_0065aa60
// Address:   0x0065aa60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0065aa60 @ 0x0065aa60
// Stable ID: aa_0065aa60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_00638180×3, FUN_0065aa60.
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

void __fastcall FUN_0065aa60(uint32_t /* width from decompiler */ *param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  if (0 < (int)param_1[5]) {

    do {

      iVar2 = param_1[4];

      piVar1 = (int *)(*(int *)(iVar2 + 4 + iVar3 * 8) + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        FUN_00638180();

      }

      piVar1 = (int *)(*(int *)(iVar2 + iVar3 * 8) + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        FUN_00638180();

      }

      iVar3 = iVar3 + 1;

    } while (iVar3 < (int)param_1[5]);

  }

  if (-1 < (int)param_1[6]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[4],param_1[6] * 8,0x12);

  }

  piVar1 = (int *)(param_1[3] + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    FUN_00638180();

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
