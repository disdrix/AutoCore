# Review A (reconstruction fidelity): `aa_00578270` Object_ResolveTargetViaReaction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578270` |
| **VA** | `0x00578270`–`0x00578298` |
| **Body** | **40 bytes** |
| **Canonical name** | `Object_ResolveTargetViaReaction_Inferred` |
| **Prior scaffold** | `FUN_00578270` / `Named_CalleeOf_CVOGHBMissionPatrol_Tick_00578270` |
| **Review date** | `2026-07-29` (W28-F dual seal) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00578270_Object_ResolveTargetViaReaction_Inferred.md` |
| **System** | object / reaction / targeting |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `get_function_by_address` + callers. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Thin **host → reaction** resolve wrapper:

| Step | Action |
|---|---|
| 1 | Read host `+0x658/+0x65c` (id pair), `+0x660` (flag) |
| 2 | `reaction = *(*(host+0x688)+0xe4e8)` into ECX |
| 3 | `return CVOGReaction_ResolveObjectTarget(reaction, flag, id0, id1)` |

Broadly called from HB/mission/activate paths (19 callers), including W27-F `Object_ActivatePlayerEnqueueHB_Inferred`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x00578270` — surface void, 3-arg call only |
| Bytes | `read_memory` 64 B — full body through `C3`; next fn at `005782a0` |
| Bounds | body `00578270`–`00578298` (40 B; pad `CC`) |
| Callee decompile | `CVOGReaction_ResolveObjectTarget` @ `004bae70` — returns ptr or 0 |
| Callers | 19 including `00650f90`, `00626890`, many `0061xxxx` / UI |
| Raw / clean | `aa_00578270_*`, `Object_ResolveTargetViaReaction_Inferred.cpp` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, dual of `004bae70` / `004e3260`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = host | **Confirmed** | `mov eax,ecx`; field loads from EAX |
| Reaction this `+0x688→+0xe4e8` | **Confirmed** | bytes `mov ecx,[eax+688]; mov ecx,[ecx+e4e8]` |
| Stack flag,id0,id1 order | **Confirmed** | push `+65c`, `+658`, `+660` then call |
| Returns EAX (not void) | **Confirmed** | plain `ret`; callers assign; callee returns |
| Product host/return types | **Open** | W27-F called return "mgr" + vfunc 0x210 |
| Id-pair = TFID | **Open** | plausible; not sealed here |
| Decompiler ≡ bytes full ABI | **Partial** | CF ok; void + missing reaction-this |

---

## 4. Control flow: clean ≡ bytes (corrected)

| Stage | Match |
|---|---|
| Load host fields | Yes |
| Load reaction this | Yes (bytes; surface omit) |
| Call resolve | Yes |
| Return pointer | Yes (bytes/callers; surface void) |

### Recovered CF

```c
// void* __fastcall Object_ResolveTargetViaReaction(Host *host)
void *reaction = *(*(void***)(host + 0x688) /* +0xe4e8 */);
return CVOGReaction_ResolveObjectTarget(
    reaction,
    *(uint8_t *)(host + 0x660),
    *(uint32_t *)(host + 0x658),
    *(uint32_t *)(host + 0x65c));
```

### Entry byte seal (40 B)

```
8B C1                      mov eax, ecx           ; host
8B 90 5C 06 00 00          mov edx, [eax+0x65c]
8B 88 88 06 00 00          mov ecx, [eax+0x688]
8B 89 E8 E4 00 00          mov ecx, [ecx+0xe4e8]  ; reaction this
52                         push edx               ; id1
8B 90 58 06 00 00          mov edx, [eax+0x658]
8A 80 60 06 00 00          mov al,  [eax+0x660]
52                         push edx               ; id0
50                         push eax               ; flag (AL meaningful)
E8 …                       call CVOGReaction_ResolveObjectTarget
C3                         ret
```

---

## 5. Gaps / open

1. Product English for host class, return type, reaction singleton.
2. Semantic of `+0x658/+0x65c` id pair and `+0x660` flag.
3. Dual of `CVOGReaction_ResolveObjectTarget` / `FUN_004e3260` (not OWN).
4. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
