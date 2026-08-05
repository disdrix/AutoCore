// =============================================================================
// FUN_00474fb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00474fb0
// Address:   0x00474fb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00474fb0 @ 0x00474fb0
// Stable ID: aa_00474fb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: if×9, return×4, do×2, while×2.
//  - Notable callees: CONCAT11×4, FUN_00474fb0.
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

void __fastcall FUN_00474fb0(int param_1)



{

  byte bVar1;

  int *in_EAX;

  char *pcVar2;

  uint8_t *puVar3;

  int iVar4;

  uint uVar5;

  uint uVar6;

  int iVar7;

  

  bVar1 = *(byte *)(in_EAX + 2);

  if ((bVar1 & 2) != 0) {

    iVar4 = *in_EAX;

    if (*(char *)((int)in_EAX + 9) == '\b') {

      if (bVar1 == 2) {

        iVar7 = 3;

      }

      else {

        if (bVar1 != 6) {

          return;

        }

        iVar7 = 4;

      }

      if (iVar4 != 0) {

        pcVar2 = (char *)(param_1 + 2);

        do {

          pcVar2[-2] = pcVar2[-2] + pcVar2[-1];

          *pcVar2 = *pcVar2 + pcVar2[-1];

          pcVar2 = pcVar2 + iVar7;

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

        return;

      }

    }

    else if (*(char *)((int)in_EAX + 9) == '\x10') {

      if (bVar1 == 2) {

        iVar7 = 6;

      }

      else {

        if (bVar1 != 6) {

          return;

        }

        iVar7 = 8;

      }

      if (iVar4 != 0) {

        puVar3 = (uint8_t *)(param_1 + 1);

        do {

          uVar6 = (uint)CONCAT11(puVar3[3],puVar3[4]) + (uint)CONCAT11(puVar3[1],puVar3[2]) & 0xffff

          ;

          uVar5 = (uint)CONCAT11(puVar3[-1],*puVar3) + (uint)CONCAT11(puVar3[1],puVar3[2]) & 0xffff;

          *puVar3 = (char)uVar5;

          puVar3[-1] = (char)(uVar5 >> 8);

          puVar3[3] = (char)(uVar6 >> 8);

          puVar3[4] = (char)uVar6;

          puVar3 = puVar3 + iVar7;

          iVar4 = iVar4 + -1;

        } while (iVar4 != 0);

      }

    }

  }

  return;

}
