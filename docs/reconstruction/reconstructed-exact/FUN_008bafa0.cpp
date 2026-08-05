// =============================================================================
// FUN_008bafa0
// -----------------------------------------------------------------------------
// Stable ID: aa_008bafa0
// Address:   0x008bafa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008bafa0 @ 0x008bafa0
// Stable ID: aa_008bafa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: do×2, if×2, while×2, return×1.
//  - Notable callees: FUN_00792c20, FUN_008bafa0.
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

void __fastcall FUN_008bafa0(uint32_t /* width from decompiler */ *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b66e6;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *param_1 = &PTR_FUN_00a46a14;

  local_4 = 0;

  puVar1 = &DAT_00d17788;

  puVar2 = &DAT_00d177c8;

  do {

    iVar3 = 5;

    do {

      if ((void *)*puVar2 != (void *)0x0) {

        operator_delete__((void *)*puVar2);

      }

      *puVar2 = 0;

      puVar2 = puVar2 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    if ((void *)*puVar1 != (void *)0x0) {

      operator_delete__((void *)*puVar1);

    }

    *puVar1 = 0;

    puVar1 = puVar1 + 1;

  } while ((int)puVar2 < 0xd178f4);

  *param_1 = &PTR_FUN_00a58c6c;

  local_4 = 0xffffffff;

  FUN_00792c20();

  ExceptionList = pvStack_c;

  return;

}
