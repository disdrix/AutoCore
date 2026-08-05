// =============================================================================
// FUN_006bfd90
// -----------------------------------------------------------------------------
// Stable ID: aa_006bfd90
// Address:   0x006bfd90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bfd90 @ 0x006bfd90
// Stable ID: aa_006bfd90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, while×3, do×2, return×1.
//  - Notable callees: FUN_006bc5b0×2, FUN_005b3370, FUN_006bacf0, FUN_006bb1c0, FUN_006bb3a0, FUN_006bc200, FUN_006bc990, FUN_006bddb0.
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

void FUN_006bfd90(int param_1,uint32_t /* width from decompiler */ *param_2,int param_3,int param_4,int *param_5)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  char cVar7;

  int iVar8;

  char local_38 [4];

  char local_34 [4];

  uint8_t local_30 [16];

  uint8_t local_20 [28];

  

  param_5[1] = 0;

  if (0 < param_3) {

    do {

      if (param_5[1] == (param_5[2] & 0x7fffffffU)) {

        FUN_005b3370(param_5,0x10);

      }

      puVar5 = (uint32_t /* width from decompiler */ *)(param_5[1] * 0x10 + *param_5);

      param_5[1] = param_5[1] + 1;

      uVar1 = *param_2;

      uVar2 = param_2[1];

      uVar3 = param_2[2];

      uVar4 = param_2[3];

      param_2 = param_2 + 4;

      param_3 = param_3 + -1;

      *puVar5 = uVar1;

      puVar5[1] = uVar2;

      puVar5[2] = uVar3;

      puVar5[3] = uVar4;

    } while (param_3 != 0);

  }

  if (1 < param_5[1]) {

    FUN_006bacf0(*param_5,0,param_5[1] + -1,&LAB_006babf0);

  }

  FUN_006bb1c0(param_5,local_20,local_30);

  FUN_006bc200(*(uint32_t /* width from decompiler */ *)(param_1 + 4),param_5,local_34);

  local_38[0] = '\x01';

  cVar7 = '\0';

  while ((cVar7 == '\0' || (local_38[0] != '\0'))) {

    local_34[0] = local_38[0] == '\0';

    iVar6 = 0;

    if (0 < param_5[1]) {

      iVar8 = 0;

      do {

        *(uint32_t /* width from decompiler */ *)(iVar8 + 0xc + *param_5) = 0;

        iVar6 = iVar6 + 1;

        iVar8 = iVar8 + 0x10;

      } while (iVar6 < param_5[1]);

    }

    *(uint32_t /* width from decompiler */ *)(param_4 + 8) = 0;

    FUN_006bf8c0(param_1,param_5,0,param_5[1] + -1,param_4);

    FUN_006bddb0(param_4,param_5);

    FUN_006bc5b0(param_5);

    FUN_006bc990(param_4,0,param_5[1] + -1,param_1,local_38);

    FUN_006bc5b0(param_5);

    cVar7 = local_34[0];

  }

  FUN_006bb3a0(param_5,local_20,local_30);

  return;

}
