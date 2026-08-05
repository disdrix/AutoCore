// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004820a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004820a0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x004820a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_004820a0.
//  - Return sites: 3.

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

void Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_004820a0(void)



{

  byte bVar1;

  int in_EAX;

  int iVar2;

  

  bVar1 = *(byte *)(in_EAX + 0x34);

  iVar2 = 0;

  if (0 < *(int *)(in_EAX + 0x38)) {

    do {

      iVar2 = iVar2 + 1;

      *(uint *)(in_EAX + 0x260) =

           *(uint *)(in_EAX + 0x260) << 8 ^

           *(uint *)(&DAT_00afd5e8 + (*(uint *)(in_EAX + 0x260) >> 0x18 ^ (uint)bVar1) * 4);

    } while (iVar2 < *(int *)(in_EAX + 0x38));

  }

  *(uint8_t *)(in_EAX + 0x58 + *(int *)(in_EAX + 0x34)) = 1;

  iVar2 = *(int *)(in_EAX + 0x38);

  if (iVar2 == 1) {

    *(byte *)(*(int *)(in_EAX + 0x24) + *(int *)(in_EAX + 0x44)) = bVar1;

    *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

    return;

  }

  if (iVar2 != 2) {

    if (iVar2 != 3) {

      *(uint8_t *)(iVar2 + 0x54 + in_EAX) = 1;

      *(byte *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = bVar1;

      *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

      *(byte *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = bVar1;

      *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

      *(byte *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = bVar1;

      *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

      *(byte *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = bVar1;

      *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

      *(char *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = *(char *)(in_EAX + 0x38) + -4;

      *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

      return;

    }

    *(byte *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = bVar1;

    *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

  }

  *(byte *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = bVar1;

  *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

  *(byte *)(*(int *)(in_EAX + 0x44) + *(int *)(in_EAX + 0x24)) = bVar1;

  *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x44) + 1;

  return;

}
