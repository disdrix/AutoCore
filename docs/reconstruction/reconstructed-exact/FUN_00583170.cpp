// =============================================================================
// FUN_00583170
// -----------------------------------------------------------------------------
// Stable ID: aa_00583170
// Address:   0x00583170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00583170 @ 0x00583170
// Stable ID: aa_00583170
// Embedded strings (evidence for future rename):
//   - "veh_paint_pallet.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1.
//  - Notable callees: CONCAT12, FUN_0040ead0, FUN_00583170, FUN_0096bb40, FUN_0096be60, FUN_0096ef70, FUN_0096efd0, FUN_0096f3e0.
//  - Strings: "veh_paint_pallet.dds".
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

void FUN_00583170(void)



{

  int iVar1;

  uint uVar2;

  uint8_t *puVar3;

  uint8_t *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  uint32_t /* width from decompiler */ local_20;

  int local_1c;

  int local_18;

  uint8_t local_10 [4];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a5446;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0096ef70();

  iVar7 = 0;

  local_4 = 0;

  FUN_00989e00(local_10,"veh_paint_pallet.dds");

  FUN_0096f3e0(local_10,0);

  if (local_1c != 0) {

    iVar1 = FUN_0096be60(0,0,0,4);

    if (iVar1 != 0) {

      if (local_1c == 0) {

        local_18 = 0;

      }

      else {

        local_18 = *(int *)(local_1c + 0x40);

      }

      uVar2 = FUN_0040ead0(*(uint32_t /* width from decompiler */ *)(local_1c + 0x24));

      iVar6 = 0;

      if (0 < *(int *)(local_1c + 0x1c)) {

        iVar5 = *(int *)(local_1c + 0x20);

        puVar4 = (uint8_t *)(iVar1 + 2);

        do {

          iVar1 = 0;

          puVar3 = puVar4;

          if (0 < iVar5) {

            do {

              local_20 = (uint)CONCAT12(*puVar3,*(uint16_t *)(puVar3 + -2));

              (&DAT_00b04870)[iVar7] = local_20;

              iVar5 = *(int *)(local_1c + 0x20);

              iVar1 = iVar1 + 1;

              iVar7 = iVar7 + 1;

              puVar3 = puVar3 + (uVar2 >> 3);

            } while (iVar1 < iVar5);

          }

          puVar4 = puVar4 + local_18;

          iVar6 = iVar6 + 1;

        } while (iVar6 < *(int *)(local_1c + 0x1c));

      }

    }

    if (local_1c != 0) {

      FUN_0096bb40(0);

    }

  }

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_c;

  return;

}
