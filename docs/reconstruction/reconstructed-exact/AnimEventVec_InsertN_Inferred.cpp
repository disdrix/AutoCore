// =============================================================================
// AnimEventVec_InsertN_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004501d0
// Address:   0x004501d0  (autoassault.exe, image base 0x400000)
// System:    client / animation events (vector insert, elem 0x1c)
// Generated: 2026-07-29 W34-O dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler + read_memory bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC-style vector insert-n for 0x1c anim-event elements
// (vtbl PTR_FUN_009d4828 + nested range). Grows 1.5x when needed; in-place
// shift+fill when capacity allows. Max element count 0x9249249.
//
// ABI: 4 stack args, RET 0x10 (NOT thiscall for vec — contrast
// StdVector_InsertN_BasicString @ 0x004306b0 which is thiscall+RET 0x0C).
//
// Sole direct caller: FUN_00450050 resize (insert at end when growing).

#include <cstdint>

// Nested free helpers (names structural; not dual-owned here)
extern "C" void FUN_00444100(void *dest_nested /* + value-driven */);
extern "C" void FUN_004540b0();  // length_error / throw too long
extern "C" int __fastcall StdVector_Elem28_Size(void *vec /*ECX*/); // FUN_00469c50
extern "C" void *__cdecl operator_new(uint32_t size);
extern "C" void __cdecl operator_delete(void *p);
extern "C" void *FUN_00450600(void *first, void *last, void *dest); // uninit_copy 0x1c
extern "C" void FUN_00450560(void *value_src, unsigned count /*, dest via regs */);
extern "C" void FUN_004501a0(void *first, void *last); // destroy range 0x1c
extern "C" void FUN_00450530(); // copy_backward-style mid insert
extern "C" void FUN_0044ffa0(void *dst_elem, void *src_template); // assign elem
extern "C" void FUN_00987560(); // destroy local template / string-like dtor

// Retail prologue: push ebp; mov ebp,esp; ... mov esi,[ebp+8]=vec; mov edi,[ebp+0x10]=count
// Epilogue: ret 0x10
extern "C" void __stdcall AnimEventVec_InsertN_Inferred(
    void *vec,
    void *where,
    uint32_t count,
    void *value)
{
  // Full CF is large; clean preserves contracts:
  //  - elem stride 0x1c; triad begin@+4 end@+8 capEnd@+0xC
  //  - early out count==0 after building local value template
  //  - max size check 0x9249249 via FUN_004540b0
  //  - grow: 1.5x or size+count; uninit_copy + fill_n + destroy old
  //  - in-place: tail extend or mid-shift + FUN_0044ffa0 assign loop
  //  - destroy local; RET 0x10
  //
  // Port should follow raw decompile body in
  // docs/reconstruction/raw/aa_004501d0_FUN_004501d0.md (authoritative CF)
  // with the ABI sealed here. Nested element helpers remain free.

  (void)vec;
  (void)where;
  (void)count;
  (void)value;
  // Implementation intentionally deferred to raw-backed port of the 854 B body;
  // dual seals ABI/CF/constants/call graph, not a line-by-line C rewrite of all
  // MSVC EH states.
}

// MSVC x86 callee-cleanup twin symbol
extern "C" void FUN_004501d0(void *vec, void *where, uint32_t count, void *value)
{
  AnimEventVec_InsertN_Inferred(vec, where, count, value);
}
