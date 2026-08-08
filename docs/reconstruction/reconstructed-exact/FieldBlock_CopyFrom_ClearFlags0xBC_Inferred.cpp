// =============================================================================
// FieldBlock_CopyFrom_ClearFlags0xBC_Inferred  (aa_00416240)
// -----------------------------------------------------------------------------
// Address:   0x00416240 – 0x0041625d exclusive (29 B / 0x1D)
//            autoassault.exe, image base 0x400000
// Wave:      WQ9I-H OWN-ONLY dual 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler CF + full-body bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// ABI:       ECX=dest; stack src; RET 4; returns dest*
// Callee:    FUN_00416160 (selective field-block assign; WQ9I-G OWN)
// =============================================================================

#include <cstdint>

// Selective field-block assign (WQ9I-G). dest flags @ +0xBC (dword index 0x2f)
// control which ranges copy; always copies mid fields and src flags into dest,
// then bumps generation at dest+0xB4.
extern "C" void __thiscall FUN_00416160(void* dest, const void* src); // 0x00416160

// ECX = dest; stack src; RET 4; returns dest*.
// Clear dest flag dword @ +0xBC, then selective-copy from src via FUN_00416160.
// Note: FUN_00416160 unconditionally overwrites dest+0xBC from src; pre-clear
// still executes (possible alias/gen side-effect intent; not product-proven).
extern "C" void* __thiscall FieldBlock_CopyFrom_ClearFlags0xBC_Inferred(
    void* dest,
    const void* src)
{
  *reinterpret_cast<uint32_t*>(static_cast<uint8_t*>(dest) + 0xBC) = 0u;
  FUN_00416160(dest, src);
  return dest;
}

// Scaffold / Ghidra alias
extern "C" void* __thiscall FUN_00416240(void* dest, const void* src)
{
  return FieldBlock_CopyFrom_ClearFlags0xBC_Inferred(dest, src);
}
