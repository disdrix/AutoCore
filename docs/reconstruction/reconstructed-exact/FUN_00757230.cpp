// =============================================================================
// FUN_00757230
// -----------------------------------------------------------------------------
// Stable ID: aa_00757230
// Address:   0x00757230  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00757230 @ 0x00757230
// Stable ID: aa_00757230
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp"
//   - "PopClipRect() - clip stack empty"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00757230, PopClipRect, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp"; "PopClipRect() - clip stack empty".
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

void __fastcall FUN_00757230(int param_1)



{

  int iVar1;

  

  iVar1 = param_1;

  if ((*(int *)(param_1 + 0x5c) != 0) &&

     (iVar1 = 0, *(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x5c) >> 4 != 0)) {

    iVar1 = *(int *)(param_1 + 0x60);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = *(uint32_t /* width from decompiler */ *)(iVar1 + -0x10);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = *(uint32_t /* width from decompiler */ *)(iVar1 + -0xc);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = *(uint32_t /* width from decompiler */ *)(iVar1 + -8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = *(uint32_t /* width from decompiler */ *)(iVar1 + -4);

    if (*(int *)(param_1 + 0x5c) != 0) {

      if (*(int *)(param_1 + 0x60) - *(int *)(param_1 + 0x5c) >> 4 != 0) {

        *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + -0x10;

      }

    }

    return;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxUIWindow.cpp",0x308,3,

                 "PopClipRect() - clip stack empty",iVar1);

  return;

}
