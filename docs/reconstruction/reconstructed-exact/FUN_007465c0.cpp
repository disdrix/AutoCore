// =============================================================================
// FUN_007465c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007465c0
// Address:   0x007465c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007465c0 @ 0x007465c0
// Stable ID: aa_007465c0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"
//   - "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: FUN_007465c0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
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

void FUN_007465c0(void)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *unaff_ESI;

  bool bVar4;

  

  iVar2 = unaff_ESI[4];

  while (0 < iVar2) {

    piVar3 = (int *)*unaff_ESI;

    if (piVar3 != (int *)0x0) {

      piVar1 = unaff_ESI + 4;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                       "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        unaff_ESI[4] = 0;

      }

      else {

        (**(code **)(*piVar3 + 0x30))(piVar3);

      }

    }

    iVar2 = unaff_ESI[4];

  }

  piVar3 = (int *)*unaff_ESI;

  if (piVar3 != (int *)0x0) {

    (**(code **)(*piVar3 + 8))(piVar3);

  }

  iVar2 = DAT_00d1f614;

  bVar4 = DAT_00d1f614 != 0;

  *unaff_ESI = 0;

  if (bVar4) {

    *(int *)(iVar2 + 900) = *(int *)(iVar2 + 900) - unaff_ESI[2] * unaff_ESI[3];

    *(int *)(iVar2 + 0x330) = *(int *)(iVar2 + 0x330) - unaff_ESI[3];

    *(int *)(iVar2 + 0x32c) = *(int *)(iVar2 + 0x32c) + -1;

  }

  return;

}
