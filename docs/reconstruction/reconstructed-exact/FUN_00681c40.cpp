// =============================================================================
// FUN_00681c40
// -----------------------------------------------------------------------------
// Stable ID: aa_00681c40
// Address:   0x00681c40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00681c40 @ 0x00681c40
// Stable ID: aa_00681c40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0067b3e0, FUN_00681c40.
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

void __fastcall FUN_00681c40(uint32_t /* width from decompiler */ *param_1)



{

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a99fc;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_009e97a4;

  local_4 = 0;

  operator_delete__((void *)param_1[7]);

  operator_delete__((void *)param_1[2]);

  operator_delete__((void *)param_1[0xd]);

  operator_delete__((void *)param_1[0x1c]);

  if (param_1[1] != 0) {

    FUN_0067b3e0();

                    /* WARNING: Subroutine does not return */

    operator_delete((void *)param_1[1]);

  }

  if ((*(char *)((int)param_1 + 0x29) != '\0') && ((uint32_t /* width from decompiler */ *)param_1[0xb] != (uint32_t /* width from decompiler */ *)0x0))

  {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xb])(1);

  }

  if ((*(char *)((int)param_1 + 0x2a) != '\0') && ((uint32_t /* width from decompiler */ *)param_1[0xc] != (uint32_t /* width from decompiler */ *)0x0))

  {

    (*(code *)**(uint32_t /* width from decompiler */ **)param_1[0xc])(1);

  }

  *param_1 = &PTR_LAB_009e9764;

  ExceptionList = pvStack_c;

  return;

}
