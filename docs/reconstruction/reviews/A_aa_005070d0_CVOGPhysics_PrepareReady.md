# Review A (reconstruction fidelity): `aa_005070d0` CVOGPhysics_PrepareReady

| Field | Value |
|---|---|
| **Stable ID** | `aa_005070d0` |
| **VA** | `0x005070d0` |
| **Canonical name** | `CVOGPhysics_PrepareReady` (inferred) |
| **Ghidra symbol** | `FUN_005070d0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005070d0_CVOGPhysics_PrepareReady.md` |
| **System** | `physics` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

`CVOGPhysics` **prepare / ensure-ready** helper. Called by the standard readiness gate:

```text
out = FUN_005070b0(phys, &byte);   // probe host+0x29 (0 if phys+0x44 null)
if (*out == 0 && *(phys+0x44) != 0)
    FUN_005070d0(phys);            // THIS UNIT
// then body vtbl write (lin vel / ang vel / impulse / pos …)
```

Body activates the host object at `phys+0x44` into the simulation context at `phys+8` and sets readiness flag `host+0x29 = 1` (via callee). **No math, no rigid-body field writes, no vtbl on `phys+0x3c`.**

Sibling probe: `FUN_005070b0` @ `0x005070b0` (read-only flag fetch).

---

## 2. Inspected artifacts

| Artifact | Path | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005070d0_FUN_005070d0.md` | Append live seal § |
| Annotated | `docs/reconstruction/raw/aa_005070d0_FUN_005070d0.annotated.md` | Updated |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005070d0.cpp` | Updated (asm-correct ABI) |
| Named clean | `reconstructed-exact/CVOGPhysics_PrepareReady.cpp` | Written |
| Function record | `docs/reconstruction/functions/aa_005070d0_CVOGPhysics_PrepareReady.md` | Written |
| Live decompile | Ghidra MCP `0x005070d0` | ≡ raw CF shape |
| Live `read_memory` | `0x005070d0` body **0x2A** bytes through `ret` | ABI sealed |
| Callee prologues | `0x0055e490`, `0x0055eb80` entry + decompile | Interface only (not dualed) |
| Sibling probe | `0x005070b0` decompile + bytes | Ready-byte contract sealed |
| Callers | Ghidra xrefs (**64** sites, 2 pages) | Gate pattern everywhere |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `thiscall` ECX=`phys` (`CVOGPhysics*`); `ret` / no stack args | **High** | `push esi; mov esi,ecx; …; pop esi; ret` |
| Early out if `*(phys+8)==0` | **High** | `mov ecx,[esi+8]; test ecx; jz` |
| `phys+8` = simulation / island / world-like context used as **callee `this`** | **High** (structural) / **Probable** (English) | Both callees receive ECX=`*(phys+8)` |
| First callee: `FUN_0055e490(world=*(phys+8), arg=phys)` | **High** (ABI) | `push esi; call` with ECX already world |
| Second gate: `host=*(phys+0x44)`; if `*(u8*)(host+0x29)==0` **and** `*(i32*)(host+0x24)!=-1` → activate | **High** | Sealed immediates `+0x29`, `+0x24`, cmp `-1` |
| Second callee: `FUN_0055eb80(world=*(phys+8), host)` | **High** (ABI) | `mov ecx,[esi+8]; push eax; call` |
| `FUN_0055eb80` sets `host+0x29=1` (ready) | **High** | Callee decompile store; matches probe |
| `FUN_0055eb80` inserts host into world active list / index tables | **High** (CF) / **Probable** (names) | Array grow + index swap at world+8/+0xc/+0x14/+0x18 |
| No null check on `phys+0x44` inside this unit | **High** | Direct `mov eax,[esi+0x44]` then `cmp [eax+0x29]` |
| Callers almost always pre-gate `+0x44≠0` via probe path | **High** | Sibling duals (SetAngularVelocity, ApplyImpulseVector, …) |
| Not a profiler stub | **High** | Real list activate + flag write in callee |
| Not a dirty-bit only flip on `phys` itself | **High** | Flag lives on **host** `+0x44`, not on `phys` header |
| Ghidra decompile of **this** unit drops callee `this` (shows `FUN_0055e490(param_1)` / `FUN_0055eb80(iVar1)`) | **High** (artifact) | Asm overrides; clean corrected |
| Exact type names for `phys+8` / `phys+0x44` | **Tentative** | Behavior sealed; RTTI/strings open |
| English role of `FUN_0055e490` (list remove / un-defer / refcount) | **Probable** | Callee CF only; not dualed deep |
| Full caller inventory English roles | **Probable** | 64 sites; sampled high-value named parents |

---

## 4. Control flow: clean ≡ instructions (decompiler shape corrected)

| Stage | Match |
|---|---|
| Save `this` in ESI | Yes |
| `world = *(this+8)`; if null → return | Yes |
| `FUN_0055e490(world, this)` | Yes (decompiler under-stated arity/`this`) |
| `host = *(this+0x44)` (unchecked) | Yes |
| If `host+0x29≠0` → skip activate | Yes |
| If `host+0x24==-1` → skip activate | Yes |
| Else `FUN_0055eb80(world, host)` | Yes |
| `ret` (no stack cleanup; 0 args) | Yes |
| No invent math / body vtbl / pos-rot writes | Yes |

### Instruction seal (`read_memory` 2026-07-29)

