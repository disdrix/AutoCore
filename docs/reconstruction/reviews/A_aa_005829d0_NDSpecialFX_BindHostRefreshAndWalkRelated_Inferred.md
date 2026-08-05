# Review A (reconstruction fidelity): `aa_005829d0` NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005829d0` |
| **VA** | `0x005829d0`–`0x00582a10` (**65 B** / `0x41`) |
| **Canonical name** | `NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred` |
| **Ghidra name** | `FUN_005829d0` |
| **Prior scaffold alias** | `Named_CalleeOf_Drive_s_VEHICLE_EXHAUST_d_005829d0` — **too narrow** |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W24-A) |
| **Counterpart** | `reviews/B_aa_005829d0_NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred.md` |
| **System** | client-fx / NDSpecialFX host bind wrapper |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` full body; peer dual `aa_00518590` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Bind an FX session onto a host and refresh**, then **optionally walk a related object** stored at `host-0x88`:

1. MI-adjust host this via `*(host-0x8C)` / `+4` lea.
2. Call `FUN_00518590` (`NDSpecialFX_BindHostAndRefresh_Inferred`).
3. If `*(host-0x88) != 0`, call `FUN_004b7030(related, 0, 0, -1)` with **ECX = param_2** (FX).

Thin wrapper used after hardpoint expansion and other attach paths — **not** vehicle-exhaust-only.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005829d0_FUN_005829d0.md` (+ W24-A append) |
| Annotated | `docs/reconstruction/raw/aa_005829d0_FUN_005829d0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/NDSpecialFX_BindHostRefreshAndWalkRelated_Inferred.cpp` |
| Clean Ghidra | `docs/reconstruction/reconstructed-exact/FUN_005829d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005829d0_*.md` |
| Peer dual | `A/B_aa_00518590_NDSpecialFX_BindHostAndRefresh_Inferred` |
| Caller context | `aa_004ff850` ExpandVehicleHardpointSlots |
| Live | `decompile_function` `0x005829d0`; `read_memory` 128 B; `analyze_function_complete` |

**Not performed:** Launcher, runtime, full `004b7030` dual (W24-D), ledgers.

---

## 3. Signature

```c
// thiscall host; 3 stack formals; ret 0xC
void __thiscall FUN_005829d0(
    int hostThis,        // ECX
    undefined4 param_2,  // FX session/template
    undefined4 param_3,
    undefined4 param_4);
```

| Item | Evidence | Conf |
|---|---|---|
| thiscall ECX host | `8B F1` | **High** |
| 3 stack formals / `ret 0xC` | `C2 0C 00` | **High** |
| MI adjust `this-0x8C` | `8B 96 74 FF FF FF` + `8D 8C 30 74 FF FF FF` | **High** |
| Call `00518590` | rel32 from `0x005829f3` | **High** |
| Related `this-0x88` | `8B B6 78 FF FF FF` | **High** |
| Walk ECX = param_2 | `8B CF` before `004b7030` | **High** |
| Walk args related,0,0,-1 | `6A FF 6A 00 6A 00 56` | **High** |

---

## 4. Control flow (sealed)

```
host = ECX
fx   = stack[0x4]
a2   = stack[0x8]
a3   = stack[0xC]

mi = *(host - 0x8C)
ecx_bind = *(mi + 4) + host - 0x8C
push a3; push a2; push fx
call FUN_00518590  // ECX = ecx_bind

related = *(host - 0x88)
if related:
  push -1; push 0; push 0; push related
  ECX = fx
  call FUN_004b7030
ret 0xC
```

| Stage | Match | Conf |
|---|---|---|
| MI lea + BindHost call | **Yes** | **High** |
| Optional related walk | **Yes** | **High** |
| Always bind first | **Yes** (walk is second) | **High** |
| ret 0xC | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Full 65 B hex in raw W24-A append. Spot checks:

| Offset | Bytes | Decode |
|---|---|---|
| +0 | `8B 44 24 0C 56 57` | load arg3; save esi/edi |
| +0xA | `8B F1` | ESI = this |
| +0x10 | `8B 96 74 FF FF FF` | EDX = [this-0x8C] |
| +0x1C | `8D 8C 30 74 FF FF FF` | LEA ECX adjusted |
| +0x23 | `E8 98 5B F9 FF` | call `0x00518590` |
| +0x28 | `8B B6 78 FF FF FF` | related = [this-0x88] |
| +0x39 | `8B CF` | ECX = FX (edi) |
| +0x3B | `E8 20 46 F3 FF` | call `0x004b7030` |
| +0x40 | `5F 5E C2 0C 00` | epilogue |

**No `disassemble_bytes` used.**

---

## 6. Call surface

| Caller | VA / note |
|---|---|
| `FUN_004ff850` | hardpoint expand — multi sites |
| `FUN_005a9760` | additional host path |

Xrefs: **12**.

| Callee | VA / note |
|---|---|
| `FUN_00518590` | BindHostAndRefresh (peer dual sealed) |
| `FUN_004b7030` | related walk (residual / W24-D) |

---

## 7. Confidence

| Claim | Level |
|---|---|
| Wrapper CF / ABI / MI offsets | **High** |
| Role = bind + optional related walk | **High** |
| Exhaust-only | **Falsified** |
| Product English for -0x88 | **Tentative** |
| BindHost stack arity 2 vs 3-push | **Partial** |
| Runtime / bit-exact | **Open** |

---

## 8. Gaps

1. Product meaning of object at `this-0x88`.
2. Full `FUN_004b7030` semantics (not OWN this unit).
3. BindHost formal count: this site pushes **3**; peer dual lists **2**.
4. Class owner of the MI layout / vtbl that hosts this method.

**Verdict:** **accept-with-gaps** — wrapper CF and ABI sealed; related-object English and BindHost arity residual.
