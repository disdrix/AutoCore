// =============================================================================
// FUN_0071aef0
// -----------------------------------------------------------------------------
// Stable ID: aa_0071aef0
// Address:   0x0071aef0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0071aef0 @ 0x0071aef0
// Stable ID: aa_0071aef0
// Embedded strings (evidence for future rename):
//   - "Error creating thread <%d>"
//   - "C:\\vog\\1_code\\palantir\\arda2\\thread\\thrThread.cpp"
//   - "Thread already created!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_0076cec0×2, vog_LogMessage×2, CreateThread, FUN_0071aef0, GetLastError.
//  - Strings: "Error creating thread <%d>"; "C:\\vog\\1_code\\palantir\\arda2\\thread\\thrThread.cpp"; "Thread already created!".
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

uint32_t /* width from decompiler */ __fastcall FUN_0071aef0(uint32_t /* width from decompiler */ param_1,SIZE_T param_2)



{

  char in_AL;

  HANDLE pvVar1;

  DWORD DVar2;

  uint32_t /* width from decompiler */ uVar3;

  LPVOID unaff_ESI;

  uint8_t local_4 [4];

  

  if (*(int *)((int)unaff_ESI + 8) == 0) {

    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,param_2,(LPTHREAD_START_ROUTINE)&LAB_0071aed0,

                          unaff_ESI,-(uint)(in_AL != '\0') & 4 | 0x10000,

                          (LPDWORD)((int)unaff_ESI + 4));

    *(HANDLE *)((int)unaff_ESI + 8) = pvVar1;

    if (pvVar1 == (HANDLE)0x0) {

      DVar2 = GetLastError();

      uVar3 = FUN_0076cec0(local_4,"Error creating thread <%d>",DVar2);

      vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\thread\\thrThread.cpp",0x31,3,uVar3);

      return 0;

    }

  }

  else {

    uVar3 = FUN_0076cec0(local_4,"Thread already created!");

    vog_LogMessage("C:\\vog\\1_code\\palantir\\arda2\\thread\\thrThread.cpp",0x40,3,uVar3);

  }

  return 1;

}
