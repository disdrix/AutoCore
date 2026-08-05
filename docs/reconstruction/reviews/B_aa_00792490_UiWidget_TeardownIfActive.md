# Review B (skeptical / adversarial): `aa_00792490` UiWidget_TeardownIfActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792490` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W22-F) |
| **Counterpart** | `reviews/A_aa_00792490_UiWidget_TeardownIfActive.md` |
| **Scratch** | `tmp/a_00792490.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Always tears down regardless of state | **Falsified** — `vtbl+0x3d8` gate; early return if false |
| 2 | Is the only close step | **Falsified** — usually after `vtbl+0x3ac`; Flush also runs `FUN_008aa320` first |
| 3 | Name `Named_VOG_DEBUG_STOP` is correct | **Falsified** — string is error path only; not purpose |
| 4 | Stack args / RET N | **Falsified** — plain `RET`; ECX this only |
| 5 | Hash walk free-lists children itself | **Overstated** — calls `vtbl+0xb0(child)`; removal is vtbl-defined |
| 6 | `+0x2ac` type known | **Unproven** — dtor(+1) + `FUN_0074e260(+0x8c)` sealed; product type Tentative |
| 7 | Server-relevant | **Falsified** — client UI only; 100+ UI close xrefs |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Gate + early return | **High** | Partial teardown / leak |
| Flag offsets | **High** | Sticky UI state |
| Hash lock/walk structure | **High** | Missed child cleanup |
| ABI ECX this | **High** | Wrong this |
| vtbl slot product names | **Tentative** | Docs only |
| Owned-object type | **Tentative** | Port mismatch |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
ESI = ECX
if !this.vtbl[0x3d8](): ret
this.vtbl[0x330](8)
clear flags; maybe release +0x2ac path
this.vtbl[0x58]()
lock hash; for each: this.vtbl[0xb0](node.value); unlock
this.vtbl[0x3b4]()
maybe dtor +0x2a8; dtor +0x4c0; zero residual
```

Caller seal:

- Thin wrappers: `CALL [vtbl+0x3ac]; CALL FUN_00792490` (e.g. `0x00817610`).
- Mission dialog flush: optional wire + reward cleanup → `FUN_008aa320` → `vtbl+0x3ac` → this.

Live decompile ≡ raw. Clean plate preserves order and offsets.

---

## 4. Surviving contract for AutoCore

```
// Client UI only
if (widget.IsActive()) {  // vtbl+0x3d8
  // typically after Hide/pre-close vtbl+0x3ac
  UiWidget_TeardownIfActive(widget);
  // releases owned resource + children via vtbl; clears residual ptrs
}
// Do not invent server-side equivalent without matching lifecycle.
// Port: preserve gate or inactive widgets get force-cleared incorrectly.
```

---

## 5. Verdict

Adversarial attacks kill the “always teardown / VOG_DEBUG_STOP-named / sole closer” stories. Core CF/ABI/offsets hold High; vtbl English + object types remain gaps → **accept-with-gaps**.
