// =============================================================================
// StdList_CopyCtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402410
// Address:   0x00402410  (autoassault.exe, image base 0x400000)
// Body:      0x00402410–0x00402495 inclusive (134 B / 0x86)
// System:    shared MSVC std::list (partition seed: missions-progression)
// Generated: 2026-08-05 R10-019 dual re-verify
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Copy-construct an MSVC circular std::list object from another:
//     dest+4 = _Myhead  <- StdList_AllocEmptySentinel_Inferred()  // 0x0040fb90
//     dest+8 = _Mysize  = 0
//     range-insert [src.begin(), src.end()) before dest.end() via FUN_00404490
//   Returns dest in EAX. Stdcall RET 8 (two stack args).
//
// LAYOUT (object size 0xC — same as StdList_DefaultCtor_Inferred sibling):
//   +0x00  residual (allocator / container_base; not written here)
//   +0x04  _Myhead (sentinel node*)
//   +0x08  _Mysize (size_t; 0 then grown by insert chain)
//
// ABI (sealed — differs from default-ctor sibling's ECX thiscall):
//   [EBP+0x8] = dest list*
//   [EBP+0xC] = src list*
//   EAX out   = dest
//   RET 0x8
//
// PAIRED / SIBLING:
//   Alloc sentinel: StdList_AllocEmptySentinel_Inferred  @ 0x0040fb90
//   Default ctor:   StdList_DefaultCtor_Inferred         @ 0x004023f0  (empty only)
//   Destroy:        StdList_Destroy_FreeHead_Inferred    @ 0x00403430
//   Range insert:   FUN_00404490 → FUN_00404560 → FUN_004040f0  (residual)
//
// CALLERS:
//   FUN_00955010 @ 00955111, 0095512d, 00955d52, 00955d71,
//                 00955d91, 00955db0, 00955dcc, 00955de8  (×8 CALL)
// =============================================================================

#include <cstdint>

// Forward: dualed aa_0040fb90 — operator_new(0xc); next=prev=self; return node*
extern "C" void* __cdecl StdList_AllocEmptySentinel_Inferred(void);

// Residual: range-insert [first, last) before where into list
//   FUN_00404490(list, where, first, last) → FUN_00404560(...)
extern "C" void __cdecl FUN_00404490(void* list, void* where, void* first, void* last);

// stdcall: dest + src on stack; EAX = dest; RET 8
extern "C" void* __stdcall StdList_CopyCtor_Inferred(void* dest, void* src)
{
    // 00402410  PUSH EBP / MOV EBP,ESP / SEH frame (LAB_009bd220, state=-1)
    // 00402431  MOV ESI, [EBP+0x8]   ; dest
    // 00402436  CALL StdList_AllocEmptySentinel_Inferred
    void* head = StdList_AllocEmptySentinel_Inferred();

    // 0040243b  MOV [ESI+4], EAX
    *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(dest) + 0x4) = head;

    // 0040243e  MOV dword [ESI+8], 0
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(dest) + 0x8) = 0;

    // 00402445  SEH state = 0  (empty dest live; exception path can free head)

    // 0040244c  MOV EAX, [EBP+0xC]   ; src
    // 0040244f  MOV EAX, [EAX+4]     ; src._Myhead
    void* src_head =
        *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(src) + 0x4);

    // 0040245d  MOV EAX, [EAX]       ; src begin = head->_Next
    void* src_begin = *reinterpret_cast<void**>(src_head);

    // 00402465  MOV EDX, [ESI+4]     ; dest._Myhead
    // 0040246b  MOV EDX, [EDX]       ; where = head->_Next (empty ⇒ sentinel)
    void* dest_head =
        *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(dest) + 0x4);
    void* where = *reinterpret_cast<void**>(dest_head);

    // 00402473..00402477
    //   PUSH src_head; PUSH src_begin; PUSH where; PUSH dest
    //   CALL FUN_00404490
    // insert [src.begin(), src.end()) before dest.end()
    FUN_00404490(dest, where, src_begin, src_head);

    // 00402483  MOV EAX, ESI / restore SEH / POP* / RET 8
    return dest;
}

// Ghidra symbol alias
extern "C" void* __stdcall FUN_00402410(void* dest, void* src)
{
    return StdList_CopyCtor_Inferred(dest, src);
}
