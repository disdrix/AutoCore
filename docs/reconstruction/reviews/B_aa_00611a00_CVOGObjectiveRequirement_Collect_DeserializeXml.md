# Review B (skeptical / adversarial): `aa_00611a00` Collect_DeserializeXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611a00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00611a00_CVOGObjectiveRequirement_Collect_DeserializeXml.md` |
| **Verdict** | **accept-with-gaps** on field map + role; COM detail open |
| **System** | missions-progression |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is Collect_Eval or Action | **Falsified** — no CountItems, no GiveItem, no progress math; only attribute ingest + logs |
| 2 | This is Serialize (write XML out) | **Falsified** — body only writes into `this` fields from node text; no emit path |
| 3 | Function is called directly from CODE | **Falsified** — callers empty; sole DATA xref is vtable `0x009e130c` |
| 4 | OptionalTarget array is unbounded / dynamic vector | **Falsified** — fixed 10 dwords at `+0x20`; count at `+0x1c`; drop when count≥10 |
| 5 | All bool fields use the same truth test | **Falsified** — TargetIs* use `!=0`; TakeAllItems/GiveToAllConvoy use `==1` |
| 6 | Continent is at same offset as CBID family near +0x10 | **Falsified** — Continent at **`+0x64`** (ctor `param_1[0x19]`) |
| 7 | OptionalDropPercent is integer percent stored as int | **Falsified** — `_wtof` → `float` at `+0x48` |
| 8 | Missing CBID always errors | **Falsified** — error only if CBID==-1 **and** !TargetIsPlayer |
| 9 | Level min/max do not set a combined flag | **Falsified** — both paths set `*(this+0x58)=1` |
| 10 | `FUN_0040d230` is domain logic / free-list | **Falsified** — decompile is `SysFreeString(*p); *p=0` only |
| 11 | Scaffold string-name `Mission_Mission_collect_objective_requirement_lacking_ch_*` is the role | **Rejected as primary name** — that is an error string slice; role is DeserializeXml |
| 12 | AutoCore `UnSerialize` is bit-identical to client | **Partial fail** — typo `ReqireLevelMin`; TakeAll/GiveToAll `!=0` vs client `==1` |
| 13 | This unit owns kill-loot or cargo progress | **Falsified** — those are Action `0x00611f20` / Eval `0x00611940` |

---

## 2. Surviving contract for AutoCore

```
Collect_DeserializeXml(req, xmlNode):
  // COM: require child attribute bag; else log lacking-child(slot) and return
  req.TargetIsTemplateVehicle = 0
  req.OptionalTargets[0..9] = -1
  req.OptionalTargetCount = 0
  req.LevelRestriction = 0
  req.RequireLevelMin = req.RequireLevelMax = -1
  req.TargetIsPlayer = 0
  for each attribute name/value (case-insensitive name):
    ContinentCBID        -> req+0x64 = atoi
    CBID                 -> req+0x10 = atoi
    TargetIsTemplateVehicle -> req+0x1a = (atoi != 0)
    TargetIsPlayer       -> req+0x19 = (atoi != 0)
    NumToCollect         -> req+0x14 = atoi
    OptionalTargetCBID   -> if count < 10: req+0x20+count*4 = atoi; count++
    OptionalDropPercent  -> req+0x48 = (float)atof
    TakeAllItems         -> req+0x18 = (atoi == 1)
    GiveToAllConvoyMembers -> req+0x4c = (atoi == 1)
    AllowedType          -> req+0x50 = atoi
    AllowedClass         -> req+0x54 = atoi
    RequireLevelMin      -> req+0x5c = atoi; LevelRestriction=1
    RequireLevelMax      -> req+0x60 = atoi; LevelRestriction=1
    // else ignore
  if req.CBID == -1 && !req.TargetIsPlayer:
    log missing collect item (mission name from owner)
  // no throw / no hard fail return code
```

Port rules:

- Do **not** treat this as progress or loot code.
- Prefer client bool polarities when matching retail mission XML (`==1` vs `!=0`).
- Cap optional targets at **10**.
- Keep Continent at end of Collect layout (`+0x64`), not next to CBID.
- Fix server typo `ReqireLevelMin` → `RequireLevelMin` if GLM uses the client spelling.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = XML field load for Collect | **High** | Mis-wire to Action/Eval |
| Offsets for CBID / Num / drop / targets | **High** | Eval/Action read wrong memory |
| Bool `==1` vs `!=0` split | **High** | TakeAll/convoy flags silently false on "2" etc. |
| Vtable +0x48 placement | **High** | Wrong virtual dispatch |
| COM method names | **Probable** | Wrong if reverse MSXML IDs matter |
| unaff_* register COM objects | **Probable** | Decompiler noise only; CF still holds |
| Runtime mission load | Open | Policy |

---

## 4. Residual disposition

| Gap | Disposition |
|-----|-------------|
| Field map + bool polarity | **Sealed High** (live decompile this pass) |
| Vtable DATA-only entry | **Sealed High** (`read_memory` + empty callers) |
| Type code 2 / Collect class | **Sealed High** (ctor `0x00611690`) |
| Serialize vs Deserialize naming | **Sealed** as Deserialize (ingest only) |
| COM ordinal dictionary | Still **Probable / open** |
| PDB original name | Open |
| Runtime / bit-exact | Open |

---

## 5. Open questions

1. Full MSXML interface map for the vtbl ordinals used here (shared with other objective loaders?).
2. Does any authoring tool emit TakeAllItems/GiveToAll values other than 0/1?
3. Is ContinentCBID default `-1` treated as “any continent” by Action/Eval consumers?
4. Sibling Kill/Deliver deserialize layout parity (offsets may differ per class).

**Verdict:** **accept-with-gaps** — adversarial pass does not break field map, role, or vtable placement. COM method names and runtime remain open.
