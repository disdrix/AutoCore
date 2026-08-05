// =============================================================================
// FUN_00422b80
// -----------------------------------------------------------------------------
// Stable ID: aa_00422b80
// Address:   0x00422b80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00422b80 @ 0x00422b80
// Stable ID: aa_00422b80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, switch×1, return×1.
//  - Notable callees: CoTaskMemFree, FUN_00422b80, FUN_00422ce0, FUN_00422d00, SafeArrayDestroy, SysFreeString, VariantClear.
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

void __thiscall FUN_00422b80(int *param_1,uint param_2)



{

  int *piVar1;

  VARIANTARG *unaff_EBX;

  

  if (unaff_EBX != (VARIANTARG *)0x0) {

    if ((param_2 & 0x2000) == 0) {

      switch(param_2 & 0xffff) {

      case 8:

        SysFreeString(*(BSTR *)&unaff_EBX->n1);

        *(uint32_t /* width from decompiler */ *)&unaff_EBX->n1 = 0;

        break;

      case 9:

      case 0xd:

        piVar1 = *(int **)&unaff_EBX->n1;

        if (piVar1 != (int *)0x0) {

          (**(code **)(*piVar1 + 8))(piVar1);

          *(uint32_t /* width from decompiler */ *)&unaff_EBX->n1 = 0;

        }

        break;

      case 0xc:

        VariantClear(unaff_EBX);

        break;

      case 0x88:

        FUN_00422ce0();

        if (param_1 != (int *)0x0) {

          (**(code **)(*param_1 + 0x10))(param_1,*(uint32_t /* width from decompiler */ *)&unaff_EBX->n1,0);

        }

        FUN_00422d00();

      }

    }

    else if (*(SAFEARRAY **)&unaff_EBX->n1 != (SAFEARRAY *)0x0) {

      SafeArrayDestroy(*(SAFEARRAY **)&unaff_EBX->n1);

      *(uint32_t /* width from decompiler */ *)&unaff_EBX->n1 = 0;

    }

    if (((param_2 & 0x1000) != 0) && ((param_2 & 0x4000) != 0xffffffff)) {

      CoTaskMemFree((LPVOID)(unaff_EBX->n1).decVal.Hi32);

    }

  }

  return;

}
