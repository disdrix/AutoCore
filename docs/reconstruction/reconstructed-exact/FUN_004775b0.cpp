// =============================================================================
// FUN_004775b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004775b0
// Address:   0x004775b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004775b0 @ 0x004775b0
// Stable ID: aa_004775b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~68 non-empty decompiler lines.
//  - Control keywords: if×9, do×4, while×4, return×4.
//  - Notable callees: FUN_004775b0.
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

void __fastcall FUN_004775b0(uint32_t /* width from decompiler */ param_1,int *param_2)



{

  byte bVar1;

  uint8_t uVar2;

  uint8_t *in_EAX;

  uint8_t *puVar3;

  int iVar4;

  

  bVar1 = *(byte *)(param_2 + 2);

  if ((bVar1 & 2) != 0) {

    iVar4 = *param_2;

    if (*(char *)((int)param_2 + 9) == '\b') {

      if (bVar1 == 2) {

        if (iVar4 != 0) {

          do {

            uVar2 = *in_EAX;

            *in_EAX = in_EAX[2];

            in_EAX[2] = uVar2;

            in_EAX = in_EAX + 3;

            iVar4 = iVar4 + -1;

          } while (iVar4 != 0);

          return;

        }

      }

      else if ((bVar1 == 6) && (iVar4 != 0)) {

        do {

          uVar2 = *in_EAX;

          *in_EAX = in_EAX[2];

          in_EAX[2] = uVar2;

          in_EAX = in_EAX + 4;

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

        return;

      }

    }

    else if (*(char *)((int)param_2 + 9) == '\x10') {

      if (bVar1 == 2) {

        if (iVar4 != 0) {

          puVar3 = in_EAX + 1;

          do {

            uVar2 = puVar3[-1];

            puVar3[-1] = puVar3[3];

            puVar3[3] = uVar2;

            uVar2 = *puVar3;

            *puVar3 = puVar3[4];

            puVar3[4] = uVar2;

            puVar3 = puVar3 + 6;

            iVar4 = iVar4 + -1;

          } while (iVar4 != 0);

          return;

        }

      }

      else if ((bVar1 == 6) && (iVar4 != 0)) {

        puVar3 = in_EAX + 1;

        do {

          uVar2 = puVar3[-1];

          puVar3[-1] = puVar3[3];

          puVar3[3] = uVar2;

          uVar2 = *puVar3;

          *puVar3 = puVar3[4];

          puVar3[4] = uVar2;

          puVar3 = puVar3 + 8;

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

      }

    }

  }

  return;

}
