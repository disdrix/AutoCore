# Review B (skeptical / adversarial): `aa_0052dac0` MissionStaging_GetOrCreatePayload

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052dac0` |
| **VA** | `0x0052dac0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0052dac0_MissionStaging_GetOrCreatePayload.md` |
| **System** | `missions-progression` |
| **Dual status** | **Present** (first full A+B dual) |
| **Verdict** | **accept-with-gaps** on CF/ABI; **reject** listed false claims |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Free function / no character `this` | **Falsified** — `MOV ESI,ECX`; map via `LEA [ESI+0x508]` |
| 2 | Decompiler formals imply map-this = whole character for lower_bound | **Misleading** — lower_bound `this` is **`char+0x508`** only |
| 3 | Always creates on miss | **Falsified** — create only when stack flag ≠ 0 |
| 4 | Returns whole tree node | **Falsified** — returns **`node+0x18`** payload |
| 5 | `RET 4` single stack arg | **Falsified** — **`RET 8`** (key + flag) |
| 6 | Is GiveMission direct callee | **Falsified** — **0** CODE xrefs from `0x005327c0`; shared staging map family only |
| 7 | “Reward region” is proven product name | **Unproven** — staging 0x30 blob role High; English open |
| 8 | Package bit-exact / runtime complete | **Fail** — static dual only |

---

## 2. Decisive dataflow

```
map = this+0x508
node = lower_bound(map, key)
if node != *(this+0x50c): return node+0x18
if !createIfMissing: return 0
payload = { 0xFF… ×11 dwords, byte0=0 }
return FUN_0052c700(this, key, &payload)  // → node+0x18
```

Live decompile CF ≡ raw. Assembly seals map base / `RET 8` / hit add `0x18`.

Dialog site `0x00943a85`: `PUSH 0` (no create), `ECX = *(client+0xe98)` character, key = `*missionDef`.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI thiscall + key + flag + RET 8 | **High** | Stack smash in port |
| Map `+0x508` / end `+0x50c` | **High** | Wrong tree |
| Return payload base not node | **High** | Off-by-0x18 field writes |
| Create flag polarity | **High** | Spurious inserts on dialog open |
| Product English | **Open** | Docs only |

---

## 4. What would overturn

1. Image rewrite at VA.
2. Proof any site uses non-character ECX with different map layout.
3. Proof return is node base (not +0x18) at any consumer — currently consumers treat EAX as payload (`[eax+0x2c]` writes in `FUN_004d5c10`).

Until then CF + ABI stand **High**.
