// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00775b30
// -----------------------------------------------------------------------------
// Stable ID: aa_00775b30
// Callee of Named_CalleeOf_Named_ecc_sys
// Address:   0x00775b30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_ecc_sys: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×12, goto×9, while×4, return×3, do×1.
//  - Notable callees: FUN_007716f0×5, FUN_00772190×4, FUN_00770650×3, FUN_00770250, FUN_00770540, FUN_00770770, FUN_007707a0, FUN_00771cb0.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_ecc_sys
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

int Named_CalleeOf_Named_CalleeOf_Named_ecc_sys_00775b30(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int extraout_ECX;

  bool bVar3;

  int *piVar4;

  int local_60 [2];

  int local_58;

  byte *local_54;

  int local_50 [3];

  byte *local_44;

  int local_40 [3];

  byte *local_34;

  int local_30 [3];

  byte *local_24;

  uint8_t local_20 [16];

  uint8_t local_10 [16];

  

  if ((0 < *param_2) && ((*(byte *)param_2[3] & 1) == 0)) {

    return -3;

  }

  iVar2 = FUN_00771cb0(local_20,local_10,local_40,local_50,local_30,local_60,0);

  if (iVar2 != 0) {

    return iVar2;

  }

  iVar2 = FUN_00770650();

  if ((((iVar2 == 0) && (iVar2 = FUN_00774f50(param_1,local_10), iVar2 == 0)) &&

      (iVar2 = FUN_00770650(), iVar2 == 0)) && (iVar2 = FUN_00770650(), iVar2 == 0)) {

    FUN_00770250();

    do {

      bVar3 = local_40[0] == 0;

      while ((bVar3 || local_40[0] < 0 || ((*local_34 & 1) != 0))) {

        while ((0 < local_50[0] && ((*local_44 & 1) == 0))) {

          iVar2 = FUN_00772190(local_50);

          if (((iVar2 != 0) ||

              (((0 < local_60[0] && ((*local_54 & 1) != 0)) &&

               (iVar2 = FUN_007716f0(local_60), iVar2 != 0)))) ||

             (iVar2 = FUN_00772190(local_60), iVar2 != 0)) goto LAB_00775d94;

        }

        iVar2 = FUN_007707a0();

        if (iVar2 == -1) {

          iVar2 = FUN_007716f0(local_50);

          if (iVar2 != 0) goto LAB_00775d94;

          piVar4 = local_60;

        }

        else {

          iVar2 = FUN_007716f0(local_40);

          if (iVar2 != 0) goto LAB_00775d94;

          piVar4 = local_30;

        }

        iVar2 = FUN_007716f0(piVar4);

        if (iVar2 != 0) goto LAB_00775d94;

        bVar3 = false;

        if (local_40[0] == 0) {

          iVar2 = FUN_00770770();

          if (iVar2 != 0) {

            iVar2 = -3;

            goto LAB_00775d94;

          }

          uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 8);

          if (local_58 == extraout_ECX) goto LAB_00775d65;

          goto LAB_00775d81;

        }

      }

      iVar2 = FUN_00772190(local_40);

    } while (((iVar2 == 0) &&

             (((local_30[0] < 1 || ((*local_24 & 1) == 0)) ||

              (iVar2 = FUN_007716f0(local_30), iVar2 == 0)))) &&

            (iVar2 = FUN_00772190(local_30), iVar2 == 0));

  }

  goto LAB_00775d94;

  while (local_58 == 1) {

LAB_00775d65:

    iVar2 = FUN_00772390();

    if (iVar2 != 0) goto LAB_00775d94;

  }

LAB_00775d81:

  iVar2 = FUN_00770540();

  *(uint32_t /* width from decompiler */ *)(iVar2 + 8) = uVar1;

  iVar2 = 0;

LAB_00775d94:

  FUN_00772250(local_20,local_10,local_40,local_50,local_30,local_60,0);

  return iVar2;

}
