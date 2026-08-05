// =============================================================================
// FUN_008e05a0
// -----------------------------------------------------------------------------
// Stable ID: aa_008e05a0
// Address:   0x008e05a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008e05a0 @ 0x008e05a0
// Stable ID: aa_008e05a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~226 non-empty decompiler lines.
//  - Control keywords: if×23, do×1, while×1, return×1.
//  - Notable callees: FUN_008df430×91, FUN_008dfc60×32, FUN_008e0410×17, FUN_008dfac0×6, FUN_008df510, FUN_008df660, FUN_008df6a0, FUN_008e05a0.
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

void __fastcall FUN_008e05a0(int *param_1)



{

  char cVar1;

  uint8_t uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *piVar4;

  int iVar5;

  

  if ((DAT_00d1b6d8 != 0) && (cVar1 = (**(code **)(*param_1 + 0x3d8))(), cVar1 != '\0')) {

    FUN_008df510();

    FUN_008df6a0();

    FUN_008df660();

    param_1[0x155] = 1;

    param_1[0x156] = 2;

    param_1[0x157] = 3;

    param_1[0x158] = 4;

    param_1[0x159] = 5;

    param_1[0x15a] = 6;

    param_1[0x15b] = 9;

    param_1[0x15c] = 10;

    param_1[0x15d] = 7;

    param_1[0x15e] = 8;

    param_1[0x15f] = 0xb;

    param_1[0x160] = 0xc;

    param_1[0x161] = 0xe;

    param_1[0x162] = 0xd;

    param_1[0x163] = 0xf;

    param_1[0x164] = 0x10;

    param_1[0x165] = 0x1c;

    FUN_008e0410(1,0);

    FUN_008e0410(3,0);

    FUN_008e0410(5,0);

    FUN_008e0410(0,1);

    FUN_008e0410(1,1);

    FUN_008e0410(4,1);

    FUN_008e0410(3,2);

    FUN_008e0410(5,2);

    FUN_008e0410(1,2);

    FUN_008e0410(2,2);

    FUN_008e0410(1,3);

    FUN_008e0410(2,3);

    FUN_008e0410(4,3);

    FUN_008e0410(3,3);

    FUN_008e0410(5,3);

    FUN_008e0410(2,4);

    FUN_008e0410(4,4);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,1,0,0,0,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,0,0,0,1,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,1,0,1,1,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,0,1,0,2,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,0,2,1,2,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,1,1,1,2,uVar3);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,1,2,2,2,uVar2);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,2,2,3,2,uVar2);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,3,0,4,0,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,4,0,5,0,uVar3);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,4,0,4,1,uVar2);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,5,0,5,2,uVar3);

    cVar1 = FUN_008df430();

    if ((((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

        (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,3,0,3,1,uVar2);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       ((cVar1 = FUN_008df430(), cVar1 != '\0' ||

        ((cVar1 = FUN_008df430(), cVar1 != '\0' ||

         (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')))))) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,1,1,2,1,uVar2);

    cVar1 = FUN_008df430();

    if ((((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

        (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       ((cVar1 = FUN_008df430(), cVar1 != '\0' || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')

        ))) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,2,1,3,1,uVar2);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       ((cVar1 = FUN_008df430(), cVar1 != '\0' ||

        ((cVar1 = FUN_008df430(), cVar1 != '\0' ||

         (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')))))) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,3,1,4,1,uVar2);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,2,1,2,2,uVar2);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,3,1,3,2,uVar2);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,4,1,4,2,uVar2);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,3,2,4,2,uVar2);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,4,2,5,2,uVar2);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,1,2,1,3,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,2,2,2,3,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,3,2,3,3,uVar3);

    cVar1 = FUN_008df430();

    if (((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,4,2,4,3,uVar2);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,5,2,5,3,uVar3);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,1,3,2,3,uVar2);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,2,3,3,3,uVar2);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,3,3,4,3,uVar2);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfc60(param_1,4,3,5,3,uVar2);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,2,3,2,4,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfc60(param_1,4,3,4,4,uVar3);

    uVar3 = FUN_008df430();

    FUN_008dfac0(0,0,uVar3);

    cVar1 = FUN_008df430();

    if ((cVar1 != '\0') || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfac0(4,0,uVar2);

    cVar1 = FUN_008df430();

    if ((((((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

          (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

         ((cVar1 = FUN_008df430(), cVar1 != '\0' || (cVar1 = FUN_008df430(), cVar1 != '\0')))) ||

        (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfac0(2,1,uVar2);

    cVar1 = FUN_008df430();

    if ((((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

        ((cVar1 = FUN_008df430(), cVar1 != '\0' ||

         (((cVar1 = FUN_008df430(), cVar1 != '\0' || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

          (cVar1 = FUN_008df430(), cVar1 != '\0')))))) ||

       (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')) {

      uVar2 = 1;

    }

    FUN_008dfac0(3,1,uVar2);

    uVar3 = FUN_008df430();

    FUN_008dfac0(0,2,uVar3);

    cVar1 = FUN_008df430();

    if ((((cVar1 != '\0') || (cVar1 = FUN_008df430(), cVar1 != '\0')) ||

        ((cVar1 = FUN_008df430(), cVar1 != '\0' ||

         ((cVar1 = FUN_008df430(), cVar1 != '\0' || (cVar1 = FUN_008df430(), cVar1 != '\0')))))) ||

       ((cVar1 = FUN_008df430(), cVar1 != '\0' || (cVar1 = FUN_008df430(), uVar2 = 0, cVar1 != '\0')

        ))) {

      uVar2 = 1;

    }

    FUN_008dfac0(4,2,uVar2);

    piVar4 = param_1 + 0x166;

    iVar5 = 0x11;

    do {

      if (*piVar4 != 0) {

        (**(code **)(*param_1 + 0xb0))(*piVar4);

        (**(code **)(*param_1 + 0xa8))(*piVar4);

      }

      piVar4 = piVar4 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

  }

  return;

}
