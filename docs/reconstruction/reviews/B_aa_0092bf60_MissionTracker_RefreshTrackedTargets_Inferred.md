# Review B (skeptical / adversarial): `aa_0092bf60` MissionTracker_RefreshTrackedTargets_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092bf60` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R11-040) |
| **Counterpart** | `reviews/A_aa_0092bf60_MissionTracker_RefreshTrackedTargets_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler body is complete / portable | **Falsified** — `force_decompile` still drops `FUN_0092a440`, TFID copy, type gate; marks live blocks unreachable |
| 2 | Success path is only `af80` then `b2a0` | **Falsified** — primary path is `af80` → type gate → `a440` → TFID memcpy; `b2a0` is **secondary** on af80 fail / null best |
| 3 | ECX-thiscall | **Falsified** — entry `MOV EDI,EAX`; caller `MOV EAX,ESI`; no `MOV ECX,…` this setup |
| 4 | Stack args / `RET n` | **Falsified** — no arg pops of this; `ADD ESP,8` frees **locals only**; bare `RET` |
| 5 | Void return | **Falsified** — `MOV AL,1` / `XOR AL,AL` on all exits |
| 6 | Writes dirty flag `+0x04` | **Falsified** — `+0x04` owned by caller `FUN_0092c640`; this unit writes `+0x08`, `+0x0B`, `+0x14` |
| 7 | Timer value is 1.0 / frame dt | **Falsified** — `DAT_00aaa690` bytes `00 00 80 40` = **4.0f** |
| 8 | `DAT_00aaaaf8` is a pointer / vtbl | **Falsified** — float **1e9f** seed for bestDistSq (`MOVSS`) |
| 9 | Copies full object / position into node | **Falsified** — only **16 B** from `obj+0x160` (sealed TFID_16 plate) |
| 10 | Multi-caller UI / packet builder | **Falsified** — **1** xref, timer path only; no opcode builders in body |
| 11 | Same as HUD refresh `0x008a8770` | **Falsified** — different VA/size/role; this fills tracker vector, not widget chrome |
| 12 | Inventory transfer of items | **Unsupported as direct role** — inventory touch is **indirect** via parent filter `0092adf0` locker FindItemByCoid gate inside `0092af80` arms; body itself is tracker refresh |
| 13 | Always calls both `a440` and `b2a0` | **Falsified** — mutually exclusive arms (secondary only if primary miss) |
| 14 | `a440` null is failure | **Falsified** — `JZ` to success epilogue `AL=1` without TFID copy |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI EAX-host / AL bool / bare RET | **High** | Wrong call convention |
| Clear + timer 4.0f | **High** | Poll rate / stale targets |
| Primary vs secondary arm split | **High** | Missing bind / double work |
| TFID_16 copy `+0x160` | **High** | Wrong identity on node |
| Type gate `0x12`/`0x0E` | **High** | Flag `+0xB` semantics |
| Product class English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

- 2026-07-23 raw decompile ≡ live force_decompile (both incomplete).  
- `read_memory` 278 B + `get_assembly_context` on `0092bf8b` / `0092bff5` / `0092c024` / `0092c058` seals full CF.  
- Caller site `0092c67c`: `MOV EAX,ESI; CALL` after `0092c080`.  
- Dualed clear helper `0092a3d0` EDI contract matches (`EDI=host` at call).  
- TFID plate `object+0x160` consistent with NAMING_REGISTRY / interaction-activation.

---

## 4. Surviving contract for AutoCore

```
// EAX = MissionTracker* host (same object as timer ESI in FUN_0092c640)
AL = MissionTracker_RefreshTrackedTargets_Inferred(host);
// Side effects: clear vector+0x11c; timer+0x14=4.0f; maybe node+TFID or secondary fill;
//               may clear flags +0x08 / +0x0B.
// Do NOT port the collapsed Ghidra decompiler. Prefer bytes/annotated/clean named.
// Pair: dirty tick FUN_0092c640; bind fill FUN_0092c080; clear 0092a3d0; filter 0092af80/0092adf0.
```

---

## 5. Verdict

Adversarial attacks on decompiler-complete / thiscall / void / dual-path-always / multi-caller claims fail. Residual product English only → **accept-with-gaps**. Terminal **false**.
