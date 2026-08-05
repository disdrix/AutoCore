// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGChat_0067b1d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0067b1d0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGChat
// Address:   0x0067b1d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOGChat: social/chat helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: inet_addr×2, FUN_0067b1d0, FUN_006847f0, htonl, htons.
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOGChat
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

uint32_t /* width from decompiler */ __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOGChat_0067b1d0(uint32_t /* width from decompiler */ *param_1,int param_2,u_short param_3,char param_4)



{

  u_short uVar1;

  ulong uVar2;

  u_long hostlong;

  

  if (param_4 == '\0') {

    if (*(uint *)(param_2 + 0x18) < 0x10) {

      uVar2 = inet_addr((char *)(param_2 + 4));

    }

    else {

      uVar2 = inet_addr(*(char **)(param_2 + 4));

    }

  }

  else {

    if (*(uint *)(param_2 + 0x18) < 0x10) {

      param_2 = param_2 + 4;

    }

    else {

      param_2 = *(int *)(param_2 + 4);

    }

    hostlong = FUN_006847f0(param_2);

    if (hostlong == 0xffffffff) {

      return 0xffffffff;

    }

    uVar2 = htonl(hostlong);

  }

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[1] = uVar2;

  *(uint16_t *)param_1 = 2;

  uVar1 = htons(param_3);

  *(u_short *)((int)param_1 + 2) = uVar1;

  return 0;

}
