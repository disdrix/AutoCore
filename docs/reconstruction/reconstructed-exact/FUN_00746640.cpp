// =============================================================================
// FUN_00746640
// -----------------------------------------------------------------------------
// Stable ID: aa_00746640
// Address:   0x00746640  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00746640 @ 0x00746640
// Stable ID: aa_00746640
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"
//   - "

// READABILITY (auto CF):
//  - Body size: ~78 non-empty decompiler lines.
//  - Control keywords: if×16, return×2.
//  - Notable callees: vog_LogMessage×2, D3DXGetFVFVertexSize, FUN_00746640.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp".
//  - Return sites: 2.

                    );

    }

    if ((uVar3 & 0x200) == 0) {

      vog_LogMessage("
//   - ",0x5d,1,

                     "
// Readability: control flow preserved from Ghidra decompile; types tentative.

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

uint32_t /* width from decompiler */ FUN_00746640(int param_1,int param_2,int param_3,uint param_4,int param_5)



{

  int *piVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  uint32_t /* width from decompiler */ unaff_ESI;

  uint32_t /* width from decompiler */ unaff_EDI;

  bool bVar5;

  uint32_t /* width from decompiler */ uVar6;

  

  iVar4 = 0;

  if ((param_4 & 8) == 0) {

    if ((param_4 & 0x20) != 0) {

      iVar4 = 1;

    }

  }

  else {

    iVar4 = 2;

  }

  uVar3 = 0;

  if ((param_4 & 1) != 0) {

    uVar3 = 0x200;

  }

  if ((param_4 & 2) != 0) {

    uVar3 = uVar3 | 8;

  }

  if ((param_4 & 4) != 0) {

    uVar3 = uVar3 | 0x20;

  }

  if (((param_4 & 0x10) != 0) || (DAT_00d1f044[0x1df] == 2)) {

    uVar3 = uVar3 | 0x10;

  }

  if ((param_4 & 0x40) != 0) {

    uVar3 = uVar3 | 0x40;

  }

  if ((char)param_4 < '\0') {

    uVar3 = uVar3 | 0x80;

  }

  if ((param_4 & 0x100) != 0) {

    uVar3 = uVar3 | 0x100;

  }

  if (param_5 != 0) {

    iVar2 = D3DXGetFVFVertexSize(param_5);

    if (iVar2 != param_3) {

      param_3 = iVar2;

    }

  }

  piVar1 = (int *)*DAT_00d1f044;

  if (iVar4 == 0) {

    if ((uVar3 & 8) == 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0x57,2,

                     "Vertex Buffer Buffer created with D3DPOOL_DEFAULT that did not specify D3DUSAGE_WRITEONLY might suffer a severe performance penalty!"

                    );

    }

    if ((uVar3 & 0x200) == 0) {

      vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0x5d,1,

                     "POOL_DEFAULT Vertex Buffer created, evicting managed resources prior to allocation!"

                    );

      (**(code **)(*piVar1 + 0x14))(piVar1);

    }

  }

  uVar6 = 0;

  iVar4 = (**(code **)(*piVar1 + 0x68))(piVar1,param_2 * param_3,uVar3,param_5,iVar4);

  if (iVar4 < 0) {

    return 0xffffffff;

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 8) = unaff_EDI;

  iVar4 = DAT_00d1f614;

  bVar5 = DAT_00d1f614 != 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = unaff_ESI;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = uVar6;

  if (bVar5) {

    *(int *)(iVar4 + 900) = *(int *)(iVar4 + 900) + param_2 * param_3;

    *(int *)(iVar4 + 0x330) = *(int *)(iVar4 + 0x330) + *(int *)(param_1 + 0xc);

    *(int *)(iVar4 + 0x32c) = *(int *)(iVar4 + 0x32c) + 1;

  }

  return 0;

}
