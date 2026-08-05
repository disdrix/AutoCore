# Review A (reconstruction fidelity): `aa_005502d0` Skill_SetIsCastingFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_005502d0` |
| **VA** | `0x005502d0` |
| **Canonical name** | `Skill_SetIsCastingFlag` |
| **Review date** | `2026-07-29` (dual residual seal; prior 2026-07-23 **accept**) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005502d0_Skill_SetIsCastingFlag.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** |
| **Scratch** | `reviews/a_005502d0.md` |

---

## 1. Purpose

Tiny skill-runtime mutator: write **is-casting flag** at **`skill+0x628`**. When setting **true**, also clear **`skill+0x170`** to **0.0f** and stamp **`skill+0x178 = g_dwClientTickMs`**. Used by cast-again HB OnStart/OnEnd and bulk clear-walk. Not validation, not network, not the full cast state machine.

```
skill+0x628 = (uint8_t)bIsCasting
if bIsCasting:
  skill+0x170 = 0.0f          // movss
  skill+0x178 = g_dwClientTickMs
// false: flag only — leaves +0x170 / +0x178 untouched
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005502d0_Skill_SetIsCastingFlag.md` |
| Annotated | `raw/aa_005502d0_Skill_SetIsCastingFlag.annotated.md` |
| Clean | `reconstructed-exact/Skill_SetIsCastingFlag.cpp` |
| Function record | `functions/aa_005502d0_Skill_SetIsCastingFlag.md` |
| Ghidra re-decompile | `0x005502d0` (2026-07-29) |
| Bytes | `read_memory` body `0x005502d0`; sites `0x0051e390`, `0x0051e3b0`, `0x0052c820` |
| Xrefs | `get_function_xrefs` → 3 CALL |
| Sibling dual residual | OnStart `aa_0051e390`, OnEnd `aa_0051e3b0` |
| Residual scratch | `reviews/a_005502d0.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = skill; **one** stack `char`; **`RET 4`** | **High** | body |
| **`skill+0x628` byte** is-casting flag | **High** | `mov [ecx+0x628],al` |
| True → `+0x170` **float 0** (`movss`) | **High** | `xorps`+`movss` |
| True → `+0x178` = `g_dwClientTickMs` (`0x00b041cc`) | **High** | load/store |
| False → **no** clear of `+0x170`/`+0x178` | **High** | `je` skip (prior open **closed**) |
| Callers: OnStart(**1**), OnEnd(**0**), FUN_0052c780(**0**) | **High** | xrefs + site bytes |
| Decomp 3-arg / `void*` flag / `unaff_SI` | **Falsified** | |
| LocalCastValidate / QB gate on `+0x628` | **High** | consumer CF |
| Product English field names | **Open** | numeric sealed |
| Runtime / bit-exact | **Open** | matrix policy |

---

## 4. Control flow: clean ≡ raw ≡ asm

| Stage | Match |
|---|---|
| Store flag → optional true side effects → RET 4 | **Yes** |
| False path leaves tick | **Yes** |
| No invented net / validation | **Yes** |

---

## 5. Asm-sealed signature

```c
void __thiscall Skill_SetIsCastingFlag(void* thisSkill /* ECX */, char bIsCasting /* stack */);
// RET 4
// *(uint8_t*)(thisSkill+0x628) = bIsCasting;
// if (bIsCasting) { *(float*)(thisSkill+0x170)=0.f; *(uint32_t*)(thisSkill+0x178)=g_dwClientTickMs; }
```

### Sealed field: `skill+0x628`

| Item | Value |
|---|---|
| Offset | `0x628` |
| Width | **1 byte** (`uint8_t` / `char`) |
| Role | Client **is-casting** / cast-active flag |
| Writers (this mutator) | OnStart→1; OnEnd→0; FUN_0052c780 walk→0 |
| Other writers | init/template clear to 0 (sibling units) |
| Readers | LocalCastValidate (busy→7); QB cooldown gauge/overlay charge path |

---

## 6. Gaps / open

1. Product / PDB English for `+0x628` / `+0x170` / `+0x178`.
2. Full product identity of `FUN_0052c780` (clear-walk sealed).
3. Semantic use of `+0x170` beyond zero-on-cast-start (other modules).
4. Runtime / bit-exact / image diff.

**Verdict:** **accept**
