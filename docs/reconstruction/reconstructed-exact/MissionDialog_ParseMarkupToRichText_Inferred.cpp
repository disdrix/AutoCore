// =============================================================================
// MissionDialog_ParseMarkupToRichText_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Parse mission/dialog markup C-string into a richtext widget:
//           flush plain runs, apply color open/close tags, insert pause ticks,
//           and resolve [$key]…[$/key] spans to keybind display text.
//
// Address:  0x008aab00  (autoassault.exe, image base 0x400000)
// Body:     0x008aab00–0x008aaf58 exclusive (1112 B / 0x458)
// Stable:   aa_008aab00
// System:   missions-progression / mission dialog chrome
// Ghidra:   FUN_008aab00
// Wave:     WQ7R-C (2026-08-04)
//
// ABI (sealed — decompiler __thiscall label is misleading):
//   ECX   = markup C-string (source)
//   stack = richtext widget* (vtbl host)
//   callers ADD ESP,4 after CALL
// Frame:  mov eax,0x204c / __chkstk; epilogue add esp,0x204c; ret
//
// Callers (6): FUN_008aaf60, FUN_008a3510 (×2), FUN_008cc5a0,
//              FUN_008cdae0, FUN_008dbe10
//
// Markup matrix (ARGB SetColor @ vtbl+0x230; PopColor @ +0x23c):
//   [$imp]/[$/imp]     0xFFFF2D00
//   [$npc]/[$/npc]     0xFF256EC8
//   [$inst]/[$/inst]   0xFFC5C025
//   [$loc]/[$/loc]     0xFFF59623
//   [$emote]/[$/emote] 0xFF29B525
//   [$pause]              Pause(0x14) @ vtbl+0x254
//   [$key]…[$/key]        keybind resolve → AppendText @ vtbl+0x250
//
// Key table: DAT_00d1bbf5 stride 0x34, end 0x00d1d455 (120 slots)
// Helpers:   FUN_007a69d0 locale ensure; FUN_007a6de0 localize;
//            FUN_007f5120 Free Look display; FUN_007f9160(index,0)
//
// Exactness: Full decompiler CF (twin of FUN_008aab00.cpp). Not modernization.
// Dual: reviews/A_aa_008aab00_* + B_aa_008aab00_*; dual report task-dual-ab-…
// Bit-for-bit / runtime / differential: DEFERRED. Product English open.
// Reject scaffold Named_npc / Named_CalleeOf_* as product plates.
// =============================================================================

#include <cstdint>
#include <cstdio>
#include <cstring>

// --- externals (image) -------------------------------------------------------

extern std::uint8_t DAT_00d1bbf5; // keybind name table base (stride 0x34)

void FUN_007a69d0();                                 // locale / string-table ensure
char* FUN_007a6de0(const void* keyOrCstr, unsigned unk); // localize
char* FUN_007f5120();                                // Free Look key display string
char  FUN_007f9160(char keyIndex, int zero);         // key index → display ready?

// Richtext widget vtbl (product English open — ordinals sealed):
//   +0x230  SetColor(ARGB)     thiscall, stack color
//   +0x23c  PopColor()         thiscall
//   +0x250  AppendText(cstr)   thiscall, stack text
//   +0x254  Pause(ticks)       thiscall, stack 0x14

// Key table end address (image absolute): 0x00d1d455
static const std::uintptr_t kKeyTableEnd = 0x00d1d455u;
static const int            kKeyTableStride = 0x34;
// Slot count: (0xd1d455 - 0xd1bbf5) / 0x34 = 120

// =============================================================================
// ECX = markupSrc; stack = richtextWidget*
// =============================================================================

