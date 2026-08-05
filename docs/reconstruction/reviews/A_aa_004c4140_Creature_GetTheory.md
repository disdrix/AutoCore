# Review A (reconstruction fidelity): `aa_004c4140` Creature_GetTheory

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c4140` |
| **VA** | `0x004c4140`–`0x004c41bb` |
| **Canonical name** | `Creature_GetTheory` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (Theory stat leaf getter) |
| **Counterpart** | `reviews/B_aa_004c4140_Creature_GetTheory.md` |
| **System** | `skills-abilities` / character stats |
| **Verdict** | **accept-with-gaps** — ABI/CF/clamp/product string sealed; per-field English + Combat/Perception asymmetry open |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + callers. No `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

Leaf **Theory** stat reader for a creature/object:

```
result = clamp(min(int16(this+0x140), 200) + int16(this+0x148), 1, 250)
```

Used as:

1. **UI / requirements** — `FUN_00845360` formats `"Theory"` and compares player Theory vs requirement short.
2. **Req gate** — `FUN_00514390` requires `Theory >= skill/item short@+0xf2`.
3. **Accuracy bonus** — `Skill_AccuracyScore_Inferred` (`0x005531d0`) casts return to `float` as attacker bonus into `Skill_NonCreatureCastAutoHit`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004c4140_Creature_GetTheory.md` (+ scaffold FUN plate) |
| Annotated | `docs/reconstruction/raw/aa_004c4140_Creature_GetTheory.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Creature_GetTheory.cpp` |
| Function record | `docs/reconstruction/functions/aa_004c4140_Creature_GetTheory.md` |
| Live decompile | `decompile_function` `0x004c4140` ≡ raw |
| Live bytes | `read_memory` 128 B @ entry (through dual RET tails + `CC`) |
| Callers | 10 xrefs (complete analysis) |
| Sibling context (not owned) | `FUN_004c4070` Combat, `FUN_004c41c0` Perception; parent `Skill_AccuracyScore_Inferred` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| Convention | **`__fastcall`** decompiler; bytes use **`ECX`** as object (`mov ax,[ecx+0x140]`) — MSVC **thiscall** compatible leaf |
| Stack args | **none** — plain **`RET`** (`C3`) |
| Return | **`int` in EAX** (1…250) |
| Body | `0x004c4140`–`0x004c41bb` |
| Classification | **leaf** (no callees) |

```c
int __fastcall Creature_GetTheory(void *creature);
```

### 3.2 Control flow — **SEALED**

```
base  = int16(creature + 0x140)
bonus = int16(creature + 0x148)
cap   = (199 < base) ? 200 : base      // min(base, 200) for signed short
sum   = cap + bonus
if sum < 250:
  if sum < 2: return 1
  return min(base, 200) + bonus        // same as sum
else:
  return 250
```

**Algebraic equivalent:** `clamp(min(base, 200) + bonus, 1, 250)`.

Live decompile **≡** 2026-07-23 raw (no CF delta). Decompiler repeats the base-cap expression; clean may keep that shape or the closed form — both match integer results.

### 3.3 Constants — **SEALED** (immediate, no DAT_*)

| Value | Hex | Role |
|---|---|---|
| 200 | `0xC8` | max base short before add |
| 250 | `0xFA` | max total return |
| 1 | `0x1` | min total return |
| 199 | `0xC7` | compare threshold (`199 < base` → cap) |

### 3.4 Product name Theory — **High**

From `FUN_00845360` (caller, context only):

```
sVar6 = FUN_004c4140();
… FUN_007a6de0("Theory", -1);
sprintf(..., "\n%i %s", req, TheoryName);
// red text if sVar6 < requirement
```

Parallel siblings: `"Combat"` ↔ `004c4070`, `"Perception"` ↔ `004c41c0`.

### 3.5 Offsets — **High**

| Off | Width | Role |
|---|---|---|
| `+0x140` | int16 | Theory base (capped at 200 before add) |
| `+0x148` | int16 | Theory additive (uncapped alone; sum clamped) |

Sibling offset pattern: Combat `+0x13e/+0x146`, Theory `+0x140/+0x148`, Perception `+0x142/+0x14a` (adjacent short pairs).

---

## 4. Confidence table

| Area | Confidence | Notes |
|---|---|---|
| ABI / leaf / ECX | **High** | entry bytes |
| CF / clamp | **High** | decompile + imm RETs |
| Name Theory | **High** | UI string |
| Accuracy uses this as float bonus | **High** | parent dual |
| Base vs bonus field English | **Probable** | structural |
| No vehicle floor intentional | **Open** | siblings differ |

---

## 5. Open questions

1. Product DB / net field names for `+0x140` / `+0x148`.
2. Why Combat/Perception apply vfunc `+0x1dc` vehicle floor and Theory does not.
3. Runtime capture of Theory dump vs this formula.
4. Whether negative bonus shorts appear in retail data.

**Verdict:** **accept-with-gaps** — small leaf fully sealed on CF/ABI/name; residual is layout English depth.
