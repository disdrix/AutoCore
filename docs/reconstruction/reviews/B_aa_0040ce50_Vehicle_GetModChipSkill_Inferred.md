# Review B (skeptical / adversarial): `aa_0040ce50` Vehicle_GetModChipSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ce50` |
| **VA** | `0x0040ce50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B) |
| **Counterpart** | `reviews/A_aa_0040ce50_Vehicle_GetModChipSkill_Inferred.md` |
| **Evidence** | Full leaf bytes; sole-caller dual `aa_0091f6b0`; twin regen getters `+0x270` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Result | Why |
|---|---|---|---|
| 1 | Shared inventory / multi-caller helper | **Falsified** | `get_function_callers` → **only** `0x0091f6b0` |
| 2 | Reads power plant / weapon / armor slot | **Falsified** | sole load base is **`vehicle+0x270`** (race-item hardpoint) |
| 3 | Null race → return **0** / null | **Falsified** | miss path `or eax,-1` → **`0xFFFFFFFF`** (caller `== -1` toast) |
| 4 | Returns short regen rate | **Falsified** | dword load `@+0x3bc`; twins use `+0x3FA`/`+0x4B6` shorts |
| 5 | Mutates vehicle / equip state | **Falsified** | pure loads + ret |
| 6 | Has callees / string table | **Falsified** | leaf; no `call`, no DAT |
| 7 | `__stdcall` / stack args | **Falsified** | ECX this; plain `c3` ret |
| 8 | “Mod chip” is a separate hardpoint not race-item | **Falsified as distinct slot** | chip role is **string/caller-driven**; storage is race-item `+0x270` field `+0x3bc` |
| 9 | Return is **proven** skill object* | **Not sealed** | residual — may be id/handle; do not over-claim |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF + offsets + −1 sentinel | **High** | false “no chip” / wrong skill into validate |
| Race-item slot identity `+0x270` | **High** | wrong hardpoint → equip bugs |
| Dual-base walk form | **High** | wrong clonebase field |
| Mod-chip **role** via sole caller | **High** | mis-name only if broader product uses same binding |
| Skill object* vs id | **Medium** | LocalCastValidate ABI / port type error |
| Product English | **Open** | rename debt |
| Runtime | **Open** | — |

---

## 3. Cross-check against raw / live

```
Live decompile 2026-07-29:
  if (*(param_1+0x270)!=0)
    return *(*( *(*( *(p+4)+4 )+0xac+p ) +0x3c ) +0x3bc);
  return 0xffffffff;

Bytes seal same CF. Clean scaffold CF matches; plate refined this dual.
Twin GetHpRegenRate: same walk, different field/width/sentinel — pattern not coincidence.
```

---

## 4. Surviving contract for AutoCore

```
Vehicle_GetModChipSkill_Inferred(vehicle) → u32:
  pRace = vehicle->raceItem@+0x270
  if !pRace: return -1
  sub = dualBase(pRace)->sub@+0x3C   // same adj as regen getters
  return *(u32*)(sub + 0x3BC)        // skill binding for mod-chip cast path

Caller TryUseModChip:
  if !vehicle || this()==-1: toast "You have no mod chip!"
  else LocalCastValidate(char, nullTarget, skipBusy, skillBinding)
```

Port rules:

* Do **not** treat 0 as missing — only **−1**.
* Do **not** invent extra hardpoint; race-item slot owns the binding.
* Keep pure (no side effects).

---

## 5. Open questions

1. Product symbol / PDB.
2. Exact type of dword `@ sub+0x3BC` (skill*, skillId, def handle).
3. Whether all race-item defs populate `+0x3BC` or only “mod chip” items.
4. Relationship to item-use path `cloneMeta+0x3bc` → vtbl`+0x234` skill resolve (`Client_UseInventoryItem_Inferred`) — same field English?

**Verdict:** **accept-with-gaps**
