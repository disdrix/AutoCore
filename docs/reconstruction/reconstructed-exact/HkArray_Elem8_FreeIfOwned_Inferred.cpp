// =============================================================================
// HkArray_Elem8_FreeIfOwned_Inferred  (Ghidra: FUN_00409a00)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409a00
// Address:   0x00409a00 – 0x00409a28 exclusive  (autoassault.exe, base 0x400000)
// Size:      40 bytes (0x28); epilogue plain RET; pad CC to next VA
// System:    allocator / hkArray-style free (element size 8)
// Dual:      WQ9J-J 2026-08-05 (decompile + read_memory + disassemble_function)
// Exactness: Behavior-preserving; free size includes machine AND 0x7fffffff.
//            Not modernization. Not bit-exact certified. Terminal false.
// =============================================================================
//
// PURPOSE:
//   SEH / stack dtor helper for a 12-byte array triple
//     { void* data; int size; int capacity }
//   If capacity is signed >= 0 (owned), free the buffer via DAT_00b05060
//   vtbl+0x14 with tag 0x12 and nbytes = (capacity & 0x7fffffff) * 8.
//   High-bit capacity (0x80000000-class) skips free (unowned / empty sentinel).
//
// ABI (machine):
//   __thiscall; ECX = array triple; plain ret; void
// =============================================================================

#include <cstdint>

extern int *DAT_00b05060;

// Ghidra name: FUN_00409a00
void __fastcall HkArray_Elem8_FreeIfOwned_Inferred(std::uint32_t *arr /*ECX*/)
{
  // arr[0] = data*, arr[1] = size (unused), arr[2] = capacity
  if (-1 < static_cast<int>(arr[2])) {
    // Machine: AND EAX,0x7fffffff then three ADD EAX,EAX (*8).
    // Decompiler prints bare arr[2]*8 (mask omitted).
    std::uint32_t nbytes = (arr[2] & 0x7fffffffu) * 8u;
    (**(void (***)(std::uint32_t, std::uint32_t, int))(*DAT_00b05060 + 0x14))(
        arr[0], nbytes, 0x12);
  }
}

// Scaffold twin entry (Ghidra name)
extern "C" void __fastcall FUN_00409a00(std::uint32_t *param_1)
{
  HkArray_Elem8_FreeIfOwned_Inferred(param_1);
}
