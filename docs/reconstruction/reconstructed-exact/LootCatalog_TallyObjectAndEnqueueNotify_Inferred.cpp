// =============================================================================
// LootCatalog_TallyObjectAndEnqueueNotify_Inferred  (aa_005e0610)
// -----------------------------------------------------------------------------
// Address:   0x005e0610–0x005e07c5 exclusive (437 B / 0x1B5)
// Module:    autoassault.exe @ image base 0x400000
// System:    loot catalog counters + reaction id enqueue during CloneBase load
// Wave:      W37-AA OWN-ONLY 2026-08-04
// Exactness: Behavior-preserving from decompile + read_memory (bytes win on
//            vfunc bucket, counter indices, notify this bases). Not modernization.
//            Bit-for-bit / runtime / differential: DEFERRED (no Launcher).
// Name:      _Inferred — no product plate string; role from sealed callees/callers.
// =============================================================================

#include <cstdint>

struct CloneBaseOpaque;
struct GameObjectOpaque {
    // ...
    // +0x34 object id (uint32)
    // +0x38 type code (int)
    // +0x3c CloneBaseOpaque*
};

struct LootCatalogManagerOpaque {
    // +0x04 compared in type-0xC path
    // counters near +0x13ce0c .. +0x13cf8c
    // reaction vector grid (bases +0xC / +0x8700C after index formula)
};

// W16-C sealed pure remap: type code → row 0..11 or -1
extern "C" int __stdcall LootCatalog_TypeCodeToRowIndex_Inferred(int typeCode);

// Ensure/load path when clonebase pointer null (unowned)
extern "C" void __thiscall FUN_004f1e20(GameObjectOpaque* obj, int a, int b);

// Identity / key helper (unowned)
extern "C" int* __thiscall FUN_00418b80(void* out, uint32_t* key);

// W30-L sealed Val12 signed int-key insert-or-find
extern "C" void __thiscall StdMap_InsertOrFindByIntKey_Val12(
    void* map, void* outPair, void* value);

// Ghidra name retained: vector push of one dword (object id)
extern "C" void __thiscall CVOGReaction_FailMissionNotify(
    void* idVector, const uint32_t* objectId);

// ABI: __thiscall ECX=manager*; stack object*, bandIndex, notifyPath; RET 0x0C
extern "C" void __thiscall LootCatalog_TallyObjectAndEnqueueNotify_Inferred(
    LootCatalogManagerOpaque* mgr, /* ECX */
    GameObjectOpaque* obj,
    int bandIndex,
    int notifyPath)
{
    auto* cb = *reinterpret_cast<CloneBaseOpaque**>(
        reinterpret_cast<char*>(obj) + 0x3c);
    // vfunc at [vtable+0x14]; return used as category bucket
    int vfuncRet = 0;
    {
        auto** vt = *reinterpret_cast<void***>(cb);
        using Vfn = int(__thiscall*)(CloneBaseOpaque*);
        vfuncRet = reinterpret_cast<Vfn>(vt[0x14 / sizeof(void*)])(cb);
    }

    int type = *reinterpret_cast<int*>(reinterpret_cast<char*>(obj) + 0x38);
    uint32_t objectId =
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(obj) + 0x34);
    // race short: retail MOVSX from cb+0x4b8 between TEST and JNZ (flags kept)
    int16_t race = *reinterpret_cast<int16_t*>(
        reinterpret_cast<char*>(cb) + 0x4b8);

    if (cb == nullptr) {
        FUN_004f1e20(obj, 0, 1);
    }
    cb = *reinterpret_cast<CloneBaseOpaque**>(
        reinterpret_cast<char*>(obj) + 0x3c);
    if (cb == nullptr) {
        return;
    }

    int16_t kind = *reinterpret_cast<int16_t*>(
        reinterpret_cast<char*>(cb) + 0x3f4);
    if (kind == 0x0B) {
        type = 0x46;
    } else if (kind == 0x0A) {
        type = 0x44;
    } else {
        type = *reinterpret_cast<int*>(reinterpret_cast<char*>(obj) + 0x38);
        if (type == 0x0C) {
            uint8_t f536 = *reinterpret_cast<uint8_t*>(
                reinterpret_cast<char*>(cb) + 0x536);
            uint8_t f535 = *reinterpret_cast<uint8_t*>(
                reinterpret_cast<char*>(cb) + 0x535);
            uint32_t idCopy = objectId;
            alignas(4) uint8_t outIt[4];
            int* keyIt = FUN_00418b80(outIt, &idCopy);
            int mgrKey = *reinterpret_cast<int*>(
                reinterpret_cast<char*>(mgr) + 4);
            if (*keyIt == mgrKey && (f536 & 4) == 0 && f535 != 0) {
                // Val12 value: key@+0 = objectId; payload from cb+0x535/0x536 bits
                // (exact dword layout residual — insert-or-find sealed W30-L)
                alignas(4) uint8_t val[0x0C]{};
                *reinterpret_cast<uint32_t*>(val) = objectId;
                *reinterpret_cast<uint32_t*>(val + 4) = static_cast<uint32_t>(f535);
                *reinterpret_cast<uint32_t*>(val + 8) =
                    (static_cast<uint32_t>(f536 >> 1) & 1u);
                alignas(4) uint8_t outPair[8];
                // retail: ECX = manager (ESI), stack (outPair*, value*)
                StdMap_InsertOrFindByIntKey_Val12(mgr, outPair, val);
            }
        }
    }

    if (vfuncRet == -1 && type == 0x0E) {
        return;
    }

    // Bytes: SUB/JZ ladder → M in {0,1,2,3}
    int M = 3;
    if (vfuncRet == 0) M = 0;
    else if (vfuncRet == 1) M = 1;
    else if (vfuncRet == 2) M = 2;

    int R = LootCatalog_TypeCodeToRowIndex_Inferred(type);
    if (R < 0) {
        return;
    }

    int P = (bandIndex > 0) ? (bandIndex - 1) : 0;
    int S = static_cast<int>(race);
    auto* base = reinterpret_cast<char*>(mgr);
    ++*reinterpret_cast<int*>(base + 0x13ce0c + M * 4);
    ++*reinterpret_cast<int*>(base + 0x13ce1c + P * 4);
    ++*reinterpret_cast<int*>(base + 0x13cf5c + R * 4);
    ++*reinterpret_cast<int*>(base + 0x13cf8c + S * 4);

    if (notifyPath != 0 && notifyPath != 1) {
        return;
    }

    // t = 0x50*(R + 12*M) + P; u = 16*(S + 9*t)
    int t = 0x50 * (R + 12 * M) + P;
    int u = 16 * (S + 9 * t);
    void* idVec = base + u + (notifyPath == 1 ? 0x0C : 0x8700C);
    CVOGReaction_FailMissionNotify(idVec, &objectId);
}

// Ghidra twin
extern "C" void __thiscall FUN_005e0610(
    LootCatalogManagerOpaque* mgr,
    GameObjectOpaque* obj,
    int bandIndex,
    int notifyPath)
{
    LootCatalog_TallyObjectAndEnqueueNotify_Inferred(mgr, obj, bandIndex, notifyPath);
}
