// =============================================================================
// FUN_007478c0
// -----------------------------------------------------------------------------
// Stable ID: aa_007478c0
// Address:   0x007478c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007478c0 @ 0x007478c0
// Stable ID: aa_007478c0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp"
//   - "FVF does not contain indices. Non-Indexed Skinning not supported"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×10, goto×5, switch×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004454f0×13, FUN_0044c3c0, FUN_007478c0, vog_LogMessage.
//  - Strings: ",uVar3,3

                 ,".
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

uint32_t /* width from decompiler */ __thiscall FUN_007478c0(int param_1,uint param_2)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ local_10 [4];

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  FUN_0044c3c0(0,0);

  FUN_004454f0();

  switch(param_2 & 0x400e) {

  case 6:

    if ((param_2 & 0x1000) != 0) {

LAB_00747940:

      FUN_004454f0();

      goto switchD_00747932_default;

    }

    uVar3 = 0x8a;

    break;

  case 8:

    if ((param_2 & 0x1000) != 0) {

      FUN_004454f0();

      FUN_004454f0();

      goto switchD_00747932_default;

    }

    uVar3 = 0xa9;

    break;

  case 10:

    if ((param_2 & 0x1000) != 0) {

      FUN_004454f0();

      FUN_004454f0();

      goto switchD_00747932_default;

    }

    uVar3 = 200;

    break;

  case 0xc:

    if ((param_2 & 0x1000) != 0) {

      FUN_004454f0();

      goto LAB_00747940;

    }

    uVar3 = 0xe7;

    break;

  default:

    goto switchD_00747932_default;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effVertexDecl.cpp",uVar3,3

                 ,"FVF does not contain indices. Non-Indexed Skinning not supported");

switchD_00747932_default:

  if ((param_2 & 0x10) != 0) {

    FUN_004454f0();

  }

  if ((param_2 & 0x20) != 0) {

    FUN_004454f0();

  }

  if ((param_2 & 0x40) != 0) {

    FUN_004454f0();

  }

  if ((char)param_2 < '\0') {

    FUN_004454f0();

  }

  if ((param_2 & 0xf00) != 0) {

    uVar2 = param_2 >> 8 & 0xf;

    uVar1 = param_2 >> 0x10;

    local_10[0] = 8;

    local_10[1] = 0xc;

    local_10[2] = 0x10;

    local_10[3] = 4;

    param_2 = 0;

    if (uVar2 != 0) {

      do {

        switch(local_10[uVar1 & 3]) {

        case 4:

          break;

        case 8:

          break;

        case 0xc:

          break;

        case 0x10:

        }

        FUN_004454f0();

        param_2 = param_2 + 1;

        uVar1 = uVar1 >> 2;

      } while (param_2 < uVar2);

    }

  }

  FUN_004454f0();

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  return 0;

}
