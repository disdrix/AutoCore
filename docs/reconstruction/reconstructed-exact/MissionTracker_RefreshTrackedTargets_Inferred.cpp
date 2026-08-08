// =============================================================================
// MissionTracker_RefreshTrackedTargets_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0092bf60
// Address:   0x0092bf60–0x0092c075  (autoassault.exe, image base 0x400000)
// Size:      278 bytes (0x116)
// System:    inventory-transfer partition (parent 0x0092adf0); MissionTracker role
// Sealed:    2026-08-05 R11-040 dual
//            Tools: decompile + force_decompile + analyze_function_complete +
//            get_function_by_address + callers/xrefs + get_assembly_context +
//            read_memory (body + DAT floats). No disassemble_bytes.
// Exactness: Behavior-preserving rewrite of **image bytes** control flow.
//            Live Ghidra decompiler collapses the primary bind arm — bytes win.
// Bit-for-bit / runtime / diff: DEFERRED.
// Ghidra:    FUN_0092bf60
// =============================================================================
//
// PURPOSE
//   Dirty/timer MissionTracker refresh (sole caller FUN_0092c640 after bind
//   FUN_0092c080):
//     1) Clear owned T* vector at host+0x11c.
//     2) host+0x14 = 4.0f poll timer.
//     3) If character ready: origin via vtbl+0x1A0; primary multi-list filter
//        FUN_0092af80 (includes dualed 0092adf0 CBID/locker arm).
//     4) On hit: type-gate host+0xB vs clone+0x38 in {0x12,0x0E};
//        FUN_0092a440 node; copy TFID_16 from obj+0x160.
//     5) Else secondary FUN_0092b2a0(host, origin); fail clears host+0x8.
//
// ABI (image-sealed)
//   EAX = MissionTracker* host   (MOV EDI,EAX)
//   Stack args: none
//   AL  = bool
//   ADD ESP,8 ; RET
//
// SOLE CALLER
//   FUN_0092c640 @ 0x0092c67c: MOV EAX,ESI ; CALL
//
// CONSTANTS
//   DAT_00aaa690 = 4.0f     poll timer reload
//   DAT_00aaaaf8 = 1.0e9f   initial bestDistSq
// =============================================================================

#include <cstdint>
#include <cstring>

using u8  = std::uint8_t;
using u32 = std::uint32_t;

// Dualed aa_0092a3d0 — image uses EDI=host, AL=1
extern "C" u8 Tracker_ClearOwnedPtrVectorAt11c_Inferred_EDI(void* host /*EDI*/);

// Residuals — image contracts documented; not dualled by R11-040.
// FUN_0092af80: EAX=host filter ctx, ESI=&bestObj out, stack (origin, &bestDistSq)
extern "C" u8 FUN_0092af80_filter(void* host /*EAX*/, void** bestObjOut /*ESI*/,
                                  void* origin, float* bestDistSq);
// FUN_0092a440: thiscall ECX=worldObj, stack host; returns node* (0x20)
extern "C" void* __thiscall FUN_0092a440(void* worldObj /*ECX*/, void* host);
// FUN_0092b2a0: stack (host, origin); AL bool
extern "C" u8 FUN_0092b2a0(void* host, void* origin);

static constexpr float kPollTimerReload = 4.0f;   // DAT_00aaa690
static constexpr float kBestDistInit    = 1.0e9f; // DAT_00aaaaf8

// MSVC multi-inheritance this-adjust used at the vtbl+0x1A0 call site:
//   mov eax, character
//   mov edx, [eax+4]        ; complete object locator / adj table ptr
//   mov ecx, [edx+4]        ; adjust offset dword
//   mov edx, [ecx+eax+4]    ; vtbl at adjusted this
//   lea ecx, [ecx+eax+4]    ; this for call
//   call [edx+0x1A0]
static void* character_origin_vtbl1a0(void* character)
{
    auto* base = reinterpret_cast<u8*>(character);
    int*  p1   = *reinterpret_cast<int**>(base + 4);
    int   adj  = p1[1]; // [edx+4]
    u8*   self = base + adj + 4;
    void** vtbl = *reinterpret_cast<void***>(self);
    using VFn = void*(__thiscall*)(void*);
    return reinterpret_cast<VFn>(vtbl[0x1A0 / 4])(self);
}

// ---------------------------------------------------------------------------
// Primary entry — image: EAX = host
// ---------------------------------------------------------------------------
extern "C" u8 MissionTracker_RefreshTrackedTargets_Inferred(void* host /*EAX*/)
{
    void* client = *reinterpret_cast<void**>(host);
    if (client == nullptr)
        return 0;

    if (*reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xE98) == nullptr)
        return 0;

    if (*reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xE04) == nullptr)
        return 0;

    // CALL 0x0092a3d0 with EDI = host
    Tracker_ClearOwnedPtrVectorAt11c_Inferred_EDI(host);

    *reinterpret_cast<float*>(reinterpret_cast<u8*>(host) + 0x14) = kPollTimerReload;

    void* character = *reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xE98);
    if (*reinterpret_cast<u8*>(reinterpret_cast<u8*>(character) + 0x4F1) != 0)
        return 0;
    if (*reinterpret_cast<void**>(reinterpret_cast<u8*>(client) + 0xD34) == nullptr)
        return 0;

    void* origin = character_origin_vtbl1a0(character);

    void* bestObj = nullptr;
    float bestDistSq = kBestDistInit;

    // Primary multi-list filter (image EAX=host, ESI=&bestObj)
    if (FUN_0092af80_filter(host, &bestObj, origin, &bestDistSq) != 0 &&
        bestObj != nullptr) {

        // Type gate on host+0xB vs clonebase+0x38
        if (*reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x0B) != 0) {
            void* clone = *reinterpret_cast<void**>(reinterpret_cast<u8*>(bestObj) + 0xA8);
            int type = *reinterpret_cast<int*>(reinterpret_cast<u8*>(clone) + 0x38);
            if (type != 0x12 && type != 0x0E)
                *reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x0B) = 0;
        }

        void* node = FUN_0092a440(bestObj, host);
        if (node == nullptr)
            return 1; // image JZ success epilogue without TFID copy

        *reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x08) = 0;
        // TFID_16 plate (NAMING_REGISTRY objectTfId)
        std::memcpy(node, reinterpret_cast<u8*>(bestObj) + 0x160, 16);
        return 1;
    }

    // Secondary multi-target fill
    if (FUN_0092b2a0(host, origin) != 0)
        return 1;

    *reinterpret_cast<u8*>(reinterpret_cast<u8*>(host) + 0x08) = 0;
    return 0;
}
