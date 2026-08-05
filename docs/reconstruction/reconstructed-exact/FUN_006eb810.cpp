// =============================================================================
// FUN_006eb810
// -----------------------------------------------------------------------------
// Stable ID: aa_006eb810
// Address:   0x006eb810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006eb810 @ 0x006eb810
// Stable ID: aa_006eb810
// Embedded strings (evidence for future rename):
//   - "LtBvTree"
//   - "StNarrowPhase"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, while×1, return×1.
//  - Notable callees: rdtsc×3, FUN_006ea1b0, FUN_006eb810.
//  - Strings: "LtBvTree"; "StNarrowPhase".
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

void FUN_006eb810(uint32_t /* width from decompiler */ *param_1,int *param_2,int *param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  uint64_t uVar2;

  char *pcVar3;

  int iVar4;

  int unaff_ESI;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ uStack_360;

  uint32_t /* width from decompiler */ *local_35c;

  int iStack_350;

  int *piStack_34c;

  uint8_t local_340 [24];

  uint32_t /* width from decompiler */ *puStack_328;

  int iStack_324;

  uint8_t *local_320;

  uint32_t /* width from decompiler */ local_31c;

  uint32_t /* width from decompiler */ local_318;

  uint8_t local_314 [508];

  uint8_t auStack_118 [276];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LtBvTree";

    uVar2 = rdtsc();

    local_35c = (uint32_t /* width from decompiler */ *)uVar2;

    DAT_00bc5644[1] = local_35c;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  FUN_006ea1b0(param_1,param_2,param_3,local_340);

  piVar1 = (int *)*param_2;

  local_320 = local_314;

  local_31c = 0;

  local_318 = 0x80000080;

  (**(code **)(*piVar1 + 0x30))(local_340,&local_320);

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "StNarrowPhase";

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  (**(code **)(*(int *)*param_1 + 0x14))();

  piVar1 = (int *)piVar1[3];

  local_35c = puStack_328 + iStack_324;

  piStack_34c = param_2;

  iStack_350 = param_2[2];

  puVar5 = puStack_328;

  if (puStack_328 != local_35c) {

    do {

      pcVar3 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)param_3[1])

                                 ((int)&uStack_360 + 3,param_3,param_1,param_2,piVar1,*puVar5);

      if (*pcVar3 != '\0') {

        uStack_360 = (int *)(**(code **)(*piVar1 + 0x34))(*puVar5,auStack_118);

        local_35c = (uint32_t /* width from decompiler */ *)*puVar5;

        iVar4 = (**(code **)(*uStack_360 + 0x14))();

        (**(code **)(*param_3 + 0x318c + (unaff_ESI * 0x20 + iVar4) * 4))

                  (param_1,&uStack_360,param_3,param_4,param_5);

      }

      puVar5 = puVar5 + 1;

    } while (puVar5 != local_35c);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar2 = rdtsc();

    local_35c = (uint32_t /* width from decompiler */ *)uVar2;

    DAT_00bc5644[1] = local_35c;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  if (-1 < (int)local_320) {

    (**(code **)(*DAT_00b05060 + 0x14))(puStack_328,(int)local_320 << 2,0x12);

  }

  return;

}
