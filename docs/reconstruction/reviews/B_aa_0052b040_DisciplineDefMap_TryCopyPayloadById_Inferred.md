# Review B (skeptical / adversarial): `aa_0052b040` DisciplineDefMap_TryCopyPayloadById_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b040` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R12-020 OWN-ONLY dual B; dual start 2646) |
| **Counterpart** | `reviews/A_aa_0052b040_DisciplineDefMap_TryCopyPayloadById_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Identity is `Named_VOG_DEBUG_STOP_*` / VOG stub | Scaffold alias | **Falsified** — no debug strings; pure find+copy leaf |
| 2 | Is `SkillDefMap_ExactFindByIntKey` / SkillDef materialize | Same “skill table” intuition | **Falsified** — SkillDefMap uses `DAT_00b04734`, nil `+0x641`, ~`0x630` payload; this uses `0x00b045b0` / nil `+0x20d` / `0x1FC` copy |
| 3 | Is `CVOGCharacter_GetResourceBalanceByType` | Paired at parent | **Falsified** — that is thiscall on `character+0x584` returning int balance; this is cdecl global-map copy returning bool |
| 4 | thiscall / ECX=character / ECX=map as formal | Decompiler `undefined FUN…(void)` noise | **Falsified** — entry has no `MOV reg,ECX` this capture; map loaded by immediate; call sites push 2 args + `ADD ESP,8` |
| 5 | stdcall `RET 8` | Two formals | **Falsified** — bare `RET` both exits; cleanup at callers |
| 6 | Always copies / never fails | Optimistic | **Falsified** — miss path `XOR AL,AL` before any `MOVSD` |
| 7 | Copies whole node including links/nil | Size guess | **Falsified** — source is `node+0x10` only; 0x7f dwords; nil at `+0x20d` not in copy window end math (copy ends at `+0x20c`) |
| 8 | Inserts / mutates map | “Lookup” overclaim | **Falsified** — read-only find + out-buffer write only |
| 9 | Lower-bound open (may return wrong key) | Helper name | **Falsified for API contract** — `FUN_00538ab0` applies exact gate (`cand!=end && !(search < cand.key)` ⇒ equality); leaf trusts helper |
| 10 | Runtime Confirmed | Wave seal claim | **Fails (open)** — no Launcher; dual CF seal only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| cdecl + bool AL | **High** | Wrong cleanup / wrong return width in ports |
| Map/end addresses | **High** | Lookup wrong table |
| 0x1FC copy contract | **High** | Buffer underrun / partial def |
| Discipline domain (not SkillDef) | **High** | Merge with SkillDefMap ports incorrectly |
| Product English name | **Low–Med** | Doc only (`_Inferred`) |
| Full field schema | **Low** | Only name `@+0x2A` consumer-sealed |
| Runtime | **Open** | Not claimed |

---

## 3. Cross-check against raw ≡ live

```text
// sealed CF
it = FUN_00538ab0(&g_map_00b045b0, &key)
if (*it == DAT_00b045b4) return false;   // AL=0
memcpy(out, (*it)+0x10, 0x1FC);          // REP MOVSD x 0x7f
return true;                             // AL=1
// bare RET; __cdecl
```

Sibling contrast (evidence only; not OWN dual):

* `SkillDefMap_ExactFindByIntKey` (`0x00418890`): returns node**; map `DAT_00b04734`; nil `+0x641`.
* `SkillDefMap_GetGlobal` (`0x0054b480`): returns `&DAT_00b04734`.
* `CVOGCharacter_GetResourceBalanceByType` (`0x0052ada0`): `RET 4`; balance int; char map `+0x584`.
* Parent `FUN_00846820`: `"Discipline: "` string + `operator_new(0x1fc)` sizes the out buffer exactly.

Bytes seal (`read_memory`):

```text
51 8D 44 24 08 50 8D 4C 24 04 51 B9 B0 45 B0 00 E8 … 3B 05 B4 45 B0 00 75 04 32 C0 59 C3
… 8D 70 10 B9 7F 00 00 00 F3 A5 … B0 01 … C3 CC…
PUSH local; LEA &key; LEA &outIt; MOV ECX,map; CALL find; CMP end; XOR AL / REP MOVSD / MOV AL,1; RET; INT3 pad
```

---

## 4. Surviving contract for AutoCore

```
DisciplineDefMap_TryCopyPayloadById_Inferred(id, out0x1FC):
  node = exact_find(g_DisciplineDefMap @ 0x00b045b0, id)   // via FUN_00538ab0
  if node == end (DAT_00b045b4):
      return false
  memcpy(out0x1FC, node+0x10, 0x1FC)
  return true
```

**Port tests:**

* Unknown id → false; out buffer untouched (or undefined — do not require zeroing).
* Known id → true; 0x1FC bytes match node payload; name consumer may read `out+0x2A`.
* Caller must free heap outs (`operator_new(0x1fc)` pattern).
* Do **not** route through SkillDefMap globals.
* Do **not** use thiscall/RET-4/RET-8 on this leaf.

**Verdict:** **accept-with-gaps** — adversarial SkillDef-merge / thiscall / always-copy / VOG-stub / Runtime Confirmed claims **falsified**. Product English + full schema + runtime remain open (terminal **false**).
