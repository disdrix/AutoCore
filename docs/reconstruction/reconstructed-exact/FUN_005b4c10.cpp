// =============================================================================
// FUN_005b4c10
// -----------------------------------------------------------------------------
// Stable ID: aa_005b4c10
// Address:   0x005b4c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005b4c10 @ 0x005b4c10
// Stable ID: aa_005b4c10
// Embedded strings (evidence for future rename):
//   - "SetupBranchForTreeType"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076cef0×2, FUN_005b4c10, FUN_005b7820, FUN_0068a4d0, FUN_0076cf00, ROUND.
//  - Strings: "SetupBranchForTreeType".
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

uint32_t /* width from decompiler */ __thiscall FUN_005b4c10(int param_1,float param_2)



{

  int iVar1;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a68ad;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0076cf00("SetupBranchForTreeType");

  local_4 = 0;

  FUN_0068a4d0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50),1,0xffffffff,0xffffffff,0xffffffff);

  if (*(int *)(param_1 + 0x60) != 0) {

    iVar1 = **(int **)(param_1 + 0x50);

    if ((-1 < iVar1) && ((short)(*(int **)(param_1 + 0x50))[1] != 0)) {

      *(uint *)(*(int *)(param_1 + 0xc) + 0xc4) =

           *(ushort *)(*(int *)(param_1 + 0x60) + iVar1 * 2) - 2;

      *(int *)(*(int *)(param_1 + 0xc) + 200) =

           (int)ROUND((float)*(int *)(*(int *)(param_1 + 0xc) + 0xa8) * param_2);

      FUN_005b7820(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0xc) + 0xd0),&DAT_00b05240);

      local_4 = 0xffffffff;

      FUN_0076cef0();

      ExceptionList = local_c;

      return 1;

    }

  }

  local_4 = 0xffffffff;

  FUN_0076cef0();

  ExceptionList = local_c;

  return 0;

}
