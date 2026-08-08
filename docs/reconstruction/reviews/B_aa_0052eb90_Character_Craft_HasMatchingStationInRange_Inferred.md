# Review B (skeptical / adversarial): `aa_0052eb90` Character_Craft_HasMatchingStationInRange_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052eb90` |
| **VA** | `0x0052eb90` |
| **Canonical name** | `Character_Craft_HasMatchingStationInRange_Inferred` |
| **Review date** | `2026-08-05` (R12-021) |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_0052eb90_Character_Craft_HasMatchingStationInRange_Inferred.md` |
| **System** | inventory-transfer — craft station proximity gate |
| **Verdict** | **accept-with-gaps** — agree with A |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs + call-site disasm context (no `disassemble_bytes`). No Launcher.

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_0052eb90` only | Scaffold OK; under-describes sealed craft-gate role |
| `Named_CalleeOf_*RefreshOpenMissionUiWindow*` | **Reject** — chain-of-caller plate; body has zero mission IDs/strings; consumers are craft host + tooltip |
| Inventory grid place / find / footprint | **Reject** — no grid X/Y, no COID stamp, no type-1/3/5/6 switch |
| Skill cast / target-list resolve | **Reject** — no opcode pack; DisciplineDef map + station subtype flags |
| Always-true / always-false stub | **Reject** — multi-exit with distance + flag ladder |
| Pure `DAT_00d1b6d8` global function (no this) | **Reject** — prologue `MOV ESI,ECX`; thiscall |
| cdecl / no stack cleanup | **Reject** — `RET 0x4` on all exits |
| `SkillDefMap` lookup | **Reject** — callee is dualed **DisciplineDef** map `0052b040` (distinct globals) |
| Product English "WorkbenchProximity" without `_Inferred` | **Reject** — subtypes/flags unproven in PDB |
| `Character_Craft_HasMatchingStationInRange_Inferred` | **Accept** — craft consumers + DisciplineDef + range; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Decompiler `undefined4` means dword return contract | **Fails** — all exits set `AL`; callers `TEST AL` / `MOV [host+0x7e2],AL` |
| `iStack_c/8/4` are uninitialized stack garbage | **Fails** — they are the last 12 bytes of the 0x1FC DisciplineDef out-buffer filled by `0052b040` (0x7f dwords) |
| Distance uses center Euclidean only | **Fails as rename** — callee is dualed **SurfaceDistance3D** (radii subtracted); threshold still 50.0f |
| `FCOMIP` means distance **>** 50 allows match | **Fails** — `JC` skips match when `50.0 < dist` (CF=1); match only when dist ≤ 50 |
| `+0x6b4` is transmission ratio / physics | **Fails in this unit** — same offset family used as RE free gate on character; physics +0x6b4 is different type |
| Four xrefs are four different semantics | **Fails** — all load `DAT_00d1b6d8` into ECX and push a craft/item object; three write craft enable/`+0x7e2`, one greyscales tooltip |
| Partition parent `008e6b50` is only structural caller | **Fails as sole-caller claim** — 4 call sites; parent is wave score / primary craft CreateChildWidgets consumer |
| Map miss returns false (deny craft) | **Fails** — miss path `MOV AL,1` (allow) |
| Subtype compare is CloneBaseObjectType Vehicle=14 | **Fails as identity** — field is clonebase **short +0x3f4** (subtype), not object-type dword at +0x38; values 0xD/0xE/0xF happen to include 14 but are station flags here |
| Product demangle proven | **Fails** — open; keep `_Inferred` |

---

## 3. Cross-check against raw + bytes

```text
SUB ESP,0x220; PUSH EBP; PUSH ESI; ESI=ECX
cmp [MI+0xa8],0 / cmp object,0 → AL=0 RET 4
cmp [ESI+0x6b4],1 JGE → AL=1 RET 4
push out; push def+0x4ac; CALL 0052b040; ADD ESP,8
TEST AL; JZ → AL=1 RET 4
idx=0
loop:
  CALL 004e5810 (count); optional delete
  if idx >= count → AL=0 RET 4
  CALL 004e5810; ResolveObjectTarget via +0xe4e8
  optional delete
  if obj && vtbl+0x1c8:
    vtbl+0x1c8 → push; char_sub vtbl+0x19c; CALL 0053e510
    FLD [00a0f524=50.0]; FCOMIP; JC skip
    subtype = def+0x3f4; ladder 0xD/0xE/0xF vs flag dwords
    if flag nonzero → AL=1 RET 4
  idx++
```

Caller samples:
```text
; craft CreateChildWidgets tail
PUSH [EBP+0x7cc]
MOV ECX,[DAT_00d1b6d8]
CALL 0052eb90
MOV [EBP+0x7e2],AL

; tooltip
PUSH item
MOV ECX,[DAT_00d1b6d8]
CALL 0052eb90
NEG AL / SBB / AND 0xdfdf  ; color select
```

Clean must **not** invent mission UI, inventory footprint place, skill-cast packing, SkillDefMap, or claim product demangle / Runtime Confirmed.

---

## 4. Agreement with Review A

- CF + thiscall RET 4 + bool AL + 50.0f + DisciplineDef flags: **agree Confirmed/High**
- Name with `_Inferred`: **agree**
- Gaps (subtype English, `+0x6b4` lexicon, `004e5810` dual, runtime): **agree open**

---

## 5. Surviving contract for AutoCore

```csharp
// Character-side craft station proximity gate (client display / UI enable)
bool HasMatchingCraftStationInRange(Character self, Object craftObject)
{
    if (self.Object == null || craftObject == null) return false;
    if (self.ReverseEngineerOpenFlag /* +0x6b4 */ > 0) return true;

    if (!DisciplineDefMap.TryCopy(craftObject.CloneBase.DisciplineId /* +0x4ac */, out var def))
        return true; // no row → allow

    foreach (var tfid in self.Object.TfidVector /* +0xe7f8 */)
    {
        var near = Resolve(self.Object.ResolveCtx /* +0xe4e8 */, tfid);
        if (near == null) continue;
        if (SurfaceDistance3D(self, near) > 50.0f) continue;

        short subtype = near.CloneBase.Subtype /* +0x3f4 */;
        if (subtype == 0x0D && def.StationFlagD != 0) return true;
        if (subtype == 0x0E && def.StationFlagE != 0) return true;
        if (subtype == 0x0F && def.StationFlagF != 0) return true;
    }
    return false;
}
// Native: ECX=character, stack=craftObject, AL bool, RET 4
```

**Port note:** UI stores result at craft host `+0x7e2`. Do **not** implement as mission refresh helper or inventory grid op. Pair with dualed DisciplineDef map `0052b040`, dualed SurfaceDistance3D `0053e510`, dualed craft CreateChildWidgets `008e6b50`.
