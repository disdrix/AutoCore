// =============================================================================
// FUN_004e1350
// -----------------------------------------------------------------------------
// Stable ID: aa_004e1350
// Address:   0x004e1350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004e1350 @ 0x004e1350
// Stable ID: aa_004e1350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_004e1350.
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

void __thiscall FUN_004e1350(uint8_t *param_1,char *param_2)



{

  char cVar1;

  char *pcVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x104);

  if (*param_2 == '\0') {

    *param_1 = 0;

  }

  else {

    pcVar2 = param_2;

    do {

      cVar1 = *pcVar2;

      pcVar2[(int)param_1 - (int)param_2] = cVar1;

      pcVar2 = pcVar2 + 1;

    } while (cVar1 != '\0');

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10c);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x110);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x114) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x114);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x118) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x118);

  param_1[0x11c] = param_2[0x11c];

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x120) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x120);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x124);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x128);

  *(uint32_t /* width from decompiler */ *)(param_1 + 300) = *(uint32_t /* width from decompiler */ *)(param_2 + 300);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x130) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x130);

  return;

}
