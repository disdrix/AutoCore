// =============================================================================
// FUN_006f1ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1ba0
// Address:   0x006f1ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1ba0 @ 0x006f1ba0
// Stable ID: aa_006f1ba0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_005ffdb0, FUN_006f1ba0.
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

void __fastcall FUN_006f1ba0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  

  iVar2 = 0;

  *param_1 = &PTR_FUN_00a0ee70;

  param_1[2] = &PTR_FUN_00a0ee6c;

  param_1[3] = &PTR_FUN_00a0ee64;

  param_1[4] = &PTR_FUN_00a0ee5c;

  param_1[5] = &PTR_FUN_00a0ee58;

  if (0 < (int)param_1[7]) {

    do {

      puVar1 = *(uint32_t /* width from decompiler */ **)(param_1[6] + iVar2 * 4);

      *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + -1;

      if (*(short *)((int)puVar1 + 6) == 0) {

        (**(code **)*puVar1)(1);

      }

      iVar2 = iVar2 + 1;

    } while (iVar2 < (int)param_1[7]);

  }

  if (-1 < (int)param_1[8]) {

    (**(code **)(*DAT_00b05060 + 0x14))(param_1[6],param_1[8] << 2,0x12);

  }

  param_1[4] = &PTR_LAB_009d278c;

  param_1[3] = &PTR_LAB_009d2784;

  *param_1 = &PTR_FUN_009d81e8;

  if ((short)*(ushort *)(param_1 + 1) < 0) {

    *(ushort *)(param_1 + 1) = *(ushort *)(param_1 + 1) & 0x7fff;

    FUN_005ffdb0(0);

  }

  *param_1 = &PTR_LAB_009cc290;

  return;

}
