# Review A (reconstruction fidelity): `aa_004f3700` VehicleEntity_DrivePathNoOp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f3700` |
| **VA** | `0x004f3700` |
| **Body span** | `0x004f3700` – `0x004f3700` inclusive (**1** byte; exclusive end `0x004f3701`) |
| **Canonical name** | `VehicleEntity_DrivePathNoOp_Inferred` |
| **Prior / alias** | `FUN_004f3700`; `Named_CalleeOf_Client_Input_DriveControlTick_004f3700` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_004f3700_VehicleEntity_DrivePathNoOp_Inferred.md` |
| **Scratch** | `reviews/a_004f3700.md` |
| **System** | `input-drive-control` |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Empty vehicle drive-path hook** — a single-byte `RET` no-op in this retail image.

All live call sites load a **vehicle entity** into `ECX` and `CALL 0x004f3700` (MSVC `__thiscall` shape with **zero stack args**). The body does **not** read `ECX`, write memory, or call anything. Residual product intent (stripped notify / debug / future hook) is **not** recoverable from this binary; name is **Inferred** from call-graph placement on the drive path (not from a string/RTTI).

**Machine proof (`read_memory` + `disassemble_function`):**

```text
0x004f3700:  c3    ret
0x004f3701+: cc…  int3 padding (not in body)
```

**Live decompile (`force_decompile` 2026-07-29):**

```c
void FUN_004f3700(void)
{
  return;
}
```

≡ frozen raw.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_004f3700_FUN_004f3700.md` | Append re-verify only (body frozen) |
| Annotated | `docs/reconstruction/raw/aa_004f3700_FUN_004f3700.annotated.md` | Machine bytes + callers |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleEntity_DrivePathNoOp_Inferred.cpp` | Named plate |
| Alias clean | `docs/reconstruction/reconstructed-exact/FUN_004f3700.cpp` | Points at same contract |
| Named scaffold | `…/Named_CalleeOf_Client_Input_DriveControlTick_004f3700.cpp` | Parent-seed alias kept |
| Function record | `docs/reconstruction/functions/aa_004f3700_VehicleEntity_DrivePathNoOp_Inferred.md` | Full dual seal |
| Live decompile | Ghidra MCP `0x004f3700` + force | **≡ raw empty return** |
| Live bytes | `read_memory` @ `0x004f3700` / `0x004f36f0` | **`c3` then `cc` pad** |
| Live xrefs | `get_xrefs_to` / `get_function_callers` | **4** sites / **4** functions |
| Call-site asm | `get_assembly_context` | ECX = vehicle before each CALL |
| Parent | `Client_Input_DriveControlTick` `0x009223b0` | Post-`SetHandbrake(1)` arm |
| Siblings | `SetHandbrake` `0x004f3620`, `PushDriveAxes` `0x004fbc10` | Cluster context only |

**Not performed:** Launcher, runtime golden, package bit-exact, product rename in Ghidra.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body is pure `ret` (1 byte `c3`) | **High** | `read_memory` + disassemble + decompile |
| No stores / no callees / no stack args | **High** | Empty body; `ret` not `ret N` |
| Call sites pass vehicle in `ECX` (thiscall shape) | **High** | Asm context at all 4 sites |
| Body **ignores** `this` | **High** | No register/memory use |
| **4** unconditional callers | **High** | Live xrefs sealed |
| Primary local: DriveControlTick after HB engage | **High** | `0x009235e4` after `SetHandbrake(1)` + optional `FUN_005081d0` |
| `FUN_00915670` / `FUN_0093a5c0` also HB1 → this → often Push | **High** | Live decompile of callers |
| `FUN_0093e120` also calls without HB arm | **High** | Vehicle non-null only; selection path |
| Not thr/steer/HB setter | **High** | Contrast `+0x614/+0x618/+0x61c` siblings |
| Not `PushDriveAxes` / no controller write | **High** | Empty; Push is separate callee at callers |
| Product English / original symbol | **Open** | No string; `_Inferred` required |
| Why retail left a CALL to empty ret | **Open** | Stripped hook hypothesis only |

---

## 4. Control flow: clean ≡ raw ≡ bytes

| Stage | Match |
|---|---|
| single `return;` | Yes |
| No invent stores / gates / clamps | Yes |
| No invent stack args / `ret 4` | Yes (`c3` only) |
| Call-graph only at dual (not invented body work) | Yes |

---

## 5. Callers (own VA xrefs only)

| Caller | Call site | Pre-call ECX | Context (caller CF, not this body) |
|---|---|---|---|
| `Client_Input_DriveControlTick` | `0x009235e4` | `*[DAT_00d1b6d8 + 0x250]` vehicle | Brake held → `SetHandbrake(1)` → optional HB `FUN_005081d0` → **this** → clear fire latch |
| `FUN_00915670` | `0x009156b9` | vehicle (`ESI`) | Gate `vehicle+0x101==0`; HB1 → this → `PushDriveAxes` |
| `FUN_0093a5c0` | `0x0093a5ff` | vehicle (`EDI` from `+0x250`) | Focus-loss arm: HB1 → this → maybe Push if `+0x101==0` |
| `FUN_0093e120` | `0x0093e20e` | vehicle from `client+0xe98 → +0x250` | Target-select path; call iff vehicle non-null; **no** SetHandbrake in arm |

---

## 6. Gaps / open

1. Runtime / live differential (matrix policy) — empty body still callable.
2. Package-level bit-exact beyond sealed 1-byte body.
3. Original PDB / product name (leave `_Inferred`).
4. Why `FUN_0093e120` shares this hook without HB engage (shared empty notify?).
5. Optional Ghidra rename to match canonical.

**Verdict:** **accept-with-gaps** — machine body + thiscall shape + **4**-site call graph sealed; product name / historical intent / runtime remain open. Package **not complete**.
