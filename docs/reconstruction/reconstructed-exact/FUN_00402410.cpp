// =============================================================================
// FUN_00402410  (Ghidra symbol twin of StdList_CopyCtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00402410
// Address:   0x00402410  (autoassault.exe, image base 0x400000)
// Body:      0x00402410–0x00402495 inclusive (134 B / 0x86)
// System:    shared MSVC std::list (partition seed: missions-progression)
// Generated: 2026-08-05 R10-019 dual re-verify (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Canonical named unit: StdList_CopyCtor_Inferred.cpp
// =============================================================================

#include <cstdint>

extern "C" void* __cdecl StdList_AllocEmptySentinel_Inferred(void);
extern "C" void __cdecl FUN_00404490(void* list, void* where, void* first, void* last);
extern "C" void* __stdcall StdList_CopyCtor_Inferred(void* dest, void* src);

// Ghidra inventory name — thin alias to named reconstruction
extern "C" void* __stdcall FUN_00402410(void* dest, void* src)
{
    return StdList_CopyCtor_Inferred(dest, src);
}

// Named implementation (kept in twin for single-TU readability; primary body in
// StdList_CopyCtor_Inferred.cpp — this file documents the FUN_* inventory path).

/*
 * Sealed CF (matches raw + live decompile + disassemble_function):
 *
 *   SEH setup (LAB_009bd220)
 *   ESI = dest = [EBP+8]
 *   head = FUN_0040fb90()                    // StdList_AllocEmptySentinel_Inferred
 *   [ESI+4] = head                           // _Myhead
 *   [ESI+8] = 0                              // _Mysize
 *   SEH state = 0
 *   src_head  = [[EBP+0xC]+4]
 *   src_begin = [src_head]
 *   where     = [[ESI+4]]                    // dest head->_Next
 *   FUN_00404490(dest, where, src_begin, src_head)
 *   EAX = ESI
 *   RET 8
 *
 * Not domain logic. Sibling empty default: StdList_DefaultCtor_Inferred @ 0x004023f0.
 */
