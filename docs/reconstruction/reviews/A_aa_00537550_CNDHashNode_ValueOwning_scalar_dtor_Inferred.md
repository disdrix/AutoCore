# Review A (reconstruction fidelity): `aa_00537550` CNDHashNode_ValueOwning_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537550` |
| **VA** | `0x00537550` |
| **Body** | `0x00537550`–`0x00537583` (**`ret 4`**, 52 B + int3 pad) |
| **Canonical name** | `CNDHashNode_ValueOwning_scalar_dtor_Inferred` (Ghidra `FUN_00537550`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00537550_CNDHashNode_ValueOwning_scalar_dtor_Inferred.md` |
| **System** | container / CNDHash (state-node / value-owning family) |
| **Live tools** | Ghidra `decompile_function`, `force_decompile`, `analyze_function_complete`, `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — MSVC scalar-deleting dtor CF **High**; product mangled name open |

---

## 1. Purpose

**Scalar deleting destructor** — **vtbl[0]** of **`PTR_FUN_009cefec`** (CNDHash node family used by **`FUN_0053c760`** / pending objective-state inserts):

1. Restore/set vptr `*this = &PTR_FUN_009cefec`.
2. If `this+0x08` (value pointer) non-null → `operator_delete(value)` (**owns payload**).
3. `this+0x08 = 0`.
4. If **`flags & 1`** → `operator_delete(this)`.
5. Return `this`.

This is the **value-owning** twin of `FUN_00537d10` (`009cf02c` family, no value free).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `force_decompile` @ `0x00537550` ≡ raw |
| Vtbl | `read_memory` @ `0x009cefec` → dword0 = `0x00537550` |
| Insert that stamps this vtbl | `FUN_0053c760` dual `A_aa_0053c760_CNDHash_Insert.md` |
| Sibling non-owning dtor | `0x00537d10` / `009cf02c` |
| Xrefs | DATA from vtbl + node ctors `FUN_0053b430`, `FUN_00538000`, `FUN_00538200`, `FUN_0053c760` |
| Raw / clean / function | `raw/aa_00537550_*`, `reconstructed-exact/FUN_00537550.cpp`, `functions/aa_00537550_*` |

---

## 3. Authoritative body

```c
undefined4 * __thiscall FUN_00537550(undefined4 *this, byte flags)
{
  *this = &PTR_FUN_009cefec;
  if ((void *)this[2] != 0) {
    operator_delete((void *)this[2]); // value at +0x08
  }
  this[2] = 0;
  if ((flags & 1) != 0) {
    operator_delete(this);
  }
  return this;
}
// ret 4
```

---

## 4. Machine seal (`read_memory`)

Hex:  
`56 8b f1 8b 46 08 85 c0 c7 06 ec ef 9c 00 74 09 50 e8 … 83 c4 04 f6 44 24 08 01 c7 46 08 00 00 00 00 74 09 56 e8 … 83 c4 04 8b c6 5e c2 04 00`

| Claim | Evidence | Conf |
|---|---|---|
| ECX→ESI this | `56 8b f1` | **High** |
| Load value `[esi+8]` | `8b 46 08` | **High** |
| Store vtbl imm `0x009cefec` | `c7 06 ec ef 9c 00` | **High** |
| Conditional delete value | `test eax; jz; push eax; call` | **High** |
| Clear `+8`; test `flags&1` | `c7 46 08 0…`; `f6 44 24 08 01` | **High** |
| Conditional delete this; **`ret 4`** | push esi; call; `8b c6 5e c2 04 00` | **High** |
| Slot 0 of `009cefec` | vtbl dword0 + DATA xrefs | **High** |

---

## 5. Node contract (from insert dual + this dtor)

| Offset | Role |
|---|---|
| `+0x00` | vtbl (`009cefec`) |
| `+0x04` | touch/mark byte (integrity walker) |
| `+0x08` | **owned** value* (state node / payload) — freed here |
| `+0x0C` | bucket next |
| `+0x10` | key |
| `+0x14/+0x18` | global list links |

---

## 6. Gaps / open

1. Product RTTI / mangled scalar-deleting dtor name.
2. Whether value free is always correct for every hash using this vtbl (mission pending is primary evidence; other insert sites share vtbl).
3. No virtual base dtor call beyond vptr reset — leaf class pattern.
4. Runtime not run.

---

## 7. Safe claims

| Safe | Unsafe |
|---|---|
| MSVC scalar dtor; owns `+8` | “always objective state” exclusive |
| vtbl `009cefec` method0 | Full class hierarchy name |
| accept-with-gaps | complete / bit-exact |
