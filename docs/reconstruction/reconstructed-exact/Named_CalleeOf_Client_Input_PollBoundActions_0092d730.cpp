// =============================================================================
// Named_CalleeOf_Client_Input_PollBoundActions_0092d730
// -----------------------------------------------------------------------------
// Stable ID: aa_0092d730
// Callee of Client_Input_PollBoundActions
// Address:   0x0092d730  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_PollBoundActions: input/binding helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, while×1.
//  - Notable callees: FUN_0092d730.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Client_Input_PollBoundActions
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

void Named_CalleeOf_Client_Input_PollBoundActions_0092d730(void)



{

  int iVar1;

  int in_EAX;

  uint uVar2;

  byte bVar3;

  uint uVar4;

  

  *(char *)(in_EAX + 0x4f8) = *(char *)(in_EAX + 0x4f8) + '\x01';

  bVar3 = *(byte *)(in_EAX + 0x4f8);

  iVar1 = *(int *)(in_EAX + 0xe04);

  uVar4 = 0;

  while( true ) {

    if (*(int *)(iVar1 + 0xe75c) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = *(int *)(iVar1 + 0xe760) - *(int *)(iVar1 + 0xe75c) >> 2;

    }

    if (uVar2 <= uVar4) {

      return;

    }

    if (*(int *)(iVar1 + 0xe75c) == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = *(int *)(iVar1 + 0xe760) - *(int *)(iVar1 + 0xe75c) >> 2;

    }

    if (uVar2 <= bVar3) {

      *(uint8_t *)(in_EAX + 0x4f8) = 0;

    }

    if (*(int *)(*(int *)(iVar1 + 0xe75c) + (uint)*(byte *)(in_EAX + 0x4f8) * 4) !=

        *(int *)(in_EAX + 0xe98)) break;

    bVar3 = *(byte *)(in_EAX + 0x4f8) + 1;

    *(byte *)(in_EAX + 0x4f8) = bVar3;

    uVar4 = (uint)(byte)((char)uVar4 + 1);

  }

  iVar1 = *(int *)(*(int *)(iVar1 + 0xe75c) + (uint)*(byte *)(in_EAX + 0x4f8) * 4);

  if (iVar1 != 0) {

    *(int *)(in_EAX + 0xe08) = *(int *)(*(int *)(iVar1 + 4) + 4) + 4 + iVar1;

    return;

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xe08) = 0;

  return;

}
