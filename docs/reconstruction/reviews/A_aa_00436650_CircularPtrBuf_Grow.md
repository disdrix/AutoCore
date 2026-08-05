# Review A (reconstruction fidelity): `aa_00436650` CircularPtrBuf_Grow

| Field | Value |
|---|---|
| **Stable ID** | `aa_00436650` |
| **VA** | `0x00436650` |
| **Body span** | `00436650` – `00436794` |
| **Canonical name** | `CircularPtrBuf_Grow` (**Inferred**) |
| **Ghidra name** | `FUN_00436650` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — W18-E) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00436650_CircularPtrBuf_Grow.md` |
| **System** | container / circular pointer-buffer utility |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Grow the **heap pointer map** of a circular buffer object so a subsequent push can proceed:

1. **this** arrives in **EBX** (custom register ABI).
2. Stack **`grow_request`** (caller always passes **1** today).
3. Guard against map overflow via **`FUN_00436860`** (`"deque<T> too long"`).
4. Optionally raise grow to **`max(capacity/2, 8)`**.
5. **`operator_new((cap+grow)*4)`**, rearrange circular contents with **`memmove`**, zero new slots.
6. **`operator_delete`** old map if any; publish **`capacity += grow`**, **`slots = new`**.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (authoritative + W18-E re-verify) | `raw/aa_00436650_FUN_00436650.md` |
| Annotated | `raw/aa_00436650_FUN_00436650.annotated.md` |
| Clean | `reconstructed-exact/CircularPtrBuf_Grow.cpp` |
| Alias clean | `reconstructed-exact/FUN_00436650.cpp` |
| Function record | `functions/aa_00436650_FUN_00436650.md` |

**This pass (live, OWN VA):**

- Ghidra `decompile_function` @ `0x00436650`
- Ghidra `read_memory` @ `0x00436650` length 340 — body ends `C2 04 00`; commit after delete sealed
- Ghidra `get_function_by_address` bounds `00436650`–`00436794`
- Ghidra `get_function_xrefs` / callers — sole `FUN_00436340` @ `00436350`
- Ghidra `get_assembly_context` @ caller — `push 1; call` with EBX=this
- Context decompile of `FUN_00436860` for throw string only (not owned)
- **Not performed:** Launcher, runtime golden, bit-exact image diff

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| **EBX** | buffer object `this` | prologue `mov eax,[ebx+8]`; all fields via EBX |
| **`[esp+4]`** | `uint grow_request` | `mov ebp,[esp+0x14]` after `sub esp,0xC; push ebp` |
| **Return** | void | `ret 4` |
| **ECX/EAX this** | **not used** | not `__thiscall` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span + `ret 4` | **High** | `read_memory` |
| EBX this; stack grow count | **High** | body + sole caller |
| Fields +4/+8/+0xC | **High** | matches push sibling |
| Max size `0xCCCCCCC` + throw string | **High** | imm + callee decompile |
| Geometric grow half-cap / min 8 | **High** | decompile CF |
| New size `(cap+grow)*4` | **High** | |
| Circular memmove rearrange + zero | **High CF** | decompiler arithmetic opaque but consistent |
| Post-delete capacity/slots commit | **High** | **bytes**; decompiler wrong |
| Product class name `CircularPtrBuf` | **Inferred** | family with `aa_00436340` |
| Bit-for-bit / runtime / differential | **Open** | deferred |

---

## 5. Control flow: clean ≡ raw ≡ live (+ bytes fix)

| Stage | Match |
|---|---|
| Overflow throw | Yes |
| Geometric grow clamp | Yes |
| new + circular memmove + zero | Yes (plate) |
| delete old + capacity/slots commit | Yes (**bytes**; clean fixes plate) |

### Recovered CF

```c
// void CircularPtrBuf_Grow(CircularPtrBuf* self /*EBX*/, unsigned grow /*stack*/)
if (0xCCCCCCC - self->capacity < grow) throw_deque_too_long();
grow = max_geometric(grow, self->capacity); // max(grow, max(cap/2,8)) if safe
neu = new void*[capacity + grow];
// circular linearize old → neu (head preserved)
if (self->slots) delete self->slots;
self->capacity += grow;
self->slots = neu;
```

---

## 6. Callers

| Caller | Site | Role |
|---|---|---|
| `FUN_00436340` (`CircularPtrBuf_PushCopy_0x14`) | `0x00436350` | grow by 1 when full |

**1 xref only.**

---

## 7. Gaps

1. Product/PDB English symbol for the container.
2. Full formal proof of every memmove length expression vs head/cap (CF sealed; algebra residual).
3. Runtime / bit-exact / differential — open.
4. Ownership of `FUN_00436860` / CRT new-delete not dualed.

**Verdict:** **accept-with-gaps**
