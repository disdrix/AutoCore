// =============================================================================
// FUN_006e9220
// -----------------------------------------------------------------------------
// Stable ID: aa_006e9220
// Address:   0x006e9220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e9220 @ 0x006e9220
// Stable ID: aa_006e9220
// Embedded strings (evidence for future rename):
//   - "TtShapeCollection"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×3, for×1, return×1.
//  - Notable callees: rdtsc×2, FUN_006e9220.
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

void FUN_006e9220(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  int *piVar1;

  uint64_t uVar2;

  int iVar3;

  char *pcVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ local_128;

  uint8_t auStack_121 [9];

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ *local_114;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "TtShapeCollection";

    uVar2 = rdtsc();

    local_128 = (uint32_t /* width from decompiler */)uVar2;

    DAT_00bc5644[1] = local_128;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_118 = param_1[2];

  piVar1 = (int *)*param_1;

  local_114 = param_1;

  local_128 = (**(code **)(*(int *)*param_2 + 0x14))();

  for (iVar3 = (**(code **)(*piVar1 + 0x2c))(); iVar3 != -1;

      iVar3 = (**(code **)(*piVar1 + 0x30))(iVar3)) {

    piVar7 = piVar1;

    pcVar4 = (char *)(*(code *)**(uint32_t /* width from decompiler */ **)param_3[1])

                               (auStack_121,param_3,param_2,param_1,piVar1,iVar3);

    if (*pcVar4 != '\0') {

      piVar5 = (int *)(**(code **)(*piVar1 + 0x34))(iVar3,&local_128);

      iVar6 = (**(code **)(*piVar5 + 0x14))();

      (**(code **)(*param_3 + 0x318c + (int)(piVar7 + iVar6 * 8) * 4))

                (&stack0xfffffec0,param_2,param_3,param_4,param_5);

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
