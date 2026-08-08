# Review A (reconstruction fidelity): `aa_00636ba0` CVOGHBMoveVehicle_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636ba0` |
| **VA** | `0x00636ba0` |
| **Body span** | `0x00636ba0`–`0x00636bbf` inclusive (**32** bytes; exclusive end `0x00636bc0` → `cc…` then ctor) |
| **Canonical name** | `CVOGHBMoveVehicle_OnEnd` |
| **Ghidra name** | `FUN_00636ba0` |
| **Review date** | `2026-08-05` (OWN-ONLY **MEGA-017**) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile ≡ machine bytes) |
| **Counterpart** | `reviews/B_aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md` |
| **System** | `input-drive-control` / heartbeat OnEnd |
| **Dual status** | **Present** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_xrefs` / `get_function_callers` + `read_memory` (body, vtbl, RTTI). **No** `disassemble_bytes`. **No** Launcher.

---

## 1. Purpose

Virtual **OnEnd** for **`CVOGHBMoveVehicle`**: when Stop disarms an armed heartbeat, park the bound vehicle entity's **steer** to **0** and **PushDriveAxes** (thr/HB bridge). Steer-only — not a full thr0/HB1 stop pack.

**Machine proof (`read_memory` len 48 @ entry):**

```text
0x00636ba0:  56                   push  esi
0x00636ba1:  8B F1                mov   esi, ecx
0x00636ba3:  8B 4E 24             mov   ecx, [esi+0x24]
0x00636ba6:  85 C9                test  ecx, ecx
0x00636ba8:  74 0F                jz    0x00636bb9
0x00636baa:  6A 00                push  0
0x00636bac:  E8 6F EA EB FF       call  0x004f5620   ; SetSteerInput
0x00636bb1:  8B 4E 24             mov   ecx, [esi+0x24]
0x00636bb4:  E8 57 50 EC FF       call  0x004fbc10   ; PushDriveAxes
0x00636bb9:  8B CE                mov   ecx, esi
0x00636bbb:  5E                   pop   esi
0x00636bbc:  E9 1F 16 ED FF       jmp   0x005081e0   ; empty C3
```

Hex: `568bf18b4e2485c9740f6a00e86feaebff8b4e24e85750ecff8bce5ee91f16edff`

Call targets: rel32 decode → `004f5620`, `004fbc10`, `005081e0` (**High**).

**Calling convention:** MSVC `__thiscall` — HB object in **ECX**; no stack args; empty-ret tail.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00636ba0_FUN_00636ba0.md` | MEGA-017 append |
| Annotated | `docs/reconstruction/raw/aa_00636ba0_FUN_00636ba0.annotated.md` | Refresh |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGHBMoveVehicle_OnEnd.cpp` | New |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00636ba0.cpp` | Updated |
| Function FUN | `docs/reconstruction/functions/aa_00636ba0_FUN_00636ba0.md` | Updated |
| Function named | `docs/reconstruction/functions/aa_00636ba0_CVOGHBMoveVehicle_OnEnd.md` | New |
| Live decompile | Ghidra `0x00636ba0` | if/call ≡ raw; **tail omitted** |
| Live bytes | `read_memory` | ≡ instruction map |
| Live xrefs | DATA `009e3b80` / `009d55a0` only | no code callers |
| RTTI | type desc `0x00af33c0` | `.?AVCVOGHBMoveVehicle@@` |
| Ctor context | `FUN_00636bd0` | entity → `+0x24` |
| Fire context | `FUN_00636cc0` | Stop on MoveTo fail |
| Callee duals | SetSteer / Push / Stop | sealed siblings |
| Partition | `WAVE_2026-08-05_mega_residual_partition_map.md` | MEGA-017 |

**Not performed:** Launcher, runtime golden, bit-exact package diff, dual of full class (ctor/fire OWN residual).

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 32 B / end `0x00636bbf` | **High** | bytes + next `cc` / ctor `00636bd0` |
| `this` in ECX | **High** | `MOV ESI,ECX` |
| Gate on `[this+0x24] != 0` | **High** | TEST/JZ |
| Call SetSteerInput with arg 0 | **High** | PUSH 0 + call target |
| Call PushDriveAxes on same entity | **High** | reload ECX from +0x24 |
| No thr0 / HB1 in this body | **High** | only two callees |
| Tail JMP empty `005081e0` | **High** | bytes + `c3` |
| Decompiler missed tail | **High** | live decompile shows bare return |
| OnEnd = vtbl+0x10 | **High** | DATA slots + Stop convention |
| RTTI class name | **High** | type descriptor |
| Shared with ToMouse subclass | **High** | same pointer at `009d55a0` |
| No direct code callers | **High** | callers empty; DATA only |
| `+0x24` = vehicle entity | **High** | ctor + callee ABI |
| Product method name string "OnEnd" | **Probable** | convention not PDB |
| Runtime / bit-exact | **Open** | deferred |

---

## 4. Control flow: clean ≡ raw ≡ live decompile ≡ bytes

| Stage | Match |
|---|---|
| Load entity `this+0x24` | **Yes** |
| Null skip | **Yes** |
| SetSteer(0) | **Yes** |
| PushDriveAxes | **Yes** |
| No thr/HB mutation in-body | **Yes** |
| Empty-ret tail | **Yes** (bytes/clean; decompiler gap noted) |
| No invent full stop pack | **Yes** |

### 4.1 Contrast: AI full park (not this unit)

| API | Steer0 | Long0 | HB1 | Push |
|---|---|---|---|---|
| **`CVOGHBMoveVehicle_OnEnd`** | yes | no | no | yes |
| residual `FUN_005d73a0` | yes | yes | yes | yes |

### 4.2 Dispatch chain (evidence only)

```text
CVOGHBBase_Stop (0x005081d0)
  └─ jmp [vtbl+0x10]  →  CVOGHBMoveVehicle_OnEnd (this)

FUN_00636cc0 (fire)
  └─ MoveToTarget fail → CVOGHBBase_Stop → this OnEnd
```

---

## 5. Gaps (honest)

1. Runtime / CE under live Stop after MoveToTarget.
2. Full `CVOGHBMoveVehicle` class dual (ctor `00636bd0`, fire `00636cc0`) residual — not OWN.
3. Empty leaf `005081e0` formal English name.
4. PDB method symbol beyond RTTI class + OnEnd slot convention.

---

## 6. Verdict

**accept-with-gaps** — fidelity of CF, ABI, RTTI class, vtbl OnEnd role, steer-only park, and dualed callees is sealed. Gaps are runtime and residual class duals only; not CF contradictions.

Path A does **not** claim runtime Confirmed. Terminal: **false**.
