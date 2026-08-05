// =============================================================================
// FUN_00443930
// -----------------------------------------------------------------------------
// Stable ID: aa_00443930
// Address:   0x00443930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00443930 @ 0x00443930
// Stable ID: aa_00443930
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×1, while×1.
//  - Notable callees: FUN_00443930.
//  - Return sites: 3.

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

void __fastcall FUN_00443930(ushort *param_1)



{

  int *piVar1;

  ushort uVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint uVar3;

  int *piVar4;

  int unaff_ESI;

  

  uVar2 = *param_1;

  uVar3 = (uint)uVar2 & *(uint *)(unaff_ESI + 0x20);

  if (*(uint *)(unaff_ESI + 0x24) <= uVar3) {

    uVar3 = uVar3 + (-1 - (*(uint *)(unaff_ESI + 0x20) >> 1));

  }

  piVar1 = (int *)(*(int *)(unaff_ESI + 0x14) + uVar3 * 4);

  piVar4 = (int *)*piVar1;

  if (piVar4 != (int *)piVar1[1]) {

    do {

      if (uVar2 <= *(ushort *)(piVar4 + 2)) {

        if (*(ushort *)(piVar4 + 2) <= uVar2) {

          *in_EAX = piVar4;

          return;

        }

        *in_EAX = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

        return;

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != (int *)piVar1[1]);

  }

  *in_EAX = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 8);

  return;

}
