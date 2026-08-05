// =============================================================================
// FUN_00496ed0
// -----------------------------------------------------------------------------
// Stable ID: aa_00496ed0
// Address:   0x00496ed0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00496ed0 @ 0x00496ed0
// Stable ID: aa_00496ed0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, do×1, while×1, return×1.
//  - Notable callees: FUN_00442ed0, FUN_004507a0, FUN_00496ed0.
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

void __fastcall FUN_00496ed0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (*(char *)(param_1 + 0x4d) != '\0') {

    if (*(int *)(param_1 + 0xac) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(param_1 + 0xb0) - *(int *)(param_1 + 0xac) >> 2;

    }

    if (*(int *)(param_1 + 0x30) == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(param_1 + 0x34) - *(int *)(param_1 + 0x30) >> 2;

    }

    FUN_00442ed0(iVar2 + iVar3);

    puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x30);

    if (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x34)) {

      do {

        iVar3 = *(int *)(param_1 + 0xac);

        if ((iVar3 == 0) ||

           ((uint)(*(int *)(param_1 + 0xb4) - iVar3 >> 2) <=

            (uint)(*(int *)(param_1 + 0xb0) - iVar3 >> 2))) {

          FUN_004507a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0),1,puVar4);

        }

        else {

          puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0xb0);

          *puVar1 = *puVar4;

          *(uint32_t /* width from decompiler */ **)(param_1 + 0xb0) = puVar1 + 1;

        }

        puVar4 = puVar4 + 1;

      } while (puVar4 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x34));

    }

  }

  return;

}
