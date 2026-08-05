// =============================================================================
// FUN_0071fb60
// -----------------------------------------------------------------------------
// Stable ID: aa_0071fb60
// Address:   0x0071fb60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071fb60 @ 0x0071fb60
// Stable ID: aa_0071fb60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: if×6, return×3.
//  - Notable callees: FUN_0071f8c0, FUN_0071faf0, FUN_0071fb60.
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

int FUN_0071fb60(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int in_EAX;

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ unaff_EDI;

  int *piVar3;

  int *piVar4;

  int local_c;

  int local_8;

  uint8_t local_4 [4];

  

  if (*(int *)(in_EAX + 0x10) == 0) {

    return -0x7ffbfe10;

  }

  piVar1 = (int *)FUN_0071faf0();

  if (piVar1 != (int *)0x0) {

    iVar2 = FUN_0071f8c0();

    if ((-1 < iVar2) && (local_8 == 0)) {

      if ((*(byte *)(in_EAX + 0x20) & 0x20) != 0) {

        (**(code **)(*piVar1 + 0x20))(piVar1,local_4);

        (**(code **)(*piVar1 + 0x44))(piVar1,local_c + param_2);

      }

      piVar4 = &local_c;

      iVar2 = (**(code **)*piVar1)(piVar1,&DAT_00a0d034);

      if (-1 < iVar2) {

        piVar3 = (int *)0x0;

        iVar2 = (**(code **)(*piVar4 + 0x30))(piVar4,local_8);

        if (-1 < iVar2) {

          iVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,0,unaff_EDI,local_c);

        }

        (**(code **)(*piVar3 + 8))(piVar3);

      }

    }

    return iVar2;

  }

  return -0x7fffbffb;

}
