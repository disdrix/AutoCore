// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, for×3.
//  - Notable callees: FUN_00414a50×2, vog_LogMessage×2, FUN_00414c20, FUN_00732c50, FUN_00746520, FUN_00972e50.
//  - Strings: ",

                   0x114,3,"; ",

                 0x11c,3,".
//  - Return sites: 4.

// =============================================================================
// Named_gfxGeometryPieceInstancing
// -----------------------------------------------------------------------------
// Stable ID: aa_00732c50
// Address:   0x00732c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "gfxGeometryPieceInstancing"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_gfxGeometryPieceInstancing(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int unaff_EDI;

  

  if ((*(int *)(unaff_EDI + 0x1c) != 0) || (*(int *)(unaff_EDI + 0x1c0) != 0)) {

    return -1;

  }

  *(uint *)(unaff_EDI + 0xbc) = *(uint *)(unaff_EDI + 0xbc) | 1;

  iVar4 = FUN_00414c20(param_1,unaff_EDI + 0x1c4,0x20,0);

  if (iVar4 < 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceInstancing.cpp",

                   0x114,3,"Unable to allocate vertex buffer for instanced data.\n");

    return iVar4;

  }

  iVar4 = *(int *)(unaff_EDI + 0x1c);

  if ((*(int *)(iVar4 + 0x10) != 0) &&

     (iVar4 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar4 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar4 + 0x18),1),

     iVar4 != 0)) {

    for (; param_1 != 0; param_1 = param_1 + -1) {

      puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(unaff_EDI + 0x1c0) * 0x30 + iVar4);

      puVar5 = param_2;

      if ((*(byte *)(param_2 + 0x2f) & 1) != 0) {

        puVar5 = (uint32_t /* width from decompiler */ *)FUN_00972e50();

      }

      uVar1 = puVar5[0xc];

      uVar2 = puVar5[8];

      uVar3 = puVar5[4];

      *puVar6 = *puVar5;

      puVar6[1] = uVar3;

      puVar6[2] = uVar2;

      puVar6[3] = uVar1;

      uVar1 = puVar5[0xd];

      uVar2 = puVar5[9];

      uVar3 = puVar5[5];

      puVar6[4] = puVar5[1];

      puVar6[5] = uVar3;

      puVar6[6] = uVar2;

      puVar6[7] = uVar1;

      uVar1 = puVar5[0xe];

      uVar2 = puVar5[10];

      uVar3 = puVar5[6];

      puVar6[8] = puVar5[2];

      puVar6[9] = uVar3;

      puVar6[10] = uVar2;

      puVar6[0xb] = uVar1;

      *(int *)(unaff_EDI + 0x1c0) = *(int *)(unaff_EDI + 0x1c0) + 1;

      param_2 = param_2 + 0x30;

    }

    FUN_00414a50();

    return 0;

  }

  FUN_00414a50();

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceInstancing.cpp",

                 0x11c,3,"Unable to lock previous vertex buffer for instanced data.\n");

  return -1;

}
