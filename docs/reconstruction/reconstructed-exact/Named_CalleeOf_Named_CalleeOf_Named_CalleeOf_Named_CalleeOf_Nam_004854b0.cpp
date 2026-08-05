// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004854b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004854b0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x004854b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_004854b0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004854b0(void)



{

  int iVar1;

  char *pcVar2;

  int in_EAX;

  char cVar3;

  int iVar4;

  

  iVar1 = in_EAX + 0xc6d;

  iVar4 = 0;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc68) = 0;

  do {

    pcVar2 = (char *)(iVar1 + iVar4);

    cVar3 = (char)iVar4;

    if (pcVar2[(in_EAX - iVar1) + 0xc6c] != '\0') {

      *(char *)(in_EAX + 0xd7c + *(int *)(in_EAX + 0xc68)) = cVar3;

      *(int *)(in_EAX + 0xc68) = *(int *)(in_EAX + 0xc68) + 1;

    }

    if (*pcVar2 != '\0') {

      *(char *)(in_EAX + 0xd7c + *(int *)(in_EAX + 0xc68)) = cVar3 + '\x01';

      *(int *)(in_EAX + 0xc68) = *(int *)(in_EAX + 0xc68) + 1;

    }

    if (pcVar2[(in_EAX - iVar1) + 0xc6e] != '\0') {

      *(char *)(in_EAX + 0xd7c + *(int *)(in_EAX + 0xc68)) = cVar3 + '\x02';

      *(int *)(in_EAX + 0xc68) = *(int *)(in_EAX + 0xc68) + 1;

    }

    if (pcVar2[(in_EAX - iVar1) + 0xc6f] != '\0') {

      *(char *)(in_EAX + 0xd7c + *(int *)(in_EAX + 0xc68)) = cVar3 + '\x03';

      *(int *)(in_EAX + 0xc68) = *(int *)(in_EAX + 0xc68) + 1;

    }

    iVar4 = iVar4 + 4;

  } while (iVar4 < 0x100);

  return;

}
