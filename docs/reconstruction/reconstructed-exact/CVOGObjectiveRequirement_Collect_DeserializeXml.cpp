// =============================================================================
// CVOGObjectiveRequirement_Collect_DeserializeXml
// -----------------------------------------------------------------------------
// Stable ID: aa_00611a00
// Address:   0x00611a00  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-29 dual A/B refine from live Ghidra decompile + raw
// Exactness: Behavior-preserving field map of decompiler control flow.
//            COM vtbl ordinals left as raw offsets (MSXML IID map open).
// Bit-for-bit vs retail EXE: DEFERRED
// Dual: reviews/A|B_aa_00611a00_CVOGObjectiveRequirement_Collect_DeserializeXml.md
// =============================================================================
//
// ROLE: Virtual Collect requirement XML/MSXML attribute loader (vtable +0x48).
//       Writes GLM fields into Collect req object. No progress / loot / inventory.
//
// CLASS: CVOGObjectiveRequirement_Collect — ctor 0x00611690 type=2, vtbl PTR_FUN_009e12c4
//
// FIELD MAP (this = CollectReq*):
//   +0x08  slot (byte, attr via FUN_00799820)
//   +0x10  CBID (i32)
//   +0x14  NumToCollect (i32)
//   +0x18  TakeAllItems (bool, value==1)
//   +0x19  TargetIsPlayer (bool, value!=0)
//   +0x1a  TargetIsTemplateVehicle (bool, value!=0)
//   +0x1c  OptionalTarget count (i32, max 10)
//   +0x20  OptionalTargetCBID[10] (i32, init -1)
//   +0x48  OptionalDropPercent (float, _wtof)
//   +0x4c  GiveToAllConvoyMembers (bool, value==1)
//   +0x50  AllowedType (i32)
//   +0x54  AllowedClass (i32)
//   +0x58  LevelRestriction flag (byte)
//   +0x5c  RequireLevelMin (i32)
//   +0x60  RequireLevelMax (i32)
//   +0x64  ContinentCBID (i32)
//
// SIBLINGS: Action 0x00611f20 (+0x04), Eval 0x00611940 (+0x10), SlotAction 0x006124b0 (+0x18)
// =============================================================================

#include <wchar.h>
#include <wtypes.h>  // BSTR / OLECHAR (illustrative; retail uses MSXML COM)

// External / unresolved helpers (retail names open)
extern void FUN_00799820(/* attr helper: writes slot byte */);
extern void FUN_007a4480(int level, const char* fmt, ...);
extern void FUN_0040d230(/* BSTR* p: SysFreeString(*p); *p=0 */);
extern long _wtol(const wchar_t* s);
extern double _wtof(const wchar_t* s);
extern int _wcsicmp(const wchar_t* a, const wchar_t* b);
extern void SysFreeString(BSTR bstr);

// COM: IXMLDOMNode-like; methods referenced by vtbl offset only.
struct MsxmlNode {
    void** vtbl;
};

struct CollectReq {
    void** vtbl;                 // +0x00  PTR_FUN_009e12c4
    void*  ownerMission;         // +0x04
    unsigned char slot;          // +0x08
    // ... packing to +0x0c type code (set in ctor = 2) ...
    int    cbid;                 // +0x10
    int    numToCollect;         // +0x14
    unsigned char takeAllItems;  // +0x18
    unsigned char targetIsPlayer;// +0x19
    unsigned char targetIsTemplateVehicle; // +0x1a
    int    optionalTargetCount;  // +0x1c
    int    optionalTargetCbid[10]; // +0x20
    float  optionalDropPercent;  // +0x48
    unsigned char giveToAllConvoyMembers; // +0x4c
    int    allowedType;          // +0x50
    int    allowedClass;         // +0x54
    unsigned char levelRestriction; // +0x58
    int    requireLevelMin;      // +0x5c
    int    requireLevelMax;      // +0x60
    int    continentCbid;        // +0x64
};

// Behavioral reconstruction (register/COM noise collapsed to named steps).
// Authoritative control flow: raw/aa_00611a00_FUN_00611a00.md + live decompile.

