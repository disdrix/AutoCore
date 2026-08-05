// =============================================================================
// FUN_009745a2
// -----------------------------------------------------------------------------
// Stable ID: aa_009745a2
// Address:   0x009745a2  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009745a2 @ 0x009745a2
// Stable ID: aa_009745a2
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×2, while×2.
//  - Notable callees: FUN_00974370, FUN_00974470, FUN_009745a2.
//  - Return sites: 4.

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

int FUN_009745a2(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  int *unaff_EBP;

  int *piVar3;

  int *piVar4;

  bool bVar5;

  

  iVar2 = 2;

  bVar5 = true;

  piVar3 = unaff_EBP;

  piVar4 = (int *)(in_EAX + 0xc);

  do {

    if (iVar2 == 0) break;

    iVar2 = iVar2 + -1;

    bVar5 = *piVar3 == *piVar4;

    piVar3 = piVar3 + 1;

    piVar4 = piVar4 + 1;

  } while (bVar5);

  if (bVar5) {

    iVar2 = *(int *)(in_EAX + 0x1c);

  }

  else {

    iVar2 = 2;

    bVar5 = true;

    piVar3 = (int *)(in_EAX + 0x14);

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar5 = *unaff_EBP == *piVar3;

      unaff_EBP = unaff_EBP + 1;

      piVar3 = piVar3 + 1;

    } while (bVar5);

    if (!bVar5) {

      return 2;

    }

    iVar2 = *(int *)(in_EAX + 0x20);

  }

  if (iVar2 == 0) {

    return 2;

  }

  cVar1 = FUN_00974470(param_3);

  if (cVar1 != '\0') {

    cVar1 = FUN_00974370(iVar2);

    return (-(uint)(cVar1 != '\0') & 0xfffffffd) + 3;

  }

  return 1;

}
