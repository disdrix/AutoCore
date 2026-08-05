// =============================================================================
// FUN_005139f0
// -----------------------------------------------------------------------------
// Stable ID: aa_005139f0
// Address:   0x005139f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005139f0 @ 0x005139f0
// Stable ID: aa_005139f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004bb0d0×2, FUN_005139f0, NetObject_SetMaskBits.
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

void __thiscall

FUN_005139f0(int param_1,uint param_2,uint param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  bool bVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  

  cVar2 = (char)param_4;

  if ((((*(uint *)(param_1 + 0x40) != param_2) || (*(uint *)(param_1 + 0x44) != param_3)) ||

      (*(char *)(param_1 + 0x48) != cVar2)) &&

     ((((param_2 & param_3) != 0xffffffff || (cVar2 != '\0')) &&

      ((param_2 != *(uint *)(param_1 + 0x50) ||

       ((param_3 != *(uint *)(param_1 + 0x54) || (cVar2 != *(char *)(param_1 + 0x58))))))))) {

    bVar1 = true;

    if ((cVar2 == '\x01') &&

       (((((*(int *)(param_1 + 0xa4) != 0 && (iVar3 = FUN_004bb0d0(&param_2), iVar3 != 0)) &&

          (*(int *)(iVar3 + 0xcb0) != 0)) &&

         ((iVar4 = FUN_004bb0d0((uint *)(param_1 + 0x50)), iVar4 != 0 &&

          (*(int *)(iVar4 + 0xcb0) != 0)))) &&

        ((*(int *)(iVar4 + 0xca8) == *(int *)(iVar3 + 0xca8) &&

         (*(int *)(iVar4 + 0xcac) == *(int *)(iVar3 + 0xcac))))))) {

      bVar1 = false;

    }

    *(uint *)(param_1 + 0x50) = param_2;

    *(uint *)(param_1 + 0x54) = param_3;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x58) = param_4;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x5c) = param_5;

    if (bVar1) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x60) = 0;

    }

  }

  *(uint *)(param_1 + 0x40) = param_2;

  *(uint *)(param_1 + 0x44) = param_3;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x48) = param_4;

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x4c) = param_5;

  if (*(void **)(param_1 + 0x14) != (void *)0x0) {

    NetObject_SetMaskBits(*(void **)(param_1 + 0x14),0x20,0);

  }

  return;

}
