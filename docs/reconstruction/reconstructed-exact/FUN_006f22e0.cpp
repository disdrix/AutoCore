// =============================================================================
// FUN_006f22e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f22e0
// Address:   0x006f22e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f22e0 @ 0x006f22e0
// Stable ID: aa_006f22e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, while×2, do×1.
//  - Notable callees: FUN_006f22e0.
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

void FUN_006f22e0(int param_1,int param_2,uint8_t *param_3)



{

  int iVar1;

  int iVar2;

  byte bVar3;

  int *piVar4;

  int *piVar5;

  int *piVar6;

  int local_c;

  int local_8;

  

  local_c = (*(int *)(param_1 + 0x24) - *(int *)(param_2 + 8)) + 8;

  *param_3 = 0;

  if (local_c < 1) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x24) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x28) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x28);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x2c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

    *(uint32_t /* width from decompiler */ *)(param_2 + 0x30) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x30);

    return;

  }

  if (3 < local_c) {

    local_c = 4;

  }

  do {

    *(int *)(param_2 + 0x24) = *(int *)(param_1 + 0x24) - local_c;

    local_8 = 0;

    piVar6 = (int *)(param_2 + 0x10);

    piVar4 = (int *)(param_2 + 0x28);

    piVar5 = (int *)(param_3 + 8);

    while( true ) {

      if (2 < local_8) {

        *(int *)(param_3 + 4) = local_c;

        *param_3 = 1;

        return;

      }

      iVar1 = *(int *)((param_1 - param_2) + (int)piVar4);

      bVar3 = (byte)*(uint32_t /* width from decompiler */ *)(param_1 + 0x24);

      iVar2 = piVar6[-1] - iVar1 >> (bVar3 & 0x1f);

      *piVar4 = (iVar2 << (bVar3 & 0x1f)) + iVar1;

      *piVar5 = iVar2;

      if (0xfe < *piVar6 - *piVar4 >> ((byte)*(uint32_t /* width from decompiler */ *)(param_2 + 0x24) & 0x1f)) break;

      local_8 = local_8 + 1;

      piVar5 = piVar5 + 1;

      piVar4 = piVar4 + 1;

      piVar6 = piVar6 + 2;

    }

    local_c = local_c + -1;

  } while( true );

}
