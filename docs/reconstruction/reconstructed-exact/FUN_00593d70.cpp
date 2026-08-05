// =============================================================================
// FUN_00593d70
// -----------------------------------------------------------------------------
// Stable ID: aa_00593d70
// Address:   0x00593d70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00593d70 @ 0x00593d70
// Stable ID: aa_00593d70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: FUN_00593d70, FUN_005976d0.
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

void __fastcall FUN_00593d70(int param_1)



{

  int iVar1;

  int iVar2;

  int local_4;

  

  if (DAT_00b04e44 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = DAT_00b04e48 - DAT_00b04e44 >> 5;

  }

  if (0 < iVar1) {

    iVar2 = 0;

    local_4 = param_1;

    do {

      if (*(int *)(iVar2 + DAT_00b04e44) != 0) {

        if (*(int *)(*(int *)(iVar2 + DAT_00b04e44) + 0x78) != 0) {

                    /* WARNING: Subroutine does not return */

          operator_delete(*(void **)(*(int *)(iVar2 + DAT_00b04e44) + 0x78));

        }

        if ((*(int *)(iVar2 + DAT_00b04e44) != 0) &&

           (*(uint32_t /* width from decompiler */ **)(iVar2 + DAT_00b04e44) != (uint32_t /* width from decompiler */ *)0x0)) {

          (**(code **)**(uint32_t /* width from decompiler */ **)(iVar2 + DAT_00b04e44))(1);

        }

      }

      *(uint32_t /* width from decompiler */ *)(iVar2 + DAT_00b04e44) = 0;

      iVar2 = iVar2 + 0x20;

      iVar1 = iVar1 + -1;

    } while (iVar1 != 0);

  }

  if ((DAT_00b04e44 != 0) && (local_4 = DAT_00b04e48 - DAT_00b04e44 >> 5, local_4 != 0)) {

    FUN_005976d0(&local_4,DAT_00b04e44,DAT_00b04e48);

  }

  return;

}
