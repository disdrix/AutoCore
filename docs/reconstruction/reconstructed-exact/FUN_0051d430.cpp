// =============================================================================
// FUN_0051d430
// -----------------------------------------------------------------------------
// Stable ID: aa_0051d430
// Address:   0x0051d430  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0051d430 @ 0x0051d430
// Stable ID: aa_0051d430
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_0051c510, FUN_0051d430.
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

void __thiscall FUN_0051d430(int param_1,uint32_t /* width from decompiler */ *param_2,int *param_3)



{

  bool bVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar1 = true;

  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar3[1];

    do {

      puVar3 = puVar2;

      bVar1 = *param_3 < (int)puVar3[3];

      if (bVar1) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar3;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar3[2];

      }

    } while (*(char *)((int)puVar2 + 0x15) == '\0');

  }

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_0051c510(&param_3,bVar1,puVar3,param_3);

  *param_2 = *puVar3;

  *(uint8_t *)(param_2 + 1) = 1;

  return;

}
