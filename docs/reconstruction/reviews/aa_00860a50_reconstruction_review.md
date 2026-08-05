# Reconstruction review: `aa_00860a50` Client_UI_InventoryDropToGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860a50` |
| **VA** | `0x00860a50` |
| **Canonical name** | `Client_UI_InventoryDropToGrid` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00860a50_Client_UI_InventoryDropToGrid.md` | Authoritative decompile |
| Annotated | `docs/reconstruction/raw/aa_00860a50_Client_UI_InventoryDropToGrid.annotated.md` | Scaffold copy |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Client_UI_InventoryDropToGrid.cpp` | Clean surface |
| Function record | `docs/reconstruction/functions/aa_00860a50_Client_UI_InventoryDropToGrid.md` | Status |
| System map | `docs/reconstruction/systems/inventory-transfer.md` | C2S drop `0x2036` |
| Wire RE | `docs/inventory-cargo-wire-re.md` | Types 1/3 early-allow |

**Primary claims under review:**

1. Early outs: null `DAT_00d1b6d8`; failed `FUN_0085f220` hit-test; non-(1|3) type blocked when object class `+0x38==4`; trade (type 5) customized/no-trade messages
2. Optional UI callback on `in_EAX[0x15d]` when `+0x2b0` set
3. Busy short-circuit: `DAT_00d1a8f6 != 0` → return 1
4. Multi-path packet build: store-like type 4 / special `cd0` path → opcode char `'\''` (0x27) size `0x40`; else grid drop → opcode char `'6'` (0x2036 LE) size `0x20` with XY packing
5. Send via `Client_SendSectorPacket(&DAT_00d1a840, size, acStack_100)`; set busy; return 1
6. Failure path: toast via `FUN_007fdfb0`, return 0

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw capture | Full CF / branches |
| Clean C++ | reconstructed-exact | Fidelity map |
| Cross-docs | inventory-transfer; cargo-wire-re | Type 1/3 / opcode narrative |

No runtime drop capture.

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

All major branches present in clean with same predicates:

| Branch | Present in clean | Match |
|---|---|---|
| `DAT_00d1b6d8 == 0` → 0 | Yes | **Yes** |
| Hit-test fail → 0 | Yes | **Yes** |
| Type ∉ {1,3} ∧ class==4 → 0 | Yes | **Yes** |
| Type 5 customized / no-trade strings | Yes | **Yes** |
| Busy → return 1 | Yes | **Yes** |
| Type 4 store reject / accept | Yes | **Yes** |
| Grid drop path size 0x20 / store path 0x40 | Yes | **Yes** |
| `Client_SendSectorPacket` + busy set | Yes | **Yes** |
| Error toast LAB_00860af5 | Yes | **Yes** |

### 3.2 Opcode encoding notes

- Grid path: `acStack_100[0] = '6'` with next bytes `' '`, 0, 0 → little-endian dword **0x00002036** (`0x2036`). Confirmed character immediate matches documented InventoryDrop opcode.
- Alternate path: `'\''` → **0x00002027** (`0x27` / 39) with size `0x40` — preserved in clean; semantic “store sell” is interpretive.

### 3.3 Type renames only

`undefined*` → `uint32_t`/`uint8_t`. CONCAT/SUB41 packing left intact (scaffold-faithful, not clarified).

### 3.4 Function record honesty

Partial scaffold; open runtime — consistent.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `in_EAX` this pointer | Medium | Formal `void` signature; clean keeps `in_EAX` — fidelity OK, port incomplete |
| XY packing (`CONCAT11` / `extraout_EDX`) | High uncertainty | Decompiler opaque; clean correctly does not invent clearer math |
| Type index `in_EAX[0x15b]+4` | Doc | Matches “inventory type on target”; not human-named in clean |
| Annotated empty of real notes | Meta | No field diagram for 0x20 drop packet |

**No clean-vs-raw fidelity revision required** for scaffold acceptance.

---

## 5. What remains uncertain

1. True signature / UI object type for `in_EAX`.
2. Exact drop packet field layout (XY, type-to, item TFID).
3. Meaning of type 4 vs 0x27/0x40 store path vs 0x2036 grid path.
4. Trade flags (`+0x17c` bit 20; `+0x4be`).
5. `FUN_0085f220` / `FUN_0085f1d0` hit-test contracts.
6. Runtime verification of early type-1/3 allow vs reject paths.
7. Live re-decompile not done.

---

## 6. Verdict

### **accept-with-gaps**

Clean is a faithful multi-branch scaffold of raw. Gaps are signature recovery, opaque coordinate packing, and untyped packet/globals — already implied by Partial scaffold status.

**Not reject / not needs-revision** for faithfulness.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Grid opcode encodes `0x2036` | **Pass** |
| Early type 1/3 path preserved | **Pass** |
| Busy gate preserved | **Pass** |
| No invented modernization of CONCAT path | **Pass** |
| Signature / layout complete | **Open** |
| Verdict | **accept-with-gaps** |
