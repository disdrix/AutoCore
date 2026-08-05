# Review B (skeptical / adversarial): `aa_005081c0` CVOGHBBase_Start

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (byte residual seal; prior 2026-07-23) |
| **Counterpart** | `reviews/A_aa_005081c0_CVOGHBBase_Start.md` |
| **Verdict** | **accept** (trivial CF; bytes close residual plate drift) |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Always calls OnStart | **Falsified** — only when `*(this+0x21) ≠ 0` |
| 2 | Enqueues into HB list | **Falsified** — 16-byte body; no list ops |
| 3 | Sets period / counter | **Falsified** — separate `SetPeriodAndCounter` |
| 4 | Stamps lastFire in base Start | **Falsified** — no `+0x14` write; subclass OnStart may stamp |
| 5 | “Activate” renames imply full arm+schedule | **Falsified as product of this unit** — Start is dormant clear + vfunc only |
| 6 | Decompiler jumptable warning implies multi-target dispatch | **Falsified** — `FF 60 04` single vtbl slot |
| 7 | Calling convention has stack args | **Falsified** — bare `ret`; ECX this |
| 8 | fDormant offset could be elsewhere | **Falsified** — bytes `+0x21`; ctor writes same |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dormant arming (+0x21 clear) | **High** | HB stays Inactive in TryFire forever |
| OnStart once-per-arm (until Stop re-dormants) | **High** | Double OnStart side effects if re-Start after Stop |
| Start ≠ Enqueue | **High** | Orphan HB never promoted by Tick |
| Tail-call OnStart | **High** | Stack/ABI mismatch in ports |
| No period math here | **High** | Mis-port regen/cast CD into Start |

---

## 3. Cross-check against raw + bytes

```
if fDormant(+0x21):
  fDormant = 0
  jmp [vtbl+4]   // OnStart, tail
else:
  ret
```

Clean must **not** invent Enqueue, AttachOwner, or lastFire stamp. Prior clean header prose over-claimed enqueue/stamp — **plate-only** error; CF body was already correct.

Sibling Stop (`0x005081d0`) is inverse: if **not** dormant, set dormant=1 and tail `vtbl+0x10` (OnEnd). Symmetric residual strengthens layout.

---

## 4. Surviving contract for AutoCore

```
// Port of CVOGHBBase_Start (client timed-action base)
void CVOGHBBase_Start(CVOGHBBase* hb) {
  if (!hb->fDormant) return;       // +0x21
  hb->fDormant = false;
  hb->vtable->OnStart(hb);         // vtbl+4; may be tail-call
}
// Callers must also:
//   CVOGHBList_Enqueue(mapList, hb)   // often before Start
//   CVOGHBBase_AttachOwnerObject(...) // when owner-linked
//   SetPeriodAndCounter / subclass ctor for period
// TryFire will return Inactive while fDormant remains true.
```

---

## 5. Open questions

1. Whether any production path calls Start **without** Enqueue (intentional dormant-clear only) — static audit residual.
2. Whether any path Enqueues **without** Start (stays Inactive until Start) — likely yes until Start.
3. Product symbol string for this method (none in body).

**Verdict:** **accept**
