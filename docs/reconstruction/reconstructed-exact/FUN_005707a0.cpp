// =============================================================================
// FUN_005707a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005707a0
// Address:   0x005707a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005707a0 @ 0x005707a0
// Stable ID: aa_005707a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, do×2, while×2.
//  - Notable callees: FUN_005707a0.
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

void __thiscall FUN_005707a0(int param_1,int param_2,int param_3,byte *param_4,byte *param_5)



{

  int iVar1;

  byte bVar2;

  uint uVar3;

  byte local_9;

  

  local_9 = 0;

  if (*(int *)(param_1 + 0xc) < 1) {

    return;

  }

  do {

    bVar2 = 0;

    if (0 < *(int *)(param_1 + 8)) {

      uVar3 = 0;

      do {

        iVar1 = *(int *)(param_1 + 0xc) * uVar3 + (uint)local_9;

        if ((*(int *)(*(int *)(param_1 + 0x28) + iVar1 * 8) == param_2) &&

           (*(int *)(*(int *)(param_1 + 0x28) + 4 + iVar1 * 8) == param_3)) {

          *param_4 = bVar2;

          *param_5 = local_9;

          return;

        }

        bVar2 = bVar2 + 1;

        uVar3 = (uint)bVar2;

      } while ((int)uVar3 < *(int *)(param_1 + 8));

    }

    local_9 = local_9 + 1;

    if (*(int *)(param_1 + 0xc) <= (int)(uint)local_9) {

      return;

    }

  } while( true );

}
