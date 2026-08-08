# Review A (reconstruction fidelity): `aa_00599550` CVOGHBMoveVehicleToMouse_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00599550` |
| **VA** | `0x00599550` |
| **Body span** | `0x00599550`–`0x0059956f` inclusive (**32** bytes / `0x20`; exclusive end `0x00599570` → complete/body) |
| **Canonical name** | `CVOGHBMoveVehicleToMouse_ctor` |
| **Ghidra name** | `FUN_00599550` |
| **Review date** | `2026-08-05` (OWN-ONLY **R13-007**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ machine bytes) |
| **Counterpart** | `reviews/B_aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md` |
| **System** | `input-drive-control` / CVOGHBMoveVehicleToMouse constructor |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / `get_function_callers` / `get_xrefs_to` + `read_memory` (body, vtbl, RTTI). **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

**Subclass constructor** for product class **CVOGHBMoveVehicleToMouse** (`PTR_FUN_009d5590`):

```text
// ECX = this; stack pEntity, pHostCtx; RET 8; returns this*
CVOGHBMoveVehicle_ctor(this, pEntity)   // FUN_00636bd0 — base
*this = &PTR_FUN_009d5590               // override MoveVehicle vtbl
*(this + 0x40) = pHostCtx
return this
```

RTTI `.?AVCVOGHBMoveVehicleToMouse@@` seals product English — **no** `_Inferred` suffix. Ctor role sealed by base-chain + vtbl install + return-this plate (family peer of dualed `CVOGHBMoveVehicle_ctor`).

**Not** the scalar dtor (`0x005996a0`), not complete/body (`0x00599570`), not base MoveVehicle ctor (`0x00636bd0`).

**Machine proof (`read_memory` len 32 @ entry):**

```text
0x00599550:  8B 44 24 04          mov   eax, [esp+4]      ; pEntity
0x00599554:  56                   push  esi
0x00599555:  50                   push  eax
0x00599556:  8B F1                mov   esi, ecx          ; this
0x00599558:  E8 73 D6 09 00       call  0x00636bd0        ; CVOGHBMoveVehicle_ctor
0x0059955d:  8B 4C 24 0C          mov   ecx, [esp+0xC]    ; pHostCtx
0x00599561:  C7 06 90 55 9D 00    mov   dword [esi], 009d5590
0x00599567:  89 4E 40             mov   [esi+0x40], ecx
0x0059956a:  8B C6                mov   eax, esi
0x0059956c:  5E                   pop   esi
0x0059956d:  C2 08 00             ret   8
```

Hex: `8b44240456508bf1e873d609008b4c240cc70690559d00894e408bc65ec20800`

Call target: rel32 decode → `00636bd0` (**High**).

**Calling convention:** MSVC `__thiscall` — object in **ECX**; two stack args; **`RET 8`**; **EAX = this**.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00599550_FUN_00599550.md` | R13-007 append |
| Annotated | `docs/reconstruction/raw/aa_00599550_FUN_00599550.annotated.md` | Refresh |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicleToMouse_ctor.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00599550.cpp` | Updated |
| Function FUN | `docs/reconstruction/functions/aa_00599550_FUN_00599550.md` | Updated |
| Function named | `docs/reconstruction/functions/aa_00599550_CVOGHBMoveVehicleToMouse_ctor.md` | New |
| Live decompile | Ghidra `0x00599550` | ≡ raw CF |
| Live bytes | `read_memory` | ≡ instruction map (32 B) |
| Live xrefs | 4 UNCONDITIONAL_CALL | all factories |
| RTTI | type desc `0x00af33e0` | `.?AVCVOGHBMoveVehicleToMouse@@` |
| Vtbl | `009d5590` dword0 | `005996a0` (parent dual scalar) |
| Base callee | `FUN_00636bd0` | R12-006 dualed |
| Partition | `WAVE_2026-08-05_r13_residual_partition_map.md` | R13-007 |

**Not performed:** Launcher, runtime golden, bit-exact package diff, dual of complete body `00599570` / residual vtbl tails (other VAs).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 32 B / end `0x0059956f` | **High** | bytes + next body at `00599570` |
| `this` in ECX | **High** | `MOV ESI,ECX` |
| CALL base ctor `00636bd0` first | **High** | rel32 decode |
| Install ToMouse vtbl `009d5590` | **High** | imm store |
| Store stack arg1 at `+0x40` | **High** | `MOV [ESI+0x40],ECX` |
| Always return this; RET 8 | **High** | `MOV EAX,ESI; RET 8` |
| Size 0x44 | **High** | all 4 `operator_new(0x44)` |
| Product name CVOGHBMoveVehicleToMouse | **High** | RTTI type desc |
| Ctor role (not dtor/OnHB) | **High** | body shape + callers |
| `+0x40` product type English | Open | role High (client+0xe04 world/sim) |
| Runtime / bit-exact | Open | no Launcher |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| ESI=this; push pEntity; CALL `00636bd0` | **Yes** |
| Install `009d5590`; store `+0x40` | **Yes** |
| Always return this; RET 8 | **Yes** |
| Invented branches | **None** (straight-line) |
| Decompile ≡ machine | **Yes** (`param_1[0x10]` ≡ `+0x40`) |
| Product name from RTTI | **Yes** — `.?AVCVOGHBMoveVehicleToMouse@@` |

---

## 5. Gaps

- Product English for field **`+0x40`** / `client+0xe04` object type (role sealed).
- Complete body dual `FUN_00599570` residual (other VA; not OWN).
- ToMouse-only vtbl residual slots (e.g. `0x00599680`).
- Runtime / bit-exact / differential.
- PDB method symbol beyond RTTI + ctor convention.

None of the gaps threaten CF/ABI/class-name seal for this unit.

---

## 6. Verdict

**accept-with-gaps** — subclass ctor CF/ABI/RET8/RTTI/vtbl override/`+0x40` store/size sealed. Residual: host-ctx product type English, complete body dual, runtime. Not reject. **Never Runtime Confirmed.**
