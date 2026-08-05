# Review B (skeptical / adversarial): `aa_00971700` AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971700` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-M) |
| **Counterpart** | `reviews/A_aa_00971700_AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_00971700.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Same as ExpandDeps path `00971820` | **Falsified** — no per-key loop; no `00744360`; single span insert |
| 2 | Same as single-key `009717a0` | **Falsified** — no `0043d670` push of one key; uses InsertRange of span |
| 3 | stdcall with stack host | **Falsified** — host in **ECX**; bare RET; no stack formal |
| 4 | `+0x50`/`+0x54` are ring indices | **Falsified** — pushed as InsertRange `first`/`last` `const uint32_t*` |
| 5 | Must have static callers to seal | **Rejected** — body + family callees sufficient; orphan noted |
| 6 | Product name retail | **Overstated** — `_Inferred` structural only |
| 7 | Decompiler arg map to `0043df90` is bit-exact | **Partial** — CF order sealed; exact erase formals residual in nested free unit |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX host + return 0 + bare RET | **High** | Wrong ABI |
| Span path host→cache→ctx→+50/+54 | **High** | Wrong keys enqueued |
| InsertRange then EnqueueEligible order | **High** | Wrong pipeline |
| No dep expand | **High** | Wrong sibling collapse |
| Nested erase formal bit-layout | **Medium** | Local clear edge cases |
| Product English / zero xrefs | **Open** | Naming / liveness |
| Runtime | **Open** | Live path unknown if orphan |

---

## 3. Cross-check against raw + bytes

```
raw:  ctx=*(*(p+0x110)+100); first/last @+0x50/+0x54;
      0043df90; 0044e1c0; 00971640; 005b2ba0; return 0
list: MOV ESI,ECX; load span; CALL erase; CALL InsertRange;
      PUSH ESI; MOV ESI,local; CALL EnqueueEligible; CALL dtor; XOR EAX,EAX; RET
hex:  full 150 B matches bounds 00971700–00971795
xrefs: []
```

Family contrast:

| VA | Expand deps? | Source |
|---|---|---|
| `00971640` | no | caller ring (ESI) |
| **`00971700`** | **no** | **cache-ctx span → local** |
| `009717a0` | yes (one key) | stack key |
| `00971820` | yes (per key) | stack ring |

---

## 4. Surviving contract for AutoCore

```
// AssPreloader_EnqueueEligibleFromCacheKeySpan_Inferred:
//   ECX = host; bare RET; returns 0
//   local = InsertRange( *(*(host+0x110)+0x64) span +0x50..+0x54 )
//   EnqueueEligibleFromRing(host, local); destroy local
//   Do not collapse with ExpandDeps siblings.
//   No static callers found — do not invent vtable without evidence.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/span/enqueue pipeline; orphan xrefs + product English residual only → **accept**.
