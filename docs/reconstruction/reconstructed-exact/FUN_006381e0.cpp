// =============================================================================
// FUN_006381e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006381e0
// Address:   0x006381e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006381e0 @ 0x006381e0
// Stable ID: aa_006381e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×8, goto×1, do×1, return×1, while×1.
//  - Notable callees: FUN_006381e0, _vsnprintf.
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

void FUN_006381e0(int *param_1,char *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *param_1;

  if ((*(int *)(iVar2 + -4) < 1) && (0x32 < *(int *)(iVar2 + -8) + 0xd)) goto LAB_00638241;

  piVar1 = (int *)(iVar2 + -4);

  *piVar1 = *piVar1 + -1;

  if (*piVar1 < 0) {

    (**(code **)(*DAT_00b05060 + 0x14))(iVar2 + -0xc,*(int *)(iVar2 + -8) + 0xd,0x11);

  }

  piVar1 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(0x10c,0x11);

  *piVar1 = 0xff;

  piVar1[1] = 0xff;

  do {

    piVar1[2] = 0;

    *param_1 = (int)(piVar1 + 3);

LAB_00638241:

    iVar3 = *(int *)((char *)*param_1 + -8) + 0xd;

    iVar2 = _vsnprintf((char *)*param_1,iVar3 / 2,param_2,&stack0x0000000c);

    if (iVar2 < 0) {

      iVar2 = *param_1;

      piVar1 = (int *)(iVar2 + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        (**(code **)(*DAT_00b05060 + 0x14))(iVar2 + -0xc,*(int *)(iVar2 + -8) + 0xd,0x11);

      }

      iVar2 = iVar3 * 2;

      if (iVar2 < 0x100) {

        iVar2 = 0xff;

      }

    }

    else {

      if (iVar2 < iVar3) {

        *(int *)(*param_1 + -0xc) = iVar2;

        return;

      }

      iVar3 = *param_1;

      piVar1 = (int *)(iVar3 + -4);

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        (**(code **)(*DAT_00b05060 + 0x14))(iVar3 + -0xc,*(int *)(iVar3 + -8) + 0xd,0x11);

      }

    }

    iVar3 = iVar2;

    if (iVar2 < 0x33) {

      iVar3 = 0x33;

    }

    piVar1 = (int *)(**(code **)(*DAT_00b05060 + 0x10))(iVar3 + 0xd,0x11);

    *piVar1 = iVar2;

    piVar1[1] = iVar3;

  } while( true );

}
