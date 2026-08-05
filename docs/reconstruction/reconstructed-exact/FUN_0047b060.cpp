// =============================================================================
// FUN_0047b060
// -----------------------------------------------------------------------------
// Stable ID: aa_0047b060
// Address:   0x0047b060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047b060 @ 0x0047b060
// Stable ID: aa_0047b060
// Embedded strings (evidence for future rename):
//   - "wx=%f, wy=%f, rx=%f, ry=%f\n"
//   - "gx=%f, gy=%f, bx=%f, by=%f\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~114 non-empty decompiler lines.
//  - Control keywords: if×11, return×10.
//  - Notable callees: FUN_00476d60×9, FUN_0047a480×9, FUN_0047a420×8, FUN_0047a400×6, fprintf×2, FUN_0046f900, FUN_0046fc80, FUN_00476cc0.
//  - Strings: "wx=%f, wy=%f, rx=%f, ry=%f\n"; "gx=%f, gy=%f, bx=%f, by=%f\n".
//  - Return sites: 10.

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

void __thiscall FUN_0047b060(int param_1,int param_2)



{

  int in_EAX;

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  uint uVar5;

  uint uVar6;

  uint uVar7;

  uint uVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  uint32_t /* width from decompiler */ local_3c;

  

  uVar1 = *(uint *)(param_1 + 0x68);

  if ((uVar1 & 1) == 0) {

                    /* WARNING: Subroutine does not return */

    FUN_00476cc0();

  }

  if ((uVar1 & 4) != 0) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if ((uVar1 & 2) != 0) {

    FUN_00476d60();

  }

  if (((param_2 != 0) && ((*(uint *)(param_2 + 8) & 4) != 0)) &&

     ((*(uint *)(param_2 + 8) & 0x800) == 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if (in_EAX != 0x20) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_0047a420();

  uVar8 = (((local_3c & 0xff) * 0x100 + (local_3c >> 8 & 0xff)) * 0x100 + (local_3c._2_2_ & 0xff)) *

          0x100 + (uint)(local_3c._2_2_ >> 8);

  FUN_0047a420();

  uVar1 = (((local_3c & 0xff) * 0x100 + (local_3c >> 8 & 0xff)) * 0x100 + (local_3c._2_2_ & 0xff)) *

          0x100 + (uint)(local_3c._2_2_ >> 8);

  if (((uVar8 < 0x13881) && (uVar1 < 0x13881)) && (uVar1 + uVar8 < 0x186a1)) {

    FUN_0047a420();

    uVar2 = FUN_0047a400();

    FUN_0047a420();

    uVar3 = FUN_0047a400();

    if (((80000 < uVar2) || (80000 < uVar3)) || (100000 < uVar3 + uVar2)) {

      FUN_00476d60();

      FUN_0047a480();

      return;

    }

    FUN_0047a420();

    uVar4 = FUN_0047a400();

    FUN_0047a420();

    uVar5 = FUN_0047a400();

    if (((80000 < uVar4) || (80000 < uVar5)) || (100000 < uVar5 + uVar4)) {

      FUN_00476d60();

      FUN_0047a480();

      return;

    }

    FUN_0047a420();

    uVar6 = FUN_0047a400();

    FUN_0047a420();

    uVar7 = FUN_0047a400();

    if (((uVar6 < 0x13881) && (uVar7 < 0x13881)) && (uVar7 + uVar6 < 0x186a1)) {

      fVar9 = (float)(int)uVar8 * DAT_00aaa620;

      fVar10 = (float)(int)uVar1 * DAT_00aaa620;

      fVar11 = (float)(int)uVar2 * DAT_00aaa620;

      fVar12 = (float)(int)uVar3 * DAT_00aaa620;

      fVar13 = (float)(int)uVar4 * DAT_00aaa620;

      fVar14 = (float)(int)uVar5 * DAT_00aaa620;

      fVar15 = (float)(int)uVar6 * DAT_00aaa620;

      fVar16 = (float)(int)uVar7 * DAT_00aaa620;

      if ((*(byte *)(param_2 + 9) & 8) != 0) {

        if ((((((int)uVar8 < 0x763e) || (0x7e0e < (int)uVar8)) ||

             (((int)uVar1 < 0x7c9c ||

              ((((0x846c < (int)uVar1 || ((int)uVar2 < 63000)) || (65000 < (int)uVar2)) ||

               (((int)uVar3 < 32000 || (34000 < (int)uVar3)))))))) ||

            (((int)uVar4 < 29000 || ((31000 < (int)uVar4 || ((int)uVar5 < 59000)))))) ||

           (((61000 < (int)uVar5 ||

             ((((int)uVar6 < 14000 || (16000 < (int)uVar6)) || ((int)uVar7 < 5000)))) ||

            (7000 < (int)uVar7)))) {

          FUN_00476d60();

          fprintf((FILE *)(_iob_exref + 0x40),"wx=%f, wy=%f, rx=%f, ry=%f\n",(double)fVar9,

                  (double)fVar10,(double)fVar11,(double)fVar12);

          fprintf((FILE *)(_iob_exref + 0x40),"gx=%f, gy=%f, bx=%f, by=%f\n",(double)fVar13,

                  (double)fVar14,(double)fVar15,(double)fVar16);

        }

        FUN_0047a480();

        return;

      }

      FUN_0046f900((double)fVar9,(double)fVar10,(double)fVar11,(double)fVar12,(double)fVar13,

                   (double)fVar14,(double)fVar15,(double)fVar16);

      FUN_0046fc80(param_1,uVar8,uVar1,uVar2,uVar3,uVar4,uVar5,uVar6,uVar7);

      FUN_0047a480();

      return;

    }

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_00476d60();

  FUN_0047a480();

  return;

}
