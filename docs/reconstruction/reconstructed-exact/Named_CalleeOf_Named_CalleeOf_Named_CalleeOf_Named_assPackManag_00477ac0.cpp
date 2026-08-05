// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00477ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_00477ac0
// Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
// Address:   0x00477ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_CalleeOf_Named_assPackManager: callee helper. Evidence string: "stream error". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "stream error"
//   - "buffer error"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~159 non-empty decompiler lines.
//  - Control keywords: if×26, return×9, goto×5, for×2.
//  - Notable callees: FUN_00477a30×5, FUN_00477a60×3, FUN_00477ac0, FUN_0047eb20, FUN_0047ebc0.
//  - Strings: "stream error"; "buffer error".
//  - Return sites: 9.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_CalleeOf_Named_assPackManager
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

uint Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_assPackManag_00477ac0(int *param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint8_t uVar2;

  int iVar3;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  if ((((param_1 == (int *)0x0) || (puVar1 = (uint32_t /* width from decompiler */ *)param_1[7], puVar1 == (uint32_t /* width from decompiler */ *)0x0))

      || (4 < param_2)) || (param_2 < 0)) {

    return 0xfffffffe;

  }

  if (((param_1[3] == 0) || ((*param_1 == 0 && (param_1[1] != 0)))) ||

     ((puVar1[1] == 0x29a && (param_2 != 4)))) {

    param_1[6] = (int)"stream error";

    return 0xfffffffe;

  }

  if (param_1[4] == 0) {

    param_1[6] = (int)"buffer error";

    return 0xfffffffb;

  }

  iVar3 = puVar1[8];

  *puVar1 = param_1;

  puVar1[8] = param_2;

  if (puVar1[1] == 0x2a) {

    if (puVar1[6] == 2) {

      *(uint8_t *)(puVar1[2] + puVar1[5]) = 0x1f;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 0x8b;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 8;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 0;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 0;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 0;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 0;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 0;

      puVar1[5] = puVar1[5] + 1;

      if (puVar1[0x1f] == 9) {

        uVar2 = 2;

      }

      else if (((int)puVar1[0x20] < 2) && (1 < (int)puVar1[0x1f])) {

        uVar2 = 0;

      }

      else {

        uVar2 = 4;

      }

      *(uint8_t *)(puVar1[5] + puVar1[2]) = uVar2;

      puVar1[5] = puVar1[5] + 1;

      *(uint8_t *)(puVar1[5] + puVar1[2]) = 0xff;

      puVar1[5] = puVar1[5] + 1;

      puVar1[1] = 0x71;

      param_1[0xc] = 0;

    }

    else {

      puVar1[1] = 0x71;

      FUN_00477a30();

      if (puVar1[0x19] != 0) {

        FUN_00477a30();

        FUN_00477a30();

      }

      param_1[0xc] = 1;

    }

  }

  if (puVar1[5] == 0) {

    if (((param_1[1] == 0) && (param_2 <= iVar3)) && (param_2 != 4)) goto LAB_00477cd6;

LAB_00477cc6:

    if (puVar1[1] == 0x29a) {

      if (param_1[1] != 0) {

LAB_00477cd6:

        param_1[6] = (int)"buffer error";

        return 0xfffffffb;

      }

LAB_00477ced:

      if ((puVar1[0x1b] != 0) || ((param_2 != 0 && (puVar1[1] != 0x29a)))) goto LAB_00477d06;

    }

    else {

      if (param_1[1] == 0) goto LAB_00477ced;

LAB_00477d06:

      iVar3 = (**(code **)(&DAT_00a26768 + puVar1[0x1f] * 0xc))(puVar1,param_2);

      if ((iVar3 == 2) || (iVar3 == 3)) {

        puVar1[1] = 0x29a;

      }

      if ((iVar3 == 0) || (iVar3 == 2)) {

        if (param_1[4] != 0) {

          return 0;

        }

        puVar1[8] = 0xffffffff;

        return 0;

      }

      if (iVar3 == 1) {

        if (param_2 == 1) {

          FUN_0047ebc0();

        }

        else {

          FUN_0047eb20(0,0);

          if (param_2 == 3) {

            *(uint16_t *)(puVar1[0xf] + -2 + puVar1[0x11] * 2) = 0;

            uVar5 = puVar1[0x11] * 2 - 2;

            puVar6 = (uint32_t /* width from decompiler */ *)puVar1[0xf];

            for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

              *puVar6 = 0;

              puVar6 = puVar6 + 1;

            }

            for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {

              *(uint8_t *)puVar6 = 0;

              puVar6 = (uint32_t /* width from decompiler */ *)((int)puVar6 + 1);

            }

          }

        }

        FUN_00477a60();

        if (param_1[4] == 0) goto LAB_00477ca7;

      }

    }

    if (param_2 == 4) {

      if ((int)puVar1[6] < 1) {

        return 1;

      }

      if (puVar1[6] == 2) {

        *(char *)(puVar1[2] + puVar1[5]) = (char)param_1[0xc];

        puVar1[5] = puVar1[5] + 1;

        *(uint8_t *)(puVar1[5] + puVar1[2]) = *(uint8_t *)((int)param_1 + 0x31);

        puVar1[5] = puVar1[5] + 1;

        *(uint8_t *)(puVar1[5] + puVar1[2]) = *(uint8_t *)((int)param_1 + 0x32);

        puVar1[5] = puVar1[5] + 1;

        *(uint8_t *)(puVar1[5] + puVar1[2]) = *(uint8_t *)((int)param_1 + 0x33);

        puVar1[5] = puVar1[5] + 1;

        *(char *)(puVar1[5] + puVar1[2]) = (char)param_1[2];

        puVar1[5] = puVar1[5] + 1;

        *(uint8_t *)(puVar1[5] + puVar1[2]) = *(uint8_t *)((int)param_1 + 9);

        puVar1[5] = puVar1[5] + 1;

        *(uint8_t *)(puVar1[5] + puVar1[2]) = *(uint8_t *)((int)param_1 + 10);

        puVar1[5] = puVar1[5] + 1;

        *(uint8_t *)(puVar1[5] + puVar1[2]) = *(uint8_t *)((int)param_1 + 0xb);

        puVar1[5] = puVar1[5] + 1;

      }

      else {

        FUN_00477a30();

        FUN_00477a30();

      }

      FUN_00477a60();

      if (0 < (int)puVar1[6]) {

        puVar1[6] = -puVar1[6];

      }

      return (uint)(puVar1[5] == 0);

    }

  }

  else {

    FUN_00477a60();

    if (param_1[4] != 0) goto LAB_00477cc6;

LAB_00477ca7:

    puVar1[8] = 0xffffffff;

  }

  return 0;

}
