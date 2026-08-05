# Review A (reconstruction fidelity): `aa_00404dc0` CVOGPhysics_SetRotation

| Field | Value |
|---|---|
| **Stable ID** | `aa_00404dc0` |
| **VA** | `0x00404dc0` |
| **Canonical name** | `CVOGPhysics_SetRotation` (inferred) |
| **Ghidra symbol** | `FUN_00404dc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00404dc0_CVOGPhysics_SetRotation.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGPhysics` helper: optional readiness prepare, then — **only when not fully ready** — forward a **rotation pointer** (typically quaternion) to the bound rigid body via **body vtbl +0x44** — **set rotation**.

Byte-identical sibling of `FUN_0040d2a0` (set position / body vtbl **+0x40**) except the final vtbl slot immediate (`0x44` vs `0x40`). Differs from `CVOGPhysics_SetAngularVelocity` (`0x0040d040`) and `ApplyImpulseVector` (`0x0040d260`) which **always** dispatch (no fully-ready skip).

No clamps, no math, no field stores of its own.

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00404dc0_FUN_00404dc0.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_00404dc0_FUN_00404dc0.annotated.md` | Updated |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGPhysics_SetRotation.cpp` | Written (CF ≡ raw) |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00404dc0.cpp` | Prior scaffold (superseded by named clean) |
| Function record | `docs/reconstruction/functions/aa_00404dc0_CVOGPhysics_SetRotation.md` | Written |
| Live decompile | Ghidra MCP `0x00404dc0` | **≡ raw** |
| Live `read_memory` | `0x00404dc0` (0x3f body) | vtbl imm **`0x44`** + fully-ready gate sealed |
| Sibling pos | `0x0040d2a0` decompile + bytes | Same CF; imm **`0x40`** |
| Ready helpers | `0x005070b0`, `0x005070d0` decompile | Probe / prepare sealed |
| Callers | Ghidra xrefs (11 sites / 10 funcs + 1 orphan site) | Network soft, airStab, camera, respawn, … |
| Prior art | `physics/verified/fn_0053eec0_networkApply.md` | Soft teleport: setRotation when not fully ready |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=`phys`, stack arg = rot ptr; `ret 4` | **High** | `C2 04 00`; ECX saved in ESI |
| Optional ready: `FUN_005070b0` out-byte; if 0 **and** `phys+0x44≠0` → `FUN_005070d0` | **High** | Decompile + instruction sequence |
| Ready probe: if `phys+0x44==0` → out=`0`; else out=`*(*(phys+0x44)+0x29)` | **High** | Live decompile of `0x5070b0` |
| **Fully-ready skip:** dispatch only if `phys+0x40==0` **OR** `phys+0x08==0` | **High** | Extra `cmp [esi+0x40]` / `cmp [esi+8]` vs angVel helpers |
| Fully-ready (`+0x40≠0` **and** `+0x08≠0`) → **no** body vtbl call | **High** | `jnz` past dispatch |
| `body = *(phys+0x3c)` | **High** | `mov ecx,[esi+0x3c]` |
| Dispatch `(**body_vtbl)[+0x44](rot)` | **High** | `call dword ptr [edx+0x44]` — imm sealed |
| Semantic: set **rotation** (not position / lin / ang) | **High** | Prior networkApply; sibling pos uses +0x40 |
| Sibling parity with `FUN_0040d2a0` setPosition | **High** | Byte-diff only final imm `44`/`40` |
| No body-null check before vtbl | **High** | No test of `+0x3c`; null → fault |
| Callers inventory (11 xrefs) | **High** (addrs) / **Probable** (English roles) | Live xrefs |
| Network soft teleport uses net rot | **High** | `FUN_0053eec0` → `FUN_00404dc0` on large pos error |
| Exact Havok method name at +0x44 | **Probable** | Industry `setRotation`; not string-proven |
| Arg layout quat xyzw | **Probable** | Callers pack 4 floats; body passthrough |
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
| `body=*(this+0x3c)`; push rot; `call [(*body)+0x44]` | Yes |
| `ret 4` thiscall | Yes |
| No invent pos / lin / ang / clamp | Yes |

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
8B 44 24 0C            mov eax, [esp+0x0c]          ; rot arg
8B 11                  mov edx, [ecx]
50                     push eax
FF 52 44               call dword [edx+0x44]        ; *** slot 0x44 ***
5E 59 C2 04 00         pop esi; pop ecx; ret 4
```

Body size **0x3f** bytes (to `ret 4` inclusive).

Sibling `0x0040d2a0` ends `FF 52 40` (slot **0x40**).  
Contrast `0x0040d040` / `0x0040d260`: **no** `+0x40`/`+0x08` gate; always `call [edx+0x54]` / `[edx+0x50]`.

---

## 5. Callers (live xrefs)

| Call site | Function | Role (Probable / High) |
|---|---|---|
| `0x0053f124` | `FUN_0053eec0` (network soft apply) | Soft teleport: snap body rot to net rot when not fully ready |
| `0x005984cc` | `VehicleAction_airStabilization` | Cleanup / orientation path after corrective impulse |
| `0x0091a80d` | `FUN_0091a5f0` (`Client_Camera_ApplyLookOffset`) | Camera look / orientation push |
| `0x00979a1a` | `ClientSpecialEvent_Respawn_Update` | Respawn pose snap (`param+0x50` phys slice) |
| `0x00917c7a` | `FUN_00917700` | Client movement / pose path |
| `0x004c3dcc` | `FUN_004c3d60` | Creature/object pose |
| `0x0059278a` | `FUN_005911b0` | — |
| `0x005d11c2` | `FUN_005d0d60` | AI / phys heading related |
| `0x005cdf26` | `FUN_005cd3b0` | — |
| `0x008124e6` | `FUN_00812360` | Net/entity apply path |
| `0x009587d8` | (site; Drive/S-style path) | Orphan-listed xref site |

---

## 6. Gaps / open

1. Exact Havok `hkRigidBody` method name for vtbl+0x44 (string / RTTI not recovered this pass).
2. Full type of `phys+0x44` and semantic name of byte `+0x29` readiness flag (shared with siblings).
3. Product English for `phys+0x40` / `phys+0x08` beyond behavioral “fully ready”.
4. Whether all callers pass unit quats; network soft path gates rot elsewhere (`FUN_00568100`) before some buffer writes — this helper does **not** re-validate.
5. Runtime CE force of fully-ready skip under live soft teleport (policy-open).

**Verdict:** **accept-with-gaps** — CF, dual gates, and vtbl slot sealed High; remaining gaps are naming/types/runtime only.
