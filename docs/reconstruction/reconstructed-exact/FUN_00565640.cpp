// =============================================================================
// FUN_00565640
// -----------------------------------------------------------------------------
// Stable ID: aa_00565640
// Address:   0x00565640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00565640 @ 0x00565640
// Stable ID: aa_00565640
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, for×1, while×1.
//  - Notable callees: FUN_0040b330, FUN_00565640, FUN_007c6110.
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

void FUN_00565640(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int local_20;

  uint8_t local_1c [4];

  void *local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009a4b21;

  local_c = ExceptionList;

  iVar3 = 0;

  local_20 = 0;

  local_18 = (void *)0x0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  ExceptionList = &local_c;

  FUN_007c6110(&local_20,local_1c);

  if (0 < local_20) {

    iVar4 = 0;

    do {

      puVar5 = (uint32_t /* width from decompiler */ *)((int)local_18 + iVar4);

      puVar1 = (uint32_t /* width from decompiler */ *)FUN_0040b330(puVar5);

      iVar3 = iVar3 + 1;

      for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar1 = *puVar5;

        puVar5 = puVar5 + 1;

        puVar1 = puVar1 + 1;

      }

      iVar4 = iVar4 + 0x180;

    } while (iVar3 < local_20);

  }

  if (local_18 == (void *)0x0) {

    ExceptionList = local_c;

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(local_18);

}
