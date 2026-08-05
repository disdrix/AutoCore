// =============================================================================
// FUN_00445230
// -----------------------------------------------------------------------------
// Stable ID: aa_00445230
// Address:   0x00445230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00445230 @ 0x00445230
// Stable ID: aa_00445230
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00437050×2, FUN_007689e0×2, FUN_00769e40×2, FUN_00445230, FUN_00445ae0, FUN_0096a7f0, stoChunkReader_EnterChunkScope.
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

uint32_t /* width from decompiler */ __thiscall FUN_00445230(int param_1,uint8_t *param_2)



{

  uint8_t *puVar1;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bef98;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope();

  puVar1 = (uint8_t *)0x0;

  local_4 = 0;

  if ((local_14 == 0x50465844) && (local_10 == 1)) {

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00437050();

    }

    else {

      FUN_007689e0();

    }

    if (*(int *)(param_1 + 0x4044) == 0) {

      FUN_00437050();

    }

    else {

      FUN_007689e0();

    }

    FUN_00445ae0();

    if (param_2 != (uint8_t *)0x0) {

      do {

        FUN_0096a7f0(*(int *)(param_2 + 0xc) + (int)puVar1 * 4);

        puVar1 = puVar1 + 1;

      } while (puVar1 < param_2);

    }

    local_4 = 0xffffffff;

    *param_2 = 1;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0;

  }

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
