# Review B (skeptical / adversarial): `aa_0056a9e0` Weapon_PackFxParamsAndDispatch_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056a9e0` |
| **VA** | `0x0056a9e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual B — live Ghidra) |
| **Counterpart** | `reviews/A_aa_0056a9e0_Weapon_PackFxParamsAndDispatch_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is primary weapon fire | Scaffold / proximity to FireHelper | **Falsified** — sole caller `FUN_0056bab0`; FireHelper is `0x0056d160`; event codes 0x14/0x15/0xc/0xe/5/6 not fire-4 |
| 2 | Free-function on FX only (no weapon) | All work is `004b*` FX APIs | **Falsified** — ECX reads `+0xe8/+0xdc/+0xe0` match weapon FireHelper fields; bab0 passes weapon as this |
| 3 | Key3 packing matches FireHelper exactly | Same keys 1–4 | **Falsified** — FireHelper uses `(1 - +0xdc)*0.5`; this unit writes raw `+0xdc` |
| 4 | Always frees the FX session | delete at end | **Falsified** — if `param_3 != NULL`, `vtbl+0xf8` path returns **without** delete |
| 5 | Null `param_4` uses zero TFID | “null target” | **Falsified** — uses `DAT_009d2f68` = **(−1,−1,0,0)** sentinel, not all zeros (`read_memory`) |
| 6 | Scaffold alias is a useful product name | PacketDispa chain | **Falsified** — chain-of-callers only; role is weapon FX pack/dispatch |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| CF spine (pack → TFID → play → dispatch/free) | **High** | Wrong FX lifecycle in port |
| Weapon as scalar source (`+0xe8/dc/e0`) | **High** | Wrong heat/fire field mapping |
| Dispatch vs free ownership split | **High** | Double-free or leak |
| Key3 transform equivalence to FireHelper | **Falsified** | Wrong muzzle scalar |
| Product event English (hit/impact/attach) | Open | Cosmetic naming only |
| `vtbl+0xf8` English | **Probable** | Wrong attach semantics |

---

## 3. Surviving contract

```
// thiscall weapon; fxSession from FUN_004ec010(eventId)
void PackFxParamsAndDispatch(weapon, fxSession, targetObj, tfidOwner) {
  if (!fxSession) return;
  SetParamFloat3(fx, {0},          key=1);
  SetParamFloat3(fx, {weapon.e8},  key=2);
  SetParamFloat3(fx, {weapon.dc},  key=3);   // RAW — not FireHelper's (1-dc)*0.5
  SetParamFloat3(fx, {weapon.e0},  key=4);
  tfid = tfidOwner ? tfidOwner+0x160 : DAT_009d2f68;  // (-1,-1,0,0)
  SetTargetTfidAndOffset(fx, tfid, offset≈{0,0,e8,0});
  provider = targetObj ? targetObj->vtbl[0x1cc]() : 0;
  PlayFxEntryList(fx, forceType=0, provider, name=0, pos=0);
  if (targetObj) { targetObj->vtbl[0xf8](fxSession, 1, 0); return; }
  TeardownFx(fxSession); delete fxSession;
}
```

---

## 4. Falsifications locked in

- **Reject** equating this unit with `Weapon_FireHelper` (`0x0056d160`).
- **Reject** “always delete FX” — ownership splits on target presence.
- **Reject** zero TFID for null owner — sentinel is (−1,−1,0,0).
- **Reject** key3 parity with FireHelper's half-complement transform.
- **Reject** PacketDispa scaffold alias as role label.

---

## 5. Open questions

1. Authoritative product name for the `vtbl+0xf8` attach/start call.
2. Why key3 skips the FireHelper `(1−x)*0.5` remap on this event path.
3. Full matrix of `FUN_0056bab0` event ids → which scripts consume keys 1–4.

**Verdict:** **accept-with-gaps**
