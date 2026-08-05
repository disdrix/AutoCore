// =============================================================================
// FUN_007849d0
// -----------------------------------------------------------------------------
// Stable ID: aa_007849d0
// Address:   0x007849d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007849d0 @ 0x007849d0
// Stable ID: aa_007849d0
// Embedded strings (evidence for future rename):
//   - "iphlpapi.dll"
//   - "GetIpAddrTable"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, do×1, while×1.
//  - Notable callees: free×2, htonl×2, malloc×2, FUN_00426b70, FUN_007849d0, GetProcAddress, LoadLibraryA.
//  - Strings: "iphlpapi.dll"; "GetIpAddrTable".
//  - Return sites: 2.

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

void FUN_007849d0(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  HMODULE hModule;

  uint *_Memory;

  int iVar2;

  u_long uVar3;

  uint *puVar4;

  int *unaff_ESI;

  size_t unaff_EDI;

  uint uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ local_1c [7];

  

  if (DAT_00d1f208 == (FARPROC)0x0) {

    hModule = LoadLibraryA("iphlpapi.dll");

    if (hModule == (HMODULE)0x0) {

      return;

    }

    DAT_00d1f208 = GetProcAddress(hModule,"GetIpAddrTable");

  }

  local_1c[0] = 0;

  _Memory = malloc(0x1c);

  iVar2 = (*DAT_00d1f208)(_Memory,local_1c,0);

  if (iVar2 == 0x7a) {

    free(_Memory);

    _Memory = malloc(unaff_EDI);

  }

  iVar2 = (*DAT_00d1f208)(_Memory,&stack0xffffffd8,0);

  if ((iVar2 == 0) && (uVar5 = 0, *_Memory != 0)) {

    uVar6 = 0;

    local_1c[0] = 0;

    puVar4 = _Memory + 1;

    do {

      htonl(0);

      uVar3 = htonl(*puVar4);

      if ((uVar3 != 0) && (uVar3 != 0x7f000001)) {

        FUN_00426b70();

        *unaff_ESI = *unaff_ESI + 1;

        puVar1 = (uint32_t /* width from decompiler */ *)(unaff_ESI[2] + -0x14 + *unaff_ESI * 0x14);

        if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

          *puVar1 = uVar6;

          puVar1[1] = uVar3;

          puVar1[2] = 0;

          puVar1[3] = 0;

          puVar1[4] = local_1c[0];

        }

      }

      uVar5 = uVar5 + 1;

      puVar4 = puVar4 + 6;

    } while (uVar5 < *_Memory);

  }

  free(_Memory);

  return;

}
