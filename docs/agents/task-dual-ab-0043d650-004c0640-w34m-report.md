# Dual A/B report — W34-M OWN `aa_0043d650` + `aa_004c0640`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W34-M  
**Scope:** VAs `0x0043d650`, `0x004c0640` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + `analyze_function_complete` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave34.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043d650` GuardedVector_ResizeZeroFill_Thiscall | **accept** — ECX thiscall + stack new_size + fill0 seed + RET 4 sealed (28 B); product residual only |
| `aa_004c0640` ParticleFluidPhase_Ctor_Inferred | **accept** — ECX thiscall + parent + HostBase/vtbl/layout + RET 4 sealed (199 B); product demangle residual only |

---

## VA `0x0043d650` — sealed facts

1. **Body:** `0x0043d650`–`0x0043d66b` (**28 B** / `0x1C`; pad `CC` then `0x0043d670` PushBack_Thiscall).
2. **ABI:** **ECX=container** (preserved into callee; body never loads ECX); stack **`new_size`**; **`RET 0x4`**. True thiscall wrapper.
3. **Semantics:** Seed stack fill dword **`0`**, call `GuardedVector_Resize_Thiscall` (`0x0043d940`, W33-L) with `(new_size, fill=0)`. Grow/shrink/equal handled entirely by callee.
4. **Layout:** Same GuardedVector family (`+0x0c` begin, `+0x10` size) — unused directly in this unit.
5. **Classification:** **wrapper** — sole callee Resize_Thiscall.
6. **Callers (6):** `FUN_004f1c70`, `FUN_004f1e20`, `FUN_004f2540`, `FUN_00542790`, `FUN_00542e20`, `FUN_00556b10`. Sites often pass **0** (empty); ABI is full resize-to-N.
7. **Name:** `GuardedVector_ResizeZeroFill_Thiscall` (Ghidra `FUN_0043d650`; **Inferred** structural). **Reject** scaffold `Named_CalleeOf_Named_VOG_DEBUG_STOP_0043d650`.
8. **Decompile ≡ bytes** for linear CF; **bytes win** on thiscall ECX + RET 4.  
   Full hex: `51518bc4c700000000008b44240c8964240450e8d802000059c20400`

### Gaps

- Product/PDB English.  
- Runtime / bit-exact.  
- Nested shrink erase free remains on `FUN_0043df90` (Resize chain).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043d650_GuardedVector_ResizeZeroFill_Thiscall.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043d650_GuardedVector_ResizeZeroFill_Thiscall.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043d650_FUN_0043d650.md` |
| Annotated | `docs/reconstruction/raw/aa_0043d650_FUN_0043d650.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_ResizeZeroFill_Thiscall.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043d650.cpp` |
| Function | `docs/reconstruction/functions/aa_0043d650_FUN_0043d650.md` |
| Function named | `docs/reconstruction/functions/aa_0043d650_GuardedVector_ResizeZeroFill_Thiscall.md` |

---

## VA `0x004c0640` — sealed facts

1. **Body:** `0x004c0640`–`0x004c0706` (**199 B** / `0xC7`; pad `CC` then next).
2. **ABI:** **ECX=this** (`MOV ESI,ECX`); stack **`parent*`**; returns **this**; SEH + `ADD ESP,0x10`; **`RET 0x4`**.
3. **Semantics:** Derived ctor of 0xC8 fluid-particle phase host:
   - `HostBase_DefaultCtor_Inferred` (`0x007560d0`, W32-O).
   - Replace vtbl → `PTR_FUN_009cb62c`; byte `+0x80 = 1`.
   - `FUN_0096f530` @ `+0x84` and `+0x8c`.
   - Zero `+0x94/+0x98/+0x9c`; `+0xa0 = parent`; `+0xa4 = *(parent+0xe4e8)`; `+0xa8 = *(parent+0xe894)`.
   - Zero `+0xac/+0xb0/+0xb4` and `+0xbc/+0xc0/+0xc4` (**skips +0xb8**).
   - `DAT_00b03790 = this`; byte `+0x78 = 0` (overrides HostBase default 1).
4. **Alloc size:** caller `new(0xC8)` (W31-P).
5. **Classification:** **worker** (derived ctor).
6. **Callers (1):** `FUN_0048fc90` (`PalantirEnv_InitPhases_Inferred`, W31-P) @ `0x0048fe4b` → store at `env+0xCC`, then `ParticleFluidPhase_Init` (`0x004c2080`, W33-S).
7. **Name:** `ParticleFluidPhase_Ctor_Inferred` (Ghidra `FUN_004c0640`; **Inferred**). **Reject** scaffold `Named_CalleeOf_Drive_NDRiver_fx_004c0640`.
8. **Decompile ≡ bytes** for full CF (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `6aff68c6199a0064a10000000050648925000000005153568bf189742408e86d5a290033db8d8e84000000895c2414c7062cb69c00c6868000000001e8afee4a008d8e8c000000c644241401e89fee4a008b44241c899e94000000899e98000000899e9c0000008986a00000008b88e8e40000898ea40000008b9094e800008b4c240c899eac000000899eb0000000899eb4000000899ebc000000899ec0000000899ec40000008996a800000089359037b000885e788bc65e5b64890d0000000083c410c20400`

### Gaps

- Product/PDB demangle for class / vtbl.  
- Semantic roles of parent `+0xe4e8` / `+0xe894`.  
- `FUN_0096f530` product type.  
- Runtime / bit-exact; `DAT_00b03790` lifetime.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004c0640_ParticleFluidPhase_Ctor_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004c0640_ParticleFluidPhase_Ctor_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004c0640_FUN_004c0640.md` |
| Annotated | `docs/reconstruction/raw/aa_004c0640_FUN_004c0640.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ParticleFluidPhase_Ctor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004c0640.cpp` |
| Function | `docs/reconstruction/functions/aa_004c0640_FUN_004c0640.md` |
| Function named | `docs/reconstruction/functions/aa_004c0640_ParticleFluidPhase_Ctor_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043d650` | Thiscall **resize-to-N with zero fill**: **ECX=container**, stack `new_size`, **RET 4**. Always seeds fill=`0` into sealed `GuardedVector_Resize_Thiscall` (W33-L). Do **not** hardcode Clear-only (body accepts any N). Do **not** mix with W28-D EAX/ECX `GuardedVector_Resize`. Closes W33-L sole-caller residual. |
| `004c0640` | Port as **phase ctor** for env+0xCC host: `new(0xC8)` → ctor(parent) → Init(flags=1). **ECX=this**, stack parent, returns this, **RET 4**. HostBase first, then derived vtbl `PTR_FUN_009cb62c`. Publish `DAT_00b03790`. Do **not** treat as PalantirEnv method or NDRiver driver. Pair with `ParticleFluidPhase_Init_Inferred` (W33-S). |

Shared: unrelated systems co-owned only by partition assignment (GuardedVector thiscall family vs fluid phase host). Each closes a prior-wave residual (Resize_Thiscall caller; InitPhases ctor free).

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`GuardedVector_*` from W28–W33 family; `ParticleFluidPhase_*` from W33-S Init peer + InitPhases wiring).  
- Rejected scaffold VOG_DEBUG_STOP / Drive_NDRiver_fx names.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).
