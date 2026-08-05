// =============================================================================
// FUN_00871030
// -----------------------------------------------------------------------------
// Stable ID: aa_00871030
// Address:   0x00871030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00871030 @ 0x00871030
// Stable ID: aa_00871030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×2.
//  - Notable callees: FUN_007fd970, FUN_008705c0, FUN_00871030, sprintf.
//  - Return sites: 2.

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

void FUN_00871030(void)



{

  uint32_t /* width from decompiler */ uVar1;

  int unaff_EBX;

  int iVar2;

  int *piVar3;

  int iVar4;

  char acStack_104 [260];

  

  iVar2 = 0;

  if (*(short *)(unaff_EBX + 0x510) != 0) {

    piVar3 = (int *)(unaff_EBX + 0x608);

    iVar4 = unaff_EBX + 0x518;

    do {

      if (*piVar3 != 0) {

        (**(code **)(*(int *)*piVar3 + 4))(1);

        FUN_008705c0(unaff_EBX,acStack_104);

        (**(code **)(*(int *)*piVar3 + 0x1d8))(acStack_104,1,1);

        uVar1 = FUN_007fd970();

        (**(code **)(*(int *)*piVar3 + 0x15c))(1,uVar1);

        (**(code **)(*(int *)*piVar3 + 0x34c))();

      }

      if (piVar3[4] != 0) {

        (**(code **)(*(int *)piVar3[4] + 4))(1);

        sprintf(acStack_104,"%d",*(uint32_t /* width from decompiler */ *)(iVar4 + 8));

        (**(code **)(*(int *)piVar3[4] + 0x1d8))(acStack_104,1,1);

        (**(code **)(*(int *)piVar3[4] + 0x34c))();

      }

      iVar2 = iVar2 + 1;

      piVar3 = piVar3 + 1;

      iVar4 = iVar4 + 0xc;

    } while (iVar2 < (int)(uint)*(ushort *)(unaff_EBX + 0x510));

    if (3 < iVar2) {

      return;

    }

  }

  piVar3 = (int *)(unaff_EBX + 0x618 + iVar2 * 4);

  iVar2 = 4 - iVar2;

  do {

    if (piVar3[-4] != 0) {

      (**(code **)(*(int *)piVar3[-4] + 4))(0);

    }

    if (*piVar3 != 0) {

      (**(code **)(*(int *)*piVar3 + 4))(0);

    }

    piVar3 = piVar3 + 1;

    iVar2 = iVar2 + -1;

  } while (iVar2 != 0);

  return;

}
