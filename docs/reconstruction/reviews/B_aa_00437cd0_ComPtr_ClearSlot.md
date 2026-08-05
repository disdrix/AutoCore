# Review B (skeptical / adversarial): `aa_00437cd0` ComPtr_ClearSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437cd0` |
| **VA** | `0x00437cd0` |
| **Canonical name** | `ComPtr_ClearSlot` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00437cd0_ComPtr_ClearSlot.md` |
| **System** | COM / OLE DB plumbing |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Is COM Release / free helper | Bytes are pure `mov [eax],0; ret` — no call | **Falsified** Release/free |
| 2 | Clears via ECX (`__thiscall`) | Slot is **EAX** (`in_EAX`) | **Falsified** ECX-this |
| 3 | CriticalSection / lock helper | No lock API; parent dual already rejected “CS” for this pair | **Falsified** CS |
| 4 | Skill-only / BattleMode-only | Many OLE DB callers + `00763740` | **Falsified** skill-only |
| 5 | Scaffold invents CF | Live ≡ clean (2 ops) | **Attack fails** |
| 6 | Same as `0041d7b0` | Sibling Releases; this only stores 0 | **Agree distinct** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store-null only | **Confirmed** | Spurious Release double-call if mis-port |
| EAX slot pointer | **Confirmed** | Wrong ABI → write corruption |
| void / no stack | **Confirmed** | |
| Domain-universal COM helper | **High** | Over-specializing ports to skill |

---

## 3. Cross-check against raw / live / bytes

```text
mov dword ptr [eax], 0
ret
```

Body end `0x00437cd6`. Clean/raw match live decompile + `read_memory` hex `c70000000000c3`.

### ABI trap

Not `__fastcall` ECX — **EAX** holds the pointer-to-slot (matches decompiler `in_EAX` and parent call sites that set EAX to local out-param address).

### Pairing trap

Do not merge with `aa_0041d7b0`: that unit Releases and **does not** store 0. Ports that “clear and release” must keep both steps separate when retail does.

---

## 4. Surviving contract for AutoCore

```
ComPtr_ClearSlot(slot /*EAX*/):
  *slot = 0

AutoCore must NOT:
  - call Release here
  - pass slot in ECX assuming thiscall
  - treat as Bstr/CS helper
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| `*EAX = 0` Confirmed | **Agree Confirmed** |
| Not Release | **Agree Confirmed** |
| accept-with-gaps | **Agree** (gaps are naming / formal ABI label only) |

---

## 6. Open questions

1. Product helper name if any.
2. None on control flow.

**Verdict:** **accept-with-gaps** — agree with A; block Release/ECX/CS misreads.
