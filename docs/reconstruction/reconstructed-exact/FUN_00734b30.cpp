// =============================================================================
// FUN_00734b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00734b30
// Address:   0x00734b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00734b30 @ 0x00734b30
// Stable ID: aa_00734b30
// Embedded strings (evidence for future rename):
//   - "* * * * * *\n  Shader Profiles for this 3D Device:\n"
//   - "\t%s == %s\n"
//   - "  DX8 Level 3D hardware is available\n"
//   - "  DX7 or older 3D hardware is available, all shaders will be emulated\n"
//   - "V2x_SHADERS_AVAILABLE"
//   - "  DX9 Level 3D hardware is available\n\tV2x_SHADERS_AVAILABLE is defined\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~240 non-empty decompiler lines.
//  - Control keywords: if×19, do×9, while×9, for×5, goto×3, return×1.
//  - Notable callees: FUN_00446f30×7, FUN_0045f220×7, FUN_0076c130×7, FUN_00445620×2, FUN_00456960×2, _strdup×2, D3DXGetPixelShaderProfile, D3DXGetVertexShaderProfile.
//  - Strings: "* * * * * *\n  Shader Profiles for this 3D Device:\n"; "\t%s == %s\n"; "  DX8 Level 3D hardware is available\n"; "V2x_SHADERS_AVAILABLE".
//  - Return sites: 1.

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

void FUN_00734b30(int param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  char *pcVar5;

  char *pcVar6;

  char *pcVar7;

  char *pcVar8;

  uint uVar9;

  char *pcVar10;

  uint uVar11;

  uint uVar12;

  uint uVar13;

  int unaff_EBX;

  undefined **ppuVar14;

  uint local_5c;

  char *local_48;

  uint32_t /* width from decompiler */ local_44;

  char local_40 [64];

  

  ppuVar14 = &PTR_s_USE_MAX_VS_VERSION_00aa5640;

  do {

    FUN_00445620();

    ppuVar14 = ppuVar14 + 2;

  } while ((int)ppuVar14 < 0xaa5660);

  ppuVar14 = &PTR_s_COMPILE_VS_11_00aa5348;

  do {

    FUN_00445620();

    ppuVar14 = ppuVar14 + 2;

  } while ((int)ppuVar14 < 0xaa53e0);

  uVar2 = *DAT_00d1f044;

  pcVar5 = (char *)D3DXGetVertexShaderProfile(uVar2);

  pcVar6 = (char *)D3DXGetPixelShaderProfile(uVar2);

  uVar11 = (uint)*(byte *)((int)DAT_00d1f044 + 0x791);

  uVar13 = (uint)*(byte *)((int)DAT_00d1f044 + 0x799);

  FUN_0076c130("* * * * * *\n  Shader Profiles for this 3D Device:\n");

  local_5c = 0;

  do {

    if (local_5c == uVar11) {

      local_48 = (&PTR_s_COMPILE_VS_1x_00aa52f4)[local_5c * 2];

      pcVar7 = PTR_s_compile_00b02d28;

      do {

        cVar1 = *pcVar7;

        pcVar7[(int)(local_40 + -(int)PTR_s_compile_00b02d28)] = cVar1;

        pcVar7 = pcVar7 + 1;

        pcVar8 = pcVar5;

      } while (cVar1 != '\0');

      do {

        cVar1 = *pcVar8;

        pcVar8 = pcVar8 + 1;

      } while (cVar1 != '\0');

      uVar9 = (int)pcVar8 - (int)pcVar5;

      pcVar7 = (char *)((int)&local_44 + 3);

      do {

        pcVar8 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar8 != '\0');

      pcVar8 = pcVar5;

      for (uVar12 = uVar9 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar8;

        pcVar8 = pcVar8 + 4;

        pcVar7 = pcVar7 + 4;

      }

      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

        *pcVar7 = *pcVar8;

        pcVar8 = pcVar8 + 1;

        pcVar7 = pcVar7 + 1;

      }

      pcVar7 = _strdup(local_40);

      iVar3 = *(int *)(unaff_EBX + 4);

      local_44 = pcVar7;

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 3) <=

          (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 3))) {

        FUN_00446f30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&local_48);

      }

      else {

        iVar3 = *(int *)(unaff_EBX + 8);

        FUN_0045f220(pcVar6);

        *(int *)(unaff_EBX + 8) = iVar3 + 8;

      }

      iVar3 = *(int *)(param_1 + 4);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_1 + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(param_1 + 8) - iVar3 >> 2)

         )) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      }

      else {

        puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

        *puVar4 = pcVar7;

        *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar4 + 1;

      }

      FUN_0076c130("\t%s == %s\n",local_48,pcVar7);

    }

    else if (local_5c != 0) {

      iVar3 = *(int *)(unaff_EBX + 4);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 3) <=

          (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 3))) {

        FUN_00446f30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&PTR_s_COMPILE_VS_1x_00aa52f4 + local_5c * 2);

      }

      else {

        iVar3 = *(int *)(unaff_EBX + 8);

        FUN_0045f220(pcVar6);

        *(int *)(unaff_EBX + 8) = iVar3 + 8;

      }

    }

    if (local_5c == uVar13) {

      pcVar7 = (&PTR_s_COMPILE_PS_1x_00aa52a4)[local_5c * 2];

      pcVar8 = PTR_s_compile_00b02d28;

      do {

        cVar1 = *pcVar8;

        pcVar8[(int)(local_40 + -(int)PTR_s_compile_00b02d28)] = cVar1;

        pcVar8 = pcVar8 + 1;

        pcVar10 = pcVar6;

      } while (cVar1 != '\0');

      do {

        cVar1 = *pcVar10;

        pcVar10 = pcVar10 + 1;

      } while (cVar1 != '\0');

      uVar9 = (int)pcVar10 - (int)pcVar6;

      pcVar8 = (char *)((int)&local_44 + 3);

      do {

        pcVar10 = pcVar8 + 1;

        pcVar8 = pcVar8 + 1;

      } while (*pcVar10 != '\0');

      pcVar10 = pcVar6;

      for (uVar12 = uVar9 >> 2; uVar12 != 0; uVar12 = uVar12 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar10;

        pcVar10 = pcVar10 + 4;

        pcVar8 = pcVar8 + 4;

      }

      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {

        *pcVar8 = *pcVar10;

        pcVar10 = pcVar10 + 1;

        pcVar8 = pcVar8 + 1;

      }

      local_48 = pcVar7;

      pcVar8 = _strdup(local_40);

      iVar3 = *(int *)(unaff_EBX + 4);

      local_44 = pcVar8;

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 3) <=

          (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 3))) {

        FUN_00446f30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&local_48);

      }

      else {

        iVar3 = *(int *)(unaff_EBX + 8);

        FUN_0045f220(pcVar6);

        *(int *)(unaff_EBX + 8) = iVar3 + 8;

      }

      iVar3 = *(int *)(param_1 + 4);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_1 + 0xc) - iVar3 >> 2) <= (uint)(*(int *)(param_1 + 8) - iVar3 >> 2)

         )) {

        FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 8));

      }

      else {

        puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

        *puVar4 = pcVar8;

        *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar4 + 1;

      }

      FUN_0076c130("\t%s == %s\n",pcVar7,pcVar8);

    }

    else if (local_5c != 0) {

      iVar3 = *(int *)(unaff_EBX + 4);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 3) <=

          (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 3))) {

        FUN_00446f30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&PTR_s_COMPILE_PS_1x_00aa52a4 + local_5c * 2);

      }

      else {

        iVar3 = *(int *)(unaff_EBX + 8);

        FUN_0045f220(pcVar6);

        *(int *)(unaff_EBX + 8) = iVar3 + 8;

      }

    }

    local_5c = local_5c + 1;

  } while (local_5c < 4);

  if (uVar11 == 1) {

    if (uVar13 != 1) goto LAB_00734fb4;

    pcVar5 = "  DX8 Level 3D hardware is available\n";

  }

  else if (uVar11 == 0) {

    if (uVar13 != 0) goto LAB_00734fb4;

    pcVar5 = "  DX7 or older 3D hardware is available, all shaders will be emulated\n";

  }

  else {

    if ((uVar11 < 2) || (uVar13 < 2)) goto LAB_00734fb4;

    iVar3 = *(int *)(unaff_EBX + 4);

    local_48 = "V2x_SHADERS_AVAILABLE";

    local_44 = "1";

    if ((iVar3 == 0) ||

       ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 3) <=

        (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 3))) {

      FUN_00446f30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&local_48);

    }

    else {

      iVar3 = *(int *)(unaff_EBX + 8);

      FUN_0045f220(pcVar6);

      *(int *)(unaff_EBX + 8) = iVar3 + 8;

    }

    pcVar5 = "  DX9 Level 3D hardware is available\n\tV2x_SHADERS_AVAILABLE is defined\n";

  }

  FUN_0076c130(pcVar5);

