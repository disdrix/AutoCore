# Dual A/B report — MEGA-114 OWN-ONLY (`0x00411e40`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-114**  
**Scope:** VA `0x00411e40` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (write).  
**Ghidra:** `decompile_function` + `force_decompile` + `get_function_by_address` + `disassemble_function` + `read_memory` + `get_function_callers` + `get_xrefs_to` + `get_function_callees`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — interaction-activation TraverseToNext payload node+8 (partition parent `0x0091b8d0`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00411e40` CNDHash_TraverseToNext_RegEdiEsi | **accept-with-gaps** — CF/ABI/strings/offsets/callers sealed; payload English + unlabeled sites open |

Path A (fidelity): CF ≡ force-decompile ≡ bytes; EDI/ESI register ABI + bare RET + payload@+8 sealed → **accept-with-gaps**.  
Path B (adversarial): fatal-abort / return-node / thiscall-merge / RET4 / lock-mutate / stack-args / VOG_DEBUG_STOP-as-name / inv-node-layout claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Scaffold status (pre-MEGA-114)

| Artifact | Pre | MEGA-114 action |
|---|---|---|
| Raw capture | present (2026-07-23 scaffold) | **Appended** live re-verify (no wipe) |
| Annotated | scaffold | **Refreshed** ABI/offsets/callers |
| Clean FUN | scaffold | **Rewritten** CF + ABI plate |
| Named clean | `Named_VOG_DEBUG_STOP_00411e40` misname | **Retired**; new `CNDHash_TraverseToNext_RegEdiEsi.cpp` |
| Function FUN record | partial scaffold | **Updated** dual sealed |
| Named function record | missing | **Created** |
| Review A / B | missing | **Created** |
| Report | missing | **This file** |

---

## VA `0x00411e40` — sealed facts

1. **Body:** `0x00411e40`–`0x00411e80` inclusive (**65 B** / `0x41`); pad `CC`.
2. **ABI:** **EDI** = CNDHash\* hash; **ESI** = `node**` cursor; **EAX** = payload|0; bare **`RET`** (not thiscall / not `RET 4`).
3. **Semantics:** CNDHash **TraverseToNext** ordered-list step:
   - Soft-assert TraversalLock @ **hash+0x1d** (`HashError:TraverseToNext…` / `VOG_DEBUG_STOP`); **non-fatal**.
   - Seed cursor from **hash+0x14** or advance **node+0x14**.
   - Return **payload** @ **node+8**, else **0**.
   - No lock set/clear, freelist, or membership mutation.
4. **Strings:** `0x00a27c9c` TraverseToNext error; `0x00a15844` `VOG_DEBUG_STOP`.
5. **Callers (named):** `Client_UpdateNpcInteractIcons` `0x0091b8d0` (partition parent; hash @ client **+0x6f0**); `FUN_0078dac0`; `FUN_007ff3d0`; `FUN_00812de0`; `FUN_008153b0`; `FUN_0083c110`.
6. **Xrefs:** **11** UNCONDITIONAL_CALL (incl. unlabeled `0078a39e` / `0078a422`).
7. **Callees:** `FUN_007a4480` only.
8. **Twin:** dualed `CNDHash_TraverseToNext` `0x00411900` — same CF/offsets/strings; **thiscall + RET 4**.
9. **Name:** `CNDHash_TraverseToNext_RegEdiEsi` (Ghidra `FUN_00411e40`). Product role string-sealed; `RegEdiEsi` distinguishes ABI twin.
10. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Payload product English / struct layout per host (interact uses type@+4, TFID@+8/+0xc).  
- Owning function English for unlabeled CALL sites.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00411e40_CNDHash_TraverseToNext_RegEdiEsi.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00411e40_CNDHash_TraverseToNext_RegEdiEsi.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00411e40_FUN_00411e40.md` |
| Annotated | `docs/reconstruction/raw/aa_00411e40_FUN_00411e40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_TraverseToNext_RegEdiEsi.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00411e40.cpp` |
| Function FUN | `docs/reconstruction/functions/aa_00411e40_FUN_00411e40.md` |
| Function named | `docs/reconstruction/functions/aa_00411e40_CNDHash_TraverseToNext_RegEdiEsi.md` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_00411e40.cpp` |

---

## Chain context (not dualled; evidence only)

```text
Client_UpdateNpcInteractIcons  0x0091b8d0  [partition parent MEGA-114]
  ├─ unlock other hash @ DAT_00d1b644+0xe8f4
  ├─ FUN_00411e10   TraversalLock_RegEsi (sets hash+0x1d)  [residual]
  ├─ FUN_00411e40   CNDHash_TraverseToNext_RegEdiEsi  [OWN MEGA-114]
  │     └─ FUN_007a4480 ×2 (unlocked path only)
  ├─ while payload:
  │     type@+4 == 1 → CVOGReaction_ResolveObjectTarget(TFID@+8/+0xc)
  │     → NDSpecialFX "generic_interact_secondary" …
  └─ clear lock @ client+0x6f0 hash +0x1d

Twin (READ-only dualed):
  CNDHash_TraverseToNext  0x00411900  [thiscall RET 4; same CF]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00411e40-mega-114-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00411e40` | Port as **CNDHash TraverseToNext** ordered-list step. Preserve **EDI=hash / ESI=cursor\*** register convention (or emit a thiscall thunk that loads them). Return **payload @ node+8**, not the node. Lock check is **non-fatal log**. |
| Do **not** | Merge with thiscall twin `00411900`; treat as VOG_DEBUG_STOP handler; use inv-u64 node +0x20 next; set/clear lock inside this VA. |
| Pair with | dualed twin `00411900`; residual lock helper `00411e10`; parent `Client_UpdateNpcInteractIcons` `0091b8d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- coverage / naming registry / system maps as applicable  

**Terminal:** **false**.
