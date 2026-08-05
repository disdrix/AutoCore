// =============================================================================
// FUN_00555360
// -----------------------------------------------------------------------------
// Stable ID: aa_00555360
// Address:   0x00555360  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00555360 @ 0x00555360
// Stable ID: aa_00555360
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~50 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, for×1, do×1, while×1.
//  - Notable callees: FUN_004b99c0×3, FUN_00555360.
//  - Return sites: 4.

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

void __fastcall FUN_00555360(int param_1)



{

  void *pvVar1;

  uint uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int local_4;

  

  local_4 = 0;

  for (uVar2 = 0;

      (*(int *)(param_1 + 0x434) != 0 &&

      (uVar2 < (uint)((*(int *)(param_1 + 0x438) - *(int *)(param_1 + 0x434)) / 0x134)));

      uVar2 = uVar2 + 1) {

    iVar3 = *(int *)(param_1 + 0x434) + local_4;

    if (*(char *)(iVar3 + 0x108) == '\0') {

      pvVar1 = *(void **)(iVar3 + 0x104);

      if (pvVar1 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *(uint32_t /* width from decompiler */ *)(iVar3 + 0x104) = 0;

    }

    local_4 = local_4 + 0x134;

  }

  if (*(char *)(param_1 + 0x548) == '\0') {

    pvVar1 = *(void **)(param_1 + 0x544);

    if (pvVar1 != (void *)0x0) {

      FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x544) = 0;

  }

  puVar4 = (uint32_t /* width from decompiler */ *)(param_1 + 0x104);

  iVar3 = 4;

  do {

    if (*(char *)(puVar4 + 1) == '\0') {

      pvVar1 = (void *)*puVar4;

      if (pvVar1 != (void *)0x0) {

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      *puVar4 = 0;

    }

    puVar4 = puVar4 + 0x43;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  return;

}
