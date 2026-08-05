# Review A (reconstruction fidelity): `aa_00519150` Skill_GetCategoryCooldownRemaining

| Field | Value |
|---|---|
| **Stable ID** | `aa_00519150` |
| **VA** | `0x00519150` |
| **Canonical name** | `Skill_GetCategoryCooldownRemaining` |
| **Review date** | `2026-07-29` (dual A/B strengthen; prior scaffold `2026-07-23`) |
| **Reviewer role** | Reconstruction fidelity / dual residual |
| **Counterpart** | `reviews/B_aa_00519150_Skill_GetCategoryCooldownRemaining.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** (CF + ABI + return modes sealed) |

---

## 1. Purpose

Query remaining **category cooldown** for `nCategoryId` on the map-owner's lazy map (`Skill_GetCategoryCooldownMap` → owner **`+0x6c`**). On hit: `deadline = start(+0x10) + duration(+0x14)`; if `g_dwClientTickMs >= deadline`, **erase** the node and return `0.0f`; if still active, return either **remaining/duration fraction** (`bAsSeconds == 0`) or **remaining seconds** (`bAsSeconds != 0`, `ms * g_flMsToSeconds`). On miss: return `0.0f`.

Call sites pass category from **`skill+0x5e8`**. Used by LocalCastValidate gate (**code 7**), QuickBar CD gauge/overlay, NPC cast gate, and related UI.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra MCP `decompile_function` / `analyze_function_complete` @ `0x00519150` |
| Bytes | `read_memory` @ `0x00519150` len 128 + tail @ `0x005191b0`/`0x005191df`/`0x005191f1` |
| Globals | `audit_globals_in_function` → `g_dwClientTickMs`, `g_flZero`, `g_flMsToSeconds_Inferred`, `DAT_00aaa5dc` |
| Callees | `Skill_GetCategoryCooldownMap`, `FUN_00418b80` (map find), `FUN_004188e0` (map erase) |
| Callers (6) | `Skill_LocalCastValidate`, `QuickBar_UpdateSkillSlotCooldownGauge`, `QuickBar_UpdateSlotCooldownOverlay`, `NPC_TryCastSkillFromSet`, `FUN_00892890`, `FUN_00922270` |
| Sibling duals | `A_aa_00518d70` GetMap; `a_0051d2f0` Map_Insert; InsertCategoryCooldown |
| Raw / clean | scaffold present (decompiler-garbled float paths — **asm authoritative**) |

---

## 3. Sealed ABI (Confirmed — machine)

```
005191b6  C2 08 00     RET 0x8   ; miss / expired
005191dc  C2 08 00     RET 0x8   ; bAsSeconds != 0 (seconds)
005191f8  C2 08 00     RET 0x8   ; bAsSeconds == 0 (fraction)
```

| Slot | Role | Evidence |
|---|---|---|
| **ECX** | map **owner** (not skill runtime) | prolog `mov esi,ecx`; GetMap×3; QB/LocalCast this-adjust onto owner |
| **stack0** | `int nCategoryId` | `mov eax,[esp+8]` after push ecx; find key |
| **stack1** | `char bAsSeconds` | `cmp byte ptr [esp+0x10],0` after two pushes |
| **ST0** | `float` return | all exits `fld` / `fild`+scale; callers `FUCOMIP` / `fstp` |
| **RET** | `0x8` | cleans two dwords |

```c
// MSVC __thiscall
float __thiscall Skill_GetCategoryCooldownRemaining(
    void *pMapOwner,   // ECX
    int   nCategoryId, // stack0
    char  bAsSeconds); // stack1 — see return modes
