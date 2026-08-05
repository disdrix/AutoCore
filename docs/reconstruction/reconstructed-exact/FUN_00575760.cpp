// =============================================================================
// FUN_00575760
// -----------------------------------------------------------------------------
// Stable ID: aa_00575760
// Address:   0x00575760  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00575760 @ 0x00575760
// Stable ID: aa_00575760
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_00418e60, FUN_00575760.
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

void __thiscall FUN_00575760(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  int local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar5 = (int *)(param_1 + 0x1a0);

  local_c = 4;

  do {

    if (*piVar5 == 0) {

      iVar1 = *piVar5;

      iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

      local_8 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

      iVar3 = *(int *)(param_2 + 4);

      local_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

      if ((iVar3 == 0) ||

         ((uint)(*(int *)(param_2 + 0xc) - iVar3 >> 3) <= (uint)(*(int *)(param_2 + 8) - iVar3 >> 3)

         )) {

        FUN_00418e60(*(uint32_t /* width from decompiler */ *)(param_2 + 8),1,&local_8);

      }

      else {

        puVar4 = *(uint32_t /* width from decompiler */ **)(param_2 + 8);

        *puVar4 = local_8;

        puVar4[1] = local_4;

        *(uint32_t /* width from decompiler */ **)(param_2 + 8) = puVar4 + 2;

      }

    }

    piVar5 = piVar5 + 4;

    local_c = local_c + -1;

  } while (local_c != 0);

  return;

}
