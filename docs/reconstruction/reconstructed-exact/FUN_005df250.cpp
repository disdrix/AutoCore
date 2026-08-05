// =============================================================================
// FUN_005df250
// -----------------------------------------------------------------------------
// Stable ID: aa_005df250
// Address:   0x005df250  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005df250 @ 0x005df250
// Stable ID: aa_005df250
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~57 non-empty decompiler lines.
//  - Control keywords: if×6, while×3, do×1, goto×1, return×1.
//  - Notable callees: FUN_005b3370, FUN_005df250.
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

void FUN_005df250(void)



{

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int local_c;

  uint local_8;

  uint local_4;

  

  piVar4 = (int *)&DAT_00d030dc;

  local_c = 0;

  local_8 = 0;

  local_4 = 0x80000000;

  puVar3 = DAT_00d030dc;

  if (DAT_00d030dc != (uint32_t /* width from decompiler */ *)0x0) {

    do {

      if (*(int *)puVar3[2] == 0) {

        iVar2 = (*(code *)*puVar3)();

        if (iVar2 != 0) {

          *(int *)puVar3[2] = iVar2;

          goto LAB_005df28e;

        }

        if (local_8 == (local_4 & 0x7fffffff)) {

          FUN_005b3370(&local_c,4);

        }

        *(uint32_t /* width from decompiler */ **)(local_c + local_8 * 4) = puVar3;

        local_8 = local_8 + 1;

        puVar3 = (uint32_t /* width from decompiler */ *)puVar3[1];

        *(uint32_t /* width from decompiler */ *)(*piVar4 + 4) = 0;

        *piVar4 = (int)puVar3;

      }

      else {

LAB_005df28e:

        piVar4 = puVar3 + 1;

        puVar3 = (uint32_t /* width from decompiler */ *)*piVar4;

      }

    } while (puVar3 != (uint32_t /* width from decompiler */ *)0x0);

    while (uVar1 = local_8, local_8 != 0) {

      while (uVar1 = uVar1 - 1, -1 < (int)uVar1) {

        puVar3 = *(uint32_t /* width from decompiler */ **)(local_c + uVar1 * 4);

        iVar2 = (*(code *)*puVar3)();

        if (iVar2 != 0) {

          *(int *)puVar3[2] = iVar2;

          *piVar4 = (int)puVar3;

          local_8 = local_8 - 1;

          piVar4 = puVar3 + 1;

          *(uint32_t /* width from decompiler */ *)(local_c + uVar1 * 4) = *(uint32_t /* width from decompiler */ *)(local_c + local_8 * 4);

        }

      }

    }

  }

  local_8 = 0;

  if (-1 < (int)local_4) {

    (**(code **)(*DAT_00b05060 + 0x14))(local_c,local_4 * 4,0x12);

  }

  return;

}
