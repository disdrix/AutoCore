# Review A (reconstruction fidelity): `aa_0040d040` CVOGPhysics_SetAngularVelocity

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d040` |
| **VA** | `0x0040d040` |
| **Canonical name** | `CVOGPhysics_SetAngularVelocity` (inferred) |
| **Ghidra symbol** | `FUN_0040d040` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0040d040_CVOGPhysics_SetAngularVelocity.md` |
| **System** | `physics` / callee of `input-drive-control` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGPhysics` helper: optional readiness prepare, then forward a **vector pointer** to the bound rigid body via **body vtbl +0x54** — **set angular velocity** (sibling of `CVOGPhysics_ApplyImpulseVector` @ `0x0040d260`, which uses **vtbl +0x50** for linear).

Body is **byte-identical** to ApplyImpulseVector except the final vtbl slot immediate (`0x54` vs `0x50`). No clamps, no math, no other stores.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d040_FUN_0040d040.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_0040d040_FUN_0040d040.annotated.md` | Updated |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysics_SetAngularVelocity.cpp` | Written (CF ≡ raw) |
| Named alias clean | `reconstructed-exact/Named_CalleeOf_Client_Input_DriveControlTick_0040d040.cpp` | Prior scaffold |
| Function record | `docs/reconstruction/functions/aa_0040d040_CVOGPhysics_SetAngularVelocity.md` | Updated |
| Live decompile | Ghidra MCP `0x0040d040` | **≡ raw** |
| Live `read_memory` | `0x0040d040` (0x30 body) | vtbl imm **`0x54`** sealed |
| Sibling | `0x0040d260` decompile + bytes | Same CF; imm **`0x50`** |
| Ready helpers | `0x005070b0`, `0x005070d0` decompile + bytes | Probe / prepare sealed |
| Callers | Ghidra xrefs (8 sites / 7 funcs) | DriveControlTick, network soft, airStab, AI, … |
| Prior art | `physics/verified/fn_0053eec0_networkApply.md`, `fn_0064d810_avd.md`, `fn_offsets_rigidbody.md` | ω write slot +0x54 |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=`phys`, stack arg = vec ptr | **High** | `ret 4`; ECX saved in ESI |
| Optional ready: `FUN_005070b0` out-byte; if 0 **and** `phys+0x44≠0` → `FUN_005070d0` | **High** | Decompile + instruction sequence |
| Ready probe: if `phys+0x44==0` → out=`0`; else out=`*(*(phys+0x44)+0x29)` | **High** | `read_memory` of `0x5070b0` |
| `body = *(phys+0x3c)` | **High** | `mov ecx,[esi+0x3c]` |
| Dispatch `(**body_vtbl)[+0x54](vec)` | **High** | `call dword ptr [edx+0x54]` — imm sealed |
| Semantic: set **angular** velocity (not linear) | **High** | Prior AVD/network/airStab; sibling linear uses +0x50 |
| Sibling parity with ApplyImpulseVector | **High** | Byte-diff only final imm `54`/`50` |
| No body-null check before vtbl | **High** | No test of `+0x3c`; null → fault |
| Callers inventory (8 sites) | **High** (addrs) / **Probable** (English roles) | Live xrefs |
| DCT zero-vec clears ω under mode gate | **High** (call site CF) | Zero pack `fStack_a0..94` then call |
| Network soft teleport uses net angVel | **High** | `FUN_0053eec0` → `FUN_0040d040(param_5)` |
| airStab cleanup zeros via `DAT_00b04eb0` | **High** | Verified airStab note |
| Exact Havok method name at +0x54 | **Probable** | Industry `setAngularVelocity`; not string-proven |
| `phys+0x44` object type / +0x29 flag name | **Tentative** | Behavior sealed; type open |
| Vec layout f3 vs f4 | **Probable** (f4 pack at callers) | Callers pack 4 floats; body passthrough |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| Save `this` in ESI | Yes |
| Out-byte on stack → `FUN_005070b0(this, &out)` | Yes (decompiler `uStack_4` artifact; asm `lea [esp+7]`) |
| If `*out==0` and `*(this+0x44)!=0` → `FUN_005070d0(this)` | Yes |
| `body=*(this+0x3c)`; push vec; `call [(*body)+0x54]` | Yes |
| `ret 4` thiscall | Yes |
| No invent linear / pos / rot / clamp | Yes |

### Instruction seal (`read_memory` 2026-07-29)

```text
51 56                  push ecx / push esi
8D 44 24 07 50         lea eax,[esp+7]; push eax   ; out-byte*
8B F1                  mov esi, ecx                 ; this
E8 .. .. .. ..         call FUN_005070b0
80 38 00               cmp byte [eax], 0
75 0D                  jnz skip_prepare
83 7E 44 00            cmp dword [esi+0x44], 0
74 07                  jz skip_prepare
8B CE                  mov ecx, esi
E8 .. .. .. ..         call FUN_005070d0
8B 4E 3C               mov ecx, [esi+0x3c]          ; body
8B 44 24 0C            mov eax, [esp+0x0c]          ; vec arg
8B 11                  mov edx, [ecx]
50                     push eax
FF 52 54               call dword [edx+0x54]        ; *** slot 0x54 ***
5E 59 C2 04 00         pop esi; pop ecx; ret 4
```

Body size **0x30** bytes (to `ret 4` inclusive).

Sibling `0x0040d260` ends `FF 52 50` (slot **0x50**).

---

## 5. Callers (live xrefs)

| Call site | Function | Role (Probable / High) |
|---|---|---|
| `0x00922653` | `Client_Input_DriveControlTick` | Zero angVel under foot/mode gate (`DAT_00d1b6d8[2]≠0`, flag chain) |
| `0x0053f12d` | `FUN_0053eec0` (network soft apply) | Soft teleport: snap body ω to net angVel |
| `0x005984dc` | `VehicleAction_airStabilization` | Cleanup zero ω (`DAT_00b04eb0`) after corrective impulse |
| `0x005d0a99` | `CVOGHBAICreatureBase_DecideHeading` | AI heading / orientation path |
| `0x005d108b` | `FUN_005d0d60` | (related AI/phys path) |
| `0x005cdf36`, `0x005ce1e1` | `FUN_005cd3b0` | Two sites |
| `0x005dadcc` | `FUN_005dac00` | — |

---

## 6. Gaps / open

1. Exact Havok `hkRigidBody` method name for vtbl+0x54 (string / RTTI not recovered this pass).
2. Full type of `phys+0x44` and semantic name of byte `+0x29` readiness flag.
3. Null-body / unready crash policy at runtime (static: no null check on `+0x3c`).
4. Whether +0x54 is pure set vs add-angular-impulse (caller packs absolute ω; AVD rewrites full ω).
5. DriveControlTick gate English names (mode / on-foot / component flags) — parent unit residual.

**Verdict:** **accept-with-gaps** — dual **CF + vtbl imm + sibling parity + readiness gate + callers** sealed; package **not complete** (Havok name, type recovery, runtime).
