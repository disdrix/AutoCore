# Annotated low-level: CVOGCharacter_SearchAutoMissions (`aa_00532b60`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_00532b60` |
| **VA** | `0x00532b60` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_00532b60_CVOGCharacter_SearchAutoMissions.md` (capture 2026-07-23) |
| **Annotation pass** | 2026-07-29 dual residual pass 2 (multi-grant + table getter + local gate) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// Entry: character* in ECX; body MOV EBP,ECX @ 0x00532b78
void CVOGCharacter_SearchAutoMissions(CVOGCharacter* this);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` | 32-bit pointer | unsigned | `ECX` → `EBP` | Character |
| return | void | — | — | — |

**Convention note:** Ghidra labeled `__fastcall` and used `this[0x150]` / `this[0x14e]` as **dword indices** → byte offsets `0x540` and `0x538`. Prefer thiscall + byte offsets in clean source.

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `int *this` + `this[0x150]` | `*(this + 0x540)` active mission hash | **High** (live `MOV EAX,[EBP+0x540]`) |
| `this[0x14e]` | `*(this + 0x538)` completed hash | **High** (live `MOV EAX,[EBP+0x538]`) |
| `FUN_0053fff0()` no arg | `ECX = DAT_00b041fc`; returns **wrapper** `@owner+0xf18` (lazy); hash = `*wrapper`; null early-out | **High** |
| Hash lock byte `+0x1d` | Traversal lock; error strings if misused | **High** |
| Hash walk `+0x14` / node `+8` | Standard CNDHash bucket/chain iteration | **High** |
| `(short)this_00[0x3e] != 0` | **`u16` at byte `def+0xF8`** (`0x3e*4`); candidate when != 0 | **High** (live `CMP word [ESI+0xF8],0`) |
| `CheckMissionRequirements(this_00, this, unaff_ESI)` | **`ECX=def`, stack0=`character` only** — no third arg | **High** (live `PUSH EBP; MOV ECX,ESI; CALL`) |
| `unaff_ESI` residual | **Falsified** as formal — ESI **is** mission def | **High** |
| `GiveMission(*this_00)` free-looking | **`ECX=character`, stack=`*def`** | **High** (live framing) |
| Requirements return polarity | **0 = pass / grant**; nonzero skip | **High** (`TEST/JNZ`) |

---

## 3. Hash traversal pattern (shared)

```text
lock byte at hash+0x1d = 1
cursor = 0
loop:
  if cursor == 0: cursor = *(hash+0x14) else cursor = *(cursor+0x14)
  if cursor == 0: unlock; return
  entry = *(cursor+8)   // mission def*
  ... process entry ...
unlock hash+0x1d = 0
```

Widths: all pointers **u32**; lock **u8**.

---

## 4. Control flow per candidate

```text
if u16(def+0xF8) == 0: continue          // not auto

// skip if active: walk character+0x540 for key *def (payload +0x8 != 0)
// skip if completed: walk character+0x538 for key *def

if CheckMissionRequirements(def, character) == 0:
  GiveMission(character, missionId)   // return ignored
// always continue to next node (multi-grant) — asm JMP LAB_00532c00
```

| Branch | Condition | Effect |
|---|---|---|
| No def table | `FUN_0053fff0` wrapper null | Early return after scope pop |
| Not auto-eligible | `u16@+0xF8 == 0` | Skip |
| Already active/completed | hash hit with payload | Skip (`goto` next) |
| Requirements fail | `!= 0` | Skip |
| Requirements pass | `== 0` | `CVOGReaction_GiveMission` then **continue scan** |

### 4.1 Field relationship (GiveMission toast)

| Unit | Condition on `u16(def+0xF8)` | Effect |
|---|---|---|
| SearchAutoMissions | **!= 0** | Candidate for auto-grant |
| GiveMission | **== 0** | Show "Received Mission" toast + audio |

Same field, opposite sense. English retail name open; CF relationship **High**.

---

## 5. Side-effect order

1. Debug scope push `FUN_00786a00("CVOGCharacter::SearchAutoMissions")`.
2. Lock mission-def hash; iterate all auto candidates.
3. For each pass: **full GiveMission** side effects (hashes, optional toast **not** for auto flag, etc.).
4. Unlock; `FUN_00786990` scope pop.

Read-only on completed/active hashes during skip checks. **No** `+0x53c` instance-completed walk in this body.

---

## 6. Callers (xref seal 2026-07-29 residual-2)

| Caller | Site | Gate | After |
|---|---|---|---|
| `CVOGCharacter_LevelUp` | `0x0053303a` | `*(*( *(this+4)+4 ) + this + 0xa8 ) + 0x7e` | epilogue |
| `CVOGCharacter_LevelDown` | `0x00533213` | same | ret |
| `CVOGReaction_CompleteObjective` | `0x00534851` | same | `OR [char+0x634], 0x10` |
| `FUN_00533220` (level-set/stat-recalc) | `0x00533586` | same | vehicle pool path |

Hash probe (active/completed): mask `hash+0x8`, buckets `+0x10`, node key `+0x10` / payload `+0x8` / next `+0xc`.

---

## 7. Open questions

- Retail English name for def `+0xF8`.
- Product names: `FUN_0053fff0`, profile enter/leave, `FUN_00533220`, `DAT_00b041fc` owner.
- Product type of relative `+0xa8` object (only `+0x7e` used).
- Whether non-xref schedules exist (login/zone).
- Runtime multi-grant capture; bit-exact / differential.
