# Review A (reconstruction fidelity): `aa_00416010` StdList_Incsize_Max1fffffff

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416010` |
| **VA** | `0x00416010`–`0x0041607e` |
| **Canonical name** | `StdList_Incsize_Max1fffffff` (**Inferred**) |
| **Prior scaffold** | `FUN_00416010` |
| **Review date** | `2026-08-04` (OWN-ONLY dual A/B — WQ9I-E) |
| **Reviewer role** | Independent reconstruction review (Path A fidelity) |
| **Counterpart** | `reviews/B_aa_00416010_StdList_Incsize_Max1fffffff.md` |
| **System** | shared MSVC `std::list` |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, callers/xrefs, `get_assembly_context`, `disassemble_function` |
| **Partition** | `WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-E** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Increment MSVC `std::list` size with overflow protection (max **`0x1fffffff`** specialization):

```
if (0x1fffffffU - list->_Mysize < count)
  throw with "list<T> too long";
list->_Mysize += count;
```

Shared leaf used by list insert helpers after buy-node (not UI-specific despite some callers).

**Not** the sealed twin `StdList_Incsize` @ `0x0043fe60` (max `0x3fffffff`). **Not** node alloc (`FUN_00415ed0`).

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `batch_decompile(0x00416010)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory` + `disassemble_function` — SEH, `be ff ff ff 1f`, `[edx+8]`, `C3` |
| Body range | `0x00416010`–`0x0041607e` (**111 B**) |
| String | `read_memory(0x00a1581c)` → `"list<T> too long"` |
| Callers | `00415dd0`, `00834700`, `008dfc60` — all `MOV ECX,1` then call |
| Clean | `reconstructed-exact/StdList_Incsize_Max1fffffff.cpp` |
| Twin reference | sealed `StdList_Incsize` @ `0x0043fe60` (W23-E) |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | count | `CMP ESI,ECX`; callers `MOV ECX,1` |
| **EDX** | list* | `MOV EAX,[EDX+8]`; `MOV [EDX+8],EAX` |
| stack | none | bare `RET` (`C3`) |
| return | void | no EAX produce for success |

```c
void __fastcall StdList_Incsize_Max1fffffff(uint32_t count /*ECX*/, StdListHeader *list /*EDX*/);
```

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Load `_Mysize` @ `+8` | **Yes** |
| Max imm `0x1fffffff` | **Yes** (`BE FF FF FF 1F`) |
| Gate `(max-size) < count` → throw | **Yes** |
| String + `FUN_00401a40` + `_CxxThrowException` / `DAT_00acc388` | **Yes** |
| Else `_Mysize += count` | **Yes** (`ADD EAX,ECX` store) |
| SEH frame `LAB_009bc919` | **Yes** (present; not port-critical) |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = list `_Incsize` | **High** (string + size field + callers) |
| ECX/EDX ABI / bare ret | **High** |
| Max `0x1fffffff` (distinct twin) | **High** |
| Product exception type English | **Open** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept-with-gaps**
