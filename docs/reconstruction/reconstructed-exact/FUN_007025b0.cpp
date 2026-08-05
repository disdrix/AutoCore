// =============================================================================
// FUN_007025b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007025b0
// Address:   0x007025b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007025b0 @ 0x007025b0
// Stable ID: aa_007025b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00702170, FUN_007023a0, FUN_007025b0.
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

uint32_t /* width from decompiler */ FUN_007025b0(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ uVar7;

  int iVar8;

  uint32_t /* width from decompiler */ *puVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ local_8;

  

  iVar8 = param_1[1];

  iVar6 = 0;

  local_8 = 0;

  puVar9 = param_3;

  uVar10 = 0;

  if (0 < iVar8) {

    do {

      if (puVar9 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar9 = (uint32_t /* width from decompiler */ *)0x0;

        uVar10 = 2;

        break;

      }

      piVar4 = (int *)*param_1;

      iVar5 = piVar4[iVar6];

      iVar1 = iVar6 + 1;

      if (iVar1 < iVar8) {

        iVar8 = piVar4[iVar6 + 1];

      }

      else {

        iVar8 = *piVar4;

      }

      *(int *)(iVar5 + 0x20) = iVar5;

      *(int *)(iVar5 + 0x30) = iVar5;

      *(int *)(iVar5 + 0x40) = iVar5;

      puVar2 = (uint32_t /* width from decompiler */ *)(iVar5 + 0x34);

      *(uint32_t /* width from decompiler */ **)(iVar5 + 0x28) = puVar2;

      puVar3 = (uint32_t /* width from decompiler */ *)(iVar5 + 0x14);

      *(uint32_t /* width from decompiler */ **)(iVar5 + 0x38) = puVar3;

      *(uint32_t /* width from decompiler */ **)(iVar5 + 0x18) = (uint32_t /* width from decompiler */ *)(iVar5 + 0x24);

      *puVar3 = *(uint32_t /* width from decompiler */ *)puVar9[1];

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x24) = *puVar9;

      *puVar2 = *param_4;

      puVar9[2] = puVar3;

      *(uint32_t /* width from decompiler */ **)(iVar5 + 0x1c) = puVar9;

      *(uint32_t /* width from decompiler */ **)(iVar8 + 0x2c) = puVar2;

      *(int *)(iVar5 + 0x3c) = iVar8 + 0x24;

      FUN_007023a0();

      puVar9 = *(uint32_t /* width from decompiler */ **)(*(int *)puVar9[1] + 0x10);

      iVar8 = param_1[1];

      iVar6 = iVar1;

      uVar10 = local_8;

    } while (iVar1 < iVar8);

  }

  FUN_00702170();

  uVar7 = 2;

  if (param_3 == puVar9) {

    uVar7 = uVar10;

  }

  return uVar7;

}
