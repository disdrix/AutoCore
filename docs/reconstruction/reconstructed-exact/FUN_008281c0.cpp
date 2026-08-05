// =============================================================================
// FUN_008281c0
// -----------------------------------------------------------------------------
// Stable ID: aa_008281c0
// Address:   0x008281c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008281c0 @ 0x008281c0
// Stable ID: aa_008281c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×9, return×4.
//  - Notable callees: FUN_00797d70, FUN_008281c0.
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

void FUN_008281c0(char param_1)



{

  void *pvVar1;

  char *pcVar2;

  int iVar3;

  uint8_t *puVar4;

  int unaff_ESI;

  

  if (*(int *)(unaff_ESI + 0x564) != 0) {

    if ((DAT_00d1b223 == '\0') || (param_1 != '\0')) {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

      if (*pcVar2 != -1) {

        iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

        *(uint8_t *)(iVar3 + 2) = 0xff;

        iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

        *(uint8_t *)(iVar3 + 1) = 0xff;

        puVar4 = (uint8_t *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

        *puVar4 = 0xff;

        (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x34c))();

      }

    }

    else {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

      if (*pcVar2 == -1) {

        iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

        *(uint8_t *)(iVar3 + 2) = 0xc4;

        iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

        *(uint8_t *)(iVar3 + 1) = 0x20;

        puVar4 = (uint8_t *)(**(code **)(**(int **)(unaff_ESI + 0x564) + 0x164))(0);

        *puVar4 = 0x20;

        (**(code **)(**(int **)(unaff_ESI + 0x564) + 0x34c))();

      }

    }

  }

  if (*(int *)(unaff_ESI + 0x568) != 0) {

    if ((DAT_00d1b223 == '\0') && (param_1 == '\0')) {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      if (*pcVar2 != -1) {

        return;

      }

      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      *(uint8_t *)(iVar3 + 2) = 0xc4;

      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      *(uint8_t *)(iVar3 + 1) = 0x20;

      puVar4 = (uint8_t *)(**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      *puVar4 = 0x20;

    }

    else {

      pcVar2 = (char *)(**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      if (*pcVar2 == -1) {

        return;

      }

      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      *(uint8_t *)(iVar3 + 2) = 0xff;

      iVar3 = (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      *(uint8_t *)(iVar3 + 1) = 0xff;

      puVar4 = (uint8_t *)(**(code **)(**(int **)(unaff_ESI + 0x568) + 0x164))(1);

      *puVar4 = 0xff;

    }

    pvVar1 = *(void **)(*(int *)(unaff_ESI + 0x568) + 0x28c);

    if (pvVar1 != (void *)0x0) {

      FUN_00797d70(pvVar1);

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    *(uint32_t /* width from decompiler */ *)(*(int *)(unaff_ESI + 0x568) + 0x28c) = 0;

    (**(code **)(**(int **)(unaff_ESI + 0x568) + 0x34c))();

  }

  return;

}
