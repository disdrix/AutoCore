# Review A (reconstruction fidelity): `aa_0045cce0` StdVector_EraseRange_Pod28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045cce0` |
| **VA** | `0x0045cce0`–`0x0045cd2b` exclusive (**75 B**) |
| **Canonical name** | `StdVector_EraseRange_Pod28` |
| **Ghidra name** | `FUN_0045cce0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W36-L) |
| **Counterpart** | `reviews/B_aa_0045cce0_StdVector_EraseRange_Pod28.md` |
| **System** | MSVC POD vector erase stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (full 75 B) + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC-style `vector<T>::erase(first, last)` for POD T size **0x1c**: shift tail forward, publish end, return iterator via out-param.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W36-L append) | `docs/reconstruction/raw/aa_0045cce0_FUN_0045cce0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045cce0_FUN_0045cce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_EraseRange_Pod28.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045cce0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0045cce0_StdVector_EraseRange_Pod28.md` |
| Live | full hex 75 B; epilogue `C2 10 00`; callers ×2 |

---

## 3. Signature (sealed)

```c
// stack (vec*, out_it*, first, last); RET 0x10; EAX=out_it*
Pod28** StdVector_EraseRange_Pod28(
    StdVectorPod28* vec,
    Pod28** out_it,
    Pod28* first,
    Pod28* last);
```

| Formal | Source | Conf |
|---|---|---|
| vec* | `[esp+4]` | **High** |
| out_it* | `[esp+8]` | **High** |
| first | `[esp+0xC]` → EAX | **High** |
| last | `[esp+0x10]` → EDX | **High** |
| stride 0x1c | `ADD 0x1C` + ECX=7 movsd | **High** |
| RET 0x10 | `C2 10 00` | **High** |
| return out_it* | `8B C1` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty range skip shift | first==last → je | **High** |
| Truncate when last==end | no loop; end=first | **High** |
| Mid erase forward shift | rep movsd ×7 loop | **High** |
| Publish end @ +8 | `89 5A 08` | **High** |
| *out = first; return out | sealed | **High** |
| Leaf | analyze complete | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (75 B) — raw W36-L append.

Entry: `8B 44 24 0C 8B 54 24 10 3B C2 74 34 …`.  
Epilogue: `C2 10 00`.  
Pad `CC`×5 before InsertN @ `0045cd30`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **leaf** |
| Callers | `FUN_0045c4b0` (resize shrink), `FUN_00466df0` |
| Callees | none |

---

## 7. Gaps

1. Product/MSVC demangle + exact T (anm-track residual only).  
2. Parent `FUN_00466df0` dual-owned elsewhere (W36-P); not sealed here.  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

ABI, stride, erase/shift/truncate CF sealed by full-body bytes. Product English only → **accept-with-gaps**.
