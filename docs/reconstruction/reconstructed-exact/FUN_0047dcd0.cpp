// =============================================================================
// FUN_0047dcd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0047dcd0
// Address:   0x0047dcd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047dcd0 @ 0x0047dcd0
// Stable ID: aa_0047dcd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~53 non-empty decompiler lines.
//  - Control keywords: if×5, return×3, do×1, while×1.
//  - Notable callees: SBORROW4×2, FUN_0047dcd0.
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

void FUN_0047dcd0(int param_1)



{

  ushort uVar1;

  ushort uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int in_EAX;

  int iVar6;

  int iVar7;

  int unaff_EDI;

  bool bVar8;

  

  iVar7 = *(int *)(in_EAX + 0x1448);

  iVar3 = *(int *)(in_EAX + 0xb54 + param_1 * 4);

  iVar6 = param_1 * 2;

  bVar8 = SBORROW4(iVar6,iVar7);

  iVar5 = iVar6 - iVar7;

  if (iVar7 < iVar6) {

    *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar3;

    return;

  }

  do {

    iVar7 = iVar6;

    if (bVar8 != iVar5 < 0) {

      iVar5 = *(int *)(in_EAX + 0xb58 + iVar6 * 4);

      iVar4 = *(int *)(in_EAX + 0xb54 + iVar6 * 4);

      uVar1 = *(ushort *)(unaff_EDI + iVar5 * 4);

      uVar2 = *(ushort *)(unaff_EDI + iVar4 * 4);

      if ((uVar1 < uVar2) ||

         ((uVar1 == uVar2 &&

          (*(byte *)(iVar5 + 0x1450 + in_EAX) <= *(byte *)(in_EAX + 0x1450 + iVar4))))) {

        iVar7 = iVar6 + 1;

      }

    }

    iVar5 = *(int *)(in_EAX + 0xb54 + iVar7 * 4);

    uVar1 = *(ushort *)(unaff_EDI + iVar3 * 4);

    uVar2 = *(ushort *)(unaff_EDI + iVar5 * 4);

    if (uVar1 < uVar2) break;

    if ((uVar1 == uVar2) &&

       (*(byte *)(in_EAX + 0x1450 + iVar3) <= *(byte *)(iVar5 + 0x1450 + in_EAX))) {

      *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar3;

      return;

    }

    *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar5;

    iVar4 = *(int *)(in_EAX + 0x1448);

    iVar6 = iVar7 * 2;

    bVar8 = SBORROW4(iVar6,iVar4);

    iVar5 = iVar6 - iVar4;

    param_1 = iVar7;

  } while (iVar6 <= iVar4);

  *(int *)(in_EAX + 0xb54 + param_1 * 4) = iVar3;

  return;

}
