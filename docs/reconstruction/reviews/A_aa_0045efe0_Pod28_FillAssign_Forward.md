# Review A (reconstruction fidelity): `aa_0045efe0` Pod28_FillAssign_Forward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0045efe0` |
| **VA** | `0x0045efe0`–`0x0045effb` exclusive (**27 B**) |
| **Canonical name** | `Pod28_FillAssign_Forward` |
| **Ghidra name** | `FUN_0045efe0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W35-M) |
| **Counterpart** | `reviews/B_aa_0045efe0_Pod28_FillAssign_Forward.md` |
| **System** | MSVC POD fill-assign stride **0x1c** |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` (no disasm dump) + `read_memory` (full body) + callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Forward assign-fill half-open `[dst_begin, dst_end)` from one POD template `*value`, element size **0x1c**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W35-M append) | `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.md` |
| Annotated | `docs/reconstruction/raw/aa_0045efe0_FUN_0045efe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Pod28_FillAssign_Forward.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0045efe0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0045efe0_Pod28_FillAssign_Forward.md` |
| Live | full hex 27 B; epilogue `C3`; callers ×3 |

---

## 3. Signature (sealed)

```c
// EAX=dst_begin, EDX=dst_end, EBX=value*; RET 0; leaf
void Pod28_FillAssign_Forward(Pod28* dst_begin, Pod28* dst_end, const Pod28* value);
```

| Formal | Source | Conf |
|---|---|---|
| dst_begin | EAX (`in_EAX` / `8B F8`) | **High** |
| dst_end | EDX (`param_2` / `3B C2`) | **High** |
| value* | EBX (`8B F3` → ESI for movsd) | **High** |
| stride 0x1c | `83 C0 1C` + ECX=7 movsd | **High** |
| RET 0 | `C3` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Empty range early out | decompile + bytes | **High** |
| Per-slot 7-dword assign | `B9 07` `F3 A5` | **High** |
| Loop until EAX==EDX | `75 EE` | **High** |
| Leaf (no callees) | analyze complete | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (27 B) — raw W35-M append.

Entry: `3B C2 74 16 56 57`.  
Epilogue: `5F 5E C3`.  
Pad `CC`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | **leaf** |
| Callers | `FUN_0045cd30`, `FUN_00466ea0`, `FUN_00469f50` |
| Callees | none |

---

## 7. Gaps

1. Product/MSVC demangle + exact T (anm-track residual only).  
2. Exact float vs dword lane interpretation (POD either way).  
3. Runtime / bit-exact / differential.

---

## 8. Verdict rationale

ABI, stride, loop, and leaf status sealed by full-body bytes + decompile CF. Gaps are product English only → **accept-with-gaps**.
