# Reconstruction review: `aa_00813730` Client_RecvInventoryDropResponse

| Field | Value |
|---|---|
| **Stable ID** | `aa_00813730` |
| **VA** | `0x00813730` |
| **Canonical name** | `Client_RecvInventoryDropResponse` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00813730_Client_RecvInventoryDropResponse.md` | Authoritative decompile |
| Annotated | `…annotated.md` | Scaffold copy + plate field notes |
| Exact C++ | `reconstructed-exact/Client_RecvInventoryDropResponse.cpp` | Clean surface |
| Function record | `functions/aa_00813730_….md` | Status |
| System map | `systems/inventory-transfer.md` | Type switch / place callee |
| Wire RE | `docs/inventory-cargo-wire-re.md` | Case 3 locker binding |
| Callee place unit | `aa_00571620` artifacts | `FUN_00571620` place call |

**Primary claims under review:**

1. Packet in EBX, client in EAX (register convention from dispatch)
2. Clear `client+0xb6`; early-out opcode `0x203b`; fail if success byte `@+0x22==0`
3. Prerequisite pointers `client+0xe04`, `+0xe4e8`, character `+0xe98`
4. Switch on inventoryType `@+0x1a`: case 1 cargo grid, 3 locker, 5 trade, 6 other TFID lookup; default invalid
5. Non-swap path places via `FUN_00571620` using locX `@+0x18` (EBX[6] low) / locY `@+0x19` when position differs or not already placed
6. Swap / concatenate branches with error strings; optional UI refresh `local_94` → `FUN_0085e890`

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw full body | Raw capture | Ground-truth CF |
| Plate comment | Raw header | Field offsets success/type/loc/swap/concat |
| Clean C++ | reconstructed-exact | Fidelity |
| Wire RE case 3 | inventory-cargo-wire-re.md | Locker pointer claims |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

Clean preserves:

| Stage | Match |
|---|---|
| `*(EAX+0xb6)=0` + `FUN_007a69d0` | **Yes** |
| Early `*EBX == 0x203b` return | **Yes** |
| Success `@+0x22` fail toast | **Yes** |
| Null checks `+0xe04` / nested `+0xe4e8` / `+0xe98` | **Yes** |
| Switch cases 1, 3, 5, 6 + default invalid | **Yes** |
| Case 1: cargo via `+0x1040+0x50c` UI + char `+0x250→+0x2b0` grid | **Yes** |
| Case 3: locker UI `+0x1034+0x510` + char `+0xcbc` | **Yes** |
| Case 5/6: trade grids `+0xce0` / lookup + mission UI refresh | **Yes** |
| Non-swap place via `FUN_00571620` | **Yes** |
| Swap path `FUN_00571010` / `FUN_00571b80` / place | **Yes** |
| Concat path `unaff_EBX[0xe]` nonzero | **Yes** |
| Trailing `local_94` UI refresh | **Yes** |

### 3.2 Type renames

`undefined1`→`uint8_t`, `undefined4`→`uint32_t /* or float bits */`. No branch pruning.

### 3.3 Function record honesty

Partial scaffold — appropriate for this large multi-path handler.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Signature `void` vs plate “EBX=packet EAX=client” | Medium | Clean keeps `in_EAX`/`unaff_EBX`; formal params unused (`void` / no client,packet args unlike grab response header) |
| Grab response claims `__cdecl (client,packet)` but same register pattern | Cross-unit | Inconsistency in scaffold headers, not drop-body CF bug |
| `unaff_EBX[6]` as locX | Plate | Char cast of dword index 6 → offset 0x18 — consistent with plate locX |
| Goto LAB_00813b75 shared error formatting | OK | Preserved |
| Annotated layer | Meta | No recovered typed packet struct |

**No fidelity revision required** for clean≡raw scaffold.

---

## 5. What remains uncertain

1. Full S2C `0x2037` packet schema (all fields beyond plate).
2. Swap vs concat field meanings (`+0x23`, `+0x38`, coids `@+0x28/+0x2c`).
3. Whether case 1 grid path always uses vehicle cargo inventory object.
4. Type 6 “other” object class.
5. Register-arg recovery vs true C signature.
6. Runtime success/fail/swap paths.
7. Interaction with incomplete decompiler of place callee (`FUN_00571620`).
8. Live re-decompile not done.

---

## 6. Verdict

### **accept-with-gaps**

Large handler is scaffolded faithfully from raw: switch, place calls, swap/concat, errors, UI refresh. Gaps are typing, signature, and semantic labeling of packet fields — not clean/raw drift.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Type switch 1/3/5/6 preserved | **Pass** |
| Place callee `FUN_00571620` preserved | **Pass** |
| Early 0x203b / fail @+0x22 preserved | **Pass** |
| Signature / packet types complete | **Open** |
| Verdict | **accept-with-gaps** |
