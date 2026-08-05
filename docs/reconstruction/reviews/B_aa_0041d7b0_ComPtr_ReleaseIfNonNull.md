# Review B (skeptical / adversarial): `aa_0041d7b0` ComPtr_ReleaseIfNonNull

| Field | Value |
|---|---|
| **Stable ID** | `aa_0041d7b0` |
| **VA** | `0x0041d7b0` |
| **Canonical name** | `ComPtr_ReleaseIfNonNull` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0041d7b0_ComPtr_ReleaseIfNonNull.md` |
| **System** | COM / OLE DB plumbing |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Free + null like BSTR helper | Bytes: Release only; **no** `mov [slot],0` | **Falsified** free+null |
| 2 | `operator delete` / CRT free | Call target is vtbl+8 | **Falsified** heap free |
| 3 | Always Releases even if null | `test eax,eax` / `jz` skip | **Falsified** always-call |
| 4 | Slot passed in ECX thiscall | Load is `[eax]`; EAX is slot | **Falsified** ECX-this |
| 5 | Skill/BattleMode-only | Many OLE DB + Unwind@* | **Falsified** skill-only |
| 6 | Scaffold invents CF | Live ≡ clean (13 B) | **Attack fails** |
| 7 | Same as `00437cd0` ClearSlot | Clear is store-0 only; this is Release | **Agree distinct** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null-guard + vtbl+8 | **Confirmed** | Crash or leak if inverted |
| No slot null-store | **Confirmed** | Port that nulls here is **extra** vs retail (usually OK) or ports that rely on leftover pointer after Release must match |
| EAX = `IUnknown**` | **Confirmed** | Wrong ABI |
| Domain-universal | **High** | Over-specializing |

---

## 3. Cross-check against raw / live / bytes

```text
mov  eax, [eax]
test eax, eax
jz   ret
mov  ecx, [eax]
push eax
call [ecx+8]
ret
```

Hex: `8b0085c074068b0850ff5108c3`. Clean/raw match live decompile.

### Double-free / dangling trap

This unit **does not** null `*slot`. A second call on the same still-non-null slot **will Release again** → potential double-Release. Retail call sites either:

- use it once at scope end, or
- null themselves before a second cleanup path (see `00423170` owner-iface null-before-Release).

Ports that auto-null after Release are a **behavior change** (usually safer) — document if diverging.

### ABI trap

Not `Release(iface)` with iface in EAX alone as the only arg without indirection — **pointer-to-slot in EAX**, then load iface.

---

## 4. Surviving contract for AutoCore

```
ComPtr_ReleaseIfNonNull(slot /*EAX*/):
  iface = *slot
  if iface != null:
    iface->Release()   // vtbl+8
  // *slot unchanged

AutoCore must NOT:
  - omit the null guard
  - treat as free+null (BSTR style) unless intentionally modernizing
  - pass iface-by-value as the only EAX value without the outer slot load
  - confuse with ClearSlot (00437cd0)
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Null-guard + vtbl+8 Release | **Agree Confirmed** |
| Slot not re-nulled | **Agree Confirmed** (important residual for ports) |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Product helper name if any.
2. Whether intentional non-null after Release is ever observed mid-function (low priority; Unwind/scope pattern dominates).

**Verdict:** **accept-with-gaps** — agree with A; block free+null / always-Release / ECX / skill-only mistakes.
