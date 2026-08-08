# Review B (skeptical / adversarial): `aa_007aec70` CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_007aec70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (OWN-ONLY WQ9L-G) |
| **Counterpart** | `reviews/A_aa_007aec70_CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `CNDUIWindow` complete dtor | **Falsified** — no vtbl install, no owner-debug, no live-counter; parent `FUN_007b5be0` is complete |
| 2 | This is scalar-deleting dtor | **Falsified** — no flags arg, no `operator_delete(this)`, bare `RET` |
| 3 | cdecl / stack this | **Falsified** — `MOV ESI,ECX`; caller `MOV ECX,ESI` |
| 4 | Always deletes shell at `+0x294` | **Falsified** — delete only when flag `+0xBB` non-zero |
| 5 | `operator_delete` noreturn truncates body | **Falsified** — continues null + vcall + zero + RET (hex) |
| 6 | Scaffold name (callee of VOG_DEBUG_STOP only) | **Falsified as product** — debug string is parent path; this body has no string load of VOG_DEBUG_STOP |
| 7 | vtbl slot is field `+0x2B4` (child iface) | **Falsified** — call is `[EAX+0x2B4]` where EAX=`*this` (method), not field write |
| 8 | Same as `FUN_007a8580` | **Falsified** — different offsets (`+0x294`/`+0xBB` vs `+0x298`/`+0xBC` path) and different vtbl slot (`+0x2B4` vs `+0x288`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Helper vs complete dtor | **High** | Wrong port layering |
| ECX this + bare RET | **High** | ABI corruption |
| Ownership flag gate | **High** | Leak or double-free |
| Empty-string vcall | **High** | Wrong method / arg |
| Product English for vcall / shell | **Open** | Name residual only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
// FUN_007aec70:
ESI=this
EDI=[ESI+0x294]
if EDI:
  if [ESI+0xBB]: RefCountedPtr_Dtor(EDI); delete EDI
  null +0x294/+0xBB; vcall[+0x2B4]("")
zero +0x29C/+0x2A0
ret
```

Live decompile 2026-08-05 ≡ raw CF; full 84 B hex seals epilogue after false-noreturn warning.  
Caller site `0x007b5c83`: `MOV ECX,ESI; CALL 007aec70` between `007a8580` and `007aff00`.

---

## 4. Surviving contract for AutoCore

```
// Port as partial CNDUIWindow teardown helper only:
void CNDUIWindow_ReleaseOwnedRefPtrAt294_ClearText_Inferred(CNDUIWindow* self) {
  // optional owned RefCountedPtr shell free @+0x294
  // clear text via vtbl[+0x2B4]("")
  // zero +0x29C/+0x2A0
}
// Do NOT free self. Do NOT treat as complete dtor.
// Pair with parent CNDUIWindow_CompleteDtor (007b5be0).
```

---

## 5. Verdict

**accept-with-gaps** — adversarial claims against complete-dtor / scalar / always-delete / scaffold product plate are falsified. Product English for vcall and shell type remains open → `_Inferred` retained.
