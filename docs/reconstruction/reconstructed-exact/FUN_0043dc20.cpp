// =============================================================================
// FUN_0043dc20
// -----------------------------------------------------------------------------
// Stable ID: aa_0043dc20
// Address:   0x0043dc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0043dc20 @ 0x0043dc20
// Stable ID: aa_0043dc20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, while×2, return×1.
//  - Notable callees: FUN_0043dc20.
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

void __fastcall FUN_0043dc20(int param_1)



{

  int *in_EAX;

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint *unaff_EBX;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {

    puVar1 = (uint32_t /* width from decompiler */ *)puVar4[1];

    do {

      if (*unaff_EBX < (uint)puVar1[3]) {

        puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

        puVar4 = puVar1;

      }

      else {

        puVar2 = (uint32_t /* width from decompiler */ *)puVar1[2];

      }

      puVar1 = puVar2;

    } while (*(char *)((int)puVar2 + 0x15) == '\0');

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  if (*(char *)((int)puVar1[1] + 0x15) == '\0') {

    puVar2 = (uint32_t /* width from decompiler */ *)puVar1[1];

    do {

      if ((uint)puVar2[3] < *unaff_EBX) {

        puVar3 = (uint32_t /* width from decompiler */ *)puVar2[2];

      }

      else {

        puVar3 = (uint32_t /* width from decompiler */ *)*puVar2;

        puVar1 = puVar2;

      }

      puVar2 = puVar3;

    } while (*(char *)((int)puVar3 + 0x15) == '\0');

  }

  *in_EAX = (int)puVar1;

  in_EAX[1] = (int)puVar4;

  return;

}
