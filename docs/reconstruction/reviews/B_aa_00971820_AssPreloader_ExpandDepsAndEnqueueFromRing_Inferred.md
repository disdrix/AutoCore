# Review B (skeptical / adversarial): `aa_00971820` AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971820` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-K) |
| **Counterpart** | `reviews/A_aa_00971820_AssPreloader_ExpandDepsAndEnqueueFromRing_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / plain RET / void (Ghidra incomplete surface) | **Falsified** — epilogue **`RET 4`**; **`XOR EAX,EAX`** return 0; ECX host |
| 2 | Enqueues source ring directly without expand | **Falsified** — every iteration: push key + `FUN_00744360` into **local**, then `FUN_00971640` with **ESI=local** |
| 3 | Reuses dirty local without clear | **Falsified** — `if local.size`: `FUN_0043df90` full-range erase before reseed |
| 4 | Scaffold `Named_…VOG_DEBUG_STOP_00971820` is product name | **Overstated** — no VOG_DEBUG string in body; reject as product plate |
| 5 | `FUN_00744360` is pure two-stack-arg cdecl | **Partial** — bytes also set **ECX=`*(*(host+0x110)+0x64)`**; full helper ABI owned by W32-L |
| 6 | Product method string in this body | **Overstated** — no `assPreloader.cpp` here; family via callee `FUN_00971640` / sibling worker |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + stack source + RET 4 + EAX=0 | **High** | Wrong object / stack smash |
| Expand-then-enqueue order | **High** | Missing deps / wrong pending set |
| Local ring lifecycle (clear/push/expand/destroy) | **High** | Leak / stale deps |
| `FUN_00744360` ECX context | **Medium** (bytes) | Mis-port of dep collect |
| Product method English | **Inferred** | Naming only |
| Runtime | **Open** | Multi-thread event races via enqueue |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for each key in source:
    clear local if non-empty
    push key; expand deps; EnqueueEligible(host, local)
  destroy local; return 0

bytes:
  MOV EBP, ECX
  MOV EBX, [ESP+…] source
  loop: CALL 0043df90? / CALL 0043d670 / CALL 00744360 / PUSH EBP; LEA ESI,local; CALL 00971640
  CALL 005b2ba0; XOR EAX,EAX; RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full 222 B hex sealed.

---

## 4. Surviving contract for AutoCore

```
// AssPreloader expand deps then enqueue from source ring:
//   ECX = AssPreloader* host
//   stack = GuardedVector* source (dword keys; +4 pages, +8 cap, +c begin, +10 size)
//   RET 4; returns 0
// Per key: local ring = {key} ∪ deps(FUN_00744360); EnqueueEligible(host, local)
// Do not skip expand; do not pass source as ESI to enqueue; do not drop RET 4.
```

---

## 5. Verdict

Adversarial review confirms sealed ABI/CF; nested dep helper + product method English remain gaps → **accept-with-gaps**.
