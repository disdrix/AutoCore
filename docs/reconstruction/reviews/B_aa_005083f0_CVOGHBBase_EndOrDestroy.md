# Review B (skeptical / adversarial): `aa_005083f0` CVOGHBBase_EndOrDestroy

| Field | Value |
|---|---|
| **Stable ID** | `aa_005083f0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005083f0_CVOGHBBase_EndOrDestroy.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Single-flag only (decompiler signature) | Trust Ghidra arity | **Falsified** — asm uses `[ebp+8]` and `[ebp+0xc]`; callers push two |
| 2 | Always runs OnEnd (`+0x14`) | Miss zero-flag path | **Falsified** — flag0==0 skips vcall, zeros `+0x18` |
| 3 | This **is** OnEnd | Slot confusion | **Falsified** — OnEnd is **`+0x14`**; this helper is **`+0x18`** and *optionally calls* OnEnd |
| 4 | Flipper `FUN_005083f0(0,0)` fully destroys via list remove | Assume hard | **Falsified** — both flags 0 → soft mark path (no OnEnd) |
| 5 | Only MissionPatrol uses it | Alias name | **Falsified** — weapon track, flipper, many vtbl DATA installs |
| 6 | `FUN_0050843d` is unrelated sibling | Split symbol | **Falsified as separate API** — SEH tail of same logical function |
| 7 | Safe no-op if no vtbl | Defensive | **Not sealed** — OnEnd path assumes valid vtbl |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual stack flags | **High** | Wrong teardown / double OnEnd |
| OnEnd = vtbl `+0x14` only when flag0≠0 | **High** | Skip end side-effects |
| Soft vs hard list unlink | **High** (CF) / **Med** (full list layout) | Leaked HB in list |
| Vtbl install at `+0x18` | **High** | Wrong slot in ported HB types |
| English name | **Medium** | Doc only |

---

## 3. Cross-check against raw

```text
// decompiler shows only param_2 char — incomplete
// authoritative:
if (flag_onEnd == 0)
  this->field_18 = 0;
else
  this->vtbl->OnEnd();          // +0x14
// tail FUN_0050843d:
if (flag_hard && this->field_18 && list_ok)
  unlink_and_destroy_more();
else {
  this->byte_20 = 1;
  this->field_18 = 0;
}
```

---

## 4. Surviving contract for AutoCore

```
CVOGHBBase_EndOrDestroy(this, flag_onEnd, flag_hard):
  if flag_onEnd == 0:
      this.listLink (+0x18) = 0
  else:
      this.OnEnd()            // vtbl +0x14
  if flag_hard && this.listLink && list.alive(+0xb0):
      List_RemoveAndDestroy(this)   // FUN_005085b0 …
  else:
      this.deadFlag (+0x20) = 1
      this.listLink = 0
```

**Port tests:**

* Vtbl slot **`+0x18`** must land here, not OnEnd body.
* `(0,0)` must **not** call OnEnd.
* `(1,x)` must call OnEnd before hard/soft tail.

---

## 5. Open questions

1. Precise ABI width of flags (byte vs dword) — compared as bytes; callers push imm 0.
2. Full `FUN_005085b0` dual if list remove needs own unit.
3. Interaction with scalar deleting dtor thunks.

**Verdict:** **accept-with-gaps**
