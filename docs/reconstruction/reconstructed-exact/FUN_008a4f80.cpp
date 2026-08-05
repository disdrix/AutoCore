// =============================================================================
// FUN_008a4f80
// -----------------------------------------------------------------------------
// Stable ID: aa_008a4f80
// Address:   0x008a4f80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a4f80 @ 0x008a4f80
// Stable ID: aa_008a4f80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~33 non-empty decompiler lines.
//  - Control keywords: if×3, do×1, while×1, return×1.
//  - Notable callees: FUN_00574730, FUN_008a2940, FUN_008a2df0, FUN_008a4900, FUN_008a4f80, FUN_008e8ac0.
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

void FUN_008a4f80(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  longlong lVar5;

  int local_4;

  

  if ((DAT_00d1b6d8 != 0) && (*(int *)(DAT_00d1b6d8 + 0xcb0) != 0)) {

    FUN_008a2940();

    uVar4 = 0;

    iVar3 = 0;

    if (*(char *)(*(int *)(DAT_00d1b6d8 + 0xcb0) + 0x1d8) != '\0') {

      local_4 = param_1 + 0x5cc;

      do {

        lVar5 = FUN_00574730(iVar3);

        iVar2 = DAT_00d1b6d8;

        if (((lVar5 != -1) &&

            (((iVar1 = *(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4),

              (int)lVar5 != *(int *)(iVar1 + 0x164 + DAT_00d1b6d8) ||

              ((int)((ulonglong)lVar5 >> 0x20) != *(int *)(iVar1 + 0x168 + DAT_00d1b6d8))) &&

             (DAT_00d1b8e0 != 0)))) && (iVar1 = FUN_008e8ac0(lVar5), iVar1 != 0)) {

          uVar4 = FUN_008a4900(local_4,iVar1 + 0x4c,uVar4);

          iVar2 = DAT_00d1b6d8;

        }

        local_4 = local_4 + 0xc;

        iVar3 = iVar3 + 1;

      } while (iVar3 < (int)(uint)*(byte *)(*(int *)(iVar2 + 0xcb0) + 0x1d8));

    }

    FUN_008a2df0();

  }

  return;

}
