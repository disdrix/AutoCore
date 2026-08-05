// =============================================================================
// FUN_00518180
// -----------------------------------------------------------------------------
// Stable ID: aa_00518180
// Address:   0x00518180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00518180 @ 0x00518180
// Stable ID: aa_00518180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×6, do×2, while×2, return×1, goto×1.
//  - Notable callees: FUN_00518180.
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

void __thiscall FUN_00518180(uint32_t /* width from decompiler */ *param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ **ppuVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint *puVar6;

  uint32_t /* width from decompiler */ *local_4;

  

  local_4 = param_1;

  puVar6 = *(uint **)(param_2 + 4);

  puVar1 = *(uint **)(param_2 + 8);

  do {

    if (puVar6 == puVar1) {

      return;

    }

    puVar5 = (uint32_t /* width from decompiler */ *)param_3[1];

    if (*(char *)((int)puVar5[1] + 0x21) == '\0') {

      puVar2 = (uint32_t /* width from decompiler */ *)puVar5[1];

      do {

        if (((int)puVar6[1] < (int)puVar2[5]) ||

           (((int)puVar6[1] <= (int)puVar2[5] && (*puVar6 <= (uint)puVar2[4])))) {

          puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

          puVar5 = puVar2;

        }

        else {

          puVar3 = (uint32_t /* width from decompiler */ *)puVar2[2];

        }

        puVar2 = puVar3;

      } while (*(char *)((int)puVar3 + 0x21) == '\0');

    }

    local_4 = (uint32_t /* width from decompiler */ *)param_3[1];

    if (puVar5 == local_4) {

LAB_005181f6:

      ppuVar4 = &local_4;

    }

    else {

      if (((int)puVar6[1] < (int)puVar5[5]) ||

         (((int)puVar6[1] <= (int)puVar5[5] && (*puVar6 < (uint)puVar5[4])))) goto LAB_005181f6;

      ppuVar4 = &param_3;

    }

    puVar5 = *ppuVar4;

    if (puVar5 != local_4) {

      *puVar6 = puVar5[6];

      puVar6[1] = puVar5[7];

    }

    puVar6 = puVar6 + 2;

  } while( true );

}
