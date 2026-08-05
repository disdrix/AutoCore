# Reconstruction review: `aa_00811be0` Client_RecvInventoryGrabResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00811be0` |
| **VA** | `0x00811be0` |
| **Canonical name** | `Client_RecvInventoryGrabResponse` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `raw/aa_00811be0_Client_RecvInventoryGrabResponse.md` | Authoritative decompile |
| Annotated | `…annotated.md` | Scaffold + plate (0x2035 / early 0x2039) |
| Exact C++ | `reconstructed-exact/Client_RecvInventoryGrabResponse.cpp` | Clean surface |
| Function record | `functions/aa_00811be0_….md` | Status |
| System map | inventory-transfer | Grab response / stack split |
| Design note | `docs/superpowers/specs/2026-07-09-inventory-stack-split-design.md` | Split path context |
| Sibling | DropResponse / SendGrab | Register + busy patterns |

**Primary claims under review:**

1. Clear `client+0xb6`; call `FUN_007a69d0`
2. Early-out when packet opcode dword `*EBX == 0x2039`
3. Resolve object from TFID at `EBX+2` (packet offset 0x8)
4. Success requires object non-null **and** `(char)EBX[0xe] != 0` (offset 0x38)
5. If `EBX[8]` low byte 0: simple path `FUN_0093d6e0` + mission UI refresh
6. Else stack-split: reduce qty, `CVOGReaction_GiveItemByCbid`, init new stack, cursor helpers, refresh
7. Failure: debug string “Grab Item failed…”, refresh

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw body | Raw | CF |
| Clean C++ | reconstructed-exact | Fidelity |
| Plate comment | Raw header | Dispatch 0x2035 / split narrative |
| Stack-split design doc | superpowers specs | Cross-check intent |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Clear `+0xb6` + helper | **Yes** |
| Early `0x2039` | **Yes** |
| TFID resolve | **Yes** |
| Dual condition object && flag `EBX[0xe]` | **Yes** |
| Simple vs split on `EBX[8]` | **Yes** |
| Split create failure toast | **Yes** |
| Split success vcall sequence | **Yes** |
| Failure OutputDebugStringA path | **Yes** |

### 3.2 Signature presentation

Header claims `__cdecl (void *client, void *packet)` but body uses `in_EAX` / `unaff_EBX` like DropResponse. Clean preserves both the header claim and the register locals — **matches raw scaffold**, including that tension.

### 3.3 Type renames only

`undefined4` → `uint32_t /* or float bits */`; no branch invents.

### 3.4 Function record honesty

Partial scaffold — appropriate.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Formal params vs registers | Medium | Clean does not wire `client`/`packet` args into body |
| `acStack_84[4]` used with long sprintf | Decompiler | Buffer size likely wrong in Ghidra (probably larger); clean keeps it |
| Annotated empty of field map | Meta | Plate only |
| No positive check for 0x2035 | Same pattern as DropResponse | Dispatcher-level |

**No clean-vs-raw fidelity revision required** for scaffold.

---

## 5. What remains uncertain

1. Full grab-response packet schema.
2. Meaning of `EBX[0xe]` (success vs split vs other).
3. Meaning of `EBX[8]` zero vs nonzero branch (simple grab vs split).
4. What `FUN_0093d6e0` does (cursor qty / UI).
5. Whether non-split full grab of whole stack is this simple branch or another packet path.
6. Runtime verification.
7. Live re-decompile not done.

---

## 6. Verdict

### **accept-with-gaps**

Clean faithfully scaffolds the raw grab-response handler (early 0x2039, resolve, simple vs split, errors). Gaps are packet field semantics, true signature, and completeness of “all grab successes” coverage.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Early 0x2039 preserved | **Pass** |
| Split create path preserved | **Yes** |
| No invented modernization | **Pass** |
| Packet/signature sealed | **Open** |
| Verdict | **accept-with-gaps** |
