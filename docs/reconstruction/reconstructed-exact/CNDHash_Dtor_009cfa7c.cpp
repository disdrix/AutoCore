// =============================================================================
// CNDHash_Dtor_009cfa7c
// -----------------------------------------------------------------------------
// Purpose:  CNDHash destructor for object family PTR_FUN_009cfa7c (owning):
//           SEH; re-stamp object vtbl; non-fatal lock log; FreeBuckets owning
//           (count=0, reclaim value-owning 009cefe4, free table); freelist slab
//           vector teardown at this+0x20.
//
// Address:  0x0053b920  (autoassault.exe, image base 0x400000)
// Body:     0x0053b920–0x0053b98a (107 bytes / 0x6B), bare ret
// Stable:   aa_0053b920
// System:   container / CNDHash
// Ghidra:   FUN_0053b920
//
// ABI:      __thiscall  void (CNDHash *this)  — bare ret
//
// Exactness: CF mirrors raw + read_memory; ECX adjust for freelist sealed.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W24-M seal).
//
// MACHINE residual: decompiler bare FUN_0059c8a0(); bytes lea ecx,[this+0x20].
// Scalar deleting dtor: FUN_0053b900 (vtbl[0] of 009cfa7c).
// FreeBuckets: FUN_005390d0 → reclaim FUN_00538190 (owning).
// =============================================================================

#include <cstdint>

extern void *ExceptionList;
extern void *LAB_009a3edb;
extern void *PTR_FUN_009cfa7c;

extern void FUN_007a4480(int level, const char *msg);
extern void FUN_005390d0(void *hash); // CNDHash_FreeBuckets_Owning_009cfa7c
extern void FUN_0059c8a0(void *freelistSubobject); // FreelistSlabVector_dtor

// void __thiscall — bare ret
void __fastcall CNDHash_Dtor_009cfa7c(void *thisHash)
{
    void *local_c;
    void *puStack_8;
    std::uint32_t local_4;

    // SEH prolog (simplified structural mirror of raw)
    puStack_8 = &LAB_009a3edb;
    local_c = ExceptionList;
    ExceptionList = &local_c;

    *reinterpret_cast<void **>(thisHash) = &PTR_FUN_009cfa7c;
    local_4 = 0;

    if (*reinterpret_cast<char *>(reinterpret_cast<std::uint8_t *>(thisHash) + 0x1d) != '\0') {
        FUN_007a4480(0, "HashError:Destructor, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
        // non-fatal — fall through
    }

    FUN_005390d0(thisHash); // ECX = this
    // MACHINE: lea ecx, [this+0x20]
    FUN_0059c8a0(reinterpret_cast<std::uint8_t *>(thisHash) + 0x20);

    ExceptionList = local_c;
}
