// =============================================================================
// FUN_00490700
// -----------------------------------------------------------------------------
// Stable ID: aa_00490700
// Address:   0x00490700  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00490700 @ 0x00490700
// Stable ID: aa_00490700
// Embedded strings (evidence for future rename):
//   - "SkyBox"
//   - "SkyBoxCloud"
//   - "SkyBoxForeground"
//   - "MatColorPrimary"
//   - "MatColorSecondary"
//   - "fCloudAlpha"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×5, while×1, return×1.
//  - Notable callees: FUN_00746270×3, FUN_009700f0×2, FUN_00442640, FUN_00490700.
//  - Strings: "SkyBox"; "SkyBoxCloud"; "SkyBoxForeground"; "MatColorPrimary".
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

void __thiscall FUN_00490700(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  int iVar5;

  short local_10;

  short local_e;

  short local_c;

  short local_a;

  int local_8;

  uint8_t local_4 [4];

  

  local_8 = param_1;

  FUN_00746270(&local_10,"SkyBox");

  FUN_00746270(&local_c,"SkyBoxCloud");

  FUN_00746270(local_4,"SkyBoxForeground");

  uVar3 = param_4;

  uVar2 = param_3;

  if (*(int *)(param_1 + 0x94) != 0) {

    iVar5 = 0;

    while( true ) {

      iVar1 = *(int *)(param_1 + 0x94);

      if (*(int *)(iVar1 + 0xc0) == 0) {

        iVar4 = 0;

      }

      else {

        iVar4 = *(int *)(iVar1 + 0xc4) - *(int *)(iVar1 + 0xc0) >> 2;

      }

      if (iVar4 <= iVar5) break;

      iVar1 = *(int *)(*(int *)(*(int *)(iVar1 + 0xc0) + iVar5 * 4) + 0x20);

      if ((*(short *)(iVar1 + 0x1c) == local_10) && (*(short *)(iVar1 + 0x1e) == local_e)) {

        FUN_009700f0("MatColorPrimary",uVar2);

        FUN_009700f0("MatColorSecondary",uVar3);

        iVar5 = iVar5 + 1;

        param_1 = local_8;

      }

      else {

        if ((*(short *)(iVar1 + 0x1c) == local_c) && (*(short *)(iVar1 + 0x1e) == local_a)) {

          FUN_00442640("fCloudAlpha",&param_2);

        }

        iVar5 = iVar5 + 1;

        param_1 = local_8;

      }

    }

  }

  return;

}
