// =============================================================================
// FUN_008aab00  /  MissionDialog_ParseMarkupToRichText_Inferred
// -----------------------------------------------------------------------------
// Ghidra-name twin — same CF quality as named clean.
// Full plate / purpose / dual: MissionDialog_ParseMarkupToRichText_Inferred.cpp
//
// Stable:   aa_008aab00
// Address:  0x008aab00  (autoassault.exe, image base 0x400000)
// Body:     0x008aab00–0x008aaf58 exclusive (1112 B / 0x458)
// System:   missions-progression / mission dialog chrome
// Wave:     WQ7R-C (2026-08-04)
//
// ABI: ECX = markup C-string; stack = richtext widget*; callers ADD ESP,4
// Vtbl: +0x230 SetColor, +0x23c PopColor, +0x250 AppendText, +0x254 Pause(0x14)
// Colors: FFFF2D00 / FF256EC8 / FFC5C025 / FFF59623 / FF29B525
// Key table: DAT_00d1bbf5 stride 0x34 end 0xd1d455 (120); FUN_007f5120/007f9160
// Exactness: Behavior-preserving rewrite of decompiler CF. Not modernization.
// Bit-for-bit / runtime: DEFERRED.
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

extern std::uint8_t DAT_00d1bbf5;

void  FUN_007a69d0();
char* FUN_007a6de0(const void* keyOrCstr, unsigned unk);
char* FUN_007f5120();
char  FUN_007f9160(char keyIndex, int zero);

