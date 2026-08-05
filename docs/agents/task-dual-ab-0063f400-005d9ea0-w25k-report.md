# Dual A/B report — W25-K OWN `aa_0063f400` + `aa_005d9ea0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W25-K  
**Scope:** VAs `0x0063f400`, `0x005d9ea0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0063f400` VehiclePhys_Mode2Helper_Ctor | **accept-with-gaps** — ABI/layout/constants/sole caller sealed; product field English + nested `0063f330` residual |
| `aa_005d9ea0` Drive_CollisionListener_PrepBodyContact | **accept-with-gaps** — ABI RET0x14/CF/gates/allowCreate=0 sealed; ctx/type English residual |

---

## VA `0x0063f400` — sealed facts

1. **Body:** `0x0063f400`–`0x0063f4c6` (199 B; `RET 4`).
2. **ABI:** **ECX**=mode-2 helper*; stack0=phys host*; **EAX**=this.
3. **Caller (1):** `VehiclePhys_SetModeHelper` mode-2 only (`0x005d4094`); factory alloc **0x60**.
4. **Callee (1):** `FUN_0063f330(this, *(host+0xc))`.
5. **Layout:** vtable `PTR_FUN_009e3ec0`; refcount `+6=1`; FLT_MAX quads; 1.0 diagonals; blends ≈0.01/0.005/0.1/0.2.
6. **Name:** `VehiclePhys_Mode2Helper_Ctor` (Ghidra `FUN_0063f400`; **Inferred**).
7. **Decompile ≡ bytes** for CF; meta `(void)` residual rejected.

### Gaps

- Product English for blend/FLT_MAX fields.  
- Mode-2 vtable method names.  
- Nested `0063f330` dual.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0063f400_VehiclePhys_Mode2Helper_Ctor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0063f400_VehiclePhys_Mode2Helper_Ctor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0063f400_FUN_0063f400.md` |
| Annotated | `docs/reconstruction/raw/aa_0063f400_FUN_0063f400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehiclePhys_Mode2Helper_Ctor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0063f400.cpp` |
| Function | `docs/reconstruction/functions/aa_0063f400_FUN_0063f400.md` |
| Function named | `docs/reconstruction/functions/aa_0063f400_VehiclePhys_Mode2Helper_Ctor.md` |
| Scratch | `docs/reconstruction/tmp/a_0063f400.md` |

---

## VA `0x005d9ea0` — sealed facts

1. **Body:** `0x005d9ea0`–`0x005da093` (500 B; `RET 0x14`).
2. **ABI:** **ECX**=CollisionListener* (`+0xc` body cache); stack×5: ctx, body*, impact*, enable, outPlayed*; void.
3. **Caller (1):** `Drive_CollisionListener_Contact` ×2 sites (body A/B).
4. **Callees:** `PlayCollisionSound` (`005d90a0`), `FUN_0040afb0`×2, `PlayCollisionEffect` (`005d9af0`, **allowCreate=0**).
5. **CF:** parent-walk → host pair-list types 1/3/4 → cache debounce → sound/FX if enable and `|impact|>1.0` (`_DAT_00af4364`) → optional `*out=1`.
6. **Name:** `Drive_CollisionListener_PrepBodyContact` (Ghidra `FUN_005d9ea0`; **Inferred**).
7. **Decompile ≡ bytes** for CF; formal count sealed by `RET 0x14` + Contact pushes.

### Gaps

- Pair type / nested `+0x38==3` product English.  
- ctx exact type.  
- enable producers detail.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005d9ea0_Drive_CollisionListener_PrepBodyContact.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005d9ea0_Drive_CollisionListener_PrepBodyContact.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005d9ea0_FUN_005d9ea0.md` |
| Annotated | `docs/reconstruction/raw/aa_005d9ea0_FUN_005d9ea0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Drive_CollisionListener_PrepBodyContact.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005d9ea0.cpp` |
| Function | `docs/reconstruction/functions/aa_005d9ea0_FUN_005d9ea0.md` |
| Function named | `docs/reconstruction/functions/aa_005d9ea0_Drive_CollisionListener_PrepBodyContact.md` |
| Scratch | `docs/reconstruction/tmp/a_005d9ea0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0063f400` | Client vehicle phys mode-2 helper ctor only. Preserve 0x60 size, vtable, refcount=+6, and SetModeHelper install/Release dance at phys+0x54. Not server simulation. |
| `005d9ea0` | Client collision SFX/VFX prep only — not server damage. Preserve allowCreate=0, 1.0f gate, dual A/B calls, and listener+0xc debounce. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
