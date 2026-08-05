# Review B (skeptical / adversarial): `aa_00531b00` CVOGMission_AddActiveObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531b00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual tighten; prior `2026-07-23`) |
| **Counterpart** | `reviews/A_aa_00531b00_CVOGMission_AddActiveObjective.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present and strengthened** (A + B modern pair) |
| **Verdict** | **accept-with-gaps** on CF + hash targets + arity; residual on helper English / runtime |
| **Scratch** | `reviews/a_00531b00.md` |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Body stores to `param_1+0x548` | **Falsified as direct store** — no write; **survives as ECX load** before `FUN_0053c460` (asm `0x00531b0d`) |
| 2 | Plate “active objective hash +0x548” is overclaim | **Partially withdrawn** — target sealed via asm; store is inside helper |
| 3 | State node also goes to `+0x548` | **Falsified** — state insert uses **`+0x55c`** (pending) per asm `0x00531b6f` |
| 4 | Always dirty journal | **Falsified** — dirty only when evaluator vector non-empty |
| 5 | Always allocates state node | **Falsified** — empty evaluators skip alloc / pending insert / dirty |
| 6 | `operator_delete` aborts (Ghidra noreturn) | **Falsified** — asm falls through into evaluator loop + dirty |
| 7 | Safe recovery after insert fail | **Attacked** — freed `stateNode` still passed to vcalls (UAF parity) |
| 8 | Two-arg thiscall mismatches GiveMission | **Falsified** — GiveMission: `PUSH obj; MOV ECX,char; CALL`; same at CompleteObjective |
| 9 | First insert failure is checked | **Falsified** — `FUN_0053c460` return **ignored** |
| 10 | Null `operator_new` safe | **Hazard preserved** — `*node = def` after possible null |
| 11 | Name implies `this` is CVOGMission | **Ambiguous** — params are (character, objectiveDef); name is plate historical |
| 12 | Vtable `+0x28` = “notify UI listeners” | **Unproven** — only call shape sealed |

---

## 2. Decisive dataflow (raw + asm)

```
this (ECX) = character
  +0x548  → CNDHash* active objectives   // FUN_0053c460 this
  +0x55c  → CNDHash* pending objectives  // FUN_0053c760 this
  +0x634  dirty flags                    // |= 0x10 if evaluators

objectiveDef (stack)
  +0x10   objective id (hash key)
  +0x158  evaluator* begin
  +0x15c  evaluator* end
  count = (end - begin) >> 2

Always:
  hash_insert(+0x548, id, def, skipIfExists=0)   // return ignored

If evaluators non-empty:
  node = new 0x14; zero; node[0] = def
  rc = hash_insert(+0x55c, id, node, 0)
  if rc != 0: operator_delete(node)              // then FALL THROUGH
  for each eval: eval->vtbl[+0x28](character, node)
  char+0x634 |= 0x10
```

Helper twin bodies (`FUN_0053c460` / `FUN_0053c760`): null value → `0x80004003`; duplicate → log + `0x80004005`; success → `0`; distinct node vtable only.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Character `this` + objectiveDef stack arg | **High** | Wrong object / def binding |
| Def hash `+0x548` via helper | **High** | Objectives never appear active |
| Pending hash `+0x55c` for 0x14 node | **High** | Pending eval / RecvObjectiveState desync |
| Dirty only with evaluators | **High** | Missing journal refresh or false dirty |
| Vcall +0x28 setup loop | **High** CF | Evaluators not primed |
| Delete then continue | **High** | Wrong error model (abort vs UAF) |
| Helper English / full CNDHash API | **Tentative** | Wrong AutoCore type names |
| Vtable +0x28 method identity | **Tentative** | Wrong setup semantics |
| Dirty bit consumers | **Tentative** | UI/journal miss |
| Clean CF ≡ raw (+ restored this) | **High** | — |

---

## 4. Offset attack checklist (must stay body/asm-backed)

| Offset | Attack | Result |
|--------|--------|--------|
| `char+0x548` as def-insert this | Invented? | **No** — asm ECX load |
| `char+0x55c` as state-insert this | Invented? | **No** — asm ECX load |
| Direct `*(char+0x548) = …` in body | Present? | **No** |
| `def+0x10` key | Invented? | **No** |
| `def+0x158/+0x15c` evaluators | Invented? | **No** |
| Node size `0x14` | Invented? | **No** |
| `char+0x634 \|= 0x10` | Invented? | **No** |
| `char+0x540` mission hash | Used here? | **No** — GiveMission only |

---

## 5. Control flow: clean ≡ raw (skeptical)

| Stage | Clean invents? | Match |
|---|---|---|
| Always def insert | No (restores hash this) | **Yes** / **Accept correction** |
| Empty-eval early out | No | **Yes** |
| Alloc / zero / back-ptr | No | **Yes** |
| Pending insert + delete on fail | No (restores `+0x55c` this) | **Yes** / **Accept correction** |
| Fall-through after delete | No | **Yes** |
| Vcall loop + dirty | No | **Yes** |
| No invented +0x548 store | None | **Yes** |

---

## 6. Surviving contract for AutoCore

```
// Character thiscall — NOT mission-object thiscall
void AddActiveObjective(Character* ch /*ECX*/, ObjectiveDef* def);

// 1) Always register def in active-objectives hash (char+0x548), key=def.id
// 2) If def has evaluators:
//      alloc 0x14 runtime node (def back-ptr @ +0)
//      insert node into pending hash (char+0x55c)
//      on insert fail: free node, still run hooks (original UAF parity)
//      for each evaluator: vtbl+0x28(ch, node)
//      ch.dirty |= 0x10
// 3) void return; first insert HRESULT ignored
```

Do **not** invent a direct `+0x548` dword store. Do **not** treat empty-evaluator objectives as dirtying the journal. Do **not** assume insert-fail aborts activation.

---

## 7. Open questions

1. PDB/original names for insert helpers and node vtables.
2. Exact pending-node field map (slots vs RecvObjectiveState).
3. Evaluator `+0x28` method identity across objective types.
4. Dirty `0x10` reader set (journal / UI).
5. Live capture: grant path nodes at `+0x548` / `+0x55c` and dirty bit.
6. GiveMission clean one-arg declaration remains cross-unit residue.

---

## 8. Relation to prior reviews

| Review | Date | Verdict | Notes |
|--------|------|---------|-------|
| Legacy skeptical | 2026-07-23 | needs-more-evidence | +0x548 / arity / helpers open |
| Dual B thin | 2026-07-23 | accept-with-gaps CF; needs-more-evidence helpers | Correct attacks on direct store + always-dirty |
| **This dual B** | **2026-07-29** | **accept-with-gaps** | Asm closes +0x548/+0x55c, arity, noreturn; English/runtime open |

---

## 9. Verdict

### **accept-with-gaps**

**Why accept:** Core activate CF is faithful; former blockers (hash target, call arity, delete control flow) are **asm-sealed High**. Clean may restore helper `this` without inventing stores.

**Why not complete / bit-exact:** Helper names, vcall identity, dirty consumers, runtime/diff still open. Failed-insert UAF is original behavior, not a clean bug.

**Bar already cleared vs 2026-07-23 skeptical package:** decompile helpers + resolve GiveMission ABI + seal `+0x548` path — done (static). Remaining bar is runtime and English naming only.
