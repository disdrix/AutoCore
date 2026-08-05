// =============================================================================
// FUN_009679d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009679d0
// Address:   0x009679d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_009679d0 @ 0x009679d0
// Stable ID: aa_009679d0
// Embedded strings (evidence for future rename):
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightTriage.cpp"
//   - "Hardware reports 0 light capability"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×2, while×2, goto×1.
//  - Notable callees: FUN_0073e480×2, FUN_009679d0, vog_LogMessage.
//  - Strings: "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightTriage.cpp"; "Hardware reports 0 light capability".
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

uint32_t /* width from decompiler */ FUN_009679d0(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int local_10;

  int local_c;

  uint32_t /* width from decompiler */ local_8;

  

  iVar3 = param_1;

  if (((*(byte *)(param_2 + 0x20) & 1) == 0) && (*(int *)(param_1 + 0x48) == 0)) {

    FUN_0073e480();

    return 0;

  }

  if (*(int *)(DAT_00d1f044 + 0xb4) == 0) {

    vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxLightTriage.cpp",0x177,5,

                   "Hardware reports 0 light capability");

    return 0;

  }

  local_8 = 1;

  if ((*(int *)(param_1 + 0x48) != 0) && (local_c = 0, 0 < *DAT_00d1f62c)) {

    local_10 = 0;

    piVar5 = (int *)(param_1 + 0x38);

    param_1 = *(int *)(DAT_00d1f044 + 0xb4);

    do {

      iVar2 = *(int *)(iVar3 + 8);

      iVar6 = piVar5[-4];

      if (0 < iVar6) {

        iVar4 = *piVar5 * 4;

        do {

          if (param_1 == 0) {

            if ((*(byte *)(param_2 + 0x21) & 0x20) != 0) {

              local_8 = 3;

            }

            goto LAB_00967af4;

          }

          (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(*(int *)(iVar2 + local_10 + 8) + iVar4) + 0x38))();

          if ((*(byte *)(param_2 + 0x21) & 0x40) == 0) {

            *piVar5 = *piVar5 + 1;

            piVar5[-4] = piVar5[-4] + -1;

            piVar1 = (int *)(iVar3 + 0x48);

            *piVar1 = *piVar1 + -1;

          }

          param_1 = param_1 + -1;

          iVar6 = iVar6 + -1;

          iVar4 = iVar4 + 4;

        } while (0 < iVar6);

      }

      local_10 = local_10 + 0x10;

      local_c = local_c + 1;

      piVar5 = piVar5 + 1;

    } while (local_c < *DAT_00d1f62c);

  }

LAB_00967af4:

  FUN_0073e480();

  return local_8;

}
