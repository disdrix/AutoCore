// =============================================================================
// FUN_00739c80
// -----------------------------------------------------------------------------
// Stable ID: aa_00739c80
// Address:   0x00739c80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00739c80 @ 0x00739c80
// Stable ID: aa_00739c80
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp"
//   - "Invalid TAG unserializing gfxGeometryPieceSkinned"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~99 non-empty decompiler lines.
//  - Control keywords: if×14, return×3, do×1, while×1.
//  - Notable callees: FUN_00769e40×3, FUN_004373b0×2, FUN_00739670×2, FUN_00970190×2, gfxGeometryPiece_Unserialize×2, FUN_00437000, FUN_00439a00, FUN_00465090.
//  - Strings: ",0x9c

                   ,3,".
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

uint __thiscall FUN_00739c80(int param_1,uint param_2)



{

  char cVar1;

  uint uVar2;

  uint uVar3;

  int iVar4;

  int iVar5;

  int local_24;

  char local_18;

  int local_14;

  int local_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar5 = param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b3f0c;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  stoChunkReader_EnterChunkScope(param_2);

  local_4 = 0;

  if (local_14 != 0x474d5048) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceMorphed.cpp",0x9c

                   ,3,"Invalid TAG unserializing gfxGeometryPieceSkinned");

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return 0xffffffff;

  }

  cVar1 = FUN_00767120();

  if (cVar1 == '\0') {

    if (local_10 == 1) {

      uVar2 = gfxGeometryPiece_Unserialize(param_2);

      param_2 = FUN_004373b0(param_2);

      param_2 = uVar2 | param_2;

      iVar5 = FUN_00970190(2);

      if (iVar5 < 0) {

        FUN_00739670();

      }

      *(uint8_t *)(param_1 + 200) = 1;

    }

    else if (local_10 == 2) {

      uVar2 = gfxGeometryPiece_Unserialize(param_2);

      uVar3 = FUN_004373b0(param_2);

      if (*(int *)(param_2 + 0x4044) == 0) {

        param_2 = FUN_00437000();

      }

      else {

        param_2 = FUN_00769660((char *)(param_1 + 200));

      }

      param_2 = uVar2 | uVar3 | param_2;

      if (*(char *)(param_1 + 200) == '\0') {

        uVar2 = FUN_00439a00();

        param_2 = param_2 | uVar2;

        FUN_00465090();

        iVar4 = 0;

        if (0 < local_24) {

          do {

            uVar2 = FUN_009a0000(*(int *)(param_1 + 0xd0) + iVar4 * 8,iVar5,param_1 + 0x1c,

                                 param_1 + 4);

            param_2 = param_2 | uVar2;

            iVar4 = iVar4 + 1;

          } while (iVar4 < local_24);

        }

        cVar1 = FUN_0096fdf0();

        iVar5 = -1;

        if (*(int *)(param_1 + 0x1c) != 0) {

          iVar5 = FUN_00752510();

        }

        if (cVar1 != '\0') {

          FUN_0096f740();

        }

      }

      else {

        iVar5 = FUN_00970190(2);

      }

      if (iVar5 < 0) {

        FUN_00739670();

      }

    }

    else {

      param_2 = 0xffffffff;

    }

    local_4 = 0xffffffff;

    if (local_18 != '\0') {

      FUN_00769e40();

    }

    ExceptionList = local_c;

    return param_2;

  }

  local_4 = 0xffffffff;

  if (local_18 != '\0') {

    FUN_00769e40();

  }

  ExceptionList = local_c;

  return 0;

}
