# Review A (reconstruction fidelity): `aa_0040c7c0` Mem_MoveDwordRange_ReturnEnd_EcxEax

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c7c0` |
| **VA** | `0x0040c7c0` |
| **Body** | `0x0040c7c0`–`0x0040c7e2` (**35 bytes**) |
| **Canonical name** | `Mem_MoveDwordRange_ReturnEnd_EcxEax` |
| **Ghidra name** | `FUN_0040c7c0` |
| **Review date** | `2026-07-29` (W22-T dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040c7c0_Mem_MoveDwordRange_ReturnEnd_EcxEax.md` |
| **System** | stl-helpers / POD relocate |
| **Dual status** | **Present (first dual seal; scaffold existed 2026-07-23)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

**Move** a dword-aligned half-open pointer range into a destination buffer and **return the write end**:

```c
size = ((srcEnd - srcBegin) >> 2) * 4;
memmove(dest, srcBegin, size);
return dest + size;
```

Same algorithm as `Mem_MoveDwordRange_ReturnEnd` (`0x004e2e80`) with a **different ABI** (ECX/EAX + one stack arg + `ret 4` vs three stack args + `ret 0xC`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x0040c7c0` |
| Bytes | `read_memory` 64 B — body 35 B through `c2 04 00` |
| Bounds | `get_function_by_address` body `0040c7c0`–`0040c7e2` |
| Callees | `get_function_callees` → `memmove` |
| IAT slot | `read_memory` @ `0x009c652c` → `0x006ea9d0` |
| Callers | `get_function_callers` / xrefs |
| Twin dual | `aa_004e2e80` Mem_MoveDwordRange_ReturnEnd |
| Pair fill | `aa_004651d0` Mem_FillDwordN_ReturnEnd (same W22-T) |
| Raw / clean | `aa_0040c7c0_*`, `Mem_MoveDwordRange_ReturnEnd_EcxEax.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body **35 B**, `ret 4` (`c2 04 00`) | **Confirmed** | `read_memory` |
| ECX = srcBegin | **Confirmed** | `sub eax,ecx` then push ecx as src |
| EAX in = srcEnd | **Confirmed** | entry sub uses EAX; decompiler `in_EAX` |
| Stack dest | **Confirmed** | `[esp+8]` after push esi |
| Size `((end-begin)>>2)*4` | **Confirmed** | `sar 2` + `lea [eax*4]` |
| Sole callee memmove | **Confirmed** | IAT call |
| Return dest+size | **Confirmed** | `add eax,esi` after memmove |
| Not object thiscall | **Confirmed** | no vtbl/fields; range helper |
| Live ≡ scaffold raw CF | **Confirmed** | side-by-side |
| Product English name | **Inferred** | role-sealed structural |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| span = end − begin | Yes |
| size = (span>>2)*4 | Yes |
| memmove(dest, src, size) | Yes |
| return dest+size | Yes |
| ret 4 | Yes (bytes; decompiler omits epilogue form) |

---

## 5. Callers / callees

| Direction | Symbol | Role |
|---|---|---|
| Caller | `FUN_00456960` | insert-N relocate (×2) |
| Caller | `FUN_00419880` | insert family (×4) |
| Caller | `FUN_0043a090`, `FUN_0043a1d0` | container insert/grow |
| Callee | `memmove` | CRT IAT |

---

## 6. Gaps / open

1. Product/PDB demangled helper name.
2. Rationale for dual ABIs vs `004e2e80` (COMDAT/template instantiation residual).
3. Runtime / bit-exact / differential.

**Verdict:** **accept**
