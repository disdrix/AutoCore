// =============================================================================
// FUN_005a9040
// -----------------------------------------------------------------------------
// Stable ID: aa_005a9040
// Address:   0x005a9040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a9040 @ 0x005a9040
// Stable ID: aa_005a9040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×5, do×3, return×3, while×3.
//  - Notable callees: FUN_004b8ed0×2, FUN_004b99c0×2, memmove×2, FUN_00516de0, FUN_005a9040.
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

void __thiscall FUN_005a9040(int param_1,uint32_t /* width from decompiler */ param_2)



{

  void *pvVar1;

  char cVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int local_4;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + -0x3c);

  puVar5 = puVar4;

  if (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + -0x38)) {

    do {

      puVar5 = puVar5 + 1;

      pvVar1 = (void *)*puVar4;

      if ((pvVar1 != (void *)0x0) && (cVar2 = FUN_004b8ed0(param_2), cVar2 != '\0')) {

        memmove(puVar4,puVar5,(*(int *)(param_1 + -0x38) - (int)puVar5 >> 2) * 4);

        *(int *)(param_1 + -0x38) = *(int *)(param_1 + -0x38) + -4;

        FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar1);

      }

      puVar4 = puVar4 + 1;

    } while (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + -0x38));

  }

  piVar3 = (int *)(param_1 + -0x28);

  local_4 = 2;

  do {

    puVar4 = (uint32_t /* width from decompiler */ *)piVar3[-1];

    puVar5 = puVar4;

    if (puVar4 != (uint32_t /* width from decompiler */ *)*piVar3) {

      do {

        puVar5 = puVar5 + 1;

        pvVar1 = (void *)*puVar4;

        if ((pvVar1 != (void *)0x0) && (cVar2 = FUN_004b8ed0(param_2), cVar2 != '\0')) {

          memmove(puVar4,puVar5,(*(int *)(param_1 + -0x38) - (int)puVar5 >> 2) * 4);

          *(int *)(param_1 + -0x38) = *(int *)(param_1 + -0x38) + -4;

          FUN_004b99c0();

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        puVar4 = puVar4 + 1;

      } while (puVar4 != (uint32_t /* width from decompiler */ *)*piVar3);

    }

    piVar3 = piVar3 + 4;

    local_4 = local_4 + -1;

    if (local_4 == 0) {

      FUN_00516de0(param_2);

      return;

    }

  } while( true );

}
