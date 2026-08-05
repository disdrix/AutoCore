// =============================================================================
// FUN_00642c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00642c30
// Address:   0x00642c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00642c30 @ 0x00642c30
// Stable ID: aa_00642c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×8, return×3, do×1, while×1.
//  - Notable callees: FUN_00642c30, memmove.
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

bool __fastcall FUN_00642c30(int param_1)



{

  char *pcVar1;

  int iVar2;

  uint uVar3;

  uint _Size;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = param_1;

  pcVar1 = (char *)(**(code **)(**(int **)(param_1 + 8) + 4))((int)&uStack_4 + 3);

  if (*pcVar1 == '\0') {

    return true;

  }

  iVar4 = *(int *)(param_1 + 0x1c);

  if (iVar4 < 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

  }

  else {

    _Size = *(int *)(param_1 + 0x10) - iVar4;

    if (*(int *)(param_1 + 0x20) < (int)_Size) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0xffffffff;

    }

    else if (0 < iVar4) {

      uVar3 = _Size & 0x800001ff;

      if ((int)uVar3 < 0) {

        uVar3 = (uVar3 - 1 | 0xfffffe00) + 1;

      }

      if (uVar3 == 0) {

        iVar5 = 0;

      }

      else {

        iVar5 = 0x200 - uVar3;

      }

      memmove((void *)(*(int *)(param_1 + 0xc) + iVar5),(void *)(iVar4 + *(int *)(param_1 + 0xc)),

              _Size);

      iVar4 = ((uint)(uVar3 != 0) + ((int)(_Size + ((int)_Size >> 0x1f & 0x1ffU)) >> 9)) * 0x200;

      *(int *)(param_1 + 0x1c) = iVar5;

      *(int *)(param_1 + 0x10) = iVar4;

      *(int *)(param_1 + 0x14) = iVar4;

    }

  }

  iVar5 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14);

  iVar4 = 0;

  if (0 < iVar5) {

    do {

      iVar2 = (**(code **)(**(int **)(param_1 + 8) + 8))

                        (*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc),iVar5);

      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + iVar2;

      iVar4 = iVar4 + iVar2;

      if (iVar2 != iVar5) {

        return iVar4 == 0;

      }

    } while (iVar4 < iVar5);

  }

  return false;

}
