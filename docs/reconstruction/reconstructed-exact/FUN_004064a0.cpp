// =============================================================================
// FUN_004064a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004064a0
// Address:   0x004064a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004064a0 @ 0x004064a0
// Stable ID: aa_004064a0
// Embedded strings (evidence for future rename):
//   - "HashError:RemoveAll, already locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×3, while×2, for×1, do×1, return×1.
//  - Notable callees: FUN_007a4480×2, FUN_004064a0.
//  - Strings: "HashError:RemoveAll, already locked for traversal"; "VOG_DEBUG_STOP".
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

uint32_t /* width from decompiler */ __fastcall FUN_004064a0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint uVar4;

  

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:RemoveAll, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  if (*(int *)(param_1 + 0x10) != 0) {

    uVar4 = 0;

    do {

      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4);

      if (iVar1 != 0) {

        puVar3 = *(uint32_t /* width from decompiler */ **)(iVar1 + 4);

        while (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

          puVar2 = (uint32_t /* width from decompiler */ *)puVar3[4];

          *puVar3 = &PTR_FUN_00a2c2bc;

          puVar3[3] = 0;

          *puVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

          *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar3;

          puVar3 = puVar2;

        }

        *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x10) + uVar4 * 4) + 4) = 0;

      }

      uVar4 = uVar4 + 1;

    } while (uVar4 <= *(uint *)(param_1 + 8));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = 0;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xc) = 0;

  return 0;

}
