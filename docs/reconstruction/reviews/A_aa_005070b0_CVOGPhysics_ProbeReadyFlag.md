# Review A (reconstruction fidelity): `aa_005070b0` CVOGPhysics_ProbeReadyFlag

| Field | Value |
|---|---|
| **Stable ID** | `aa_005070b0` |
| **VA** | `0x005070b0`–`0x005070cc` |
| **Body span** | 28 B (`0x1C`) through second `RET 4` (pad `CC` after) |
| **Canonical name** | `CVOGPhysics_ProbeReadyFlag` (inferred; Ghidra still `FUN_005070b0`) |
| **Ghidra symbol** | `FUN_005070b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction fidelity (OWN-ONLY dual; physics ready probe) |
| **Counterpart** | `reviews/B_aa_005070b0_CVOGPhysics_ProbeReadyFlag.md` |
| **System** | `physics` / `CVOGPhysics` readiness gate |
| **Dual status** | **Present (first full dual)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Tiny **thiscall readiness probe** used by CVOGPhysics write helpers (set angVel, apply impulse/vector, position dirty gates, vehicle component paths):

* If `this+0x44 == null` → write **`0`** into the out-byte.
* Else → copy **one byte** from `*( *(this+0x44) + 0x29 )` into the out-byte.

No prepare, no vtbl, no math, no other stores. Sibling prepare path is **`FUN_005070d0`** (out of OWN-ONLY scope) and is only invoked by *callers* when this probe returns 0 **and** `this+0x44 ≠ 0`.

Product English for the host object at `+0x44` and the flag at host `+0x29` is **not** string-sealed — only the load/store CF is **High**.

---

## 2. Inspected artifacts / evidence (OWN VA only)

| Artifact | Path / tool | This pass |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_005070b0_FUN_005070b0.md` | ≡ live decompile |
| Annotated | `docs/reconstruction/raw/aa_005070b0_FUN_005070b0.annotated.md` | Scaffold; CF ≡ raw |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005070b0.cpp` | CF ≡ raw |
| Function record | `docs/reconstruction/functions/aa_005070b0_FUN_005070b0.md` | Scaffold |
| Live decompile | Ghidra MCP `decompile_function` `0x005070b0` | **≡ raw** |
| Force recompile | Ghidra MCP `force_decompile` `0x005070b0` | **≡ decompile (rep 2)** |
| Live `read_memory` | `0x005070b0` length 32 | **Instruction seal (rep 3)** |
| Function bounds | `get_function_by_address` | Entry `005070b0`, body–`005070cc` |

**Not performed (OWN-ONLY):** full caller inventory, dual of `FUN_005070d0`, host type recovery, runtime CE force, ledger updates.

**Context-only (not re-proven here):** parent duals already cite this VA as the ready probe (`A/B_aa_0040d040_*`, `A/B_aa_0040d260_*`, `A_aa_00404cb0_*`).

---

## 3. Signature

```c
// MSVC __thiscall — ECX = object* (CVOGPhysics* at known callers), stack arg = out-byte*
// Both exit paths leave EAX = out pointer (callers: CMP BYTE PTR [EAX], 0)
// RET 4
void __thiscall CVOGPhysics_ProbeReadyFlag(
    int /*CVOGPhysics**/ this,
    uint8_t *outReady);
// Stack at entry: [esp+4] = outReady
// Semantic return: *outReady ∈ {0, host[+0x29]}; EAX aliases outReady*
```

| Item | Evidence | Confidence |
|---|---|---|
| Convention | `C2 04 00` (`ret 4`) on both exits; ECX used as `this` (`[ECX+0x44]`) | **High** |
| Out-param | `MOV EAX,[ESP+4]` then `MOV BYTE [EAX],…` | **High** |
| EAX = out* | Both paths load out ptr into EAX after/before store | **High** |
| No callees | Leaf: only loads/stores + ret | **High** |
| Body range | `005070b0`–`005070cc` | **High** |

---

## 4. Control flow (sealed)

```
host = *(this + 0x44)
if host == null:
    *out = 0
    return   // EAX = out
*out = *(uint8_t*)(host + 0x29)
return       // EAX = out
```

### 4.1 Three-rep agreement

| Rep | Source | Result |
|---|---|---|
| 1 | Live `decompile_function` | Null host → `*out=0`; else `*out=*(host+0x29)` |
| 2 | `force_decompile` | Identical pseudocode |
| 3 | `read_memory` bytes | Same CF; seals offsets `+0x44` / `+0x29` and `ret 4` |

Decompiler omits explicit “EAX returns out*” (types as `void`); machine code seals the EAX alias that callers rely on — **not** a behavior gap, only a decompiler presentation gap.

---

## 5. Machine bytes (`read_memory` @ `0x005070b0`, 2026-07-29)

```text
Hex: 8b414485c0750a8b442404c60000c204008a48298b4424048808c20400  (then cc cc cc)

8B 41 44            mov  eax, [ecx+0x44]      ; host = this+0x44
85 C0               test eax, eax
75 0A               jnz  host_live
8B 44 24 04         mov  eax, [esp+4]         ; out*
C6 00 00            mov  byte ptr [eax], 0
C2 04 00            ret  4
; host_live:
8A 48 29            mov  cl, [eax+0x29]       ; flag = host[+0x29]
8B 44 24 04         mov  eax, [esp+4]         ; out*
88 08               mov  [eax], cl
C2 04 00            ret  4
CC CC CC            int3 pad
```

Body size **28 B** through final `ret 4` (exclusive of pad).

| Immediate / offset | Role | Confidence |
|---|---|---|
| `+0x44` | Host / attach object pointer on `this` | **High** (load site sealed) |
| `+0x29` | Single-byte ready (or enable) flag on host | **High** (load site sealed) |
| `ret 4` | One stack arg (out*) | **High** |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Leaf probe: null `+0x44` → out `0` | **High** | Decompile ×2 + bytes |
| Else out = `*(*(this+0x44)+0x29)` | **High** | `8A 48 29` / `88 08` |
| `thiscall` + `ret 4` | **High** | ECX base; both exits `C2 04 00` |
| EAX left as out* | **High** | Both paths; parent callers `CMP [EAX],0` |
| No prepare / no side effects beyond `*out` | **High** | No calls, no other stores |
| Name `CVOGPhysics_ProbeReadyFlag` | **Probable** | Usage at CVOGPhysics helpers; Ghidra still `FUN_*` |
| `+0x44` type / `+0x29` English name | **Tentative** | Behavior sealed; type open |
| Flag polarity (1=ready always) | **Probable** | Callers treat `0` as “not ready → maybe prepare” |
| Host always non-null when flag meaningful | **High** (CF) | Null short-circuits to 0 |

---

## 7. Gaps / open (OWN unit)

1. Exact type of object at `this+0x44` and semantic name of byte `+0x29`.
2. Who **writes** host`+0x29` (producers) — out of OWN-ONLY.
3. Whether any non-CVOGPhysics object reuses the same offsets with different English meaning.
4. Ghidra signature still `undefined FUN_005070b0(void)` — plate not updated this pass.
5. Sibling `FUN_005070d0` prepare dual not opened here.

**Verdict:** **accept-with-gaps** — dual **CF + offsets + ret + EAX-out alias** sealed by three-rep (decompile / force / bytes); remaining gaps are type names and producers only.
