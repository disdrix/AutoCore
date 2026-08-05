// =============================================================================
// FUN_00744c10
// -----------------------------------------------------------------------------
// Stable ID: aa_00744c10
// Address:   0x00744c10  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00744c10 @ 0x00744c10
// Stable ID: aa_00744c10
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_0044dba0×2, FUN_0044e8c0, FUN_00744c10.
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

void __fastcall FUN_00744c10(int param_1)



{

  int iVar1;

  int iVar2;

  int local_4;

  

  iVar1 = DAT_00d1f050;

  local_4 = param_1;

  if ((DAT_00d1f050 != 0) && (iVar2 = *(int *)(param_1 + 0x50), iVar2 != *(int *)(param_1 + 0x54)))

  {

    do {

      FUN_0044e8c0(&local_4);

      if (local_4 != *(int *)(iVar1 + 8)) {

        *(int *)(local_4 + 0x10) = *(int *)(local_4 + 0x10) + -1;

      }

      iVar2 = iVar2 + 4;

    } while (iVar2 != *(int *)(param_1 + 0x54));

  }

  if (*(void **)(param_1 + 0x50) == (void *)0x0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x50) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x54) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = 0;

    FUN_0044dba0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x14) + 4));

    *(int *)(*(int *)(param_1 + 0x14) + 4) = *(int *)(param_1 + 0x14);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x14);

    *(int *)(*(int *)(param_1 + 0x14) + 8) = *(int *)(param_1 + 0x14);

    FUN_0044dba0(*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x20) + 4));

    *(int *)(*(int *)(param_1 + 0x20) + 4) = *(int *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x24) = 0;

    *(uint32_t /* width from decompiler */ *)*(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(int *)(*(int *)(param_1 + 0x20) + 8) = *(int *)(param_1 + 0x20);

    return;

  }

                    /* WARNING: Subroutine does not return */

  operator_delete(*(void **)(param_1 + 0x50));

}
