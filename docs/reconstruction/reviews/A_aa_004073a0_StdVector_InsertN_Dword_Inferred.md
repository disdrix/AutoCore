# Review A (reconstruction fidelity): `aa_004073a0` StdVector_InsertN_Dword_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004073a0` |
| **VA** | `0x004073a0` |
| **Canonical name** | `StdVector_InsertN_Dword_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004073a0_StdVector_InsertN_Dword_Inferred.md` |
| **System** | util / container (generic) |
| **Verdict** | **accept-with-gaps** under `_Inferred` product method name |

---

## 1. Purpose

MSVC-style `std::vector<T>` **insert-n** for **4-byte** elements. Inserts `count` copies of `*value` at iterator `pos`, growing capacity when needed (1.5× growth with exact-fit floor). Generic infrastructure used by mission/skill/UI push paths via `FUN_0040dbf0` (insert-1 wrapper) and many direct multi-insert call sites. **Not** domain logic.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004073a0_FUN_004073a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004073a0_FUN_004073a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004073a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004073a0_FUN_004073a0.md` |
| Live decompile | Ghidra `batch_decompile` `0x004073a0` (2026-07-29) — **≡ raw body** |
| Image | `read_memory 0x004073a0` length `0x20` — standard SEH prolog |
| Wrapper | decompile `FUN_0040dbf0` `0x0040dbf0` → calls this with `count=1` |
| Callers | `get_function_callers` → **35+** functions (ApplyCreateFromPacket, EvaluatePendingObjectives, GatherTargetsInArea, combat damage, freelist/UI, …) |
| Prior art | FailMissionNotify dual (`aa_004149d0`) seals push → grow chain role |

**Not performed:** bulk disassembly, Launcher, runtime, Ghidra rename commit.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body ≡ raw ≡ live decompile | **High** | CF spine identical |
| `__thiscall` vector object | **High** | `param_1` = this; triad at `+4/+8/+0xc` |
| Triad: begin `+4` / end `+8` / cap-end `+0xc` | **High** | size/cap = `(ptr-begin)>>2` |
| Element stride **4** | **High** | all `>> 2` / `* 4` math |
| `param_2` = insert position (iterator, absolute ptr) | **High** | used as mid split for relocate |
| `param_3` = insert count | **High** | early-out if 0 |
| `param_4` = value source (`*param_4` copied into fills) | **High** | `local_18 = *param_4`; fill via `FUN_004e2f70` / `FUN_005739b0` |
| Growth: `cap + (cap>>1)` (1.5×), else exact `size+count` | **High** | body exact; max elem count `0x3fffffff` |
| Realloc path: `operator_new(n*4)` → copy prefix → fill n → copy suffix → delete old → update triad | **High** | decompile |
| In-place path when capacity remains (two sub-cases by distance-to-end) | **High** | |
| Overflow/abort via `FUN_00418130` when size would exceed max | **High** | |
| Product English (`_Insert_n` / MSVC mangling) | **Inferred** | no string/RTTI on VA |
| Element type always same domain | **Falsified** | multi-caller dword bag |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Load begin; cap = 0 if null else `(capEnd-begin)>>2` | Yes |
| If count==0 return | Yes |
| Max-size check → `FUN_00418130` | Yes |
| If need grow: 1.5× then min-fit; `operator_new`; three-way relocate; delete old; write triad | Yes |
| Else if insert near end: shift tail then fill | Yes |
| Else: shift-from-end path + fill | Yes |
| No domain / packet / mission logic | Yes |

### 4.1 Insert-1 wrapper (`FUN_0040dbf0`)

```
index = (pos-begin)>>2  (0 if empty)
FUN_004073a0(pos, 1, value)   // thiscall this=vec
*outIt = begin + index*4
```

Push-dword slow path (`aa_004149d0` / Vector_PushDword historical) → this wrapper → this unit.

---

## 5. Signature (decompiler-derived)

```c
void __thiscall StdVector_InsertN_Dword_Inferred(
    VectorDword *this,   // +4 begin, +8 end, +0xc capEnd
    uint32_t *pos,       // insert iterator (element*)
    uint count,
    uint32_t *value);    // *value replicated count times
```

---

## 6. Gaps / open

1. Exact MSVC demangled name (`std::vector<…>::_Insert_n` template args).
2. Full caller taxonomy (dozens; generic only).
3. Bit-exact / runtime / image diff.
4. Precise roles of relocate helpers `FUN_004e2e80` / `FUN_004e2f70` / `FUN_004e24d0` / `FUN_005739b0` (copy/fill family — sealed as such).

**Verdict:** **accept-with-gaps** — role + growth + triad sealed; keep `_Inferred` until demangled symbol.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw | **Pass** |
| Triad + stride 4 | **Pass** |
| 1.5× growth CF | **Pass** |
| Multi-caller generic (not mission-only) | **Pass** |
| Domain logic absent | **Pass** |
| Verdict | **accept-with-gaps** |
