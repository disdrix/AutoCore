# Review A (reconstruction fidelity): `aa_009697a0` StringVec_PushBackIfAbsent_EnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_009697a0` |
| **VA** | `0x009697a0`–`0x0096982D` exclusive (**141 B**) |
| **Canonical name** | `StringVec_PushBackIfAbsent_EnsureTrailingDirSep` |
| **Ghidra name** | `FUN_009697a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-J) |
| **Counterpart** | `reviews/B_aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md` |
| **System** | `StringVecShell` unique push_back + trailing dir sep |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body 141 B). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Normalize input path (ensure trailing directory separator via `FUN_009694e0`), linear-scan the shell for an equal `basic_string` (stride `0x1c`), and call `StringVec_PushBack` **only if** the scan reaches end (absent).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-J append) | `docs/reconstruction/raw/aa_009697a0_FUN_009697a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009697a0_FUN_009697a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_PushBackIfAbsent_EnsureTrailingDirSep.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_009697a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009697a0_StringVec_PushBackIfAbsent_EnsureTrailingDirSep.md` |
| Nested normalize | `aa_009694e0` (W32-A) |
| Nested push_back | `aa_004301f0` (W33-D) |
| Live | decompile + 141 B hex |

---

## 3. Signature (sealed)

```c
// EDI = self; stack path*; RET 0x04; void
void StringVec_PushBackIfAbsent_EnsureTrailingDirSep(
    StringVecShell* self /*EDI*/,
    const void* path);
```

| Formal | Source | Conf |
|---|---|---|
| self | EDI (`8B 77 04`, `8B CF` before push_back) | **High** |
| path | stack after SEH (`8B 44 24 2C`) | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009acae3; sub esp,0x1c
FUN_009694e0(&local, path)          // E8 → 009694e0
EH = 0
it = [EDI+4]; end = [EDI+8]
if it != end:
  loop: IAT operator==(it, local); if eq break; it += 0x1c; while it != end
  absent = (it == end)
else absent = true
if absent:
  mov ecx, EDI; call StringVec_PushBack(local)  // E8 → 004301f0
EH = -1
IAT ~basic_string(local)
restore SEH; add esp,0x28; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| SEH + local 0x1c | hex + decompile | **High** |
| Normalize first | call order | **High** |
| Stride 0x1c scan | `83 C6 1C` | **High** |
| Absent-only push | `75 0B` skip when found; `8B CF` + call | **High** |
| RET 4 | `C2 04 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (141 B) — see raw W34-J append.

Entry: `6A FF 68 E3 CA 9A 00` (SEH).  
Epilogue: `83 C4 28 C2 04 00`.  
Pad: `CC CC CC` then `FUN_00969830`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | **none** in Ghidra xrefs (peer `009696c0` also empty) |
| Callees | `FUN_009694e0`, IAT `operator==`, `FUN_004301f0`, IAT dtor |

---

## 7. Gaps

1. No sealed retail callers (xrefs empty).  
2. Product English for path-list role.  
3. Runtime / bit-exact / differential — open.

---

## 8. Verdict

EDI ABI, trailing-sep normalize, linear equality scan, and absent-only `StringVec_PushBack` are sealed against full-body hex and sibling duals → **accept-with-gaps**.
