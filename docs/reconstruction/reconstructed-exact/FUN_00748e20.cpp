// =============================================================================
// FUN_00748e20
// -----------------------------------------------------------------------------
// Stable ID: aa_00748e20
// Address:   0x00748e20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00748e20 @ 0x00748e20
// Stable ID: aa_00748e20
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×11, return×4, for×1, goto×1, do×1, while×1.
//  - Notable callees: FUN_00414a50×3, FUN_0044ba80×2, FUN_0044bd10, FUN_0044be40, FUN_00743be0, FUN_00746520, FUN_00748e20, FUN_00962ea0.
//  - Strings: ",0x520,2,

                   ".
//  - Return sites: 4.

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

byte __thiscall FUN_00748e20(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int iVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  int iVar5;

  int local_34;

  uint8_t local_2c [32];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b08c7;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  if ((*(uint *)(param_1 + 0xbc) >> 6 & 1) != 0) {

    ExceptionList = &local_c;

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPiece.cpp",0x520,2,

                   "Triangle level picking on pick tree *disabled* pieces is a very bad idea!! App developers, FIX THIS asap!"

                  );

  }

  if (param_4 == 0) {

    param_4 = param_1 + 0x10;

  }

  iVar5 = *(int *)(param_4 + 4);

  if (iVar5 == 0) {

    ExceptionList = local_c;

    return 0;

  }

  for (iVar4 = *(int *)(iVar5 + 0x28); iVar4 != *(int *)(iVar5 + 0x2c); iVar4 = iVar4 + 8) {

    if ((*(char *)(iVar4 + 6) == '\0') && (*(char *)(iVar4 + 7) == '\0')) goto LAB_00748eb5;

  }

  iVar4 = 0;

LAB_00748eb5:

  if ((*(int *)(iVar5 + 0x10) == 0) ||

     (iVar5 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar5 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar5 + 0x18),4),

     iVar5 == 0)) {

    FUN_00414a50();

    ExceptionList = local_c;

    return 0;

  }

  iVar1 = *(int *)(param_1 + 0xc);

  local_34 = 0;

  if (iVar1 != 0) {

    if (*(int *)(iVar1 + 0x10) == 0) {

      local_34 = 0;

    }

    else {

      local_34 = FUN_00743be0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x18),*(uint32_t /* width from decompiler */ *)(iVar1 + 0x1c),0x810);

    }

    if (local_34 == 0) {

      FUN_00414a50();

      FUN_0044ba80();

      ExceptionList = local_c;

      return 0;

    }

  }

  FUN_0044bd10(local_2c,(uint)*(ushort *)(iVar4 + 2) + iVar5,*(uint32_t /* width from decompiler */ *)(param_1 + 0xac));

  bVar2 = 0;

  local_4 = 0;

  if ((DAT_00d1a554 == '\0') || (*(int *)(param_1 + 0xb8) == 0)) {

    iVar5 = *(int *)(param_1 + 0xa8);

    iVar4 = 0;

    if (0 < iVar5) {

      do {

        bVar3 = FUN_00962ea0(param_3,iVar4);

        iVar4 = iVar4 + 1;

        bVar2 = bVar2 | bVar3;

      } while (iVar4 < iVar5);

    }

  }

  else {

    bVar2 = FUN_0044be40(local_2c);

  }

  FUN_00414a50();

  if (local_34 != 0) {

    FUN_0044ba80();

  }

  ExceptionList = local_c;

  return bVar2;

}
