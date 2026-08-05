# Review A (reconstruction fidelity): `aa_005081f0` CVOGHBBase_EmptyVFunc

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081f0` |
| **VA** | `0x005081f0` |
| **Body** | `0x005081f0` only (**1** byte `c3`) |
| **Canonical name** | `CVOGHBBase_EmptyVFunc` |
| **Prior / alias** | `FUN_005081f0`; parent-seed `Named_CalleeOf_CVOGHBOKToCastAgain_OnEnd_005081f0` (**incomplete**) |
| **Review date** | `2026-07-29` (W18-A OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_005081f0_CVOGHBBase_EmptyVFunc.md` |
| **System** | heartbeat / shared empty leaf |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Shared empty leaf** — a single-byte `RET` with zero side effects.

Roles (xref evidence, not body logic):

1. **Base `CVOGHBBase` vtbl +0x14** default method (`0x009cdab0` table).
2. **Nop tail** after subclass work (OKToCastAgain OnEnd, Token OnEnd, etc. `jmp` here with ECX=this).
3. Misc CALL sites needing an empty thiscall-shaped target.

Product English / PDB symbol open. Structural name **`CVOGHBBase_EmptyVFunc`** reflects primary HB base-slot hosting without asserting contested “OnEnd” English for slot +0x14 vs Stop’s +0x10.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005081f0_FUN_005081f0.md` |
| Annotated | `docs/reconstruction/raw/aa_005081f0_FUN_005081f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_EmptyVFunc.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005081f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005081f0_CVOGHBBase_EmptyVFunc.md` |
| Live decompile | empty `return;` |
| Live bytes | `c3` then `cc` pad |
| Base vtbl | `read_memory` `0x009cdab0` — dword at +0x14 = `0x005081f0` |

---

## 3. Byte seal (`read_memory` @ `0x005081f0`)

```
c3                 ret
cc cc cc …         int3 pad (not body)
```

| Claim | Evidence | Conf |
|---|---|---|
| Body is pure `ret` | hex `c3` only | **High** |
| No stack cleanup in callee | not `c2 xx 00` | **High** |
| No stores / no callees | 1-byte body | **High** |
| Decompile ≡ raw ≡ bytes | all empty return | **High** |
| Distinct from `0x005081e0` | neighbor also `c3`, different VA | **High** |
| Distinct from `EmptyRet` `0x0056f570` | different VA | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| single `return;` | **Yes** |
| No invented domain work | **Yes** |
| No invented stack args / `ret N` | **Yes** |

Prior residual (`a_0051e3b0`) already sealed this VA as empty High — this dual owns the unit artifacts.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Pure nop body | **High** | sole byte `c3` |
| Base vtbl +0x14 default | **High** | `0x009cdac4` → this |
| Ignores `this` / stack args | **High** | body has no loads |
| Not Stop/detach implementation | **High** | no side effects |
| Product/PDB symbol | **Open** | no string in body |
| Slot English “OnEnd” | **Inferred only** | Stop dual uses +0x10 for OnEnd label; EndOrDestroy/subclass use +0x14 |

---

## 6. Gaps / open

1. Original compiler/PDB symbol.
2. Exhaustive DATA-slot census.
3. Runtime / bit-exact / differential — open.

**Verdict:** **accept**
