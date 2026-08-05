// =============================================================================
// FUN_0054a1a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0054a1a0
// Address:   0x0054a1a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0054a1a0 @ 0x0054a1a0
// Stable ID: aa_0054a1a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, return×3.
//  - Notable callees: FUN_0054a1a0, FUN_0054d7c0.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0054a1a0(void)



{

  char cVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar2 = (uint32_t /* width from decompiler */ *)*DAT_00b04744;

  while (puVar2 != DAT_00b04744) {

    if ((void *)puVar2[4] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)puVar2[4]);

    }

    if (*(char *)((int)puVar2 + 0x15) == '\0') {

      puVar3 = (uint32_t /* width from decompiler */ *)puVar2[2];

      if (*(char *)((int)puVar3 + 0x15) == '\0') {

        cVar1 = *(char *)((int)*puVar3 + 0x15);

        puVar2 = puVar3;

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

        while (cVar1 == '\0') {

          cVar1 = *(char *)((int)*puVar3 + 0x15);

          puVar2 = puVar3;

          puVar3 = (uint32_t /* width from decompiler */ *)*puVar3;

        }

      }

      else {

        cVar1 = *(char *)((int)puVar2[1] + 0x15);

        puVar5 = (uint32_t /* width from decompiler */ *)puVar2[1];

        puVar3 = puVar2;

        while ((puVar2 = puVar5, cVar1 == '\0' && (puVar3 == (uint32_t /* width from decompiler */ *)puVar2[2]))) {

          cVar1 = *(char *)((int)puVar2[1] + 0x15);

          puVar5 = (uint32_t /* width from decompiler */ *)puVar2[1];

          puVar3 = puVar2;

        }

      }

    }

  }

  pvVar4 = (void *)DAT_00b04744[1];

  if (*(char *)((int)pvVar4 + 0x15) == '\0') {

    FUN_0054d7c0(*(uint32_t /* width from decompiler */ *)((int)pvVar4 + 8));

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar4);

  }

  DAT_00b04744[1] = DAT_00b04744;

  _DAT_00b04748 = 0;

  *DAT_00b04744 = DAT_00b04744;

  DAT_00b04744[2] = DAT_00b04744;

  return;

}
