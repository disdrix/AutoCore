# Review A (reconstruction fidelity): `aa_004c41c0` Creature_GetPerception

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c41c0` |
| **VA** | `0x004c41c0`–`0x004c428e` |
| **Canonical name** | `Creature_GetPerception` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (Perception stat getter + MI thr) |
| **Counterpart** | `reviews/B_aa_004c41c0_Creature_GetPerception.md` |
| **System** | `skills-abilities` / character stats |
| **Verdict** | **accept-with-gaps** — ABI/CF/clamp/thr/product string sealed; per-field English + vtbl product name open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers. No `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

Creature **Perception** stat reader:

```
score = min(min(int16(this+0x142), 200) + int16(this+0x14a), 250)
thr   = (MI_vtbl(+0x1DC) != 0) ? 1 : -100
return max(score, thr)   // if (thr < score) score; else thr
```

Used as:

1. **UI / requirements** — `FUN_00845360` formats `"Perception"` and compares player Perception vs requirement short `@+0xee`.
2. **Req gate** — `FUN_00514390` and related skill/item gates.
3. **Debug dump** — `Client_DebugDumpEntityCombatStats` packs as **P** in `(C:%d Th:%d Te:%d P:%d)`.
4. **Combat residual** — called from `Skill_NonCreatureCastAutoHit` (return may be discarded in high pcode — residual on that unit).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c41c0_Creature_GetPerception.md` (+ scaffold FUN plate) |
| Annotated | `docs/reconstruction/raw/aa_004c41c0_Creature_GetPerception.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Creature_GetPerception.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c41c0_Creature_GetPerception.md` |
| Live decompile | `decompile_function` `0x004c41c0` ≡ raw |
| Live bytes | `read_memory` @ entry + thr tail (`0x004c4260`) |
| Callers | 12 xrefs (complete analysis) |
| Sibling context (not owned) | `FUN_004c4070` Combat, `FUN_004c4140` Theory |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__fastcall`** decompiler; bytes use **`ECX`** as object (`56 8B F1`) — MSVC **thiscall** compatible |
| Stack args | **none** — plain **`RET`** (`C3`) |
| Return | **`int` in EAX** |
| Body | `0x004c41c0`–`0x004c428e` |
| Static callees | **none**; **indirect** `call [edx+0x1DC]` present |

```c
int __fastcall Creature_GetPerception(void *creature);
```

### 3.2 Control flow — **SEALED**

```
base  = int16(creature + 0x142)
bonus = int16(creature + 0x14a)
score = min(min(base, 200) + bonus, 250)
probe = MI_vtbl(+0x1DC)()
thr   = (probe != 0) ? 1 : -100
if thr < score: return score   // recompute on path
else:           return thr     // second probe call
```

**Algebraic equivalent:** `max(min(min(base,200)+bonus,250), thr)`.

Live decompile **≡** 2026-07-23 raw (no CF delta). Shape matches Combat sibling (W17-O sealed thr encode).

### 3.3 Constants — **SEALED** (immediate, no DAT_*)

| Value | Hex | Role |
|---|---|---|
| 200 | `0xC8` | max base short before add |
| 250 | `0xFA` | max total score |
| 199 | `0xC7` | compare threshold (`199 < base` → cap) |
| 0x65 | 101 | thr encode mask |
| -100 | `0x9C` as add | thr offset → 1 or -100 |
| 0x1DC | 476 | vtbl slot |

### 3.4 Product name Perception — **High**

From `FUN_00845360` (caller, context only):

```
sVar6 = FUN_004c41c0();
… FUN_007a6de0("Perception", -1);
sprintf(..., "\n%i %s", req, PerceptionName);
// red text if sVar6 < requirement
```

Parallel siblings: `"Combat"` ↔ `004c4070`, `"Theory"` ↔ `004c4140`.

### 3.5 Offsets — **High**

| Off | Width | Role |
|---|---|---|
| `+0x142` | int16 | Perception base (capped at 200 before add) |
| `+0x14a` | int16 | Perception additive |

Sibling offset pattern: Combat `+0x13e/+0x146`, Theory `+0x140/+0x148`, Perception `+0x142/+0x14a` (adjacent short pairs).

### 3.6 thr encode — **High** (same as Combat)

```
neg; sbb; and 0x65; add -100  →  1 if probe≠0 else -100
```

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| ABI / ECX / plain RET | **High** | entry bytes |
| CF / clamp / max thr | **High** | decompile + imm RETs |
| Name Perception | **High** | UI string |
| thr vtbl+0x1DC | **High** for encode; **Probable** vehicle English |
| Base vs bonus field English | **Probable** | structural |
| Discarded return at cast auto-hit | **Open** | residual on parent unit |

---

## 5. Open questions

1. Product DB / net field names for `+0x142` / `+0x14a`.
2. Exact product identity of `vtbl+0x1DC` probe (vehicle seat / MI flag).
3. Runtime capture of Perception dump vs this formula.
4. Whether thr=-100 path is live for unmodified characters.

**Verdict:** **accept-with-gaps** — CF/ABI/name sealed; residual is layout English + probe product name.
