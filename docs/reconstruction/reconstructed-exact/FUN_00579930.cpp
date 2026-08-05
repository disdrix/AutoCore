// =============================================================================
// FUN_00579930
// -----------------------------------------------------------------------------
// Stable ID: aa_00579930
// Address:   0x00579930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00579930 @ 0x00579930
// Stable ID: aa_00579930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_004d3ae0, FUN_00579930.
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

void __thiscall FUN_00579930(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  char cVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if ((*(char *)(param_1[0x29] + 0x7e) != '\0') && ((char)param_1[0x81] == '\0')) {

    *(uint8_t *)(param_1 + 0x81) = 1;

    FUN_004d3ae0(param_1,param_2);

    cVar1 = (**(code **)(*param_1 + 0x2c4))(param_2);

    cVar2 = (**(code **)(*param_1 + 0x2c0))(param_2);

    if ((cVar1 != '\0') &&

       ((cVar2 != '\0' &&

        (puVar4 = (uint32_t /* width from decompiler */ *)param_1[0x7a], puVar4 != (uint32_t /* width from decompiler */ *)param_1[0x7b])))) {

      do {

        piVar3 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar4,puVar4[1]);

        if (piVar3 != (int *)0x0) {

          (**(code **)(*piVar3 + 0x114))(param_2);

        }

        puVar4 = puVar4 + 2;

      } while (puVar4 != (uint32_t /* width from decompiler */ *)param_1[0x7b]);

    }

    *(uint8_t *)(param_1 + 0x81) = 0;

  }

  return;

}
