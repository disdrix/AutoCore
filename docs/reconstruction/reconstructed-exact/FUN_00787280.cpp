// =============================================================================
// FUN_00787280
// -----------------------------------------------------------------------------
// Stable ID: aa_00787280
// Address:   0x00787280  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00787280 @ 0x00787280
// Stable ID: aa_00787280
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00429b50, FUN_00787280, memmove.
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

void __fastcall FUN_00787280(int *param_1)



{

  size_t _Size;

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  void *pvVar3;

  

  iVar1 = *param_1;

  if (iVar1 != 0) {

    if (*(code **)(iVar1 + 0x14) != (code *)0x0) {

      (**(code **)(iVar1 + 0x14))(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x18),param_1[3]);

    }

    if ((code *)param_1[2] != (code *)0x0) {

      (*(code *)param_1[2])(*(uint32_t /* width from decompiler */ *)(*param_1 + 0x18),param_1[3]);

    }

    pvVar3 = *(void **)(*param_1 + 8);

    puVar2 = (uint32_t /* width from decompiler */ *)FUN_00429b50(*(uint32_t /* width from decompiler */ *)(*param_1 + 4),pvVar3);

    iVar1 = *param_1;

    if ((void *)*puVar2 != pvVar3) {

      _Size = (*(int *)(iVar1 + 8) - (int)pvVar3 >> 2) * 4;

      pvVar3 = memmove((void *)*puVar2,pvVar3,_Size);

      *(void **)(iVar1 + 8) = (void *)((int)pvVar3 + _Size);

    }

  }

  return;

}
