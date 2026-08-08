# Review A (reconstruction fidelity): `aa_00416e80` FreelistSlabVector_Teardown_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416e80` |
| **VA** | `0x00416e80` |
| **Body** | `0x00416e80`–`0x00416ef6` (**119 B** / `0x77`) |
| **Canonical name** | `FreelistSlabVector_Teardown_Inferred` |
| **Ghidra name** | `FUN_00416e80` |
| **Prior scaffold** | `FUN_00416e80` |
| **Review date** | `2026-08-05` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual **WQ9I-A**) |
| **Counterpart** | `reviews/B_aa_00416e80_FreelistSlabVector_Teardown_Inferred.md` |
| **System** | container / CNDHash freelist slab pointer vector |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

**Freelist slab pointer-vector teardown** used by CNDHash-family complete dtors:

1. Walk `[begin, end)` at freelist+0x08/+0x0c as `void**` array; `_aligned_free` each slab pointer.
2. If begin ≠ null: `operator_delete(begin)` to free the pointer array buffer (**returns**).
3. Always zero triad +0x08 / +0x0c / +0x10.

Does **not** walk freelist head at +0x00 (nodes reclaimed earlier by DestroyBucketTable).

Parents: `CNDHash_Dtor_00a2c2b0` (`FUN_00406420`) pushes `this+0x20`; sibling hash dtors; thin wrapper `FUN_00416c30`. Twin CF: thiscall `0x0059c8a0` `FreelistSlabVector_dtor`.

**Not** hash destroy, bucket free, or domain logic.

---

## 2. ABI (SEALED)

| Slot | Role |
|---|---|
| stack0 | freelist subobject* |
| return | void; **`ret 4`** (`C2 04 00`) |

```c
void FreelistSlabVector_Teardown_Inferred(FreelistSlab *fl /*stack*/);
```

Decompiler void + false noreturn on delete — **bytes override**.

---

## 3. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00416e80` (2026-08-05) ≡ raw scaffold CF spine |
| Bytes | `read_memory` 128 B — loop `_aligned_free`; optional delete; **always** zero triad; **`ret 4`** |
| Bounds | `get_function_by_address` body `00416e80`–`00416ef6` |
| Callers | `FUN_00406420`, `00413850`, `004157f0`, `004169a0`, `00416c30` + 3 unwind stubs |
| Twin | `0x0059c8a0` thiscall freelist dtor (W24-M) |
| Raw / annotated / clean | `aa_00416e80_*`, `FreelistSlabVector_Teardown_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 4. Control flow: clean ≡ raw ≡ live (+ bytes)

```c
// SEH install
it = fl->begin; end = fl->end;
while (it != end) { _aligned_free(*it); ++it; }
if (fl->begin) operator_delete(fl->begin); // RETURNS
fl->begin = fl->end = fl->cap = null;      // ALWAYS
// SEH restore; ret 4
```

| Stage | Match |
|---|---|
| aligned_free loop stride 4 | **Yes** (raw + live + bytes) |
| operator_delete buffer | **Yes** (when begin ≠ 0) |
| triad zero always | **Yes** (bytes; decomp partial) |
| delete returns | **Yes** (bytes fall-through) |
| stdcall ret 4 | **Yes** (`C2 04 00`) |
| No freelist-head walk | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Freelist slab vector teardown role | **Confirmed** | parents + CF |
| +0x08/+0x0c/+0x10 triad | **Confirmed** | bytes + CNDHash layout |
| `_aligned_free` per slot | **Confirmed** | IAT call |
| operator_delete returns + always zero | **Confirmed** | bytes override decomp |
| stdcall ret 4 | **Confirmed** | `C2 04 00` |
| Body **119 B** | **Confirmed** | bounds |
| Product name | **Open** | `_Inferred` |

---

## 6. Gaps / open

1. Product English for freelist subobject type.
2. Full dual of wrapper `00416c30` / sibling hash dtors (not OWN).
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
