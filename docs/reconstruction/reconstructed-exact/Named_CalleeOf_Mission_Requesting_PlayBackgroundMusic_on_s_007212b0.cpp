// =============================================================================
// Named_CalleeOf_Mission_Requesting_PlayBackgroundMusic_on_s_007212b0
// -----------------------------------------------------------------------------
// Stable ID: aa_007212b0
// Callee of Mission_Requesting_PlayBackgroundMusic_on_s
// Address:   0x007212b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Mission_Requesting_PlayBackgroundMusic_on_s: mission/objective helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, while×1.
//  - Notable callees: CVOGReaction_RandomUnitScalar, FUN_004248c0, FUN_007212b0.
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Mission_Requesting_PlayBackgroundMusic_on_s
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

uint Named_CalleeOf_Mission_Requesting_PlayBackgroundMusic_on_s_007212b0(void)



{

  int in_EAX;

  int iVar1;

  uint uVar2;

  int iVar3;

  

  if (*(int *)(in_EAX + 0x44) != 0) {

    if ((*(int *)(in_EAX + 0x48) - *(int *)(in_EAX + 0x44)) / 200 != 0) {

      uVar2 = 0;

      iVar3 = 0;

      while( true ) {

        if (*(int *)(in_EAX + 0x44) == 0) {

          iVar1 = 0;

        }

        else {

          iVar1 = (*(int *)(in_EAX + 0x48) - *(int *)(in_EAX + 0x44)) / 200;

        }

        if (iVar1 <= (int)uVar2) break;

        iVar1 = *(int *)(in_EAX + 0x44) + iVar3;

        if ((*(int *)(iVar1 + 0xb8) != 0) && (*(char *)(iVar1 + 0xbc) != '\0')) {

          return uVar2;

        }

        uVar2 = uVar2 + 1;

        iVar3 = iVar3 + 200;

      }

      iVar3 = CVOGReaction_RandomUnitScalar();

      iVar3 = *(int *)(iVar3 + 0x14);

      if (*(int *)(iVar3 + 0x9c4) == 0) {

        FUN_004248c0();

      }

      *(int *)(iVar3 + 0x9c4) = *(int *)(iVar3 + 0x9c4) + -1;

      uVar2 = **(uint **)(iVar3 + 0x9c0);

      uVar2 = uVar2 ^ uVar2 >> 0xb;

      *(uint **)(iVar3 + 0x9c0) = *(uint **)(iVar3 + 0x9c0) + 1;

      uVar2 = uVar2 ^ (uVar2 & 0xff3a58ad) << 7;

      uVar2 = uVar2 ^ (uVar2 & 0xffffdf8c) << 0xf;

      if (*(int *)(in_EAX + 0x44) == 0) {

        return (uVar2 >> 0x12 ^ uVar2) % 0;

      }

      return (uVar2 >> 0x12 ^ uVar2) %

             (uint)((*(int *)(in_EAX + 0x48) - *(int *)(in_EAX + 0x44)) / 200);

    }

  }

  return 0xffffffff;

}
