// =============================================================================
// FUN_0046d070
// -----------------------------------------------------------------------------
// Stable ID: aa_0046d070
// Address:   0x0046d070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046d070 @ 0x0046d070
// Stable ID: aa_0046d070
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0046d070.
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

void __fastcall FUN_0046d070(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ *param_2)



{

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  int iVar3;

  

  *in_EAX = *param_2;

  in_EAX[1] = param_2[1];

  in_EAX[2] = param_2[2];

  in_EAX[3] = param_2[3];

  in_EAX[4] = param_2[4];

  in_EAX[5] = param_2[5];

  in_EAX[6] = param_2[6];

  in_EAX[7] = param_2[7];

  in_EAX[8] = param_2[8];

  in_EAX[9] = param_2[9];

  in_EAX[10] = param_2[10];

  puVar1 = in_EAX + 0xb;

  iVar2 = (int)param_2 + (0x2c - (int)puVar1);

  iVar3 = 3;

  do {

    *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar2 + (int)puVar1);

    puVar1[1] = *(uint32_t /* width from decompiler */ *)(iVar2 + 4 + (int)puVar1);

    puVar1 = puVar1 + 2;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  in_EAX[0x11] = param_2[0x11];

  in_EAX[0x12] = param_2[0x12];

  in_EAX[0x13] = param_2[0x13];

  return;

}