```text
005070d0  56                push esi
005070d1  8B F1             mov  esi, ecx              ; this = phys
005070d3  8B 4E 08          mov  ecx, [esi+0x8]        ; world
005070d6  85 C9             test ecx, ecx
005070d8  74 1E             jz   loc_ret               ; +0x1E → 005070f8
005070da  56                push esi                   ; arg0 = phys
005070db  E8 B0 73 05 00    call FUN_0055e490          ; thiscall ECX=world
005070e0  8B 46 44          mov  eax, [esi+0x44]       ; host
005070e3  80 78 29 00       cmp  byte ptr [eax+0x29], 0
005070e7  75 0F             jnz  loc_ret
005070e9  83 78 24 FF       cmp  dword ptr [eax+0x24], -1
005070ed  74 09             jz   loc_ret
005070ef  8B 4E 08          mov  ecx, [esi+0x8]        ; world again
005070f2  50                push eax                   ; arg0 = host
005070f3  E8 88 7A 05 00    call FUN_0055eb80          ; thiscall ECX=world
005070f8  5E                pop  esi
005070f9  C3                ret
```

Body size **0x2A** bytes (`0x005070d0`..`0x005070f9` inclusive). Padding `CC` follows.

Call targets (rel32 from next-IP):

| Site | rel32 | Target |
|---|---|---|
| `0x005070db` | `+0x000573B0` | `0x0055e490` |
| `0x005070f3` | `+0x00057A88` | `0x0055eb80` |

---

## 5. Sibling probe contract (`FUN_005070b0` @ `0x005070b0`) — boundary only

```text
// thiscall phys, stack: out_byte*
if (*(phys+0x44) == 0)  *out = 0;
else                    *out = *(u8*)(*(phys+0x44) + 0x29);
ret 4
```

Bytes sealed: `8B 41 44 85 C0 75 0A … C6 00 00 C2 04 00` / `8A 48 29 … 88 08 C2 04 00`.

**Pairing:** probe returns 0 when host null **or** ready flag clear → callers optionally invoke prepare when host non-null.

---

## 6. Callee contracts (interface only — not dual-owned)

### `FUN_0055e490(world, phys)` @ `0x0055e490`

- Prologue uses `ECX` as `this` (`mov esi,ecx`), loads stack arg as search key.
- Decompile: walk `world+0x108` length `world+0x10c`; if entry == arg, swap-remove, dec `*(i16*)(arg+6)`, destroy if refcount hits 0.
- **Role (Probable):** remove `phys` from a world-side pending/owned pointer list (often no-op if not present). Not expanded in this dual.

### `FUN_0055eb80(world, host)` @ `0x0055eb80`

- Prologue `mov edi,ecx`; stack arg → host.
- Decompile (High CF):
  - Grow list at `world+8` if `count==capacity` (mask `0x7fffffff`).
  - Push `host` onto active ptr array; bump count at `world+0xc`.
  - Free-list / index table shuffle using `host+0x24` as slot index.
  - `*(host+0x24) = new_index`; **`*(u8*)(host+0x29) = 1`**; clear `host+0x34/0x38`; call `FUN_0062a6c0(world, host)`; `*(host+0x30)=0`.
- **Role (High):** **activate host into world** and mark ready — this is the prepare payload.

---

## 7. Callers (live xrefs, page-complete)

**≥64** unconditional call sites. Representative named parents (not exhaustive roles):

| Call site(s) | Function | Role (Probable / High) |
|---|---|---|
| `0x0040d05b` | `FUN_0040d040` / SetAngularVelocity | Ready gate before body vtbl +0x54 |
| `0x0040d27b` | `CVOGPhysics_ApplyImpulseVector` | Ready gate before vtbl +0x50 |
| `0x00404ccb` | `FUN_00404cb0` ApplyVector vtbl+0x5c | Same gate pattern |
| `0x0040d2bb` | `FUN_0040d2a0` | Position/related physics write helper |
| `0x0053ef37` | `FUN_0053eec0` network soft apply | Soft teleport readiness |
| `0x0053d7ba` | `CVOGReaction_TeleportTarget` | Teleport path |
| `0x0059853e`, `0x0059856f`, `0x00598620` | `VehicleAction_airStabilization` | airStab write enable |
| `0x00598885` | `VehicleAction_applyAction` | Action apply |
| `0x0064bf6f`, `0x0064c01e` | `hkVehicleFramework_postTickApplyForces` | Post-tick force apply |
| `0x0064d8da` | `hkAngularVelocityDamper_update` | AVD path |
| `0x005d0d1c` | `CVOGHBAICreatureBase_DecideHeading` | AI phys write |
| many `0x0053d*`, `0x005d*`, `0x0064*`, `0x0066*`, `0x0091*` | misc reaction / vehicle / client | Shared gate |

**Pattern:** prepare is a **shared write-enable**, not domain-specific logic.

---

## 8. Gaps / open

1. Exact C++ type of `phys+8` (island / `hkWorld` wrapper / custom sim) and `phys+0x44` (host / phantom / action body).
2. Deep dual of `FUN_0055e490` / `FUN_0055eb80` / `FUN_0062a6c0` (list algorithms, edge cases).
3. Semantic name of `host+0x24` index (`-1` = not in free/active pool?).
4. Runtime policy when `phys+8!=0` but `phys+0x44==0` (static: would fault if second stage reached; callers usually prevent).
5. Whether `FUN_0055e490` ever fires on the hot vehicle tick path (list hit rate).

**Verdict:** **accept-with-gaps** — **own-body CF + both call ABIs + ready-flag side effect + probe pairing + caller surface** sealed; package incomplete only on type names and deep callee duals.
