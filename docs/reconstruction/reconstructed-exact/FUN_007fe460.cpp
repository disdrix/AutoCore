// =============================================================================
// FUN_007fe460
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe460
// Address:   0x007fe460  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fe460 @ 0x007fe460
// Stable ID: aa_007fe460
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00418700, FUN_00418790, FUN_007fe460.
//  - Return sites: 2.

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

void __thiscall

FUN_007fe460(int *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_3;

  iVar2 = (int)param_2;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad0a4;

  local_c = ExceptionList;

  puVar1 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)((int)param_2 + 0x3124);

  while( true ) {

    if (puVar1 == *(uint32_t /* width from decompiler */ **)((int)param_2 + 0x3124)) {

      ExceptionList = &local_c;

      param_2 = operator_new(0x30);

      if (param_2 == (int *)0x0) {

        param_2 = (int *)0x0;

      }

      else {

        *(uint8_t *)((int)param_2 + 0xe) = 0xff;

        *(uint8_t *)((int)param_2 + 0xd) = 0xff;

        *(uint8_t *)(param_2 + 3) = 0xff;

        *(uint8_t *)((int)param_2 + 0xf) = 0xff;

        param_2[2] = 0;

        param_2[8] = 0;

        *param_2 = -1;

        param_2[1] = -1;

      }

      local_4 = 0xffffffff;

      *param_2 = iVar3;

      param_2[1] = param_4;

      param_2[2] = param_5;

      param_2[3] = param_6;

      param_2[4] = *param_1;

      param_2[5] = param_1[1];

      param_2[6] = param_1[2];

      param_2[7] = param_1[3];

      param_2[8] = 0;

      iVar2 = *(int *)(iVar2 + 0x3124);

      iVar3 = FUN_00418700(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),&param_2);

      FUN_00418790();

      *(int *)(iVar2 + 4) = iVar3;

      **(int **)(iVar3 + 4) = iVar3;

      ExceptionList = local_c;

      return;

    }

    if ((*(int *)puVar1[2] == param_3) && (((int *)puVar1[2])[1] == param_4)) break;

    puVar1 = (uint32_t /* width from decompiler */ *)*puVar1;

  }

  *(int *)(puVar1[2] + 8) = param_5;

  *(int *)(puVar1[2] + 0xc) = param_6;

  iVar2 = puVar1[2];

  *(int *)(iVar2 + 0x10) = *param_1;

  *(int *)(iVar2 + 0x14) = param_1[1];

  *(int *)(iVar2 + 0x18) = param_1[2];

  *(int *)(iVar2 + 0x1c) = param_1[3];

  *(uint32_t /* width from decompiler */ *)(puVar1[2] + 0x20) = 0;

  return;

}
