// =============================================================================
// FUN_008db100
// -----------------------------------------------------------------------------
// Stable ID: aa_008db100
// Address:   0x008db100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008db100 @ 0x008db100
// Stable ID: aa_008db100
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×5, return×2.
//  - Notable callees: FUN_008db100.
//  - Return sites: 2.

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

void FUN_008db100(void)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ uVar3;

  int *unaff_ESI;

  uint8_t auStack_8 [8];

  

  if (unaff_ESI[0x16a] != 0) {

    cVar2 = (**(code **)(*unaff_ESI + 0x3d8))();

    if (cVar2 != '\0') {

      if ((char)unaff_ESI[0x146] == '\0') {

        (**(code **)(*(int *)unaff_ESI[0x16a] + 4))(0);

        return;

      }

      unaff_ESI[0x144] = 0;

      if ((int *)unaff_ESI[0x168] != (int *)0x0) {

        iVar1 = *(int *)unaff_ESI[0x16a];

        uVar3 = (**(code **)(*(int *)unaff_ESI[0x168] + 0x120))(auStack_8,1,0);

        (**(code **)(iVar1 + 0x114))(uVar3);

      }

      if ((int *)unaff_ESI[0x168] != (int *)0x0) {

        iVar1 = *(int *)unaff_ESI[0x16a];

        uVar3 = (**(code **)(*(int *)unaff_ESI[0x168] + 0x140))(auStack_8,1);

        (**(code **)(iVar1 + 0x130))(uVar3);

      }

      (**(code **)(*(int *)unaff_ESI[0x16a] + 0xcc))(1);

      (**(code **)(*(int *)unaff_ESI[0x16a] + 0xfc))(0,0x3f800000);

      (**(code **)(*(int *)unaff_ESI[0x16a] + 0x34c))();

    }

  }

  return;

}
