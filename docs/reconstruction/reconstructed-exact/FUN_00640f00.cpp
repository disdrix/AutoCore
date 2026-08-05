// =============================================================================
// FUN_00640f00
// -----------------------------------------------------------------------------
// Stable ID: aa_00640f00
// Address:   0x00640f00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00640f00 @ 0x00640f00
// Stable ID: aa_00640f00
// Embedded strings (evidence for future rename):
//   - "VisualDebugger: ["
//   - "] viewer for the new client connection"
//   - "Auto selecting the ["
//   - "ERROR: "
//   - "] for the new client connection as it is not in the viewer list"
//   - "Cannot auto select viewer ["
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×4, for×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00631dc0×9, FUN_00631da0×2, FUN_00631f80×2, FUN_00637f70, FUN_0063f630, FUN_00640f00.
//  - Strings: "VisualDebugger: ["; "] viewer for the new client connection"; "Auto selecting the ["; "ERROR: ".
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

uint32_t /* width from decompiler */ __thiscall FUN_00640f00(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  char *pcVar6;

  char *pcVar7;

  uint32_t /* width from decompiler */ uVar8;

  

  piVar1 = (int *)FUN_0063f630();

  iVar4 = 0;

  if (0 < piVar1[1]) {

    iVar3 = 0;

    do {

      iVar2 = FUN_00637f70(*(uint32_t /* width from decompiler */ *)(iVar3 + *piVar1),param_2);

      if (iVar2 == 0) {

        (**(code **)(*param_1 + 8))(iVar4);

        if (0 < DAT_00d030ec) {

          pcVar7 = "VisualDebugger: [";

          (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

          FUN_00631dc0(pcVar7);

          uVar5 = 0x5d;

          pcVar6 = "] viewer for the new client connection";

          pcVar7 = "Auto selecting the [";

          uVar8 = param_2;

          (**(code **)(*DAT_00d030e0 + 4))

                    ("Auto selecting the [",param_2,"] viewer for the new client connection",0x5d);

          FUN_00631dc0(pcVar7);

          FUN_00631dc0(uVar8);

          FUN_00631dc0(pcVar6);

          uVar8 = FUN_00631da0(uVar5);

          FUN_00631f80(uVar8);

        }

        break;

      }

      iVar4 = iVar4 + 1;

      iVar3 = iVar3 + 0xc;

    } while (iVar4 < piVar1[1]);

  }

  if ((iVar4 == piVar1[1]) && (-1 < DAT_00d030ec)) {

    pcVar7 = "VisualDebugger: [";

    (**(code **)(*DAT_00d030e0 + 4))("VisualDebugger: [");

    FUN_00631dc0(pcVar7);

    pcVar7 = "ERROR: ";

    (**(code **)(*DAT_00d030e0 + 4))("ERROR: ");

    FUN_00631dc0(pcVar7);

    uVar8 = 0x5d;

    pcVar6 = "] for the new client connection as it is not in the viewer list";

    pcVar7 = "Cannot auto select viewer [";

    (**(code **)(*DAT_00d030e0 + 4))

              ("Cannot auto select viewer [",param_2,

               "] for the new client connection as it is not in the viewer list",0x5d);

    FUN_00631dc0(pcVar7);

    FUN_00631dc0(param_2);

    FUN_00631dc0(pcVar6);

    uVar8 = FUN_00631da0(uVar8);

    FUN_00631f80(uVar8);

  }

  return 0;

}
