// =============================================================================
// FUN_006bafb0
// -----------------------------------------------------------------------------
// Stable ID: aa_006bafb0
// Address:   0x006bafb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006bafb0 @ 0x006bafb0
// Stable ID: aa_006bafb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~58 non-empty decompiler lines.
//  - Control keywords: if×6, do×4, while×4, return×1.
//  - Notable callees: FUN_006bafb0×2.
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

void FUN_006bafb0(int param_1,int param_2,int param_3,code *param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  char *pcVar4;

  int iVar5;

  uint8_t local_26;

  uint8_t uStack_25;

  int iStack_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  

  do {

    iVar3 = param_2 + param_3 >> 1;

    local_20 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 8);

    local_1c = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar3 * 8);

    iVar3 = param_2;

    iVar5 = param_3;

    do {

      pcVar4 = (char *)(*param_4)(&local_26,param_1 + iVar3 * 8,&local_20);

      if (*pcVar4 != '\0') {

        iStack_24 = param_1 + iVar3 * 8;

        do {

          iStack_24 = iStack_24 + 8;

          iVar3 = iVar3 + 1;

          pcVar4 = (char *)(*param_4)(&local_26,iStack_24,&local_20);

        } while (*pcVar4 != '\0');

      }

      pcVar4 = (char *)(*param_4)(&uStack_25,&local_20,param_1 + iVar5 * 8);

      if (*pcVar4 != '\0') {

        iStack_24 = param_1 + iVar5 * 8;

        do {

          iStack_24 = iStack_24 + -8;

          iVar5 = iVar5 + -1;

          pcVar4 = (char *)(*param_4)(&uStack_25,&local_20,iStack_24);

        } while (*pcVar4 != '\0');

      }

      if (iVar5 < iVar3) break;

      if (iVar5 != iVar3) {

        uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 8);

        uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar5 * 8);

        *(uint32_t /* width from decompiler */ *)(param_1 + iVar5 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 8);

        *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar5 * 8) = *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar3 * 8);

        *(uint32_t /* width from decompiler */ *)(param_1 + iVar3 * 8) = uVar1;

        *(uint32_t /* width from decompiler */ *)(param_1 + 4 + iVar3 * 8) = uVar2;

      }

      iVar5 = iVar5 + -1;

      iVar3 = iVar3 + 1;

    } while (iVar3 <= iVar5);

    if (param_2 < iVar5) {

      FUN_006bafb0(param_1,param_2,iVar5,param_4);

    }

    param_2 = iVar3;

    if (param_3 <= iVar3) {

      return;

    }

  } while( true );

}
