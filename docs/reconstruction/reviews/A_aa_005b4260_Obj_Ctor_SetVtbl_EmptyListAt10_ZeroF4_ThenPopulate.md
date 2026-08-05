# Review A (reconstruction fidelity): `aa_005b4260` Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b4260` |
| **VA** | `0x005b4260`–`0x005b42e6` (**134 B**) |
| **Canonical name** | `Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate` |
| **Ghidra name** | `FUN_005b4260` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-O) |
| **Counterpart** | `reviews/B_aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` |
| **System** | host object / MSVC ctor + populate |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body through `ret 0x14`) + `get_bulk_xrefs` (empty). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Convenience **constructor**: same empty shell as `Obj_DefaultCtor_SetVtbl_EmptyListAt10_ZeroF4At20`, then `FUN_005b3fa0(this, p2..p6)` under MSVC SEH. Final `ret 0x14`.

**No live code xrefs** — production uses default ctor + separate populate. Still sealed as a real binary unit for completeness / possible dead code retention.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-O) | `docs/reconstruction/raw/aa_005b4260_FUN_005b4260.md` |
| Annotated | `docs/reconstruction/raw/aa_005b4260_FUN_005b4260.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005b4260.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b4260_Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate.md` |
| Default-ctor twin | `aa_005b3f60` |
| Live | zero xrefs; SEH + `ret 0x14` from bytes |

---

## 3. Signature (sealed)

```c
// ECX = this*; five stack args; ret 0x14; returns this
void * __thiscall Obj_Ctor_SetVtbl_EmptyListAt10_ZeroF4_ThenPopulate(
    void *self,
    uint32_t p2, uint32_t p3, uint32_t p4, uint32_t p5, uint32_t p6);
```

| Formal | Source | Conf |
|---|---|---|
| self | ECX | **High** |
| five stack args | `ret 0x14` + push sequence | **High** |
| return | EAX = this | **High** |
| SEH handler | imm `0x009a6860` | **High** |

---

## 4. Control flow (clean ≡ **bytes**)

```
SEH prolog (state=-1, handler=0x009a6860)
[esi] = 0x009d95b4
edi = esi+0x10
call FUN_005b43b0 → head/size empty
state = 0
zero F4 at +0x20
push p6,p5,p4,p3,p2; ecx=esi
call FUN_005b3fa0
SEH epilog; eax=esi; ret 0x14
```

| Stage | Match | Conf |
|---|---|---|
| Shell ≡ default ctor | **Yes** | **High** |
| Populate call | **Yes** (rel32 → `0x005b3fa0`) | **High** |
| `ret 0x14` | **Yes** | **High** |
| Zero callers | **Yes** (bulk xrefs empty) | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (134 B):
```
6aff6860689a0064a100000000506489250000000051568bf1578d7e108bcf89742408c706b4959d00e82201000089470433c08947088b4c24288b5424240f57c0894424148b44242c508b442424518b4c24245250518bcef30f114620f30f114624f30f114628f30f11462ce8cffcffff8b4c240c5f8bc65e64890d0000000083c410c21400
```

| Feature | Encoding |
|---|---|
| SEH handler | `68 60 68 9A 00` |
| Vtbl / list LEA | same pattern as default ctor |
| Populate call | `E8 CF FC FF FF` → `0x005b3fa0` |
| Epilogue | `83 C4 10` + `C2 14 00` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- No live callers (role = dead convenience vs retained link).
- Product class name; full `FUN_005b3fa0` arg semantics (other unit).
- Runtime differential — open.

---

## 7. Verdict

**accept-with-gaps** — convenience-ctor CF/ABI/bytes sealed; dead-caller + product class residual.
