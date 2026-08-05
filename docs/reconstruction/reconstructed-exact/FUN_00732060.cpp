// =============================================================================
// FUN_00732060
// -----------------------------------------------------------------------------
// Stable ID: aa_00732060
// Address:   0x00732060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00732060 @ 0x00732060
// Stable ID: aa_00732060
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"
//   - "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo..."
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceInstancing.cpp"
//   - "Unable to lock vertex buffer for instanced piece.\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, do×1, while×1, for×1.
//  - Notable callees: vog_LogMessage×2, FUN_00732060, FUN_00746520, FUN_00972e50.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp"; ",

                 0xd7,3,".
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

uint32_t /* width from decompiler */ FUN_00732060(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int *piVar6;

  int in_EAX;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar9;

  

  if (DAT_00afa360 != 1) {

    return 0xffffffff;

  }

  iVar7 = *(int *)(unaff_EBX + 0x1c);

  if ((*(int *)(iVar7 + 0x10) != 0) &&

     (iVar7 = FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar7 + 0x14),*(uint32_t /* width from decompiler */ *)(iVar7 + 0x18),1),

     iVar7 != 0)) {

    if (param_1 != 0) {

      puVar9 = (uint32_t /* width from decompiler */ *)(in_EAX * 0x30 + 0x18 + iVar7);

      do {

        puVar8 = param_2;

        if ((*(byte *)(param_2 + 0x2f) & 1) != 0) {

          puVar8 = (uint32_t /* width from decompiler */ *)FUN_00972e50();

        }

        uVar2 = puVar8[0xc];

        uVar3 = puVar8[8];

        uVar4 = puVar8[4];

        puVar9[-6] = *puVar8;

        puVar9[-5] = uVar4;

        puVar9[-4] = uVar3;

        puVar9[-3] = uVar2;

        uVar2 = puVar8[0xd];

        uVar3 = puVar8[9];

        uVar4 = puVar8[5];

        puVar9[-2] = puVar8[1];

        puVar9[-1] = uVar4;

        *puVar9 = uVar3;

        puVar9[1] = uVar2;

        uVar2 = puVar8[0xe];

        uVar3 = puVar8[10];

        uVar4 = puVar8[6];

        puVar9[2] = puVar8[2];

        puVar9[3] = uVar4;

        puVar9[4] = uVar3;

        puVar9[5] = uVar2;

        puVar9 = puVar9 + 0xc;

        param_2 = param_2 + 0x30;

        param_1 = param_1 + -1;

      } while (param_1 != 0);

    }

    *(uint *)(unaff_EBX + 0xbc) = *(uint *)(unaff_EBX + 0xbc) | 1;

    piVar5 = *(int **)(*(int *)(unaff_EBX + 0x1c) + 0x10);

    if ((piVar5 != (int *)0x0) && (piVar6 = (int *)*piVar5, piVar6 != (int *)0x0)) {

      piVar1 = piVar5 + 4;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 < 0) {

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxDeviceVB.cpp",0xd3,1,

                       "Call to gfxDeviceVB::Unlock more times than locked! Bad mojo...");

        piVar5[4] = 0;

        return 0;

      }

      (**(code **)(*piVar6 + 0x30))(piVar6);

    }

    return 0;

  }

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxGeometryPieceInstancing.cpp",

                 0xd7,3,"Unable to lock vertex buffer for instanced piece.\n");

  return 0xffffffff;

}
