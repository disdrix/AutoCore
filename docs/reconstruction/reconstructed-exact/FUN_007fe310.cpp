// =============================================================================
// FUN_007fe310
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe310
// Address:   0x007fe310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007fe310 @ 0x007fe310
// Stable ID: aa_007fe310
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, while×1.
//  - Notable callees: FUN_00418700, FUN_00418790, FUN_007fe310.
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

void FUN_007fe310(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  int *local_24 [2];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009ad08f;

  local_1c = ExceptionList;

  puVar1 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(param_1 + 0x3124);

  while( true ) {

    if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x3124)) {

      ExceptionList = &local_1c;

      local_24[0] = operator_new(0x30);

      if (local_24[0] == (int *)0x0) {

        local_24[0] = (int *)0x0;

      }

      else {

        *(uint8_t *)((int)local_24[0] + 0xe) = 0xff;

        *(uint8_t *)((int)local_24[0] + 0xd) = 0xff;

        *(uint8_t *)(local_24[0] + 3) = 0xff;

        *(uint8_t *)((int)local_24[0] + 0xf) = 0xff;

        local_24[0][2] = 0;

        local_24[0][8] = 0;

        *local_24[0] = -1;

        local_24[0][1] = -1;

      }

      local_14 = 0xffffffff;

      *local_24[0] = param_2;

      local_24[0][1] = param_3;

      local_24[0][2] = param_4;

      local_24[0][3] = param_5;

      local_24[0][4] = 0;

      local_24[0][5] = 0;

      local_24[0][6] = 0;

      local_24[0][7] = 0;

      local_24[0][8] = param_6;

      iVar2 = *(int *)(param_1 + 0x3124);

      iVar3 = FUN_00418700(iVar2,*(uint32_t /* width from decompiler */ *)(iVar2 + 4),local_24);

      FUN_00418790();

      *(int *)(iVar2 + 4) = iVar3;

      **(int **)(iVar3 + 4) = iVar3;

      ExceptionList = local_1c;

      return;

    }

    if ((*(int *)puVar1[2] == param_2) && (((int *)puVar1[2])[1] == param_3)) break;

    puVar1 = (uint32_t /* width from decompiler */ *)*puVar1;

  }

  *(int *)(puVar1[2] + 8) = param_4;

  *(int *)(puVar1[2] + 0xc) = param_5;

  iVar2 = puVar1[2];

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x10) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(iVar2 + 0x1c) = 0;

  *(int *)(puVar1[2] + 0x20) = param_6;

  return;

}
