# Review A (reconstruction fidelity): `aa_00537d10` CNDHashNode_NonOwning_scalar_dtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00537d10` |
| **VA** | `0x00537d10` |
| **Body** | `0x00537d10`–`0x00537d2b` (**`ret 4`**, 28 B; int3 pad before `FUN_00537d30`) |
| **Canonical name** | `CNDHashNode_NonOwning_scalar_dtor_Inferred` (Ghidra `FUN_00537d10`; created 2026-07-29) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00537d10_CNDHashNode_NonOwning_scalar_dtor_Inferred.md` |
| **System** | container / CNDHash (def / non-owning value family) |
| **Live tools** | Ghidra `create_function`, `decompile_function`, `force_decompile`, `read_memory`, `get_xrefs_to` (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — scalar dtor CF **High**; product name open |

---

## 1. Purpose

**Scalar deleting destructor** — **vtbl[0]** of **`PTR_FUN_009cf02c`** (CNDHash node family used by **`FUN_0053c460`** / active-def hash inserts and siblings):

1. Set vptr `*this = &PTR_FUN_009cf02c`.
2. If **`flags & 1`** → `operator_delete(this)`.
3. Return `this`.

**Does not** free `this+0x08` value — values are **not owned** by this node family (e.g. objective **definition** pointers living in mission data).

Twin: value-owning dtor `FUN_00537550` on vtbl `009cefec`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function create | Ghidra `create_function` @ `0x00537d10` (was undefined; body between pad and `00537d30`) |
| Fresh decompile | `force_decompile` @ `0x00537d10` |
| Machine | `read_memory` length 32 |
| Vtbl dword0 | `read_memory` @ `0x009cf02c` → `0x00537d10` |
| Insert stamp | `FUN_0053c460` sets `*node = &PTR_FUN_009cf02c` |
| DATA xrefs to vtbl | `FUN_0053c460`, `FUN_005307e0`, `FUN_00538bd0`, `FUN_0053b230`, `FUN_0053b720`, `FUN_0060bb80`, self |
| Twin owning dtor | `0x00537550` |

---

## 3. Authoritative body

```c
undefined4 * __thiscall FUN_00537d10(undefined4 *this, byte flags)
{
  *this = &PTR_FUN_009cf02c;
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
`f6 44 24 04 01 56 8b f1 c7 06 2c f0 9c 00 74 09 56 e8 … 83 c4 04 8b c6 5e c2 04 00 cc`

| Claim | Evidence | Conf |
|---|---|---|
| Test `flags&1` first (vs twin order) | `f6 44 24 04 01` before vtbl store | **High** (order differs from 00537550 but same effect) |
| ECX→ESI; vtbl imm `0x009cf02c` | `56 8b f1 c7 06 2c f0 9c 00` | **High** |
| No load/delete of `[esi+8]` | no `8b 46 08` / no value push | **High** |
| Conditional `operator_delete(this)`; **`ret 4`** | `74 09 56 e8… 8b c6 5e c2 04 00` | **High** |
| Adjacent to integrity `00537d30` | next non-pad byte `53 57 8b f9…` at `00537d30` | **High** |

---

## 5. Family contrast

| | `00537d10` / `009cf02c` | `00537550` / `009cefec` |
|---|---|---|
| Free value `+8` | **No** | **Yes** |
| Typical insert | `FUN_0053c460` (def hash `char+0x548`) | `FUN_0053c760` (state hash `char+0x55c`) |
| Value lifetime | External (defs) | Owned (state nodes) |

---

## 6. Gaps / open

1. Product mangled name / RTTI.
2. Full set of hash instances using `009cf02c` (multi-domain; not mission-only).
3. Flag bit meanings beyond MSVC scalar bit0 (only bit0 tested).
4. Runtime not run.

---

## 7. Safe claims

| Safe | Unsafe |
|---|---|
| Non-owning scalar dtor; vtbl `009cf02c`[0] | “does nothing useful” |
| No value free | Mission-only type name |
| accept-with-gaps | complete |
