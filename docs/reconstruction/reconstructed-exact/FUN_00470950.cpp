// =============================================================================
// FUN_00470950
// -----------------------------------------------------------------------------
// Stable ID: aa_00470950
// Address:   0x00470950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00470950 @ 0x00470950
// Stable ID: aa_00470950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×2.
//  - Notable callees: FUN_00470950, FUN_004766e0, FUN_00476cc0, malloc.
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

void __thiscall FUN_00470950(int param_1,uint param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *in_EAX;

  void *pvVar1;

  uint uVar2;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar3;

  

  if ((param_1 != 0) && (unaff_EBX != 0)) {

    if (in_EAX != (uint32_t /* width from decompiler */ *)0x0) {

      FUN_004766e0(param_1);

      if (*(code **)(param_1 + 0x248) == (code *)0x0) {

        pvVar1 = malloc(0x100);

      }

      else {

        pvVar1 = (void *)(**(code **)(param_1 + 0x248))(param_1);

      }

      if ((pvVar1 == (void *)0x0) && ((*(byte *)(param_1 + 0x6e) & 0x10) == 0)) {

                    /* WARNING: Subroutine does not return */

        FUN_00476cc0(param_1);

      }

      *(void **)(unaff_EBX + 0x4c) = pvVar1;

      *(void **)(param_1 + 0x188) = pvVar1;

      puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0x4c);

      for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

        *puVar3 = *in_EAX;

        in_EAX = in_EAX + 1;

        puVar3 = puVar3 + 1;

      }

      for (uVar2 = param_2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

        *(uint8_t *)puVar3 = *(uint8_t *)in_EAX;

        in_EAX = (uint32_t /* width from decompiler */ *)((int)in_EAX + 1);

        puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      }

      *(byte *)(unaff_EBX + 0xb9) = *(byte *)(unaff_EBX + 0xb9) | 0x20;

    }

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x50) = *param_3;

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x54) = param_3[1];

      *(uint16_t *)(unaff_EBX + 0x58) = *(uint16_t *)(param_3 + 2);

      if (param_2 == 0) {

        param_2 = 1;

      }

    }

    *(uint *)(unaff_EBX + 8) = *(uint *)(unaff_EBX + 8) | 0x10;

    *(short *)(unaff_EBX + 0x16) = (short)param_2;

  }

  return;

}
