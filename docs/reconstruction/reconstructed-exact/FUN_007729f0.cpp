// =============================================================================
// FUN_007729f0
// -----------------------------------------------------------------------------
// Stable ID: aa_007729f0
// Address:   0x007729f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007729f0 @ 0x007729f0
// Stable ID: aa_007729f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~46 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, while×3, do×2.
//  - Notable callees: FUN_00770850×2, rand×2, FUN_007701d0, FUN_00770490, FUN_007729f0.
//  - Return sites: 4.

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

int __fastcall FUN_007729f0(int *param_1)



{

  int in_EAX;

  uint uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int *piVar5;

  

  FUN_007701d0();

  if (in_EAX < 1) {

    return 0;

  }

  do {

    uVar1 = rand();

    uVar1 = (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f) & 0xfffffff;

  } while (uVar1 == 0);

  iVar2 = FUN_00770850(uVar1,param_1);

  while( true ) {

    if (iVar2 != 0) {

      return iVar2;

    }

    in_EAX = in_EAX + -1;

    if (in_EAX < 1) break;

    if ((param_1[1] < *param_1 + 1) && (iVar2 = FUN_00770490(), iVar2 != 0)) {

      return iVar2;

    }

    *param_1 = *param_1 + 1;

    iVar2 = *param_1;

    puVar3 = (uint32_t /* width from decompiler */ *)(param_1[3] + -4 + iVar2 * 4);

    puVar4 = (uint32_t /* width from decompiler */ *)(param_1[3] + -8 + iVar2 * 4);

    iVar2 = iVar2 + -1;

    if (0 < iVar2) {

      do {

        *puVar3 = *puVar4;

        puVar3 = puVar3 + -1;

        puVar4 = puVar4 + -1;

        iVar2 = iVar2 + -1;

      } while (iVar2 != 0);

    }

    *(uint32_t /* width from decompiler */ *)param_1[3] = 0;

    piVar5 = param_1;

    uVar1 = rand();

    iVar2 = FUN_00770850((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f),piVar5);

  }

  return 0;

}
