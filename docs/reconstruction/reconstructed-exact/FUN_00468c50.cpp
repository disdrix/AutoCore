// =============================================================================
// FUN_00468c50
// -----------------------------------------------------------------------------
// Stable ID: aa_00468c50
// Address:   0x00468c50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00468c50 @ 0x00468c50
// Stable ID: aa_00468c50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×8, return×7.
//  - Notable callees: FUN_00468c50.
//  - Return sites: 7.

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

bool FUN_00468c50(void)



{

  int *piVar1;

  byte bVar2;

  byte bVar3;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar4;

  uint uVar5;

  uint32_t /* width from decompiler */ *unaff_ESI;

  

  if (*(uint *)(in_EAX[1] + 8) < *(uint *)(unaff_ESI[1] + 8)) {

    return true;

  }

  if (*(uint *)(in_EAX[1] + 8) <= *(uint *)(unaff_ESI[1] + 8)) {

    if ((uint)in_EAX[2] < (uint)unaff_ESI[2]) {

      return true;

    }

    if (in_EAX[2] == unaff_ESI[2]) {

      uVar4 = (**(code **)(*(int *)*in_EAX + 0x14))();

      uVar5 = (**(code **)(*(int *)*unaff_ESI + 0x14))();

      if (uVar4 < uVar5) {

        return true;

      }

      if (uVar4 <= uVar5) {

        if ((uint)in_EAX[1] < (uint)unaff_ESI[1]) {

          return true;

        }

        if (in_EAX[1] == unaff_ESI[1]) {

          piVar1 = (int *)*in_EAX;

          bVar2 = (**(code **)(*(int *)*unaff_ESI + 0x1c))();

          bVar3 = (**(code **)(*piVar1 + 0x1c))();

          return bVar3 < bVar2;

        }

      }

      return false;

    }

  }

  return false;

}