void MissionDialog_ParseMarkupToRichText_Inferred(
    char* markupSrc /*ECX*/,
    int*  richtextWidget /*stack*/)
{
    // Frame locals (decompiler names → roles):
    //   workBuf      local_1000[+local_ffa]: 4 KiB working copy of markup
    //   runBuf       local_2000:             4 KiB plain-run / key-name buffer
    //   keyDisplay   local_2040:             64-byte sprintf staging
    //   runLen       local_204c:             current run length
    //   scanIdx      iVar7:                  index into workBuf
    std::uint8_t workBuf[0x1000 + 6]; // decompiler split local_1000[6]+local_ffa[4086]
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

    // uStack_4 = 0x8aab0a  (return-address cookie / frame marker in image)

    if (richtextWidget == nullptr || markupSrc == nullptr) {
        return;
    }

    FUN_007a69d0();

    // --- copy markupSrc → workBuf (includes NUL) -----------------------------
    // Image: iVar7 = -(int)param_1; store via param_1[(local_1000 + iVar7)]
    {
        char* src = markupSrc;
        int   delta = -(int)(std::uintptr_t)src;
        do {
            ch = *src;
            // workBuf[(src - markupSrc)] ≡ src[workBuf + delta] form
            src[(int)((std::uint8_t*)workBuf + delta)] = ch;
            src = src + 1;
        } while (ch != '\0');
    }

    scanIdx = 0;
    runLen  = 0;

    if (workBuf[0] == 0) {
        return;
    }

    // --- main scan -----------------------------------------------------------
    for (;;) {
        // LAB_008aab70
        p = workBuf + scanIdx;

        // Tag introducer: '[' (0x5b) + '$' (0x24)
        if (workBuf[scanIdx] == 0x5b && workBuf[scanIdx + 1] == 0x24) {

            // Flush pending plain run before tag paint
            if (runLen > 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                runBuf[runLen] = 0;
                // AppendText @ vtbl+0x250
                reinterpret_cast<void(__thiscall*)(int*, std::uint8_t*)>(
                    vtbl[0x250 / 4])(richtextWidget, runBuf);
                runLen = 0;
            }

            // Color / pause / key — ordered strnicmp chain (exact arm order)
            if (_strnicmp(reinterpret_cast<char*>(p), "[$imp]", 6) == 0) {
                // SetColor 0xFFFF2D00
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                    vtbl[0x230 / 4])(richtextWidget, 0xffff2d00u);
                scanIdx = scanIdx + 6;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$/imp]", 7) == 0) {
                // PopColor
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*)>(
                    vtbl[0x23c / 4])(richtextWidget);
                scanIdx = scanIdx + 7;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$npc]", 6) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                    vtbl[0x230 / 4])(richtextWidget, 0xff256ec8u);
                scanIdx = scanIdx + 6;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$/npc]", 7) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*)>(
                    vtbl[0x23c / 4])(richtextWidget);
                scanIdx = scanIdx + 7;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$inst]", 7) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                    vtbl[0x230 / 4])(richtextWidget, 0xffc5c025u);
                scanIdx = scanIdx + 7;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$/inst]", 8) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*)>(
                    vtbl[0x23c / 4])(richtextWidget);
                scanIdx = scanIdx + 8;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$loc]", 6) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                    vtbl[0x230 / 4])(richtextWidget, 0xfff59623u);
                scanIdx = scanIdx + 6;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$/loc]", 7) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*)>(
                    vtbl[0x23c / 4])(richtextWidget);
                scanIdx = scanIdx + 7;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$emote]", 8) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*, unsigned)>(
                    vtbl[0x230 / 4])(richtextWidget, 0xff29b525u);
                scanIdx = scanIdx + 8;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$/emote]", 9) == 0) {
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*)>(
                    vtbl[0x23c / 4])(richtextWidget);
                scanIdx = scanIdx + 9;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$pause]", 8) == 0) {
                // Pause(0x14)
                vtbl = reinterpret_cast<void**>(*richtextWidget);
                reinterpret_cast<void(__thiscall*)(int*, int)>(
                    vtbl[0x254 / 4])(richtextWidget, 0x14);
                scanIdx = scanIdx + 8;
            }
            else if (_strnicmp(reinterpret_cast<char*>(p), "[$key]", 6) != 0) {
                // Unknown "[$" introducer: treat first byte as plain text
                // (LAB_008aaf20 accumulate path)
                runBuf[runLen] = *p;
                runLen  = runLen + 1;
                scanIdx = scanIdx + 1;
            }
            else {
                // --- [$key] … [$/key] ----------------------------------------
                // Body starts at workBuf + scanIdx + 6 (local_ffa + scanIdx)
                p = workBuf + scanIdx + 6;
                runLen = 0;
                ch = static_cast<char>(*p);
                scanIdx = scanIdx + 6;

                while (ch != '\0') {
                    // Close tag: "[$" at current + strnicmp "[$/key]"
                    if ((static_cast<std::uint8_t>(ch) == 0x5b) &&
                        (workBuf[scanIdx + 1] == 0x24) &&
                        (_strnicmp(reinterpret_cast<char*>(p), "[$/key]", 7) == 0)) {

                        scanIdx = scanIdx + 7;
                        runBuf[runLen] = 0;

                        // Localize "Free Look"; image hand-rolled 2-byte strcmp
                        freeLookLoc = reinterpret_cast<std::uint8_t*>(
                            FUN_007a6de0("Free Look", 0xffffffffu));
                        keyName = runBuf;

                        // LAB_008aadf7 — MSVC-style pairwise strcmp
                        for (;;) {
                            std::uint8_t a = *keyName;
                            less = (a < *freeLookLoc);
                            if (a != *freeLookLoc) {
                                // (1 - less) - (less != 0) → -1 if less else +1
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

                        // LAB_008aae20 — resolve display string
                        if (cmp == 0) {
                            // Free Look match → helper display + "%s"
                            keyName = reinterpret_cast<std::uint8_t*>(FUN_007f5120());
                            fmt = "%s";
                        }
                        else {
                            // Length of key name in runBuf (exclude empty / long)
                            keyName = runBuf;
                            do {
                                ch = static_cast<char>(*keyName);
                                keyName = keyName + 1;
                            } while (ch != '\0');
                            // length = keyName - (runBuf + 1); require 0 < len < 0x22
                            if ((keyName != runBuf + 1) &&
                                (static_cast<unsigned>(
                                     static_cast<int>(keyName - (runBuf + 1))) < 0x22u)) {

                                FUN_007a69d0();
                                keyIndex = '\0';
                                tableEntry = &DAT_00d1bbf5;
                                do {
                                    char* slotName = FUN_007a6de0(tableEntry, 0xffffffffu);
                                    cmp = _stricmp(reinterpret_cast<char*>(runBuf), slotName);
                                    if (cmp == 0) {
                                        goto key_table_hit; // LAB_008aaea5 with index
                                    }
                                    tableEntry = tableEntry + kKeyTableStride;
                                    keyIndex = static_cast<char>(keyIndex + 1);
                                } while (reinterpret_cast<std::uintptr_t>(tableEntry) <
                                         kKeyTableEnd);
                            }
                            keyIndex = '\0';
                        key_table_hit: // LAB_008aaea5
                            keyIndex = FUN_007f9160(keyIndex, 0);
                            if (keyIndex != '\0') {
                                // Non-zero: display already ready in keyDisplay;
                                // skip sprintf (FUN_007f9160 side-effect — open)
                                goto key_append; // LAB_008aaedb
                            }
                            keyName = runBuf;
                            fmt = "<%s>";
                        }

                        std::sprintf(keyDisplay, fmt, keyName);

                    key_append: // LAB_008aaedb
                        vtbl = reinterpret_cast<void**>(*richtextWidget);
                        reinterpret_cast<void(__thiscall*)(int*, char*)>(
                            vtbl[0x250 / 4])(richtextWidget, keyDisplay);
                        runLen = 0;
                        break; // leave key while → main end-check
                    }

                    // Accumulate one key-name character
                    runBuf[runLen] = *p;
                    runLen = runLen + 1;
                    p = workBuf + scanIdx + 1;
                    scanIdx = scanIdx + 1;
                    ch = static_cast<char>(*p);
                }
                // Unclosed [$key]…NUL: fall through with runLen leftover chars
                // discarded at next tag flush / final check (image CF).
            }
        }
        else {
            // Plain character
            runBuf[runLen] = workBuf[scanIdx];
            // LAB_008aaf20
            runLen  = runLen + 1;
            scanIdx = scanIdx + 1;
        }

        // LAB_008aaf23 — end of work buffer?
        if (workBuf[scanIdx] == 0) {
            if (runLen == 0) {
                return;
            }
            // Final plain-run flush
            vtbl = reinterpret_cast<void**>(*richtextWidget);
            runBuf[runLen] = 0;
            reinterpret_cast<void(__thiscall*)(int*, std::uint8_t*)>(
                vtbl[0x250 / 4])(richtextWidget, runBuf);
            return;
        }
        // else continue LAB_008aab70
    }
}
