// =============================================================================
// Client_Interact_OpenCVOGStore_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00938670
// Address:   0x00938670  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-027 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler + assembly CF.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime this wave).
// Ghidra:    FUN_00938670
// Retired:   Named_CalleeOf_Client_InteractClickPickTarget_00938670
// =============================================================================

// PURPOSE:
//   Client interact path that opens a CVOGStore UI from a 16-byte TFID.
//   1) If the local vehicle entity is present, park it: flag@+0x109=1,
//      handbrake=1, longitudinal input=0.
//   2) Resolve TFID → object, dynamic_cast ClonedObjectBase → CVOGStore.
//   3) Early-out if the matching store dialog is already visible on this store.
//   4) Emit C2S sector packet opcode 0x2024 (size 0x18) with the TFID.
//   5) Stamp TFID into dialog host storage and open dialog index 0x0B or 0x0C
//      (selected by store byte +0x4e5) via FUN_007fef20.
//
// ABI (assembly-sealed):
//   - ESI live-in = ClientController* (not ECX thiscall).
//   - Stack: TFID_16 as four dwords; RET 0x10.
//   - Body: 0x00938670–0x009387dc (0x16D bytes).
//
// Callers:
//   - Client_InteractClickPickTarget @ 0x00924f8c (clone type case 0x16)
//   - FUN_00946c00 @ 0x00947057 (sector event case 3)

#include <cstdint>

struct TFID_16 {
    uint32_t dwCoidLo;
    uint32_t dwCoidHi;
    uint32_t mid;
    uint32_t hi;
};

struct TypeDescriptor;

// Externs (Ghidra-named / dualed elsewhere)
extern "C" {
void __thiscall VehicleEntity_SetFlag_109(void* entity, uint8_t value);
void __thiscall VehicleEntity_SetHandbrake(void* entity, int value);
void __thiscall VehicleEntity_SetLongitudinalInput(void* entity, int value);
void* /*thiscall-ish ECX=objMgr*/ Object_ResolveFromTFID(void* objMgr, TFID_16* tfid);
void* __cdecl __RTDynamicCast(void* obj, uint32_t vfDelta,
    TypeDescriptor* src, TypeDescriptor* dst, uint32_t isRef);
// Client dialog open hub — ECX=client, stack (dialogIndex, openFlag, extra)
void __thiscall FUN_007fef20(void* client, int dialogIndex, int openFlag, int extra);
}

extern TypeDescriptor CVOGClonedObjectBase_RTTI; // VA 0x00af8e10  .?AVCVOGClonedObjectBase@@
extern TypeDescriptor CVOGStore_RTTI;            // VA 0x00afe0c8  .?AVCVOGStore@@

// Layout offsets (client / store) — sealed from disassemble_function
enum : uint32_t {
    kClient_VehicleHolder   = 0x0e98,  // -> +0x250 entity*
    kClient_WorldBlob       = 0x0e04,  // -> +0xe4e8 object manager*
    kClient_Communicator    = 0x0c78,
    kClient_DialogHost_0B   = 0x105c,  // dialog table 0x1030 + 0x0B*4
    kClient_DialogHost_0C   = 0x1060,  // dialog table 0x1030 + 0x0C*4
    kEntitySlot             = 0x0250,
    kStore_SubtypeFlag      = 0x04e5,  // selects dialog 0xB vs 0xC
    kHost0B_BoundStore       = 0x0588,
    kHost0C_BoundStore       = 0x05a0,
    kHost0B_TfidSlot        = 0x0528,
    kHost0C_TfidSlot        = 0x0548,
    kVtbl_IsVisible         = 0x03d8,
    kVtbl_SendPacket        = 0x0018,
    kDialogIndex_StoreA     = 0x0B,
    kDialogIndex_StoreB     = 0x0C,
    kOpcode_StoreInteract   = 0x2024,
};

