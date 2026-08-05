// =============================================================================
// FUN_007199e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007199e0
// Address:   0x007199e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007199e0 @ 0x007199e0
// Stable ID: aa_007199e0
// Embedded strings (evidence for future rename):
//   - "Removing empty chunk entirely"
//   - "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoPackOSFile.cpp"
//   - "Reducing chunk from %d to %d at %d"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~79 non-empty decompiler lines.
//  - Control keywords: if×6, for×3, return×3.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, FUN_004812f0, FUN_007199e0, FUN_00989e00.
//  - Strings: "Removing empty chunk entirely"; "C:\\vog\\1_code\\palantir\\arda2\\storage\\stoPackOSFile.cpp"; "Reducing chunk from %d to %d at %d".
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



uint32_t /* width from decompiler */ FUN_007199e0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,int param_3,int *param_4)



{

  uint uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int *piVar3;

  int iVar4;

  int *unaff_EBX;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int *local_1010;

  uint local_100c [1024];

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0x7199f0;

  piVar6 = (int *)unaff_EBX[0xe];

  local_100c[0] = param_3 + 0xfffU & 0xfffff000;

  local_1010 = piVar6;

  for (piVar3 = (int *)unaff_EBX[0xd]; piVar3 != piVar6; piVar3 = piVar3 + 7) {

    uVar1 = piVar3[1] + 0xfffU & 0xfffff000;

    if (((int)local_100c[0] <= (int)uVar1) &&

       ((local_1010 == piVar6 || ((int)uVar1 < (int)(local_1010[1] + 0xfffU & 0xfffff000))))) {

      local_1010 = piVar3;

    }

  }

  if (local_1010 == piVar6) {

    *param_4 = unaff_EBX[0xb];

    param_4[6] = (int)unaff_EBX;

    unaff_EBX[0xb] = unaff_EBX[0xb] + local_100c[0];

  }

  else {

    piVar3 = local_1010;

    piVar6 = param_4;

    for (iVar4 = 7; iVar4 != 0; iVar4 = iVar4 + -1) {

      *piVar6 = *piVar3;

      piVar3 = piVar3 + 1;

      piVar6 = piVar6 + 1;

    }

    iVar4 = local_1010[1];

    iVar5 = (iVar4 + 0xfffU & 0xfffff000) - local_100c[0];

    if (iVar5 == 0) {

      uVar2 = FUN_0076cec0(local_100c,"Removing empty chunk entirely");

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoPackOSFile.cpp",0x1c0,1,uVar2);

      FUN_004812f0(&local_1010,local_1010);

    }

    else {

      uVar2 = FUN_0076cec0(local_100c,"Reducing chunk from %d to %d at %d",iVar4,iVar4 - iVar5,

                           *local_1010 + local_100c[0]);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\storage\\stoPackOSFile.cpp",0x1c6,1,uVar2);

      *local_1010 = *local_1010 + local_100c[0];

      local_1010[1] = iVar5;

    }

  }

  param_4[1] = param_3;

  piVar3 = (int *)FUN_00989e00(&local_1010,param_1);

  param_4[4] = *piVar3;

  iVar8 = 0;

  (**(code **)(*unaff_EBX + 4))(*param_4);

  iVar4 = param_3;

  (**(code **)(*unaff_EBX + 0x18))(param_2);

  iVar5 = (**(code **)(*unaff_EBX + 0x30))();

  if (iVar5 != *param_4 + param_4[1]) {

    return 0xffffffff;

  }

  if (0 < iVar8 - param_3) {

    puVar7 = (uint32_t /* width from decompiler */ *)&stack0xffffefe8;

    for (iVar5 = 0x400; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

    }

    (**(code **)(*unaff_EBX + 0x18))(&stack0xffffefe8,iVar8 - param_3);

    iVar5 = (**(code **)(*unaff_EBX + 0x30))();

    if (iVar5 != *param_4 + iVar4) {

      return 0xffffffff;

    }

  }

  return 0;

}
