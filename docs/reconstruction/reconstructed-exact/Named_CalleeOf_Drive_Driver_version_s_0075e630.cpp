// =============================================================================
// Named_CalleeOf_Drive_Driver_version_s_0075e630
// -----------------------------------------------------------------------------
// Stable ID: aa_0075e630
// Callee of Drive_Driver_version_s
// Address:   0x0075e630  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Drive_Driver_version_s: drive/input helper. Evidence string: "Release". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Debug"
//   - "Release"
//   - "Non-WHQL"
//   - "WHQL Certified"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_0075e630, _snprintf, s.
//  - Strings: "Debug"; "Release"; "Non-WHQL"; "WHQL Certified".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Drive_Driver_version_s
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

uint32_t /* width from decompiler */ Named_CalleeOf_Drive_Driver_version_s_0075e630(char *param_1,size_t param_2)



{

  int in_EAX;

  char *pcVar1;

  char *pcVar2;

  

  if ((param_1 != (char *)0x0) && (0x230 < (int)param_2)) {

    pcVar2 = "Debug";

    if (*(char *)(in_EAX + 0x7a8) == '\0') {

      pcVar2 = "Release";

    }

    pcVar1 = "Non-WHQL";

    if (*(int *)(in_EAX + 0x738) != 0) {

      pcVar1 = "WHQL Certified";

    }

    _snprintf(param_1,param_2,"%s - %s(%s) [%d.%d.%d.%d %s, %s D3D Runtime]",in_EAX + 0x2f0,

              in_EAX + 0x4f0,in_EAX + 0x6f0,(uint)*(ushort *)(in_EAX + 0x716),

              (uint)*(ushort *)(in_EAX + 0x714),(uint)*(ushort *)(in_EAX + 0x712),

              (uint)*(ushort *)(in_EAX + 0x710),pcVar1,pcVar2);

    return 0;

  }

  return 0xffffffff;

}
