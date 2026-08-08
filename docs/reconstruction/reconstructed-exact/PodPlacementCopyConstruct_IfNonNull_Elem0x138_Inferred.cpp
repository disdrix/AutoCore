// =============================================================================
// PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040a6e0
// Address:   0x0040a6e0  (autoassault.exe, image base 0x400000)
// System:    util / POD placement (Logic-UI event width 0x138)
// Dual:      WQ9I-D 2026-08-04 (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler control flow + sealed ABI.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime Confirmed).
// =============================================================================
//
// PURPOSE:
//   MSVC-style null-checked placement / uninitialized copy-construct of one
//   0x138-byte POD element. If dest is non-null, forwards to the dualed leaf
//   PodCopyConstruct_Elem0x138_Inferred (0x00408880).
//
// ABI (sealed):
//   cdecl formals on stack; bare ret (parent cleans 8 bytes).
//   Stack[0x4] = void* dest
//   Stack[0x8] = const void* src
//   void return
//
// CALLERS:
//   FUN_00409f10 thin stdcall trampoline (RET 8) used by:
//     - FUN_00409cc0 ConstructN-style fill (stride +0x138)
//     - FUN_0040a4a0 uninit-copy range (stride +0x138)
//
// REJECT:
//   - Chain-of-caller SendLogicUi scaffold plate names
//   - Tree / freelist / CNDHash identity (co-located neighborhood only)
//   - Claiming product field map of the 0x138 event POD
//
// =============================================================================

// Forward: dualed WQ9H-I leaf
// void __thiscall PodCopyConstruct_Elem0x138_Inferred(void* dest /*ECX*/, const void* src /*stack*/);
// /* ret 4 */

void PodPlacementCopyConstruct_IfNonNull_Elem0x138_Inferred(
    void* dest,
    const void* src)
{
    // Live body installs SEH (LAB_009bdcb1) around the construct path.
    // Scope dword transitions 0 → 0xffffffff across the call (MSVC EH).

    if (dest != nullptr) {
        // thiscall handoff: ECX = dest, stack = src (leaf RET 4)
        PodCopyConstruct_Elem0x138_Inferred(dest, src);
    }
    // null dest: no-op (MSVC placement / uninitialized construct guard)
}
