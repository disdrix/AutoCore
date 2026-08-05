# Review B (skeptical / adversarial): `aa_00799900` XmlContainer_GetItem_OrDebugStop

| Field | Value |
|---|---|
| **Stable ID** | `aa_00799900` |
| **VA** | `0x00799900` |
| **Canonical name** | `XmlContainer_GetItem_OrDebugStop` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00799900_XmlContainer_GetItem_OrDebugStop.md` |
| **System** | XML / mission-def / NDSpecialFX load |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function **is** only “debug stop” | Success path returns item; log only on fail | **Falsified** rename-as-identity |
| 2 | Non-zero status means success (Win32 style) | `test eax; jnz fail` → **0 = success** | **Falsified** inverted |
| 3 | Always logs a visible message | `NDError_Log(0, …)` — flag 0 skips format path | **Falsified** always-visible |
| 4 | Uses `this` fields beyond +8 | Body only `*(this+8)` + vcall | **Falsified** multi-field |
| 5 | Decompiler “return saved param_2” exact | Bytes: `mov eax,[esp+4]` after call (slot may change) | **Partial** — A’s High note OK; strict pre-copy return **weaker** |
| 6 | Scaffold invents CF | Live ≡ raw | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| +0x8 collection + vtbl 0x1c | **Confirmed** | Wrong object |
| 0 = success | **Confirmed** | Inverted abort |
| Fail → log string + return 0 | **Confirmed** | Miss abort |
| Success return pointer | **High** | |
| Log actually prints | **Low/Open** | flag 0 |
| Interface English names | **Open** | |

---

## 3. Cross-check against raw / live / bytes

```
mov eax, [ecx+8]
mov ecx, [eax]          ; vtbl
lea edx, [esp+4]        ; &item_slot
push edx
push item
push collection
call [ecx+0x1c]
test eax,eax
jnz fail
mov eax, [esp+4]
ret 4
fail:
push "VOG_DEBUG_STOP"
push 0
call FUN_007a4480
xor eax,eax
ret 4
```

### Polarity trap

Treat **0 as success** for this vcall (HRESULT-like or custom). Non-zero aborts with null.

### Naming trap

Do **not** rename the whole unit to `VOG_DEBUG_STOP` as if that is its only behavior — string is the **failure assert path**. (Separate note: other addresses historically misnamed with this string; this unit does contain the literal.)

---

## 4. Surviving contract for AutoCore

```
item' = XmlContainer_GetItem_OrDebugStop(this, item):
  st = (*(this+8))->vtbl[+0x1c](*(this+8), item, &slot)
  if st == 0: return slot (post-call)
  NDError_Log(0, "VOG_DEBUG_STOP")
  return null

AutoCore must NOT:
  - invert success polarity
  - assume log always prints (flag 0)
  - skip null check at call sites (MissionDef breaks loop on null)
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Container +0x8 / vtbl+0x1c | **Agree Confirmed** |
| 0 success | **Agree Confirmed** |
| Fail log + 0 | **Agree Confirmed** |
| Return post-call slot | **Agree High** (prefer bytes over pre-copy decompile) |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Interface of `*(this+8)`.
2. Out-param rewrite policy of the vcall.
3. Runtime.

**Verdict:** **accept-with-gaps** — agree with A; block inverted status and “function is only debug stop” naming.