void __thiscall CVOGObjectiveRequirement_Collect_DeserializeXml(
    CollectReq* self,
    MsxmlNode* node)
{
    // node->vtbl[0x44/4] — COM prep (exact method open)
    ((void(__stdcall*)(MsxmlNode*))node->vtbl[0x44 / 4])(node);

    // Read attribute "slot" into self+0x08 (FUN_00799820 wrapper)
    FUN_00799820(/* L"slot", &self->slot, width=0xa — decomp order */);

    // node->vtbl[0x30/4] — obtain child attribute container
    MsxmlNode* child = nullptr;
    // ((... )node->vtbl[0x30/4])(...);  // result in register (decomp unaff_EBX)
    // if no child:
    //   FUN_007a4480(1, "!!!Mission - collect objective requirement lacking child nodes slot:%d\n", self->slot);
    //   return;

    if (child == nullptr) {
        FUN_007a4480(1,
            "!!!Mission - collect objective requirement lacking child nodes slot:%d\n",
            (int)self->slot);
        return;
    }

    // child->vtbl[0x20/4] — attribute enumerator; count in register (unaff_EBP)
    int attrCount = 0;
    void* attrEnum = nullptr; // unaff_ESI

    // ----- default init (re-applied each deserialize) -----
    self->targetIsTemplateVehicle = 0;
    for (int t = 0; t < 10; ++t)
        self->optionalTargetCbid[t] = -1;
    self->optionalTargetCount = 0;
    self->levelRestriction = 0;
    self->requireLevelMin = -1;
    self->requireLevelMax = -1;
    self->targetIsPlayer = 0;

    for (int i = 0; i < attrCount; ++i) {
        // attrEnum->vtbl[0x1c/4](i) → name BSTR
        // node/child value text via vtbl[0x68/4] → value BSTR
        const wchar_t* name = L"";  // placeholder for decomp walk
        BSTR value = nullptr;

        if (_wcsicmp(L"ContinentCBID", name) == 0) {
            // get text → _wtol → continent
            self->continentCbid = _wtol(value);
            SysFreeString(value);
        } else if (_wcsicmp(L"CBID", name) == 0) {
            self->cbid = _wtol(value);
            SysFreeString(value);
        } else if (_wcsicmp(L"TargetIsTemplateVehicle", name) == 0) {
            self->targetIsTemplateVehicle = (_wtol(value) != 0);
            SysFreeString(value);
        } else if (_wcsicmp(L"TargetIsPlayer", name) == 0) {
            self->targetIsPlayer = (_wtol(value) != 0);
            SysFreeString(value);
        } else if (_wcsicmp(L"NumToCollect", name) == 0) {
            self->numToCollect = _wtol(value);
            SysFreeString(value);
        } else if (_wcsicmp(L"OptionalTargetCBID", name) == 0) {
            if (self->optionalTargetCount < 10) {
                self->optionalTargetCbid[self->optionalTargetCount] = _wtol(value);
                self->optionalTargetCount += 1;
                SysFreeString(value);
            }
            // else: silently drop
        } else if (_wcsicmp(L"OptionalDropPercent", name) == 0) {
            self->optionalDropPercent = (float)_wtof(value);
            SysFreeString(value);
        } else if (_wcsicmp(L"TakeAllItems", name) == 0) {
            self->takeAllItems = (_wtol(value) == 1);
            SysFreeString(value);
        } else if (_wcsicmp(L"GiveToAllConvoyMembers", name) == 0) {
            self->giveToAllConvoyMembers = (_wtol(value) == 1);
            FUN_0040d230(/* &value */);
        } else if (_wcsicmp(L"AllowedType", name) == 0) {
            self->allowedType = _wtol(value);
            FUN_0040d230(/* &value */);
        } else if (_wcsicmp(L"AllowedClass", name) == 0) {
            self->allowedClass = _wtol(value);
            FUN_0040d230(/* &value */);
        } else if (_wcsicmp(L"RequireLevelMin", name) == 0) {
            self->requireLevelMin = _wtol(value);
            FUN_0040d230(/* &value */);
            self->levelRestriction = 1;
        } else if (_wcsicmp(L"RequireLevelMax", name) == 0) {
            self->requireLevelMax = _wtol(value);
            FUN_0040d230(/* &value */);
            self->levelRestriction = 1;
        }
        // else: unknown name ignored

        // attr release: child/attr->vtbl[0x08/4]
    }

    if (self->cbid == -1 && self->targetIsPlayer == 0) {
        // mission display name: *(int*)(*(int*)(self+4)+0x14c)+4
        FUN_007a4480(1,
            "!!!Mission - collect objective did not find an item to collect: %S\n",
            /* missionName */);
    }

    // COM teardown + SysFreeString of temps; restore SEH
}
