// =============================================================================
// FUN_005a9150
// -----------------------------------------------------------------------------
// Stable ID: aa_005a9150
// Address:   0x005a9150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a9150 @ 0x005a9150
// Stable ID: aa_005a9150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×1, while×1.
//  - Notable callees: FUN_00584290×2, FUN_005a8ec0, FUN_005a9150.
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

void __fastcall FUN_005a9150(int param_1)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  

  FUN_005a8ec0();

  if (*(int *)(param_1 + 0xe8) != 0) {

    cVar3 = '\0';

    if ('\0' < *(char *)(param_1 + 0xb0)) {

      do {

        pvVar1 = *(void **)(*(int *)(param_1 + 0xe8) + 0x78 + cVar3 * 0x14c);

        if (pvVar1 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(pvVar1);

        }

        cVar3 = cVar3 + '\x01';

      } while (cVar3 < *(char *)(param_1 + 0xb0));

    }

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xe8);

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      if (puVar2[-1] == 0) {

        operator_delete__(puVar2 + -1);

      }

      else {

        (**(code **)*puVar2)(3);

      }

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe8) = 0;

  }

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xec);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    if (puVar2[-1] != 0) {

      (**(code **)*puVar2)(3);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = 0;

      FUN_00584290();

      return;

    }

    operator_delete__(puVar2 + -1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xec) = 0;

  FUN_00584290();

  return;

}
