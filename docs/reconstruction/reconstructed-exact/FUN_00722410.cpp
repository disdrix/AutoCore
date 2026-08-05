// =============================================================================
// FUN_00722410
// -----------------------------------------------------------------------------
// Stable ID: aa_00722410
// Address:   0x00722410  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00722410 @ 0x00722410
// Stable ID: aa_00722410
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_00722410.
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

int __fastcall FUN_00722410(uint32_t /* width from decompiler */ *param_1)



{

  int *in_EAX;

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_28 = 0;

  if (param_1 == (uint32_t /* width from decompiler */ *)0x0) {

    return -0x7ff8ffa9;

  }

  if (*in_EAX == 0) {

    return -0x7ffbfe10;

  }

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  local_4 = 0;

  *param_1 = 0;

  puVar3 = &local_24;

  local_24 = 0x24;

  local_20 = 0x11;

  iVar1 = (**(code **)(*(int *)*in_EAX + 0xc))((int *)*in_EAX,puVar3,&local_28,0);

  if (-1 < iVar1) {

    piVar2 = (int *)&DAT_00a0d044;

    iVar1 = (**(code **)*puVar3)(puVar3,&DAT_00a0d044,param_1);

    if (iVar1 < 0) {

      if (piVar2 != (int *)0x0) {

        (**(code **)(*piVar2 + 8))(piVar2);

      }

      return iVar1;

    }

    if (piVar2 != (int *)0x0) {

      (**(code **)(*piVar2 + 8))(piVar2);

    }

    iVar1 = 0;

  }

  return iVar1;

}
