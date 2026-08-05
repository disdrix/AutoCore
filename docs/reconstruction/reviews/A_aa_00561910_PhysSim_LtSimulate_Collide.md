# Review A (reconstruction fidelity): `aa_00561910` PhysSim_LtSimulate_Collide

| Field | Value |
|---|---|
| **Stable ID** | `aa_00561910` |
| **VA** | `0x00561910`–`0x00561B5B` |
| **Canonical name** | `PhysSim_LtSimulate_Collide` |
| **Ghidra name** | `FUN_00561910` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W23-L) |
| **Counterpart** | `reviews/B_aa_00561910_PhysSim_LtSimulate_Collide.md` |
| **System** | physics / island simulate |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` 588 B + xrefs; prior verified `fn_00561910_islandStep.md` |
| **Verdict** | **accept** |

---

## 1. Purpose

Collide half of island **`LtSimulate`**:

1. Install `stepInfo` `{dt, inv_dt}` at island `+0x150/+0x154` and derived scales `+0x170..+0x1a4`.
2. Copy agent block from `*(island+0xcc)` → `+0x140..+0x14c`.
3. Flush pending body pairs when `+0x24 > 0`.
4. For each sub-island: `FUN_00629d90` (LtBroadPhase/narrowphase); optional `TtIslandPostCollideCb`.
5. Deferred deletes; `StPostCollideCB` list.

**Not** applyAction / integrate (companion `FUN_00561b60`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00561910_FUN_00561910.md` (+ 2026-07-29 W23-L append) |
| Annotated | `docs/reconstruction/raw/aa_00561910_FUN_00561910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysSim_LtSimulate_Collide.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00561910.cpp` |
| Function record | `docs/reconstruction/functions/aa_00561910_FUN_00561910.md` |
| Prior verified | `physics/verified/fn_00561910_islandStep.md` |
| Live | decompile ≡ raw; `read_memory` 588 B; epilog `59 C2 04 00` |

---

## 3. Signature (sealed)

```c
// 1 stack formal; ECX = island*; return void; RET 4
void PhysSim_LtSimulate_Collide(void *island, float *stepInfo);
```

| Formal | Source | Conf |
|---|---|---|
| island | ECX → ESI | **High** |
| stepInfo | Stack[0x4] → EBP | **High** |
| cleanup | `RET 4` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Store dt/inv_dt @ +0x150/+0x154 | **Yes** | **High** |
| Agent copy +0x140..+0x14c from +0xcc | **Yes** | **High** |
| Scaled terms +0x170..+0x1a4 | **Yes** | **High** |
| Busy flags +0x12c/+0x12d | **Yes** | **High** |
| Flush pairs when +0x24>0 (×3 sites) | **Yes** | **High** |
| Sub-island loop → broadphase | **Yes** (bytes fix this) | **High** |
| Optional post-collide CB | **Yes** | **High** |
| Deferred deletes + StPostCollideCB | **Yes** | **High** |
| No applyAction in this unit | **Yes** | **High** |
| Callers StepTo + FUN_00562bf0 only | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Body size **588** B; epilog `POP ECX; RET 4`. Broadphase call site bytes:

```text
MOV EAX, [ESI+0xc4]
MOV ECX, [ESI+8]
MOV ECX, [ECX+EDI*4]   ; sub-island this
PUSH EBX                 ; island+0x140
PUSH EAX
CALL FUN_00629d90
```

Profiler string `LtSimulate` @ `0x009d2894` (`read_memory`).

---

## 6. Gaps

- Product English for island/world manager type (Havok-like Lt).
- Full sub-island / agent struct beyond offsets used.
- Runtime / bit-exact.

---

## 7. Verdict

CF/ABI/role/call-site residual sealed against live decompile + body bytes + prior verified plate → **accept**.
