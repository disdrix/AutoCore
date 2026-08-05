// =============================================================================
// FUN_0048ca90
// -----------------------------------------------------------------------------
// Stable ID: aa_0048ca90
// Address:   0x0048ca90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048ca90 @ 0x0048ca90
// Stable ID: aa_0048ca90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0048c7b0, FUN_0048ca90.
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

void __thiscall FUN_0048ca90(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  char *pcVar2;

  char *pcVar3;

  char *pcVar4;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a06b8;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  pcVar2 = operator_new(**(int **)(param_1 + 0x20) + 1);

  if (pcVar2 != (char *)0x0) {

    pcVar3 = (char *)(*(int *)(param_1 + 0x20) + 8);

    pcVar4 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

      *pcVar4 = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

  }

  local_4 = 0;

  if (pcVar2 != (char *)0x0) {

    cVar1 = FUN_0048c7b0(pcVar2,param_2);

    if (cVar1 != '\0') {

      local_4 = 0xffffffff;

                    /* WARNING: Subroutine does not return */

      operator_delete(pcVar2);

    }

  }

  local_4 = 0xffffffff;

                    /* WARNING: Subroutine does not return */

  operator_delete(pcVar2);

}
