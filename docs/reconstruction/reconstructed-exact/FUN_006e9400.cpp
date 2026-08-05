// =============================================================================
// FUN_006e9400
// -----------------------------------------------------------------------------
// Stable ID: aa_006e9400
// Address:   0x006e9400  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e9400 @ 0x006e9400
// Stable ID: aa_006e9400
// Embedded strings (evidence for future rename):
//   - "TtShapeCollection"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, for×1, return×1.
//  - Notable callees: rdtsc×2, FUN_006e9400.
//  - Strings: "TtShapeCollection".
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

void FUN_006e9400(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,int param_4)



{

  int *piVar1;

  uint64_t uVar2;

  int iVar3;

  char *pcVar4;

  int iVar5;

  int iStack_130;

  int *local_128;

  uint32_t /* width from decompiler */ uStack_124;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ *local_114;

  uint8_t auStack_110 [268];

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtShapeCollection";

    uVar2 = rdtsc();

    local_128 = (int *)uVar2;

    DAT_00bc5644[1] = local_128;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_118 = param_1[2];

  piVar1 = (int *)*param_1;

  local_114 = param_1;

  local_128 = (int *)(**(code **)(*(int *)*param_2 + 0x14))();

  for (iVar3 = (**(code **)(*piVar1 + 0x2c))(); iVar3 != -1;

      iVar3 = (**(code **)(*piVar1 + 0x30))(iVar3)) {

    pcVar4 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)param_3[1])

                               ((int)&uStack_124 + 3,param_3,param_2,param_1,piVar1,iVar3);

    if (*pcVar4 != '\0') {

      local_128 = (int *)(**(code **)(*piVar1 + 0x34))(iVar3,auStack_110);

      uStack_124 = iVar3;

      iVar5 = (**(code **)(*local_128 + 0x14))();

      (**(code **)(*param_3 + 0x118c + (iVar5 * 0x20 + iStack_130) * 4))

                (&local_128,param_2,param_3,param_4);

      if (*(char *)(param_4 + 4) != '\0') break;

    }

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d2878;

    uVar2 = rdtsc();

    DAT_00bc5644[1] = (int)uVar2;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
