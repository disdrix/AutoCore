# Review B (skeptical / independent): `aa_008a81a0` Client_InteractPrompt_SetTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a81a0` |
| **VA** | `0x008a81a0` |
| **Canonical name** | `Client_InteractPrompt_SetTarget_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md` |
| **System** | `interaction-activation` / UI chrome |
| **Verdict** | **accept-with-gaps** — agree with A; keep `_Inferred` |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_008a81a0` only | Scaffold only; under-describes sealed chrome role |
| `Client_SendUseObject` / interact net | **Reject** — no net; caller dual already separates UseObject |
| `Client_RefreshInteractPromptTarget` | **Reject** — that is `0x009210e0` (picker); this is the host setter |
| `UI_ShowTooltip` generic | **Reject** — verbs + host `+0x50c` are interact-specific |
| `Client_InteractPrompt_SetTarget` without `_Inferred` | **Reject** — no product method string |
| `Client_InteractPrompt_SetTarget_Inferred` | **Accept** |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| Target is stack formal not ESI | **Fails** — decomp `unaff_ESI`; caller leaves object in ESI; entry does not load target from stack |
| Host is ECX thiscall | **Fails** — `[ebp+8]` host; `ret 4` only |
| Always shows prompt | **Fails** — early outs; empty path when interact gates fail |
| Talk path without type 0x12 | **Fails** — gate on clone `+0x38==0x12` + `FUN_008a8140` |
| Name without `_Inferred` | **Fails** — no PDB/method string |

---

## 3. Agreement with Review A

- ABI ESI+host, verbs, widget slots, not UseObject: **agree Confirmed**
- Keep `_Inferred`: **agree**
- Gaps (host product name, 009254ae, runtime): **agree open**

---

## 4. Residual risks

- Ports must preserve **ESI** convention if hooking retail; C wrappers need an explicit target arg plus ESI load.
- Trade faction compare uses adj-this `+0x164/+0x168` — do not invent alternate IDs without new bytes.

**Verdict:** **accept-with-gaps**
