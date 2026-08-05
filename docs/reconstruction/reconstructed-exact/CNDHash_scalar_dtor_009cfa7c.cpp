// =============================================================================
// CNDHash_scalar_dtor_009cfa7c
// -----------------------------------------------------------------------------
// Purpose:  MSVC scalar-deleting destructor for owning CNDHash family
//           PTR_FUN_009cfa7c: run body dtor FUN_0053b920, then if flags&1
//           operator_delete(this). Returns this. ret 4.
//
// Address:  0x0053b900  (autoassault.exe, image base 0x400000)
// Body:     0x0053b900–0x0053b91d (30 B incl. CC pad; live ret at end)
// Stable:   aa_0053b900
// System:   container / CNDHash
// Ghidra:   FUN_0053b900
//
// ABI:      __thiscall  void*(CNDHash *this, unsigned char flags)  — ret 4
//
// Exactness: CF mirrors raw + read_memory. Decompiler noreturn on delete is residual.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W25-H seal).
//
// Vtbl:     dword0 of 0x009cfa7c = this entry.
// Body:     CNDHash_Dtor_009cfa7c (FUN_0053b920) — W24-M dual.
// =============================================================================

extern "C" void operator_delete(void *);

// Body dtor — bare ret thiscall
extern void __fastcall FUN_0053b920(void *thisHash); // CNDHash_Dtor_009cfa7c

void *__thiscall CNDHash_scalar_dtor_009cfa7c(void *thisHash, unsigned char flags)
{
    FUN_0053b920(thisHash);

    if ((flags & 1) != 0) {
        operator_delete(thisHash);
    }
    return thisHash;
}
