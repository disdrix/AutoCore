# Review B (skeptical / adversarial): `aa_0092b2a0` MissionTracker_FillTrackedTargetSlots_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092b2a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY R12-008) |
| **Counterpart** | `reviews/A_aa_0092b2a0_MissionTracker_FillTrackedTargetSlots_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Void return / undefined only | **Falsified** — `MOV AL,1` / `XOR AL,AL` on both epilogues |
| 2 | ECX-thiscall | **Falsified** — host from `[EBP+8]` into `EBX`; caller pushes stack args |
| 3 | Bare `RET` / cdecl | **Falsified** — **`RET 8`** at `0x0092bf43` and `0x0092bf59` |
| 4 | EAX-host like parent refresh | **Falsified** — stack host; EAX not entry host (caller uses `PUSH EDI`) |
| 5 | Always uses race path | **Falsified** — entry prefers CBID lists `+0x54`/`+0x80`; race only if both empty and `+0xAC>0` |
| 6 | Unlimited targets | **Falsified** — hard top-**4** slots |
| 7 | TFID from `obj+0x160` (primary path) | **Falsified** — emit uses **`obj+0x164`** (`LEA …+0x164`) |
| 8 | Vector solely at `+0x118` begin | **Falsified as begin** — begin is **`+0x11C`**; image addresses container via `ADD …,0x118` with end/cap at `+0x120/+0x124` |
| 9 | Success does not write host flags | **Falsified** — `MOV byte ptr [host+0x8], AL` with `AL=1` |
| 10 | Multi-caller UI / packet / inventory move | **Falsified** — **1** xref from refresh only; no opcode builders; inventory is partition ancestry not body role |
| 11 | Min-range 10000 applies to CBID arm | **Unsupported / race-arm specific** — `DAT_00aaa880` gate observed on race insert path; CBID arm uses `FUN_00929c60` + map ranking |
| 12 | Decompiler complete portable body | **Falsified** — type propagation not settling; SEH delete paths mislabeled non-returning |
| 13 | Runtime Confirmed | **Falsified** — no Launcher; terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI stack host/origin / AL / RET 8 | **High** | Wrong call convention |
| Sole caller secondary role | **High** | Mis-wire refresh |
| Top-4 + node 0x20 emit | **High** | Tracker UI empty/wrong |
| TFID `+0x164` vs `+0x160` | **High** | Identity mismatch vs primary bind |
| FLT_MAX / 10000f / −1.0f | **High** | Rank/filter bugs |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

- 2026-07-23 raw decompile ≡ live decompile shape (both noisy on iterators).
- `get_function_by_address`: body `0092b2a0`–`0092bf5b`.
- Caller site `0092c058`: `PUSH EBP; PUSH EDI; CALL; TEST AL`.
- Fill site: `ADD EAX,0x118`, `new 0x20`, TFID template `DAT_00a158a0`, copy `@+0x164`.
- Constants sealed via `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// stdcall stack args; RET 8
AL = MissionTracker_FillTrackedTargetSlots_Inferred(host, origin);
// Side effects: may push ≤4 nodes (0x20: TFID_16@0 + pos@0x10) onto vector begin host+0x11C;
//               host+0x08 = 1 on any push.
// Pair: sole caller MissionTracker_RefreshTrackedTargets_Inferred (secondary after 0092af80 miss).
// Do NOT treat as primary single-target bind (that is 0092a440 + TFID@+0x160).
```

---

## 5. Verdict

Adversarial attacks on void/thiscall/cdecl/multi-caller/primary-TFID claims fail. Residual product English + residual callees → **accept-with-gaps**. Terminal **false**.
