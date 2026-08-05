// =============================================================================
// CloneBase_Load
// -----------------------------------------------------------------------------
// Purpose:  Client CloneBase content-load orchestrator (host thiscall).
//           Creates host CNDHash tables, first-time global config, loads WAD,
//           materializes clone-object array + map modules, optional region
//           missions / type defs / LoadSkillsFX + SpecialFX master.
//
// Address:  0x00541e70  (autoassault.exe, image base 0x400000)
// Body:     0x00541e70–0x00542757 (~2279 bytes; ret 0x0C)
// Stable:   aa_00541e70
// System:   client-content / clonebase / gamedata
// Ghidra:   FUN_00541e70
//
// ABI:      __thiscall
//             ECX = content host*
//             stack: char flagA, char flagB, char flagC   (ret 0xC)
//             SEH LAB_009a40ca
//
// Name evidence: logs "CloneBase: start" / "CloneBase: end"; sole caller
//   FUN_00542aa0 host ctor when param_5==0.
//
// Exactness: CF mirrors raw + live decompile + read_memory ABI (ret 0xC).
// Nested callees left as FUN_* (OWN scope = this VA only).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W24-N).
// =============================================================================

#include <cstdint>
#include <cstdlib>
#include <cwchar>

// --- external symbols (Ghidra names; sealed duals noted where known) ---------
void FUN_007a4480(uint32_t level, const char *msg); // NDError log
void FUN_007a4400(const char *zone);
void FUN_007a4390(void);
int  FUN_007e1d80(void);                             // CreateInstance / PrepareDataConnection
void *operator_new(uint32_t size);
void operator_delete(void *p);
void _CxxThrowException(void *obj, void *throwInfo);
uint32_t FUN_00544640(int buckets);                  // CNDHash ctor variants
uint32_t FUN_005447d0(int buckets);
uint32_t FUN_005448f0(int buckets);
uint32_t FUN_00544750(int buckets);
uint32_t FUN_00544a00(int buckets);
uint32_t FUN_00544ba0(int buckets);
char CloneBase_LoadWadFile(void);                    // aa sealed
void FUN_007d81a0(void *dst);                        // ReadConfigCosts
void FUN_007b92c0(void *dst);                        // ReadConfigNewChars
int  FUN_007b8f30(void *dst);                        // ReadRemovedObjects
void FUN_007b7df0(void);
int  FUN_007e1630(void *out);                        // ReadNameList path
void FUN_00402c40(void);
void FUN_00544b10(void *nameRec);
int  FUN_007d9980(void *out);                        // CloseWadReader
void FUN_00403450(void *a, uint32_t b);
int  FUN_004ecf70(void *a, uint32_t b, char *name);
void FUN_004eaed0(void *p);
void FUN_00545790(void *a, int obj, int flag);
void FUN_004f1e20(int a, int b);
void FUN_005e0580(int obj, int idx, int flag);        // loot catalog path
void FUN_005e0610(int obj, int idx, int flag);
void FUN_00545590(void *a, int obj, int flag);
void FUN_0056e4e0(void);
uint32_t FUN_005ea260(uint32_t a, uint8_t b, char *name, uint32_t c);
void FUN_00545690(uint32_t a, uint32_t mod, int flag);
void FUN_005438c0(void *end, int n, void *val);
uint32_t FUN_0060b870(void);                         // CVOGRegionMissions_Ctor
void FUN_00541950(void);                             // Client_ReloadTypeDefTable_Inferred
void FUN_00541aa0(void);                             // Client_LoadSkillsFX (thiscall host)
void FUN_004a6790(void);                             // SpecialFXMaster load
void free(void *p);
// COM / STL helpers referenced in raw
extern void *ExceptionList;
extern "C" void *PTR_FUN_00af8c9c;
extern int DAT_00b04690;
extern char DAT_00b04694;
extern int DAT_00b04698;
extern char DAT_00b03e64;
extern int DAT_00b035fc;
extern void *DAT_00acc430;
extern void *DAT_00ac15a0;
extern void *DAT_00b04620;
extern void *DAT_00b046a4;

