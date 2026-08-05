# Review A (reconstruction fidelity): `aa_0043fe60` StdList_Incsize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043fe60` |
| **VA** | `0x0043fe60`–`0x0043fece` |
| **Canonical name** | `StdList_Incsize` (**Inferred**) |
| **Prior scaffold** | `FUN_0043fe60` / `Named_CalleeOf_Auth_AuthServer_0043fe60` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity — OWN-ONLY W23-E |
| **Counterpart** | `reviews/B_aa_0043fe60_StdList_Incsize.md` |
| **System** | shared MSVC `std::list` |
| **Verdict** | **accept** — ABI, size field, max gate, string, throw path, three-rep sealed |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ bounds/callers/callees/xrefs). No `disassemble_bytes`. Own VA only. No ledgers. No Launcher.

---

## 1. Purpose

Increment MSVC `std::list` size with overflow protection:

```
if (0x3fffffffU - list->_Mysize < count)
  throw with "list<T> too long";
list->_Mysize += count;
```

Shared leaf — Auth, audio queue (`StdList_PushPayloadNode`), UI, and many insert paths. Auth parent-seed name is **not** the purpose.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0043fe60_FUN_0043fe60.md` (+ W23-E live seal) |
| Annotated | `docs/reconstruction/raw/aa_0043fe60_FUN_0043fe60.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Incsize.cpp` |
| Alias | `docs/reconstruction/reconstructed-exact/FUN_0043fe60.cpp` |
| Function record | `docs/reconstruction/functions/aa_0043fe60_StdList_Incsize.md` |
| Live decompile | Ghidra `decompile_function` `0x0043fe60` — **≡** raw |
| Live bytes | `read_memory` `0x0043fe60` length 120 → SEH + max + size store + `C3` |
| String | `inspect_memory_content` `0x00a1581c` → `list<T> too long` |
| Call site ABI | `read_memory` `0x0048036e` → `mov ecx,1; mov edx,ebx; call` |
| Bounds | `get_function_by_address` → `0043fe60`–`0043fece` |

---

## 3. Sealed residuals

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| count | **ECX** (`cmp esi,ecx`; caller `mov ecx,1`) |
| list* | **EDX** (`mov eax,[edx+8]`; caller `mov edx,ebx`) |
| Epilogue | plain **`RET`** (`C3`) |
| Return | void |

```c
void __fastcall StdList_Incsize(uint32_t count /*ECX*/, StdListHeader *list /*EDX*/);
```

### 3.2 Size field — **SEALED**

| Fact | Evidence |
|---|---|
| `_Mysize` at `list+8` | `8b 42 08` load; `89 42 08` store |
| Operation | `add eax,ecx` then store |

### 3.3 Overflow max — **SEALED**

```
be ff ff ff 3f    mov esi, 0x3fffffff
2b f0             sub esi, size
3b f1             cmp esi, count
73 33             jae ok
```

Gate: `0x3fffffffU - size < count` → throw.

### 3.4 Throw path — **SEALED**

| Step | Evidence |
|---|---|
| Message | push `0x00a1581c` → `"list<T> too long"` |
| `FUN_00401a40` | call after string ctor |
| `_CxxThrowException` | + `ThrowInfo` `DAT_00acc388` |
| Noreturn | decompiler WARNING; no return after throw |

### 3.5 Three-rep — **SEALED**

live decompile ≡ raw body ≡ annotated CF ≡ clean plate control flow.

---

## 4. Gaps (owned)

| Gap | Severity | Notes |
|---|---|---|
| Exact C++ exception type name | Low | ThrowInfo sealed; type name open |
| Full `StdListHeader` +0/+4 meaning | Low | only +8 required here |
| Runtime / bit-exact | Open | deferred |

Nested callees (`FUN_00401a40`, throw) not re-proven beyond call presence.

---

## 5. Confidence

| Claim | Confidence |
|---|---|
| MSVC `_Incsize` role | **High** |
| ECX/EDX ABI + plain RET | **High** |
| Max `0x3fffffff` + string | **High** |
| Shared leaf (not Auth-only) | **High** (18+ callers) |
| Name `StdList_Incsize` | **High** (inferred STL; no product symbol) |

**Verdict:** **accept**.
