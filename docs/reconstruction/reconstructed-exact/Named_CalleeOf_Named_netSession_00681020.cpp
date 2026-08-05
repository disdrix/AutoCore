// =============================================================================
// Named_CalleeOf_Named_netSession_00681020
// -----------------------------------------------------------------------------
// Stable ID: aa_00681020
// Callee of Named_netSession (+2 other named callers)
// Address:   0x00681020  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_netSession: auth/session helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_netSession (+2 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×2.
//  - Notable callees: FUN_00680e30, FUN_00681020.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_netSession (+2 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_CalleeOf_Named_netSession_00681020(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3,char param_4)



{

  uint uVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (param_4 == '\0') {

    if (param_3 != 0) {

      FUN_00680e30(param_3);

      puVar2 = (uint32_t /* width from decompiler */ *)*param_2;

      puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

      for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {

        *puVar3 = *puVar2;

        puVar2 = puVar2 + 1;

        puVar3 = puVar3 + 1;

      }

      for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {

        *(uint8_t *)puVar3 = *(uint8_t *)puVar2;

        puVar2 = (uint32_t /* width from decompiler */ *)((int)puVar2 + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

    }

    *(uint *)(param_1 + 0xc) = param_3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    return;

  }

  operator_delete__(*(void **)(param_1 + 4));

  *(uint *)(param_1 + 8) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 4) = *param_2;

  *param_2 = 0;

  *(uint *)(param_1 + 0xc) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

  return;

}
