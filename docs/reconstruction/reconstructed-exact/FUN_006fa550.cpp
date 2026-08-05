// =============================================================================
// FUN_006fa550
// -----------------------------------------------------------------------------
// Stable ID: aa_006fa550
// Address:   0x006fa550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006fa550 @ 0x006fa550
// Stable ID: aa_006fa550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_005d6a40, FUN_005d6ae0, FUN_006f82e0, FUN_006fa550, FUN_006fb090.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __thiscall FUN_006fa550(uint32_t /* width from decompiler */ *param_1,int param_2)



{

  float *pfVar1;

  int iVar2;

  uint16_t *puVar3;

  int local_24;

  float local_20;

  float local_1c;

  float local_18;

  

  FUN_005d6ae0(param_1[5],param_2);

  local_24 = 0;

  if (0 < *(int *)(param_2 + 0x54)) {

    iVar2 = (*(int *)(*(int *)param_1[4] + 4) - *(int *)(param_2 + 0x54)) * 0x30;

    puVar3 = (uint16_t *)(param_2 + 0x24);

    do {

      pfVar1 = (float *)(**(int **)param_1[4] + 0x10 + iVar2);

      if (_DAT_00a0ef18 <=

          local_20 * *pfVar1 +

          local_1c * pfVar1[1] + local_18 * *(float *)(**(int **)param_1[4] + 0x18 + iVar2)) {

        local_24 = local_24 + 1;

        puVar3 = puVar3 + 3;

        iVar2 = iVar2 + 0x30;

      }

      else {

        FUN_006f82e0((*(int **)param_1[4])[1] * 0x30 + -0x30 + **(int **)param_1[4]);

        if ((ushort)puVar3[-2] < 6) {

          *(int *)(param_2 + 0x50) = *(int *)(param_2 + 0x50) + -1;

        }

        (**(code **)(*(int *)param_1[3] + 8))(*puVar3);

        FUN_006fb090(local_24,*param_1,param_1[1]);

        *(int *)(*(int *)param_1[4] + 4) = *(int *)(*(int *)param_1[4] + 4) + -1;

      }

    } while (local_24 < *(int *)(param_2 + 0x54));

  }

  if (1 < *(int *)(param_2 + 0x54)) {

    FUN_005d6a40(param_1 + 0x1c,param_2);

    *(uint8_t *)(param_2 + 0x59) = 1;

    return;

  }

  *(uint8_t *)(param_2 + 0x59) = 0;

  return;

}
