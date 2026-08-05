// =============================================================================
// FUN_00724870  (scaffold alias → CSoundManager_ProbeSoundFileExists_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00724870
// Address:   0x00724870  (autoassault.exe, image base 0x400000)
// Body:      0x00724870–0x007249b0 (0x140 / 320 bytes)
// System:    client audio / CSoundManager path probe
// Dual seal: 2026-07-29 W21-M
// Canonical clean: CSoundManager_ProbeSoundFileExists_Inferred.cpp
// Exactness: Decompiler-shaped control flow; ABI notes in plate.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

// Decompiler surface (register names noisy). Prefer CSoundManager_ProbeSoundFileExists_Inferred.
// Real ABI: EAX=path, stack=(this, outPath, outKind*), RET 0x0C, AL=bool.

extern "C" void FUN_00722790(...);
extern "C" int FUN_007b6a20(void);
extern "C" char* FUN_007b6420(void);
extern "C" char FUN_007b66c0(int);
extern "C" int __stdcall PathFileExistsA(const char*);

extern "C" char DAT_00d1e574[];

std::uint8_t FUN_00724870(std::uint32_t param_1, int param_2, std::uint32_t* param_3)
{
    char cVar1;
    char* in_EAX; // path (EAX)
    int iVar2;
    int BVar3;
    char* pcVar4;
    char* pcVar5;
    std::uint32_t uVar6;
    char* pcVar7;
    std::uint32_t uVar8;
    char* pcVar9;
    char* pcVar10;
    char local_208[259];
    char local_105;
    char local_104[260];

    local_105 = '\0';
    iVar2 = -static_cast<int>(reinterpret_cast<std::intptr_t>(in_EAX));
    do {
        cVar1 = *in_EAX;
        in_EAX[reinterpret_cast<std::intptr_t>(local_208) + iVar2] = cVar1;
        in_EAX = in_EAX + 1;
    } while (cVar1 != '\0');
    FUN_00722790(local_208); // real: ECX=param_1 this, stack=local_208
    iVar2 = FUN_007b6a20();
    if (((*reinterpret_cast<std::uint8_t*>(iVar2 + 4)) & 1) != 0) {
        BVar3 = PathFileExistsA(local_208);
        if (BVar3 != 0) goto LAB_00724972;
        pcVar4 = FUN_007b6420();
        pcVar10 = DAT_00d1e574;
        do {
            pcVar7 = pcVar10;
            if (0xF < *reinterpret_cast<std::uint32_t*>(pcVar10 + 0x14)) {
                pcVar7 = *reinterpret_cast<char**>(pcVar10);
            }
            pcVar9 = local_104;
            do {
                cVar1 = *pcVar7;
                *pcVar9 = cVar1;
                pcVar7 = pcVar7 + 1;
                pcVar9 = pcVar9 + 1;
                pcVar5 = pcVar4;
            } while (cVar1 != '\0');
            do {
                cVar1 = *pcVar5;
                pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            uVar6 = static_cast<std::uint32_t>(pcVar5 - pcVar4);
            pcVar7 = &local_105;
            do {
                pcVar9 = pcVar7 + 1;
                pcVar7 = pcVar7 + 1;
            } while (*pcVar9 != '\0');
            pcVar9 = pcVar4;
            for (uVar8 = uVar6 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
                *reinterpret_cast<std::uint32_t*>(pcVar7) = *reinterpret_cast<std::uint32_t*>(pcVar9);
                pcVar9 = pcVar9 + 4;
                pcVar7 = pcVar7 + 4;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
                *pcVar7 = *pcVar9;
                pcVar9 = pcVar9 + 1;
                pcVar7 = pcVar7 + 1;
            }
            BVar3 = PathFileExistsA(local_104);
            if (BVar3 != 0) goto LAB_00724972;
            pcVar10 = pcVar10 + 0x1c;
        } while (reinterpret_cast<std::intptr_t>(pcVar10) < 0xd1e7a4);
    }
    cVar1 = FUN_007b66c0(iVar2);
    if (cVar1 == '\0') {
        return 0;
    }
LAB_00724972:
    if (param_2 != 0) {
        pcVar4 = local_208;
        param_2 = param_2 - reinterpret_cast<int>(pcVar4);
        do {
            cVar1 = *pcVar4;
            pcVar4[param_2] = cVar1;
            pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
    }
    if (param_3 != nullptr) {
        *param_3 = 2;
    }
    return 1;
}
