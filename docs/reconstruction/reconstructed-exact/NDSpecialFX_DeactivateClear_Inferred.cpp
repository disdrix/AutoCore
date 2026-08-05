// =============================================================================
// NDSpecialFX_DeactivateClear_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b7150
// Address:   0x004b7150 – 0x004b7320  (autoassault.exe, image base 0x400000)
// System:    client-fx / NDSpecialFX lifecycle
// Generated: 2026-07-29 W23-H dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction from live Ghidra decompile.
//            Twin FUN_004b7150.cpp is the line-faithful decompiler mirror
//            (includes operator_delete residual edges as decompiled).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Host-level deactivate/clear for an NDSpecialFX session/object:
//     - flush staged multi-target hits when buffer at +0x3c is present
//     - optional physics detach for owned children with +0x90e bit7
//     - mark all owned CVOG children destroy-pending (+0x90e bit0)
//     - clear attachment lists and stop sound payloads by name
//
// ABI:
//   __thiscall (ECX = fx host); no stack args; plain ret (C3).
//
// RELATED:
//   FUN_004b6980 = NDSpecialFX_FlushStagedMultiHits_Inferred (aa_004b6980)
//   FUN_007203b0 = CSoundManager_MarkStopByName_Inferred
//   Caller FUN_004b8ed0 FX destroy/timeout path invokes this then returns 1
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_004b6980(void* fx);
extern "C" void FUN_0058e300(int zero, int phys);
extern "C" void FUN_00590f00(void* a, void* b);
extern "C" void FUN_004b6e00(int zero);
extern "C" void FUN_00720d40(void* name, int flag);
extern "C" void FUN_007203b0(void* name, int flag);
extern "C" void FUN_00498a90(void);
extern "C" void FUN_00498ab0(int zero);
extern "C" void operator_delete(void* p);

// Intrusive list node layout as used by decomp (next, prev, value).
struct FxListNode {
    FxListNode* next;
    FxListNode* prev;
    void* value;
};

static FxListNode* Head(void* fx, uint32_t off)
{
    return *reinterpret_cast<FxListNode**>(static_cast<uint8_t*>(fx) + off);
}

static void ClearListHeadSize(void* fx, uint32_t head_off, uint32_t size_off)
{
    // Decomp pattern: head self-loop; size = 0. Residual first-node free edges
    // are preserved in FUN_004b7150.cpp; happy path is empty-after-reset.
    auto* head = Head(fx, head_off);
    void* first = *reinterpret_cast<void**>(head);
    *reinterpret_cast<void**>(head) = head;
    *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(head) + 4) = head;
    *reinterpret_cast<int*>(static_cast<uint8_t*>(fx) + size_off) = 0;
    if (first != head) {
        operator_delete(first);
    }
}

extern "C" void __thiscall NDSpecialFX_DeactivateClear_Inferred(void* fx)
{
    auto* base = static_cast<uint8_t*>(fx);

    // 1) Flush staged multi-target hits
    if (*reinterpret_cast<int*>(base + 0x3c) != 0) {
        FUN_004b6980(fx);
    }

    // 2) Optional physics detach for flagged children
    int* host = *reinterpret_cast<int**>(base + 0x10);
    if (host != nullptr) {
        auto** vtable = *reinterpret_cast<void***>(host);
        using Vfn = int(__thiscall*)(void*);
        int ent = reinterpret_cast<Vfn>(vtable[0x1cc / 4])(host);
        int phys = (ent != 0) ? *reinterpret_cast<int*>(ent + 8) : 0;
        if (phys != 0) {
            auto* head = Head(fx, 0x204);
            auto* n = *reinterpret_cast<FxListNode**>(head);
            if (n != head) {
                do {
                    auto* child = static_cast<uint8_t*>(n->value);
                    if ((child[0x90e] & 0x80) != 0) {
                        FUN_0058e300(0, phys);
                    }
                    n = n->next;
                } while (n != head);
            }
        }
    }

    // 3) Mark every owned child destroy-pending; clear parent link @+0x14
    {
        auto* head = Head(fx, 0x204);
        auto* n = *reinterpret_cast<FxListNode**>(head);
        if (n != head) {
            do {
                auto* child = static_cast<uint8_t*>(n->value);
                child[0x90e] = static_cast<uint8_t>(child[0x90e] | 1);
                FUN_00590f00(*reinterpret_cast<void**>(base + 0x2c),
                             *reinterpret_cast<void**>(base + 0x10));
                *reinterpret_cast<void**>(child + 0x14) = nullptr;
                n = n->next;
            } while (n != head);
        }
    }

    FUN_004b6e00(0);

    // 4) Clear list @+0x1ec / size @+0x1f0
    // Decomp: if first node != head, operator_delete(value) first (edge).
    {
        auto* head = Head(fx, 0x1ec);
        auto* n = *reinterpret_cast<FxListNode**>(head);
        if (n != head) {
            operator_delete(n->value);
            // decomp marks noreturn on this edge; retail continues only if empty
        }
        ClearListHeadSize(fx, 0x1ec, 0x1f0);
    }

    // 5) Stop sounds on list @+0x1f8 when size @+0x1fc != 0
    if (*reinterpret_cast<int*>(base + 0x1fc) != 0) {
        auto* head = Head(fx, 0x1f8);
        auto* n = *reinterpret_cast<FxListNode**>(head);
        if (n != head) {
            do {
                void* name = n->value;
                FUN_00720d40(name, 1);
                FUN_007203b0(name, 1);
                n = n->next;
            } while (n != head);
        }
    }

    // 6) Clear list @+0x1f8 / size 0; then walk aux list @+0x21c
    {
        auto* head = Head(fx, 0x1f8);
        auto* n = *reinterpret_cast<FxListNode**>(head);
        if (n == head) {
            ClearListHeadSize(fx, 0x1f8, 0x1fc);
            auto* h2 = Head(fx, 0x21c);
            auto* m = *reinterpret_cast<FxListNode**>(h2);
            if (m != h2) {
                do {
                    FUN_00498a90();
                    FUN_00498ab0(0);
                    m = m->next;
                } while (m != h2);
            }
            return;
        }
        operator_delete(n->value);
    }
}
