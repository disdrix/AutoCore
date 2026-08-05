// =============================================================================
// FUN_00965290
// -----------------------------------------------------------------------------
// Stable ID: aa_00965290
// Address:   0x00965290  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00965290 @ 0x00965290
// Stable ID: aa_00965290
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_0076f6e0, FUN_0076f970, FUN_00965290, SQRT.
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

int __thiscall FUN_00965290(int param_1,float *param_2,float param_3,uint32_t /* width from decompiler */ *param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  int *piVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  int local_48;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  uint32_t /* width from decompiler */ uStack_8;

  float fStack_4;

  

  puVar6 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

  local_48 = 0;

  iVar5 = 0;

  if (puVar6 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc)) {

    do {

      piVar4 = (int *)*puVar6;

      (**(code **)(*piVar4 + 0x48))();

      iVar5 = (**(code **)(*piVar4 + 0xc))();

      if ((*(byte *)(iVar5 + 0xbc) & 1) != 0) {

        uStack_10 = 0;

        uStack_c = 0;

        uStack_8 = 0;

        fStack_4 = g_flOne;

        FUN_0076f970(iVar5,&uStack_10,iVar5 + 0x9c,iVar5 + 0x80,iVar5 + 0x90);

        *(uint *)(iVar5 + 0xbc) = *(uint *)(iVar5 + 0xbc) & 0xfffffffe;

      }

      FUN_0076f6e0();

      fVar1 = *param_2;

      fVar2 = param_2[1];

      fVar3 = param_2[2];

      iVar5 = (**(code **)(*piVar4 + 0x48))();

      if (SQRT((fStack_1c - fVar1) * (fStack_1c - fVar1) +

               (fStack_18 - fVar2) * (fStack_18 - fVar2) + (fStack_14 - fVar3) * (fStack_14 - fVar3)

              ) < param_3 + *(float *)(iVar5 + 0xc)) {

        local_48 = local_48 + 1;

        iVar5 = (**(code **)*param_4)(piVar4);

        if (iVar5 == 1) {

          return local_48;

        }

      }

      puVar6 = puVar6 + 1;

      iVar5 = local_48;

    } while (puVar6 != *(uint32_t /* width from decompiler */ **)(param_1 + 0xc));

  }

  return iVar5;

}
