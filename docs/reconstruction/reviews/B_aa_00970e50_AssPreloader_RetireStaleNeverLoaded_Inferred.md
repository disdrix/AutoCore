# Review B (skeptical / adversarial): `aa_00970e50` AssPreloader_RetireStaleNeverLoaded_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00970e50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-O) |
| **Counterpart** | `reviews/A_aa_00970e50_AssPreloader_RetireStaleNeverLoaded_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler plain RET / void only | **Partially false** — epilogue **`RET 8`**; two stack args sealed |
| 2 | Retires when age **≤** maxAge | **Falsified** — keep path is `age <= maxAge`; retire is **strictly older** |
| 3 | Always destroys every map entry | **Falsified** — age gate + optional null object at +0x10 |
| 4 | Uses pending ring +0x1c | **Falsified** — retire push is **`self+0xAC`** (`LEA EDI,[EBP+0xAC]`) |
| 5 | Scaffold `Named_assPreloader` is product plate | **Overstated** — family from path string; method English **Inferred** from log text |
| 6 | maxAge free/unspecified | **Falsified at sole caller** — `FUN_007b7000` passes **300.0f** (`0x43960000`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 + (self, maxAge) | **High** | Stack smash |
| Age keep/retire polarity | **High** | Wrong purge set |
| Product log lines 0x2A8 / 0x2B7 | **High** | Mis-named behavior |
| Map +0x10/+0x14 + node fields | **High** | Corrupt preloader state |
| Ring +0xAC | **High** | Wrong retire sink |
| Product method English | **Inferred** | Naming only |
| Nested erase dual | **Open** | Incomplete port |
| Runtime | **Open** | Tick race with worker |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  now = FUN_0076c330
  for map nodes:
    if now-stamp <= maxAge: ++it
    else: release; log never-loaded; push +0xAC; erase; retired++
  log retired count

bytes:
  F3 0F 10 44 24 14 / F3 0F 5C 43 14 / 0F 2F 44 24 58  ; age COMISS maxAge
  6A 01 FF 10                                         ; vtbl[0](1)
  68 4C EA A9 00                                      ; "Preloaded asset <%s>..."
  68 A8 02 00 00                                      ; line 0x2A8
  8D BD AC 00 00 00                                   ; EDI = self+0xAC
  68 24 EA A9 00 / 68 B7 02 00 00                     ; count fmt + line 0x2B7
  C2 08 00                                            ; RET 8
```

Caller `FUN_007b7000` @ `007b708a`: `push 0x43960000; push *(DAT_00d1f050+0x6c); call`.

---

## 4. Surviving contract for AutoCore

```
// AssPreloader retire never-loaded older than maxAge:
//   stack (self*, float maxAge); RET 8; void
//   Map at +0x10 (end +0x14); node key+0xC / obj+0x10 / stamp+0x14
//   Keep if (now-stamp) <= maxAge
//   Else: release obj; log never-loaded; push PodU32U8 to +0xAC; erase; count++
//   Always log "Retired %d preload blocks from pool."
// Sole retail tick uses maxAge = 300.0f on *(AssManager+0x6c).
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/age polarity/product logs/ring; method English + nested erase residual → **accept-with-gaps**.
