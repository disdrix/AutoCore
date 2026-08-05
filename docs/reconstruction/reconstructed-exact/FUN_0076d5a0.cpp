// =============================================================================
// FUN_0076d5a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0076d5a0
// Address:   0x0076d5a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076d5a0 @ 0x0076d5a0
// Stable ID: aa_0076d5a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×5, return×4, for×1, while×1.
//  - Notable callees: FUN_0076d5a0, GetCurrentThread, GetThreadContext.
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

DWORD FUN_0076d5a0(void)



{

  int in_EAX;

  HANDLE hThread;

  BOOL BVar1;

  int iVar2;

  int iVar3;

  char *unaff_EBX;

  DWORD *pDVar4;

  DWORD local_3e0 [8];

  DWORD local_3c0;

  uint32_t /* width from decompiler */ local_3bc;

  uint32_t /* width from decompiler */ local_3b4;

  DWORD local_3b0;

  uint32_t /* width from decompiler */ local_3ac;

  uint32_t /* width from decompiler */ local_3a4;

  CONTEXT local_2d8;

  

  if (*unaff_EBX != '\0') {

    hThread = GetCurrentThread();

    local_2d8.ContextFlags = 0x10001;

    BVar1 = GetThreadContext(hThread,&local_2d8);

    if (BVar1 != 0) {

      pDVar4 = local_3e0;

      for (iVar3 = 0x42; iVar3 != 0; iVar3 = iVar3 + -1) {

        *pDVar4 = 0;

        pDVar4 = pDVar4 + 1;

      }

      iVar3 = in_EAX + 1;

      local_3e0[0] = local_2d8.Eip;

      local_3e0[3] = 3;

      local_3e0[1] = 0;

      local_3a4 = 3;

      local_3b0 = local_2d8.Esp;

      local_3ac = 0;

      local_3b4 = 3;

      local_3c0 = local_2d8.Ebp;

      local_3bc = 0;

      if (iVar3 != 0) {

        while (iVar2 = (*DAT_00d0dfd0)(0x14c,*(uint32_t /* width from decompiler */ *)(unaff_EBX + 4),hThread,local_3e0,

                                       &local_2d8,0,DAT_00d0dfac,DAT_00d0dfc0,0), iVar2 != 0) {

          iVar3 = iVar3 + -1;

          if (iVar3 == 0) {

            return local_3e0[0];

          }

        }

        if (iVar3 != 0) {

          return 0;

        }

      }

      return local_3e0[0];

    }

  }

  return 0;

}
