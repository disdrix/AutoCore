# Review A (reconstruction fidelity): `aa_00431ae0` StringVec_Tidy

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431ae0` |
| **VA** | `0x00431ae0`–`0x00431b27` exclusive (**71 B**) |
| **Canonical name** | `StringVec_Tidy` |
| **Ghidra name** | `FUN_00431ae0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-D) |
| **Counterpart** | `reviews/B_aa_00431ae0_StringVec_Tidy.md` |
| **System** | `vector<basic_string>` tidy / buffer release (stride 0x1c) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 71 B) + sibling `FUN_00431aa0` decompile + thunk `0x00431ad0` bytes. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Fully release a `StringVecShell` buffer: destroy every live `basic_string` in `[begin, end)`, free the allocation, and null begin/end/capEnd. Null begin is idempotent tidy.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-D append) | `docs/reconstruction/raw/aa_00431ae0_FUN_00431ae0.md` |
| Annotated | `docs/reconstruction/raw/aa_00431ae0_FUN_00431ae0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_Tidy.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00431ae0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00431ae0_StringVec_Tidy.md` |
| Sibling range-dtor | `FUN_00431aa0` (no free/null) |
| Thunk | `0x00431ad0` `JMP 0x00431ae0` |
| Live | decompile + 71 B hex |

---

## 3. Signature (sealed)

```c
// ECX=self; bare RET; void
void StringVec_Tidy(StringVecShell* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX (`8B D9`) | **High** |
| cleanup | `C3` | **High** |
| stack args | none | **High** |

---

## 4. Control flow (bytes authority)

```
begin = [this+4]
if begin == null:
  goto zero_triad
end = [this+8]
for p = begin; p != end; p += 0x1c:
  ~basic_string(p)          // IAT [0x009c62f4]
operator_delete(begin)      // cdecl ADD ESP,4
zero_triad:
  [this+4] = [this+8] = [this+0xc] = 0
  ret
```

| Stage | Match | Conf |
|---|---|---|
| ECX=this | `8B D9` | **High** |
| null jump to zero | `74 24` → shared epilogue | **High** |
| destroy loop +0x1c | `83 C6 1C` / `75 F1` | **High** |
| free begin | push `[ebx+4]` + call + `83 C4 04` | **High** |
| triad zero after free | `C7 43 04/08/0C 00…` | **High** (bytes; decompile missed) |
| bare RET | `C3` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (71 B) — see raw W33-D append.

Entry: `53 8B D9 56`.  
Epilogue: `C7 43 04 00 00 00 00` … `5B C3`.  
Pad: `CC` from `0x00431b27`.

**Decompile ≢ bytes:** false noreturn on `operator_delete`; missing post-delete zeros. **Bytes win.**

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | listing/path cleanup, AssManager helpers, EH catch |
| Callees | IAT `~basic_string`, `operator_delete` |
| Thunk | `0x00431ad0` |

---

## 7. Gaps

1. Product/MSVC demangle for host container class.  
2. Exact CRT free import plate (behavioral free sealed).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict

Destroy loop, free, and full triad null sealed by full-body hex despite decompiler gap → **accept-with-gaps**.
