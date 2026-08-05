# Review A (reconstruction fidelity): `aa_004651d0` Mem_FillDwordN_ReturnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_004651d0` |
| **VA** | `0x004651d0` |
| **Body** | `0x004651d0`–`0x004651f0` (**33 bytes**) |
| **Canonical name** | `Mem_FillDwordN_ReturnEnd` |
| **Ghidra name** | `FUN_004651d0` |
| **Review date** | `2026-07-29` (W22-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004651d0_Mem_FillDwordN_ReturnEnd.md` |
| **System** | stl-helpers / POD fill |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**Fill N dwords** at a destination pointer with `*value`, then **return the write end** so vector insert-N realloc paths can chain a suffix copy.

Custom register ABI (MSVC helper style):

| Register | Role |
|---|---|
| EDI | dest start |
| ESI | count |
| EDX | pointer to fill dword |
| EAX out | dest + count |

Sibling (range form): `StdFill_DwordRange` @ `0x005739b0` (first/last/value, void, cdecl).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004651d0` |
| Bytes | `read_memory` 64 B @ entry — body 33 B through `c3` |
| Bounds | `get_function_by_address` body `004651d0`–`004651f0` |
| Callers | `get_function_callers` / `get_xrefs_to` → 00456960, 00429970, 00419880 |
| Parent context | dual of `StdVector_InsertN_Dword_EaxFill_Inferred` (`aa_00456960`) |
| Raw / clean | `aa_004651d0_*`, `Mem_FillDwordN_ReturnEnd.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **33 B**, bare `ret` (`c3`) | **Confirmed** | `read_memory` |
| EDI dest / ESI count / EDX value* | **Confirmed** | `test esi`; loop `[edx]`→`[eax]`; `lea [edi+esi*4]` |
| Re-read `*value` each iter (no hoist) | **Confirmed** | `8b 1a` inside loop; edx not advanced |
| Return write end | **Confirmed** | `lea eax,[edi+esi*4]` |
| Leaf (no callees) | **Confirmed** | callees empty |
| Count==0 early-out still returns dest | **Confirmed** | jbe to lea with esi=0 |
| Product English name | **Inferred** | role-sealed structural |
| Decompiler `__fastcall` full story | **Residual** | understates ESI/EDI contract |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| test count / jbe skip | Yes |
| loop store *value, ++dest cursor, --count | Yes |
| pop ebx; lea end; ret | Yes |
| return dest+count | Yes |

### Recovered CF

```c
// EDI=dest, ESI=count, EDX=value*
uint32_t *Mem_FillDwordN_ReturnEnd(uint32_t *dest, int count, uint32_t const *value) {
  for (uint32_t *p = dest; count != 0; --count, ++p)
    *p = *value;
  return dest + count; // equivalent lea with original count
}
```

(Implementation uses original ESI in the final `lea`; loop counter is a copy in ECX.)

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00456960` | insert-N EAX fill (×2 sites) |
| Caller | `FUN_00429970` | insert family (×2) |
| Caller | `FUN_00419880` | insert family (×2); pairs with `0040c7c0` |
| Callee | — | leaf |

---

## 6. Gaps / open

1. Product/PDB demangled helper name.
2. Full taxonomy of all future xrefs beyond the three parents sealed here.
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
