// =============================================================================
// FUN_00461b20
// -----------------------------------------------------------------------------
// Stable ID: aa_00461b20
// Address:   0x00461b20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00461b20 @ 0x00461b20
// Stable ID: aa_00461b20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: FUN_00461b20.
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

void FUN_00461b20(int *param_1)



{

  int *piVar1;

  int *piVar2;

  int *piVar3;

  int *in_EAX;

  int *unaff_EBX;

  

  for (; in_EAX != param_1; in_EAX = in_EAX + 3) {

    piVar2 = (int *)*unaff_EBX;

    if ((piVar2 != (int *)0x0) && (piVar2[1] = piVar2[1] + 1, piVar2[1] == 1)) {

      (**(code **)(*piVar2 + 4))();

    }

    piVar3 = (int *)*in_EAX;

    if (piVar3 != (int *)0x0) {

      piVar1 = piVar3 + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 == 0) {

        (**(code **)(*piVar3 + 8))();

      }

    }

    *in_EAX = (int)piVar2;

    *(char *)(in_EAX + 1) = (char)unaff_EBX[1];

    *(uint8_t *)((int)in_EAX + 5) = *(uint8_t *)((int)unaff_EBX + 5);

    *(uint8_t *)((int)in_EAX + 6) = *(uint8_t *)((int)unaff_EBX + 6);

    in_EAX[2] = unaff_EBX[2];

  }

  return;

}
