// =============================================================================
// Gfx_WBMP_Create_failed
// -----------------------------------------------------------------------------
// Stable ID: aa_0098b5b0
// Address:   0x0098b5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_WBMP_Create_failed @ 0x0098b5b0
// Stable ID: aa_0098b5b0
// Embedded strings (evidence for future rename):
//   - "Not a WBMP"
//   - "Unsupported WBMP type"
//   - "WBMP Create failed"
//   - "Corrupted WBMP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: return×6, if×5, for×1.
//  - Notable callees: _CxxThrowException×4, FUN_004323e0, FUN_00433a00, FUN_00433d30, FUN_00435240, FUN_00435290, Gfx_WBMP_Create_failed.
//  - Strings: "Not a WBMP"; "Unsupported WBMP type"; "WBMP Create failed"; "Corrupted WBMP".
//  - Return sites: 6.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "WBMP Create failed"
 * Domain alias of FUN_0098b5b0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint __thiscall Gfx_WBMP_Create_failed(int *param_1,int param_2)



{

  int iVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ local_40;

  char *local_2c;

  int local_28;

  char *local_24;

  char *local_20;

  char *local_1c;

  char local_18 [2];

  byte local_16;

  byte bStack_15;

  uint8_t *local_14;

  void *local_10;

  uint8_t *puStack_c;

  uint32_t /* width from decompiler */ local_8;

  

  puStack_c = &LAB_009ac27c;

  local_10 = ExceptionList;

  local_14 = &stack0xffffffa4;

  if (param_1 == (int *)0x0) {

    return (uint)ExceptionList & 0xffffff00;

  }

  local_8 = 0;

  ExceptionList = &local_10;

  iVar1 = (**(code **)(*param_1 + 8))(local_18,4,1);

  if (iVar1 == 0) {

    local_1c = "Not a WBMP";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_1c,(ThrowInfo *)&DAT_00acc49c);

  }

  if (local_18[0] != '\0') {

    local_20 = "Unsupported WBMP type";

                    /* WARNING: Subroutine does not return */

    _CxxThrowException(&local_20,(ThrowInfo *)&DAT_00acc49c);

  }

  if (((char)((ushort)_local_16 >> 8) != '\0') && ((char)_local_16 != '\0')) {

    FUN_004323e0((char)_local_16,1,4);

    if (*(int *)(param_2 + 4) == 0) {

      local_24 = "WBMP Create failed";

                    /* WARNING: Subroutine does not return */

      _CxxThrowException(&local_24,(ThrowInfo *)&DAT_00acc49c);

    }

    FUN_00433a00();

    uVar2 = (uint)local_16;

    FUN_00433d30();

    FUN_00435240();

    for (iVar1 = 0; iVar1 < (int)(uint)bStack_15; iVar1 = iVar1 + 1) {

      local_28 = iVar1;

      (**(code **)(*param_1 + 8))(local_40,(int)(uVar2 + 7) >> 3,1);

      FUN_00435290();

    }

    ExceptionList = local_10;

    return 1;

  }

  local_2c = "Corrupted WBMP";

                    /* WARNING: Subroutine does not return */

  _CxxThrowException(&local_2c,(ThrowInfo *)&DAT_00acc49c);

}
