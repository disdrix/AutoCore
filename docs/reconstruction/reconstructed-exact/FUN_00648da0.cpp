// =============================================================================
// FUN_00648da0
// -----------------------------------------------------------------------------
// Stable ID: aa_00648da0
// Address:   0x00648da0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00648da0 @ 0x00648da0
// Stable ID: aa_00648da0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_00648da0.
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

void __fastcall FUN_00648da0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  iVar2 = 0;

  *param_1 = &PTR_FUN_009e4760;

  if (0 < (int)param_1[6]) {

    do {

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1[5] + iVar2 * 4);

      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

      if (*(short *)((int)puVar1 + 6) == 0) {

        (**(code **)*puVar1)(1);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)param_1[6]);

  }

  iVar2 = 0;

  if (0 < (int)param_1[3]) {

    do {

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1[2] + iVar2 * 4);

      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

      if (*(short *)((int)puVar1 + 6) == 0) {

        (**(code **)*puVar1)(1);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)param_1[3]);

  }

  if (-1 < (int)param_1[10]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[8],param_1[10] << 5,0x12);

  }

  if (-1 < (int)param_1[7]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[5],param_1[7] * 4,0x12);

  }

  if (-1 < (int)param_1[4]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[2],param_1[4] * 4,0x12);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
