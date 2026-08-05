// =============================================================================
// Named_CalleeOf_Named_Client_InitInstance_00932af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00932af0
// Callee of Named_Client_InitInstance
// Address:   0x00932af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_Client_InitInstance: callee helper. Evidence string: "XutoAssaultSplash". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "XutoAssaultSplash"
//   - "Auto Assault"
//   - "Failed to CreateWindowEx for splashscreen!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×2, return×2, for×1, while×1.
//  - Notable callees: PeekMessageA×2, CreateWindowExA, DispatchMessageA, FUN_007a4480, FUN_00932af0, GetDesktopWindow, GetStockObject, GetWindowRect.
//  - Strings: "XutoAssaultSplash"; "Auto Assault"; "Failed to CreateWindowEx for splashscreen!".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Callee of Named_Client_InitInstance
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

void Named_CalleeOf_Named_Client_InitInstance_00932af0(void)



{

  ATOM AVar1;

  HWND pHVar2;

  int iVar3;

  int unaff_ESI;

  tagRECT *lpRect;

  tagRECT local_54;

  tagMSG local_44;

  WNDCLASSA local_28;

  

  lpRect = &local_54;

  pHVar2 = GetDesktopWindow();

  GetWindowRect(pHVar2,lpRect);

  *(int *)(unaff_ESI + 0x3194) = ((local_54.bottom - local_54.top) + -0x80) / 2;

  *(int *)(unaff_ESI + 0x3190) = ((local_54.right - local_54.left) + -0x200) / 2;

  local_28.hInstance = *(HINSTANCE *)(unaff_ESI + 0x3180);

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x319c) = 0x80;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x3198) = 0x200;

  local_28.style = 0x3023;

  local_28.lpfnWndProc = (WNDPROC)&LAB_0092c990;

  local_28.cbClsExtra = 0;

  local_28.cbWndExtra = 0;

  local_28.hIcon = LoadIconA(local_28.hInstance,(LPCSTR)0x65);

  local_28.hCursor = (HCURSOR)0x0;

  local_28.hbrBackground = GetStockObject(4);

  local_28.lpszMenuName = (LPCSTR)0x0;

  local_28.lpszClassName = "XutoAssaultSplash";

  AVar1 = RegisterClassA(&local_28);

  if (AVar1 != 0) {

    pHVar2 = CreateWindowExA(0,"XutoAssaultSplash","Auto Assault",0x80000000,

                             *(int *)(unaff_ESI + 0x3190),*(int *)(unaff_ESI + 0x3194),

                             *(int *)(unaff_ESI + 0x3198),*(int *)(unaff_ESI + 0x319c),(HWND)0x0,

                             (HMENU)0x0,*(HINSTANCE *)(unaff_ESI + 0x3180),(LPVOID)0x0);

    *(HWND *)(unaff_ESI + 0x318c) = pHVar2;

  }

  if (*(HWND *)(unaff_ESI + 0x318c) == (HWND)0x0) {

    FUN_007a4480(1,"Failed to CreateWindowEx for splashscreen!");

    return;

  }

  ShowWindow(*(HWND *)(unaff_ESI + 0x318c),1);

  UpdateWindow(*(HWND *)(unaff_ESI + 0x318c));

  iVar3 = PeekMessageA(&local_44,*(HWND *)(unaff_ESI + 0x318c),0,0,1);

  while (iVar3 != 0) {

    TranslateMessage(&local_44);

    DispatchMessageA(&local_44);

    iVar3 = PeekMessageA(&local_44,*(HWND *)(unaff_ESI + 0x318c),0,0,1);

  }

  return;

}
