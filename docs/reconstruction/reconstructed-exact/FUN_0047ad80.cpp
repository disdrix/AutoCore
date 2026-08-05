// =============================================================================
// FUN_0047ad80
// -----------------------------------------------------------------------------
// Stable ID: aa_0047ad80
// Address:   0x0047ad80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047ad80 @ 0x0047ad80
// Stable ID: aa_0047ad80
// Embedded strings (evidence for future rename):
//   - "gamma = (%d/100000)\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×8, return×7.
//  - Notable callees: FUN_00476d60×6, FUN_0047a480×4, FUN_0046feb0, FUN_0046ff50, FUN_00476cc0, FUN_0047a420, FUN_0047ad80, fprintf.
//  - Strings: "gamma = (%d/100000)\n".
//  - Return sites: 7.

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

void __thiscall FUN_0047ad80(int param_1,int param_2)



{

  uint uVar1;

  int in_EAX;

  int iVar2;

  float fVar3;

  uint32_t /* width from decompiler */ local_8;

  

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

  if (((param_2 != 0) && ((*(uint *)(param_2 + 8) & 1) != 0)) &&

     ((*(uint *)(param_2 + 8) & 0x800) == 0)) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  if (in_EAX != 4) {

    FUN_00476d60();

    FUN_0047a480();

    return;

  }

  FUN_0047a420();

  iVar2 = FUN_0047a480();

  if (iVar2 == 0) {

    iVar2 = (((local_8 & 0xff) * 0x100 + (local_8 >> 8 & 0xff)) * 0x100 + (local_8._2_2_ & 0xff)) *

            0x100 + (uint)(local_8._2_2_ >> 8);

    if (iVar2 == 0) {

      FUN_00476d60();

      return;

    }

    if (((*(byte *)(param_2 + 9) & 8) != 0) && ((iVar2 < 45000 || (46000 < iVar2)))) {

      FUN_00476d60();

      fprintf((FILE *)(_iob_exref + 0x40),"gamma = (%d/100000)\n");

      return;

    }

    fVar3 = (float)iVar2 * DAT_00aaa620;

    *(float *)(param_1 + 0x15c) = fVar3;

    FUN_0046feb0((double)fVar3);

    FUN_0046ff50();

  }

  return;

}
