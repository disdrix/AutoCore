// =============================================================================
// FUN_00634c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00634c50
// Address:   0x00634c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00634c50 @ 0x00634c50
// Stable ID: aa_00634c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×7, do×2, while×2, return×1.
//  - Notable callees: FUN_007468e0×2, FUN_00414ae0, FUN_00416240, FUN_00437960, FUN_0044ba40, FUN_0044bcc0, FUN_00634c50, FUN_00743ba0.
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

void __fastcall FUN_00634c50(int param_1)



{

  uint *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  uint uVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int local_104;

  uint local_100;

  uint8_t local_e8 [12];

  uint8_t local_dc [216];

  

  if ((((*(int *)(param_1 + 0x18) != 0) && (*(int *)(param_1 + 0x20) != 0)) &&

      (*(int *)(param_1 + 0x10) != 0)) &&

     ((*(int *)(param_1 + 0x14) != 0 && (*(int *)(param_1 + 0x1c) != 0)))) {

    iVar9 = *(int *)(param_1 + 0xc);

    puVar1 = (uint *)(iVar9 + 0xbc);

    *puVar1 = *puVar1 | 1;

    iVar2 = *(int *)(param_1 + 0xc);

    iVar3 = FUN_00414ae0(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x18),0);

    if (iVar3 != 0) {

      iVar4 = FUN_0044bcc0();

      uVar5 = FUN_00437960();

      FUN_00416240(uVar5);

      iVar6 = FUN_007468e0(0,0);

      iVar7 = FUN_007468e0(3,0);

      local_100 = 0;

      if (*(int *)(param_1 + 0x18) != 0) {

        local_104 = 0;

        do {

          puVar11 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar6 + 2) + iVar3);

          puVar8 = (uint32_t /* width from decompiler */ *)FUN_009732d0(local_e8,*(int *)(param_1 + 0x10) + local_104);

          *puVar11 = *puVar8;

          puVar11[1] = puVar8[1];

          puVar11[2] = puVar8[2];

          puVar11 = (uint32_t /* width from decompiler */ *)((uint)*(ushort *)(iVar7 + 2) + iVar3);

          puVar8 = (uint32_t /* width from decompiler */ *)FUN_00973240(local_dc,*(int *)(param_1 + 0x14) + local_104);

          iVar3 = iVar3 + iVar4;

          local_104 = local_104 + 0xc;

          *puVar11 = *puVar8;

          puVar11[1] = puVar8[1];

          puVar11[2] = puVar8[2];

          local_100 = local_100 + 1;

        } while (local_100 < *(uint *)(param_1 + 0x18));

      }

      if (*(int *)(*(int *)(iVar9 + 0x14) + 0x10) != 0) {

        FUN_007464e0();

      }

    }

    iVar9 = FUN_0044ba40(0,*(uint32_t /* width from decompiler */ *)(param_1 + 0x20),0x800);

    if (iVar9 != 0) {

      if (*(int *)(param_1 + 0x20) != 0) {

        uVar10 = 0;

        do {

          *(uint16_t *)(iVar9 + uVar10 * 2) =

               *(uint16_t *)(*(int *)(param_1 + 0x1c) + uVar10 * 4);

          uVar10 = uVar10 + 1;

        } while (uVar10 < *(uint *)(param_1 + 0x20));

      }

      if (*(int *)(*(int *)(iVar2 + 0xc) + 0x10) != 0) {

        FUN_00743ba0();

      }

    }

  }

  return;

}
