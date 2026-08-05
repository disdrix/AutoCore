# Review A (reconstruction fidelity): `aa_00402ea0` CombatFloater_UninitializedFillN_0x38_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402ea0` |
| **VA** | `0x00402ea0` |
| **Canonical name** | `CombatFloater_UninitializedFillN_0x38_Inferred` |
| **Prior scaffold** | `FUN_00402ea0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00402ea0_CombatFloater_UninitializedFillN_0x38_Inferred.md` |
| **System** | `missions-progression` / combat floater UI |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

**Fill-N / uninitialized_fill_n** for combat-floater POD (**0x38**):

1. Call `CombatFloater_ConstructN_0x38` (`FUN_00404600`) with dest / count / template payload.
2. Return **`dst + count * 0x38`** (end of just-constructed range).

Sole caller: `CombatFloaterVector_InsertN_0x38_Inferred` (`0x00403680`) when constructing N template copies into a hole (realloc or in-place insert). Distinct from range relocate (`0x004044c0`) and assign-over-range (`0x004044e0`).

ABI: **`ret 0x0C`** (3 stack args); ECX thiscall noise on formals is decompiler artifact for a free helper.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00402ea0` |
| Bytes | `read_memory` 48 B — `lea`/`imul`-style end = `dst + n*0x38`, `C2 0C 00` |
| Callers | only `FUN_00403680` |
| Callee dual | `A_aa_00404600_CombatFloater_ConstructN_0x38_Inferred` |
| Raw / clean | `aa_00402ea0_*` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Calls `FUN_00404600` then returns end | **Confirmed** | raw ≡ live |
| End = `param_2 + param_3 * 0x38` | **Confirmed** | decompile + bytes `8D 04 D7` pattern |
| Stride **0x38** | **Confirmed** | return arithmetic |
| ConstructN = loop PodCopy | **High** | sealed callee dual |
| Used as insert fill-n | **High** | sole parent insert |
| Product name | **Open** | INFERRED |

---

## 4. Control flow: clean ≡ raw ≡ live

```c
// int FillN(dst, count, template)  — formals per raw labels
CombatFloater_ConstructN_0x38(dst, count, template);
return dst + count * 0x38;
```

| Stage | Match |
|---|---|
| Single construct-N call | Yes |
| Return advanced pointer | Yes |
| No grow / no free | Yes |

---

## 5. Gaps / open

1. Exact stack formal names at call sites (parent dual owns insert ABI).
2. Product symbol.

**Verdict:** **accept**
