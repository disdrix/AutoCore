// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0047eb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0047eb20
// Callee of Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag
// Address:   0x0047eb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0047f540×2, FUN_0047eb20.
//  - Return sites: 2.

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

void __thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_0047eb20(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int in_EAX;

  

  iVar1 = *(int *)(in_EAX + 0x16b4);

  if (0xd < iVar1) {

    *(ushort *)(in_EAX + 0x16b0) =

         *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_1 << ((byte)iVar1 & 0x1f));

    *(uint8_t *)(*(int *)(in_EAX + 8) + *(int *)(in_EAX + 0x14)) =

         *(uint8_t *)(in_EAX + 0x16b0);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(uint8_t *)(*(int *)(in_EAX + 0x14) + *(int *)(in_EAX + 8)) =

         *(uint8_t *)(in_EAX + 0x16b1);

    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 1;

    *(ushort *)(in_EAX + 0x16b0) =

         (ushort)param_1 >> (0x10U - (char)*(int *)(in_EAX + 0x16b4) & 0x1f);

    *(int *)(in_EAX + 0x16b4) = *(int *)(in_EAX + 0x16b4) + -0xd;

    FUN_0047f540(param_2,1);

    return;

  }

  *(int *)(in_EAX + 0x16b4) = iVar1 + 3;

  *(ushort *)(in_EAX + 0x16b0) =

       *(ushort *)(in_EAX + 0x16b0) | (ushort)(param_1 << ((byte)iVar1 & 0x1f));

  FUN_0047f540(param_2,1);

  return;

}
