# Review A (reconstruction fidelity): `aa_004c1960` ParticleFluidPhase_CreateLiquidChild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c1960` |
| **VA** | `0x004c1960`–`0x004c1a0f` exclusive (**175 B** / `0xAF`) |
| **Canonical name** | `ParticleFluidPhase_CreateLiquidChild_Inferred` |
| **Ghidra name** | `FUN_004c1960` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-O) |
| **Counterpart** | `reviews/B_aa_004c1960_ParticleFluidPhase_CreateLiquidChild_Inferred.md` |
| **System** | client / particle fluid phase / env liquid |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `get_function_by_address` + `read_memory` (full 175 B) + callee batch_decompile (`FUN_004c1800`, `FUN_004c0fe0`, `FUN_004c1a10`). **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

On the fluid-particle phase host, create/install/activate the 0x40 liquid child at `+0xc4`:

1. `operator_new(0x40)` under SEH.
2. `FUN_004c1800(new, phase)` thiscall ctor (or null).
3. Store at **`phase+0xc4`**.
4. `FUN_004c0fe0(child)` — liquid filter + RT buffers (`UIFluid*.fx` / `VOGEnvironmentLiquid.cpp`).
5. If `child+0x10 != 1`: activate (`FUN_0075bf40(0)`, `FUN_007567b0(child+0x38,0)`, set flag 1).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-O) | `docs/reconstruction/raw/aa_004c1960_FUN_004c1960.md` |
| Annotated | `docs/reconstruction/raw/aa_004c1960_FUN_004c1960.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_CreateLiquidChild_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c1960.cpp` |
| Function records | `functions/aa_004c1960_FUN_004c1960.md`, `functions/aa_004c1960_ParticleFluidPhase_CreateLiquidChild_Inferred.md` |
| Related | Init W33-S; blend `FUN_004c1a10`; nested ctor/init free |
| Live | full body hex; 2 xrefs CALL; callees sealed |

**Not performed:** Launcher, runtime, parent ledgers.

---

## 3. Signature (sealed)

```c
// ECX=phase*; bare RET; void
void __fastcall ParticleFluidPhase_CreateLiquidChild_Inferred(void *phase /*ECX*/);
```

| Formal | Source | Conf |
|---|---|---|
| phase | ECX (`mov esi,ecx`) | **High** |
| return | void (no EAX contract) | **High** |
| cleanup | bare `C3` after `ADD ESP,0x10` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
esi = ecx (phase)
raw = operator_new(0x40)
child = raw ? FUN_004c1800(raw, phase) : 0
[phase+0xc4] = child
FUN_004c0fe0(child)          // ECX=child (bytes: mov ecx,eax before call)
if [child+0x10] != 1:
  FUN_0075bf40(0)
  FUN_007567b0([child+0x38], 0)
  [child+0x10] = 1
return
```

| Stage | Match | Conf |
|---|---|---|
| Body size 0xAF / bare RET | **Yes** | **High** |
| ECX thiscall (bytes) | **Yes** | **High** |
| Store `+0xc4` / size 0x40 | **Yes** | **High** |
| Call order 5 callees | **Yes** | **High** |
| Activate gate on `+0x10` | **Yes** | **High** |
| Callers Init + blend rebind | **Yes** | **High** |

---

## 5. Gaps

- Product demangle for 0x40 child / `FUN_004c1800` / `DAT_00b03794`.
- Nested free `FUN_004c0fe0` product English and full resource ownership.
- OOM null-child path (thiscall/activate on null) residual.
- Runtime / bit-exact / differential.

---

## 6. Verdict

Reconstruction fidelity sealed for ABI, body bounds, install offset, call order, and activate gate. Nested ctor/init remain free → **accept-with-gaps**.
