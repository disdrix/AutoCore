// =============================================================================
// FUN_009114f0
// -----------------------------------------------------------------------------
// Stable ID: aa_009114f0
// Address:   0x009114f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009114f0 @ 0x009114f0
// Stable ID: aa_009114f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×14, return×3, do×1, while×1.
//  - Notable callees: FUN_008a0210×2, FUN_008a0ed0×2, Client_QuickBar_ActivateSlot, Client_SendRespawnInSector, FUN_0089fe10, FUN_0089fe40, FUN_008a70c0, FUN_008a70e0.
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

void FUN_009114f0(void)



{

  char cVar1;

  char cVar2;

  int *in_EAX;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ unaff_EBX;

  uint32_t /* width from decompiler */ unaff_ESI;

  int *piVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  if ((DAT_00d1b20f != '\0') && (DAT_00d1b624 != (code *)0x0)) {

    if ((DAT_00d1b958 == (int *)0x0) ||

       (cVar1 = (**(code **)(*DAT_00d1b958 + 0x3d8))(), cVar1 == '\0')) {

      cVar1 = (*DAT_00d1b624)(4);

      (*DAT_00d1b624)(5);

      cVar2 = (*DAT_00d1b624)(3);

      if (((cVar1 != '\0') || ((char)unaff_EBX != '\0')) || (cVar2 != '\0')) {

        if ((DAT_00d1b998 == (int *)0x0) ||

           (cVar1 = (**(code **)(*DAT_00d1b998 + 0xd0))(), cVar1 == '\0')) {

          piVar5 = &DAT_00d1b870;

          do {

            if ((*piVar5 != 0) && (cVar1 = (**(code **)(*(int *)*piVar5 + 0x3d8))(), cVar1 != '\0'))

            {

              (**(code **)(*(int *)*piVar5 + 0x44c))(unaff_ESI,unaff_EBX,cVar2);

            }

            piVar5 = piVar5 + 1;

          } while ((int)piVar5 < 0xd1b958);

        }

        else {

          Client_SendRespawnInSector();

        }

      }

    }

    else {

      cVar1 = (*DAT_00d1b624)(4);

      if ((cVar1 == '\0') || (in_EAX[0x126] < 0)) {

        cVar1 = (*DAT_00d1b624)(5);

        if ((cVar1 != '\0') && (-1 < in_EAX[0x127])) {

          iVar3 = FUN_008a70c0();

          if (iVar3 < 0) {

            iVar3 = in_EAX[0x127];

          }

          (**(code **)(*in_EAX + 0x338))(8,iVar3);

        }

      }

      else {

        iVar3 = FUN_008a70e0();

        if (iVar3 < 0) {

          iVar3 = in_EAX[0x126];

        }

        (**(code **)(*in_EAX + 0x338))(8,iVar3);

      }

    }

    cVar1 = (*DAT_00d1b624)(0xf);

    if (((cVar1 != '\0') && (DAT_00d1b8f0 != (int *)0x0)) &&

       (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0')) {

      FUN_008a0210(1);

    }

    cVar1 = (*DAT_00d1b624)(0x10);

    if (((cVar1 != '\0') && (DAT_00d1b8f0 != (int *)0x0)) &&

       (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0')) {

      FUN_008a0210(0);

    }

    cVar1 = (*DAT_00d1b624)(0x11);

    if (((cVar1 != '\0') && (DAT_00d1b8f0 != (int *)0x0)) &&

       ((cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0' &&

        (cVar1 = FUN_0089fe40(), cVar1 != '\0')))) {

      uVar7 = 0xffffffff;

      uVar6 = 0;

      uVar4 = FUN_0089fe10(0,0xffffffff);

      Client_QuickBar_ActivateSlot(uVar4,uVar6,uVar7);

    }

    cVar1 = (*DAT_00d1b624)(0x12);

    piVar5 = DAT_00d1b8f0;

    if (((cVar1 != '\0') && (DAT_00d1b8f0 != (int *)0x0)) &&

       (cVar1 = (**(code **)(*DAT_00d1b8f0 + 0x3d8))(), cVar1 != '\0')) {

      if (piVar5[0x143] + 1 < 0) {

        FUN_008a0ed0();

        return;

      }

      FUN_008a0ed0();

      return;

    }

  }

  return;

}
