# Review B (skeptical / adversarial): `aa_00626210` CVOGHBActivatePlayer_OnEnd_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00626210` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-P dual B) |
| **Counterpart** | `reviews/A_aa_00626210_CVOGHBActivatePlayer_OnEnd_Inferred.md` |
| **Scratch** | `docs/reconstruction/tmp/a_00626210.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `CVOGHBBase_Stop` | **Falsified** — Stop is `0x005081d0` (dormant + tail `vtbl+0x10`); this is **callee** of OnEnd dispatch |
| 2 | Always notifies host | **Falsified** — needs host≠0 **and** `this+0x28==0` |
| 3 | Writes float / vehicle clutch at `+0x6c8` | **Falsified for this path** — **byte** store `C6 80 … 01`; physics `+0x6c8` is other layouts |
| 4 | Sets `this+0x28` itself | **Falsified** — no write to `+0x28` in body |
| 5 | Code callers exist | **Falsified** — DATA vtbl only; virtual dispatch |
| 6 | `FUN_005081f0` is real Stop cleanup | **Falsified** — `C3` empty; shared nop OnEnd tail |
| 7 | Product name proven | **Overstated** — structural `_Inferred` from activate vtbl + OnEnd slot |
| 8 | Host `vtbl+0x18` is EndOrDestroy proven here | **Out of scope** — only args `(1,1)` sealed on this VA |
| 9 | Ghidra `__fastcall` void prototype is full ABI | **Noise** — ECX thiscall, no stack |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall / gate / `+0x6c8` / host vcall | **High** | Port loses host complete notify |
| Vtbl slot `+0x14` OnEnd | **High** | Wrong lifecycle hook |
| Empty tail | **High** | Invented cleanup |
| Product English | **Medium** | Naming only |
| Host method semantics | **Open / OOS** | Wrong host teardown pairing |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw/live:
  if (*(this+0x24) && !*(this+0x28)) {
    *(host+0x6c8)=1;
    host->vtbl+0x18(1,1);
  }
  → empty FUN_005081f0

bytes:
  56 8B F1  8B 46 24  85 C0  74 19  80 7E 28 00  75 13
  C6 80 C8 06 00 00 01  8B 4E 24  8B 01  6A 01  6A 01  FF 50 18
  8B CE  5E  E9 → 005081f0 (C3)
```

Clean **must not**:
- invert the `+0x28` gate,
- treat `+0x6c8` as float gear field on this object path,
- claim static code callers,
- fold host `vtbl+0x18` body into this unit,
- invent `this+0x28=1` write.

---

## 4. Surviving contract for AutoCore

```csharp
// Retail aa_00626210 — CVOGHBActivatePlayer_OnEnd_Inferred
// thiscall: this=ECX. No stack args. Void.
unsafe void OnEnd(CVOGHBBase* self)
{
    void* host = *(void**)((byte*)self + 0x24);
    if (host != null && *((byte*)self + 0x28) == 0)
    {
        *((byte*)host + 0x6c8) = 1;
        // host.vtbl[0x18/4](host, 1, 1) — keep as object virtual, not this leaf
        CallHostVtbl18(host, 1, 1);
    }
    // empty base OnEnd tail — no-op
}
```

---

## 5. Verdict

Adversarial pass **confirms** A on CF/ABI/slot/host side effects; product English + host-vfunc body remain gaps → **accept-with-gaps**.
