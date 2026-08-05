# Review A (reconstruction fidelity): `aa_00406840` LogicUiEventQueue_Resize

| Field | Value |
|---|---|
| **Stable ID** | `aa_00406840` |
| **VA** | `0x00406840`–`0x004068e7` |
| **Canonical name** | `LogicUiEventQueue_Resize` |
| **Ghidra name** | `FUN_00406840` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-E) |
| **Counterpart** | `reviews/B_aa_00406840_LogicUiEventQueue_Resize.md` |
| **System** | client-logic-ui / event queue |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` + `analyze_function_complete`; callers `FUN_00801c50` / `FUN_00946c00` |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style **`vector::resize(n, value)`** for Logic-UI event elements (stride **0x138**):

1. `size = begin ? (end-begin)/0x138 : 0`
2. If `newCount <= size`: if strictly smaller, erase `[begin+newCount*0x138, end)` via `FUN_00407640`; return
3. If `newCount > size`: `LogicUiEventQueue_InsertN(queue, end, newCount-size, &value)`

Live callers both clear (`newCount=0`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00406840_FUN_00406840.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00406840_FUN_00406840.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LogicUiEventQueue_Resize.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406840.cpp` |
| Function record | `docs/reconstruction/functions/aa_00406840_FUN_00406840.md` |
| Insert-N dual | `LogicUiEventQueue_InsertN` (`0x004076a0`, W23-B) |
| Live | decompile ≡ raw; `read_memory` 168 B; both exits `C2 38 01` |

---

## 3. Signature (sealed)

```c
// ECX=queue; EAX=newCount; stack Event value[0x138] by-value; RET 0x138
void __fastcall LogicUiEventQueue_Resize(void* queue, uint32_t newCount /*EAX*/, /* value */);
```

| Formal | Source | Conf |
|---|---|---|
| queue | ECX | **High** |
| newCount | EAX (`in_EAX`) | **High** |
| value | Stack POD 0x138 B | **High** (`RET 0x138`) |
| cleanup | `RET 0x138` both exits | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
size = (end-begin)/0x138 or 0
if newCount <= size:
  if newCount < size: erase [begin+new*stride, end)
  return
else:
  InsertN(queue, end, newCount-size, &value)
  return
```

| Stage | Match | Conf |
|---|---|---|
| Stride 0x138 magic div | Yes (`D3 20 0D D2`) | **High** |
| Shrink erase path | Yes → `00407640` | **High** |
| Grow InsertN path | Yes → `004076a0` | **High** |
| RET 0x138 | Yes both exits | **High** |
| Callers clear (EAX=0) | Yes `xor eax,eax` | **High** |

---

## 5. Gaps

- Full 0x138 event record layout (shared residual with InsertN family).
- `FUN_00407640` not dual-sealed this wave (erase helper role sealed from CF).
- Runtime / bit-exact.

---

## 6. Verdict

CF/ABI/stride/callers fully sealed; remaining gaps are shared family residuals, not this unit's CF → **accept**.
