# Review A (reconstruction fidelity): `aa_009668a0` PerfStatRings_CommitAndTrim_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009668a0` |
| **VA** | `0x009668a0`–`0x00966c03` exclusive (**867 B** / `0x363`) |
| **Canonical name** | `PerfStatRings_CommitAndTrim_Inferred` |
| **Ghidra name** | `FUN_009668a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W30-E) |
| **Counterpart** | `reviews/B_aa_009668a0_PerfStatRings_CommitAndTrim_Inferred.md` |
| **System** | Palantir / frame perf stat rings |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Commit current period bins on a global perf-stat object into **4 channel GuardedVector rings + 1 sum ring**, enforce dual sliding budgets (**short sum > 500**, **long sum > 3000**), publish **0x4C dwords** from `+0xCC` to `+0x1FC`, clear live bins/block. Optional timer attribution via `FUN_0076c3c0` when `+0xC8 == 0`.

Sole call site: `FUN_007545c0` → `FUN_009668a0(DAT_00d1f614)` on Palantir frame path.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W30-E) | `docs/reconstruction/raw/aa_009668a0_FUN_009668a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009668a0_FUN_009668a0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PerfStatRings_CommitAndTrim_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009668a0.cpp` |
| Function records | `functions/aa_009668a0_FUN_009668a0.md`, `…_PerfStatRings_CommitAndTrim_Inferred.md` |
| PushBack dual | `GuardedVector_PushBack` W29-B (`0043c830`) |
| Live | decompile; body bounds; entry/epilogue hex; caller/callee xrefs |

---

## 3. Signature (sealed)

```c
// stdcall; 1 stack formal; ret 4
void __stdcall PerfStatRings_CommitAndTrim_Inferred(void* stats);
```

| Formal | Source | Conf |
|---|---|---|
| stats | stack (`8B 6C 24 0C` after push ebx/ebp) | **High** |
| return | void; epilogue `5F 5E 5D 5B C2 04 00` | **High** |

Decompiler shows cdecl-style `void FUN_009668a0(int)` without `ret 4` — **corrected by bytes**.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
commit_count[+0x3D0]++
if timing_enabled[+0xC8]==0: sample timer; add delta into bins[phase]; phase=3
for i in 0..3:
  PushBack(ring_i @ +0x5C+i*0x14, &bins[+0x34+i*4])   // EAX=ring, stack=value*
  channel_totals[+0x44+i*4] += bins[i]
  sum += bins[i]
short_sum[+0x54] += sum; long_sum[+0xC0] += sum
PushBack(sum_ring @ +0xAC, &sum)
sample_count[+0x58]++
while short_sum > 500: subtract oldest from 4 rings; sample_count--
while long_sum > 3000: advance begin on 4+1 rings; long_sum -= oldest sum
bins[0..3]=0
memcpy(+0x1FC, +0xCC, 0x4C*4); memset(+0xCC, 0, 0x4C*4)
if timing: sample; add delta; phase=0
ret 4
```

| Stage | Match | Conf |
|---|---|---|
| Stack object* + ret 4 | **Yes** (bytes) | **High** |
| PushBack EAX/stack (W29-B) | **Yes** (`56 8B C7 E8→0043c830`) | **High** |
| Ring stride 0x14 | **Yes** (`83 C7 14`) | **High** |
| Thresholds 500 / 3000 | **Yes** (`cmp …, 0x1F4` / long loop on `+0xC0`) | **High** |
| Snapshot 0x4C dwords | **Yes** (decompile for-loops count 0x4C) | **High** |
| Cold long-window body after epilogue linear addr | **Yes** (MSVC out-of-line) | **High** |

---

## 5. Machine bytes (`read_memory`)

| Region | Note |
|---|---|
| Entry | `53 55 8B 6C 24 0C 83 85 D0 03 00 00 01 80 BD C8 00 00 00 00 56 57 75 25` |
| Timer open | `8B CD E8 …` → `0076c3c0`; phase `C7 85 C4 … 03` |
| Push loop | `8D 75 34 8D 7D 5C … 56 8B C7 E8 … 0043c830`; `83 C6 04 83 C7 14` |
| Short thresh | `81 7D 54 F4 01 00 00` |
| Epilogue | `5F 5E 5D 5B C2 04 00` |
| Size | **867 B** exclusive end `0x00966c03`; pad `CC` |

**No `disassemble_bytes` used.**

---

## 6. Gaps

- Product English for 4 channel names / Palantir overlay labels.
- Physical units of timer sample and of thresholds 500 / 3000.
- Full type of snapshot blob at `+0xCC` / `+0x1FC`.
- Parent `FUN_007545c0` / `DAT_00d1f614` ownership story (unowned).
- Runtime / bit-exact / differential.

---

## 7. Verdict

CF, ABI (`ret 4`), ring layout, PushBack sites, dual window trims, snapshot publish sealed → **accept-with-gaps** (product labels / units residual).
