# Review A (reconstruction fidelity): `aa_00637da0` CVOGObjectiveRequirement_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00637da0` |
| **VA** | `0x00637da0` |
| **Body end** | `0x00637db1` (`RET 4`) |
| **Canonical name** | `CVOGObjectiveRequirement_ctor` |
| **Prior scaffold** | `FUN_00637da0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00637da0_CVOGObjectiveRequirement_ctor.md` |
| **System** | `missions-progression` |
| **Agent** | W17-Q OWN-ONLY |
| **Verdict** | **accept-with-gaps** — base ctor ABI + vfptr + parent sealed |

---

## 1. Purpose

MSVC **`__thiscall` constructor** for RTTI base class `CVOGObjectiveRequirement`:

1. `*this = PTR_LAB_009e3bac` (`0x009e3bac`).
2. `*(this+0x04) = parent` (stack arg).
3. Return `this` in **EAX**.

Leaf: no callees, no RequirementType, no inventory. Subclass ctors (Collect type **2**, Deliver type **3**, …) call this then overwrite vfptr and fill type-specific fields.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00637da0_FUN_00637da0.md` (+ 2026-07-29 residual) |
| Annotated | `docs/reconstruction/raw/aa_00637da0_FUN_00637da0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObjectiveRequirement_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00637da0_CVOGObjectiveRequirement_ctor.md` |
| Live decompile | Ghidra `decompile_function` `0x00637da0` — two stores; CF ≡ scaffold |
| Live bytes | `read_memory` 18 B @ `0x00637da0` |
| Vtable | `read_memory` 64 B @ `0x009e3bac` |
| RTTI | string `.?AVCVOGObjectiveRequirement@@` @ `0x00afe9dc` |
| Callers | `get_function_callers` / `get_xrefs_to` — 14 subclass ctors |
| Sibling duals | Collect `A_aa_00611690_*`, Deliver `A_aa_00610bc0_*` (base step sealed there) |

**Not performed:** `disassemble_bytes`, Launcher, live CE, bit-exact image diff.

---

## 3. Sealed facts

### 3.1 ABI — **SEALED**

| Fact | Evidence |
|---|---|
| `this` in **ECX** | `8B C1` (save to EAX) |
| Stack `parent` (4 B) | `8B 4C 24 04` |
| Epilogue **`RET 4`** | `C2 04 00` |
| Return `this*` in **EAX** | EAX never overwritten after save; callers treat return as this |
| Convention | MSVC **`__thiscall`**, one stack dword |

```c
void* __thiscall CVOGObjectiveRequirement_ctor(void* this, void* parent);
// RET 4
```

### 3.2 Body stores — **SEALED**

| Store | Bytes | Meaning |
|---|---|---|
| `*this = 0x009e3bac` | `C7 00 AC 3B 9E 00` | base vfptr |
| `*(this+4) = parent` | `89 48 04` | parent field |

Full body:

```text
0x00637da0: 8B C1  8B 4C 24 04  C7 00 AC 3B 9E 00  89 48 04  C2 04 00
```

### 3.3 Identity — **SEALED High**

| Fact | Evidence |
|---|---|
| RTTI base class | `.?AVCVOGObjectiveRequirement@@` (no subclass suffix) |
| Shared by Collect/Deliver/… | 14 xrefs; Collect dual already documents this call |
| Temporary vfptr | Collect/Deliver overwrite `*this` after base returns |

### 3.4 Vtable head (informational)

LE dwords @ `0x009e3bac`: first slot `0x00637f00`, then stub cluster (`0x00489918`×3, …). Product English for slots **Open**.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| vfptr install | **Yes** |
| parent store | **Yes** |
| RET 4 / return this | **Yes** (clean returns this; raw decompiler said void — **corrected** via bytes) |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Base ctor role | **Confirmed** | callers + RTTI |
| ABI / RET 4 / return this | **Confirmed** | full body bytes |
| vfptr `0x009e3bac` | **Confirmed** | |
| parent @ `+0x04` | **Confirmed** | |
| Name `CVOGObjectiveRequirement_ctor` | **High** | RTTI exact class name |
| No RequirementType write | **Confirmed** | body has no `+0x0c` store |
| Base vfptr slot names | **Open** | |
| Runtime / bit-exact | **Open** | |

---

## 6. Gaps

1. English names of base virtuals under `PTR_LAB_009e3bac`.
2. Semantic of `parent` per caller (objective instance vs def row).
3. Runtime construction capture.
4. Parent unit: full requirement factory type-dispatch table.

---

## 7. Surviving contract

```
// __thiscall; RET 4; returns this
*this = 0x009e3bac;   // base CVOGObjectiveRequirement vfptr
this[1] = parent;     // +0x04
// subclass must overwrite *this and write type @ +0x0c
```
