# Review B (skeptical / adversarial): `aa_005081d0` CVOGHBBase_Stop

| Field | Value |
|---|---|
| **Stable ID** | `aa_005081d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005081d0_CVOGHBBase_Stop.md` |
| **Verdict** | **accept** (trivial CF; Start-symmetric residual) |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Always calls OnEnd | **Falsified** — only when `*(this+0x21) == 0` |
| 2 | Dequeues from HB list | **Falsified** — 16-byte body; no list ops |
| 3 | Clears period / counter | **Falsified** — no period field writes |
| 4 | Stamps or clears lastFire in base Stop | **Falsified** — no `+0x14` write |
| 5 | “Stop” renames imply full teardown + free | **Falsified as product of this unit** — Stop is dormant set + vfunc only |
| 6 | Decompiler jumptable warning implies multi-target dispatch | **Falsified** — `FF 60 10` single vtbl slot |
| 7 | Calling convention has stack args | **Falsified** — bare `ret`; ECX this |
| 8 | Gate polarity matches Start | **Falsified** — Start acts when dormant ≠ 0 (`jz`); Stop acts when dormant == 0 (`jnz`) |
| 9 | vtbl slot is same as OnStart | **Falsified** — OnStart `+4`; OnEnd `+0x10` |
| 10 | Alias as DriveControlTick-only helper | **Falsified as identity** — base method; many skill/AI/input callers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dormant re-arm (+0x21 set to 1) | **High** | TryFire keeps firing after intended stop |
| OnEnd once-per-disarm (until Start re-arms) | **High** | Double OnEnd side effects if re-Stop after Start |
| Stop ≠ Dequeue | **High** | Orphan list entry keeps ticking dormant nodes |
| Tail-call OnEnd | **High** | Stack/ABI mismatch in ports |
| No period math here | **High** | Mis-port cancel/CD into Stop |
| Inverse of Start | **High** | Wrong gate/slot → Start/Stop dual-broken lifecycle |

---

## 3. Cross-check against raw + bytes

```
if fDormant(+0x21) == 0:   // armed
  fDormant = 1
  jmp [vtbl+0x10]          // OnEnd, tail
else:
  ret                      // already dormant
```

Clean must **not** invent Dequeue, free, AttachOwner clear, or lastFire clear. Scaffold `FUN_005081d0` plate and DriveControlTick-only alias under-claim the base lifecycle role.

Sibling Start (`0x005081c0`) is inverse: if dormant, clear dormant=0 and tail `vtbl+4` (OnStart). Byte twins:

| | Start | Stop |
|---|---|---|
| Branch | `74 09` jz | `75 09` jnz |
| Write +0x21 | `00` | `01` |
| Tail jmp | `[eax+4]` | `[eax+0x10]` |

---

## 4. Surviving contract for AutoCore

```
// Port of CVOGHBBase_Stop (client timed-action base)
void CVOGHBBase_Stop(CVOGHBBase* hb) {
  if (hb->fDormant) return;        // +0x21 already dormant
  hb->fDormant = true;
  hb->vtable->OnEnd(hb);           // vtbl+0x10; may be tail-call
}
// Callers may also:
//   CVOGHBList_Remove / Dequeue (when dropping from map list)
//   free / ref release (when destroying HB object)
// TryFire will return Inactive while fDormant remains true.
```

---

## 5. Open questions

1. Whether any production path calls Stop **without** list Remove (intentional dormant-only) — static audit residual.
2. Whether any path Removes **without** Stop (armed but unlisted) — caller-specific.
3. Product symbol string for this method / OnEnd slot (none in body).

**Verdict:** **accept**
