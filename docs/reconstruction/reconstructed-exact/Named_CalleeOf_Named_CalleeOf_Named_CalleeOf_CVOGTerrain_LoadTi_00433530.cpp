// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTi_00433530
// -----------------------------------------------------------------------------
// Stable ID: aa_00433530
// Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTintMap
// Address:   0x00433530  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTintMap: config/load helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~39 non-empty decompiler lines.
//  - Control keywords: if×8, return×7.
//  - Notable callees: FUN_00433530.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTintMap
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

byte __fastcall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVOGTerrain_LoadTi_00433530(uint param_1)



{

  byte bVar1;

  byte bVar2;

  int in_EAX;

  int unaff_ESI;

  

  if ((*(int *)(in_EAX + 4) == 0) || (*(int *)(in_EAX + 0x28) == 0)) {

    return 0;

  }

  if ((((-1 < (int)param_1) && (-1 < unaff_ESI)) && ((int)param_1 < *(int *)(in_EAX + 0xc))) &&

     (unaff_ESI < *(int *)(in_EAX + 0x10))) {

    if (*(short *)(in_EAX + 0x16) == 8) {

      return *(byte *)(*(int *)(in_EAX + 0x30) * unaff_ESI + *(int *)(in_EAX + 0x34) + param_1);

    }

    bVar1 = *(byte *)(((int)(*(ushort *)(in_EAX + 0x16) * param_1) >> 3) +

                      *(int *)(in_EAX + 0x30) * unaff_ESI + *(int *)(in_EAX + 0x34));

    if (*(ushort *)(in_EAX + 0x16) == 4) {

      param_1 = param_1 & 0x80000001;

      if ((int)param_1 < 0) {

        param_1 = (param_1 - 1 | 0xfffffffe) + 1;

      }

      bVar2 = ('\x01' - (char)param_1) * '\x04';

      return ('\x0f' << (bVar2 & 0x1f) & bVar1) >> (bVar2 & 0x1f);

    }

    if (*(short *)(in_EAX + 0x16) == 1) {

      param_1 = param_1 & 0x80000007;

      if ((int)param_1 < 0) {

        param_1 = (param_1 - 1 | 0xfffffff8) + 1;

      }

      bVar2 = 7 - (char)param_1;

      return ('\x01' << (bVar2 & 0x1f) & bVar1) >> (bVar2 & 0x1f);

    }

    return 0;

  }

  if (*(int *)(in_EAX + 0x14c) != -1) {

    return *(byte *)(in_EAX + 0x14c);

  }

  return **(byte **)(in_EAX + 0x34);

}
