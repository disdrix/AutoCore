# Review B (skeptical / adversarial): `aa_008718a0` UiHost_ClearTrackedPairAndRefresh_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008718a0` |
| **VA** | `0x008718a0` |
| **Canonical name** | `UiHost_ClearTrackedPairAndRefresh_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008718a0_UiHost_ClearTrackedPairAndRefresh_Inferred.md` |
| **System** | client UI / vehicle-garage host residual |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Deletes/frees the node | Only stores `*node=0`; no free | **Falsified** free |
| 2 | Always refreshes | Skip if null or `*node==0` | **Falsified** always |
| 3 | cdecl 2-arg free function | `mov ecx,esi` + `ret 8` thiscall | **Falsified** ABI |
| 4 | Same as list remove-all | Single pair match only | **Falsified** |
| 5 | Lookup ignores keyB | Both `+8` and `+0xc` compared | **Falsified** |
| 6 | Refresh uses node as `this` | `00871150` takes node as param; host in EAX/ESI | **Attack fails** — host is `this` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI + clear-if-set | **Confirmed** | Wrong calling convention |
| Pair lookup | **Confirmed** | Wrong entry cleared |
| No free | **Confirmed** | UAF if port frees |
| Key English meaning | **Tentative** | Wrong clear site |
| Host class | **Open** | Docs |

---

## 3. Cross-check against raw / live / bytes

```
batch_decompile ≡ raw ≡ bytes (full function 0x2b bytes).
00871690: match node+8/+0xc under list lock.
00871150: large UI rebind — not part of this VA's complexity.
```

### Merge trap

Do **not** fold into `00871150` or list destroy helpers. This VA is only **clear flag + invoke refresh**.

### Zero trap

If `*node` already 0, **no** refresh — ports that always refresh diverge.

---

## 4. Surviving contract for AutoCore

```
UiHost_ClearTrackedPairAndRefresh(this, keyA, keyB):
  node = FindNode(this+0x628, keyA, keyB)
  if node && *node != 0:
    *node = 0
    RefreshFromNode(this, node)

AutoCore must NOT:
  - free the node here
  - refresh when already clear
  - drop keyB from the match
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Lookup + clear + refresh | **Agree Confirmed** |
| thiscall ret 8 | **Agree Confirmed** |
| Key semantics Tentative | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Node flag meaning (selected? dirty? equipped?).
2. Parent dual for `009440e0`.
3. Whether keys are TFID halves.

**Verdict:** **accept-with-gaps** — agree with A; block free/always-refresh mistakes.
