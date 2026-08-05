// =============================================================================
// PoolHost_Acquire0x40_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00986070
// Address:   0x00986070–0x00986124 inclusive (181 B / 0xB5)
// Module:    autoassault.exe (image base 0x400000)
// System:    process pool host (*DAT_00d1f624) / HostBase aux slot
// Wave:      W33-R 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
//            Freelist shrink size and track-vector push sealed from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Acquire a 0x40 object from the pool host freelist (pop last), or
//   operator_new(0x40)+FUN_0074e380 when freelist empty. Always push the
//   result pointer onto the host track vector @+4/+8/+0xC via FUN_004406e0.
//   Return the object pointer (or 0 if new failed).
//
// SOLE CALLER: HostBase_EnsureAuxPtrs_Inferred (0x00756320, W32-Q):
//   if (flags & 1) { EBX = *DAT_00d1f624; host[+4] = PoolHost_Acquire0x40(); }
//
// RETAIL ABI: EBX=pool host; no stack formals; bare ret; EAX=obj*.
// CLEAN ABI:  explicit pool pointer (models unaff_EBX).
// SEH: LAB_009af9d3 (omitted in clean; present in retail).
// =============================================================================

#include <cstdint>

extern "C" void* operator_new(unsigned size);
extern "C" void* FUN_0074e380(void* raw); // 0x40 complete ctor
extern "C" void __fastcall FUN_00456780(unsigned new_size, void* vec_host);

// EAX=container host, ESI=&value — retail register contract for push
extern "C" void FUN_004406e0_push(void* host, void** value_slot);

// Ghidra: FUN_00986070
// Retail: pool host arrives in EBX. Clean takes it as an explicit argument.
extern "C" void* PoolHost_Acquire0x40_Inferred(void* pool)
{
    auto* base = static_cast<std::uint8_t*>(pool);
    void* begin = *reinterpret_cast<void**>(base + 0x14);
    void* end   = *reinterpret_cast<void**>(base + 0x18);
    void* result;

    const bool empty =
        begin == nullptr ||
        (static_cast<std::uint32_t>(
             (static_cast<std::uint8_t*>(end) - static_cast<std::uint8_t*>(begin)) >> 2) == 0);

    if (empty) {
        void* raw = operator_new(0x40);
        result = raw ? FUN_0074e380(raw) : nullptr;
    } else {
        // Pop last freelist entry
        result = *(reinterpret_cast<void**>(end) - 1);
        unsigned size = static_cast<unsigned>(
            (static_cast<std::uint8_t*>(end) - static_cast<std::uint8_t*>(begin)) >> 2);
        // Freelist vector host @ pool+0x10 (begin@+4, end@+8 relative)
        FUN_00456780(size - 1, base + 0x10);
    }

    // Track/issued vector @ pool+4/+8/+0xC
    FUN_004406e0_push(pool, &result);
    return result;
}

// Ghidra twin — retail EBX contract; wrapper for catalog linkage only
extern "C" void* FUN_00986070(void)
{
    // Callers must set EBX = *DAT_00d1f624 before this symbol in retail.
    return nullptr;
}