LAB_00734fb4:

  iVar3 = *(int *)(unaff_EBX + 4);

  local_48 = "D3DX_VERSION_22";

  local_44 = &DAT_00a326c8;

  if ((iVar3 == 0) ||

     ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 3) <= (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 3)

     )) {

    FUN_00446f30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&local_48);

  }

  else {

    iVar3 = *(int *)(unaff_EBX + 8);

    FUN_0045f220(pcVar6);

    *(int *)(unaff_EBX + 8) = iVar3 + 8;

  }

  FUN_0076c130("  Using Direct X 9.0c\n");

  if ((2 < uVar11) && (2 < uVar13)) {

    iVar3 = *(int *)(unaff_EBX + 4);

    local_48 = "3x_SHADERS_AVAILABLE";

    local_44 = &DAT_00a326c8;

    if ((iVar3 == 0) ||

       ((uint)(*(int *)(unaff_EBX + 0xc) - iVar3 >> 3) <=

        (uint)(*(int *)(unaff_EBX + 8) - iVar3 >> 3))) {

      FUN_00446f30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 8),&local_48);

    }

    else {

      iVar3 = *(int *)(unaff_EBX + 8);

      FUN_0045f220(pcVar6);

      *(int *)(unaff_EBX + 8) = iVar3 + 8;

    }

    FUN_0076c130("  DX9c Level 3D hardware is available\n\t3x_SHADERS_AVAILABLE is defined\n");

  }

  FUN_0076c130("* * * * * *\n");

  return;

}
