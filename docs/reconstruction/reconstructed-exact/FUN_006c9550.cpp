// =============================================================================
// FUN_006c9550
// -----------------------------------------------------------------------------
// Stable ID: aa_006c9550
// Address:   0x006c9550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006c9550 @ 0x006c9550
// Stable ID: aa_006c9550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~63 non-empty decompiler lines.
//  - Control keywords: if×9, do×1, while×1, return×1.
//  - Notable callees: FUN_006c9550.
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

void __thiscall FUN_006c9550(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,float *param_4)



{

  float fVar1;

  float unaff_EBX;

  int iVar2;

  float unaff_ESI;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  

  (**(code **)(*(int *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xc) + 0x18))(param_2,param_3,param_4);

  iVar2 = 1;

  if (1 < *(int *)(param_1 + 0x10)) {

    do {

      (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + iVar2 * 8) + 0x18))

                (param_2,param_3,&stack0xffffffc4);

      fVar1 = unaff_ESI;

      if (*param_4 < unaff_ESI) {

        fVar1 = *param_4;

      }

      *param_4 = fVar1;

      fVar1 = unaff_EBX;

      if (param_4[1] < unaff_EBX) {

        fVar1 = param_4[1];

      }

      param_4[1] = fVar1;

      fVar1 = fStack_34;

      if (param_4[2] < fStack_34) {

        fVar1 = param_4[2];

      }

      param_4[2] = fVar1;

      fVar1 = fStack_30;

      if (param_4[3] < fStack_30) {

        fVar1 = param_4[3];

      }

      param_4[3] = fVar1;

      fVar1 = fStack_2c;

      if (fStack_2c < param_4[4]) {

        fVar1 = param_4[4];

      }

      param_4[4] = fVar1;

      fVar1 = fStack_28;

      if (fStack_28 < param_4[5]) {

        fVar1 = param_4[5];

      }

      param_4[5] = fVar1;

      fVar1 = fStack_24;

      if (fStack_24 < param_4[6]) {

        fVar1 = param_4[6];

      }

      param_4[6] = fVar1;

      fVar1 = fStack_20;

      if (fStack_20 < param_4[7]) {

        fVar1 = param_4[7];

      }

      param_4[7] = fVar1;

      iVar2 = iVar2 + 1;

    } while (iVar2 < *(int *)(param_1 + 0x10));

  }

  return;

}
