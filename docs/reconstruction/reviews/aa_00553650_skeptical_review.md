# Skeptical / adversarial review: `Skill_ValidateTargetForSkill` @ `0x00553650`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00553650` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Target validation unit, return polarity, naming |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_00553650_Skill_ValidateTargetForSkill.md` | Body |
| `raw/aa_00553650_Skill_ValidateTargetForSkill.annotated.md` | Plate |
| `reconstructed-exact/Skill_ValidateTargetForSkill.cpp` | Clean |
| `functions/aa_00553650_Skill_ValidateTargetForSkill.md` | Record |
| `systems/skills-abilities.md` | Role “Target legality” |
| `docs/topic-extractions/skill-cast.md` | Name map entry only |

**Not performed:** caller xrefs, handler decompile at vtable+0x44, runtime.

---

## 2. Evidence used

### Authoritative body (complete)

```c
iVar1 = (**(this+0x5f0)+0x44)(pSkill, this);
if (iVar1 != 1) {
  pvStack_18 = pSkill;
  FUN_004e2600(&LAB_005532e0, &pvStack_18, 0);
  return CONCAT31(..., 1);  // low byte 1
}
return 0;
```

Mechanical facts:

1. Single virtual call; no range math; no TFID compare in-body.
2. `pTarget` is never read.
3. Feedback path only when handler `!= 1`.
4. Function returns `0` iff handler returned `1`.

---

## 3. Attack results

### Claim 1 — Returns 1 if valid, 0 if rejected (plate)

| Sub-claim | Attack result |
|-----------|----------------|
| Plate text | **FALSIFIED by body** if handler `1` means valid |
| Alternate: handler `1` means invalid | Then plate could match function return — but feedback on `!= 1` makes “invalid → feedback → return 1” the natural reading, implying function `1` = failure/feedback path |
| LocalCastValidate-style `0=ok` | **Consistent with body** if this function also uses `0=ok` |

**Best adversarial reading:** plate is **wrong**; function returns **0 on handler success (1)**, **1 on handler failure path**.

---

### Claim 2 — Validates “target for skill”

| Sub-claim | Attack result |
|-----------|----------------|
| Name implies target object checked | **BROKEN.** `pTarget` unused |
| Handler receives target | **BROKEN.** Args are `(pSkill, this)` only |
| Could still validate if `this` is target | **Possible** — then first formal `pSkill` is skill and `this` is target (thiscall on target). Or `this` is skill and `pSkill` misnamed. **Unselected** |

Without callers + handler, “target legality” is a **label**, not a proof.

---

### Claim 3 — On reject, queues UI/feedback

| Sub-claim | Attack result |
|-----------|----------------|
| `FUN_004e2600` called on handler `!= 1` | **Holds** |
| It is UI/feedback | **Probable at best** — name/LAB not sealed |
| Always user-visible error | **Unproven** |

---

### Claim 4 — System-critical target gate on cast path

| Sub-claim | Attack result |
|-----------|----------------|
| Listed in skills-abilities entry table | Yes |
| Appears on RequestCast / QuickBar activate paths | **Not in those decompiles** — they use LocalCastValidate + ResolveCastTarget, not this function |
| Importance | May be used from other cast pipelines (NPC, ground target UI, item skills) — **not shown here** |

---

### Claim 5 — Small unit is fully understood

| Sub-claim | Attack result |
|-----------|----------------|
| CF shape simple | **Holds** |
| Semantics sealed | **Fails** — polarity + object roles open |

---

## 4. Alternate interpretations

| Story | Fits CF? |
|-------|----------|
| `this`=skill, formal0=target misnamed, handler on skill strategy | Partial (args order is formal0, this) |
| `this`=target, formal0=skill, handler on target’s skill component at +0x5f0 | Fits thiscall style |
| Return 0=ok matching rest of skill stack | Fits body if handler 1=ok |
| Return 1=ok matching plate | Requires handler 1=bad and feedback on success — **awkward** |

---

## 5. What was confirmed despite skepticism

1. Exact CF: one virtual call, two returns.
2. Feedback only on handler `!= 1`.
3. `pTarget` dead.
4. Clean faithful to body (not plate).
5. No range/TFID math in unit.

---

## 6. Critical contradictions found

### C1 — Plate polarity vs body

Direct contradiction. Any port following the plate without reading the body will invert accept/reject.

### C2 — Name “ValidateTarget” vs unused target formal

Naming package is overconfident.

### C3 — System map role vs missing cast-path callers in this batch

May still be important elsewhere; cannot claim it is *the* player cast target check.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | Return polarity meaning | **Yes** |
| R2 | Identity of `this` / formals | **Yes** |
| R3 | Handler method | Yes |
| R4 | Callers | Yes |
| R5 | Feedback function role | Mild |

---

## 8. Concrete checks performed

1. Line-by-line body re-derivation.
2. Confirmed `pTarget` has zero reads.
3. Compared plate sentence to both return paths.
4. Grepped batch cast senders for this symbol — not used in RequestCast/QB activate bodies.
5. Clean vs raw parity.

---

## 9. Verdict

### **`needs-more-evidence`**

Tiny CF is solid; **semantic package is not**. Plate is actively dangerous.

### Port guidance

- Prefer body polarity: treat return `0` as the handler-success path until callers prove otherwise.
- Do not trust formal name `pTarget`.
- Demote system-map wording from “target legality” to “vtable+0x44 gate (roles TBD).”

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Plate 1=valid | **Falsified** (vs natural reading) |
| 2 | Validates target object | **Unproven / name fails** |
| 3 | Feedback on reject path | **CF holds; UI role soft** |
| 4 | On player cast path | **Not shown** |
| 5 | Fully understood | **Fails** |

**Final verdict: `needs-more-evidence`**
