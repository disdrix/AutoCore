// =============================================================================
// NpcMissionDialog_TeardownChildWidgetLists  (was FUN_008aa320)
// -----------------------------------------------------------------------------
// Stable ID: aa_008aa320
// Address:   0x008aa320  (autoassault.exe, image base 0x400000)
// System:    missions-progression / client UI
// Body:      0x008aa320–0x008aa3ef exclusive (207 B)
//
// Purpose: Walk two dynamic child-widget pointer vectors on the NPC mission
// dialog and, for each non-null entry, invoke child vtbl+0x440 then dialog
// vtbl+0xb0(child). Used from Client_MissionDialog_FlushPreparedResponse after
// the optional 0x206E wire flush / reward UI cleanup, before dialog vtbl+0x3ac
// and FUN_00792490.
//
// ABI (custom register):
//   ESI = NpcMissionDialog* dialog
//   bare ret; saves EBX/EBP/EDI
//   NOT ECX-thiscall
//
// Vectors (dword indices on dialog*):
//   [0x1cb]/[0x1cc] → +0x72c / +0x730  (begin/end; count = (end-begin)>>2)
//   [0x1cf]/[0x1d0] → +0x73c / +0x740
//
// Does NOT clear vector storage, zero begin/end, or touch dialog+0x650.
//
// Exactness: control flow mirrors Ghidra decompile 2026-07-29 W21-T dual seal.
// Dual: reviews/A_aa_008aa320_* and B_aa_008aa320_*
// =============================================================================

#include <cstdint>

// Retail entry: ESI=dialog, bare ret.
// Written as an explicit-arg form for readability; register binding is ABI.
void NpcMissionDialog_TeardownChildWidgetLists(int* dialog /*ESI*/)
{
    int count;
    int i;

    // ---- list 1 @ +0x72c / +0x730 ----
    if (dialog[0x1cb] == 0)
        count = 0;
    else
        count = (dialog[0x1cc] - dialog[0x1cb]) >> 2;

    for (i = 0; i < count; i++) {
        int* slot = reinterpret_cast<int*>(dialog[0x1cb] + i * 4);
        if (*slot != 0) {
            int* child = reinterpret_cast<int*>(*slot);
            (**(void (**)())(*child + 0x440))();                 // child vtbl+0x440
            (**(void (**)(int))(*dialog + 0xb0))(*slot);         // dialog vtbl+0xb0(child)
        }
    }

    // ---- list 2 @ +0x73c / +0x740 ----
    if (dialog[0x1cf] == 0)
        count = 0;
    else
        count = (dialog[0x1d0] - dialog[0x1cf]) >> 2;

    for (i = 0; i < count; i++) {
        int off = i * 4;
        int childPtr = *reinterpret_cast<int*>(dialog[0x1cf] + off);
        if (childPtr != 0) {
            int* child = reinterpret_cast<int*>(childPtr);
            (**(void (**)())(*child + 0x440))();
            (**(void (**)(int))(*dialog + 0xb0))(childPtr);
        }
    }
}
