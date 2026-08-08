# Dual A/B report — MEGA-112 OWN-ONLY (`0x0040c6b0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-112**  
**Scope:** VA `0x0040c6b0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs (siblings read-only evidence).  
**Ghidra:** `decompile_function` / `force_decompile` + `analyze_function_complete` + callers/xrefs + `disassemble_function` + `read_memory` + parent disasm. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual partition — interaction-activation TraverseToNext TFID\* node+0xc (`WAVE_2026-08-05_mega_residual_partition_map.md` MEGA-112).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040c6b0` CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred | **accept-with-gaps** |

Path A (fidelity): CF/ABI/EDI-ESI/plain-RET/next+0x20/payload+0xc/string/sole-caller sealed; product hash RTTI open → **accept-with-gaps**.  
Path B (adversarial): thiscall-RET4-merge / 0x1c-node-merge / fatal-unlock / node-return / VOG_DEBUG_STOP-as-name / universal-TFID claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## Scaffold status (pre-MEGA-112)

| Artifact | Pre | MEGA-112 action |
|---|---|---|
| Raw capture | present (2026-07-23 scaffold) | **Appended** live re-verify (body preserved) |
| Annotated | present (scaffold) | **Refreshed** |
| Clean named cpp | missing / VOG misname only | **Created** meaningful named + retired VOG scaffold |
| FUN twin | scaffold | **Refreshed** |
| Named function record | missing | **Created** |
| FUN function record | partial scaffold | **Updated** |
| Review A | missing | **Created** |
| Review B | missing | **Created** |
| Report | missing | **This file** |

---

## VA `0x0040c6b0` — sealed facts

1. **Body:** `0x0040c6b0`–`0x0040c6f0` inclusive (**65 B** / `0x41`); dual plain **`RET`** (`c3`); pad `CC` before `List_TraversalUnlock` `0x0040c700`.
2. **ABI:** **EDI** = CNDHash\* hash; **ESI** = node-cursor\*\*; **EAX** = payload (TFID\*); **plain RET** — **not** thiscall / **not** `RET 4`.
3. **Semantics:** CNDHash **TraverseToNext** for **0x28 / u64-key** nodes:
   - Soft-assert TraversalLock @ **hash+0x1d** (`HashError:TraverseToNext…` / `VOG_DEBUG_STOP`); **fall-through**.
   - Ordered walk: first node @ **hash+0x14**, successor @ **node+0x20**, payload @ **node+0xc**.
   - No lock write, no membership mutation, no free.
4. **Callers (code):** `Client_UpdateNpcInteractIcons` `0x0091b8d0` @ `0x0091b961` + `0x0091be26` only.
5. **Xrefs:** 2 UNCONDITIONAL_CALL.
6. **Callees:** `FUN_007a4480` only.
7. **Parent seal:** `MOV EDI, *[DAT_00d1b644+0xe8f4]`; `LEA ESI, [esp+cursor]`; `CALL 0040c6b0`; return cast `TFID_16*` → `Object_ResolveFromTFID`; post-loop `hash+0x1d = 0`. Companion lock set: `FUN_00411e10`.
8. **Name:** `CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred` (Ghidra `FUN_0040c6b0`). Product TraverseToNext string-sealed; hash stamp / RTTI open → `_Inferred`. Retired `Named_VOG_DEBUG_STOP_0040c6b0`.
9. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + parent call sites. Force ≡ non-force.

### Gaps

- Product English / RTTI for hash instance at `DAT_00d1b644+0xe8f4`.  
- TFID\* value_type is consumer-local (sole parent); not proven universal.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040c6b0_CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040c6b0_CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0040c6b0_FUN_0040c6b0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040c6b0_FUN_0040c6b0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040c6b0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_0040c6b0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040c6b0_FUN_0040c6b0.md` |
| Function named | `docs/reconstruction/functions/aa_0040c6b0_CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_UpdateNpcInteractIcons  0x0091b8d0
  ├─ FUN_00411e10  TraversalLock set (ESI=hash; +0x1d=1)     [residual]
  ├─ FUN_0040c6b0  TraverseToNext TFID* node+0x20/+0xc       [OWN MEGA-112]
  │     hash = *[DAT_00d1b644 + 0xe8f4]
  ├─ Object_ResolveFromTFID(pTfid) …
  ├─ (inner) FUN_00411900  thiscall TraverseToNext +0x14/+8  [dualed elsewhere]
  ├─ unlock hash+0x1d = 0
  ├─ FUN_00411e40  reg TraverseToNext next+0x14/value+8      [residual]
  │     hash = *[DAT_00d1b6d8 + 0x6f0]
  └─ unlock that hash+0x1d = 0

Family contrast:
  00411900  thiscall RET4  next+0x14 value+8   (0x1c-class) [dualed]
  00411e40  reg EDI/ESI    next+0x14 value+8   (0x1c-class) [residual]
  0040c6b0  reg EDI/ESI    next+0x20 value+0xc (0x28-class) [OWN]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-0040c6b0-mega-112-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040c6b0` | Port as **CNDHash TraverseToNext** for **0x28-class** nodes (list-next **+0x20**, value **+0xc**). **EDI=hash, ESI=&cursor, plain RET**. Soft-log if unlocked; do **not** early-return. Do **not** merge with thiscall twin `00411900` or reg twin `00411e40` (different next/value offsets). |
| Pair with | residual lock `00411e10`; dualed thiscall Traverse `00411900`; residual reg Traverse `00411e40`; parent `Client_UpdateNpcInteractIcons` `0091b8d0`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`
- `NAMING_REGISTRY` / COVERAGE / CHANGE_LOG as applicable  
- Progress / inventory ledgers  

**Not written by this agent.**
