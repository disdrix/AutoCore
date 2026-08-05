// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_007fddd0
// -----------------------------------------------------------------------------
// Stable ID: aa_007fddd0
// Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
// Address:   0x007fddd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00418690, FUN_007fddd0, memmove.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Client_OnBadCharacterLoginId
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Client_OnBadCharac_007fddd0(void)



{

  int *piVar1;

  int *piVar2;

  char cVar3;

  int *_Dst;

  int unaff_EDI;

  int *local_4;

  

  _Dst = *(int **)(unaff_EDI + 0x3068);

  if (_Dst != *(int **)(unaff_EDI + 0x306c)) {

    local_4 = _Dst + 1;

    do {

      piVar1 = (int *)*_Dst;

      if (piVar1 == (int *)0x0) {

        _Dst = _Dst + 1;

        local_4 = local_4 + 1;

      }

      else {

        memmove(_Dst,local_4,(*(int *)(unaff_EDI + 0x306c) - (int)local_4 >> 2) * 4);

        *(int *)(unaff_EDI + 0x306c) = *(int *)(unaff_EDI + 0x306c) + -4;

        piVar2 = (int *)piVar1[0xac];

        cVar3 = (**(code **)(*piVar1 + 0x3d8))();

        if (cVar3 != '\0') {

          (**(code **)(*piVar1 + 0x440))();

        }

        if (piVar2 != (int *)0x0) {

          (**(code **)(*piVar2 + 0xb0))(piVar1);

        }

        (**(code **)*piVar1)(1);

      }

    } while (_Dst != *(int **)(unaff_EDI + 0x306c));

  }

  FUN_00418690(0);

  return;

}
