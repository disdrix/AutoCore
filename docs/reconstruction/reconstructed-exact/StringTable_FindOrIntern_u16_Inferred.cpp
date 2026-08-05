// =============================================================================
// StringTable_FindOrIntern_u16_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004a1770
// Address:   0x004a1770 – 0x004a18a8 exclusive (312 B / 0x138)
// Module:    autoassault.exe (image base 0x400000)
// System:    global vector<basic_string> intern / lookup
// Wave:      W34-I OWN-ONLY dual 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

// Ghidra: FUN_004a1770
// Preferred: StringTable_FindOrIntern_u16_Inferred
// REJECT: Named_CalleeOf_Named_VOG_DEBUG_STOP_004a1770
//
// cdecl; bare RET; returns u16 index (hit) or size-1 after intern (miss).
// Global table shell @ 0x00b03608 (begin DAT_00b0360c, end DAT_00b03610, stride 0x1c).
// Empty table seeds "Empty" at index 0 then intern query.
// Caller FUN_004a18b0 stores u16 at +0x1dc cloudName / +0x1de skyName.

#include <cstdint>

struct StringVecShell;
struct BasicString;

// g_string_table @ 0x00b03608
// DAT_00b0360c = begin; DAT_00b03610 = end

extern "C" void FUN_004301f0(StringVecShell* self, const BasicString* value); // StringVec_PushBack

// Clean contract:
//
// unsigned StringTable_FindOrIntern_u16_Inferred(const char* name)
// {
//   for (i = 0; i < size; ++i)
//     if (compare(table[i], name) == 0) return i & 0xffff;
//   if (size == 0) push("Empty");
//   push(name);
//   return size_after - 1;
// }

extern "C" unsigned StringTable_FindOrIntern_u16_Inferred(const char* name);
// Twin symbol: FUN_004a1770
