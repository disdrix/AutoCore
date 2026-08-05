# Review B (skeptical / adversarial): `aa_00911840` Client_UiModalDispatch_AbandonConfirm

| Field | Value |
|---|---|
| **Stable ID** | `aa_00911840` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Re-verify** | Live decompile residual cases + xrefs (same-day seal pass) |
| **Counterpart** | `reviews/A_aa_00911840_Client_UiModalDispatch_AbandonConfirm.md` |
| **Chain** | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| **Verdict** | **accept-with-gaps** on full unit; residual cases **`0x4e46` Yes→C2S `0x20B2`** and **`0x4e47` No close-only** **High / hard to attack** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Function name is abandon-specific | Function is a **kitchen-sink** modal switch (login, delete char, keybinds, many 0x4e** codes) | **Name over-narrow — attack holds** |
| 2 | Opening with `0x4e47` means Yes is `0x4e47` | Confirm **send** is case **`0x4e46`**; `0x4e47` is dismiss group | **Direct inversion risk if docs lag** |
| 3 | Yes/No pairing is proven | Open-site `MOV EAX,0x4e46` + stack `0x4e47` + dual-id store (UF-009) + dispatch cases | **Attack fails — High** |
| 4 | Confirm fails the mission locally | No `CVOGReaction_FailMission` — C2S only + close | **Falsified if claimed** |
| 5 | `param_2==8` is definitely mouse click | Pattern-consistent; no enum table recovered this pass | **Probable** |
| 6 | Stash always valid mission id | Null `dialog+0x670` → `DAT_00d1b4b4 = -1` → confirm no-ops send | **Holds as gate** |
| 7 | Mission id in packet is raw `DAT_00d1b4b4` | Packet uses `*CNDHash_LookupByKey(...)` value, not raw global | **Subtle; usually same** |
| 8 | `FUN_0053fff0` returns hash directly | Returns pointer to table root object; code uses `*puVar7` as hash | **Must not mis-type** |
| 9 | Caller graph empty ⇒ dead code | Xrefs: CALL `009140fe`, CALL `009257e9`, DATA `00a30694` | **Attack fails** |
| 10 | Slice clean is full function | Explicit excerpt only | **Do not treat as full CF** |
| 11 | Case `0x4e47` might still send | Live body: only `FUN_007fc360` in multi-case group | **Attack fails — High** |
| 12 | Case `0x4e46` opcode might be wrong | Literal `apiStack_460[0] = 0x20b2` + size `0x18` | **Attack fails — High** |

---

## 2. Residual dual cases — adversarial seal

### 2.1 Yes path `0x4e46` → C2S `0x20B2`

**Attack surface:** mis-wire server handler; optimistically fail locally; wrong mission id field; wrong size.

| Required condition for send | Fail mode |
|---|---|
| `param_2 == 8` | Silent no-op |
| `DAT_00d1b4b4 != 0xFFFFFFFF` | Close without send |
| `DAT_00d1b6d8 != 0` | Close without send |
| `*FUN_0053fff0() != 0` | Close without send |
| `CNDHash_LookupByKey(table, key) != null` | Close without send |

**Sealed:** literal opcode `0x20B2`, size `0x18`, COID dual-base fields, mission id from def node, then close. **No** local FailMission.

**Hard to attack.** Any AutoCore C2S implementer must honor the gates (especially sentinel stash and def lookup).

### 2.2 No path `0x4e47` → close-only

**Attack surface:** accidental FailMission on dismiss.

**Sealed:** `0x4e47` is in a **multi-case dismiss family** (`0x4e45`, `0x4e47`, `0x4e4b`, `0x4e4d`, `0x4e4f`, `0x4e52`, `0x4e53`, `0x4e55`, `0x4e57`, `0x4e59`, `0x4e5b`). Body on `param_2==8` is exclusively `FUN_007fc360()` → shared exit. **Zero** packet construction.

**Hard to attack** for “No must not send.”

