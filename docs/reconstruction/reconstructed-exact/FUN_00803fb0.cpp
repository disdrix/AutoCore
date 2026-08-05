// =============================================================================
// FUN_00803fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00803fb0
// Address:   0x00803fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00803fb0 @ 0x00803fb0
// Stable ID: aa_00803fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00803e40×3, FUN_00977de0×2, FUN_00803b50, FUN_00803fb0, GetObjectA.
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

uint32_t /* width from decompiler */ FUN_00803fb0(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int *in_EAX;

  int *piVar2;

  int iVar3;

  uint8_t local_3c [60];

  

  piVar2 = *(int **)in_EAX[0xe];

  if (piVar2 == (int *)in_EAX[0xe]) {

    return 0;

  }

  piVar1 = (int *)piVar2[2];

  GetObjectA((HANDLE)in_EAX[0x98],0x3c,local_3c);

  (**(code **)(*piVar1 + 0x6c))(local_3c);

  FUN_00977de0(param_1);

  if (piVar2 != (int *)in_EAX[0xe]) {

    piVar2 = (int *)(**(code **)(*piVar1 + 0x90))();

    iVar3 = (**(code **)(*in_EAX + 0x24))();

    if (iVar3 < *piVar2) {

      (**(code **)(*piVar1 + 0xa4))(0);

      FUN_00803e40(in_EAX + 0x58);

      FUN_00803e40(in_EAX + 0x18);

      FUN_00803e40(in_EAX + 0x58);

    }

    else {

      (**(code **)(*piVar1 + 0xa4))(in_EAX[0x99]);

    }

  }

  FUN_00977de0(param_1);

  FUN_00803b50(in_EAX);

  return 1;

}
