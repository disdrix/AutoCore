// =============================================================================
// Vehicle_ResolveFirstHardpointOccupantTfid_Inferred  (was FUN_004f8b80)
// Address:  0x004f8b80  Stable: aa_004f8b80
// System:   skills-abilities
//
// Sole caller: Client_Skill_ResolveCastTarget @ 0x0093b3a0
//   Path: outFlags&4 && skill+0x614&8 → this helper; miss → "No enemies found."
//
// Walk (asm Confirmed):
//   table = *(vehicle+0x260)   // weapon hardpoint ptr[3]
//   for off in {0,4,8}:
//     slot = *(table+off); vtbl+0x40; list = slot+0x13c; count list+0x24
//     lock+iterate list → obj = *(listValue+4); return obj+0x160
//   else &DAT_009cd0f8 (coid 0xFFFFFFFF/0xFFFFFFFF)
//
// Table identity: weapon (FUN_004fe110 "Tried to equip same weapon %d").
// Method name INFERRED — no product symbol string in body.
// Dual: reviews/A|B_aa_004f8b80_Vehicle_ResolveFirstHardpointOccupantTfid_Inferred.md
// =============================================================================

#include <cstdint>
#include <windows.h>

// thiscall list: EnterCriticalSection(list+4); list+0x28 = 1 (traversal lock)
extern void __fastcall FUN_004294f0(int list);
// thiscall list; outCursor; outListValue. ret 0 = has element, 1 = done
extern unsigned __fastcall FUN_004022a0(int list, int* outCursor, int* outListValue);
extern std::uint32_t DAT_009cd0f8;

// Returns pointer to 16-byte TFID (occupant+0x160) or &DAT_009cd0f8 sentinel.
std::uint32_t* __fastcall Vehicle_ResolveFirstHardpointOccupantTfid_Inferred(int vehicle)
{
    // asm: mov ecx, [vehicle+0x260]; mov esi, [ecx+ebp]
    int* slotTable = *reinterpret_cast<int**>(vehicle + 0x260);

    for (int off = 0; off < 0xc; off += 4) {
        int* slot = *reinterpret_cast<int**>(reinterpret_cast<char*>(slotTable) + off);
        if (slot == nullptr) {
            continue;
        }

        // vtbl+0x40 → active/valid slot?
        char active = (**(char(**)())(*slot + 0x40))();
        if (active == '\0') {
            continue;
        }

        int list = slot[0x4f]; // +0x13c
        if (list == 0 || *reinterpret_cast<unsigned*>(list + 0x24) == 0) {
            continue;
        }

        int cursor = 0;
        int listValue = 0;
        FUN_004294f0(list);
        unsigned done = FUN_004022a0(list, &cursor, &listValue);
        while (done == 0) {
            // asm: mov edx, listValue; mov edi, [edx+4]
            int obj = *reinterpret_cast<int*>(listValue + 4);
            if (obj != 0) {
                if (*reinterpret_cast<char*>(list + 0x28) != '\0') {
                    *reinterpret_cast<char*>(list + 0x28) = 0;
                    LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
                }
                // asm: lea eax, [edi+0x160]
                return reinterpret_cast<std::uint32_t*>(obj + 0x160);
            }
            done = FUN_004022a0(list, &cursor, &listValue);
        }

        if (*reinterpret_cast<char*>(list + 0x28) != '\0') {
            *reinterpret_cast<char*>(list + 0x28) = 0;
            LeaveCriticalSection(reinterpret_cast<LPCRITICAL_SECTION>(list + 4));
        }
    }

    return &DAT_009cd0f8;
}
