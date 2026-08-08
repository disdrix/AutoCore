# Review A (reconstruction fidelity): `aa_00418790` StdList_Incsize_00418790

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418790` |
| **VA** | `0x00418790`–`0x004187fe` inclusive (**111 B** / `0x6F`) |
| **Canonical name** | `StdList_Incsize_00418790` |
| **Ghidra name** | `FUN_00418790` |
| **Prior / alias** | `Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00418790` (**retired** — parent-seed) |
| **Review date** | `2026-08-05` (R10-024 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00418790_StdList_Incsize_00418790.md` |
| **System** | shared MSVC `std::list` `_Incsize` (fastcall, max `0x3fffffff`) |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `disassemble_function` + `analyze_function_complete` + `read_memory` + callers/xrefs + `get_function_by_address` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Increment MSVC `std::list` size with overflow protection:

```
if (0x3fffffffU - list->_Mysize < count)
  throw with "list<T> too long";
list->_Mysize += count;
```

Shared leaf — push/insert wrappers across missions and multi-domain hosts. RecvBroadcast parent-seed name is **not** the purpose.

Twin (already dualed): **`StdList_Incsize`** @ `0x0043fe60` (W23-E **accept**) — same CF/ABI/max/string/throw.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ R10-024 append) | `docs/reconstruction/raw/aa_00418790_FUN_00418790.md` |
| Annotated | `docs/reconstruction/raw/aa_00418790_FUN_00418790.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/StdList_Incsize_00418790.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00418790.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Client_RecvBroadcast_00418790.cpp` |
| Function records | `functions/aa_00418790_FUN_00418790.md`, `functions/aa_00418790_StdList_Incsize_00418790.md` |
| Live | decompile ≡ CF; body hex 111 B; plain `RET`; 29 CALL xrefs; call-site `MOV ECX,1` / `MOV EDX,list` |

---

## 3. Signature (sealed)

```c
// __fastcall; ECX=count, EDX=list*; plain RET; void
void __fastcall StdList_Incsize_00418790(uint32_t count /*ECX*/, StdListHeader *list /*EDX*/);
```

| Slot | Source | Conf |
|---|---|---|
| count | **ECX** (`CMP ESI,ECX`; callers `MOV ECX,1`) | **High** |
| list* | **EDX** (`MOV EAX,[EDX+8]`; callers `MOV EDX,EBX`) | **High** |
| return | void (plain `RET` / `C3`) | **High** |
| cleanup | no stack args — **`RET`** not `RET n` | **High** |
| SEH | `LAB_009bc919` frame | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH setup | **Yes** | **High** |
| Load size `@list+8` | **Yes** (`8B 42 08`) | **High** |
| Max immediate `0x3fffffff` | **Yes** (`BE FF FF FF 3F`) | **High** |
| Gate `max - size < count` → throw | **Yes** | **High** |
| String `"list<T> too long"` @ `0x00a1581c` | **Yes** (`read_memory`) | **High** |
| `FUN_00401a40` + `_CxxThrowException` / `DAT_00acc388` | **Yes** | **High** |
| Success: `size += count` store `@+8` | **Yes** | **High** |
| No node alloc / no relink in body | **Yes** | **High** |
| Twin match `0043fe60` CF/ABI | **Yes** | **High** |
| Product `list<T>` English | open | **Inferred** STL role only |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker / shared leaf |
| External CALL xrefs | **29** |
| Caller functions | **21** (insert/push wrappers) |
| Callees (throw path) | `basic_string` ctor, `FUN_00401a40`, `_CxxThrowException` |
| Twin | `StdList_Incsize` `0x0043fe60` |
| Parent dual context | `FUN_004027f0` push_front (MEGA-089) |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| size `@+8` + max `0x3fffffff` + `"list<T> too long"` | **Yes** |
| Match dualed `StdList_Incsize` twin CF | **Yes** |
| Fastcall ECX/EDX sealed at call sites | **Yes** |
| Parent-seed RecvBroadcast name misleading | **Yes** → retire |
| VA suffix needed (name collision with `0043fe60`) | **Yes** → `StdList_Incsize_00418790` |

**Name accepted:** `StdList_Incsize_00418790` (no product invent; STL role High).

---

## 7. Gaps (owned)

| Gap | Severity | Notes |
|---|---|---|
| Exact C++ exception type English | Low | ThrowInfo + length_error ctor sealed |
| Full `StdListHeader` +0 meaning | Low | only +8 required here |
| Why two identical image copies | Low | link artifact; both shared leaves |
| Runtime / bit-exact | Open | deferred |

---

## 8. Confidence

| Claim | Confidence |
|---|---|
| MSVC `_Incsize` role | **High** |
| ECX/EDX ABI + plain RET | **High** |
| Max `0x3fffffff` + string | **High** |
| Shared leaf (not RecvBroadcast-only) | **High** (29 sites) |
| Name `StdList_Incsize_00418790` | **High** (inferred STL; VA disambiguation) |

**Verdict:** **accept**.
