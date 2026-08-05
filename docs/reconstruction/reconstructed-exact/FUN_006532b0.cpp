// =============================================================================
// FUN_006532b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006532b0
// Address:   0x006532b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006532b0 @ 0x006532b0
// Stable ID: aa_006532b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~109 non-empty decompiler lines.
//  - Control keywords: if×13, do×6, while×6, return×1.
//  - Notable callees: FUN_005b3300×2, FUN_00658800×2, FUN_006532b0, FUN_00657d10.
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

void __thiscall FUN_006532b0(int param_1,int param_2)



{

  uint uVar1;

  int iVar2;

  int unaff_EBX;

  int iVar3;

  int iVar4;

  int iStack_54;

  int local_50;

  int local_48;

  int local_44;

  int local_40;

  int local_3c;

  uint local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t auStack_30 [16];

  uint8_t auStack_20 [28];

  

  iVar3 = *(int *)(param_2 + 0x124);

  local_48 = 0;

  local_44 = 0;

  local_40 = -0x80000000;

  if (iVar3 < 0) {

    iVar4 = iVar3 << 7;

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)(iVar4 + local_48))(0);

      iVar4 = iVar4 + 0x80;

    } while (iVar4 < 0);

  }

  else {

    if (iVar3 < 1) {

      iVar4 = 0;

      if (0 < iVar3) {

        do {

          if (iVar4 != 0) {

            FUN_00658800();

          }

          iVar4 = iVar4 + 1;

        } while (iVar4 < iVar3);

      }

    }

    else {

      local_48 = 0;

      local_44 = 0;

      local_40 = -0x80000000;

      if (0 < iVar3) {

        FUN_005b3300(&local_48,iVar3,0x80);

      }

    }

    iVar4 = local_48;

    iVar2 = iVar3;

    if (0 < iVar3) {

      do {

        local_50 = iVar2;

        if (iVar4 != 0) {

          FUN_00658800();

        }

        local_50 = local_50 + -1;

        iVar4 = iVar4 + 0x80;

        iVar2 = local_50;

      } while (local_50 != 0);

    }

  }

  uVar1 = *(uint *)(param_2 + 0x124);

  local_3c = 0;

  local_38 = 0;

  local_34 = 0x80000000;

  local_44 = iVar3;

  if (0 < (int)uVar1) {

    FUN_005b3300(&local_3c,((int)uVar1 < 0) - 1 & uVar1,4);

  }

  iVar3 = 0;

  local_38 = uVar1;

  if (0 < *(int *)(param_2 + 0x124)) {

    iVar4 = 0;

    do {

      (**(code **)(**(int **)(*(int *)(param_2 + 0x120) + iVar3 * 4) + 0x18))(auStack_30);

      FUN_00657d10(auStack_30,auStack_20);

      *(int *)(local_3c + iVar3 * 4) = iVar4 + local_48;

      iVar3 = iVar3 + 1;

      iVar4 = iVar4 + 0x80;

    } while (iVar3 < *(int *)(param_2 + 0x124));

  }

  (**(code **)(**(int **)(param_1 + -8) + 0x24))(&local_3c,DAT_00d034fc,DAT_00d034f8);

  if (-1 < local_40) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_48,local_40 * 4,0x12);

  }

  iVar3 = 0;

  if (0 < local_50) {

    iVar4 = 0;

    do {

      (*(code *)**(uint32_t /* width from decompiler */ **)(iStack_54 + iVar4))(0);

      iVar3 = iVar3 + 1;

      iVar4 = iVar4 + 0x80;

    } while (iVar3 < local_50);

  }

  if (-1 < param_1) {

    (**(code **)(*DAT_00b05060 + 0x14))(iStack_54,param_1 << 7,0x12);

  }

  iVar3 = 0;

  if (0 < *(int *)(unaff_EBX + 8)) {

    do {

      iVar4 = *(int *)(*(int *)(unaff_EBX + 4) + iVar3 * 4);

      (**(code **)(**(int **)(unaff_EBX + -8) + 0xc))

                (*(int *)(iVar4 + 0x14) + 0x20,iVar4 + 0xc,0,DAT_00d034f8);

      iVar3 = iVar3 + 1;

    } while (iVar3 < *(int *)(unaff_EBX + 8));

  }

  return;

}