### 2.3 Yes/No residual — **closed (UF-009)**

**Facts that previously refused to reconcile:**

| Fact | Source |
|---|---|
| Decompiler open call shows third arg **`0x4e47`** | `Client_MissionDialogHandleButton` state 2 |
| Packet send is under case **`0x4e46`** | This function |
| Case **`0x4e47`** only closes modal | This function (multi-case group) |

**Resolution (High):** live asm at open is `MOV EAX,0x4e46` then `PUSH 0x4e47` then `CALL FUN_007fdfb0`. `Client_ShowModalPrompt` stores EAX→`+0x498` (Yes) and param_3→`+0x49c` (No). Decompiler stack-only view of the call was incomplete.

**Do not** implement AutoCore UI tests that assert “decompiler third arg == confirm.” Confirm is **`0x4e46`**; dismiss is **`0x4e47`**.

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| C2S opcode `0x20B2` + size `0x18` on confirm case | **High** | Abandon never reaches server |
| COID + mission id fields in packet | **High** | Server rejects / wrong quest |
| Cancel path does not send | **High** | Accidental fail on dismiss |
| Yes id = `0x4e46` for abandon prompt | **High** (UF-009) | Wire wrong UI event |
| No id = `0x4e47` close-only | **High** | Accidental FailMission on dismiss |
| Local mission fail on confirm | **None** (does not) | Client desync if server never echoes S2C |
| Function-wide rename to AbandonConfirm | **Reject** | Misleads future RE |
| Entry vector liveness | **High** (xrefs) | Treating as dead code |

---

## 4. Surviving contract for AutoCore

```
// Client abandon confirm (static) — residual cases sealed
on_mission_dialog_state2_button1:
  stash DAT_00d1b4b4 = selectedMissionId or -1
  open modal via Client_ShowModalPrompt:
    Yes id = 0x4e46 (EAX → host+0x498)
    No  id = 0x4e47 (stack → host+0x49c)

on_modal_click(code, action):
  require action == 8  // Probable primary/confirm event
  if code == 0x4e46 and stash != -1 and character live:
    if missionDefTable.contains(stash):
      send_sector(0x20B2, size=0x18, coid, missionIdFromDef)
      maybe refresh mission chrome (0x13)
    close_modal()  // always on action 8 for this case
  if code == 0x4e47:
    close_modal() only  // never send

// NOT on this path:
//   FailMission(char, id)  — wait for S2C 0x20B2 / Client_RecvFailMission
```

---

## 5. Contradictions

| Doc / claim | Issue |
|---|---|
| Prior HandleButton Review A residual “modal `0x4e47` handler open” | **Closed:** handler is this VA; **`0x4e47` is cancel**, send is **`0x4e46`** |
| Name `Client_UiModalDispatch_AbandonConfirm` | Useful for **slice** artifact; dangerous as sole function name |
| `missionState.md` “no abandon path” | **Client path exists**; server AutoCore must still handle C2S |
| Older raw residual “Probable Yes/No” | **Superseded** by UF-009 + this dual — treat as **High** |
| Older B §7 “pairing needs-more-evidence” | **Superseded this pass** — pairing + residual cases sealed |

---

## 6. What would close remaining gaps

1. Named outer functions for CALL sites `0x009140fe` / `0x009257e9` (create-function / recover message map).
2. Runtime: click Yes → observe event code `0x4e46` and C2S `0x20B2`; click No → no packet.
3. Prove `*piVar8 == key` always (or document when def payload differs).
4. Enum / table for `param_2` values (promote 8 beyond Probable).

---

## 7. Verdict

C2S abandon confirm send is **hard to attack**. Cancel close-only is **hard to attack**. Yes/No residual pairing is **High** (UF-009), not Probable. Soft targets remaining: **name over-narrowness**, **`param_2==8` enum**, **runtime e2e**, **full switch**.

**Verdict: accept-with-gaps** — residual dual cases **sealed**; unit-level gaps (full switch / runtime) remain.
