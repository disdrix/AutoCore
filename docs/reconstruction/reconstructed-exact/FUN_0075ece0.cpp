// =============================================================================
// FUN_0075ece0
// -----------------------------------------------------------------------------
// Stable ID: aa_0075ece0
// Address:   0x0075ece0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075ece0 @ 0x0075ece0
// Stable ID: aa_0075ece0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"
//   - "EndScene() Failed"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: EndScene, FUN_0074f360, FUN_0075ece0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"; "EndScene() Failed".
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

uint32_t /* width from decompiler */ FUN_0075ece0(void)



{

  int iVar1;

  uint32_t /* width from decompiler */ *unaff_EDI;

  

  iVar1 = DAT_00d1f05c;

  if (unaff_EDI[0x1e9] == 1) {

    if (*(int *)(DAT_00d1f05c + 4) != 0) {

      FUN_0074f360();

      iVar1 = *(int *)(iVar1 + 0x144);

      if (iVar1 != 0) {

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0xc) = 0;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x10) = 0xffffffff;

        *(uint32_t /* width from decompiler */ *)(iVar1 + 0x14) = 0xffffffff;

      }

    }

    iVar1 = (**(code **)(*(int *)*unaff_EDI + 0xa8))((int *)*unaff_EDI);

    if (iVar1 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x15b,3,

                     "EndScene() Failed");

      return 0xffffffff;

    }

  }

  unaff_EDI[0x1e9] = unaff_EDI[0x1e9] + -1;

  return 0;

}
