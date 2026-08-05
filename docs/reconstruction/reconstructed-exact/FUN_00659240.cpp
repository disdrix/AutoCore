// =============================================================================
// FUN_00659240
// -----------------------------------------------------------------------------
// Stable ID: aa_00659240
// Address:   0x00659240  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00659240 @ 0x00659240
// Stable ID: aa_00659240
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005ffdb0, FUN_00659240.
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

void __fastcall FUN_00659240(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = param_1[3];

  *param_1 = &PTR_FUN_009e4620;

  if (0 < iVar2) {

    iVar3 = 0;

    do {

      puVar1 = *(uint32_t /* width from decompiler */ **)(iVar3 + param_1[2]);

      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

      if (*(short *)((int)puVar1 + 6) == 0) {

        (**(code **)*puVar1)(1);

      }

      iVar3 = iVar3 + 0x50;

      iVar2 = iVar2 + -1;

    } while (iVar2 != 0);

  }

  if (-1 < (int)param_1[4]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[2],(param_1[4] & 0x7fffffff) * 0x50,0x12);

  }

  *param_1 = &PTR_FUN_009d81e8;

  if ((short)*(ushort *)(param_1 + 1) < 0) {

    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;

    FUN_005ffdb0(0);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
