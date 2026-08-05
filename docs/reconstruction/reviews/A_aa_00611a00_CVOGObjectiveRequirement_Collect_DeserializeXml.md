# Review A (reconstruction fidelity): `aa_00611a00` Collect_DeserializeXml

| Field | Value |
|---|---|
| **Stable ID** | `aa_00611a00` |
| **VA** | `0x00611a00` |
| **Canonical name** | `CVOGObjectiveRequirement_Collect_DeserializeXml` |
| **Prior FUN_** | `FUN_00611a00` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction-fidelity review |
| **Counterpart** | `reviews/B_aa_00611a00_CVOGObjectiveRequirement_Collect_DeserializeXml.md` |
| **Verdict** | **accept-with-gaps** |
| **System** | missions-progression |

---

## 1. Purpose / role

**Collect requirement XML/MSXML attribute loader** (virtual method on Collect `PTR_FUN_009e12c4` at **vtable +0x48**).

Loads mission-file child-node attributes into a `CVOGObjectiveRequirement_Collect` instance (`this` = ECX/`param_1`). Sibling roles:

| Slot | VA | Role |
|------|-----|------|
| vtbl+0x04 | `0x00611f20` | Collect_Action (kill-loot + inventory event) |
| vtbl+0x10 | `0x00611940` | Collect_Eval (cargo count / NumToCollect) |
| vtbl+0x18 | `0x006124b0` | Collect_SlotAction (UI have/need) |
| **vtbl+0x48** | **`0x00611a00`** | **Collect_DeserializeXml (this unit)** |

Does **not** compute progress, spawn loot, or write objective-state floats. Pure **GLM/XML field ingest**.

---

## 2. Inspected artifacts

| Artifact | Path / note |
|---|---|
| Live Ghidra | `decompile_function` @ `0x00611a00` (this session ≡ raw) |
| Live Ghidra | `analyze_function_complete` — callees, DATA xref only |
| Live Ghidra | `read_memory` vtable `0x009e12c4` (80 B) → slot `0x009e130c` = LE `00 1a 61 00` |
| Live Ghidra | Collect ctor `0x00611690` — type **2**, vtable install, field defaults |
| Live Ghidra | `FUN_0040d230` — BSTR free+null (cleanup helper) |
| Live Ghidra | `FUN_00799820` — attribute byte write helper (`slot`) |
| Raw | `raw/aa_00611a00_FUN_00611a00.md` |
| Annotated | `raw/aa_00611a00_FUN_00611a00.annotated.md` |
| Scaffold clean | `reconstructed-exact/FUN_00611a00.cpp` |
| Named clean (this pass) | `reconstructed-exact/CVOGObjectiveRequirement_Collect_DeserializeXml.cpp` |
| Function record | `functions/aa_00611a00_CVOGObjectiveRequirement_Collect_DeserializeXml.md` |
| Registry | `NAMING_REGISTRY.md` → `CVOGObjectiveRequirement_Collect_DeserializeXml` |
| Chain | `reviews/CHAIN_2026-07-29_inventory_collect.md` |
| AutoCore port | `src/.../ObjectiveRequirementCollect.cs` `UnSerialize` |
| Siblings dual | A/B `aa_00611940`, `aa_00611f20`, `aa_006124b0` |

**Not used:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Signature / entry

```c
// MSVC __thiscall
void __thiscall CVOGObjectiveRequirement_Collect_DeserializeXml(
    CollectReq* this,   // ECX — Collect requirement object
    IXMLDOMNode* node); // stack0 — requirement XML element (MSXML COM)
```

- **Direct CODE callers:** none (`get_function_callers` empty).
- **DATA xref:** sole listed xref to function body is vtable pointer at **`0x009e130c`** (`PTR_FUN_009e12c4 + 0x48`).
- Virtual-only dispatch (same pattern as Collect_Eval/Action).

---

## 4. Control flow (sealed)

