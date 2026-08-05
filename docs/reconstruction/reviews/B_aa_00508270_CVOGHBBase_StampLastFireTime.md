# Review B (skeptical / adversarial): `aa_00508270` CVOGHBBase_StampLastFireTime

| Field | Value |
|---|---|
| **Stable ID** | `aa_00508270` |
| **VA** | `0x00508270` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (residual seal; prior accept 2026-07-23) |
| **Counterpart** | `reviews/A_aa_00508270_CVOGHBBase_StampLastFireTime.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (no `disassemble_bytes`) |
| **Verdict** | **accept** (trivial helper; sealed High) |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Also clears dormant / starts HB | **Falsified** — single store; Start owns dormant |
| 2 | Zeros lastFire | **Falsified** — stamps **current** `g_dwClientTickMs` |
| 3 | No callers | **Falsified** — OnStart tail, `FUN_00578b30` ×2, orphan `0x005cc54a/55b`, 28 DATA |
| 4 | TryFire calls this helper | **Falsified as call** — TryFire **inlines** same store |
| 5 | Touches period / counter | **Falsified** — only `+0x14` |
| 6 | Name “ResetStartTick” (plate misnomer elsewhere) | **Reject as name** — body is last-fire stamp @ `+0x14` |
| 7 | Stack formals / non-void return | **Falsified** — bare `ret`; ECX this only |
| 8 | Global is not client tick | **Falsified** — `0x00b041cc` = `g_dwClientTickMs` (81 xrefs; family consumers) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stamp = client tick @ `+0x14` | **High** | Wrong CD / elapsed / UI remaining |
| No side effects beyond that store | **High** | Accidental Start/period bugs in port |
| Call inventory complete for **code** | **High** named; orphan region needs owner name | Missed arm path |
| Vtable DATA = intentional virtual slot | **Probable** | Could be shared helper slot; index open |
| Semantic “elapsed clock reset” | **High** | GetRemaining / TryFire gate depend on `+0x14` |

---

## 3. Cross-check against raw / machine

```
mov eax, [g_dwClientTickMs]   ; A1 CC41B000
mov [ecx+0x14], eax           ; 89 41 14
ret                           ; C3
```

Clean ≡ raw ≡ decompile ≡ 9-byte body. No invented clamps, branches, or callees.

Sibling **GetRemainingSeconds** (`0x00508280`) immediately consumes `+0x14` as last-fire in remaining math — supports field role without re-owning sibling.

---

## 4. Surviving contract for AutoCore

```
CVOGHBBase_StampLastFireTime(HB* this /* ECX */):
  this->dwLastFireTickMs (+0x14) = g_dwClientTickMs (0x00b041cc)
  // void; no period/counter/owner/dormant writes

Use:
  - Manual arm / cast-again OnStart (tail)
  - Non-fire paths that need elapsed reset (e.g. FUN_00578b30)
  - Vtable method on many HB classes (DATA slots)
  - NOT required for TryFire success path (inlines identical store)

Pair with:
  SetPeriodAndCounter / Start / list Enqueue for schedule
  GetRemainingSeconds for UI seconds left
```

---

## 5. Open questions

1. Name the function owning tail-jmps at `0x005cc54a` / `0x005cc55b`.
2. Map each DATA xref to class vtbl + slot offset.
3. Product behavior: stamp without period change vs immediate fire — outside this body.
4. Runtime / bit-exact still deferred.

**Verdict:** **accept** (trivial helper; sealed High)
