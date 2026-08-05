# Review A (reconstruction fidelity): `aa_004cbfc0` Vector_InsertN_0x10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cbfc0` |
| **VA** | `0x004cbfc0`–`0x004cc21c` |
| **Canonical name** | `Vector_InsertN_0x10` |
| **Ghidra name** | `FUN_004cbfc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W25-M) |
| **Counterpart** | `reviews/B_aa_004cbfc0_Vector_InsertN_0x10.md` |
| **System** | MSVC STL vector insert (16-byte POD) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` prologue/epilogue; helpers `005dd920`/`00608720`/`004cb1d0`; callers include `CVOGHBWakeupSkill_ctor` |
| **Verdict** | **accept** |

---

## 1. Purpose

MSVC-style `vector<T>::_Insert_n` for **T size 0x10**: insert `count` copies of a 16-byte POD at `insertAt`, reallocating (1.5×) when capacity is insufficient.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004cbfc0_FUN_004cbfc0.md` (+ W25-M append) |
| Annotated | `docs/reconstruction/raw/aa_004cbfc0_FUN_004cbfc0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Vector_InsertN_0x10.cpp` |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_004cbfc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004cbfc0_Vector_InsertN_0x10.md` |
| Live | decompile `0x004cbfc0`; `read_memory` entry SEH + terminal `ret 0xc`; throw helper string |

---

## 3. Signature

```c
void __thiscall Vector_InsertN_0x10(void* this, void* insertAt, unsigned count, const void* value);
// ret 0xc
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ESI=this | `8B F1` after prologue | **High** |
| +4/+8/+0xc begin/end/cap | decomp loads + `>>4` | **High** |
| Element 0x10 | `* 0x10`, `>> 4`, value 4 dwords | **High** |
| ret 0xc | epilogue bytes | **High** |
| STL vector | throw `"vector<T> too long"` | **High** |

---

## 4. Control flow (sealed)

```
snapshot 16B value
if count==0: return
if size+count > max(0x0fffffff): throw
if size+count > capacity:
  grow 1.5× (or fit); new[]; copy prefix; fill n; copy suffix; delete old; rebind
elif tail < count:  // in-place past-end insert shape
  move/fill helpers
else:               // pure interior
  shift tail + assign hole
```

| Stage | Match | Conf |
|---|---|---|
| Early count==0 | **Yes** | **High** |
| Grow formula | **Yes** `cap+(cap>>1)` | **High** |
| POD copy/fill callees | **Yes** stride 0x10 loops | **High** |
| Two in-place shapes | **Yes** decomp branches | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Decode |
|---|---|
| Entry | SEH push `-1`, `LAB_009a1e20`, `fs:[0]` |
| `8B F1` | this → ESI |
| `C1 F8 04` / `C1 F9 04` | signed `>>4` element counts |
| Exit | ExceptionList restore + **`ret 0xc`** |

Decompile CF ≡ structural paths; helper product names residual.

---

## 6. Gaps

1. Product element type name (TFID vs other).  
2. Named duals for shift helpers still open.  
3. Runtime / bit-exact / differential open.

**None block vector-insert role/ABI/stride seal.**

---

## 7. Verdict

**accept** — classic MSVC 16-byte vector insert sealed (layout, grow, throw string, ABI, CF).
