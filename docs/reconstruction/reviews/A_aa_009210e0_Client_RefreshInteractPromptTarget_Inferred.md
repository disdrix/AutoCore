# Review A (reconstruction fidelity): `aa_009210e0` Client_RefreshInteractPromptTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009210e0` |
| **VA** | `0x009210e0`–`0x00921355` |
| **Canonical name (Ghidra)** | `FUN_009210e0` |
| **Proposed name** | `Client_RefreshInteractPromptTarget_Inferred` (**High** role; product name absent) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra W18-L) |
| **Reviewer role** | Reconstruction fidelity (interact prompt refresh) |
| **Counterpart** | `reviews/B_aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` |
| **System** | `interaction-activation` |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Timer-driven proximity interact refresh:** choose a nearby world object and push it into the interact prompt UI host (`FUN_008a81a0`), without sending UseObject.

### Primary use

Sole caller `FUN_009216e0`: accumulates dt on `this+0x15a` vs threshold `+0x159`; on fire calls `vtbl+0x478` then **`PUSH ESI; CALL FUN_009210e0`**.

### Algorithm (sealed)

1. Gate on `DAT_00d1b8c8` + `vtbl+0x3d8`.
2. Seed null TFID; sample local player pos (`vtbl+0x1a0`).
3. Prefer `DAT_00d1d888` if not self and dist² ≤ **225.0f**; else mode-**6** radius-**15** map gather + resolve.
4. Tip id **3** when a candidate path is taken.
5. Fallbacks: mode **3** living → (if `world+0xf5`) mode **7** / filterA **0x14** → `FindFirstObjectInRadius(15)`.
6. `FUN_008a81a0(promptHost)` with **ESI = object**.

**Not** `Client_Input_PollBoundActions` Activate edge (that sends 0x2072 / 0x2055). **Not** click pick hub.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009210e0_FUN_009210e0.md` (+ v2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_009210e0_FUN_009210e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RefreshInteractPromptTarget_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_009210e0_Client_RefreshInteractPromptTarget_Inferred.md` |
| Live Ghidra | decompile; complete analysis; callers/callees; `read_memory` body + `DAT_00aaaca4` + null TFID + caller site |
| Sibling duals | `Client_FindFirstObjectInRadius`; `Skill_GatherTargetsInArea`; `Skill_GatherTargetsRadiusMap_Inferred`; PollBoundActions Activate |

**Not performed:** Launcher, runtime, bit-exact, parent ledger edits, `disassemble_bytes`.

---

## 3. Signature

```c
// RET 4 — stack dword cleaned; body does not load [ebp+8]/[esp+…] formal
void Client_RefreshInteractPromptTarget_Inferred(void *client_unused_from_caller);
```

| Item | Evidence |
|---|---|
| `RET 4` | epilogue `C2 04 00` |
| Caller push | `00921738`: `56 E8 …` = `PUSH ESI; CALL` |
| Unused formal | no load of stack arg in body; globals only |
| ESI out | `8B F0` after resolves; `FUN_008a81a0` uses unaff_ESI |

**Decompiler trap:** shows `void FUN_009210e0(void)` — omits RET-4 formal.

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Double gate host / vtbl+0x3d8 | **Yes** |
| Prefer d1d888 vs 225 dist² / self | **Yes** |
| Mode 6 @ 15f re-query | **Yes** |
| Tip 3 + early UI path | **Yes** |
| Mode 3 → optional 7/0x14 → FindFirst 15 | **Yes** |
| Always prompt update if gate passed | **Yes** |
| No network send | **Yes** |

**Constants:** `0x41700000` = 15.0f; `DAT_00aaaca4` = `0x43610000` = 225.0f.

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Prompt refresh not UseObject | **High** | callees list |
| 15f / 225 geometry | **High** | imm + global bytes |
| Mode cascade 6→3→7 | **High** | push immediates |
| Sole timer caller | **High** | 1 xref |
| Product name | **Tentative** | `_Inferred` |
| Prompt host type (`d1b8c8`) | **Tentative** | |

---

## 6. Gaps / open

1. Retail names for `DAT_00d1b8c8`, `FUN_008a81a0`, `FUN_009216e0`.
2. Whether `DAT_00d1d888` is written by this unit (no — only read; writers elsewhere).
3. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — CF/radii/modes High; product names open.
