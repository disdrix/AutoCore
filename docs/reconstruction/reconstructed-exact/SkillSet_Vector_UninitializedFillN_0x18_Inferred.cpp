// =============================================================================
// SkillSet_Vector_UninitializedFillN_0x18_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00406f00
// Address:   0x00406f00–0x00406f1c exclusive (28 B; autoassault.exe base 0x400000)
// System:    STL / SkillSet vector (NPCSkillSetEntry stride 0x18)
// Generated: 2026-08-04 WQ9G-F OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of live bytes + call-site ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Supersedes: FUN_00406f00.cpp scaffold.
// Dual: reviews/A|B_aa_00406f00_SkillSet_Vector_UninitializedFillN_0x18_Inferred.md
// Caller: FUN_00412730 (SkillSet vector insert / reallocate) — 2 sites.
// Callee: FUN_00412aa0 → FUN_00412b10 (6-dword element construct).
// =============================================================================
//
// PURPOSE:
//   Uninitialized fill of n SkillSet entries (0x18 each) from a prototype value.
//   Returns the end pointer dest + n*0x18 (MSVC vector _Ufill-style).
//
// ABI: EDI=dest, ESI=count, ECX=vector* (threaded), stack=const T* value; ret 4.
// Bytes: 8B 44 24 04 50 51 8B 4C 24 0C 56 57 E8 .. 8D 14 76 83 C4 10 8D 04 D7 C2 04 00
// =============================================================================

struct NPCSkillSetEntry {
  // 0x18 bytes — six dwords; field English open (copied wholesale by ctor helper).
  unsigned char bytes[0x18];
};

// FUN_00412aa0: ECX = value*, stack dest + count; constructs count elements of 0x18.
extern "C" void __fastcall SkillSetEntry_UninitializedFillLoop_Inferred(
    const NPCSkillSetEntry* value /*ECX*/,
    NPCSkillSetEntry* dest,
    unsigned count);

// Register args EDI/ESI are part of the sealed ABI (not C++ portable).
// Clean plate documents the contract; implementation mirrors control flow.

extern "C" NPCSkillSetEntry* SkillSet_Vector_UninitializedFillN_0x18_Inferred(
    void* /*vector_ecx*/,
    NPCSkillSetEntry* dest_edi,
    unsigned count_esi,
    const NPCSkillSetEntry* value_stack)
{
  SkillSetEntry_UninitializedFillLoop_Inferred(value_stack, dest_edi, count_esi);
  // lea edx, [esi+esi*2]; lea eax, [edi+edx*8]  => dest + count*0x18
  return dest_edi + count_esi;
}
