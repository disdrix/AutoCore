# Dual A/B report — MEGA-113 OWN-ONLY (`0x00411e10`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-113**  
**Scope:** VA `0x00411e10` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** HTTP `127.0.0.1:8089` — `decompile_function` / `force_decompile` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees + `search_strings` / `inspect_memory_content`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — nested callee of dualed **Client_UpdateNpcInteractIcons** (`0x0091b8d0`): **CNDHash TraversalLock set**.  
**System (partition):** interaction-activation.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00411e10` CNDHash_TraversalLock | **accept-with-gaps** — CF/ABI/ESI/RET/flag+0x1d/strings/16 xrefs sealed; product class English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): thiscall / RET4 / VOG_DEBUG_STOP-name / List-merge / early-return / CS / throw / walk claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00411e10` — sealed facts

1. **Body:** `0x00411e10`–`0x00411e35` inclusive (**38 B** / `0x26`); pad `CC` ×10 before `FUN_00411e40`.
2. **ABI:** custom **ESI** = CNDHash\*; no stack args; void; bare **`RET`** (`C3`). **Not** thiscall.
3. **Semantics:** CNDHash **TraversalLock set**:
   - If `*(hash+0x1d) != 0`: log `"HashError:TraversalLock, already locked for traversal"` + `"VOG_DEBUG_STOP"` via `FUN_007a4480`.
   - **Always** write `*(hash+0x1d) = 1` (soft double-lock — no early return).
   - No CS; no walk; no throw.
4. **Strings:** `0x00a27cd0` HashError TraversalLock; `0x00a15844` VOG_DEBUG_STOP.
5. **Callees:** `FUN_007a4480` only (×2).
6. **Callers / xrefs:** **16** UNCONDITIONAL_CALL. Named: `Client_UpdateNpcInteractIcons` (`0x0091b8d0` @ `0x0091b94d` / `0x0091be5e`), `NDUIWindow_ReloadInterface`, `FUN_00790f80`, `FUN_00791260`, `FUN_00791f30`, `FUN_00792340`, `FUN_007ff3d0`, `FUN_0083c110` (×2), `FUN_0088c340`. Orphan sites still show ESI preload.
7. **Unlock:** caller-owned inline `*(hash+0x1d)=0` (e.g. `0x0091be46`, `0x0091befe`) — not this VA.
8. **Name:** `CNDHash_TraversalLock` (Ghidra `FUN_00411e10`). **Reject** scaffold `Named_VOG_DEBUG_STOP_00411e10`.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site ESI setup.

### Gaps

- Product C++ class / stamp-family English for shared leaf.  
- Intentional re-lock API vs debug residual.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00411e10_CNDHash_TraversalLock.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00411e10_CNDHash_TraversalLock.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00411e10_FUN_00411e10.md` |
| Annotated | `docs/reconstruction/raw/aa_00411e10_FUN_00411e10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_TraversalLock.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00411e10.cpp` |
| Function | `docs/reconstruction/functions/aa_00411e10_FUN_00411e10.md` |
| Function named | `docs/reconstruction/functions/aa_00411e10_CNDHash_TraversalLock.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_UpdateNpcInteractIcons  (0x0091b8d0)  [partition parent; dualed elsewhere]
  ├─ CNDHash_TraversalLock (0x00411e10)     [OWN MEGA-113]  ESI=[client+0xe8f4]
  ├─ traverse interact TFIDs / FX attach …
  └─ inline *(hash+0x1d)=0

Object/UI walkers (hash @ +0x4c0)
  └─ CNDHash_TraversalLock                  ESI=[obj+0x4c0]

Char mission hash walkers (+0x538 / +0x6f0 / +0x53c)
  └─ CNDHash_TraversalLock

Peer (residual, not OWN):
  FUN_00411e40  TraverseToNext-style chain step (flag check string @ 00a27c9c)

List parallel (different type; dualed):
  List_TraversalLock   0x004294f0
  List_TraversalUnlock 0x0040c700
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00411e10-mega-113-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00411e10` | Port as **CNDHash TraversalLock set**. **ESI** = hash\* (custom), **bare ret**, void. Flag at **`+0x1d`**. Soft double-lock: log then still set. Pair with caller-owned clear of `+0x1d`. Do **not** model as thiscall or as `List_TraversalLock`. Reject VOG_DEBUG_STOP as the function name. |
| Pair with | partition parent `Client_UpdateNpcInteractIcons` `0091b8d0`; residual TraverseToNext `00411e40`; dualed List_TraversalLock/Unlock; CNDHash host ctor/alloc family. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (`CNDHash_TraversalLock`; retire `Named_VOG_DEBUG_STOP_00411e10`)  
- `systems/*` residual tables (interaction-activation + shared CNDHash)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00411e10`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + force_decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + strings. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources use meaningful name `CNDHash_TraversalLock`; machine ABI correction (ESI custom, bare ret).  
- Odd behavior preserved: double-lock logs then still sets flag; unlock not in this body.  
- Scaffold `Named_VOG_DEBUG_STOP_00411e10` **retired** as product identity. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
