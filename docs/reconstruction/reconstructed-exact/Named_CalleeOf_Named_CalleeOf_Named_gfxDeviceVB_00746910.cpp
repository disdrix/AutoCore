// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00746910
// -----------------------------------------------------------------------------
// Stable ID: aa_00746910
// Callee of Named_CalleeOf_Named_gfxDeviceVB (+1 other named callers)
// Address:   0x00746910  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Named_gfxDeviceVB: callee helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve. Named_CalleeOf_Named_gfxDeviceVB (+1 other named callers).
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~60 non-empty decompiler lines.
//  - Control keywords: for×1, switch×1, return×1.
//  - Notable callees: FUN_00746910.
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Named_gfxDeviceVB (+1 other named callers)
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Named_CalleeOf_Named_CalleeOf_Named_gfxDeviceVB_00746910(void)



{

  int iVar1;

  int in_EAX;

  ushort *puVar2;

  int iVar3;

  ushort local_20 [16];

  

  local_20[0] = 0;

  local_20[1] = 0;

  local_20[2] = 0;

  local_20[3] = 0;

  local_20[4] = 0;

  local_20[5] = 0;

  local_20[6] = 0;

  local_20[7] = 0;

  iVar1 = *(int *)(in_EAX + 8);

  puVar2 = *(ushort **)(in_EAX + 4);

  local_20[8] = 0;

  local_20[9] = 0;

  local_20[10] = 0;

  local_20[0xb] = 0;

  local_20[0xc] = 0;

  local_20[0xd] = 0;

  local_20[0xe] = 0;

  local_20[0xf] = 0;

  for (; puVar2 != (ushort *)(iVar1 + -8); puVar2 = puVar2 + 4) {

    puVar2[1] = local_20[(uint)*puVar2 * 2];

    switch((char)puVar2[2]) {

    case '\0':

    case '\x04':

    case '\x05':

    case '\x06':

    case '\b':

    case '\t':

    case '\v':

    case '\r':

    case '\x0e':

    case '\x0f':

      iVar3 = 4;

      break;

    case '\x01':

    case '\a':

    case '\n':

    case '\f':

    case '\x10':

      iVar3 = 8;

      break;

    case '\x02':

      iVar3 = 0xc;

      break;

    case '\x03':

      iVar3 = 0x10;

      break;

    default:

      iVar3 = 0;

    }

    *(int *)(local_20 + (uint)*puVar2 * 2) = *(int *)(local_20 + (uint)*puVar2 * 2) + iVar3;

  }

  return;

}
