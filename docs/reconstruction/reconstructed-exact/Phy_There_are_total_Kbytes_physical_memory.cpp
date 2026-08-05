// =============================================================================
// Phy_There_are_total_Kbytes_physical_memory
// -----------------------------------------------------------------------------
// Stable ID: aa_00575c20
// Address:   0x00575c20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Phy_There_are_total_Kbytes_physical_memory @ 0x00575c20
// Stable ID: aa_00575c20
// Embedded strings (evidence for future rename):
//   - "Using %*ld bytes. \r\n"
//   - "%ld percent of system memory is in use. \r\n"
//   - " \r\n"
//   - "There are %*ld total Kbytes of physical memory. \r\n"
//   - "There are %*ld free Kbytes of physical memory. \r\n"
//   - "There are %*ld total Kbytes of paging file. \r\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×2, while×2, do×1, return×1.
//  - Notable callees: _snprintf×8, HeapWalk×2, Phy_There_are_total_Kbytes_physical_memory, GetProcessHeaps, GlobalMemoryStatus.
//  - Strings: "Using %*ld bytes. \r\n"; "%ld percent of system memory is in use. \r\n"; " \r\n"; "There are %*ld total Kbytes of physical memory. \r\n".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "There are %*ld total Kbytes of physical memory. 
"
 * Domain alias of FUN_00575c20 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void Phy_There_are_total_Kbytes_physical_memory(basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>

                  *param_1)



{

  DWORD DVar1;

  int iVar2;

  int iVar3;

  HANDLE *ppvVar4;

  _MEMORYSTATUS _Stack_4043c;

  _PROCESS_HEAP_ENTRY _Stack_4041c;

  char acStack_40400 [1024];

  HANDLE apvStack_40000 [65536];

  

  DVar1 = GetProcessHeaps(0x10000,apvStack_40000);

  iVar3 = 0;

  if (DVar1 != 0) {

    ppvVar4 = apvStack_40000;

    do {

      _Stack_4041c.lpData = (PVOID)0x0;

      iVar2 = HeapWalk(*ppvVar4,&_Stack_4041c);

      while (iVar2 != 0) {

        if (((byte)_Stack_4041c.wFlags & 4) != 0) {

          iVar3 = iVar3 + _Stack_4041c.cbData;

        }

        iVar2 = HeapWalk(*ppvVar4,&_Stack_4041c);

      }

      ppvVar4 = ppvVar4 + 1;

      DVar1 = DVar1 - 1;

    } while (DVar1 != 0);

  }

  _snprintf(acStack_40400,0x400,"Using %*ld bytes. \r\n",7,iVar3);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  GlobalMemoryStatus(&_Stack_4043c);

  _snprintf(acStack_40400,0x400,"%ld percent of system memory is in use. \r\n",

            _Stack_4043c.dwMemoryLoad);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1," \r\n");

  _snprintf(acStack_40400,0x400,"There are %*ld total Kbytes of physical memory. \r\n",7,

            _Stack_4043c.dwTotalPhys >> 10);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  _snprintf(acStack_40400,0x400,"There are %*ld free Kbytes of physical memory. \r\n",7,

            _Stack_4043c.dwAvailPhys >> 10);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  _snprintf(acStack_40400,0x400,"There are %*ld total Kbytes of paging file. \r\n",7,

            _Stack_4043c.dwTotalPageFile >> 10);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  _snprintf(acStack_40400,0x400,"There are %*ld free Kbytes of paging file. \r\n",7,

            _Stack_4043c.dwAvailPageFile >> 10);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  _snprintf(acStack_40400,0x400,"There are %*ld total Kbytes of virtual memory. \r\n",7,

            _Stack_4043c.dwTotalVirtual >> 10);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  _snprintf(acStack_40400,0x400,"There are %*ld free Kbytes of virtual memory. \r\n",7,

            _Stack_4043c.dwAvailVirtual >> 10);

  std::basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>::append

            (param_1,acStack_40400);

  return;

}
