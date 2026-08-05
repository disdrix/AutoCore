// =============================================================================
// UI_MissionJournalRow_ApplySelection_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0082a050
// Address:   0x0082a050  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0082a050
// System:    missions-progression / journal UI
// Generated: 2026-07-29 W24-K dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md
//            reviews/B_aa_0082a050_UI_MissionJournalRow_ApplySelection_Inferred.md
// =============================================================================
//
// PURPOSE:
//   Apply a journal-row selection triple into row chrome:
//     kind 0 / null → clear selection + hide title
//     kind 1 → "[level] name" title from mission def; journal-ready → "(Complete)"
//     kind 2 → title from secondary string payload
//   Always ends in layout helper FUN_00829fa0.
//
// ABI: ECX = row widget*; EAX = SelectionTriple*; no stack formals; ret.
// Widget fields (sealed):
//   +0x500 kind, +0x504 p1, +0x508 p2, +0x4fe flag
//   +0x52c title widget*, +0x530 complete-label widget*, +0x524 aux*
// =============================================================================

#include <cstdint>
#include <cstdio>

struct SelectionTriple {
    std::int32_t kind; // low byte used as discriminant
    void* p1;
    void* p2;
};

// Callees (product names open unless dual-sealed elsewhere)
extern "C" void FUN_007a69d0();
extern "C" char* FUN_007a6de0(void* string_id_or_ptr);
extern "C" char FUN_0052b3b0(void* character /*ECX*/, void* mission /*stack*/); // IsMissionJournalReady
extern "C" void FUN_0092d580();
extern "C" std::uint8_t FUN_006a3db0();
extern "C" void FUN_00829fa0();
extern void* DAT_00d1b6d8; // local character*

using vfn = void*(__thiscall*)(void*, ...);

static inline void* vcall(void* obj, std::uint32_t off)
{
    auto** vt = *reinterpret_cast<void***>(obj);
    return reinterpret_cast<vfn>(vt[off / 4])(obj);
}

void __fastcall UI_MissionJournalRow_ApplySelection_Inferred(
    void* row_widget /*ECX*/,
    SelectionTriple* sel /*EAX — register arg, decompiler in_EAX*/)
{
    auto* row = reinterpret_cast<std::uint32_t*>(row_widget);
    char buf[500];

    if (sel == nullptr || *reinterpret_cast<char*>(&sel->kind) == 0) {
        row[0x140] = 0;
        row[0x141] = 0;
        row[0x142] = 0;
        *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(row) + 0x4fe) = 0;
        if (row[0x14b] != 0) {
            // set empty text; hide
            (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0x1d8);
            (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0xcc);
        }
        (void)vcall(row_widget, 0xcc);
        (void)vcall(row_widget, 0x34c);
    } else {
        FUN_007a69d0();
        row[0x140] = static_cast<std::uint32_t>(sel->kind);
        row[0x141] = reinterpret_cast<std::uint32_t>(sel->p1);
        row[0x142] = reinterpret_cast<std::uint32_t>(sel->p2);
        const char kind = static_cast<char>(row[0x140]);
        *reinterpret_cast<std::uint8_t*>(reinterpret_cast<char*>(row) + 0x4fe) = 0;

        if (kind == 1) {
            if (row[0x14b] != 0) {
                auto* mission_holder = reinterpret_cast<std::uint8_t*>(row[0x141]);
                auto* mission = *reinterpret_cast<std::uint8_t**>(mission_holder + 0x14c);
                const short level = *reinterpret_cast<short*>(mission + 0x11c);
                char* name = FUN_007a6de0(*reinterpret_cast<void**>(mission + 0x14c));
                std::sprintf(buf, "[%d] %s", static_cast<int>(level), name);
                (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0x1d8);
                (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0x21c);
                (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0xcc);
                if (DAT_00d1b6d8 != nullptr) {
                    // local character vbase +0x27c refresh (exact this adj in decompile)
                }
                FUN_0092d580();
                // Title recolor: three FUN_006a3db0 samples + alpha from slot-1 color dword
                (void)FUN_006a3db0();
                (void)FUN_006a3db0();
                (void)FUN_006a3db0();
                (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0x15c);
            }
        } else if (kind == 2 && row[0x14b] != 0) {
            (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0x1d8);
            (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0xcc);
            (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0x15c);
        }

        if (row[0x14c] != 0) {
            bool ready = false;
            if (row[0x141] != 0 && DAT_00d1b6d8 != nullptr) {
                auto* mission_holder = reinterpret_cast<std::uint8_t*>(row[0x141]);
                void* mission = *reinterpret_cast<void**>(mission_holder + 0x14c);
                // Image: thiscall FUN_0052b3b0(ECX=DAT_00d1b6d8, mission)
                ready = FUN_0052b3b0(DAT_00d1b6d8, mission) != 0;
            }
            (void)ready; // drives set-text "" vs "(Complete)" via label vtbl+0x1d8
            (void)vcall(reinterpret_cast<void*>(row[0x14c]), 0x1d8);
            if (row[0x14b] != 0) {
                (void)vcall(reinterpret_cast<void*>(row[0x14b]), 0x164);
                (void)vcall(reinterpret_cast<void*>(row[0x14c]), 0x154);
            }
            (void)vcall(reinterpret_cast<void*>(row[0x14c]), 0x34c);
        }

        if (row[0x149] != 0) {
            (void)vcall(reinterpret_cast<void*>(row[0x149]), 0xd4);
            FUN_00829fa0();
            return;
        }
    }
    FUN_00829fa0();
}
