# Review B (skeptical / adversarial): `aa_004da2e0` Client_Combat_ApplyMultiTargetHits_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004da2e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004da2e0_Client_Combat_ApplyMultiTargetHits_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Pure FX audio / particle teardown | Calls `004d78e0` (floaters/shield/HP) | **Falsified** as FX-only |
| 2 | Always builds deferred 0x28 record | Skipped entirely when `this+0x7E==0` | **Survives** as gated |
| 3 | Dense `TFID_16` array (16B stride) | Loop does `pTVar8 += 2` (32B) | **Falsified** 16B claim — **0x20** sealed |
| 4 | Hits dead/filtered objects | Requires `vtbl+0x198()==0` | **Survives** gate |
| 5 | Identical to `004b67d0` | Stage vs apply; different callees | **Falsified** merge |
| 6 | `operator_delete(vector)` true noreturn ends process | SEH cleanup path; known artifact | **Survives** as noise |

---

## 2. Live ≡ raw

Live decompile matches raw `aa_004da2e0`: SEH frame `LAB_009a2290`, vector locals, resolve loop, optional 0x28 pack, `FUN_004e1600`, vector free.

`004d78e0` live body contains `Client_EnqueueCombatFloater_INFERRED` and shield writes — anchors combat role.

---

## 3. Surviving contract

```
// thiscall host (flag @ +0x7E)
// for each 0x20-stride entry in [entries, count):
//   obj = ResolveTFID(entry); if obj && !obj->vtbl[0x198]():
//     status = ApplyHit_004d78e0(...); store status; push entry*
// if host[+0x7E] && hits:
//   pack 0x28 record (transform + count + 0x20*count blob) → FUN_004e1600
// free temp vector
```

**Gaps kept:** product names; entry meta schema; lost-thiscall at some callers.

**Verdict:** **accept-with-gaps**.
