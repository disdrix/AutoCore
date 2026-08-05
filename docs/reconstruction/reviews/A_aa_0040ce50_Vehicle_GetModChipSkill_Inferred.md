# Review A (reconstruction fidelity): `aa_0040ce50` Vehicle_GetModChipSkill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040ce50` |
| **VA** | `0x0040ce50`–`0x0040ce79` (body; `ret` / no stack args) |
| **Canonical name** | `Vehicle_GetModChipSkill_Inferred` (prior `FUN_0040ce50`) |
| **Plate alias** | `Named_CalleeOf_Named_CalleeOf_Client_Input_DriveControlTick_0040ce50` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040ce50_Vehicle_GetModChipSkill_Inferred.md` |
| **System** | input-drive-control / inventory race-item (mod-chip skill side-path) |
| **Evidence pass** | Live `decompile 0x0040ce50` + `read_memory` full leaf; sole caller dual `aa_0091f6b0`; twin walk `aa_004fb630` GetHpRegenRate |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny **pure getter** leaf: return the equipped vehicle **mod-chip skill binding** (dword) from the **race-item** hardpoint, or sentinel **`-1`** when no race item is equipped.

Walk (sealed ≡ `Vehicle_GetHpRegenRate` dual-base pattern):

1. `pRace = *(vehicle + 0x270)`.
2. If `pRace == 0` → return **`0xffffffff` (−1)**.
3. Else dual-base adjust:  
   `adj = *(*( *(pRace+4) + 4 ) + 0xAC + pRace)`  
   `sub = *(adj + 0x3C)`  
   return **`*(sub + 0x3BC)`** as `u32` / skill binding dword.

**Sole production caller:** `Client_Input_TryUseModChip` (`0x0091f6b0`) — uses return as `Skill_LocalCastValidate` skill arg; treats **−1** as “no mod chip” → modal `"You have no mod chip!"`.

No mutation. No callees. No globals.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0040ce50_FUN_0040ce50.md` |
| Annotated | `docs/reconstruction/raw/aa_0040ce50_FUN_0040ce50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0040ce50.cpp` |
| Function record | `docs/reconstruction/functions/aa_0040ce50_FUN_0040ce50.md` |
| Sole-caller dual | `reviews/A_aa_0091f6b0_Client_Input_TryUseModChip.md` / `B_…` |
| Twin walk | `Vehicle_GetHpRegenRate` `0x004fb630` (field `+0x3FA` short; null→0) |
| Live | `decompile` + `read_memory` `@0x0040ce50` length 48; `get_function_callers` |

**Three-rep:** present (scaffold → dual-refined 2026-07-29).

---

## 3. Signature (image-sealed)

```c
// __fastcall / thiscall: ECX = vehicle*
// no stack args; plain `ret` (0xC3)
// returns u32 skill-binding dword, or 0xFFFFFFFF when race-item null
uint32_t __fastcall Vehicle_GetModChipSkill_Inferred(void *vehicle);
```

| Item | Evidence | Conf |
|---|---|---|
| ECX = `this` / vehicle | `cmp [ecx+0x270],0` then loads via ECX | **High** |
| Plain `ret` (no `ret N`) | bytes `c3` @ hit path + miss path | **High** |
| Null race → `or eax,-1` | `83 c8 ff` / `c3` | **High** |
| Field load dword `@+0x3bc` | `8b 81 bc 03 00 00` | **High** |
| Dual-base `+0xac` / sub `+0x3c` | identical encoding family to `0x004fb630` | **High** |

### Leaf bytes (`read_memory` `@0x0040ce50`, 42B body + pad)

```
83 b9 70 02 00 00 00    cmp dword ptr [ecx+0x270], 0
74 1d                   je  miss
8b 81 70 02 00 00       mov eax, [ecx+0x270]      ; raceItem*
8b 48 04                mov ecx, [eax+4]
8b 51 04                mov edx, [ecx+4]
8b 84 02 ac 00 00 00    mov eax, [edx+eax+0xac]  ; dual-base adj
8b 48 3c                mov ecx, [eax+0x3c]      ; subrecord*
8b 81 bc 03 00 00       mov eax, [ecx+0x3bc]     ; skill binding dword
c3                      ret
83 c8 ff                or  eax, -1
c3                      ret
```

### Dual-base sketch (shared with HP/shield regen getters)

```
vehicle+0x270 : RaceItem* (hardpoint; inventory map sealed)
RaceItem multi-inherit:
  adj  = *(*( *(race+4)+4 ) + 0xAC + race)
  sub  = *(adj + 0x3C)
  out  = *(sub + 0x3BC)     // THIS unit — dword skill binding
  // twin GetHpRegenRate: (i16)*(sub + 0x3FA)
  // twin GetShieldRegenRate: (i16)*(sub + 0x4B6)
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| `vehicle+0x270 == 0` → −1 | **Yes** | **High** |
| Else dual-base → `sub+0x3bc` dword | **Yes** | **High** |
| Pure leaf (no calls) | **Yes** | **High** |
| No invented branches | **Yes** | **High** |

---

## 5. Caller contract (sealed by parent dual, owned here as consumer)

| Site | Function | Use of return |
|---|---|---|
| only | `Client_Input_TryUseModChip` `0x0091f6b0` | `== -1` → `"You have no mod chip!"`; else `Skill_LocalCastValidate(..., skill=ret)` |

`get_function_callers` → **only** `FUN_0091f6b0`. Not a shared inventory API.

Parent also requires `player+0x250` vehicle non-null before calling; this leaf only checks race-item slot on that vehicle.

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF / offsets / sentinel −1 | **High** | full leaf bytes sealed |
| `+0x270` = race-item hardpoint | **High** | inventory equip map + twin regen getters |
| Dual-base walk form | **High** | byte-identical pattern family vs `0x004fb630` |
| Role = mod-chip skill lookup | **High** | sole caller string + LocalCastValidate |
| Return is skill **object*** | **Medium** | caller casts to `void*` skill; sibling item path uses `cloneMeta+0x3bc` as **id** into vtbl skill resolve — type residual |
| Product symbol | **Open** | `_Inferred`; no RTTI/string in leaf |
| Subrecord English at `+0x3C` / field `+0x3BC` | **Tentative** | clonebase / skill-binding names open |
| Runtime / bit-exact | **Open** | deferred |

---

## 7. Gaps

1. Product name (not FUN).
2. Whether `+0x3BC` is skill object*, skill id, or skill-def handle (LocalCastValidate ABI).
3. Whether non-mod-chip race items can still hold a non−1 binding (false “has chip” path).
4. Type plate for dual-base adj / subrecord.

**Verdict:** **accept-with-gaps**
