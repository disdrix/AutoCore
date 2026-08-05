// =============================================================================
// FUN_0071fc20
// -----------------------------------------------------------------------------
// Stable ID: aa_0071fc20
// Address:   0x0071fc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071fc20 @ 0x0071fc20
// Stable ID: aa_0071fc20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0071f8c0, FUN_0071faf0, FUN_0071fc20.
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

int FUN_0071fc20(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4,

                uint32_t /* width from decompiler */ param_5)



{

  int in_EAX;

  int *piVar1;

  int iVar2;

  

  if (*(int *)(in_EAX + 0x10) == 0) {

    return -0x7ffbfe10;

  }

  piVar1 = (int *)FUN_0071faf0();

  if (piVar1 != (int *)0x0) {

    iVar2 = FUN_0071f8c0();

    if ((-1 < iVar2) && (param_4 == 0)) {

      if ((*(byte *)(in_EAX + 0x20) & 0x80) != 0) {

        (**(code **)(*piVar1 + 0x3c))(piVar1,param_3);

      }

      if ((*(byte *)(in_EAX + 0x20) & 0x20) != 0) {

        (**(code **)(*piVar1 + 0x44))(piVar1,0);

      }

      if ((*(byte *)(in_EAX + 0x20) & 0x40) != 0) {

        (**(code **)(*piVar1 + 0x40))(piVar1,param_5);

      }

      *(uint8_t *)(in_EAX + 0x38) = 0;

      iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,0,param_1,param_2);

    }

    return iVar2;

  }

  return -0x7fffbffb;

}
