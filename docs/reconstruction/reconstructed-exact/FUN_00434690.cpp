// =============================================================================
// FUN_00434690
// -----------------------------------------------------------------------------
// Stable ID: aa_00434690
// Address:   0x00434690  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00434690 @ 0x00434690
// Stable ID: aa_00434690
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×13, return×9, goto×2.
//  - Notable callees: FUN_00434690.
//  - Return sites: 9.

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

uint32_t /* width from decompiler */ FUN_00434690(void)



{

  uint uVar1;

  uint uVar2;

  int iVar3;

  uint *unaff_ESI;

  int *unaff_EDI;

  uint32_t /* width from decompiler */ uVar4;

  

  if ((unaff_EDI == (int *)0x0) || (unaff_ESI == (uint *)0x0)) {

    return 0;

  }

  iVar3 = (**(code **)(*unaff_EDI + 8))();

  if (iVar3 == 0) {

    return 0;

  }

  uVar1 = *unaff_ESI;

  if (uVar1 == 0xc) {

    uVar1 = unaff_ESI[1];

    uVar2 = unaff_ESI[2];

    *unaff_ESI = *unaff_ESI;

    *(short *)(unaff_ESI + 3) = (short)uVar2;

    unaff_ESI[1] = uVar1 & 0xffff;

    unaff_ESI[2] = uVar1 >> 0x10;

    *(short *)((int)unaff_ESI + 0xe) = (short)(uVar2 >> 0x10);

    unaff_ESI[4] = 0;

    unaff_ESI[5] = 0;

    unaff_ESI[6] = 0;

    unaff_ESI[7] = 0;

    unaff_ESI[8] = 0;

    unaff_ESI[9] = 0;

    uVar4 = 0xffffffe4;

  }

  else {

    if (uVar1 == 0x28) goto LAB_00434777;

    if (uVar1 != 0x40) {

      if (uVar1 < 0x29) {

        return 0;

      }

      iVar3 = (uint)*(ushort *)((int)unaff_ESI + 0xe) * unaff_ESI[1] + 0x1f;

      if (unaff_ESI[5] != ((int)(iVar3 + (iVar3 >> 0x1f & 0x1fU)) >> 5) * unaff_ESI[2] * 4) {

        return 0;

      }

      if ((short)unaff_ESI[3] != 1) {

        return 0;

      }

      if (unaff_ESI[4] != 0) {

        return 0;

      }

      if (unaff_ESI[8] != 0) {

        return 0;

      }

      (**(code **)(*unaff_EDI + 0x10))(uVar1 - 0x28,1);

      goto LAB_00434777;

    }

    uVar4 = 0x18;

  }

  (**(code **)(*unaff_EDI + 0x10))(uVar4,1);

LAB_00434777:

  if (unaff_ESI[5] == 0) {

    unaff_ESI[5] = ((uint)*(ushort *)((int)unaff_ESI + 0xe) * unaff_ESI[1] + 0x1f >> 3 & 0x1ffffffc)

                   * unaff_ESI[2];

  }

  if (unaff_ESI[8] == 0) {

    if (*(ushort *)((int)unaff_ESI + 0xe) < 9) {

      unaff_ESI[8] = 1 << ((byte)*(ushort *)((int)unaff_ESI + 0xe) & 0x1f);

      return 1;

    }

    unaff_ESI[8] = 0;

  }

  return 1;

}