```
1. SEH setup (DAT_009a8530)
2. node->vtbl[+0x44]()                     // COM prep on requirement element
3. FUN_00799820(..., L"slot", this+8, 0xa) // write slot byte at this+0x08
4. child = node->vtbl[+0x30]()             // first/only child node set
5. if child == null:
     log "!!!Mission - collect objective requirement lacking child nodes slot:%d\n"
         with (byte)this->slot; return
6. child->vtbl[+0x20]()                    // attribute map / enumerator
7. DEFAULT INIT (see §5)
8. for i in 0 .. attrCount-1:
     name = attrs[i].name  (BSTR, case-insensitive via _wcsicmp)
     value = attrs[i].text (_wtol / _wtof)
     match name → write field (unknown names ignored — goto LAB_00611e94)
     release attr COM
9. if (this->CBID == -1) && (!this->TargetIsPlayer):
     log "!!!Mission - collect objective did not find an item to collect: %S\n"
         with mission name string from *(this+4)+0x14c+4
10. release COM / BSTRs; restore ExceptionList; return
```

Decompiler shows `unaff_EBX` / `unaff_EBP` / `unaff_ESI` for COM results that land in registers — body still readable as attribute walk.

---

## 5. Field map (sealed High)

Defaults applied **before** attribute walk (re-init even after ctor):

| Offset | Field (XML name) | Init / write rule | Parse |
|-------:|------------------|-------------------|-------|
| `+0x08` | slot (attr, not child) | via `FUN_00799820` early | byte |
| `+0x10` | **CBID** | ctor `-1`; write `_wtol` | item clonebase id |
| `+0x14` | **NumToCollect** | ctor `0`; write `_wtol` | need count |
| `+0x18` | **TakeAllItems** | ctor `0`; write **`_wtol == 1`** | bool (strict 1) |
| `+0x19` | **TargetIsPlayer** | init `0`; write **`_wtol != 0`** | bool (any nonzero) |
| `+0x1a` | **TargetIsTemplateVehicle** | init `0`; write **`_wtol != 0`** | bool |
| `+0x1c` | optional-target **count** | init `0` | int, max **10** |
| `+0x20`..`+0x44` | **OptionalTargetCBID** ×10 | each init `-1` | append if count &lt; 10 |
| `+0x48` | **OptionalDropPercent** | ctor float `0`; write `_wtof` → float | drop % |
| `+0x4c` | **GiveToAllConvoyMembers** | write **`_wtol == 1`** | bool (strict 1) |
| `+0x50` | **AllowedType** | ctor `-1`; write `_wtol` | bitmask/class type |
| `+0x54` | **AllowedClass** | ctor `-1`; write `_wtol` | bitmask |
| `+0x58` | level-restriction **flag** | init `0`; set **1** if RequireLevelMin **or** Max seen | byte |
| `+0x5c` | **RequireLevelMin** | init `-1`; write `_wtol` | |
| `+0x60` | **RequireLevelMax** | init `-1`; write `_wtol` | |
| `+0x64` | **ContinentCBID** | ctor `-1`; write `_wtol` | continent filter |

### Bool polarity (important)

| Field | Client truth test |
|-------|-------------------|
| TargetIsPlayer / TargetIsTemplateVehicle | `value != 0` |
| TakeAllItems / GiveToAllConvoyMembers | `value == 1` only |

### Cap

- `OptionalTargetCBID`: if count already **≥ 10**, additional tags are **silently dropped** (no log).

### Post-parse validation

- Missing item: **`CBID == -1` AND `TargetIsPlayer == 0`** → error log (does **not** abort further; COM teardown still runs).
- `TargetIsPlayer` with no CBID is **accepted** (player-kill collect path).

---

## 6. Ctor defaults cross-check (`0x00611690`)

