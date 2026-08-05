// =============================================================================
// FUN_00931fa0
// -----------------------------------------------------------------------------
// Stable ID: aa_00931fa0
// Address:   0x00931fa0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00931fa0 @ 0x00931fa0
// Stable ID: aa_00931fa0
// Embedded strings (evidence for future rename):
//   - "Failed!"
//   - "Success!"
//   - "Wait for TNL Thread to end - %s (%d)"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, for×1.
//  - Notable callees: CloseHandle, CreateEventA, FUN_004dfcc0, FUN_007a4480, FUN_00931fa0, GetForegroundWindow, SignalObjectAndWait, _beginthread.
//  - Strings: "Failed!"; "Success!"; "Wait for TNL Thread to end - %s (%d)".
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

uint8_t FUN_00931fa0(void)



{

  uint8_t uVar1;

  void *in_EAX;

  HWND pHVar2;

  HANDLE pvVar3;

  DWORD DVar4;

  char *pcVar5;

  HANDLE hObjectToWaitOn;

  

  if (*(char *)(*(int *)((int)in_EAX + 0xde8) + 5) == '\0') {

    pHVar2 = GetForegroundWindow();

    if (pHVar2 != *(HWND *)((int)in_EAX + 0x3188)) {

      return 2;

    }

  }

  DAT_00d09870 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCSTR)0x0);

  pvVar3 = (HANDLE)_beginthread((_StartAddress *)&LAB_0092cd50,0,in_EAX);

  hObjectToWaitOn = (HANDLE)0x0;

  if (pvVar3 != (HANDLE)0x0) {

    hObjectToWaitOn = pvVar3;

  }

  uVar1 = FUN_004dfcc0((int)in_EAX + 0x750,*(uint32_t /* width from decompiler */ *)((int)in_EAX + 0x858),

                       *(uint32_t /* width from decompiler */ *)((int)in_EAX + 0xd30));

  DVar4 = SignalObjectAndWait(DAT_00d09870,hObjectToWaitOn,0xffffffff,0);

  pcVar5 = "Failed!";

  if (DVar4 != 0xffffffff) {

    pcVar5 = "Success!";

  }

  FUN_007a4480(0xffffffff,"Wait for TNL Thread to end - %s (%d)",pcVar5,DVar4);

  CloseHandle(DAT_00d09870);

  return uVar1;

}
