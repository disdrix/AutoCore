// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_00769e40×2, FUN_0095ee00, FUN_009701d0, FUN_00989e00, FUN_009a0000, FUN_009a00d0, stoChunkReader_EnterChunkScope, vog_LogMessage.
//  - Strings: "PalShadowProjection.fx"; "Invalid chunk version unserializing gfxShadowVolume"; "Invalid TAG unserializing gfxShadowVolume".
//  - Return sites: 2.

// =============================================================================
// Named_gfxBodyMassageMachine_0095ee00
// -----------------------------------------------------------------------------
// Stable ID: aa_0095ee00
// Address:   0x0095ee00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxBodyMassageMachine"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Named_gfxBodyMassageMachine_0095ee00(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  int unaff_ESI;

  uint32_t /* width from decompiler */ uVar2;

  char *pcVar3;

  uint8_t local_24 [12];

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3beb;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_1);

  local_4 = 0;

  if (local_14 == 0x53484456) {

    if (local_10 == 1) {

      FUN_00989e00(local_24,"PalShadowProjection.fx");

      FUN_009701d0(local_24);

      FUN_009a00d0(unaff_ESI + 8,param_1,unaff_ESI + 0x20);

      *(uint *)(unaff_ESI + 0xbc) = *(uint *)(unaff_ESI + 0xbc) | 1;

      FUN_009a0000(unaff_ESI + 0x10,param_1,unaff_ESI + 0x20,0);

      if (*(int *)(unaff_ESI + 0xc) == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(*(int *)(unaff_ESI + 0xc) + 0x1c);

      }

      *(int *)(unaff_ESI + 0xa8) = iVar1 / 3;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xac) = 4;

      if ((*(uint *)(unaff_ESI + 0xbc) >> 1 & 1) != 0) {

        *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb0) = 2;

      }

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return 0;

    }

    pcVar3 = "Invalid chunk version unserializing gfxShadowVolume";

    uVar2 = 0x702;

  }

  else {

    pcVar3 = "Invalid TAG unserializing gfxShadowVolume";

    uVar2 = 0x6e5;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",uVar2,3,

                 pcVar3);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