// Image labels this __thiscall; ECX is markup, not widget this.
void FUN_008aab00(char* param_1 /*ECX markup*/, int* param_2 /*stack widget*/)
{
    std::uint8_t workBuf[0x1000 + 6];
    std::uint8_t runBuf[4096];
    char         keyDisplay[64];
    int          runLen;
    int          scanIdx;
    int          cmp;
    std::uint8_t* keyName;
    std::uint8_t* freeLookLoc;
    std::uint8_t* tableEntry;
    char          keyIndex;
    bool          less;
    char          ch;
    const char*   fmt;
    std::uint8_t* p;
    void**        vtbl;

    if ((param_2 != nullptr) && (param_1 != nullptr)) {
        FUN_007a69d0();

        // strcpy-equivalent into workBuf
        {
            char* src = param_1;
            int   delta = -(int)(std::uintptr_t)src;
            do {
                ch = *src;
                src[(int)((std::uint8_t*)workBuf + delta)] = ch;
                src = src + 1;
            } while (ch != '\0');
        }

        scanIdx = 0;
        runLen  = 0;

        if (workBuf[0] != 0) {
            for (;;) {
                // LAB_008aab70
                p = workBuf + scanIdx;

                if ((workBuf[scanIdx] == 0x5b) && (workBuf[scanIdx + 1] == 0x24)) {
                    if (0 < runLen) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        runBuf[runLen] = 0;
                        reinterpret_cast<void(__thiscall*)(int*, std::uint8_t*)>(
                            vtbl[0x250 / 4])(param_2, runBuf);
                        runLen = 0;
                    }

                    if (_strnicmp(reinterpret_cast<char*>(p), "[$imp]", 6) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                            vtbl[0x230 / 4])(param_2, 0xffff2d00u);
                        scanIdx = scanIdx + 6;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$/imp]", 7) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*)>(
                            vtbl[0x23c / 4])(param_2);
                        scanIdx = scanIdx + 7;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$npc]", 6) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                            vtbl[0x230 / 4])(param_2, 0xff256ec8u);
                        scanIdx = scanIdx + 6;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$/npc]", 7) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*)>(
                            vtbl[0x23c / 4])(param_2);
                        scanIdx = scanIdx + 7;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$inst]", 7) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                            vtbl[0x230 / 4])(param_2, 0xffc5c025u);
                        scanIdx = scanIdx + 7;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$/inst]", 8) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*)>(
                            vtbl[0x23c / 4])(param_2);
                        scanIdx = scanIdx + 8;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$loc]", 6) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                            vtbl[0x230 / 4])(param_2, 0xfff59623u);
                        scanIdx = scanIdx + 6;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$/loc]", 7) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*)>(
                            vtbl[0x23c / 4])(param_2);
                        scanIdx = scanIdx + 7;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$emote]", 8) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                            vtbl[0x230 / 4])(param_2, 0xff29b525u);
                        scanIdx = scanIdx + 8;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$/emote]", 9) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*)>(
                            vtbl[0x23c / 4])(param_2);
                        scanIdx = scanIdx + 9;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$pause]", 8) == 0) {
                        vtbl = reinterpret_cast<void**>(*param_2);
                        reinterpret_cast<void(__thiscall*)(int*, int)>(
                            vtbl[0x254 / 4])(param_2, 0x14);
                        scanIdx = scanIdx + 8;
                    }
                    else if (_strnicmp(reinterpret_cast<char*>(p), "[$key]", 6) != 0) {
                        // Unknown "[$" — accumulate first char (LAB_008aaf20)
                        runBuf[runLen] = *p;
                        runLen  = runLen + 1;
                        scanIdx = scanIdx + 1;
                    }
                    else {
                        // [$key] body
                        p = workBuf + scanIdx + 6;
                        runLen = 0;
                        ch = static_cast<char>(*p);
                        scanIdx = scanIdx + 6;

                        while (ch != '\0') {
                            if ((static_cast<std::uint8_t>(ch) == 0x5b) &&
                                (workBuf[scanIdx + 1] == 0x24) &&
                                (_strnicmp(reinterpret_cast<char*>(p), "[$/key]", 7) == 0)) {

                                scanIdx = scanIdx + 7;
                                runBuf[runLen] = 0;

                                freeLookLoc = reinterpret_cast<std::uint8_t*>(
                                    FUN_007a6de0("Free Look", 0xffffffffu));
                                keyName = runBuf;

                                // LAB_008aadf7 pairwise strcmp
                                for (;;) {
                                    std::uint8_t a = *keyName;
                                    less = (a < *freeLookLoc);
                                    if (a != *freeLookLoc) {
                                        cmp = (1 - static_cast<unsigned>(less)) -
                                              static_cast<unsigned>(less != 0);
                                        break;
                                    }
                                    if (a == 0) {
                                        cmp = 0;
                                        break;
                                    }
                                    a = keyName[1];
                                    less = (a < freeLookLoc[1]);
                                    if (a != freeLookLoc[1]) {
                                        cmp = (1 - static_cast<unsigned>(less)) -
                                              static_cast<unsigned>(less != 0);
                                        break;
                                    }
                                    keyName = keyName + 2;
                                    freeLookLoc = freeLookLoc + 2;
                                    if (a == 0) {
                                        cmp = 0;
                                        break;
                                    }
                                }

                                // LAB_008aae20
                                if (cmp == 0) {
                                    keyName = reinterpret_cast<std::uint8_t*>(FUN_007f5120());
                                    fmt = "%s";
                                }
                                else {
                                    keyName = runBuf;
                                    do {
                                        ch = static_cast<char>(*keyName);
                                        keyName = keyName + 1;
                                    } while (ch != '\0');
                                    if ((keyName != runBuf + 1) &&
                                        (static_cast<unsigned>(
                                             static_cast<int>(keyName - (runBuf + 1))) < 0x22u)) {
                                        FUN_007a69d0();
                                        keyIndex = '\0';
                                        tableEntry = &DAT_00d1bbf5;
                                        do {
                                            char* slotName =
                                                FUN_007a6de0(tableEntry, 0xffffffffu);
                                            cmp = _stricmp(
                                                reinterpret_cast<char*>(runBuf), slotName);
                                            if (cmp == 0) {
                                                goto LAB_008aaea5;
                                            }
                                            tableEntry = tableEntry + 0x34;
                                            keyIndex = static_cast<char>(keyIndex + 1);
                                        } while ((int)(std::uintptr_t)tableEntry < 0xd1d455);
                                    }
                                    keyIndex = '\0';
                                LAB_008aaea5:
                                    keyIndex = FUN_007f9160(keyIndex, 0);
                                    if (keyIndex != '\0') {
                                        goto LAB_008aaedb;
                                    }
                                    keyName = runBuf;
                                    fmt = "<%s>";
                                }

                                std::sprintf(keyDisplay, fmt, keyName);

                            LAB_008aaedb:
                                vtbl = reinterpret_cast<void**>(*param_2);
                                reinterpret_cast<void(__thiscall*)(int*, char*)>(
                                    vtbl[0x250 / 4])(param_2, keyDisplay);
                                runLen = 0;
                                break;
                            }

                            runBuf[runLen] = *p;
                            runLen = runLen + 1;
                            p = workBuf + scanIdx + 1;
                            scanIdx = scanIdx + 1;
                            ch = static_cast<char>(*p);
                        }
                    }
                }
                else {
                    runBuf[runLen] = workBuf[scanIdx];
                    // LAB_008aaf20
                    runLen  = runLen + 1;
                    scanIdx = scanIdx + 1;
                }

                // LAB_008aaf23
                if (workBuf[scanIdx] == 0) {
                    if (runLen == 0) {
                        return;
                    }
                    vtbl = reinterpret_cast<void**>(*param_2);
                    runBuf[runLen] = 0;
                    reinterpret_cast<void(__thiscall*)(int*, std::uint8_t*)>(
                        vtbl[0x250 / 4])(param_2, runBuf);
                    return;
                }
            }
        }
    }
    return;
}
