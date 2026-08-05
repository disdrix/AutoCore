// =============================================================================
// FUN_00471fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00471fa0
// Address:   0x00471fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00471fa0 @ 0x00471fa0
// Stable ID: aa_00471fa0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×7, return×4, do×3, while×3, for×1.
//  - Notable callees: FUN_00471fa0.
//  - Return sites: 4.

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

void __fastcall FUN_00471fa0(int param_1)



{

  uint8_t *puVar1;

  uint8_t uVar2;

  uint8_t uVar3;

  int *in_EAX;

  uint8_t *puVar4;

  uint8_t *puVar5;

  int iVar6;

  

  iVar6 = *in_EAX;

  if ((char)in_EAX[2] == '\x06') {

    if (*(char *)((int)in_EAX + 9) == '\b') {

      puVar4 = (uint8_t *)(in_EAX[1] + param_1);

      puVar5 = puVar4;

      if (iVar6 != 0) {

        do {

          uVar2 = puVar4[-1];

          puVar5[-1] = puVar4[-2];

          puVar5[-2] = puVar4[-3];

          puVar1 = puVar4 + -4;

          puVar4 = puVar4 + -4;

          puVar5[-3] = *puVar1;

          iVar6 = iVar6 + -1;

          puVar5[-4] = uVar2;

          puVar5 = puVar5 + -4;

        } while (iVar6 != 0);

        return;

      }

    }

    else {

      puVar4 = (uint8_t *)(in_EAX[1] + param_1);

      puVar5 = puVar4;

      if (iVar6 != 0) {

        do {

          uVar2 = puVar4[-1];

          uVar3 = puVar4[-2];

          puVar5[-1] = puVar4[-3];

          puVar5[-2] = puVar4[-4];

          puVar5[-3] = puVar4[-5];

          puVar5[-4] = puVar4[-6];

          puVar5[-5] = puVar4[-7];

          puVar1 = puVar4 + -8;

          puVar4 = puVar4 + -8;

          puVar5[-6] = *puVar1;

          puVar5[-7] = uVar2;

          iVar6 = iVar6 + -1;

          puVar5[-8] = uVar3;

          puVar5 = puVar5 + -8;

        } while (iVar6 != 0);

        return;

      }

    }

  }

  else if ((char)in_EAX[2] == '\x04') {

    if (*(char *)((int)in_EAX + 9) == '\b') {

      puVar4 = (uint8_t *)(in_EAX[1] + param_1);

      puVar5 = puVar4;

      if (iVar6 != 0) {

        do {

          uVar2 = puVar4[-1];

          puVar1 = puVar4 + -2;

          puVar4 = puVar4 + -2;

          puVar5[-1] = *puVar1;

          iVar6 = iVar6 + -1;

          puVar5[-2] = uVar2;

          puVar5 = puVar5 + -2;

        } while (iVar6 != 0);

        return;

      }

    }

    else {

      puVar5 = (uint8_t *)(in_EAX[1] + param_1);

      puVar4 = puVar5;

      for (; iVar6 != 0; iVar6 = iVar6 + -1) {

        uVar2 = puVar5[-1];

        uVar3 = puVar5[-2];

        puVar4[-1] = puVar5[-3];

        puVar1 = puVar5 + -4;

        puVar5 = puVar5 + -4;

        puVar4[-2] = *puVar1;

        puVar4[-3] = uVar2;

        puVar4 = puVar4 + -4;

        *puVar4 = uVar3;

      }

    }

  }

  return;

}
