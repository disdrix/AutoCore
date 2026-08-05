# Review B (skeptical / adversarial): `Client_MaybeShowMultiActiveMissionTip_Inferred` / `FUN_008ac7a0` @ `0x008ac7a0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ac7a0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` |
| **Counterpart** | `reviews/A_aa_008ac7a0_Client_MaybeShowMultiActiveMissionTip_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/threshold; **needs-more-evidence** on product English and field semantics |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Refreshes mission dialog lists (HandleButton comment) | **Falsified** — no UI list callees; only hash walk + tip |
| 2 | Always shows tip `0x20` after accept | **Falsified** — requires count ≥ 2 and gate bit clear |
| 3 | Counts every hash payload | **Falsified** — dual predicate `+0xf8`/`+0xfc` filters |
| 4 | Tip threshold is `> 0` (any active) | **Falsified** — `cmp ebx,2` / `1 < count` |
| 5 | Mutates mission state / sends C2S | **Falsified** — only lock byte + tip helper |
| 6 | stdcall / `ret N` | **Falsified** — plain `C3` |
| 7 | `+0x540` is completed-mission hash | **Falsified** vs system map (active = `+0x540`; completed `+0x538/+0x53c`) |
| 8 | Scaffold name `Named_VOG_DEBUG_STOP` is product role | **Falsified** — string is lock assert only |
| 9 | Product tip/field English sealed | **Open** |
| 10 | Runtime Confirmed | **Open** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Count predicate pair | **Confirmed** | Wrong multi-mission tip trigger |
| Threshold ≥ 2 | **Confirmed** | Tip fires too early/late |
| Hash `+0x540` walk topology | **Confirmed** | Miss instances / infinite walk |
| Lock `+0x1d` | **Confirmed** | Concurrent hash corruption if omitted |
| Tip id `0x20` + this `DAT_00d1a840` | **Confirmed** | Wrong tip / wrong host |
| Gate `+0xd34` bit0 | **Confirmed** as gate; **Probable** as tip bit | Over-claim FirstFlags identity |
| Payload field English | **Low** | Docs only |
| Product C++ name | **Open** | Docs only |

---

## 3. Surviving contract for AutoCore

```
// no formals; void
Client_MaybeShowMultiActiveMissionTip_Inferred():
  if !DAT_00d1b6d8: return
  if (byte)(DAT_00d1b6d8+0xd34) & 1: return
  hash = *(DAT_00d1b6d8+0x540)
  assert/set hash+0x1d traversal lock
  count = 0
  for node in chain(hash+0x14 → node+0x14):
    payload = node+8
    if !payload: break
    if *(int16*)(payload+0xf8)==0 AND *(int32*)(payload+0xfc)!=-1:
      count++
  clear hash+0x1d
  if count >= 2:
    Client_MaybeShowFirstTimeTip(DAT_00d1a840, tipId=0x20)

// NOT dialog list rebuild. NOT GiveMission. NOT C2S.
// Preserve exact +0xf8/+0xfc tests even if English unknown.
```

---

## 4. Falsification notes

### 4.1 “Refresh dialog lists”

Parent clean still labels this `// refresh dialog lists`. Body has zero list/UI rebuild callees. Adversarial take: **rename parent comment** when convenient; do not port as UI refresh.

### 4.2 “VOG_DEBUG_STOP is the purpose”

Scaffold auto-name latched onto assert string. Real work is multi-active tip. Keep HashError path as debug-only.

### 4.3 “Tip on every accept”

Accept path always calls this after tip `2`, but this unit early-outs on gate and on count&lt;2. Ports that always show tip `0x20` invent spam.

### 4.4 Field fantasy

Do not invent “status enum” / “continent” product names for `+0xf8`/`+0xfc` without producer dual. Preserve raw tests.

---

## 5. Open questions

1. Tip `0x20` string table English.
2. Payload type + field producers/consumers.
3. Whether gate bit is strictly tip-0x20 FirstFlags on the same object as MaybeShowFirstTimeTip’s `char+0xd30` map.
4. Runtime golden after multi-accept.

**Verdict:** **accept-with-gaps** — structural seal holds under adversarial read; English residual only.
