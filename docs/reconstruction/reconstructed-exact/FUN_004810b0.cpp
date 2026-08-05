// =============================================================================
// FUN_004810b0
// -----------------------------------------------------------------------------
// Stable ID: aa_004810b0
// Address:   0x004810b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004810b0 @ 0x004810b0
// Stable ID: aa_004810b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×4, if×3.
//  - Notable callees: FUN_004810b0, WSAGetLastError, send.
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

bool __thiscall FUN_004810b0(SOCKET param_1,uint *param_2)



{

  char *in_EAX;

  int iVar1;

  int *unaff_EBX;

  int unaff_EDI;

  

  iVar1 = send(param_1,in_EAX,unaff_EDI,0);

  if (iVar1 != -1) {

    *unaff_EBX = iVar1;

    *param_2 = (uint)(iVar1 != unaff_EDI);

    return iVar1 != -1;

  }

  *unaff_EBX = 0;

  iVar1 = WSAGetLastError();

  if (iVar1 != 0x2733) {

    if (iVar1 != 0x2738) {

      *param_2 = 0;

      return false;

    }

    *param_2 = 3;

    return false;

  }

  *param_2 = 2;

  return false;

}
