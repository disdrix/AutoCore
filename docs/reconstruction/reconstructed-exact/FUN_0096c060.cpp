// =============================================================================
// FUN_0096c060
// -----------------------------------------------------------------------------
// Stable ID: aa_0096c060
// Address:   0x0096c060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096c060 @ 0x0096c060
// Stable ID: aa_0096c060
// Embedded strings (evidence for future rename):
//   - "Error loading texture"
//   - "%s - %s\r\n%s"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_006a5dac, FUN_006b7a5a, FUN_0076cec0, FUN_0096c060, vog_LogMessage.
//  - Strings: "Error loading texture"; "%s - %s\r\n%s".
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

uint32_t /* width from decompiler */ __thiscall

FUN_0096c060(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint uVar3;

  uint uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint uVar6;

  int unaff_ESI;

  int iVar7;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint32_t /* width from decompiler */ local_30;

  uint32_t /* width from decompiler */ local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  iVar2 = *(int *)(unaff_ESI + 0x24);

  local_3c = 0;

  local_38 = 0;

  local_34 = 0;

  local_30 = 0;

  local_2c = 0;

  local_28 = 0;

  local_24 = 0;

  iVar7 = -0x7789f4a7;

  uVar4 = (iVar2 != 0x31545844) - 1 & 0xff000000;

  uVar3 = *(uint *)(unaff_ESI + 0x2c);

  uVar6 = uVar3 & 0xf;

  if (uVar6 == 1) {

    puVar1 = (uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

    iVar7 = D3DXCreateTextureFromFileInMemoryEx

                      (*DAT_00d1f044,param_2,param_3,*param_1,param_1[1],param_4,0,iVar2,

                       *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30),0xffffffff,0xffffffff,uVar4,&local_3c,0,

                       puVar1);

    if (-1 < iVar7) {

      uVar5 = (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x48) = uVar5;

      (**(code **)(*(int *)*puVar1 + 0x44))((int *)*puVar1,0,&local_24);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = local_30;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = uStack_14;

      return 0;

    }

  }

  else if (uVar6 == 2) {

    puVar1 = (uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

    iVar7 = D3DXCreateCubeTextureFromFileInMemoryEx

                      (*DAT_00d1f044,param_2,param_3,*param_1,

                       (-(uint)((uVar3 & 0x100) != 0) & 0xfffffffc) + 1,0,iVar2,

                       *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30),0xffffffff,0xffffffff,uVar4,&local_3c,0,

                       puVar1);

    if (-1 < iVar7) {

      uVar5 = (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x48) = uVar5;

      (**(code **)(*(int *)*puVar1 + 0x44))((int *)*puVar1,0,&local_24);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = uStack_14;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = local_30;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = uStack_18;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34) = 6;

      return 0;

    }

  }

  else if (uVar6 == 4) {

    puVar1 = (uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10);

    iVar7 = D3DXCreateVolumeTextureFromFileInMemoryEx

                      (*DAT_00d1f044,param_2,param_3,*param_1,param_1[1],0,

                       (-(uint)((uVar3 & 0x100) != 0) & 0xfffffffc) + 1,0,iVar2,

                       *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30),0xffffffff,0xffffffff,uVar4,&local_3c,0,

                       puVar1);

    if (-1 < iVar7) {

      uVar5 = (**(code **)(*(int *)*puVar1 + 0x34))((int *)*puVar1);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x48) = uVar5;

      (**(code **)(*(int *)*puVar1 + 0x44))((int *)*puVar1,0,&local_24);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x24) = local_30;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x20) = uStack_1c;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1c) = uStack_20;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x34) = uStack_18;

      return 0;

    }

  }

  uVar5 = FUN_006b7a5a(iVar7,"Error loading texture");

  uVar5 = FUN_006a5dac(iVar7,uVar5);

  uVar5 = FUN_0076cec0(&stack0x00000000,"%s - %s\r\n%s",uVar5);

  vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTextureImpl.cpp",0x205,

                 3,uVar5);

  return 0xffffffff;

}
