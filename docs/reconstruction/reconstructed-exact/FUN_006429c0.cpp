// =============================================================================
// FUN_006429c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006429c0
// Address:   0x006429c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006429c0 @ 0x006429c0
// Stable ID: aa_006429c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, do×1, while×1.
//  - Notable callees: CVOGReaction_ResolveObjectTarget, FUN_006429c0, Object_ResolveFromTFID.
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

void __thiscall FUN_006429c0(int param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  pvVar2 = Object_ResolveFromTFID((TFID_16 *)(param_1 + 0x28));

  (**(code **)(**(int **)(param_1 + 0x24) + 0x58))();

  puVar4 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x24) + 0x148);

  puVar1 = *(uint32_t /* width from decompiler */ **)(*(int *)(param_1 + 0x24) + 0x14c);

  if (puVar4 != puVar1) {

    do {

      piVar3 = (int *)CVOGReaction_ResolveObjectTarget(0,*puVar4,puVar4[1]);

      if (piVar3 != (int *)0x0) {

        (**(code **)(*piVar3 + 0x114))(pvVar2);

      }

      puVar4 = puVar4 + 2;

    } while (puVar4 != puVar1);

    *param_2 = DAT_00af5018;

    return;

  }

  *param_2 = DAT_00af5018;

  return;

}
