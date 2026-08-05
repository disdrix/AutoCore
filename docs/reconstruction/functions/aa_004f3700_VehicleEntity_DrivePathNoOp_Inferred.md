# Function record: VehicleEntity_DrivePathNoOp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3700` |
| **Canonical name** | `VehicleEntity_DrivePathNoOp_Inferred` |
| **Ghidra symbol** | `FUN_004f3700` (rename optional) |
| **Aliases** | `Named_CalleeOf_Client_Input_DriveControlTick_004f3700` |
| **Address** | `0x004f3700` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Body span** | `0x004f3700` – `0x004f3700` inclusive (**1** byte; exclusive end `0x004f3701`) |
| **Calling convention** | MSVC `__thiscall` shape (`this` in `ECX` at all call sites; **no** stack args; `ret` / `c3`) |
| **Return type** | `void` |
| **System** | `input-drive-control` |
| **Completion status** | **Human-refined + dual A/B create 2026-07-29** — empty body + 4-site call graph sealed; product name / runtime open |
| **Bit-for-bit / runtime / diff** | Body sealed statically; package runtime/diff open |

---

## 1. Summary

Empty **vehicle drive-path hook**: single-byte `RET` in this image. Callers place a vehicle entity in `ECX` then `CALL` this VA — typically on handbrake-engage arms of client input / focus-loss helpers, plus one target-select path. The body performs **no** work. Name is **Inferred** (call-graph / partition “vehicle drive path”; no product string).

Live re-decompile + `read_memory` 2026-07-29 ≡ frozen raw.

---

## 2. Signature

```c
void __thiscall VehicleEntity_DrivePathNoOp_Inferred(VehicleEntity* this);
```

| Arg | Location | Type | Meaning |
|---|---|---|---|
| `this` | `ECX` | `VehicleEntity*` | Vehicle entity (set by all 4 call sites; **unread** by body) |

No stack arguments. Epilogue is plain `ret` (`c3`), not `ret 4`.

---

## 3. Behavior (exact)

### 3.1 Machine body (`read_memory` @ `0x004f3700`)

| VA | Hex | Instruction |
|---|---|---|
| `0x004f3700` | `c3` | `ret` |
| `0x004f3701+` | `cc …` | int3 padding (not in body) |

### 3.2 Pseudocode

```
return;
```

No branches. No stores. No callees. No globals.

---

## 4. Memory map

| Location | Access | Notes |
|---|---|---|
| *(none)* | — | Body is pure control transfer |

Callers commonly touch (elsewhere, not here): entity `+0x61c` handbrake via `SetHandbrake`, controller via `PushDriveAxesToController`.

---

## 5. Callers (live xrefs 2026-07-29)

**4** caller functions, **4** unconditional call sites (`get_function_callers` + `get_xrefs_to`).

| Symbol / label | Address | Call site | Notes |
|---|---|---|---|
| `Client_Input_DriveControlTick` | `0x009223b0` | `0x009235e4` | After `SetHandbrake(1)` on Brake arm; ECX = `*[world+0x250]` |
| `FUN_00915670` | `0x00915670` | `0x009156b9` | HB1 path; then `PushDriveAxes` |
| `FUN_0093a5c0` | `0x0093a5c0` | `0x0093a5ff` | Focus-loss: HB1 → this → maybe Push |
| `FUN_0093e120` | `0x0093e120` | `0x0093e20e` | Vehicle non-null; **no** HB in this arm |

---

## 6. Callees / side effects

| Item | Value |
|---|---|
| Direct callees | **None** |
| Global / static touches | **None** |
| Entity field writes | **None** |
| Exceptions / error paths | **None** |

---

## 7. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004f3700_FUN_004f3700.md` |
| Annotated | `docs/reconstruction/raw/aa_004f3700_FUN_004f3700.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_DrivePathNoOp_Inferred.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_004f3700_VehicleEntity_DrivePathNoOp_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_004f3700_VehicleEntity_DrivePathNoOp_Inferred.md` |
| Scratch | `docs/reconstruction/reviews/a_004f3700.md` |

---

## 8. Confidence

| Claim | Level |
|---|---|
| Control flow / machine body | **High** |
| Call graph (4 sites) | **High** |
| thiscall ECX = vehicle at sites | **High** |
| Parameter semantic name `this` | **High** (site shape) / body-unused |
| Product / PDB name | **Tentative** — `_Inferred` |
| Historical non-empty body in other builds | **Open** |

---

## 9. Dual verdict

**accept-with-gaps** (2026-07-29 OWN-ONLY dual A/B create).
