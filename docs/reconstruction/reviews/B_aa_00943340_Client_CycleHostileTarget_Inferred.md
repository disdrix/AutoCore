# Review B (skeptical / adversarial): `aa_00943340` Client_CycleHostileTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00943340` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY WQ9R-C) |
| **Counterpart** | `reviews/A_aa_00943340_Client_CycleHostileTarget_Inferred.md` |
| **Scratch** | `tmp/a_00943340.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + analyze/xrefs/callers. **No** `disassemble_bytes`. Own VA `0x00943340` only.

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | thiscall ECX=client | **Falsified** — `MOV ESI,EAX` at entry; callers put client in **EAX** |
| 2 | cdecl (caller cleans) | **Falsified** — `RET 8` |
| 3 | Ally / any-target cycle | **Falsified** — gather mode immediate **2** (hostile) |
| 4 | stepDir 0 = prev | **Falsified** — `(stepDir==0)*2-1` → **+1** when 0 |
| 5 | Pure distance sort only | **Overstated** — `FUN_00930360` uses view-forward scoring (nested, not re-owned) |
| 6 | Always cycles even with no prior selection handle | **Partial** — when `client+0x3048==0`, idx stays 0 (first after sort); caller usually requires `DAT_00d1d888!=0` |
| 7 | Product name Confirmed | **Overstated** — `_Inferred`; no plate string on VA |
| 8 | Live ≠ raw | **Falsified** — identical CF |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EAX client + RET 8 | **High** | ABI break |
| Hostile mode 2 gather | **High** | wrong target class |
| stepDir polarity | **High** | inverted next/prev keys |
| Range 110.0f at call sites | **High** (arg is free float) | wrong default only if port hardcodes wrong |
| Selection apply via FUN_0093e120 | **High** role / nested CF | highlight bugs if stubbed wrong |
| Product key English | **Inferred** | rename |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if player+0x4f1: return
  origin = player.vtbl+0x1a0()
  count = Gather(list, mode=2, max=50, range, score=-1)
  SortView(client, list, &count)
  if count==0: return
  idx = find(curSel) ± step; wrap
  if valid TFID: Select(Resolve(tfid))

bytes:
  55 8B EC 83 E4 F0 81 EC 44 03 00 00 53 56 8B F0 …
  gather push chain includes 6A 02 (mode), 6A 50 (0x32), BF800000
  … 5F 5E 5B 8B E5 5D C2 08 00
```

**No conflict** on owned ABI/CF. Nested sort/select product plates remain open.

---

## 4. Surviving contract for AutoCore

```
// Client_CycleHostileTarget_Inferred @ 0x00943340
// EAX=ClientShell*; stack (float range, char stepDir); RET 8; void
//
// Gather hostiles in range (mode 2, max 50) → view-sort →
// step current client+0x3048 by ±1 with wrap → FUN_0093e120.
//
// Call sites: PollBoundActions next(0)/prev(1) @ 110.f when DAT_00d1d888 set.
```

Port rules:

- Preserve **EAX** client convention or wrap with explicit client* arg in AutoCore API.
- Do not change gather mode away from **2** without a new dual.
- stepDir: **0 = next (+1)**, **nonzero = prev (−1)**.
- Sibling `FUN_00943520` is first-pick path — not this unit.

---

## Checklist

| Check | Result |
|---|---|
| Adversarial ABI (EAX/RET8) | **Pass** |
| Mode/step polarity attack | **Pass** |
| Name humility | **Pass** (`_Inferred`) |
| No disassemble_bytes | **Pass** |
