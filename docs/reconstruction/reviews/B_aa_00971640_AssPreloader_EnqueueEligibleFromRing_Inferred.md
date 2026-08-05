# Review B (skeptical / adversarial): `aa_00971640` AssPreloader_EnqueueEligibleFromRing_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971640` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-K) |
| **Counterpart** | `reviews/A_aa_00971640_AssPreloader_EnqueueEligibleFromRing_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / plain RET / no ESI formal (decompiler void FUN(int)) | **Falsified** — epilogue **`RET 4`**; entry uses **ESI** as source ring; callers push host then reload ESI |
| 2 | Scans host itself as ring | **Falsified** — callers point ESI at **temp local ring**; host is stack arg (EBP) |
| 3 | Always SetEvent | **Falsified** — gated on dirty flag set only after successful push |
| 4 | Pushes when key **is** in tree map | **Falsified** — requires iterator **== end** (`host+0x14`) |
| 5 | Product name retail string in this body | **Overstated** — no string here; AssPreloader family from sibling `FUN_00971480` path only; method English **Inferred** |
| 6 | Insert stores key* pointer not value | **Falsified** — nested `FUN_0043d420` is `*dst = *src` (value copy) |
| 7 | Same vector as tracked set +0x7c | **Falsified** — pending is **+0x1c**; tracked (sibling) is **+0x7c** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI source + stack host + RET 4 | **High** | Wrong object / stack smash |
| Gate order: tree → cache → contains → push | **High** | Wrong enqueue set |
| host+0x1c / +0x10 / +0x110 / +4 | **High** | Corrupt preloader state |
| Product method English | **Inferred** | Naming only |
| Nested tree/cache product types | **Open** | Mis-port of eligibility |
| Runtime | **Open** | Multi-thread event races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for each slot in ESI ring:
    if tree_end && (cache_end || node+0xc==0) && !contains(+0x1c):
      push(+0x1c); dirty=1
  if dirty: SetEvent(host+4)

bytes:
  MOV EBP, [ESP+…] host
  MOV EDI, [ESI+0xC] begin loop
  LEA ECX, [EBP+0x10] / CALL 0043d5e0
  CMP it, [EBP+0x14]
  MOV EDI, [EBP+0x110] / CALL 0044e8c0
  LEA EDI, [EBP+0x1C] / CALL contains / push
  RET 4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full 184 B hex sealed.

Caller check: `FUN_009717a0` `push esi` (host) / `lea esi,[local]` / call — confirms dual-object ABI.

---

## 4. Surviving contract for AutoCore

```
// AssPreloader enqueue eligible keys from caller ring:
//   ESI = source GuardedVector (+4 pages, +8 cap, +c begin, +10 size)
//   stack = AssPreloader* host; RET 4; void
//   Eligibility: absent from host tree (+0x10/+0x14) AND
//     resource missing/unloaded via *(host+0x110) AND
//     not already in host+0x1c pending
//   On any push: SetEvent(*(HANDLE*)(host+4))
// Do not treat as leaf; do not drop ESI; do not use +0x7c here.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/gates; product method English + nested dual residual → **accept-with-gaps**.
