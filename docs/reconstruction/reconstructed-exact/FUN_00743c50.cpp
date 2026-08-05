// =============================================================================
// FUN_00743c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00743c50
// Address:   0x00743c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00743c50 @ 0x00743c50
// Stable ID: aa_00743c50
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp"
//   - "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo..."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, while×1, return×1.
//  - Notable callees: FUN_00743c50, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp".
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

void FUN_00743c50(void)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  int *unaff_ESI;

  bool bVar4;

  

  iVar2 = unaff_ESI[3];

  while (0 < iVar2) {

    piVar3 = (int *)*unaff_ESI;

    if (piVar3 != (int *)0x0) {

      piVar1 = unaff_ESI + 3;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceIB.cpp",0xca,1,

                       "Call to gfxDeviceIB::Unlock more times than locked! Bad mojo...");

        unaff_ESI[3] = 0;

      }

      else {

        (**(code **)(*piVar3 + 0x30))(piVar3);

      }

    }

    iVar2 = unaff_ESI[3];

  }

  piVar3 = (int *)*unaff_ESI;

  if (piVar3 != (int *)0x0) {

    (**(code **)(*piVar3 + 8))(piVar3);

  }

  iVar2 = DAT_00d1f614;

  bVar4 = DAT_00d1f614 != 0;

  *unaff_ESI = 0;

  if (bVar4) {

    *(int *)(iVar2 + 0x38c) = *(int *)(iVar2 + 0x38c) - unaff_ESI[4] * unaff_ESI[1];

    *(int *)(iVar2 + 0x340) = *(int *)(iVar2 + 0x340) - unaff_ESI[1];

    *(int *)(iVar2 + 0x33c) = *(int *)(iVar2 + 0x33c) + -1;

  }

  return;

}