| Item | Value | Confidence |
|------|-------|------------|
| Vtable | `*this = PTR_FUN_009e12c4` | **High** |
| Type code | `this+0x0c = 2` (Collect) | **High** |
| CBID / OptionalTarget slots / Continent / Allowed* / Level min-max | `-1` | **High** |
| NumToCollect / target count / drop float | `0` | **High** |
| Matches deserialize init of target array + flags | Yes | **High** |

---

## 7. Callees

| Callee | Role |
|--------|------|
| `FUN_00799820` | Write `slot` attribute into `this+8` |
| `_wcsicmp` | Case-insensitive XML field name match (13 names) |
| `_wtol` / `_wtof` | Integer / float value parse from wide text |
| `SysFreeString` | BSTR free on most value paths |
| `FUN_0040d230` | Fast BSTR free+null (`*ptr` free, then null) — used on GiveToAllConvoy / Allowed* / RequireLevel paths |
| `FUN_007a4480` | Mission error logger (two strings) |
| MSXML COM vtbl | `+0x44`, `+0x30`, `+0x20`, `+0x1c`, `+0x68`, `+0x08` — node/attr walk |

---

## 8. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| Role = Collect XML deserialize / field load | **High** | string table + write-only to `this` + 13 field names |
| Name `Collect_DeserializeXml` | **High** (layout/RTTI/family); original PDB open | Registry + sibling Action/Eval |
| Vtable slot `+0x48` only entry | **High / Confirmed** | `read_memory` `0x009e130c` = `0x00611a00`; no CODE callers |
| Field offsets §5 | **High / Confirmed** | decompile stores; ctor defaults; Eval/Action consumers of +0x10/+0x14/+0x48/+0x1c/+0x20… |
| OptionalTarget max 10 | **High / Confirmed** | `if (*(int*)(this+0x1c) < 10)` before store |
| TakeAllItems / GiveToAllConvoy **== 1** | **High / Confirmed** | decompile `lVar2 == 1` |
| TargetIsPlayer / Template **!= 0** | **High / Confirmed** | decompile `lVar2 != 0` |
| Drop % is float via `_wtof` | **High / Confirmed** | only `_wtof` site → `*(float*)(this+0x48)` |
| Missing-CBID error gated by !TargetIsPlayer | **High / Confirmed** | final `if` |
| Level flag +0x58 set on Min **or** Max | **High / Confirmed** | shared tail after both branches |
| Unknown attribute names ignored | **High** | `goto LAB_00611e94` |
| COM vtbl ordinal semantics | **Probable** | ordinals consistent with other mission XML loaders; exact MSXML IIDs open |
| Register recovery of child/attr enumerator (`unaff_*`) | **Probable** | decompiler SEH/COM noise; CF structure sealed |
| Clean ≡ field map + CF | **High** (behavioral) | named clean this pass |
| Runtime / bit-exact | Open | policy |

---

## 9. AutoCore port notes (fidelity, not blocking this unit)

| Client (this unit) | AutoCore `ObjectiveRequirementCollect.UnSerialize` | Note |
|---|---|---|
| `RequireLevelMin` | typo element `ReqireLevelMin` | server may miss real GLM key |
| TakeAllItems `== 1` | `(int)takeItems != 0` | nonzero-only values differ |
| GiveToAllConvoy `== 1` | `!= 0` | same |
| OptionalTarget[10] | array of 10 | **aligned** |
| CBID / Num / drop / continent / Allowed* / TargetIs* | present | **aligned** |
| Missing-child / missing-CBID logs | not mirrored | client-only diagnostics |

---

## 10. Residual / gaps

1. Exact MSXML interface / vtbl method names for `+0x44/+0x30/+0x20/+0x68` — Probable only.
2. Whether any non-virtual CODE path calls this body (none found).
3. Original PDB symbol name.
4. Runtime mission XML load observation.
5. Bit-exact / image diff (policy).

**Verdict:** **accept-with-gaps** — field map, vtable placement, role, and bool polarities sealed static; COM ordinal names + runtime open.
