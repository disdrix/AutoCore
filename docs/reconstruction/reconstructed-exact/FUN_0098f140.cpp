// =============================================================================
// FUN_0098f140
// -----------------------------------------------------------------------------
// Stable ID: aa_0098f140
// Address:   0x0098f140  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0098f140 @ 0x0098f140
// Stable ID: aa_0098f140
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: FUN_0044f6a0×4, FUN_0098efc0×3, FUN_00457c80, FUN_0098f140.
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

void FUN_0098f140(void)



{

  void *pvVar1;

  int iVar2;

  int unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009af640;

  local_c = ExceptionList;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_00457c80(*(uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x28) + 4));

  *(int *)(*(int *)(unaff_EDI + 0x28) + 4) = *(int *)(unaff_EDI + 0x28);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c) = 0;

  *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x28) = *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x28);

  *(int *)(*(int *)(unaff_EDI + 0x28) + 8) = *(int *)(unaff_EDI + 0x28);

  iVar2 = *(int *)(unaff_EDI + 0x18);

  if (iVar2 != *(int *)(unaff_EDI + 0x1c)) {

    do {

      FUN_0098efc0(unaff_EDI);

      FUN_0098efc0(unaff_EDI);

      FUN_0098efc0(unaff_EDI);

      FUN_0044f6a0();

      FUN_0044f6a0();

      FUN_0044f6a0();

      FUN_0044f6a0();

      iVar2 = iVar2 + 6;

    } while (iVar2 != *(int *)(unaff_EDI + 0x1c));

  }

  pvVar1 = *(void **)(unaff_EDI + 0x18);

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x1c) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x20) = 0;

  if (pvVar1 == (void *)0x0) {

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(pvVar1);

}
