// =============================================================================
// FUN_0072b870
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b870
// Address:   0x0072b870  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b870 @ 0x0072b870
// Stable ID: aa_0072b870
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×8, return×2.
//  - Notable callees: FUN_0072b380×4, FUN_0072b870.
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

void FUN_0072b870(void)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *unaff_ESI;

  uint32_t /* width from decompiler */ *unaff_EDI;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ac838;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *unaff_EDI = *unaff_ESI;

  unaff_EDI[1] = unaff_ESI[1];

  unaff_EDI[2] = unaff_ESI[2];

  unaff_EDI[3] = unaff_ESI[3];

  unaff_EDI[4] = unaff_ESI[4];

  unaff_EDI[5] = unaff_ESI[5];

  unaff_EDI[6] = unaff_ESI[6];

  if (unaff_ESI[7] != 0) {

    pvVar1 = operator_new(0x3c);

    local_4 = 0;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0072b380(unaff_ESI[7]);

    }

    unaff_EDI[7] = uVar2;

  }

  local_4 = 0xffffffff;

  if (unaff_ESI[8] != 0) {

    pvVar1 = operator_new(0x3c);

    local_4 = 1;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0072b380(unaff_ESI[8]);

    }

    unaff_EDI[8] = uVar2;

  }

  local_4 = 0xffffffff;

  if (unaff_ESI[9] != 0) {

    pvVar1 = operator_new(0x3c);

    local_4 = 2;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0072b380(unaff_ESI[9]);

    }

    unaff_EDI[9] = uVar2;

  }

  local_4 = 0xffffffff;

  if (unaff_ESI[10] != 0) {

    pvVar1 = operator_new(0x3c);

    local_4 = 3;

    if (pvVar1 != (void *)0x0) {

      uVar2 = FUN_0072b380(unaff_ESI[10]);

      unaff_EDI[10] = uVar2;

      ExceptionList = local_c;

      return;

    }

    unaff_EDI[10] = 0;

  }

  ExceptionList = local_c;

  return;

}
