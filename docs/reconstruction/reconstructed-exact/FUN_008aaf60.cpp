// Ghidra-name twin — full plate on Client_MissionDialog_SetHeaderCaption_Inferred.cpp
// Stable aa_008aaf60 / VA 0x008aaf60 / dual 2026-08-04 WQ7R-A
//
// NOTE: decompiler shows __fastcall(param_1) + unaff_EDI; body uses ECX dialog
// and EDI caption key. vtbl+0x1d8 takes (0,1,1) not (0) — see named clean.

#include <cstdint>
#include <string>

extern int DAT_00d1b6d8;
extern char DAT_00d1b21c;
extern void* ExceptionList;
extern std::uint8_t LAB_009abcb7;

void FUN_007a69d0();
char* FUN_007a6de0(/* EDI key pushed */, unsigned unk);
void FUN_005465c0();
void FUN_008aab00(std::uint32_t widget);
void FUN_008aa610();

// Keep decompiler shape for raw≡clean twin; lag notes in named unit / annotated.
void __fastcall FUN_008aaf60(int param_1)
{
    char* pcVar1;
    int unaff_EDI; // register EDI caption key — set by caller
    std::string local_28;
    std::uint32_t uStack_10;
    void* local_c;
    std::uint8_t* puStack_8;
    std::uint32_t local_4;

    local_4 = 0xffffffffu;
    puStack_8 = &LAB_009abcb7;
    local_c = ExceptionList;

    if (*(int*)(param_1 + 0x6e0) != 0) {
        if (unaff_EDI == 0) {
            ExceptionList = &local_c;
            // lag: real call is (0,1,1)
            (**(void(**)(int, int, int))(**(int**)(param_1 + 0x6e0) + 0x1d8))(0, 1, 1);
            (**(void(**)())(**(int**)(param_1 + 0x6e0) + 0x34c))();
        } else {
            ExceptionList = &local_c;
            FUN_007a69d0();
            pcVar1 = (char*)FUN_007a6de0(/*EDI*/ unaff_EDI, 0xffffffffu);
            local_28.assign(pcVar1 ? pcVar1 : "");
            local_4 = 0;
            if (DAT_00d1b6d8 != 0) {
                FUN_005465c0();
            }
            (**(void(**)(int, int, int))(**(int**)(param_1 + 0x6e0) + 0x1d8))(0, 1, 1);
            FUN_008aab00(*(std::uint32_t*)(param_1 + 0x6e0));
            (**(void(**)())(**(int**)(param_1 + 0x6e0) + 0x1f0))();
            (**(void(**)())(**(int**)(param_1 + 0x6e0) + 0x34c))();
            if (((DAT_00d1b21c == '\0') || (*(int*)(param_1 + 0x648) == 2)) ||
                (*(int*)(param_1 + 0x648) == 3)) {
                (**(void(**)())(**(int**)(param_1 + 0x6e0) + 0x1fc))();
            }
            uStack_10 = 0xffffffffu;
            local_4 = 0xffffffffu;
        }
        (**(void(**)(int))(**(int**)(param_1 + 0x6e0) + 0x214))(0);
        FUN_008aa610();
    }
    ExceptionList = local_c;
}
