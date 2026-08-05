# Review A (reconstruction fidelity): `aa_004e39d0` StdVector_U32_InsertN_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e39d0` |
| **VA** | `0x004e39d0` |
| **Canonical name (Ghidra)** | `FUN_004e39d0` |
| **Proposed name** | `StdVector_U32_InsertN_Inferred` (**High** role; product symbol absent) |
| **Prior scaffold alias** | `Named_CalleeOf_CVOGSectorMap_AddCharacter_004e39d0` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_004e39d0_StdVector_U32_InsertN_Inferred.md` |
| **System** | `containers` / `combat` (multi-hit temp vector) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**MSVC-style `std::vector<T>` insert-N for 4-byte elements** (`thiscall` vector host).

Layout (High from stride `>> 2` and `* 4` arithmetic):

| Offset | Field |
|---|---|
| `+0x04` | `begin` / data pointer |
| `+0x08` | `end` |
| `+0x0c` | `capacity_end` |

Control flow:

1. No-op when `count (param_3) == 0`.
2. If capacity cannot hold `size + count`, grow: preferred capacity `max(old + old/2, size+count)` capped vs `0x3fffffff`; on overflow path calls `FUN_004e1050` (length-error / throw helper — **Probable**).
3. Realloc path: `operator_new(newCap*4)`, `memmove` prefix before insert point, fill N copies via `FUN_004e2f70`, `memmove` suffix, `operator_delete` old buffer (Ghidra noreturn artifact after first free), rewrite begin/end/capacity.
4. In-place path: shift tail with `FUN_004e2e80` / `FUN_004e24d0` / `FUN_005739b0` fill helpers.

**Combat role:** sole multi-target hit path `Client_Combat_ApplyMultiTargetHits_Inferred` (`0x004da2e0`) grows a local `TFID*` success vector with this insert. Also used by sector map / clone load / list builders (`004d35c0`, `00541410`, …).

**Not** combat hit apply, not deferred queue enqueue, not invalid-subscript throw (`004e0eb0`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004e39d0` |
| Callers | `get_function_callers` → `004da2e0`, `004d35c0`, `00541410`, `004d4ff0`, `004d5110`, `004d5c10`, `004e4b10`, `004e54a0` |
| Parent dual | `A_aa_004da2e0_Client_Combat_ApplyMultiTargetHits_Inferred` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_004e39d0` |
| Function record | `docs/reconstruction/functions/aa_004e39d0_FUN_004e39d0.md` |

**This pass:** live decompile; callers. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = vector<uint32_t|pointer> host
void __thiscall StdVector_U32_InsertN_Inferred(
    void *vec,           // this — begin@+4 end@+8 cap@+0xC
    void *insert_at,     // param_2 — iterator into [begin,end]
    uint count,          // param_3 — number of 4-byte slots to insert
    undefined4 *value);  // param_4 — *value copied count times (deref once)
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_004e1050` | Capacity / length overflow path |
| `operator_new` / `operator_delete` | Buffer realloc |
| `memmove` | Prefix/suffix relocate |
| `FUN_004e2f70` | Fill N value copies at insert hole |
| `FUN_004e2e80` / `FUN_004e24d0` / `FUN_005739b0` | In-place shift/fill |

| Caller (sample) | Role |
|---|---|
| `0x004da2e0` | Multi-target hit success TFID* vector |
| `0x004d35c0` | `CVOGSectorMap_AddCharacter` |
| `0x00541410` | `CloneBase_LoadWadFile` |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Zero-count early return | Yes |
| Capacity check + 1.5× grow | Yes |
| Realloc + memmove + fill + free | Yes |
| In-place shift branches | Yes |
| Element stride 4 (`>>2` / `*4`) | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `vector<T>` insert-N, T size 4 | **High** | arithmetic |
| begin/end/cap @ +4/+8/+0xC | **High** | |
| Used by multi-target combat path | **High** | sole grow callee of `004da2e0` |
| `FUN_004e1050` = length_error throw | **Probable** | overflow gate only |
| Product STL symbol | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Exact MSVC STL version / mangled name.
2. Whether `T` is always pointer vs raw u32 at every caller.
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — container CF High; product name open.
