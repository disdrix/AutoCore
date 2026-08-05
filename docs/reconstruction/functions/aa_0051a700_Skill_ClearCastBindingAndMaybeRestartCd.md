# Function record: Skill_ClearCastBindingAndMaybeRestartCd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a700` |
| **Canonical name** | `Skill_ClearCastBindingAndMaybeRestartCd` |
| **Address** | `0x0051a700` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__thiscall` — **`RET 0x14`** (5 stack dwords) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual A/B residual strengthen (2026-07-29)** — ABI/partial-TFID erase/restart polarity sealed; map owner + product bit names open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

---

## 1. Summary

Find active-cast binding by **skillId** (`FUN_00518c20` map @ `+0x68` + `FUN_0051c150`), erase with `FUN_0051cb40` only when node value matches **partial TFID** (`+0x18`, `+0x1c`, `byte(+0x20)`). Then resolve skill via **`owner.vtbl+0x234(skillId)`**; if non-null and **`skill+0x61c != 0`**, call `Skill_StartCastAgainHeartbeat(owner, skill, 0)`.

Mutating counterpart to read-only `Skill_LookupActiveCastBinding`. Distinct from `Skill_SiblingCastClear` (host HB list `+0xB0`).

---

## 2. Signature (asm-sealed 2026-07-29)

```c
void __thiscall Skill_ClearCastBindingAndMaybeRestartCd(
    void* pOwner,      // ECX
    int   nSkillId,    // stack0 — map key (node+0x10)
    uint32_t tfid0,    // stack1 — vs node+0x18
    uint32_t tfid1,    // stack2 — vs node+0x1c
    int   tfid2,       // stack3 — low byte vs node+0x20
    char  tfid3_pad);  // stack4 — not read in body
// RET 0x14
```

Ghidra plate/decomp formals `(this, pSkill, nSkillId, nTfidLo, nTfidHi, bGlobal)` are **misnamed**.

---

## 3. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.*` |
| Clean | `reconstructed-exact/Skill_ClearCastBindingAndMaybeRestartCd.cpp` |
| Dual A/B | `reviews/A_aa_0051a700_*`, `reviews/B_aa_0051a700_*` |
| Scratch | `reviews/a_0051a700.md` |
| Map getter | `aa_00518c20` FUN_00518c20 (leave-FUN) |
| Find | `aa_0051c150` Map_ExactFindByIntKey |
| Lookup sibling | `aa_00518cf0` Skill_LookupActiveCastBinding |
| StartCastAgain | `aa_00519200` (call site `0x0051a77c`) |
| Erase | `aa_0051cb40` FUN_0051cb40 |
| Known callers | `Skill_ApplyStatusEffectLocal`, `FUN_00578ce0` |

---

## 4. Confidence

| Dimension | Level |
|---|---|
| Control flow | **Confirmed** (PE body) |
| Asm ABI / `RET 0x14` | **Confirmed** |
| Partial TFID erase gate | **Confirmed** |
| Restart polarity `+0x61c != 0`, charge 0 | **Confirmed** |
| Map owner product type | **Open** |
| `+0x61c` / vtbl+0x234 product English | **Open** |
| Overall | **Human-refined; dual residual accept-with-gaps** |
