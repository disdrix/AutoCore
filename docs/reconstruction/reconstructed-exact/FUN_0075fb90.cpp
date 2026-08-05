// =============================================================================
// FUN_0075fb90
// -----------------------------------------------------------------------------
// Stable ID: aa_0075fb90
// Address:   0x0075fb90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0075fb90 @ 0x0075fb90
// Stable ID: aa_0075fb90
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"
//   - "BeginScene() Failed"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×2.
//  - Notable callees: BeginScene, FUN_0075fb90, FUN_0076c3c0, FUN_00965ab0, FUN_0096a3f0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp"; "BeginScene() Failed".
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

uint32_t /* width from decompiler */ FUN_0075fb90(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar1 = DAT_00d1f048;

  if (unaff_EBX[0x1e9] == 0) {

    puVar4 = &DAT_00d0e128;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    puVar4 = &DAT_00d0e0e8;

    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {

      *puVar4 = 0;

      puVar4 = puVar4 + 1;

    }

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[0xf] = 0;

    DAT_00d1a568 = 0;

    DAT_00d1a564 = 0;

    DAT_00d1a558 = 0;

    DAT_00d1a55c = 0;

    iVar3 = (**(code **)(*(int *)*unaff_EBX + 0xa4))((int *)*unaff_EBX);

    if (iVar3 < 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDevice.cpp",0x138,3,

                     "BeginScene() Failed");

      return 0xffffffff;

    }

    iVar3 = unaff_EBX[0x1e8];

    FUN_00965ab0(iVar3);

    uVar2 = FUN_0076c3c0();

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0x30) = uVar2;

    FUN_0096a3f0();

  }

  unaff_EBX[0x1e9] = unaff_EBX[0x1e9] + 1;

  return 0;

}
