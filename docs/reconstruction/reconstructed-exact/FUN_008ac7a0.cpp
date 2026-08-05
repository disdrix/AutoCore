// Ghidra-name twin — full plate on Client_MaybeShowMultiActiveMissionTip_Inferred.cpp
// Stable aa_008ac7a0 / VA 0x008ac7a0 / dual 2026-08-04 WQ7R-A

#include <cstdint>

extern int DAT_00d1b6d8;
extern int DAT_00d1a840;

void FUN_007a4480(int channel, const char* msg);
void __thiscall Client_MaybeShowFirstTimeTip(void* uiHost, unsigned tipId);

void FUN_008ac7a0(void)
{
    int iVar1;
    int iVar2;
    int iVar3;

    if ((DAT_00d1b6d8 != 0) && ((*(std::uint8_t*)(DAT_00d1b6d8 + 0xd34) & 1) == 0)) {
        iVar1 = *(int*)(DAT_00d1b6d8 + 0x540);
        iVar2 = 0;
        iVar3 = 0;
        if (*(char*)(iVar1 + 0x1d) != '\0') {
            FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
            FUN_007a4480(0, "VOG_DEBUG_STOP");
        }
        *(std::uint8_t*)(iVar1 + 0x1d) = 1;
        while (true) {
            iVar1 = *(int*)(DAT_00d1b6d8 + 0x540);
            if (*(char*)(iVar1 + 0x1d) == '\0') {
                FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
                FUN_007a4480(0, "VOG_DEBUG_STOP");
            }
            if (iVar3 == 0) {
                iVar3 = *(int*)(iVar1 + 0x14);
            } else {
                iVar3 = *(int*)(iVar3 + 0x14);
            }
            if (iVar3 == 0) {
                iVar1 = 0;
            } else {
                iVar1 = *(int*)(iVar3 + 8);
            }
            if (iVar1 == 0) break;
            if ((*(short*)(iVar1 + 0xf8) == 0) && (*(int*)(iVar1 + 0xfc) != -1)) {
                iVar2 = iVar2 + 1;
            }
        }
        *(std::uint8_t*)(*(int*)(DAT_00d1b6d8 + 0x540) + 0x1d) = 0;
        if (1 < iVar2) {
            Client_MaybeShowFirstTimeTip(
                reinterpret_cast<void*>(static_cast<std::uintptr_t>(
                    static_cast<unsigned>(DAT_00d1a840))),
                0x20u);
        }
    }
}
