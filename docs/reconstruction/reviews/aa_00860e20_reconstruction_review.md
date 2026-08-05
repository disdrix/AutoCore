# Reconstruction review: `aa_00860e20` Client_SendInventoryGrab_FromGrid

| Field | Value |
|---|---|
| **Stable ID** | `aa_00860e20` |
| **VA** | `0x00860e20` |
| **Canonical name** | `Client_SendInventoryGrab_FromGrid` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00860e20_Client_SendInventoryGrab_FromGrid.md` | Authoritative Ghidra decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_00860e20_Client_SendInventoryGrab_FromGrid.annotated.md` | Scaffold annotation (copy of raw) |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Client_SendInventoryGrab_FromGrid.cpp` | Clean port surface |
| Function record | `docs/reconstruction/functions/aa_00860e20_Client_SendInventoryGrab_FromGrid.md` | Completion / confidence |
| System map | `docs/reconstruction/systems/inventory-transfer.md` | Opcode / flow claims |
| Wire RE | `docs/inventory-cargo-wire-re.md` | C2S grab size / type-from window |

**Primary claims under review (clean must match low-level):**

1. Optional cursor/UI pre-clear via `unaff_EDI` vtable `+0x3ac` vs `DAT_00d1d8dc[0x146]`
2. Always calls `FUN_007fbbb0()` before send gate
3. Busy gate: only builds/sends when `DAT_00d1a8f6 == 0`
4. Packet: opcode `0x2034`, size `0x20`, item TFID from resolved object `+0x160/+0x164/+0x168`, inventory type from `*(param_1+0x56c)+4`, quantity = `param_2`
5. Send via `g_pSectorNetConnection_INFERRED` vtable `+0x18` when non-null
6. Sets `DAT_00d1b4b0 = 1` and `DAT_00d1a8f6 = 1` after send path; **always returns 1**

**Not re-authored:** No edits to reconstructed-exact, function records, raw, or annotated layers.

**Optional live re-decompile:** Not performed in this review session.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth for CF, packet fill, globals |
| Plate comment | Raw header comment | Opcode `0x2034`, size `0x20`, type-from window, quantity arg |
| Clean implementation | `Client_SendInventoryGrab_FromGrid.cpp` | Line-by-line map to raw |
| System / wire docs | inventory-transfer.md; inventory-cargo-wire-re.md | Cross-check opcode/size narrative |

No runtime / CE / packet capture verification.

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Optional EDI pre-clear | `if (unaff_EDI) { resolve; match → flags + vcall }` | Same | **Yes** |
| Always `FUN_007fbbb0` | Yes | Yes | **Yes** |
| Busy gate | `if (DAT_00d1a8f6 == 0)` | Same | **Yes** |
| Packet fill order | opcode → qty/TFID fields → type → param_2 | Same order | **Yes** |
| Conditional net send | null-check connection then vtable+0x18 | Same | **Yes** |
| Busy set | `DAT_00d1b4b0=1`, `DAT_00d1a8f6=1` | Same | **Yes** |
| Return | always `1` | always `1` | **Yes** |

### 3.2 Packet constants

| Element | Raw | Clean | Match |
|---|---|---|---|
| Opcode | `auStack_20[0] = 0x2034` | Same | **Yes** |
| Size arg | `0x20` | Same | **Yes** |
| Type byte | `*(window+0x56c)+4` | Same | **Yes** |
| Quantity | `param_2` → `uStack_4` | Same | **Yes** |

### 3.3 Type renames only

Clean replaces `undefined4`/`undefined1` with `uint32_t`/`uint8_t`. No control-flow invents, no extra clamps, no modernized packet struct.

### 3.4 Function record honesty

Record correctly marks **Partial scaffold**, signature Tentative–Probable, runtime open. Consistent with artifact quality.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| `unaff_EDI` / incomplete signature | Medium (portability) | Decompiler failed to recover EDI-held “this” / object pointer; clean preserves unaff name — correct fidelity, incomplete port surface |
| `g_pSectorNetConnection_INFERRED` | Doc / naming | Name already marked inferred; identity vs other drop path `Client_SendSectorPacket` unresolved in this unit |
| Annotated layer empty of real annotation | Meta | Annotated is raw copy; no recovered field layout struct |
| Stack layout of 0x20 packet | Open | Clean does not introduce typed `InventoryGrab` struct (scaffold-correct; not a fidelity bug) |
| Always return 1 even when busy-skipped send | Behavioral | Matches raw; callers must not treat return as “packet sent” |

**No revision required** for clean-vs-raw faithfulness of the scaffold body.

---

## 5. What remains uncertain

1. True calling convention / what `param_1` is (UI window) vs EDI object holder.
2. Exact in-memory layout of the 0x20 grab packet fields (offsets of TFID / type / qty).
3. Identity of `DAT_00d1a8f6` (busy / pending-op flag) and who clears it.
4. Meaning of pre-clear path (`DAT_00d1d8dc`, `DAT_00d1d8f4/f5`).
5. Whether return-always-1 is intentional API or decompiler artifact of register return.
6. Runtime round-trip not observed.
7. Live Ghidra re-decompile not performed this session.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean C++ is a faithful scaffold of the raw decompile (control flow, constants, globals, call order) with only width renames.

**Gaps:** Incomplete signature (`unaff_EDI`), untyped packet buffer, unresolved globals, no runtime seal. Function record already labels Partial scaffold.

**Not reject / not needs-revision:** No material clean-vs-raw fidelity error.

---

## 7. Reviewer role statement

Judges faithfulness of reconstructed-exact C++ to raw/annotated low-level evidence. Does not re-author, certify wire layout, or validate live grab gameplay.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Opcode `0x2034` / size `0x20` | **Pass** |
| Type-from window `+0x56c+4` | **Pass** |
| No invented modernizations | **Pass** |
| Function record does not overclaim | **Pass** |
| Signature / runtime complete | **Open** |
| Verdict | **accept-with-gaps** |
