// =============================================================================
// FUN_007a1e70
// -----------------------------------------------------------------------------
// Stable ID: aa_007a1e70
// Address:   0x007a1e70  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a1e70 @ 0x007a1e70
// Stable ID: aa_007a1e70
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~264 non-empty decompiler lines.
//  - Control keywords: if×31, for×14, return×7, goto×4.
//  - Notable callees: FUN_00414a50×13, FUN_00746520×5, FUN_00414ae0×2, FUN_007a1e70.
//  - Return sites: 7.

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

uint * __fastcall FUN_007a1e70(int param_1)



{

  bool bVar1;

  bool bVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint *puVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  uint *puVar8;

  uint32_t /* width from decompiler */ *puVar9;

  bool local_6;

  bool local_5;

  bool local_4;

  char local_2;

  char local_1;

  

  local_2 = *(char *)(param_1 + 0x1dc);

  local_1 = *(char *)(param_1 + 0x1f8);

  bVar1 = *(int *)(param_1 + 0x168) < 6;

  if (bVar1) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x174) + 0xa8) = 0;

  }

  bVar1 = !bVar1;

  puVar4 = (uint *)(uint)bVar1;

  local_6 = *(int *)(param_1 + 0x17c) < 6;

  if (local_6) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x188) + 0xa8) = 0;

  }

  local_6 = !local_6;

  local_5 = *(int *)(param_1 + 400) < 6;

  if (local_5) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x19c) + 0xa8) = 0;

  }

  local_5 = !local_5;

  local_4 = *(int *)(param_1 + 0x1b8) < 6;

  if (local_4) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1c4) + 0xa8) = 0;

  }

  local_4 = !local_4;

  bVar2 = *(int *)(param_1 + 0x1a4) < 6;

  if (bVar2) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1b0) + 0xa8) = 0;

  }

  if ((*(int *)(param_1 + 0x1cc) < 6) || (*(char *)(param_1 + 0x1dc) == '\0')) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x1d8) + 0xa8) = 0;

    local_2 = '\0';

  }

  if ((*(int *)(param_1 + 0x1e8) < 6) || (*(char *)(param_1 + 0x1f8) == '\0')) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 500) + 0xa8) = 0;

    local_1 = '\0';

  }

  if (bVar1) {

    iVar6 = *(int *)(param_1 + 0x174);

    puVar4 = (uint *)(iVar6 + 0xbc);

    *puVar4 = *puVar4 | 1;

    iVar7 = *(int *)(param_1 + 0x168);

    iVar6 = *(int *)(iVar6 + 0x14);

    if (*(int *)(iVar6 + 0x10) != 0) {

      if (iVar7 < 1) {

        iVar7 = *(int *)(iVar6 + 0x18);

      }

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14),iVar7,1);

      if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

        puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x16c);

        for (uVar5 = (uint)(*(int *)(param_1 + 0x168) * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

          *puVar3 = *puVar9;

          puVar9 = puVar9 + 1;

          puVar3 = puVar3 + 1;

        }

        for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

          *(uint8_t *)puVar3 = *(uint8_t *)puVar9;

          puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

          puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

        }

      }

    }

    FUN_00414a50();

    *(int *)(*(int *)(param_1 + 0x174) + 0xa8) = *(int *)(param_1 + 0x168) / 3;

    puVar4 = (uint *)(*(int *)(param_1 + 0x174) + 0xbc);

    *puVar4 = *puVar4 & 0xfffffffe;

  }

  if (local_6) {

    iVar6 = *(int *)(param_1 + 0x188);

    puVar4 = (uint *)(iVar6 + 0xbc);

    *puVar4 = *puVar4 | 1;

    iVar7 = *(int *)(param_1 + 0x17c);

    iVar6 = *(int *)(iVar6 + 0x14);

    if (*(int *)(iVar6 + 0x10) == 0) {

LAB_007a2045:

      puVar4 = (uint *)FUN_00414a50();

      return puVar4;

    }

    if (iVar7 < 1) {

      iVar7 = *(int *)(iVar6 + 0x18);

    }

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14),iVar7,1);

    if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) goto LAB_007a2045;

    puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x180);

    for (uVar5 = (uint)(*(int *)(param_1 + 0x17c) * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar3 = *puVar9;

      puVar9 = puVar9 + 1;

      puVar3 = puVar3 + 1;

    }

    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(uint8_t *)puVar3 = *(uint8_t *)puVar9;

      puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

    FUN_00414a50();

    *(int *)(*(int *)(param_1 + 0x188) + 0xa8) = *(int *)(param_1 + 0x17c) / 3;

    iVar6 = *(int *)(param_1 + 0x188);

    puVar4 = (uint *)(iVar6 + 0xbc);

    *puVar4 = *puVar4 & 0xfffffffe;

    puVar4 = (uint *)(iVar6 + 0xbc);

  }

  if (local_5) {

    iVar6 = *(int *)(param_1 + 0x19c);

    puVar4 = (uint *)(iVar6 + 0xbc);

    *puVar4 = *puVar4 | 1;

    iVar7 = *(int *)(param_1 + 400);

    iVar6 = *(int *)(iVar6 + 0x14);

    if (*(int *)(iVar6 + 0x10) == 0) {

LAB_007a20f9:

      puVar4 = (uint *)FUN_00414a50();

      return puVar4;

    }

    if (iVar7 < 1) {

      iVar7 = *(int *)(iVar6 + 0x18);

    }

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14),iVar7,1);

    if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) goto LAB_007a20f9;

    puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x194);

    for (uVar5 = (uint)(*(int *)(param_1 + 400) * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar3 = *puVar9;

      puVar9 = puVar9 + 1;

      puVar3 = puVar3 + 1;

    }

    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(uint8_t *)puVar3 = *(uint8_t *)puVar9;

      puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

    FUN_00414a50();

    *(int *)(*(int *)(param_1 + 0x19c) + 0xa8) = *(int *)(param_1 + 400) / 3;

    puVar4 = (uint *)(*(int *)(param_1 + 0x19c) + 0xbc);

    *puVar4 = *puVar4 & 0xfffffffe;

  }

  if (local_4) {

    iVar6 = *(int *)(param_1 + 0x1c4);

    puVar4 = (uint *)(iVar6 + 0xbc);

    *puVar4 = *puVar4 | 1;

    iVar7 = *(int *)(param_1 + 0x1b8);

    iVar6 = *(int *)(iVar6 + 0x14);

    if (*(int *)(iVar6 + 0x10) == 0) {

LAB_007a21a7:

      puVar4 = (uint *)FUN_00414a50();

      return puVar4;

    }

    if (iVar7 < 1) {

      iVar7 = *(int *)(iVar6 + 0x18);

    }

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14),iVar7,1);

    if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) goto LAB_007a21a7;

    puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1bc);

    for (uVar5 = (uint)(*(int *)(param_1 + 0x1b8) * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *puVar3 = *puVar9;

      puVar9 = puVar9 + 1;

      puVar3 = puVar3 + 1;

    }

    for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

      *(uint8_t *)puVar3 = *(uint8_t *)puVar9;

      puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

    }

    FUN_00414a50();

    *(int *)(*(int *)(param_1 + 0x1c4) + 0xa8) = *(int *)(param_1 + 0x1b8) / 3;

    puVar4 = (uint *)(*(int *)(param_1 + 0x1c4) + 0xbc);

    *puVar4 = *puVar4 & 0xfffffffe;

  }

  if (bVar2) {

LAB_007a22c1:

    if (local_2 != '\0') {

      puVar4 = (uint *)(*(int *)(param_1 + 0x1d8) + 0xbc);

      *puVar4 = *puVar4 | 1;

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00414ae0(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1cc),1);

      if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar4 = (uint *)FUN_00414a50();

        return puVar4;

      }

      puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1d0);

      for (uVar5 = (uint)(*(int *)(param_1 + 0x1cc) * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar3 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar3 = puVar3 + 1;

      }

      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

      FUN_00414a50();

      *(int *)(*(int *)(param_1 + 0x1d8) + 0xa8) = *(int *)(param_1 + 0x1cc) / 3;

      puVar4 = (uint *)(*(int *)(param_1 + 0x1d8) + 0xbc);

      *puVar4 = *puVar4 & 0xfffffffe;

    }

    if (local_1 != '\0') {

      puVar4 = (uint *)(*(int *)(param_1 + 500) + 0xbc);

      *puVar4 = *puVar4 | 1;

      puVar3 = (uint32_t /* width from decompiler */ *)FUN_00414ae0(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1e8),1);

      if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

        puVar4 = (uint *)FUN_00414a50();

        return puVar4;

      }

      puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1ec);

      for (uVar5 = (uint)(*(int *)(param_1 + 0x1e8) * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar3 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar3 = puVar3 + 1;

      }

      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

      FUN_00414a50();

      puVar4 = (uint *)(*(int *)(param_1 + 0x1e8) * 0x55555556);

      *(int *)(*(int *)(param_1 + 500) + 0xa8) = *(int *)(param_1 + 0x1e8) / 3;

      puVar8 = (uint *)(*(int *)(param_1 + 500) + 0xbc);

      *puVar8 = *puVar8 & 0xfffffffe;

    }

    return puVar4;

  }

  iVar6 = *(int *)(param_1 + 0x1b0);

  puVar4 = (uint *)(iVar6 + 0xbc);

  *puVar4 = *puVar4 | 1;

  iVar7 = *(int *)(param_1 + 0x1a4);

  iVar6 = *(int *)(iVar6 + 0x14);

  if (*(int *)(iVar6 + 0x10) != 0) {

    if (iVar7 < 1) {

      iVar7 = *(int *)(iVar6 + 0x18);

    }

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00746520(*(uint32_t /* width from decompiler */ *)(iVar6 + 0x14),iVar7,1);

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      puVar9 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x1a8);

      for (uVar5 = (uint)(*(int *)(param_1 + 0x1a4) * 0x1c) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

        *puVar3 = *puVar9;

        puVar9 = puVar9 + 1;

        puVar3 = puVar3 + 1;

      }

      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar9;

        puVar9 = (uint32_t /* width from decompiler */ *)((int)puVar9 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

      FUN_00414a50();

      *(int *)(*(int *)(param_1 + 0x1b0) + 0xa8) = *(int *)(param_1 + 0x1a4) / 3;

      puVar4 = (uint *)(*(int *)(param_1 + 0x1b0) + 0xbc);

      *puVar4 = *puVar4 & 0xfffffffe;

      goto LAB_007a22c1;

    }

  }

  puVar4 = (uint *)FUN_00414a50();

  return puVar4;

}
