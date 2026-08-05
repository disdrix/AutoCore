// =============================================================================
// FUN_0072cde0
// -----------------------------------------------------------------------------
// Stable ID: aa_0072cde0
// Address:   0x0072cde0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072cde0 @ 0x0072cde0
// Stable ID: aa_0072cde0
// Embedded strings (evidence for future rename):
//   - "Invalid chunk version unserializing phyBoundingVolume"
//   - "Invalid TAG unserializing phyBoundingVolume"
//   - "C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingVolume.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_00769e40×2, FUN_00435fe0, FUN_0072cde0, FUN_00767fd0, stoChunkReader_EnterChunkScope, vog_LogMessage.
//  - Strings: "Invalid chunk version unserializing phyBoundingVolume"; "Invalid TAG unserializing phyBoundingVolume".
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

int __thiscall FUN_0072cde0(int param_1,int param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1776;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 == 0x42564f4c) {

    if (local_10 == 1) {

      if (*(int *)(param_2 + 0x4044) == 0) {

        FUN_00435fe0(param_1 + 4);

      }

      else {

        FUN_00767fd0(param_1 + 4);

      }

      iVar1 = *(int *)(param_2 + 0x402c);

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return (-1 < iVar1) - 1;

    }

    pcVar3 = "Invalid chunk version unserializing phyBoundingVolume";

    uVar2 = 0x52;

  }

  else {

    pcVar3 = "Invalid TAG unserializing phyBoundingVolume";

    uVar2 = 0x44;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\physics\\phyBoundingVolume.cpp",uVar2,3,

                 pcVar3);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return -1;

}
