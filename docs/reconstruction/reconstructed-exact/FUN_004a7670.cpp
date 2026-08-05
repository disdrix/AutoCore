// =============================================================================
// FUN_004a7670
// -----------------------------------------------------------------------------
// Stable ID: aa_004a7670
// Address:   0x004a7670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004a7670 @ 0x004a7670
// Stable ID: aa_004a7670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, do×1, while×1, return×1.
//  - Notable callees: FUN_004a6d80, FUN_004a7670.
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

void __thiscall FUN_004a7670(int param_1,uint32_t /* width from decompiler */ *param_2,uint *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  bool bVar3;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  bVar3 = true;

  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar2[1];

    do {

      puVar2 = puVar1;

      bVar3 = *param_3 < (uint)puVar2[3];

      if (bVar3) {

        puVar1 = (uint32_t /* width from decompiler */ *)*puVar2;

      }

      else {

        puVar1 = (uint32_t /* width from decompiler */ *)puVar2[2];

      }

    } while (*(char *)((int)puVar1 + 0x15) == '\0');

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_004a6d80(&param_3,bVar3,puVar2,param_3);

  *param_2 = *puVar2;

  *(uint8_t *)(param_2 + 1) = 1;

  return;

}
