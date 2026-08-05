// =============================================================================
// FUN_00449f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00449f20
// Address:   0x00449f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00449f20 @ 0x00449f20
// Stable ID: aa_00449f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~47 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: CONCAT31, FUN_00449f20, FUN_0044a140, FUN_00460380, FUN_0046c1b0.
//  - Return sites: 3.

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

int __fastcall FUN_00449f20(int param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *unaff_EBX;

  int local_50 [2];

  uint32_t /* width from decompiler */ local_48;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint8_t local_24 [4];

  void *local_20;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  undefined *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &DAT_009bdf60;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0046c1b0();

  if (local_50[0] != *(int *)(param_1 + 8)) {

    ExceptionList = local_c;

    return local_50[0] + 0xc;

  }

  local_40 = 0;

  local_3c = 0;

  local_38 = 0;

  local_4 = 0;

  local_2c = *unaff_EBX;

  local_28 = local_48;

  FUN_00460380(local_24);

  local_14 = local_34;

  local_10 = local_30;

  local_4 = CONCAT31(local_4._1_3_,1);

  piVar1 = (int *)FUN_0044a140(local_50,&local_2c);

  if (local_20 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

    operator_delete(local_20);

  }

  ExceptionList = local_c;

  return *piVar1 + 0xc;

}