// Vector-like locals (begin/end/cap) — shapes from decompiler stack slots
struct PodVec {
    void *begin;
    void *end;
    void *cap;
};

void __thiscall CloneBase_Load(
    void *host /* ECX */,
    char flagA /* region-missions / late */,
    char flagB /* loot init path */,
    char flagC /* skip-heavy */)
{
    // SEH frame omitted (LAB_009a40ca); ExceptionList chain as retail.
    uint32_t cookie = 0;
    void *hostLocal = host;

    FUN_007a4480(0xffffffffu, "CloneBase: start");

    int hr = FUN_007e1d80();
    if (hr < 0) {
        int throwObj = hr;
        _CxxThrowException(&throwObj, &DAT_00acc430);
    }
    FUN_007a4480(0xffffffffu, "after CreateInstance comWadReader.CloneBaseReader.1");

    // Four host CNDHash shells
    void *mem = operator_new(0x34);
    uint32_t h = mem ? FUN_00544640(0xc) : 0;
    *(uint32_t *)((char *)host + 0xf10) = h;

    mem = operator_new(0x34);
    h = mem ? FUN_005447d0(4) : 0;
    *(uint32_t *)((char *)host + 0xf14) = h;

    mem = operator_new(0x34);
    h = mem ? FUN_005448f0(0xc) : 0;
    *(uint32_t *)((char *)host + 0xf0c) = h; // skills FX hash (LoadSkillsFX target)

    mem = operator_new(0x34);
    h = mem ? FUN_00544750(4) : 0;
    *(uint32_t *)((char *)host + 0xef0) = h;

    FUN_007a4480(0xffffffffu, "After hashes");

    DAT_00b04690 = DAT_00b04690 + 1;
    int *errPtr = nullptr;
    if (DAT_00b04690 == 1) {
        mem = operator_new(0x34);
        DAT_00b04698 = mem ? (int)FUN_00544a00(10) : 0;
        FUN_007a4480(0xffffffffu, "before PrepareDataConnection");
        FUN_007e1d80();
        FUN_007a4480(0xffffffffu, "before ReadConfigCosts");
        FUN_007d81a0(&DAT_00b04620);
        FUN_007a4480(0xffffffffu, "before ReadConfigNewChars");
        FUN_007b92c0(&DAT_00b046a4);
        FUN_007a4480(0xffffffffu, "before ReadRemovedObjects");
        errPtr = (int *)FUN_007b8f30((char *)host + 4);
        FUN_007a4480(0xffffffffu, "after ReadRemovedObjects");
        FUN_007b7df0();
    }

    if (CloneBase_LoadWadFile() == 0) {
        uint32_t z = 0;
        _CxxThrowException(&z, &DAT_00ac15a0);
    }

    PodVec cloneArr = {nullptr, nullptr, nullptr};
    int walk = 0;
    // SEH state = 5
    if (DAT_00b04694 == 0) {
        errPtr = (int *)FUN_007e1630(nullptr /* local_48 placeholder */);
        FUN_007a4480(0xffffffffu, "before ReadNameList");
    } else {
        FUN_00402c40();
        for (;;) {
            int hash = DAT_00b04698;
            if (*(char *)(hash + 0x1d) == 0) {
                FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
                FUN_007a4480(0, "VOG_DEBUG_STOP");
            }
            if (walk == 0) {
                walk = *(int *)(hash + 0x14);
            } else {
                walk = *(int *)(walk + 0x14);
            }
            int node = (walk == 0) ? 0 : *(int *)(walk + 8);
            if (node == 0) {
                break;
            }
            // name record → FUN_00544b10 (fields from node+4/+8/+0x10/flags)
            // (locals omitted; CF preserved in raw)
            uint8_t nameRec[/*sizeof name record ~0xA0*/ 0xA0];
            (void)nameRec;
            FUN_00544b10(nameRec);
        }
        *(uint8_t *)(DAT_00b04698 + 0x1d) = 0;
    }

    PodVec mapArr = {nullptr, nullptr, nullptr};
    // SEH state = 6
    int closeHr = FUN_007d9980(nullptr /* local_38 */);
    FUN_007a4480(0xffffffffu, "after CloseWadReader");
    if (errPtr != nullptr || closeHr != 0) {
        int throwObj = (int)(intptr_t)errPtr;
        _CxxThrowException(&throwObj, &DAT_00acc430);
    }

    FUN_007a4480(0xffffffffu, "before array");
    // Clone-object materialization: stride 0x114 over cloneArr
    int index = 0;
    uint32_t *rec = cloneArr.begin ? (uint32_t *)((char *)cloneArr.begin + 4) : nullptr;
    for (;;) {
        int count = 0;
        if (cloneArr.begin) {
            count = (int)(((char *)cloneArr.end - (char *)cloneArr.begin) / 0x114);
        }
        if (index >= count) {
            break;
        }
        void *key = (void *)rec[-1];
        void *objMem = operator_new(0x200);
        int obj = 0;
        if (objMem) {
            char nameBuf[128];
            char *namePtr = nameBuf;
            uint32_t conv = ((uint32_t(*)())PTR_FUN_00af8c9c)();
            FUN_00403450(rec + 1, conv);
            cookie |= 1;
            obj = FUN_004ecf70(key, *rec, namePtr);
        }
        if ((cookie & 1) != 0) {
            cookie &= ~1u;
            // free dynamic name if grown off stack
        }
        *(uint8_t *)(obj + 0x2a) = *(uint8_t *)(rec + 0x23);
        *(uint8_t *)(obj + 0x2b) = *(uint8_t *)((char *)rec + 0x8d);
        if (DAT_00b04694 == 0) {
            FUN_004eaed0((char *)rec + 0x8e);
        }
        switch (*(int *)(obj + 0x38)) {
        case 6: case 8: case 10: case 0xc: case 0xe:
        case 0x10: case 0x1a: case 0x1c: case 0x32: case 0x34:
            if (*(int *)(obj + 0x38) == 0x1a) {
                FUN_00545790(key, obj, 0);
            }
            if (flagB != 0 && flagC == 0) {
                if (*(int *)(obj + 0x3c) == 0) {
                    FUN_004f1e20(0, 1);
                }
                if (*(int *)(*(int *)(obj + 0x3c) + 0x3a4) == 1) {
                    int idx = (int)*(short *)(*(int *)(obj + 0x3c) + 0x3f0);
                    FUN_005e0580(obj, idx, 0);
                    FUN_005e0610(obj, idx, 0);
                }
                int cb = *(int *)(obj + 0x3c);
                if (*(short *)(cb + 0x3f4) == 8) {
                    if (*(int *)(cb + 0x3a8) == 1) {
                        for (int i = 0; i < 0x50; ++i) {
                            FUN_005e0580(obj, i, 1);
                            FUN_005e0610(obj, i, 1);
                        }
                    }
                } else if (*(int *)(cb + 0x3a8) == 1) {
                    int idx = (int)*(short *)(cb + 0x3f0);
                    FUN_005e0580(obj, idx, 1);
                    FUN_005e0610(obj, idx, 1);
                }
            }
            break;
        default:
            break;
        }
        FUN_00545590(key, obj, 0);
        ++index;
        rec += 0x45; // 0x45 dwords = 0x114 bytes
    }
    FUN_007a4480(0xffffffffu, "after array");

    if (flagA != 0 && flagC == 0) {
        FUN_0056e4e0();
    }

    int mapCount = mapArr.begin
        ? (int)(((char *)mapArr.end - (char *)mapArr.begin) / 0x154)
        : 0;
    FUN_007a4480(0xffffffffu, "after SafeArrayAccessData CVOGMapModule");

    if (flagC == 0 && mapCount > 0) {
        uint32_t *mrec = (uint32_t *)((char *)mapArr.begin + 4);
        int left = mapCount;
        do {
            char nameBuf[128];
            char *namePtr = nameBuf;
            uint32_t conv = ((uint32_t(*)())PTR_FUN_00af8c9c)();
            FUN_00403450((char *)mrec + 6, conv);
            char nameCopy[504];
            // strcpy namePtr → nameCopy; free if heap
            void *modMem = operator_new(0x60);
            uint32_t mod = modMem
                ? FUN_005ea260(mrec[-1], *(uint8_t *)(mrec + 1), nameCopy, *mrec)
                : 0;
            FUN_00545690(*(uint32_t *)(mod + 0x1c), mod, 0);

            // 0x21 bucket inserts into host vector slots
            uint8_t bit = 1;
            int base = 7;
            int loop = 0x21;
            do {
                if ((*(uint8_t *)(mod + 0x14) & 1) != 0 ||
                    (*(uint32_t *)(mod + 0x14) & (1u << (bit & 0x1f))) != 0) {
                    int slot = (base + 1 + *(int *)(mod + 0x18)) * 0x10 + (int)(intptr_t)hostLocal;
                    int begin = *(int *)(slot + 4);
                    if (begin == 0 ||
                        (uint32_t)(*(int *)(slot + 0xc) - begin) >> 2 <=
                            (uint32_t)(*(int *)(slot + 8) - begin) >> 2) {
                        FUN_005438c0(*(void **)(slot + 8), 1, &mod);
                    } else {
                        uint32_t *end = *(uint32_t **)(slot + 8);
                        *end = mod;
                        *(uint32_t **)(slot + 8) = end + 1;
                    }
                }
                int slot2 = (*(int *)(mod + 0x18) + 1) * 0x10 + (int)(intptr_t)hostLocal;
                int begin2 = *(int *)(slot2 + 4);
                if (begin2 == 0 ||
                    (uint32_t)(*(int *)(slot2 + 0xc) - begin2) >> 2 <=
                        (uint32_t)(*(int *)(slot2 + 8) - begin2) >> 2) {
                    FUN_005438c0(*(void **)(slot2 + 8), 1, &mod);
                } else {
                    uint32_t *end = *(uint32_t **)(slot2 + 8);
                    *end = mod;
                    *(uint32_t **)(slot2 + 8) = end + 1;
                }
                bit = (uint8_t)(bit + 1);
                base += 7;
                --loop;
            } while (loop != 0);

            mrec += 0x55; // 0x55 dwords = 0x154 bytes
            --left;
        } while (left != 0);
    }

    FUN_007a4480(0xffffffffu, "before SafeArrayUnaccessData CVOGMapModule");
    if (flagA != 0 && *(int *)((char *)hostLocal + 0xf18) == 0) {
        void *rm = operator_new(0x10);
        uint32_t rmv = rm ? FUN_0060b870() : 0;
        *(uint32_t *)((char *)hostLocal + 0xf18) = rmv;
    }
    FUN_007a4480(0xffffffffu, "after CVOGRegionMissions");

    mem = operator_new(0x34);
    h = mem ? FUN_00544ba0(6) : 0;
    *(uint32_t *)((char *)hostLocal + 0xf1c) = h;
    if (flagC == 0) {
        FUN_00541950(); // ReloadContinentObjects / TypeDef table
    }
    FUN_007a4480(0xffffffffu, "after ReloadContinentObjects");

    // Normal success path (both COM vectors empty / already unaccessed)
    if (DAT_00b03e64 == 0) {
        FUN_007a4480(0xffffffffu, "before LoadSkillsFX and SpecialFXMaster");
        if (DAT_00b035fc != 0) {
            FUN_007a4400("@@LoadSkillsFX");
            FUN_00541aa0(); // Client_LoadSkillsFX — thiscall host
            FUN_004a6790(); // SpecialFX master
            FUN_007a4390();
        }
        FUN_007a4480(0xffffffffu, "after LoadSkillsFX and SpecialFXMaster");
    }
    FUN_007a4480(0xffffffffu, "CloneBase: end");
    // ExceptionList restore; ret 0xC
}
