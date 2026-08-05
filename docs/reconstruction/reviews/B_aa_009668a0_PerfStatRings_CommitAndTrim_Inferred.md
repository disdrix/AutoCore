# Review B (skeptical / adversarial): `aa_009668a0` PerfStatRings_CommitAndTrim_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009668a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W30-E) |
| **Counterpart** | `reviews/A_aa_009668a0_PerfStatRings_CommitAndTrim_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `__thiscall` ECX=stats | **Falsified** — object loaded from stack (`8B 6C 24 0C`); no ECX this for body |
| 2 | cdecl / no cleanup | **Falsified** — epilogue **`C2 04 00`** (`ret 4`) |
| 3 | `FUN_0043c830(piVar5)` as thiscall on bin ptr | **Falsified** — **EAX=ring** (`8B C7`), stack=`&bin` (`56`); matches W29-B PushBack |
| 4 | Flat arrays not GuardedVector | **Falsified** — page map load `(blocks[page])[res]`; begin/size/capacity at ring+4/+8/+C/+10 |
| 5 | Single window | **Falsified** — short **500** on `+0x54` **and** long **3000** on `+0xC0` |
| 6 | Linear layout only | **Falsified** — long-window body cold-placed after epilogue address |
| 7 | Product name retail | **Overstated** — inferred; Palantir path is caller evidence only |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall ret 4 + stack object* | **High** | Wrong ABI / stack smash |
| PushBack EAX/stack ×5 | **High** | Corrupts wrong container |
| 4 rings stride 0x14 + sum ring | **High** | Offset drift |
| Short 500 / long 3000 trims | **High** | Window policy wrong |
| Snapshot 0x4C dwords | **High** | Publish size wrong |
| Channel product labels | **Open** | Naming only |
| Timer units | **Open** | Metric scale |
| Runtime | **Open** | Multi-frame races |

---

## 3. Cross-check against raw + bytes

```
raw / live decompile:
  +0x3D0++; optional timer open; push 4 bins + sum; trim 500; trim 3000;
  zero bins; copy 0x4C; clear; timer close

bytes:
  entry 53 55 8B 6C 24 0C …
  PushBack: 56 8B C7 E8 → 0043c830; EDI += 0x14; ESI += 4
  5th: LEA EAX,[EBP+0xAC]; push &sum; call 0043c830
  cmp [EBP+0x54], 0x1F4 (500)
  epilogue 5F 5E 5D 5B C2 04 00
  long-window cold body after ret linear addr; JG/JMP re-enter

callee ABI:
  0043c830 sealed W29-B: EAX container, stack value*, RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 **stage tree**; ABI + PushBack call shape corrected by `read_memory`.

---

## 4. Surviving contract for AutoCore

```
// PerfStat ring commit (global DAT_00d1f614):
//   stdcall; stack = stats*; ret 4
//   push bins[4] into rings at +0x5C stride 0x14 via GuardedVector_PushBack
//   push sum into ring +0xAC
//   while short_sum(+0x54) > 500: subtract oldest sample from 4 channels
//   while long_sum(+0xC0) > 3000: advance begin on 4+1 rings
//   publish 0x4C dwords +0xCC → +0x1FC; clear live
// Do not model as thiscall; do not use plain vector::push_back.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/rings/trims/PushBack; product labels + units + runtime residual → **accept-with-gaps**.
