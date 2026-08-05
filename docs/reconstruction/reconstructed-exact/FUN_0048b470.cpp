// =============================================================================
// FUN_0048b470
// -----------------------------------------------------------------------------
// Stable ID: aa_0048b470
// Address:   0x0048b470  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0048b470 @ 0x0048b470
// Stable ID: aa_0048b470
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, do×1, return×1, for×1.
//  - Notable callees: FUN_0048b470.
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

void __fastcall FUN_0048b470(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x18);

  while (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    puVar2 = (uint32_t /* width from decompiler */ *)*puVar1;

    puVar1 = (uint32_t /* width from decompiler */ *)puVar1[10];

    (*(code *)*puVar2)(1);

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0;

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 0x2c);

  do {

    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x4c);

    if ((puVar2 == puVar1) || (puVar2 == (uint32_t /* width from decompiler */ *)0x0)) {

      return;

    }

    puVar3 = (uint32_t /* width from decompiler */ *)((puVar2 == puVar1) - 1 & (uint)puVar2);

    for (; puVar2 != puVar1; puVar2 = (uint32_t /* width from decompiler */ *)puVar2[8]) {

      if (puVar2 == puVar3) {

        *(uint32_t /* width from decompiler */ *)(puVar2[7] + 0x20) = puVar2[8];

        *(uint32_t /* width from decompiler */ *)(puVar2[8] + 0x1c) = puVar2[7];

        puVar2[8] = 0;

        puVar2[7] = 0;

        break;

      }

    }

    if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*puVar3)(1);

    }

  } while( true );

}
