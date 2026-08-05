# Review A (reconstruction fidelity): `aa_008a81a0` Client_InteractPrompt_SetTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a81a0` |
| **VA** | `0x008a81a0`–`0x008a856e` |
| **Canonical name** | `Client_InteractPrompt_SetTarget_Inferred` |
| **Ghidra name** | `FUN_008a81a0` |
| **Review date** | `2026-07-29` (W19-I OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md` |
| **System** | `interaction-activation` / UI chrome |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` entry/tail + string cluster. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Interact-prompt **chrome setter**: with host on stack and target in **ESI**, classify talk / pick-up / trade / interact and update the host widget (`Press <key> to …`). Clears/hides when target null or non-matching. **Does not** emit UseObject.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | `0x008a81a0` |
| Bytes | entry gates + `ret 4` / `0x3f000000` show arg |
| Strings | cluster `@0x00a4b61c` (verbs + `Press` + format) |
| Caller dual | `Client_RefreshInteractPromptTarget_Inferred` (`0x009210e0`) |
| Sibling | `FUN_008a8140` talkable; `CVOGCharacter_FindActiveObjectiveIdForInteract` |
| Raw / clean | `raw/aa_008a81a0_*`, `reconstructed-exact/Client_InteractPrompt_SetTarget_Inferred.cpp` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x008a81a0`–`0x008a856e` (974 B) | **Confirmed** | Ghidra + tail `C2 04 00` |
| Stack host + **ESI target**; **`ret 4`** | **Confirmed** | entry load `[ebp+8]`; caller ESI; epilogue |
| Early outs: same `+0x50c`, no char, no widget `+0x68c` | **Confirmed** | entry bytes/decomp |
| Verbs talk/pick up/trade/interact | **Confirmed** | string VAs |
| Format `%s <%s> %s %s` + `Press` | **Confirmed** | |
| Widget text `vtbl+0x1d8`, show `vtbl+0xfc(flag, 0.5f)` | **Confirmed** | |
| Host `+0x50c` cache target | **Confirmed** | |
| Not UseObject / net send | **Confirmed** | no net callees |
| Product host class / method English | **Inferred** | `_Inferred` required |
| Second xref container @ `0x009254ae` | **Open** | undefined function |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Triple early-out | **Yes** |
| Null → clear `+0x50c` → show only | **Yes** |
| Talk / pick up / trade / interact order | **Yes** |
| sprintf + cache + caption + show | **Yes** |
| No invent UseObject | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Verb strings | **Yes** |
| Caller = RefreshInteractPromptTarget | **Yes** |
| Host chrome fields | **Yes** |
| Product class/method | **No** |

**Decision:** promote **`Client_InteractPrompt_SetTarget_Inferred`** (role High; method English open → `_Inferred`).

---

## 6. Gaps

1. Product name of `DAT_00d1b8c8` / host class.
2. Product method English.
3. Full `FUN_008a8140` talkable semantics (sibling).
4. Containing function of `0x009254ae`.
5. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
