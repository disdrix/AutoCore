// =============================================================================
// Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_007fe640
// Address:   0x007fe640  (autoassault.exe, image base 0x400000)
// System:    host / CNDHash (stamp 00a2c2e4; field owner+0x3084)
// Dual:      WQ9I-D 2026-08-04 (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed recreate ABI.
// Bit-for-bit vs retail EXE: DEFERRED (no Launcher / runtime Confirmed).
// =============================================================================
//
// PURPOSE:
//   On a host/owner object, take the CNDHash at +0x3084 (if non-null):
//     1. Soft-assert TraversalLock @ hash+0x1d; force lock = 1
//     2. Walk ordered node list (head @ hash+0x14, next @ node+0x20)
//     3. For each payload object* @ node+0xc:
//          if obj->vtbl[+0x3d8](): obj->vtbl[+0x440]()
//          if obj+0x2b0 != 0: (*(obj+0x2b0))->vtbl[+0xb0](obj)
//     4. Unlock @+0x1d = 0
//     5. CNDHash_Recreate_00a2c2e4 with EAX=hash, BL=2 (log2=2)
//
// ABI (sealed):
//   stdcall; Stack[0x4] = owner*; void; RET 4
//   Recreate handoff (hidden in decompiler): EAX = *(owner+0x3084); BL = 2
//
// CALLERS (2):
//   FUN_00934880 @ 0x009348bc  (host rebuild path)
//   FUN_009349b0 @ 0x009349d4  (host teardown path gated on +0xf40)
//
// REJECT:
//   - Named_VOG_DEBUG_STOP_* scaffold plate (assert string only)
//   - Skill thiscall recreate merge (different ABI / VA family)
//   - Claiming product English for host class or vtbl methods
//   - Hard-abort on lock errors (logs only; continues)
//
// =============================================================================

// Dualed WQ9H-E:
// void CNDHash_Recreate_00a2c2e4(void* hash /*EAX*/, unsigned char log2 /*BL*/);
// /* bare ret */

void Host_CNDHash_TraverseTeardownThenRecreate_BL2_Inferred(void* owner)
{
    void* hash = *(void**)((char*)owner + 0x3084);
    if (hash == nullptr) {
        return;
    }

    // TraversalLock — soft log if already locked, then force lock
    if (*(unsigned char*)((char*)hash + 0x1d) != 0) {
        FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
        FUN_007a4480(0, "VOG_DEBUG_STOP");
    }
    *(unsigned char*)((char*)hash + 0x1d) = 1;

    void* cursor = nullptr;
    for (;;) {
        hash = *(void**)((char*)owner + 0x3084);

        if (*(unsigned char*)((char*)hash + 0x1d) == 0) {
            FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }

        // ordered list: first node at hash+0x14; successor at node+0x20
        if (cursor == nullptr) {
            cursor = *(void**)((char*)hash + 0x14);
        } else {
            cursor = *(void**)((char*)cursor + 0x20);
        }

        void* obj = nullptr;
        if (cursor != nullptr) {
            obj = *(void**)((char*)cursor + 0xc);
        }
        if (obj == nullptr) {
            break;
        }

        // thiscall vtbl[+0x3d8] predicate
        void** vtbl = *(void***)obj;
        char ok = ((char(__thiscall*)(void*))vtbl[0x3d8 / 4])(obj);
        if (ok != 0) {
            ((void(__thiscall*)(void*))vtbl[0x440 / 4])(obj);
        }

        // secondary binding object+0x2b0 → vtbl[+0xb0](obj)
        void* secondary = *(void**)((char*)obj + 0x2b0);
        if (secondary != nullptr) {
            void** svtbl = *(void***)secondary;
            ((void(__thiscall*)(void*, void*))svtbl[0xb0 / 4])(secondary, obj);
        }
    }

    // unlock then recreate with log2 = 2 (matches host ctor seed)
    hash = *(void**)((char*)owner + 0x3084);
    *(unsigned char*)((char*)hash + 0x1d) = 0;
    // EAX = hash; BL = 2
    CNDHash_Recreate_00a2c2e4(hash, /*log2=*/2);
}
