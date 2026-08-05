// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004a9a20
// -----------------------------------------------------------------------------
// Stable ID: aa_004a9a20
// Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
// Address:   0x004a9a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: CONCAT31×3, CVOGReaction_RandomUnitScalar×3, block×2, FUN_004a9a20.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP
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

/* WARNING: Removing unreachable block (ram,0x004a9a83) */

/* WARNING: Removing unreachable block (ram,0x004a9acb) */



uint Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_ST_004a9a20(void)



{

  ushort uVar1;

  uint16_t uVar2;

  ulonglong uVar3;

  int iVar4;

  uint uVar5;

  byte bVar6;

  

  iVar4 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar4 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

  if ((char)((ulonglong)uVar1 % 10) == '\0') {

    iVar4 = CVOGReaction_RandomUnitScalar();

    if (0xfffff < *(int *)(iVar4 + 0xc)) {

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

    }

    uVar2 = *(uint16_t *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

    *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

    return (uint)(byte)(((byte)uVar2 & 7) + 0x18);

  }

  iVar4 = CVOGReaction_RandomUnitScalar();

  if (0xfffff < *(int *)(iVar4 + 0xc)) {

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0xc) = 0;

  }

  uVar1 = *(ushort *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 0xc) * 2);

  *(int *)(iVar4 + 0xc) = *(int *)(iVar4 + 0xc) + 1;

  uVar3 = (ulonglong)uVar1;

  bVar6 = (byte)(uVar3 % 10);

  if (7 < bVar6) {

    uVar5 = CONCAT31((int3)(-((int)(char)bVar6 & 0x80000001U) >> 8),

                     -(((int)(char)bVar6 & 0x80000001U) != 0)) & 0xfffffff1;

    return CONCAT31((int3)(uVar5 >> 8),(char)uVar5 + '\x0f');

  }

  return CONCAT31((int3)(uVar3 / 10 >> 8),bVar6 + 0x10);

}
