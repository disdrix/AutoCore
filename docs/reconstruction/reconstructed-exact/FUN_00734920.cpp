// =============================================================================
// FUN_00734920
// -----------------------------------------------------------------------------
// Stable ID: aa_00734920
// Address:   0x00734920  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00734920 @ 0x00734920
// Stable ID: aa_00734920
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004406e0, FUN_00456780, FUN_00734920.
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

void FUN_00734920(int *param_1)



{

  int iVar1;

  uint uVar2;

  void *pvVar3;

  int unaff_EDI;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009ad5f5;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  iVar1 = (**(code **)(*param_1 + 8))();

  if (*(int *)(unaff_EDI + 0x2c) == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = *(int *)(unaff_EDI + 0x30) - *(int *)(unaff_EDI + 0x2c) >> 2;

  }

  if (uVar2 < iVar1 + 1U) {

    FUN_00456780(0);

  }

  if (*(int *)(iVar1 * 4 + *(int *)(unaff_EDI + 0x2c)) == 0) {

    pvVar3 = operator_new(0x10);

    if (pvVar3 == (void *)0x0) {

      pvVar3 = (void *)0x0;

    }

    else {

      *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 4) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 8) = 0;

      *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0xc) = 0;

    }

    uStack_4 = 0xffffffff;

    *(void **)(*(int *)(unaff_EDI + 0x2c) + iVar1 * 4) = pvVar3;

  }

  FUN_004406e0();

  ExceptionList = pvStack_c;

  return;

}