// RET 0x8
```

**Decompiler noise (falsified as authoritative):** invented `float10* __return_storage_ptr__` third-looking param; swapped/fused `nCategoryId`/`bAsSeconds`; identical dual returns; pointer return on miss/erase. Prefer bytes.

---

## 4. Sealed control flow (Confirmed)

```c
float __thiscall Skill_GetCategoryCooldownRemaining(void *pMapOwner, int nCategoryId, char bAsSeconds)
{
  void *map;
  void *it;           // stack local
  uint  start, duration, deadline, remaining;

  // ESI = pMapOwner
  map = Skill_GetCategoryCooldownMap(pMapOwner);          // 0x00518d70
  FUN_00418b80(map, &it, &nCategoryId);                // lower_bound/find by int key @ node+0x0C
  map = Skill_GetCategoryCooldownMap(pMapOwner);
  if (it == *(void **)((char *)map + 4)) {             // it == head → miss
    return g_flZero;                                   // fld [0x00a0f518]
  }

  duration = *(uint *)((char *)it + 0x14);             // +0x14
  start    = *(uint *)((char *)it + 0x10);             // +0x10
  deadline = start + duration;                         // may wrap unsigned
  // duration kept on stack for fraction path

  if (g_dwClientTickMs /*0x00b041cc*/ >= deadline) {   // cmp now,deadline; jb active
    map = Skill_GetCategoryCooldownMap(pMapOwner);
    FUN_004188e0(map, /*out*/, it);                    // RB erase + operator_delete
    return g_flZero;
  }

  remaining = deadline - g_dwClientTickMs;             // sub eax,edx

  if (bAsSeconds != 0) {
    // fild remaining; if signed-negative: fadd DAT_00aaa5dc (2^32)
    // fmul g_flMsToSeconds_Inferred @ 0x00a0f72c (= 0.001f)
    return (float)remaining * 0.001f;                  // remaining **seconds**
  } else {
    // fild remaining; optional +2^32
    // fidiv dword duration
    return (float)remaining / (float)duration;         // remaining **fraction** of total
  }
}
```

| Stage | Bytes | Match |
|---|---|---|
| `mov esi,ecx`; load category; GetMap + find | `8B F1` … `E8 … 518d70` / `418b80` | Yes |
| `it == [map+4]` → miss → `fld g_flZero` / `ret 8` | `3B 48 04` / `74` / `D9 05 18 F5 A0 00` | Yes |
| `+0x14` dur, `+0x10` start, add | `8B 51 14` / `8B 41 10` / `03 C2` | Yes |
| compare `g_dwClientTickMs` @ `00b041cc` | `8B 15 CC 41 B0 00` / `3B D0` / `72` active | Yes |
| expired → GetMap + `FUN_004188e0` erase | call sites `005191a2` / `005191a9` | Yes |
| active: `sub` remaining; test `bAsSeconds` | `2B C2` / `80 7C 24 10 00` | Yes |
| seconds: `fild` + optional `fadd 2^32` + `fmul 0.001` | `DB 44…` / `D8 05 DC A5 AA 00` / `D8 0D 2C F7 A0 00` | Yes |
| fraction: `fild` + optional `fadd 2^32` + `fidiv [duration]` | `DA 74 24 0C` | Yes |
| epilogue `pop esi; pop ecx; ret 8` | all three exits | Yes |

Function span: **`0x00519150`–`0x005191f9`** (ends `C2 08 00`; padding `CC`).

---

## 5. Sealed layouts / globals

### Category cooldown node (consumer of Insert layout)

| Off | Field | Width | Notes |
|---|---|---|---|
| +0x00 / +4 / +8 | left / parent / right | ptr | tree |
| +0x0C | **key** = categoryId | i32 | `FUN_00418b80` compares `node[3]` |
| +0x10 | **startTick** | u32 | this body |
| +0x14 | **durationMs** | u32/i32 | this body; fraction divisor |
| +0x18 / +0x19 | color / isnil | u8 | erase/find walk |
| size | | **0x1C** | sealed by Map_Insert dual |

### Globals (this unit)

| VA | Name | Value / role | Conf |
|---|---|---|---|
| `0x00b041cc` | `g_dwClientTickMs` | client ms tick (plate: GetTickCount-style) | **Confirmed** load + Insert start |
| `0x00a0f518` | `g_flZero` | `0.0f` — miss/expired return | **Confirmed** `read_memory` 00…00 |
| `0x00a0f72c` | `g_flMsToSeconds_Inferred` | **0.001f** (`6f 12 83 3a`) — seconds path | **Confirmed** |
| `0x00aaa5dc` | `DAT_00aaa5dc` | **2^32** as float (`00 00 80 4f`) — uint→x87 | **Confirmed** |

### Return modes (plate correction)

| `bAsSeconds` | Return (ST0) | Typical callers |
|---|---|---|
| **0** | `remainingMs / durationMs` ∈ (0,1] (≈0 if tiny) | QB first probe vs `DAT_00aaa664` (~1e-4) |
| **≠0** | `remainingMs * 0.001` **seconds** | LocalCast code 7; QB second call for gauge text/fill |

Prior scaffold text “else remaining **ms**” is **falsified** — false branch is **fraction**, not integer/ms float of remaining alone.

---

## 6. Callees (roles)

| VA | Name | Role | Conf |
|---|---|---|---|
| `0x00518d70` | `Skill_GetCategoryCooldownMap` | lazy map @ owner+0x6c | **Confirmed** |
| `0x00418b80` | `FUN_00418b80` | `std::map`-style **lower_bound/find** by int key @ node+0x0C; out it or head | **High CF** (body decompiled) |
| `0x004188e0` | `FUN_004188e0` | **erase** node (rebalance + `operator_delete`); throws on isnil iterator | **High CF** |

Product English names for find/erase helpers remain residual (shared MSVC tree helpers used elsewhere).

---

## 7. Callers (9 xrefs / 6 functions)

| Caller | Call sites | Args pattern | Use of ST0 |
|---|---|---|---|
| `Skill_LocalCastValidate` `0x0051a790` | `0x0051a8ac` | ECX=ESI caster; push **1**, push `skill+0x5e8` | `FUCOMIP` vs `g_flZero` → return **7** if remaining |
| `QuickBar_UpdateSkillSlotCooldownGauge` `0x00825520` | `0x00825924`, `0x00825959` | push **0** then **1**; cat `skill+0x5e8`; ECX this-adjust local char | 0: fraction > `DAT_00aaa664` (~1e-4); 1: seconds for gauge |
| `QuickBar_UpdateSlotCooldownOverlay` `0x00827ab0` | `0x00827d5e`, `0x00827d93` | same 0/1 pair | same |
| `NPC_TryCastSkillFromSet` `0x005d1280` | `0x005d15c4` | push **1**, cat | zero-test gate |
| `FUN_00892890` | `0x00892afc`, `0x00892b2d` | 0/1 pair | UI-like fraction then seconds |
| `FUN_00922270` | `0x009222e0` | push **1**, cat | zero-test |

**ECX host:** always map-owner path (LocalCast `ESI` caster; QB `DAT_00d1b6d8` + vtable this-adjust). **Not** skill object as map host.

---

## 8. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ABI `__thiscall` + 2 stack args + `RET 8` + float ST0 | **Confirmed** | three epilogues |
| Lookup by category id via map find | **Confirmed** | |
| Entry **+0x10 start / +0x14 duration** | **Confirmed** | bytes + Insert dual |
| `deadline = start + duration`; active iff `now < deadline` | **Confirmed** | unsigned cmp |
| Clock = **`g_dwClientTickMs` @ `0x00b041cc`** | **Confirmed** | closes prior Medium gap |
| Expired → erase via `FUN_004188e0` → 0 | **Confirmed** | side effect on query |
| Miss → 0 without erase | **Confirmed** | |
| `bAsSeconds≠0` → seconds (`* 0.001`) | **Confirmed** | closes float-scale gap |
| `bAsSeconds==0` → **fraction** remaining/duration | **Confirmed** | plate “ms” **falsified** |
| `skill+0x5e8` is category key at call sites | **Confirmed** | all sampled callers |
| Map owner ECX, map @ +0x6c | **Confirmed** | GetMap dual + this unit |
| Find/erase product names | **Open** | roles sealed |
| duration==0 fraction path | **Open** | `fidiv` edge (inf/NaN) |
| Runtime / bit-exact image | **Open** | matrix deferred |

---

## 9. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Map get → find → hit test | Yes (asm) |
| Deadline math + clock | Yes (asm) |
| Erase expired | Yes |
| Dual return scale | Yes (asm) — **not** in scaffold clean/raw decompile |
| No invented insert | Yes |

Scaffold `reconstructed-exact/Skill_GetCategoryCooldownRemaining.cpp` and raw capture still embed **broken float decompiler** output; treat as non-authoritative until rewritten from this dual.

---

## 10. Gaps / open

1. Product names for **`FUN_00418b80`** / **`FUN_004188e0`** (find / erase) — shared tree helpers.
2. **`duration == 0`** on fraction path (`fidiv`) — undefined x87 edge; no caller guard seen in this unit.
3. Whether erase-on-read races multi-consumer UI in same frame (client assumed single-threaded).
4. Server authority for true CD — out of client unit scope (B).
5. Optional: rewrite clean/raw from sealed CF (this dual).

**Verdict:** **accept** — ABI, CF, clock, return modes, and node field consumers sealed. Residual names/edges are non-blocking for AutoCore client UX + LocalCast code 7.