// MSVC retail shape: ESI this + stdcall TFID (not standard __thiscall).
// Port note: pass client explicitly; do not invent ECX-thiscall without rewriting callers.
void Client_Interact_OpenCVOGStore_Inferred(void* client /*ESI*/, TFID_16 storeTfid)
{
    // Stage 1 — vehicle park for store UI
    void* vehHolder = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(client) + kClient_VehicleHolder);
    void* entity = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(vehHolder) + kEntitySlot);
    if (entity != nullptr) {
        VehicleEntity_SetFlag_109(entity, 1);
        VehicleEntity_SetHandbrake(entity, 1);
        VehicleEntity_SetLongitudinalInput(entity, 0);
    }

    // Stage 2 — resolve + RTTI to CVOGStore
    void* world = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(client) + kClient_WorldBlob);
    void* objMgr = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(world) + 0xe4e8);
    void* obj = Object_ResolveFromTFID(objMgr, &storeTfid);
    void* store = __RTDynamicCast(obj, 0,
        &CVOGClonedObjectBase_RTTI, &CVOGStore_RTTI, 0);
    if (store == nullptr) {
        return;
    }

    auto storeFlag = *reinterpret_cast<uint8_t*>(
        reinterpret_cast<uint8_t*>(store) + kStore_SubtypeFlag);

    // Stage 3 — already-open same store early-outs
    if (storeFlag == 0) {
        void* hostB = *reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(client) + kClient_DialogHost_0B);
        auto** vtblB = *reinterpret_cast<void***>(hostB);
        using VisibleFn = char(__thiscall*)(void*);
        char visible = reinterpret_cast<VisibleFn>(vtblB[kVtbl_IsVisible / 4])(hostB);
        if (visible != 0) {
            void* bound = *reinterpret_cast<void**>(
                reinterpret_cast<uint8_t*>(hostB) + kHost0B_BoundStore);
            if (bound == store) {
                return;
            }
        }
        // re-check flag (matches retail branch that can skip 0xC path)
        storeFlag = *reinterpret_cast<uint8_t*>(
            reinterpret_cast<uint8_t*>(store) + kStore_SubtypeFlag);
        if (storeFlag == 0) {
            goto send_and_open;
        }
    }

    {
        void* hostC = *reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(client) + kClient_DialogHost_0C);
        auto** vtblC = *reinterpret_cast<void***>(hostC);
        using VisibleFn = char(__thiscall*)(void*);
        char visible = reinterpret_cast<VisibleFn>(vtblC[kVtbl_IsVisible / 4])(hostC);
        if (visible != 0) {
            void* bound = *reinterpret_cast<void**>(
                reinterpret_cast<uint8_t*>(hostC) + kHost0C_BoundStore);
            if (bound == store) {
                return;
            }
        }
    }

send_and_open:
    // Stage 4 — C2S 0x2024
    struct {
        uint32_t opcode;
        uint32_t pad; // decompiler shows auStack_18[2]; layout is 0x18 total with TFID
        TFID_16 tfid;
    } pkt{};
    // Assembly stores opcode at [ESP+8] after pushes and TFID at +0x10..+0x1c;
    // send size is 0x18. Port: opcode + 16-byte TFID is the payload contract.
    uint32_t sendBuf[6] = {};
    sendBuf[0] = kOpcode_StoreInteract;
    sendBuf[2] = storeTfid.dwCoidLo;
    sendBuf[3] = storeTfid.dwCoidHi;
    sendBuf[4] = storeTfid.mid;
    sendBuf[5] = storeTfid.hi;

    void* comm = *reinterpret_cast<void**>(
        reinterpret_cast<uint8_t*>(client) + kClient_Communicator);
    if (comm != nullptr) {
        auto** vtbl = *reinterpret_cast<void***>(comm);
        using SendFn = void(__thiscall*)(void*, int, void*, int, int);
        reinterpret_cast<SendFn>(vtbl[kVtbl_SendPacket / 4])(
            comm, -1, sendBuf, 0x18, 0);
    }

    // Stage 5 — stamp TFID + open dialog 0xB or 0xC
    uint32_t* slot;
    int dialogIndex;
    storeFlag = *reinterpret_cast<uint8_t*>(
        reinterpret_cast<uint8_t*>(store) + kStore_SubtypeFlag);
    if (storeFlag == 0) {
        void* hostB = *reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(client) + kClient_DialogHost_0B);
        slot = reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint8_t*>(hostB) + kHost0B_TfidSlot);
        dialogIndex = kDialogIndex_StoreA;
    } else {
        void* hostC = *reinterpret_cast<void**>(
            reinterpret_cast<uint8_t*>(client) + kClient_DialogHost_0C);
        slot = reinterpret_cast<uint32_t*>(
            reinterpret_cast<uint8_t*>(hostC) + kHost0C_TfidSlot);
        dialogIndex = kDialogIndex_StoreB;
    }
    slot[0] = storeTfid.dwCoidLo;
    slot[1] = storeTfid.dwCoidHi;
    slot[2] = storeTfid.mid;
    slot[3] = storeTfid.hi;

    FUN_007fef20(client, dialogIndex, 1, 0);
}
