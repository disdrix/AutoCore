# Review A (reconstruction fidelity): `aa_0040d2a0` CVOGPhysics_SetPosition

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040d2a0` |
| **VA** | `0x0040d2a0` |
| **Canonical name** | `CVOGPhysics_SetPosition` (inferred) |
| **Ghidra symbol** | `FUN_0040d2a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_0040d2a0_CVOGPhysics_SetPosition.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGPhysics` helper: optional readiness prepare, then — **only when not fully ready** — forward a **position pointer** (typically xyzw) to the bound rigid body via **body vtbl +0x40** — **set position**.

Byte-identical sibling of `FUN_00404dc0` / `CVOGPhysics_SetRotation` except the final vtbl slot immediate (`0x40` vs `0x44`). Differs from `CVOGPhysics_SetAngularVelocity` (`0x0040d040`) and `ApplyImpulseVector` (`0x0040d260`), which **always** dispatch (no fully-ready skip).

No clamps, no math, no field stores of its own.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_0040d2a0_FUN_0040d2a0.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_0040d2a0_FUN_0040d2a0.annotated.md` | Scaffold notes |
| Clean scaffold | `docs/reconstruction/reconstructed-exact/FUN_0040d2a0.cpp` | CF ≡ raw |
| Named alias | `reconstructed-exact/Named_CalleeOf_Named_VOG_DEBUG_STOP_0040d2a0.cpp` | Prior scaffold |
| Function record | `docs/reconstruction/functions/aa_0040d2a0_FUN_0040d2a0.md` | Scaffold |
| Live decompile | Ghidra MCP `0x0040d2a0` | **≡ raw** |
| Live `read_memory` | `0x0040d2a0` (0x3f body + pad) | vtbl imm **`0x40`** + dual gates sealed |
| Sibling rot | `0x00404dc0` dual A/B | Same CF; imm **`0x44`** |
| Ready helpers | `0x005070b0`, `0x005070d0` duals | Probe / prepare sealed |
| Callers | Ghidra xrefs (9 funcs) | Network soft, activate, AI, … |
| Prior art | `physics/verified/fn_0053eec0_networkApply.md` | Soft teleport: setPosition when not fully ready |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=`phys`, stack arg = pos ptr; `ret 4` | **High** | `C2 04 00`; ECX saved in ESI |
| Optional ready: `FUN_005070b0` out-byte; if 0 **and** `phys+0x44≠0` → `FUN_005070d0` | **High** | Decompile + instruction sequence |
| Ready probe: if `phys+0x44==0` → out=`0`; else out=`*(*(phys+0x44)+0x29)` | **High** | Sibling dual of `0x5070b0` |
| **Fully-ready skip:** dispatch only if `phys+0x40==0` **OR** `phys+0x08==0` | **High** | Extra `cmp [esi+0x40]` / `cmp [esi+8]` vs angVel helpers |
| Fully-ready (`+0x40≠0` **and** `+0x08≠0`) → **no** body vtbl call | **High** | `jnz` past dispatch |
| `body = *(phys+0x3c)` | **High** | `mov ecx,[esi+0x3c]` |
| Dispatch `(**body_vtbl)[+0x40](pos)` | **High** | `call dword ptr [edx+0x40]` — imm sealed |
| Semantic: set **position** (not rotation / lin / ang) | **High** | networkApply table; sibling rot uses +0x44 |
| Sibling parity with `FUN_00404dc0` setRotation | **High** | Byte-diff only final imm `40`/`44` |
| No body-null check before vtbl | **High** | No test of `+0x3c`; null → fault |
| Callers inventory (9 funcs) | **High** (addrs) / **Probable** (English roles) | Live xrefs |
| Network soft teleport uses net pos | **High** | `FUN_0053eec0` → `FUN_0040d2a0` on large pos error |
| Exact Havok method name at +0x40 | **Probable** | Industry `setPosition`; not string-proven |
| Arg layout f3 vs f4 | **Probable** | Callers pack 4 floats; body passthrough |
| `phys+0x40` / `+0x08` English “fully ready” | **High** (behavioral) / **Probable** (name) | Matches networkApply soft/hard gate |

---

## 4. Control flow: clean ≡ raw ≡ instructions

| Stage | Match |
|---|---|
| Save `this` in ESI | Yes |
| Out-byte on stack → `FUN_005070b0(this, &out)` | Yes (decompiler `uStack_4` artifact; asm `lea [esp+7]`) |
| If `*out==0` and `*(this+0x44)!=0` → `FUN_005070d0(this)` | Yes |
| If `*(this+0x40)==0` **or** `*(this+0x08)==0` → body dispatch | Yes |
| Else (fully ready) → skip body call | Yes |
| `body=*(this+0x3c)`; push pos; `call [(*body)+0x40]` | Yes |
| `ret 4` thiscall | Yes |
| No invent rot / lin / ang / clamp | Yes |

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
80 7E 40 00            cmp byte [esi+0x40], 0       ; fully-ready gate
74 06                  jz do_call                   ; +0x40==0 → call
83 7E 08 00            cmp dword [esi+0x08], 0
75 0D                  jnz skip_call                ; +0x40≠0 && +0x08≠0 → skip
8B 4E 3C               mov ecx, [esi+0x3c]          ; body
8B 44 24 0C            mov eax, [esp+0x0c]          ; pos arg
8B 11                  mov edx, [ecx]
50                     push eax
FF 52 40               call dword [edx+0x40]        ; *** slot 0x40 ***
5E 59 C2 04 00         pop esi; pop ecx; ret 4
```

Body size **0x3f** bytes to `ret 4` inclusive (`CC` pad follows).

Sibling `0x00404dc0` ends `FF 52 44` (slot **0x44**).

---

## 5. Callers (live xrefs)

| Function | Role (Probable / High) |
|---|---|
| `FUN_0053eec0` (network soft apply) | Soft teleport: snap body pos when ‖Δpos‖ > 15 |
| `Vehicle_ActivateEnterWorld` @ `0x00503f30` | Enter-world pose write |
| `FUN_004f2930`, `FUN_004fb370` | Vehicle / create helpers |
| `FUN_004c5700`, `FUN_0053e600` | Related phys / entity paths |
| `FUN_005911b0`, `FUN_005cd3b0`, `FUN_005e9ef0` | AI / placement / misc |

---

## 6. Gaps / open

1. Exact Havok `hkRigidBody` method name for vtbl+0x40 (string / RTTI not recovered this pass).
2. Full type of `phys+0x44` and semantic name of byte `+0x29` readiness flag.
3. Null-body / unready crash policy at runtime (static: no null check on `+0x3c`).
4. Whether any caller packs only xyz (w undefined) vs full f4.
5. Product / PDB mangled name (Ghidra still `FUN_0040d2a0`).

**Verdict:** **accept-with-gaps** — dual **CF + vtbl imm + fully-ready skip + readiness gate + sibling parity + callers** sealed; package **not complete** (Havok name, type recovery, runtime).
