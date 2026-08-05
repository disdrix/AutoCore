# Dual A/B report — W19-D OWN-ONLY (`0x00419ad0`, `0x0076cef0`)

**Date:** 2026-07-29  
**Agent:** W19-D OWN-ONLY  
**Scope:** OWN ONLY VAs `0x00419ad0`, `0x0076cef0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` (+ function meta / xrefs / complete analysis). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_00419ad0` CNDHash_BucketChainTouchRepair | **accept** — **EDI bucket, touch@+8 / next@+0x10, log+sever CF sealed; product spelling residual** |
| `aa_0076cef0` Profiler_ScopeLeave | **accept** — **1-byte `c3` leave stub sealed; twin of ScopeEnter** |

---

## `aa_00419ad0` — CNDHash_BucketChainTouchRepair

### Sealed facts

1. **Body:** `0x00419ad0`–`0x00419b30` exclusive (**96** B). Final `c3`; following `cc` pad.

2. **ABI:** **EDI = bucket header***; bare **`ret`**. Clobbers EBX/ESI. **Not** ECX-thiscall.

3. **Layout:** `bucket+0x04` = chain head; `node+0x08` = touch byte; `node+0x10` = next.

4. **Algorithm:** mark-walk; healthy null-next → clear marks; already-touched next → `FUN_007a4480(1, "HashListError: Went to node we already touched! Attempting repair!" @ 0x00a64710)`, sever `prev->next=0`, clear marks.

5. **Callees:** `FUN_007a4480` only. **No free**, no key compare, no ordered-list work.

6. **Callers (4):** `CNDHash_Insert_u64` (`FUN_00413920` @ `00413a14`); `CNDHash_BucketUnlinkByU64Key` (`FUN_00419b80` ×2); `FUN_00419620` @ `00419714`. Insert site sets EDI=bucket then CALL.

7. **Distinct from** `aa_00537d30` (ECX list; touch@+4; next@+0xC) — same string/algorithm **family**, different unit.

8. **Name:** structural `CNDHash_BucketChainTouchRepair`; registry/plate alias `Util_HashListError_Repair`.

### Gaps

1. Product/PDB symbol spelling.  
2. Ownership of severed tail nodes (no free here).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_00419ad0_CNDHash_BucketChainTouchRepair.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_00419ad0_CNDHash_BucketChainTouchRepair.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_00419ad0_CNDHash_BucketChainTouchRepair.md` |
| Review B | `docs/reconstruction/reviews/B_aa_00419ad0_CNDHash_BucketChainTouchRepair.md` |
| Function record | `docs/reconstruction/functions/aa_00419ad0_CNDHash_BucketChainTouchRepair.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_00419ad0_FUN_00419ad0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_BucketChainTouchRepair.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00419ad0.cpp` |
| Raw | `docs/reconstruction/raw/aa_00419ad0_FUN_00419ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_00419ad0_FUN_00419ad0.annotated.md` |

---

## `aa_0076cef0` — Profiler_ScopeLeave

### Sealed facts

1. **Body:** `0x0076cef0` = **`c3` (`ret`)** only. Exclusive end `0x0076cef1`. Following `cc` is pad.

2. **CF:** empty `return;` — decompile ≡ raw ≡ live re-verify.

3. **ABI:** bare `ret` (not `ret n`). Ignores ECX and any stack args.

4. **Callees:** none. Classification: **stub**.

5. **Roles (xref / sibling, not body):**  
   - Leave twin of `Profiler_ScopeEnter` @ `0x0076cf00` (`8b 41 04 c2 04 00`).  
   - ≥100 UNCONDITIONAL_CALL sites (AI/drive/physics/terrain/spawn…).  
   - Physics docs: enter/leave pair — **ignore for port**.

6. **Not this VA:** enter `0x0076cf00`; other mass empties (e.g. `0x0056f570`).

7. **Name:** `Profiler_ScopeLeave` (structural; spelling residual vs Exit/EndZone).

### Gaps

1. Original PDB/compiler symbol spelling.  
2. Exhaustive DATA-slot census (N/A — pure code leaf).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_0076cef0_Profiler_ScopeLeave.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_0076cef0_Profiler_ScopeLeave.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_0076cef0_Profiler_ScopeLeave.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0076cef0_Profiler_ScopeLeave.md` |
| Function record | `docs/reconstruction/functions/aa_0076cef0_Profiler_ScopeLeave.md` |
| Scaffold alias record | `docs/reconstruction/functions/aa_0076cef0_FUN_0076cef0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Profiler_ScopeLeave.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0076cef0.cpp` |
| Raw | `docs/reconstruction/raw/aa_0076cef0_FUN_0076cef0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076cef0_FUN_0076cef0.annotated.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### BucketChainTouchRepair (`0x00419ad0`)

- Port as **post-mutate integrity walk** on u64 CNDHash **bucket** chains, not a free/remove helper.
- Preserve **EDI bucket** ABI (or explicit bucket param that matches call sites).
- Use **touch@+8 / next@+0x10** — do **not** substitute `00537d30` offsets.
- On cycle: **log + sever only**; do not invent free inside this VA.
- Call after bucket insert/unlink the way retail does (unconditional).

### Profiler_ScopeLeave (`0x0076cef0`)

- Treat as **shared nop leave** — do not invent timer stop, zone stack pop, or `ret 4`.
- Pair with ScopeEnter is **client instrumentation**; sector/physics ports should **ignore**.
- Distinct from enter `0x0076cf00` and other empty leaves.

---

## This report

`docs/agents/task-dual-ab-00419ad0-0076cef0-w19d-report.md`
