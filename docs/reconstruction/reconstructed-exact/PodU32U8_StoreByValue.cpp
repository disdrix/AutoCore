// =============================================================================
// PodU32U8_StoreByValue
// -----------------------------------------------------------------------------
// Stable ID: aa_0043e8f0
// Address:   0x0043e8f0–0x0043e902  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043e8f0
// System:    POD store adapter (by-value stack → split-pointer store)
// Dual:      W33-M 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI:
//   ESI  = dest (void*; NOT null-checked)
//   stack = uint32_t u32_val, uint32_t u8_val (low byte used)
//   bare RET (cdecl — callers ADD ESP,8 after CALL)
//   returns dest in EAX
//
// Body (19 B): LEA/PUSH &u8_val; LEA ECX,&u32_val; MOV EAX,ESI;
//              CALL PodU32U8_StoreSplit (0x0043ea50, RET 4); MOV EAX,ESI; RET.
// Writes 5 bytes at dest via nested StoreSplit (u32 @ +0, u8 @ +4).
// Name is structural (_Inferred). Product/PDB open.
// =============================================================================

#include <cstdint>

// Nested leaf sealed W32-M.
extern "C" void PodU32U8_StoreSplit(void* dest /*EAX*/,
                                    const uint32_t* pU32 /*ECX*/,
                                    const uint8_t* pU8 /*stack*/);

// Clean surface: ESI dest + by-value stack formals made explicit.
void* PodU32U8_StoreByValue(void* dest /*ESI; retail*/,
                            uint32_t u32_val /*stack*/,
                            uint32_t u8_val /*stack; low byte*/)
{
  const uint8_t u8 = static_cast<uint8_t>(u8_val);
  PodU32U8_StoreSplit(dest, &u32_val, &u8);
  return dest;
}
