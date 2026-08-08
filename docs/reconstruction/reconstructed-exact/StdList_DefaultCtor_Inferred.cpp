// =============================================================================
// StdList_DefaultCtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004023f0
// Address:   0x004023f0  (autoassault.exe, image base 0x400000)
// Body:      0x004023f0–0x00402405 inclusive (22 B / 0x16)
// System:    shared MSVC std::list (partition seed: missions-progression)
// Generated: 2026-08-05 MEGA-052 dual re-verify
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================
//
// PURPOSE:
//   Default-construct an empty MSVC circular std::list object:
//     this+4 = _Myhead  <- StdList_AllocEmptySentinel_Inferred()  // 0x0040fb90
//     this+8 = _Mysize  = 0
//   Returns this in EAX. Plain RET (no stack args).
//
// LAYOUT (object size 0xC — vector-ctor element stride):
//   +0x00  residual (allocator / container_base; not written here)
//   +0x04  _Myhead (sentinel node*)
//   +0x08  _Mysize (size_t)
//
// PAIRED:
//   Alloc sentinel: StdList_AllocEmptySentinel_Inferred  @ 0x0040fb90
//   Destroy:        StdList_Destroy_FreeHead_Inferred    @ 0x00403430
//
// RETIRED SCAFFOLD NAME:
//   Named_CalleeOf_CVOGReaction_Dispatch_004023f0  (parent-seed only; not domain logic)
//
// CALLERS (sample):
//   CVOGReaction_Dispatch @ 0x0057c9c7
//   CVOGVariable_EvaluateComputed @ 0x005afe6c
//   FUN_0089bc30 / FUN_008edc80 / FUN_008a8770 (stack locals)
//   DATA: FUN_004e80c0 / FUN_008a5c90 (eh_vector_constructor_iterator element ctor)
// =============================================================================

#include <cstdint>

// Forward: dualed aa_0040fb90 — operator_new(0xc); next=prev=self; return node*
extern "C" void* __cdecl StdList_AllocEmptySentinel_Inferred(void);

// ECX = this list*; no stack args; EAX = this; RET
extern "C" void* __fastcall StdList_DefaultCtor_Inferred(void* self)
{
    // 004023f0  PUSH ESI / MOV ESI, ECX
    // 004023f3  CALL StdList_AllocEmptySentinel_Inferred
    void* head = StdList_AllocEmptySentinel_Inferred();

    // 004023f8  MOV [ESI+4], EAX
    *reinterpret_cast<void**>(reinterpret_cast<std::uint8_t*>(self) + 0x4) = head;

    // 004023fb  MOV dword [ESI+8], 0
    *reinterpret_cast<std::uint32_t*>(reinterpret_cast<std::uint8_t*>(self) + 0x8) = 0;

    // 00402402  MOV EAX, ESI / POP ESI / RET
    return self;
}

// Ghidra symbol alias
extern "C" void* __fastcall FUN_004023f0(void* self)
{
    return StdList_DefaultCtor_Inferred(self);
}
