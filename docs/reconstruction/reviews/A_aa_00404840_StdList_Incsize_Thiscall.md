# Review A (reconstruction fidelity): `aa_00404840` StdList_Incsize_Thiscall

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404840` |
| **VA** | `0x00404840`–`0x004048AE` |
| **Canonical name** | `StdList_Incsize_Thiscall` (**Inferred** STL role; ABI sealed) |
| **Prior scaffold** | `FUN_00404840` / `Named_CalleeOf_Client_DebugListMissionsStatus_00404840` |
| **Review date** | `2026-08-05` (OWN-ONLY dual A/B — **R10-006**) |
| **Reviewer role** | Independent reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00404840_StdList_Incsize_Thiscall.md` |
| **System** | shared MSVC `std::list` |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, callers/`get_assembly_context` |
| **Partition** | `WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-006** |
| **Verdict** | **accept** |

**Tools:** Ghidra decompile + analyze + `read_memory` + xrefs. No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Increment MSVC `std::list` size with overflow protection (thiscall specialization):

```
if (0x3fffffffU - list->_Mysize < count)
  throw with "list<T> too long";
list->_Mysize += count;
```

Shared leaf used by list insert helpers after BuyNode (`0x00418700`). **Not** mission-only despite partition seed / some callers.

**Not** the sealed fastcall twin `StdList_Incsize` @ `0x0043fe60` (ECX=count, EDX=list*, bare `RET`). **Not** max-`0x1fffffff` peer `0x00416010`.

---

## 2. Inspected artifacts

| Artifact | Source |
|---|---|
| Live decompile | `decompile_function(0x00404840)` ≡ 2026-07-23 raw |
| Entry / body bytes | `read_memory(0x00404840)` — SEH, `be ff ff ff 3f`, `[ecx+8]`, `C2 04 00` |
| Body range | `0x00404840`–`0x004048AE` (**111 B**) |
| String | `read_memory(0x00a1581c)` → `"list<T> too long"` |
| Callers | `00402d2f`, `00404110`, `00517dd6`, `0052b376` — all `PUSH 1` / `MOV ECX,list` / call |
| Clean | `reconstructed-exact/StdList_Incsize_Thiscall.cpp` |
| Twin reference | sealed `StdList_Incsize` @ `0x0043fe60` (W23-E) |

---

## 3. ABI (SEALED)

| Slot | Role | Evidence |
|------|------|----------|
| **ECX** | list* | `MOV EAX,[ECX+8]`; `MOV [ECX+8],EAX`; callers `MOV ECX,ESI/EDI/EBX` |
| stack `[esp+4]` | count | `MOV EDX,[ESP+4]`; callers `PUSH 1` |
| epilogue | **`RET 4`** | `C2 04 00` |
| return | void | no EAX produce for success |

```c
void __thiscall StdList_Incsize_Thiscall(StdListHeader *list /*ECX*/, uint32_t count /*stack*/);
```

---

## 4. Control flow: clean ≡ live

| Stage | Match |
|---|---|
| Load `_Mysize` @ `+8` | **Yes** (`8B 41 08`) |
| Max imm `0x3fffffff` | **Yes** (`BE FF FF FF 3F`) |
| Gate `(max-size) < count` → throw | **Yes** |
| String + `FUN_00401a40` + `_CxxThrowException` / `DAT_00acc388` | **Yes** |
| Else `_Mysize += count` | **Yes** (`ADD EAX,EDX` store) |
| `RET 4` | **Yes** |
| SEH frame `LAB_009bc919` | **Yes** (present; not port-critical) |

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| Role = list `_Incsize` | **High** (string + size field + callers) |
| ECX list / stack count / `RET 4` | **High** |
| Max `0x3fffffff` (distinct from Max1fffffff) | **High** |
| Distinct from fastcall twin `0043fe60` | **High** |
| Product exception type English | **Open** |
| Runtime / bit-exact | **Open** |

**Verdict:** **accept**
