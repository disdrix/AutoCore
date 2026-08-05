// =============================================================================
// FUN_00638370
// -----------------------------------------------------------------------------
// Stable ID: aa_00638370
// Address:   0x00638370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00638370 @ 0x00638370
// Stable ID: aa_00638370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: for×3, while×1, return×1.
//  - Notable callees: FUN_00638370.
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

void __fastcall FUN_00638370(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ *param_3,int param_4)



{

  byte *pbVar1;

  byte *in_EAX;

  uint uVar2;

  int iVar3;

  byte *pbVar4;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar5;

  

  puVar5 = param_3;

  for (uVar2 = (uint)(unaff_EBX << 10) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar5 = 0;

    puVar5 = puVar5 + 1;

  }

  pbVar4 = in_EAX + param_2 * param_4;

  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {

    *(uint8_t *)puVar5 = 0;

    puVar5 = (uint32_t /* width from decompiler */ *)((int)puVar5 + 1);

  }

  while (in_EAX != pbVar4) {

    pbVar1 = in_EAX + unaff_EBX;

    puVar5 = param_3;

    for (; in_EAX != pbVar1; in_EAX = in_EAX + 1) {

      puVar5[*in_EAX] = puVar5[*in_EAX] + 1;

      puVar5 = puVar5 + 0x100;

    }

  }

  return;

}
