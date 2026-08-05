// =============================================================================
// Gfx_NDSkyBoxBlend
// -----------------------------------------------------------------------------
// Stable ID: aa_00490c60
// Address:   0x00490c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_NDSkyBoxBlend @ 0x00490c60
// Stable ID: aa_00490c60
// Embedded strings (evidence for future rename):
//   - "SkyBox"
//   - "SkyBoxCloud"
//   - "SkyBoxForeground"
//   - "NDSkyBoxBlend.fx"
//   - "DiffuseTexture"
//   - "DiffuseTextureBlending"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~103 non-empty decompiler lines.
//  - Control keywords: if×14, goto×2, while×1, return×1.
//  - Notable callees: FUN_00970140×6, FUN_00746270×3, FUN_009701d0×3, FUN_00989e00×3, Gfx_NDSkyBoxBlend.
//  - Strings: "SkyBox"; "SkyBoxCloud"; "SkyBoxForeground"; "NDSkyBoxBlend.fx".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "NDSkyBoxBlend.fx"
 * Domain alias of FUN_00490c60 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Gfx_NDSkyBoxBlend(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  short local_24;

  short local_22;

  int local_20;

  short local_1c;

  short local_1a;

  int local_18;

  int local_14;

  short local_10;

  short local_e;

  uint8_t local_c [4];

  uint8_t local_8 [4];

  uint8_t local_4 [4];

  

  if (*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) != 0) {

    FUN_00746270(&local_24,"SkyBox");

    FUN_00746270(&local_1c,"SkyBoxCloud");

    FUN_00746270(&local_10,"SkyBoxForeground");

    if ((*(short *)(param_1 + 0x98) < 1) &&

       (iVar3 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar3 != 0)) {

      local_18 = **(int **)(iVar3 + 1000);

    }

    else {

      local_18 = *(int *)(param_1 + 0x9c);

    }

    if ((*(short *)(param_1 + 0xa0) < 1) &&

       (iVar3 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar3 != 0)) {

      local_14 = **(int **)(iVar3 + 0x3f4);

    }

    else {

      local_14 = *(int *)(param_1 + 0xa4);

    }

    if ((*(short *)(param_1 + 0xa8) < 1) &&

       (iVar3 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar3 != 0)) {

      local_20 = **(int **)(iVar3 + 0x3e4);

    }

    else {

      local_20 = *(int *)(param_1 + 0xac);

    }

    if ((*(short *)(param_1 + 0xb0) < 1) &&

       (iVar3 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar3 != 0)) {

      iVar3 = **(int **)(iVar3 + 0x3f0);

    }

    else {

      iVar3 = *(int *)(param_1 + 0xb4);

    }

    iVar4 = 0;

    while( true ) {

      iVar1 = *(int *)(param_1 + 0x94);

      if (*(int *)(iVar1 + 0xc0) == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(iVar1 + 0xc4) - *(int *)(iVar1 + 0xc0) >> 2;

      }

      if (iVar2 <= iVar4) break;

      iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0xc0) + iVar4 * 4) + 0x20);

      if ((*(short *)(iVar1 + 0x1c) == local_24) && (*(short *)(iVar1 + 0x1e) == local_22)) {

        FUN_00989e00(local_c,"NDSkyBoxBlend.fx");

        FUN_009701d0(local_c);

        if (local_20 != 0) {

          FUN_00970140("DiffuseTexture",local_20);

        }

        if (iVar3 == 0) {

LAB_00490f22:

          iVar4 = iVar4 + 1;

        }

        else {

          FUN_00970140("DiffuseTextureBlending",iVar3);

          iVar4 = iVar4 + 1;

        }

      }

      else {

        if ((*(short *)(iVar1 + 0x1c) != local_1c) || (*(short *)(iVar1 + 0x1e) != local_1a)) {

          if ((((*(short *)(iVar1 + 0x1c) == local_10) && (*(short *)(iVar1 + 0x1e) == local_e)) &&

              (iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar1 != 0)) &&

             (*(int *)(iVar1 + 0x3ec) != 0)) {

            FUN_00989e00(local_4,"NDSkyBoxForegroundBlend.fx");

            FUN_009701d0(local_4);

            FUN_00970140("DiffuseTexture",

                         **(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3ec));

            FUN_00970140("DiffuseTextureBlending",

                         **(uint32_t /* width from decompiler */ **)(*(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8) + 0x3f8));

          }

          goto LAB_00490f22;

        }

        FUN_00989e00(local_8,"NDSkyBoxCloudBlend.fx");

        FUN_009701d0(local_8);

        if (local_18 != 0) {

          FUN_00970140("DiffuseTexture",local_18);

        }

        if (local_14 == 0) goto LAB_00490f22;

        FUN_00970140("DiffuseTextureBlending",local_14);

        iVar4 = iVar4 + 1;

      }

    }

  }

  return;

}
