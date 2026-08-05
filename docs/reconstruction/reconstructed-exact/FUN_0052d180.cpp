// =============================================================================
// FUN_0052d180
// -----------------------------------------------------------------------------
// Stable ID: aa_0052d180
// Address:   0x0052d180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0052d180 @ 0x0052d180
// Stable ID: aa_0052d180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, return×4, for×1.
//  - Notable callees: FUN_00418b80, FUN_0052ada0, FUN_0052af70, FUN_0052b140, FUN_0052d180, FUN_00538ab0.
//  - Return sites: 4.

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

byte __thiscall FUN_0052d180(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  short sVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  short sVar6;

  uint32_t /* width from decompiler */ *puVar7;

  uint32_t /* width from decompiler */ *puVar8;

  uint32_t /* width from decompiler */ local_210;

  int local_20c;

  uint32_t /* width from decompiler */ local_208 [10];

  uint32_t /* width from decompiler */ local_1e0;

  

  local_210 = param_2;

  piVar3 = (int *)FUN_00538ab0(&local_20c,&local_210);

  if (*piVar3 != DAT_00b045b4) {

    puVar7 = (uint32_t /* width from decompiler */ *)(*piVar3 + 0x10);

    puVar8 = local_208;

    for (iVar5 = 0x7f; iVar5 != 0; iVar5 = iVar5 + -1) {

      *puVar8 = *puVar7;

      puVar7 = puVar7 + 1;

      puVar8 = puVar8 + 1;

    }

    cVar1 = FUN_0052b140(param_2);

    if (cVar1 == '\0') {

      return 4;

    }

    local_210 = param_2;

    FUN_00418b80(&local_20c,&local_210);

    if ((local_20c != *(int *)(param_1 + 0x588)) && (iVar5 = *(int *)(local_20c + 0x14), 0 < iVar5))

    {

      iVar4 = FUN_0052ada0(param_2);

      return (iVar5 <= iVar4) - 1U & 2;

    }

    sVar2 = FUN_0052af70(local_1e0);

    sVar6 = (short)local_1e0;

    if ((0 < sVar6) && (sVar6 < 4)) {

      return ((int)sVar2 < *(int *)(&DAT_009ceeb0 + sVar6 * 4)) - 1U & 3;

    }

  }

  return 5;

}
