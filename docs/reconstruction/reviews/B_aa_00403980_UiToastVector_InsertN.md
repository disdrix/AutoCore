# Review B (skeptical / adversarial): `UiToastVector_InsertN` / `FUN_00403980` @ `0x00403980`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00403980` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00403980_UiToastVector_InsertN.md` |
| **Verdict** | **accept-with-gaps** — reject “always realloc”, wrong stride, and UI/mission identity |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Always reallocates | **Falsified** — in-place paths when `capacity >= size+count` |
| 2 | Growth is always 2× | **Falsified** — **1.5×** (`cap + (cap>>1)`) with floor to `size+count` |
| 3 | Element size ≠ `0x98` | **Falsified** — pervasive `/0x98` and `*0x98` |
| 4 | Deep-constructs toast fields | **Overstated** — POD stack copy + fill helpers; no per-field ctors in this body |
| 5 | This is the public push API | **Falsified** — push is `0040c5c0`; grow bridge `0040c720` |
| 6 | Grants missions / formats strings | **Falsified** — memory management only |
| 7 | `count` always 1 | **Falsified as absolute** — formal is general; toast grow uses 1 |
| 8 | begin lives at `this+0` | **Falsified** — `*(this+4)` |
| 9 | Product name sealed | **Open** |
| 10 | Helper names fully proven | **Probable only** — dual owns insert CF, not each helper’s dual |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stride `0x98` | **Confirmed** | Wrong alloc size / OOB |
| begin/end/cap +4/+8/+0xC | **Confirmed** | Corrupt adjacent fields |
| 1.5× growth policy | **Confirmed** | Memory blowup or thrash if ported as 2× only |
| Max count `0x1af286b` | **Confirmed** | Missing abort path |
| In-place vs realloc branch | **Confirmed** | Forced realloc changes pointer stability |
| POD (no owning ctor) | **High** | Leaks if port invents string ctors |
| Product symbol | **Open** | Docs |
| Second caller domain | **Medium** | May not be toast UI if different `T` same size |

---

## 3. Surviving contract for AutoCore

```
// MSVC-like vector insert for POD ToastElement sizeof=0x98
void InsertN(Vec* v, ToastElem* pos, size_t n, const ToastElem& value):
  if n == 0: return
  // capacity math on +4/+8/+0xC
  // if need grow: 1.5x (capped), new[], relocate, delete[]
  // else shift in place and fill n copies of value
  // value treated as 0x98 POD (0x26 dwords)

// Ports MUST preserve:
//  - 0x98 stride
//  - 1.5x growth (not silent 2x-only)
//  - max-size guard path
//  - POD fill (no deep string ownership here)
```

---

## 4. Falsification notes

### 4.1 “Push” conflation

Call graph: push → (fast copy **or** grow) → **this**. Ports that only implement push without insert will fail when the queue fills.

### 4.2 Growth formula

`cap + (cap>>1)` is **not** optional flavor; decompile has explicit overflow-to-zero then recompute path. Match MSVC behavior for pointer-stability tests.

### 4.3 Craft scaffold alias

`Named_CalleeOf_…_Client_RecvCraftFr_*` is **not** exclusive — toast insert is shared.

---

## 5. Open questions

1. Retail `T` / method name.
2. Duals for move/fill helpers.
3. `FUN_00402ed0` element domain confirmation.
4. Runtime realloc counts under burst toasts — open.

**Verdict:** **accept-with-gaps**. Sealed vector insert-N for `0x98` POD; reject push-identity, always-realloc, and non-POD overclaims.
