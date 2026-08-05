// =============================================================================
// FUN_0096bdc0
// -----------------------------------------------------------------------------
// Stable ID: aa_0096bdc0
// Address:   0x0096bdc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096bdc0 @ 0x0096bdc0
// Stable ID: aa_0096bdc0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp"
//   - "Cannot compute normal map from texture"
//   - "%s - %s\r\n%s"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: return×3, if×2.
//  - Notable callees: vog_LogMessage×2, FUN_006a5dac, FUN_006b7a5a, FUN_0076cec0, FUN_0096bdc0.
//  - Strings: "Cannot compute normal map from texture"; "%s - %s\r\n%s".
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

uint32_t /* width from decompiler */ FUN_0096bdc0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  int unaff_EDI;

  

  if (((byte)*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x2c) & 0xf) != 1) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                   0x434,3);

    return 0xffffffff;

  }

  iVar1 = D3DXComputeNormalMap

                    (*(uint32_t /* width from decompiler */ *)(unaff_EDI + 0x10),*(uint32_t /* width from decompiler */ *)(param_1 + 0x10),0,param_3,

                     param_4,param_2);

  if (iVar1 < 0) {

    uVar2 = FUN_006b7a5a(iVar1,"Cannot compute normal map from texture");

    uVar2 = FUN_006a5dac(iVar1,uVar2);

    uVar2 = FUN_0076cec0(&stack0xfffffffc,"%s - %s\r\n%s",uVar2);

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",

                   0x43c,3,uVar2);

    return 0xffffffff;

  }

  *(byte *)(unaff_EDI + 0x2d) = *(byte *)(unaff_EDI + 0x2d) | 2;

  return 0;

}
