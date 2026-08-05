// =============================================================================
// FUN_00730910
// -----------------------------------------------------------------------------
// Stable ID: aa_00730910
// Address:   0x00730910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00730910 @ 0x00730910
// Stable ID: aa_00730910
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~93 non-empty decompiler lines.
//  - Control keywords: if×12, do×1, return×1, for×1, goto×1, while×1.
//  - Notable callees: FUN_00972cc0×2, FUN_0040cf90, FUN_0040d1a0, FUN_0043f4b0, FUN_0044b930, FUN_00730910, FUN_00734550, FUN_00752df0.
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

uint32_t /* width from decompiler */ __thiscall FUN_00730910(int param_1,int param_2)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  uint8_t *local_1a0;

  int local_19c;

  uint8_t local_190 [156];

  float fStack_f4;

  float fStack_f0;

  float fStack_ec;

  float fStack_e8;

  float fStack_e4;

  float fStack_e0;

  char cStack_d8;

  uint uStack_d4;

  uint8_t auStack_d0 [204];

  

  piVar1 = *(int **)(param_2 + 0x10);

  local_1a0 = (uint8_t *)0x0;

  local_19c = 0;

  do {

    iVar2 = piVar1[0x19];

    if (iVar2 == 0) {

      iVar5 = 0;

    }

    else {

      iVar5 = *(int *)(iVar2 + 0x10);

    }

    if (iVar5 <= local_19c) {

      return local_1a0;

    }

    if (iVar2 != 0) {

      iVar5 = local_19c;

      for (puVar3 = (uint32_t /* width from decompiler */ *)**(uint32_t /* width from decompiler */ **)(iVar2 + 0xc);

          puVar3 != *(uint32_t /* width from decompiler */ **)(iVar2 + 0xc); puVar3 = (uint32_t /* width from decompiler */ *)*puVar3) {

        if (iVar5 == 0) {

          piVar4 = puVar3 + 2;

          goto LAB_00730976;

        }

        iVar5 = iVar5 + -1;

      }

    }

    piVar4 = (int *)0x0;

LAB_00730976:

    iVar2 = *piVar4;

    FUN_00972cc0();

    iVar5 = (**(code **)(*piVar1 + 8))(*(uint32_t /* width from decompiler */ *)(iVar2 + 0xc),local_190);

    if (-1 < iVar5) {

      FUN_00972cc0();

      FUN_0040d1a0(iVar2 + 0x10);

      FUN_0040cf90(iVar2 + 0x20);

      FUN_00973030(auStack_d0);

      local_1a0 = local_190;

      if ((uStack_d4 & 1) != 0) {

        local_1a0 = (uint8_t *)FUN_00972e50();

      }

      if (*(int *)(param_1 + 0x28) != 0) {

        FUN_0044b930(0);

      }

      if (*(int *)(param_1 + 0x18) != 0) {

        FUN_0043f4b0();

      }

      if (*(int *)(*(int *)(param_1 + 0x18) + 0x34) == 0) {

        FUN_00967150(*(int *)(param_1 + 0x18) + 0x24);

      }

      FUN_00734550();

      if ((uStack_d4 >> 2 & 1) != 0) {

        if (cStack_d8 == '\0') {

          fStack_e0 = g_flOne / fStack_f4;

          fStack_e4 = fStack_e0;

        }

        else {

          fStack_e0 = g_flOne / fStack_ec;

          fStack_e4 = g_flOne / fStack_f0;

        }

        fStack_e8 = g_flOne / fStack_f4;

        uStack_d4 = uStack_d4 & 0xfffffffb;

      }

      FUN_00752df0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),local_1a0,1,&fStack_e8,0,0);

      if (*(int *)(param_1 + 0x28) == 0) {

        local_1a0 = (uint8_t *)

                    FUN_0075e8e0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),0,*(uint32_t /* width from decompiler */ *)(param_1 + 4));

      }

      else {

        local_1a0 = (uint8_t *)

                    FUN_0075e9f0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xc),0,*(uint32_t /* width from decompiler */ *)(param_1 + 4),0,0);

      }

    }

    local_19c = local_19c + 1;

  } while( true );

}
