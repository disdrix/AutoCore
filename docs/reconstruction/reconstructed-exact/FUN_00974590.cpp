// =============================================================================
// FUN_00974590
// -----------------------------------------------------------------------------
// Stable ID: aa_00974590
// Address:   0x00974590  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00974590 @ 0x00974590
// Stable ID: aa_00974590
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×7, return×5, do×2, while×2.
//  - Notable callees: FUN_00974370, FUN_00974470, FUN_00974590.
//  - Return sites: 5.

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

int __fastcall

FUN_00974590(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,int *param_5)



{

  char cVar1;

  int *in_EAX;

  int iVar2;

  int *piVar3;

  int *piVar4;

  bool bVar5;

  

  if (param_2 != *in_EAX) {

    return 4;

  }

  iVar2 = 2;

  bVar5 = true;

  piVar3 = param_5;

  piVar4 = in_EAX + 3;

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *piVar3 == *piVar4;

    piVar3 = piVar3 + 1;

    piVar4 = piVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    iVar2 = in_EAX[7];

  }

  else {

    iVar2 = 2;

    bVar5 = true;

    piVar3 = param_5;

    piVar4 = in_EAX + 5;

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar5 = *piVar3 == *piVar4;

      piVar3 = piVar3 + 1;

      piVar4 = piVar4 + 1;

    } while (bVar5);

    if (!bVar5) {

      return 2;

    }

    iVar2 = in_EAX[8];

  }

  if (iVar2 == 0) {

    return 2;

  }

  cVar1 = FUN_00974470(param_4,param_5);

  if (cVar1 != '\0') {

    cVar1 = FUN_00974370(iVar2);

    return (-(uint)(cVar1 != '\0') & 0xfffffffd) + 3;

  }

  return 1;

}
