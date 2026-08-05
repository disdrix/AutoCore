// =============================================================================
// Named_CalleeOf_Named_hkWorld_006cb5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006cb5e0
// Callee of Named_hkWorld
// Address:   0x006cb5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_hkWorld: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: do×3, while×3, if×1, return×1.
//  - Notable callees: FUN_006cafd0, FUN_006cb5e0.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_hkWorld
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

uint32_t /* width from decompiler */ * __thiscall Named_CalleeOf_Named_hkWorld_006cb5e0(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ param_2,int param_3)



{

  int *piVar1;

  byte bVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  param_1[2] = param_2;

  *(uint16_t *)((int)param_1 + 6) = 1;

  *param_1 = &PTR_FUN_00a0d914;

  iVar3 = 0;

  param_1[0x1364] = 0;

  param_1[0x1365] = 0;

  param_1[0x1366] = 0x80000000;

  param_1[0x1369] = 0x80000000;

  param_1[0x1367] = 0;

  param_1[0x1368] = 0;

  *(uint8_t *)(param_1 + 0x1363) = 0;

  *(uint8_t *)((int)param_1 + 0x4d8d) = 1;

  piVar1 = param_1 + 3;

  iVar4 = 8;

  do {

    iVar5 = 8;

    do {

      *piVar1 = param_3;

      if (param_3 != 0) {

        *(short *)(param_3 + 6) = *(short *)(param_3 + 6) + 1;

      }

      piVar1 = piVar1 + 1;

      iVar5 = iVar5 + -1;

    } while (iVar5 != 0);

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

  piVar1 = param_1 + 0x43;

  do {

    bVar2 = (byte)iVar3;

    iVar3 = iVar3 + 1;

    *piVar1 = 1 << (bVar2 & 0x1f);

    piVar1 = piVar1 + 1;

  } while (iVar3 < 0x20);

  FUN_006cafd0();

  return param_1;

}
