# Review B (skeptical / adversarial): `StdVector_EraseRange_Dword_Inferred` / `FUN_00410490` @ `0x00410490`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00410490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00410490_StdVector_EraseRange_Dword_Inferred.md` |
| **Verdict** | **accept** on CF/width/ABI/end rebind; **needs-more-evidence** only on product symbol |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Frees the vector buffer (`operator_delete`) | **Falsified** — only memmove + store end; no free |
| 2 | Element size is toast `0x98` or floater `0x38` | **Falsified** — `>>2` / `*4`; parents index with `*4` |
| 3 | Calls element destructors | **Falsified** — POD memmove only |
| 4 | `__cdecl` free function | **Falsified** — `mov ebx,ecx` this; **`ret 0xC`** |
| 5 | Erases single element only | **Falsified** — arbitrary `[first,last)` via memmove size |
| 6 | Shrinks capacity | **Falsified** — cap `@+0xC` never written |
| 7 | gfxFont-only helper | **Overstated** — scaffold seed; 4 multi-domain callers |
| 8 | Decompiler invents memmove | **Falsified** — IAT call at `[0x009c652c]` |
| 9 | `*outIt` only written when range non-empty | **Falsified** — always written (empty range still sets iterator) |
| 10 | Product name sealed | **Open** |
| 11 | Runtime / bit-exact verified | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dword element width | **Confirmed** | Wrong memmove size / iterator math |
| End `@+8` rebind | **Confirmed** | Stale end → double-use of erased range |
| `ret 0xC` thiscall | **Confirmed** | Stack imbalance |
| Empty-range outIt still set | **Confirmed** | Iterator invalid if port omits store |
| No free / no dtor | **Confirmed** | Over-free or wrong type dtor port |
| Multi-domain helper | **High** | Treating as single feature API |
| Product STL name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// __thiscall; ret 0xC
// Vector: end pointer at this+8; elements are 4-byte POD
void StdVector_EraseRange_Dword(Vec* this, void** outIt, void* first, void* last):
  if first != last:
    size = ((end - last) >> 2) * 4
    p = memmove(first, last, size)
    this->end = p + size
  *outIt = first

// NOT operator_delete. NOT capacity shrink. NOT toast 0x98 erase.
// Callers: resize-shrink (004367f0, 00410420), bit-trim (004365e0), 00449000.
```

---

## 4. Falsification notes

### 4.1 “vector::clear frees memory”

Clear/resize-to-zero typically ends at end=`begin` via this erase (or equivalent) without releasing capacity — matching MSVC `vector` until `shrink_to_fit` / dtor. This VA never frees.

### 4.2 “Size formula is weird so decompiler wrong”

`((end-last)>>2)*4` is the standard MSVC dword scaling pattern; for aligned pointers it equals `end-last`. Bytes show `sar 2` then `lea [eax*4]`.

### 4.3 Confusion with toast ConstructN / InsertN

Toast helpers use `/0x98` and pod-copy leaves. This unit is **generic dword** and only appears on dword-vector resize/trim paths.

### 4.4 gfxFont seed alias

`Named_CalleeOf_…_gfxFontImpl_*` is inventory residue. Static callers include equip-gfx clear via `004367f0` and unrelated domains.

### 4.5 Bitset caller `004365e0`

That caller still uses this as **dword-word** erase after converting bit count → word count (`+0x1f >> 5`). Element width remains 4; bit packing is **caller** concern.

---

## 5. Open questions

1. Retail symbol.
2. Whether begin lives at `this+0` or `this+4` on every host type (parents use `+4`; this VA only needs `+8`).
3. Bit-exact / runtime — open.

**Verdict:** **accept** on sealed erase-range CF, dword width, thiscall/`ret 0xC`, and end rebind. Reject free/dtor/toast-width overclaims. Product symbol open.
