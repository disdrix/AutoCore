// =============================================================================
// FUN_007563c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007563c0
// Address:   0x007563c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007563c0 @ 0x007563c0
// Stable ID: aa_007563c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_00755db0, FUN_007563c0, FUN_00986210.
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

void __fastcall FUN_007563c0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b098e;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a9f534;

  local_4 = 1;

  FUN_00986210(param_1[1]);

  puVar1 = (uint32_t /* width from decompiler */ *)param_1[0x14];

  param_1[1] = 0;

  if (puVar1 != (uint32_t /* width from decompiler */ *)param_1[0x15]) {

    do {

      FUN_00755db0(*puVar1);

      puVar1 = (uint32_t /* width from decompiler */ *)param_1[0x14];

    } while (puVar1 != (uint32_t /* width from decompiler */ *)param_1[0x15]);

  }

  if ((uint32_t /* width from decompiler */ *)param_1[2] != (uint32_t /* width from decompiler */ *)0x0) {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[2])(1);

  }

  param_1[2] = 0;

  if ((void *)param_1[0x14] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[0x14]);

  }

  param_1[0x14] = 0;

  param_1[0x15] = 0;

  param_1[0x16] = 0;

  *param_1 = &PTR_LAB_00a9f47c;

  ExceptionList = pvStack_c;

  return;

}
