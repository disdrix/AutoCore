// =============================================================================
// FUN_00670bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00670bb0
// Address:   0x00670bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00670bb0 @ 0x00670bb0
// Stable ID: aa_00670bb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×5, return×2, do×1, while×1.
//  - Notable callees: FUN_00680c30×2, FUN_00680c50×2, FUN_0066f910, FUN_0066ff20, FUN_00670bb0, FUN_0067a6c0, FUN_0076c3c0, thunk_FUN_0076c4d0.
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

uint32_t /* width from decompiler */ __fastcall FUN_00670bb0(int param_1)



{

  char cVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uStack_48;

  uint8_t auStack_44 [28];

  uint8_t auStack_28 [28];

  void *local_c;

  uint8_t *puStack_8;

  int iStack_4;

  

  iStack_4 = 0xffffffff;

  puStack_8 = &LAB_009a90ad;

  local_c = ExceptionList;

  if (*(int *)(param_1 + 0x38) != 0) {

    ExceptionList = &local_c;

    cVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 0xc))();

    if (cVar1 != '\0') {

      FUN_00680c30();

      iStack_4 = 0;

      if (*(int *)(param_1 + 0x38) != 0) {

        do {

          cVar1 = (**(code **)(**(int **)(param_1 + 0x38) + 8))(auStack_28,&uStack_48);

          if (cVar1 == '\0') break;

          FUN_0066ff20(auStack_28,uStack_48,0);

        } while (*(int *)(param_1 + 0x38) != 0);

        if ((*(int *)(param_1 + 0x38) != 0) && (uVar2 = FUN_0076c3c0(), 10 < uVar2)) {

          thunk_FUN_0076c4d0();

          FUN_00680c30();

          iStack_4._0_1_ = 1;

          FUN_0067a6c0(auStack_44,*(uint8_t *)(param_1 + 0xc));

          (**(code **)(**(int **)(param_1 + 0x38) + 4))(auStack_44,0);

          iStack_4 = (uint)iStack_4._1_3_ << 8;

          FUN_00680c50();

        }

      }

      iStack_4 = 0xffffffff;

      FUN_00680c50();

      ExceptionList = local_c;

      return 1;

    }

    FUN_0066f910();

  }

  ExceptionList = local_c;

  return 1;

}
