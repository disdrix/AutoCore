// =============================================================================
// FUN_0095f880
// -----------------------------------------------------------------------------
// Stable ID: aa_0095f880
// Address:   0x0095f880  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0095f880 @ 0x0095f880
// Stable ID: aa_0095f880
// Embedded strings (evidence for future rename):
//   - "Invalid chunk version unserializing gfxMorphedGeometryNodeMaster"
//   - "Invalid TAG unserializing gfxMorphedGeometryNodeMaster"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00769e40×2, FUN_0095dae0, FUN_0095f560, FUN_0095f880, stoChunkReader_EnterChunkScope, vog_LogMessage.
//  - Strings: ";

    uVar3 = 0x5a4;

  }

  else {

    pcVar4 = "; ";

    uVar3 = 0x595;

  }

  vog_LogMessage(".
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

uint FUN_0095f880(void)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ uVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ local_38;

  uint8_t local_34 [8];

  void *local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3c4e;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(unaff_ESI);

  local_4 = 0;

  if (local_14 == 0x4d52464d) {

    if (local_10 == 1) {

      local_38 = 0;

      local_2c = (void *)0x0;

      local_28 = 0;

      local_24 = 0;

      local_4 = 1;

      uVar1 = FUN_0095dae0(&local_38,local_34);

      uVar2 = FUN_0095f560();

      if (local_2c != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

        operator_delete(local_2c);

      }

      local_4 = 0xffffffff;

      if (local_18 != '\0') {

        FUN_00769e40();

      }

      ExceptionList = local_c;

      return uVar1 | uVar2;

    }

    pcVar4 = "Invalid chunk version unserializing gfxMorphedGeometryNodeMaster";

    uVar3 = 0x5a4;

  }

  else {

    pcVar4 = "Invalid TAG unserializing gfxMorphedGeometryNodeMaster";

    uVar3 = 0x595;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxBodyMassageMachine.cpp",uVar3,3,

                 pcVar4);

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0xffffffff;

}
