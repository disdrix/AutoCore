# Review A (reconstruction fidelity): `aa_00539810` StdVector_Dword_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00539810` |
| **VA** | `0x00539810` |
| **Canonical name** | `StdVector_Dword_InsertN_Inferred` |
| **Prior scaffold** | `FUN_00539810` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00539810_StdVector_Dword_InsertN_Inferred.md` |
| **System** | containers / missions-progression (LevelUp push_back grow) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style **`std::vector<uint32_t|pointer>` insert-N** (`thiscall` vector host).

Layout (High from `>> 2` / `* 4`):

| Offset | Field |
|---|---|
| `+0x04` | begin |
| `+0x08` | end |
| `+0x0c` | capacity_end |

Control flow (live decompile ≡ raw):

1. Snapshot capacity count; **deref** `*param_4` once into local fill value.
2. **No-op** when `count (param_3) == 0`.
3. If `size + count` exceeds max (`0x3fffffff` guard) → `FUN_00537590()` length-error path.
4. **Realloc** when `capacity < size + count`: grow `cap + (cap>>1)` (or force-fit), `operator_new(n*4)`, `memmove` prefix, fill N via `FUN_004e2f70`, `memmove` suffix, `operator_delete` old, rewrite begin/end/cap.
5. **In-place** when capacity suffices: shift tail (`FUN_004e2e80` / `FUN_004e24d0`) + fill hole (`FUN_004e2f70` / `FUN_005739b0`).

**Known caller:** sole `StdVector_PushBackDword_Inferred` (`0x0053a820`) with `count=1` on LevelUp residual vector. Body is generic insert-N (twin shape of `StdVector_U32_InsertN_Inferred` @ `0x004e39d0`).

**Not** XP formula, not floater 0x38 vector, not map rebalance.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x00539810` (full body) |
| Callers | `get_function_callers` → `FUN_0053a820` only |
| Parent dual | `A_aa_0053a820_StdVector_PushBackDword_Inferred` |
| Twin dual | `A_aa_004e39d0_StdVector_U32_InsertN_Inferred` |
| Raw / clean | `aa_00539810_*` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = vector host
void __thiscall StdVector_Dword_InsertN_Inferred(
    void *vec,        // this: begin@+4 end@+8 cap@+0xC
    void *insert_at,  // param_2
    unsigned count,   // param_3
    uint32_t *value); // param_4 — *value captured once
```

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Element size **4** | **Confirmed** | `>> 2`, `* 4`, `new(count*4)` |
| Layout +4/+8/+0xC | **Confirmed** | body |
| n==0 early exit | **Confirmed** | outer `if (param_3 != 0)` |
| Geometric grow + force-fit | **Confirmed** | `uVar2 + (uVar2>>1)` |
| Realloc memmove + fill + delete | **Confirmed** | body |
| In-place shift branches | **Confirmed** | two arms after capacity check |
| Sole push_back caller today | **High** | callers list |
| Product name | **Open** | INFERRED |
| Exact throw helper `FUN_00537590` semantics | **Probable** | length_error twin |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Capacity/size dword math | Yes |
| Realloc vs in-place split | Yes |
| Fill via shared dword helpers | Yes |
| Ghidra noreturn after `operator_delete` | Artifact only — CF still realloc complete |

---

## 6. Gaps / open

1. Product / RTTI name.
2. Whether other call sites exist via indirect or unlisted xrefs.
3. LevelUp vector element meaning (id token) — parent dual.

**Verdict:** **accept-with-gaps**
