// =============================================================================
// __RTDynamicCast
// -----------------------------------------------------------------------------
// Stable ID: aa_004898a4
// Address:   0x004898a4–0x004898a9  (autoassault.exe, image base 0x400000)
// System:    interaction-activation (partition); CRT cross-cutting helper
// Generated: 2026-07-23 scaffold; R10-011 dual refresh 2026-08-05
// Exactness: In-image unit is a 6-byte IAT thunk. CRT body is external.
// Bit-for-bit vs retail EXE: DEFERRED for CRT DLL; thunk bytes sealed.
// =============================================================================

/*
 * Behavioral notes:
 * - OWN image body: FF 25 48 66 9C 00  =>  jmp dword ptr [0x009C6648]
 * - IAT symbol: PTR___RTDynamicCast_009c6648 → EXTERNAL __RTDynamicCast (MSVC CRT)
 * - Decompiler recursive-call display is non-authoritative.
 * - Callers: cdecl, five dwords, ADD ESP,0x14 after CALL.
 * - Parent evidence (not dualled): FUN_00938670 @ 0x00938670 uses
 *     dynamic_cast-style call CVOGClonedObjectBase → CVOGStore (VfDelta=0, isRef=0).
 *
 * Port guidance:
 * - Prefer native C++ dynamic_cast / equivalent RTTI helper; do not reimplement
 *   this IAT trampoline in AutoCore game code.
 * - When matching retail call sites, preserve 5-arg cdecl + NULL-on-fail for
 *   pointer casts (isReference == 0).
 */

#include <cstdint>

// MSVC CRT export contract (library; not the 6-byte image thunk body).
// TypeDescriptor layout is MSVC RTTI; pointers are to .rdata descriptors in-image.
extern "C" void* __cdecl __RTDynamicCast(
    void* inptr,
    long VfDelta,
    void* srcType,      // const TypeDescriptor*
    void* targetType,   // const TypeDescriptor*
    int isReference);

// ---------------------------------------------------------------------------
// Image-local view of the import trampoline (documentation / RE mirror only).
// At runtime the linker/loader binds 0x009C6648; the code at 0x004898a4 is only:
//   jmp dword ptr [__imp___RTDynamicCast]
// ---------------------------------------------------------------------------
#if defined(AUTOCORE_RE_MIRROR_IAT_THUNKS)
// Not for production AutoCore ports — illustrates in-image machine shape.
static void* __declspec(naked) __RTDynamicCast_IatThunk_Mirror()
{
    __asm {
        jmp dword ptr [0x009C6648]
    }
}
#endif

// Machine bytes (OWN body only):
//   0x004898a4: FF 25 48 66 9C 00
