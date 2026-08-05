// =============================================================================
// FUN_006eda50
// -----------------------------------------------------------------------------
// Stable ID: aa_006eda50
// Address:   0x006eda50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006eda50 @ 0x006eda50
// Stable ID: aa_006eda50
// Embedded strings (evidence for future rename):
//   - "LthkBvAgent"
//   - "Stchild"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~55 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: rdtsc×3, FUN_006eda50.
//  - Strings: "LthkBvAgent"; "Stchild".
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

void FUN_006eda50(int *param_1,uint32_t /* width from decompiler */ *param_2,int *param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5)



{

  uint64_t uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *local_50;

  int local_4c;

  int local_48;

  int *local_44;

  undefined **ppuStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  char cStack_38;

  uint32_t /* width from decompiler */ uStack_24;

  

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = "LthkBvAgent";

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  local_48 = param_1[2];

  iVar4 = *param_1;

  local_44 = param_1;

  local_50 = *(int **)(iVar4 + 0xc);

  local_4c = param_1[1];

  iVar2 = (**(code **)(*local_50 + 0x14))();

  iVar3 = (**(code **)(*(int *)*param_2 + 0x14))();

  ppuStack_40 = &PTR_LAB_00a0e9d8;

  cStack_38 = '\0';

  uStack_24 = 0x7f7fffff;

  uStack_3c = 0x7f7fffff;

  (**(code **)(*param_3 + 0x318c + (iVar2 * 0x20 + iVar3) * 4))

            (&local_50,param_2,param_3,&ppuStack_40,&ppuStack_40);

  if (cStack_38 != '\0') {

    if (DAT_00bc5644 < DAT_00bc5648) {

      *DAT_00bc5644 = "Stchild";

      uVar1 = rdtsc();

      DAT_00bc5644[1] = (int)uVar1;

      DAT_00bc5644 = DAT_00bc5644 + 3;

    }

    local_50 = *(int **)(iVar4 + 0x10);

    local_4c = local_44[1];

    iVar4 = (**(code **)(*local_50 + 0x14))();

    (**(code **)(*param_3 + 0x318c + (iVar4 * 0x20 + iVar3) * 4))

              (&local_50,param_2,param_3,param_4,param_5);

  }

  if (DAT_00bc5644 < DAT_00bc5648) {

    *DAT_00bc5644 = &DAT_009d282c;

    uVar1 = rdtsc();

    DAT_00bc5644[1] = (int)uVar1;

    DAT_00bc5644 = DAT_00bc5644 + 3;

  }

  return;

}
