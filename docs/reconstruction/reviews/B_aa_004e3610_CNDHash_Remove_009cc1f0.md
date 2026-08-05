# Review B (skeptical / adversarial): `aa_004e3610` CNDHash_Remove_009cc1f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e3610` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W27-K) |
| **Counterpart** | `reviews/A_aa_004e3610_CNDHash_Remove_009cc1f0.md` |
| **Scratch** | `tmp/a_004e3610.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is only a debug trap (`VOG_DEBUG_STOP` name) | **Falsified** — full remove CF; strings are warn-only on lock; returns 0/E_FAIL |
| 2 | Lock aborts remove | **Falsified** — log then fall through to lookup |
| 3 | cdecl / all args on stack | **Falsified** — ECX=this; `RET 8` cleans 8 B only |
| 4 | Always frees payload | **Falsified** — early `node+8=0` after out copy; delete path dead when out set (bytes) |
| 5 | Same instance as `0x00538b20` | **Overstated** — same algorithm family, different node freelist vtbl (`009cc1f0` vs `009cf024`) and site |
| 6 | Decompiler `FUN_004e2ca0(param_2)` alone is full lookup | **Partially careful** — bytes also mask key and load bucket from `hash+0x10` before call |
| 7 | operator_delete is noreturn | **Falsified** — normal CALL + ADD ESP; freelist continues |
| 8 | Product name is retail symbol | **Overstated** — CNDHash from HashError family + prior seals; vtbl suffix disambiguates |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + RET 8 + HRESULT | **High** | Port ABI break |
| Out transfer / suppress free | **High** | Double-free or leak |
| Ordered-list + freelist | **High** | Heap corruption |
| Bucket index before find | **High** | Wrong node / miss |
| Product English | **Medium** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + caller

```
ECX = hash (caller MOV ECX,EDI @ 004d65c6)
push out; push key; CALL 004e3610
TEST EAX / JL miss → else operator_delete(*out)
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Body hex 200 B seals both epilogues and vtbl `009cc1f0`.

---

## 4. Surviving contract for AutoCore

```
// Port:
hr = CNDHash_Remove_009cc1f0(hash, key, &outValue);
// hr==0: outValue owns former node value (or null); node on freelist
// hr==E_FAIL: key missing; *outValue remains 0 if out non-null
// do not free value when out was used — caller owns it
// lock bit is diagnostic only
```

---

## 5. Verdict

Adversarial pass **confirms** A: not a debug-only stub; transfer policy and ABI sealed → **accept**.
